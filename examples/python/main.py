import wx
import wx.aui as aui
import litecad as lc
import ctypes as ct
import random
from os.path import dirname
import ezdxf
from ezdxf.colors import aci2rgb
import math
import sys

app = wx.App(0)

f = wx.Frame(None, title="LiteCAD AUI")
f.SetSize(wx.Size(800, 600))

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
        .CloseButton(True)
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
        .CloseButton(True)
)

p = wx.Panel(f)

mgr.AddPane(
    p,
    aui.AuiPaneInfo()
        .CenterPane()
        .Name("cad")
)

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
lc.lcPropPutInt(hWnd, lc.LC_PROP_WND_COLORBG, 0x0)

hDrw = lc.lcCreateDrawing()
hBlock = lc.lcPropGetHandle(hDrw, lc.LC_PROP_DRW_BLOCK_MODEL)

lc.lcWndSetBlock(hWnd, hBlock)

# ---------------- RESIZE SYNC ----------------
def on_size(event):
    w, h = p.GetClientSize()
    print(w, h)
    lc.lcWndResize(hWnd, 0, 0, w, h)
    event.Skip()

p.Bind(wx.EVT_SIZE, on_size)

# ---------------- DXF + DATA ----------------
N = 300
M = 300
min_v = -6000.0
max_v = 6000.0

step = (max_v - min_v) / float(N)

tab = (ct.c_double * (2 * N * M))()

for i in range(N):
    for j in range(M):
        i0 = (i * M + j) * 2
        tab[i0] = min_v + i * step
        tab[i0 + 1] = min_v + j * step

dxf = ezdxf.readfile(dirname(__file__) + "/Отметка -250 каркасы.dxf")
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

for entity in msp:
    color = get_color_int(entity, dxf)
    h = None

    if entity.dxftype() == "LINE":
        start = entity.dxf.start
        end = entity.dxf.end

        h = lc.lcBlockAddLine(hBlock, start.x, start.y, end.x, end.y)
        lc.lcPropPutInt(h, lc.LC_PROP_ENT_COLOR, 0x0)

    elif entity.dxftype() in ("LWPOLYLINE", "POLYLINE"):
        if entity.dxftype() == "LWPOLYLINE":
            points = entity.get_points("xy")
            closed = entity.closed
        else:
            points = [(p.x, p.y) for p in entity.points()]
            closed = entity.is_closed

        h = lc.lcBlockAddPolyline(hBlock, 0, closed, 0)

        for x, y in points:
            lc.lcPlineAddVer(h, 0, x, y)

        lc.lcPlineEnd(h)
        lc.lcPropPutInt(h, lc.LC_PROP_ENT_COLOR, 0x0)

    elif entity.dxftype() == "ARC":
        center = entity.dxf.center
        radius = entity.dxf.radius
        a = entity.dxf.start_angle
        b = entity.dxf.end_angle

        arc_angle = math.fmod(a - b + 180, 360) - 180
        arc_angle = arc_angle * (math.pi / 180)
        a *= math.pi / 180
        a -= arc_angle / 2

        h = lc.lcBlockAddArc(hBlock, center.x, center.y, radius, a, arc_angle)
        lc.lcPropPutInt(h, lc.LC_PROP_ENT_COLOR, 0x0)

    elif entity.dxftype() == "CIRCLE":
        center = entity.dxf.center
        radius = entity.dxf.radius

        h = lc.lcBlockAddCircle(hBlock, center.x, center.y, radius, 1)
        lc.lcPropPutInt(h, lc.LC_PROP_ENT_COLOR, 0x0)

# ---------------- GRID ----------------
for i in range(N - 1):
    for j in range(M - 1):

        i0 = (i * M + j) * 2
        i1 = ((i + 1) * M + j) * 2
        i2 = ((i + 1) * M + (j + 1)) * 2
        i3 = (i * M + (j + 1)) * 2

        pline = lc.lcBlockAddPolyline(hBlock, 0, 1, random.randint(0, 1))

        lc.lcPlineAddVer(pline, None, tab[i0], tab[i0 + 1])
        lc.lcPlineAddVer(pline, None, tab[i1], tab[i1 + 1])
        lc.lcPlineAddVer(pline, None, tab[i2], tab[i2 + 1])
        lc.lcPlineAddVer(pline, None, tab[i3], tab[i3 + 1])

        lc.lcPropPutInt(pline, lc.LC_PROP_ENT_COLOR, 0x000000)
        lc.lcPropPutInt(pline, lc.LC_PROP_ENT_FALPHA, 75)

        lc.lcPlineEnd(pline)

lc.lcBlockUpdate(hBlock, 0, 0)

# ---------------- FINAL ----------------
mgr.Update()
f.Layout()
f.Show()
f.Raise()

app.MainLoop()