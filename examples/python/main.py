import wx
import wx.aui as aui
import litecad as lc
import ctypes as ct
import random
from os.path import dirname
import ezdxf
from ezdxf.colors import aci2rgb
import numpy as np
import math
import sys
import time

app = wx.App(0)

f = wx.Frame(None, title="LiteCAD AUI")
f.SetSize(wx.Size(1280, 720))

# ---------------- AUI ----------------
mgr = aui.AuiManager()
mgr.SetManagedWindow(f)

left = wx.Panel(f)

mgr.AddPane(
    left,
    aui.AuiPaneInfo()
    .Left()
    .Caption("Left Tools")
    .BestSize((200, -1))
    .MinSize((150, -1))
    .Name("left")
    .CloseButton(True),
)

# ---------------- BOTTOM PANEL ----------------
bottom = wx.Panel(f)

mgr.AddPane(
    bottom,
    aui.AuiPaneInfo()
    .Bottom()
    .Caption("Log")
    .BestSize((-1, 150))
    .MinSize((-1, 100))
    .Name("bottom")
    .CloseButton(True),
)

p = wx.Panel(f)

mgr.AddPane(p, aui.AuiPaneInfo().CenterPane().Name("cad"))

mgr.Update()

# ---------------- LC INIT ----------------
lc.lcInitialize()

f.Show()
f.Raise()

# важно для wxGTK (GTK layout)
wx.Yield()

# ---------------- CREATE LC WINDOW ----------------
if sys.platform == "win32":
    hWnd = lc.lcCreateWindow(int(p.GetHandle()), 0)
elif sys.platform == "linux":
    hWnd = lc.lcCreateWindow(int(p.GetGtkWidget()), lc.XLC_WINDOW_GTK_BACKEND)

lc.lcPropPutBool(hWnd, lc.LC_PROP_WND_GRIDSHOW, True)
lc.lcPropPutInt(hWnd, lc.LC_PROP_WND_COLORBG, 0x87CEEB)

hDrw = lc.lcCreateDrawing()
hBlock = lc.lcPropGetHandle(hDrw, lc.LC_PROP_DRW_BLOCK_MODEL)

lc.lcWndSetBlock(hWnd, hBlock)


# ---------------- RESIZE SYNC ----------------
def on_size(event):
    w, h = p.GetClientSize()
    lc.lcWndResize(hWnd, 0, 0, w, h)
    event.Skip()


p.Bind(wx.EVT_SIZE, on_size)

dxf = ezdxf.readfile(dirname(__file__) + "/DxfFiles/+100 m_2019.dxf")
msp = dxf.modelspace()


def get_color_int(e, doc):
    if e.dxf.hasattr("true_color"):
        return e.dxf.true_color

    aci = e.dxf.color

    if aci == 256:
        layer = doc.layers.get(e.dxf.layer)
        r, g, b = aci2rgb(layer.color)
    elif aci == 0:
        return 0x000000
    else:
        r, g, b = aci2rgb(aci)

    return (r << 16) | (g << 8) | b


# ---------------- DXF TO LC ----------------
total_points = 0

L = lc.lcDrwAddLayer(hDrw, "0", "0", None, 1)
# lc.lcPropPutBool(L, lc.LC_PROP_LAYER_LOCKED, True)
for entity in msp:
    color = get_color_int(entity, dxf)
    h = None
    if entity.dxftype() == "LINE":
        start = entity.dxf.start
        end = entity.dxf.end

        h = lc.lcBlockAddLine(hBlock, start.x, start.y, end.x, end.y)
        lc.lcPropPutInt(h, lc.LC_PROP_ENT_COLOR, color)
        lc.lcPropPutHandle(h, lc.LC_PROP_ENT_LAYER, L)

    elif entity.dxftype() in ("LWPOLYLINE", "POLYLINE"):
        if entity.dxftype() == "LWPOLYLINE":
            points = entity.get_points("xy")
            closed = entity.closed
            filled = getattr(entity, "fill", False)
        else:
            points = [(p.x, p.y) for p in entity.points()]
            closed = entity.is_closed
            filled = getattr(entity, "fill", False)

        fillcolor = getattr(entity, "fillcolor", None)
        h = lc.lcBlockAddPolyline(hBlock, 0, closed, filled)

        for x, y in points:
            lc.lcPlineAddVer(h, 0, x, y)

        lc.lcPlineEnd(h)
        lc.lcPropPutInt(h, lc.LC_PROP_ENT_COLOR, color)
        if fillcolor is not None:
            lc.lcPropPutInt(h, lc.LC_PROP_ENT_COLOR, int(fillcolor))
        lc.lcPropPutHandle(h, lc.LC_PROP_ENT_LAYER, L)

    elif entity.dxftype() == "ARC":
        center = entity.dxf.center
        radius = entity.dxf.radius
        a = entity.dxf.start_angle
        b = entity.dxf.end_angle

        arc_angle = math.fmod(a - b + 180, 360) - 180
        arc_angle = arc_angle * (math.pi / 180)
        a *= math.pi / 180
        a -= arc_angle / 2

        h = lc.lcBlockAddArc(hBlock, center.x, center.y, radius, a, abs(arc_angle))
        lc.lcPropPutInt(h, lc.LC_PROP_ENT_COLOR, color)
        lc.lcPropPutHandle(h, lc.LC_PROP_ENT_LAYER, L)

    elif entity.dxftype() == "CIRCLE":
        center = entity.dxf.center
        radius = entity.dxf.radius

        h = lc.lcBlockAddCircle(hBlock, center.x, center.y, radius, 0)
        lc.lcPropPutInt(h, lc.LC_PROP_ENT_COLOR, color)
        lc.lcPropPutHandle(h, lc.LC_PROP_ENT_LAYER, L)

    elif entity.dxftype() in ("TEXT", "MTEXT"):
        if entity.dxftype() == "TEXT":
            insert = entity.dxf.insert
            text = entity.dxf.text
            height = entity.dxf.height
            rotation = entity.dxf.rotation if entity.dxf.hasattr("rotation") else 0.0
        else:
            insert = entity.dxf.insert
            text = entity.text
            height = (
                entity.dxf.char_height if entity.dxf.hasattr("char_height") else 1.0
            )
            rotation = entity.dxf.rotation if entity.dxf.hasattr("rotation") else 0.0

        h = lc.lcBlockAddText(hBlock, text, insert.x, insert.y)

        lc.lcPropPutInt(h, lc.LC_PROP_ENT_COLOR, color)
        lc.lcPropPutHandle(h, lc.LC_PROP_ENT_LAYER, L)
        lc.lcPropPutFloat(h, lc.LC_PROP_TEXT_H, height)
        lc.lcPropPutFloat(h, lc.LC_PROP_TEXT_ANGLE, rotation)

# ---------------- GRID ----------------
xyzkji = np.load(dirname(__file__) + "/xyz_kji.npy")
xy = xyzkji.take(5, axis=1)
xy = xy[..., [0, 2]]
N = xy.shape[0]
M = xy.shape[1]

for i in range(N - 1):
    for j in range(M - 1):
        pline = lc.lcBlockAddPolyline(hBlock, 0, 1, 1)

        lc.lcPlineAddVer(pline, None, xy[i, j, 1] * 100, -xy[i, j, 0] * 100)
        lc.lcPlineAddVer(pline, None, xy[i + 1, j, 1] * 100, -xy[i + 1, j, 0] * 100)
        lc.lcPlineAddVer(pline, None, xy[i + 1, j + 1, 1] * 100, -xy[i + 1, j + 1, 0] * 100)
        lc.lcPlineAddVer(pline, None, xy[i, j + 1, 1] * 100, -xy[i, j + 1, 0] * 100)

        lc.lcPropPutInt(pline, lc.LC_PROP_ENT_COLOR, 0x000000)
        lc.lcPropPutInt(pline, lc.LC_PROP_ENT_FCOLOR, 0x000000)
        lc.lcPropPutInt(pline, lc.LC_PROP_ENT_FALPHA, 125)

        lc.lcPlineEnd(pline)

for i in range(N - 1):
    for j in range(M - 1):
        i0 = (i * M + j) * 2

        # smooth noise
        v = (
            90
            + 25 * math.sin(i * 0.15)
            + 15 * math.cos(j * 0.12)
            + 10 * math.sin((i + j) * 0.08)
        )

        v = max(50, min(130, v))

        t = (v - 50.0) / (130.0 - 50.0)

        if t < 0.5:
            k = t * 2.0
            r = int(255 * k)
            g = int(255 * k)
            b = int(255 * (1.0 - k))
        else:
            k = (t - 0.5) * 2.0
            r = 255
            g = int(255 * (1.0 - k))
            b = 0

        color = (r << 16) | (g << 8) | b

        #h = lc.lcBlockAddText(
        #    hBlock,
        #    f"{v:.0f}",
        #    xy[i, j, 1] * 100, -xy[i, j, 0] * 100
        #)

        #lc.lcPropPutInt(h, lc.LC_PROP_ENT_COLOR, color)
        #lc.lcPropPutInt(h, lc.LC_PROP_ENT_LWIDTH, lc.LC_LW_PIXEL)
        #lc.lcPropPutFloat(h, lc.LC_PROP_TEXT_H, 14.0)


x0 = lc.lcPropGetFloat(hBlock, lc.LC_PROP_BLOCK_XMIN)
y0 = lc.lcPropGetFloat(hBlock, lc.LC_PROP_BLOCK_YMIN)
x1 = lc.lcPropGetFloat(hBlock, lc.LC_PROP_BLOCK_XMAX)
y1 = lc.lcPropGetFloat(hBlock, lc.LC_PROP_BLOCK_YMAX)

wx.CallAfter(lc.lcWndZoomRect, hWnd, x0, y0, x1, y1)

print("START")
t0 = time.perf_counter()
lc.lcBlockUpdate(hBlock, 0, 0)
t1 = time.perf_counter()

print("time:", t1 - t0)


def on_select(evt):
    hEnt = lc.lcBlockGetFirstSel(hBlock)
    while hEnt:
        if lc.lcPropGetInt(evt, lc.LC_PROP_EVENT_INT4) == 1:
            lc.lcPropPutInt(hEnt, lc.LC_PROP_ENT_FALPHA, 125)
        else:
            lc.lcPropPutInt(hEnt, lc.LC_PROP_ENT_FALPHA, 0)
        hEnt = lc.lcBlockGetNextSel(hBlock)
    lc.lcBlockUnselect(hBlock)
    lc.lcBlockUpdate(hBlock, 0, None)
    lc.lcWndRedraw(hWnd)


on_select_cb = lc.F_LCEVENT(on_select)

lc.lcEventSetProc(lc.LC_EVENT_SELECT, on_select_cb, 0, None)

# ---------------- FINAL ----------------
mgr.Update()
f.Layout()
f.Show()
f.Raise()

app.MainLoop()
