import wx
import litecad as lc
import ctypes as ct
import random

app = wx.App(0)
f = wx.Frame(None)
lc.lcInitialize()
hWnd = lc.lcCreateWindow(f.GetHandle(), 0)
hDrw = lc.lcCreateDrawing()
hBlock = lc.lcDrwAddBlock(hDrw, "Main", 0, 0)

N = 300
M = 300
min_v = -1000.0
max_v = 1000.0

step = (max_v - min_v) / float(N)

# double* tab = malloc(sizeof(double) * 2 * N * M);
tab = (ct.c_double * (2 * N * M))()

# заполнение координат
for i in range(N):
    for j in range(M):
        i0 = (i * M + j) * 2
        tab[i0] = min_v + i * step
        tab[i0 + 1] = min_v + j * step

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
        lc.lcPropPutInt(pline, lc.LC_PROP_ENT_COLOR, 0x0)
        lc.lcPropPutInt(pline, lc.LC_PROP_ENT_FCOLOR, random.randint(0, 0xFFFFFF))
        lc.lcPropPutInt(pline, lc.LC_PROP_ENT_FALPHA, 75)

lc.lcWndSetBlock(hWnd, hBlock)
lc.lcBlockUpdate(hBlock, 0, 0)

def on_size(event):
    w, h = f.GetClientSize().GetWidth(), f.GetClientSize().GetHeight()
    lc.lcWndResize(hWnd, 0, 0, w, h)
f.Bind(wx.EVT_SIZE, on_size)
f.Show()
app.MainLoop()
