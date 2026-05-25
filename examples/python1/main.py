import wx
import wx.aui as aui
import litecad as lc
import sys
import math

# ---------------- APP ----------------
app = wx.App(0)
f = wx.Frame(None, title="LiteCAD Feature Demo", size=(1200, 800))

mgr = aui.AuiManager()
mgr.SetManagedWindow(f)

panel = wx.Panel(f)
def on_size(event):
    w, h = panel.GetClientSize()
    print(w, h)
    lc.lcWndResize(hWnd, 0, 0, w, h)
    event.Skip()

panel.Bind(wx.EVT_SIZE, on_size)
mgr.AddPane(panel, aui.AuiPaneInfo().CenterPane().Name("cad"))
mgr.Update()

lc.lcInitialize()

# ---------------- CREATE LC WINDOW ----------------
if sys.platform == "win32":
    hWnd = lc.lcCreateWindow(int(panel.GetHandle()), 0)
else:
    hWnd = lc.lcCreateWindow(int(panel.GetGtkWidget()), lc.XLC_WINDOW_GTK_BACKEND)

lc.lcPropPutBool(hWnd, lc.LC_PROP_WND_GRIDSHOW, True)
lc.lcPropPutInt(hWnd, lc.LC_PROP_WND_COLORBG, 0x202020)

# ---------------- DRAWING ----------------
hDrw = lc.lcCreateDrawing()
hBlock = lc.lcPropGetHandle(hDrw, lc.LC_PROP_DRW_BLOCK_MODEL)
lc.lcWndSetBlock(hWnd, hBlock)

# ---------------- LAYERS ----------------
layer_red = lc.lcDrwAddLayer(hDrw, "RED", "Red Layer", None, 1)
layer_green = lc.lcDrwAddLayer(hDrw, "GREEN", "Green Layer", None, 2)
layer_blue = lc.lcDrwAddLayer(hDrw, "BLUE", "Blue Layer", None, 3)

# =========================
# LINE DEMO
# =========================
ln = lc.lcBlockAddLine(hBlock, 0, 0, 100, 100)
lc.lcPropPutInt(ln, lc.LC_PROP_ENT_COLOR, 0xFF0000)
lc.lcPropPutFloat(ln, lc.LC_PROP_ENT_LWIDTH, 2.0)
lc.lcPropPutHandle(ln, lc.LC_PROP_ENT_LAYER, layer_red)

# =========================
# POLYLINE DEMO
# =========================
pl = lc.lcBlockAddPolyline(hBlock, 0, 0, 0)

points = [(150, 0), (200, 50), (180, 120), (120, 100)]
for x, y in points:
    lc.lcPlineAddVer(pl, 0, x, y)

lc.lcPlineEnd(pl)
lc.lcPropPutInt(pl, lc.LC_PROP_ENT_COLOR, 0x00FF00)
lc.lcPropPutInt(pl, lc.LC_PROP_ENT_LWIDTH, lc.LC_LW_REAL)
lc.lcPropPutFloat(pl, lc.LC_PROP_ENT_LWIDTH, 1.5)
lc.lcPropPutHandle(pl, lc.LC_PROP_ENT_LAYER, layer_green)

# =========================
# ARC DEMO
# =========================
center_x, center_y = 300, 50
radius = 60

arc = lc.lcBlockAddArc(
    hBlock,
    center_x,
    center_y,
    radius,
    0,
    math.pi * 1.5
)

lc.lcPropPutInt(arc, lc.LC_PROP_ENT_COLOR, 0x0000FF)
lc.lcPropPutInt(arc, lc.LC_PROP_ENT_LWIDTH, lc.LC_LW_PIXEL)
lc.lcPropPutFloat(arc, lc.LC_PROP_ENT_LWIDTH, 3.0)
lc.lcPropPutHandle(arc, lc.LC_PROP_ENT_LAYER, layer_blue)

# =========================
# CIRCLE DEMO
# =========================
circle = lc.lcBlockAddCircle(hBlock, 400, 150, 50, 0)
lc.lcPropPutInt(circle, lc.LC_PROP_ENT_COLOR, 0xFFFF00)
lc.lcPropPutInt(circle, lc.LC_PROP_ENT_LWIDTH, lc.LC_LW_REAL)
lc.lcPropPutFloat(circle, lc.LC_PROP_ENT_LWIDTH, 4.0)
lc.lcPropPutHandle(circle, lc.LC_PROP_ENT_LAYER, layer_red)

# =========================
# LAYER VISUAL TEST OBJECTS
# =========================
for i in range(5):
    l = lc.lcBlockAddLine(hBlock, 500, i * 30, 650, i * 30)
    lc.lcPropPutHandle(l, lc.LC_PROP_ENT_LAYER, layer_green)
    lc.lcPropPutInt(l, lc.LC_PROP_ENT_LWIDTH, lc.LC_LW_REAL)
    lc.lcPropPutFloat(l, lc.LC_PROP_ENT_LWIDTH, 0.5 + i)

# ---------------- VIEW ----------------
lc.lcBlockUpdate(hBlock, 1, 0)

x0 = lc.lcPropGetFloat(hBlock, lc.LC_PROP_BLOCK_XMIN)
y0 = lc.lcPropGetFloat(hBlock, lc.LC_PROP_BLOCK_YMIN)
x1 = lc.lcPropGetFloat(hBlock, lc.LC_PROP_BLOCK_XMAX)
y1 = lc.lcPropGetFloat(hBlock, lc.LC_PROP_BLOCK_YMAX)

wx.CallAfter(lc.lcWndZoomRect, hWnd, x0, y0, x1, y1)

# ---------------- SHOW ----------------
mgr.Update()
f.Show()
f.Raise()

app.MainLoop()