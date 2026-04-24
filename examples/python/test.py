import wx
import litecad as lc
import ctypes as ct
import random
from os.path import dirname
import ezdxf
from ezdxf.colors import aci2rgb

app = wx.App(0)
f = wx.Frame(None)
lc.lcInitialize()
hWnd = lc.lcCreateWindow(f.GetHandle(), 0)
hDrw = lc.lcCreateDrawing()
hBlock = lc.lcDrwAddBlock(hDrw, "Main", 0, 0)

hPline = lc.lcBlockAddPolyline(hBlock, 0, 1, 0)
lc.lcPlineAddVer(hPline, None, -50, -50)
lc.lcPlineAddVer(hPline, None, 0, 0)
lc.lcPlineAddVer(hPline, None, 50, -50)
lc.lcPlineAddVer(hPline, None, 100, 50)
lc.lcPropPutInt(hPline, lc.LC_PROP_ENT_LWIDTH, lc.LC_LW_PIXEL)
lc.lcPropPutFloat(hPline, lc.LC_PROP_ENT_LWIDTH, 10.0)

lc.lcWndSetBlock(hWnd, hBlock)
lc.lcBlockUpdate(hBlock, 0, 0)

def on_size(event):
    w, h = f.GetClientSize().GetWidth(), f.GetClientSize().GetHeight()
    lc.lcWndResize(hWnd, 0, 0, w, h)
f.Bind(wx.EVT_SIZE, on_size)
f.Show()
app.MainLoop()
