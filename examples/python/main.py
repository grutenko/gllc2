import wx
import litecad as lc
import ctypes as ct
import random
from os.path import dirname
import ezdxf
from ezdxf.colors import aci2rgb
import math

app = wx.App(0)
f = wx.Frame(None)
f.SetSize(wx.Size(800, 600))
lc.lcInitialize()
hWnd = lc.lcCreateWindow(f.GetHandle(), 0)
lc.lcPropPutBool(hWnd, lc.LC_PROP_WND_GRIDSHOW, False)
lc.lcPropPutInt(hWnd, lc.LC_PROP_WND_COLORBG, 0x0)
hDrw = lc.lcCreateDrawing()
hBlock = lc.lcPropGetHandle(hDrw, lc.LC_PROP_DRW_BLOCK_MODEL)
lc.lcWndSetBlock(hWnd, hBlock)


def on_size(event):
    w, h = f.GetClientSize().GetWidth(), f.GetClientSize().GetHeight()
    lc.lcWndResize(hWnd, 0, 0, w, h)


f.Bind(wx.EVT_SIZE, on_size)
f.Show()

N = 600
M = 600
min_v = -6000.0
max_v = 6000.0

step = (max_v - min_v) / float(N)

# double* tab = malloc(sizeof(double) * 2 * N * M);
tab = (ct.c_double * (2 * N * M))()

# заполнение координат
for i in range(N):
    for j in range(M):
        i0 = (i * M + j) * 2
        tab[i0] = min_v + i * step + random.uniform(-0.5, 0.5)
        tab[i0 + 1] = min_v + j * step + random.uniform(-0.5, 0.5)

dxf = ezdxf.readfile(dirname(__file__) + "\\Отметка -250 каркасы.dxf")
msp = dxf.modelspace()


def get_color_int(e, doc):
    # True Color (уже RGB, упакован в int)
    if e.dxf.hasattr("true_color"):
        return e.dxf.true_color  # уже 0xRRGGBB

    aci = e.dxf.color

    # BYLAYER
    if aci == 256:
        layer = doc.layers.get(e.dxf.layer)
        r, g, b = aci2rgb(layer.color)
    # BYBLOCK (без контекста — заглушка)
    elif aci == 0:
        return 0x000000
    else:
        r, g, b = aci2rgb(aci)

    return (r << 16) | (g << 8) | b


total_points = 0
# ---------- ENTITIES ----------
for entity in msp:
    color = get_color_int(entity, dxf)
    linetype_name = entity.dxf.linetype or "BYLAYER"

    # ---------- POLYLINE / LWPOLYLINE ----------
    if entity.dxftype() == "LINE":
        start = entity.dxf.start
        end = entity.dxf.end

        h = lc.lcBlockAddLine(hBlock, start.x, start.y, end.x, end.y)
        total_points += 2
        lc.lcPropPutInt(h, lc.LC_PROP_ENT_COLOR, 0xffffff)
        lc.lcPropPutInt(h, lc.LC_PROP_ENT_LWIDTH, lc.LC_LW_REAL)
        lc.lcPropPutFloat(h, lc.LC_PROP_ENT_LWIDTH, 2)

        # ---------- POLYLINE / LWPOLYLINE ----------
    elif entity.dxftype() in ("LWPOLYLINE", "POLYLINE"):
        if entity.dxftype() == "LWPOLYLINE":
            points = entity.get_points("xy")
            closed = entity.closed
            total_points += len(points)
        elif entity.dxftype() == "POLYLINE":
            points = [(p.x, p.y) for p in entity.points()]
            closed = entity.is_closed
            total_points += len(points)
        h = lc.lcBlockAddPolyline(hBlock, 0, closed, 0)
        for x, y in points:
            lc.lcPlineAddVer(h, 0, x, y)
        lc.lcPlineEnd(h)
        lc.lcPropPutInt(h, lc.LC_PROP_ENT_COLOR, 0xffffff)
        lc.lcPropPutInt(h, lc.LC_PROP_ENT_LWIDTH, lc.LC_LW_REAL)
        lc.lcPropPutFloat(h, lc.LC_PROP_ENT_LWIDTH, 2)

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
        lc.lcPropPutInt(h, lc.LC_PROP_ENT_COLOR, 0xffffff)
    elif entity.dxftype() == "CIRCLE":
        center = entity.dxf.center
        radius = entity.dxf.radius
        h = lc.lcBlockAddCircle(hBlock, center.x, center.y, radius, 1)
        lc.lcPropPutInt(h, lc.LC_PROP_ENT_COLOR, 0xffffff)

# генерация полилиний
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
        lc.lcPropPutInt(pline, lc.LC_PROP_ENT_COLOR, 0xffffff)
        lc.lcPropPutInt(pline, lc.LC_PROP_ENT_FALPHA, 75)
        lc.lcPropPutBool(pline, lc.LC_PROP_ENT_LOCKED, True)
        lc.lcPlineEnd(pline)

lc.lcBlockUpdate(hBlock, 0, 0)


app.MainLoop()
