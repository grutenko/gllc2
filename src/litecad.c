#include "litecad.h"
#include "block.h"
#include "drawing.h"
#include "event.h"
#include "line.h"
#include "linetype.h"
#include "object.h"
#include "polyline.h"
#include "window.h"
#include <X11/Xlib.h>

void LCAPI lcEventSetProc(int EventType, F_LCEVENT pFunc, int Prm1, void *Prm2) {
  gllc_event_set_proc(EventType, (void (*)(struct gllc_event *))pFunc, Prm1, Prm2);
}

void LCAPI lcEventReturnCode(int code) {
}

LCAPI int lcEventsEnable(int b) { return 0; }

// Initialization
LCAPI int lcInitialize() {
#ifdef DEBUG
  printf("DEBUG build\n");
#endif

#ifdef NDEBUG
  printf("RELEASE build\n");
#endif
  return 0;
}

LCAPI int lcUninitialize(int bSaveConfig) {
  return 0;
}

// GUI strings
LCAPI int lcStrAdd(char *szTag, char *szText) {
  return 0;
}

LCAPI int lcStrSet(char *szTag, char *szText) {
  return 0;
}

LCAPI char *lcStrGet(char *szTag) {
  return 0;
}

LCAPI int lcStrFileLoad(char *szFileName) {
  return 0;
}

LCAPI int lcStrFileSave(char *szFileName, char *szLanguage) {
  return 0;
}

// Objects properties
LCAPI int lcPropGetBool(void *hObject, int idProp) {
  return gllc_prop_get_bool((struct gllc_object *)hObject, idProp);
}

LCAPI int lcPropGetInt(void *hObject, int idProp) {
  return gllc_prop_get_int((struct gllc_object *)hObject, idProp);
}

double LCAPI lcPropGetFloat(void *hObject, int idProp) {
  return gllc_prop_get_float((struct gllc_object *)hObject, idProp);
}
LCAPI char *lcPropGetStr(void *hObject, int idProp) {
  return gllc_prop_get_string((struct gllc_object *)hObject, idProp);
}

LCAPI int lcPropGetStrA(void *hObject, int idProp, char *szBuf, int BufSize) { return 0; }
LCAPI int lcPropGetStr2(void *hObject, int idProp) { return 0; }
LCAPI int lcPropGetChar(int iChar) { return 0; }

LCAPI void *lcPropGetHandle(void *hObject, int idProp) {
  return gllc_prop_get_handle((struct gllc_object *)hObject, idProp);
}
LCAPI int lcPropPutBool(void *hObject, int idProp, int bValue) {
  return gllc_prop_put_bool((struct gllc_object *)hObject, idProp, bValue);
}

LCAPI int lcPropPutInt(void *hObject, int idProp, int Value) {
  return gllc_prop_put_int((struct gllc_object *)hObject, idProp, Value);
}

LCAPI int lcPropPutFloat(void *hObject, int idProp, double Value) {
  return gllc_prop_put_float((struct gllc_object *)hObject, idProp, Value);
}

LCAPI int lcPropPutStr(void *hObject, int idProp, char *szValue) {
  return gllc_prop_put_string((struct gllc_object *)hObject, idProp, szValue);
}

LCAPI int lcPropPutHandle(void *hObject, int idProp, void *hValue) {
  return gllc_prop_put_handle((struct gllc_object *)hObject, idProp, hValue);
}

// Design window
LCAPI void *lcCreateWindow(void *hWndParent, int Style) {
#if defined(_WIN32) || defined(__EMSCRIPTEN__)
  if (Style & XLC_WINDOW_GTK_BACKEND || Style & XLC_WINDOW_WAYLAND_BACKEND || Style & XLC_WINDOW_X11_BACKEND) {
    fprintf("Error: Using XLC_WINDOW_*_BACKEND allowed only for linux build.\n");
    return NULL;
  }
#elif defined(__linux__)
  int backends = Style & (XLC_WINDOW_GTK_BACKEND |
                          XLC_WINDOW_WAYLAND_BACKEND |
                          XLC_WINDOW_X11_BACKEND);
  if (backends && (backends & (backends - 1))) {
    fprintf(stderr, "Error: Multiple backends selected at once.\n");
    return NULL;
  }
#else
#error "GLLC Library: Unsupported platform. Only Windows, Emscripten, and Linux (X11/Wayland/GTK) are supported."
#endif

#if defined(_WIN32)
  return gllc_window_create_win32((HWND)hWndParent, Style);
#elif defined(__EMSCRIPTEN__)
  return gllc_window_create_webgl((const char *)surface, Style);
#elif defined(__linux__)
  if (Style & XLC_WINDOW_GTK_BACKEND) {
    return gllc_window_create_gtk((GtkWindow *)hWndParent, Style);
  } else if (Style & XLC_WINDOW_WAYLAND_BACKEND) {
    return gllc_window_create_wayland((struct wl_surface *)hWndParent, Style);
  } else if (Style & XLC_WINDOW_X11_BACKEND) {
    fprintf(stderr, "Error: use XlcCreateWindowX11() for X11_backend\n");
    return NULL;
  } else {
    fprintf(stderr, "Error: Not selected backend. Use XLC_WINDOW_*_BACKEND.\n");
    return NULL;
  }
#endif
}

LCAPI int lcDeleteWindow(void *hLcWnd) {
  return gllc_window_destroy((struct gllc_window *)hLcWnd);
}

LCAPI int lcWndOnClose(void *hLcWnd) {
  return 1;
}

LCAPI int lcWndExeCommand(void *hLcWnd, int Command, int CmdParam) {
  return 1;
}

LCAPI int lcWndExitCommand(void *hLcWnd) {
  return 1;
}

LCAPI int lcWndResize(void *hLcWnd, int Left, int Top, int Width, int Height) {
  return gllc_window_resize((struct gllc_window *)hLcWnd, Left, Top, Width, Height);
}

LCAPI int lcWndRedraw(void *hLcWnd) {
  return gllc_window_redraw((struct gllc_window *)hLcWnd);
}

LCAPI int lcWndRedrawAuto(void *hLcWnd, int Elapse, F_REDRAW pFunc) {
  return gllc_window_redraw((struct gllc_window *)hLcWnd);
}

LCAPI int lcWndSetFocus(void *hLcWnd) {
  return gllc_window_set_focus((struct gllc_window *)hLcWnd);
}

LCAPI int lcWndSetExtents(void *hLcWnd, double Xmin, double Ymin, double Xmax, double Ymax) {
  return 1;
}

LCAPI int lcWndSetBlock(void *hLcWnd, void *hBlock) {
  return gllc_window_set_block((struct gllc_window *)hLcWnd, (struct gllc_block *)hBlock);
}

LCAPI int lcWndSetProps(void *hLcWnd, void *hPropWnd) {
  return 1;
}

LCAPI int lcWndSetCmdwin(void *hLcWnd, void *hCmdLine) {
  return 1;
}

LCAPI int lcWndSetBasePoint(void *hLcWnd, int bState, double X, double Y) {
  return 1;
}

LCAPI int lcWndEmulator(void *hLcWnd, int Mode) {
  return 1;
}

LCAPI int lcWndMagnifier(void *hLcWnd, int bOn, int Width, int Height, int Zoom, int Flags) {
  return 1;
}

LCAPI int lcWndHoverText(void *hLcWnd, char *szText, int X, int Y, int Align) {
  return 1;
}

LCAPI int lcWndMessage(void *hLcWnd, char *szText, int uType) {
  return 1;
}

LCAPI int lcWndWaitPoint(void *hLcWnd, char *szText, double *pXdrw, double *pYdrw) {
  return 1;
}

LCAPI int lcWndWaitPoint2(void *hLcWnd, char *szText, double *pXdrw, double *pYdrw, F_WAITPOINT pFunc, int FuncPrm) {
  return 1;
}

LCAPI int lcWndInputStr(void *hLcWnd) {
  return 1;
}

LCAPI int lcWndUpdate(void *hLcWnd, int Mode) {
  return 1;
}

LCAPI void *lcWndDrwAdd(void *hLcWnd, char *szFileName) {
  return NULL;
}

LCAPI int lcWndDrwDelete(void *hLcWnd, void *hLcDrw) {
  return 1;
}

LCAPI void *lcWndDrwGet(void *hLcWnd, int Index) {
  return NULL;
}

// zoom
LCAPI int lcWndZoomRect(void *hLcWnd, double Left, double Bottom, double Right, double Top) {
  return 1;
}

LCAPI int lcWndZoomScale(void *hLcWnd, double Scal) {
  return 1;
}

LCAPI int lcWndZoomMove(void *hLcWnd, double DX, double DY) {
  return 1;
}

LCAPI int lcWndZoomPos(void *hLcWnd, double Xc, double Yc, double PixSize) {
  return 1;
}

LCAPI int lcWndZoomEnt(void *hLcWnd, void *hEnt, double Scal) {
  return 1;
}

// coordinates
LCAPI int lcWndGetCursorCoord(void *hLcWnd, int *pXwin, int *pYwin, double *pXdrw, double *pYdrw) {
  return 1;
}

LCAPI int lcCoordDrwToWnd(void *hLcWnd, double Xdrw, double Ydrw, int *pXwnd, int *pYwnd) {
  return 1;
}

LCAPI int lcCoordWndToDrw(void *hLcWnd, int Xwnd, int Ywnd, double *pXdrw, double *pYdrw) {
  return gllc_window_coord_to_drw((struct gllc_window *)hLcWnd, Xwnd, Ywnd, pXdrw, pYdrw);
}

LCAPI int lcWndCoordFromDrw(void *hLcWnd, double Xdrw, double Ydrw, int *pXwin, int *pYwin) {
  return gllc_window_coord_to_wnd((struct gllc_window *)hLcWnd, Xdrw, Ydrw, pXwin, pYwin);
}

LCAPI int lcWndCoordToDrw(void *hLcWnd, int Xwin, int Ywin, double *pXdrw, double *pYdrw) {
  return 1;
}

// retrieve entities
LCAPI void *lcWndGetEntByPoint(void *hLcWnd, int Xwin, int Ywin) {
  return gllc_window_get_ent_by_point((struct gllc_window *)hLcWnd, Xwin, Ywin);
}

LCAPI void *lcWndGetEntByPoint2(void *hLcWnd, double X, double Y, double Delta) { return NULL; }
LCAPI int lcWndGetEntsByPoint(void *hLcWnd, int Xwin, int Ywin, int nMaxEnts) { return 0; }
LCAPI int lcWndGetEntsByRect(void *hLcWnd, double Lef, double Bot, double Rig, double Top, int bCross, int nMaxEnts) { return 0; }
LCAPI void *lcWndGetEntity(int iEnt) { return NULL; }
LCAPI void *lcWndGetEntByID(void *hLcWnd, int Id) { return NULL; }
LCAPI void *lcWndGetEntByIDH(void *hLcWnd, char *szId) { return NULL; }
LCAPI void *lcWndGetEntByKey(void *hLcWnd, int Key) { return NULL; }
LCAPI int lcWndPickEnt(void *hLcWnd, char *szTitle, char *szCursorText) { return 0; }

// Font functions
LCAPI void *lcFontGetFirst() { return NULL; }
LCAPI void *lcFontGetNext(void *hFont) { return NULL; }
LCAPI void *lcFontAddRes(char *szFontName, void *hModule, int idResource) { return NULL; }
LCAPI void *lcFontAddFile(char *szFontName, char *szFilename, char *szOutFontName) { return NULL; }
LCAPI void *lcFontAddBin(char *szFontName, void *hData) { return NULL; }
LCAPI void *lcFontGetChar(void *hFont, int CharCode) { return NULL; }
LCAPI char *lcFontGetName(char *szFilename) { return NULL; }

// Progress indicator
LCAPI int lcProgressCreate(void *hLcWnd, int W, int H, char *szTitle) { return 0; }
LCAPI int lcProgressSetText(char *szText) { return 0; }
LCAPI int lcProgressStart(int MinVal, int MaxVal) { return 0; }
LCAPI int lcProgressSetPos(int Val) { return 0; }
LCAPI int lcProgressInc() { return 0; }
LCAPI int lcProgressDelete() { return 0; }

// Quadrangle point coordinates
LCAPI void *lcQuadCreate() { return NULL; }
LCAPI int lcQuadDelete(void *hQuad) { return 0; }
LCAPI int lcQuadSet(void *hQuad, double x0, double y0, double x1, double y1, double x2, double y2, double x3, double y3) { return 0; }
LCAPI int lcQuadTransXYtoUV(void *hQuad, double X, double Y, double *pU, double *pV) { return 0; }
LCAPI int lcQuadTransUVtoXY(void *hQuad, double U, double V, double *pX, double *pY) { return 0; }
LCAPI int lcQuadContains(void *hQuad, double X, double Y) { return 0; }

// Array of Quadrangles
LCAPI void *lcGridCreate() { return NULL; }
LCAPI int lcGridDelete(void *hGrid) { return 0; }
LCAPI int lcGridSet(void *hGrid, double X0, double Y0, double W, double H, int Nx, int Ny) { return 0; }
LCAPI int lcGridSetDest(void *hGrid, int Ix, int Iy, double X, double Y) { return 0; }
LCAPI int lcGridUpdate(void *hGrid) { return 0; }
LCAPI int lcGridTrans(void *hGrid, double X, double Y, double *pXdest, double *pYdest) { return 0; }
LCAPI int lcGridGetNode(void *hGrid, int bDest, int Ix, int Iy, double *pX, double *pY) { return 0; }
LCAPI int lcGridGetCell(void *hGrid, double X, double Y, int *pIx, int *pIy) { return 0; }
LCAPI int lcGridSetView(void *hGrid, int Mode, void *hLcWnd, int ColLine, int ColNode) { return 0; } // Mode: 0-disable, 1-original, 2-destination

// Command Window
LCAPI void *lcCreateCmdwin(void *hWndParent, int Left, int Top, int Width, int Height) { return NULL; }
LCAPI int lcCmdwinResize(void *hCmdLine, int Left, int Top, int Width, int Height) { return 0; }
LCAPI int lcCmdwinUpdate(void *hCmdLine) { return 0; } // undoc

// Properties Window
LCAPI void *lcCreateProps(void *hWndParent, int Mode) { return NULL; }
LCAPI int lcDeleteProps(void *hPropWnd) { return 0; }
LCAPI int lcPropsResize(void *hPropWnd, int Left, int Top, int Width, int Height) { return 0; }
LCAPI int lcPropsUpdate(void *hPropWnd, int bSelChanged) { return 0; }

// Status Bar
LCAPI void *lcCreateStatbar(void *hWndParent) { return NULL; } // also LC_PROP_SBAR_H and others
LCAPI int lcDeleteStatbar(void *hStatbar) { return 0; }
LCAPI int lcStatbarResize(void *hStatbar, int Left, int Top, int Width, int Height) { return 0; }
LCAPI int lcStatbarCell(void *hStatbar, int Id, int Pos) { return 0; }
LCAPI int lcStatbarText(void *hStatbar, int Id, char *szText) { return 0; }
LCAPI int lcStatbarRedraw(void *hStatbar) { return 0; }

// utility functions
LCAPI int lcDgGetValue(void *hWnd, int Lef, int Top, char *szTitle, char *szPrompt) { return 0; }
LCAPI int lcHelp(char *szTopic) { return 0; }
void LCAPI lcGetPolarPoint(double x0, double y0, double Angle, double Dist, double *pOutX, double *pOutY) {
}
void LCAPI lcGetPolarPrm(double x1, double y1, double x2, double y2, double *pAngle, double *pDist) {
}
LCAPI int lcGetClientSize(void *hWnd, int *pWidth, int *pHeight) { return 0; }
LCAPI int lcGetErrorCode() { return 0; }
LCAPI char *lcGetErrorStr() { return NULL; }
LCAPI int lcGetStr(int Mode) { return 0; }
LCAPI int lcGetDrwXData(char *szFileName) { return 0; }
LCAPI int lcGetDrwPreview(char *szFileName, unsigned char *pOutDIB) { return 0; }
LCAPI int lcFilletSetLines(double L1x0, double L1y0, double L1x1, double L1y1, double L2x0, double L2y0, double L2x1, double L2y1) { return 0; }
LCAPI int lcFillet(double Rad, double Bis, double Tang) { return 0; }
LCAPI int lcFilletGetPoint(int iPnt, double *pX, double *pY) { return 0; }
LCAPI int lcFileToStrA(char *szFileName, char *pBuf) { return 0; }

// Custom command interface
LCAPI void *lcCreateCommand(void *hLcWnd, int Id, char *szTitle) { return NULL; }
LCAPI int lcCmdExit(void *hCmd) { return 0; }
LCAPI int lcCmdCursorText(void *hCmd, char *szText) { return 0; }
LCAPI int lcCmdMessage(void *hCmd, char *szText, int uType) { return 0; }
LCAPI int lcCmdResetLastPt(void *hCmd) { return 0; }

LCAPI int lcTIS_InitLibrary(char *szLicenseKey, int bErrMsg) { return 0; }
LCAPI int lcTIS_CloseLibrary() { return 0; }
LCAPI int lcCameraConnect(char *szName) { return 0; } // LC_PROP_G_CAMERA_COUNT
LCAPI int lcCameraDisconnect() { return 0; }
LCAPI int lcCameraShot() { return 0; }

//-----------------------------------------------------------------------------
// Drawing
//-----------------------------------------------------------------------------
LCAPI void *lcCreateDrawing() {
  return gllc_drw_create();
}
LCAPI int lcDeleteDrawing(void *hDrw) { return 0; }
LCAPI int lcDrwNew(void *hDrw, char *szFileName, void *hLcWnd) { return 0; }
LCAPI int lcDrwLoad(void *hDrw, char *szFileName, void *hLcWnd) { return 0; }
LCAPI int lcDrwLoadMem(void *hDrw, void *hMem, void *hLcWnd) { return 0; }
LCAPI int lcDxfLoadMem(void *hDrw, void *hMem, void *hLcWnd) { return 0; }
LCAPI void *lcDrwLoadTIN(void *hDrw, char *szFileName, void *hLcWnd) { return NULL; }
LCAPI int lcDrwSaveTIN(void *hDrw, void *hLcWnd) { return 0; }
LCAPI int lcDrwInsert(void *hDrw, char *szFileName, int Overwrite,
                      void *hLcWnd) { return 0; }
LCAPI int lcDrwInsertSHP(void *hDrw, void *hLayer, char *szFileName,
                         void *hLcWnd) { return 0; }
LCAPI int lcDrwCopy(void *hDrw, void *hDrwSrc) { return 0; }
LCAPI int lcDrwSave(void *hDrw, char *szFileName, int bBak, void *hLcWnd) { return 0; }
LCAPI int lcDrwSaveMem(void *hDrw, void *hMem, int MemSize) { return 0; }

LCAPI void *lcDrwAddLayer(void *hDrw, char *szName, char *szColor, void *hLtype,
                          int Lwidth) {
  return gllc_drw_add_layer((struct gllc_drawing *)hDrw, szName, szColor, (struct gllc_linetype *)hLtype, Lwidth);
}
LCAPI void *lcDrwAddLayer2(void *hDrw, char *szName, void *hFromLayer) { return NULL; }
LCAPI void *lcDrwAddLinetype(void *hDrw, char *szName, char *szDefinition) { return NULL; }
LCAPI void *lcDrwAddLinetypeF(void *hDrw, char *szName, char *szFileName,
                              char *szLtypeName) {
}
LCAPI void *lcDrwAddTextStyle(void *hDrw, char *szName, char *szFontName,
                              int bWinFont) {
}
LCAPI void *lcDrwAddDimStyle(void *hDrw, char *szName) { return NULL; }
LCAPI void *lcDrwAddMlineStyle(void *hDrw, char *szName) { return NULL; }
LCAPI void *lcDrwAddPntStyle(void *hDrw, char *szName, void *hBlock,
                             double BlockScale, void *hTStyle,
                             double TextHeight, double TextWidth) {
}
LCAPI void *lcDrwAddFilling(void *hDrw, char *szName) { return NULL; }
LCAPI void *lcDrwAddImage(void *hDrw, char *szName, char *szFileName) { return NULL; }
LCAPI void *lcDrwAddImage2(void *hDrw, char *szName, int Width, int Height,
                           int nBits, void *hData, int bTopDown) {
}
LCAPI void *lcDrwAddImage3(void *hDrw, char *szName, void *hMem) { return NULL; }
LCAPI void *lcDrwAddImageCam(void *hDrw, char *szName) { return NULL; }
LCAPI void *lcDrwAddBlock(void *hDrw, char *szName, double X, double Y) {
  return gllc_drw_add_block(hDrw, szName, X, Y);
}
LCAPI void *lcDrwAddBlockFromFile(void *hDrw, char *szName, char *szFileName,
                                  int Overwrite, void *hwParent) {
}
LCAPI void *lcDrwAddBlockFromDrw(void *hDrw, char *szName, void *hDrw2,
                                 int Overwrite, void *hwParent) {
}
LCAPI void *lcDrwAddBlockFile(void *hDrw, char *szName, char *szFileName,
                              int Overwrite, void *hwParent) {
}
LCAPI void *lcDrwAddBlockPaper(void *hDrw, char *szName, int PaperSize,
                               int Orient, double Width, double Height) {
}
LCAPI void *lcDrwAddBlockCopy(void *hDrw, char *szName, void *hSrcBlock) { return NULL; }

LCAPI int lcDrwDeleteObject(void *hDrw, void *hObject) { return 0; }
LCAPI int lcDrwDeleteUnused(void *hDrw, int ObjType) { return 0; } // undoc
LCAPI int lcDrwCountObjects(void *hDrw, int ObjType) { return 0; }
LCAPI int lcDrwSortObjects(void *hDrw, int ObjType) { return 0; }
LCAPI int lcDrwUpdateWinFonts(void *hDrw, void *hTStyle) { return 0; }
LCAPI int lcDrwUpdateBlkRefs(void *hDrw, void *hBlock) { return 0; }
LCAPI int lcDrwUpdateTexts(void *hDrw, void *hTStyle) { return 0; }

LCAPI void *lcDrwGetFirstObject(void *hDrw, int ObjType) { return NULL; }
LCAPI void *lcDrwGetNextObject(void *hDrw, void *hObject) { return NULL; }
LCAPI void *lcDrwGetObjectByID(void *hDrw, int ObjType, int Id) { return NULL; }
LCAPI void *lcDrwGetObjectByIDH(void *hDrw, int ObjType, char *szId) { return NULL; }
LCAPI void *lcDrwGetObjectByName(void *hDrw, int ObjType, char *szName) { return NULL; }
LCAPI void *lcDrwGetEntByID(void *hDrw, int Id) { return NULL; }
LCAPI void *lcDrwGetEntByIDH(void *hDrw, char *szId) { return NULL; }
LCAPI void *lcDrwGetEntByKey(void *hDrw, int Key) { return NULL; }

LCAPI int lcDrwClearXData(void *hDrw, int ObjType, int Mode) { return 0; }
LCAPI int lcDrwPurge(void *hDrw) { return 0; }
LCAPI int lcDrwExplode(void *hDrw, int Mode) { return 0; }
LCAPI int lcDrwSetLimits(void *hDrw, double Xmin, double Ymin, double Xmax,
                         double Ymax) {
}

LCAPI int lcDrwUndoRecord(void *hDrw, int Mode) { return 0; }
LCAPI int lcDrwUndo(void *hDrw, int bRedo) { return 0; }

// Clipping rectangles (also LC_PROP_CRECT_ID and others)
LCAPI int lcCRectsClear(void *hDrw) { return 0; }
LCAPI int lcCRectsAdd(void *hDrw, int ID, double Lef, double Bot, double Width,
                      double Height) {
}
LCAPI int lcCRectsDivide(void *hDrw, int NumX, int NumY, int bClearExist) { return 0; }
LCAPI void *lcCRectsGetFirst(void *hDrw) { return NULL; }
LCAPI void *lcCRectsGetNext(void *hDrw, void *hCRect) { return NULL; }
LCAPI void *lcCRectsGetWithID(void *hDrw, int Id) { return NULL; }
LCAPI int lcCRectsActive(void *hDrw, void *hCRect) { return 0; }
LCAPI void *lcCRectsGetActive(void *hDrw) { return NULL; }
LCAPI int lcCRectsDelete(void *hDrw, void *hCRect) { return 0; }
LCAPI int lcCRectsSave(void *hDrw, void *hCRect, char *szFileName) { return 0; }
LCAPI int lcCRectsBitmap(void *hDrw, void *hCRect, char *szFileName,
                         double PixelSize) {
}

// Block
LCAPI int lcBlockSetViewRect(void *hBlock, double Xcen, double Ycen,
                             double Width, double Height) {
}
LCAPI int lcBlockSetViewRect2(void *hBlock, double Lef, double Bot, double Rig,
                              double Top) {
}
LCAPI int lcBlockSetPaperSize(void *hBlock, int PaperSize, int Orient,
                              double Width, double Height) {
}
LCAPI int lcBlockRasterize(void *hBlock, char *szFileName, double Xmin,
                           double Ymin, double Xmax, double Ymax, int ImgW,
                           int ImgH) {
}
LCAPI int lcBlockRasterizeMem(void *hBlock, void *hMem, double Xmin,
                              double Ymin, double Xmax, double Ymax, int ImgW,
                              int ImgH) {
}
LCAPI int lcBlockUpdate(void *hBlock, int bUpdEnts, void *hNewEnt) {
  gllc_block_update(hBlock);
  return 1;
}
LCAPI int lcBlockMove(void *hBlock, double dX, double dY, int bUpdate) { return 0; }
LCAPI int lcBlockScale(void *hBlock, double X, double Y, double Scal,
                       int bUpdate) {
}
LCAPI int lcBlockRotate(void *hBlock, double X, double Y, double Angle,
                        int bUpdate) {
}
LCAPI int lcBlockMirror(void *hBlock, double X1, double Y1, double X2,
                        double Y2, int bUpdate) {
}

// Add graphic objects into a block
LCAPI int lcBlockClear(void *hBlock, void *hLayer) { return 0; }
LCAPI int lcBlockPurge(void *hBlock) { return 0; }
LCAPI int lcBlockSortEnts(void *hBlock, int bByLayers, void *hWnd) { return 0; }
LCAPI int lcBlockSortEnts2(void *hBlock, void *idEnts,
                           int nEnts) {

} // for DWG plugin
LCAPI void *lcBlockAddPoint(void *hBlock, double X, double Y) { return NULL; }
LCAPI void *lcBlockAddPoint2(void *hBlock, double X, double Y, int PtMode,
                             double PtSize) {
}
LCAPI void *lcBlockAddPoint3d(void *hBlock, double X, double Y, double Z) { return NULL; }
LCAPI int lcBlockAddPointsF(void *hBlock, char *szFileName, void *hWnd) { return 0; }
LCAPI void *lcBlockAddXline(void *hBlock, double X, double Y, double Angle,
                            int bRay) {
}
LCAPI void *lcBlockAddXline2P(void *hBlock, double X, double Y, double X2,
                              double Y2, int bRay) {
}
LCAPI void *lcBlockAddLine(void *hBlock, double X1, double Y1, double X2,
                           double Y2) {
  double p0[2] = {X1, Y1};
  double p1[2] = {X2, Y2};
  return gllc_block_add_line((struct gllc_block *)hBlock, p0, p1);
}
LCAPI void *lcBlockAddLineDir(void *hBlock, double X, double Y, double Angle,
                              double Dist) {
}
LCAPI void *lcBlockAddLineTan(void *hBlock, void *hEnt1, void *hEnt2, int Mode) { return NULL; }
LCAPI void *lcBlockAddPolyline(void *hBlock, int FitType, int bClosed,
                               int bFilled) {
  return gllc_block_add_polyline(hBlock, bClosed, bFilled);
}
LCAPI void *lcBlockAddRPolygon(void *hBlock, int nVers, double Xc, double Yc,
                               double R, double Ang0, int bInscribed,
                               int bFilled) {
  return NULL;
}
LCAPI void *lcBlockAddSpline(void *hBlock, int bClosed, int bFilled) { return NULL; }
LCAPI void *lcBlockAddBezier(void *hBlock) { return NULL; }
LCAPI void *lcBlockAddMline(void *hBlock, int FitType, int bClosed) { return NULL; }
LCAPI void *lcBlockAddRect(void *hBlock, double Xc, double Yc, double Width,
                           double Height, double Angle, int bFilled) {
  return gllc_block_add_rect((struct gllc_block *)hBlock, (double[]){Xc, Yc}, Width, Height, Angle, bFilled);
}
LCAPI void *lcBlockAddRect2(void *hBlock, double Left, double Bottom,
                            double Width, double Height, double Rad,
                            int bFilled) {
}
LCAPI void *lcBlockAddCircle(void *hBlock, double X, double Y, double Radius,
                             int bFilled) {
  return gllc_block_add_circle((struct gllc_block *)hBlock, X, Y, Radius, bFilled);
}
LCAPI void *lcBlockAddArc(void *hBlock, double X, double Y, double Radius,
                          double StartAngle, double ArcAngle) {
  return gllc_block_add_arc((struct gllc_block *)hBlock, X, Y, Radius, StartAngle, ArcAngle);
}
LCAPI void *lcBlockAddArc3P(void *hBlock, double X1, double Y1, double X2,
                            double Y2, double X3, double Y3) {
  return NULL;
}
LCAPI void *lcBlockAddFillet(void *hBlock, void *hEnt1, void *hEnt2,
                             double Radius) {
  return NULL;
}
LCAPI void *lcBlockAddEllipse(void *hBlock, double X, double Y, double R1,
                              double R2, double RotAngle, double StartAngle,
                              double ArcAngle) {
  return NULL;
}
LCAPI void *lcBlockAddText(void *hBlock, char *szText, double X, double Y) { return NULL; }
LCAPI void *lcBlockAddText2(void *hBlock, char *szText, double X, double Y,
                            int Align, double H, double WScale, double RotAngle,
                            double Oblique) {
  return NULL;
}
LCAPI void *lcBlockAddText3(void *hBlock, char *szText, double X1, double Y1,
                            double X2, double Y2, int Align, double HW,
                            double Oblique) {
  return NULL;
}
LCAPI void *lcBlockAddTextWin(void *hBlock, char *szText, double X, double Y) { return NULL; }
LCAPI void *lcBlockAddTextWin2(void *hBlock, char *szText, double X, double Y,
                               int Align, double H, double WScale,
                               double RotAngle, double Oblique) {
  return NULL;
}
LCAPI void *lcBlockAddMText(void *hBlock, char *szText, double X, double Y,
                            double WrapWidth, int Align, double RotAngle,
                            double H, double WScale) {
  return NULL;
}
LCAPI void *lcBlockAddArcText(void *hBlock, char *szText, double X, double Y,
                              double Radius, double StartAngle, int bClockwise,
                              double H, double WScale, int Align) {
  return NULL;
}
LCAPI void *lcBlockAddBlockRef(void *hBlock, void *hRefBlock, double X,
                               double Y, double Scal, double Angle) {
  return NULL;
}
LCAPI void *lcBlockAddBlockRefID(void *hBlock, int idRefBlock, double X,
                                 double Y, double Scal, double Angle) {
  return NULL;
} // undoc
LCAPI void *lcBlockAddBlockRefIDH(void *hBlock, char *szIdRefBlock, double X,
                                  double Y, double Scal, double Angle) {
  return NULL;
} // undoc
LCAPI void *lcBlockAddAttDef(void *hBlock, int Mode, char *szTag,
                             char *szPrompt, char *szDefVal, double X, double Y,
                             int Align, double H, double WScale,
                             double RotAngle, double Oblique) {
  return NULL;
}
LCAPI void *lcBlockAddXref(void *hBlock, char *szFileName, double X, double Y,
                           double ScalX, double ScalY, double Angle) {
  return NULL;
}
LCAPI void *lcBlockAddImageRef(void *hBlock, void *hImage, double X, double Y,
                               double Width, double Height, int bBorder) {
  return NULL;
}
LCAPI void *lcBlockAddImageRefUns(void *hBlock, void *hImage, double X,
                                  double Y, double Scal, int Align,
                                  int bBorder) {
  return NULL;
}
LCAPI void *lcBlockAddImagePlace(void *hBlock, int Id, double X, double Y,
                                 double Width, double Height, int bBorder) {
  return NULL;
}
LCAPI void *lcBlockAddEcw(void *hBlock, char *szFileName) { return NULL; }
LCAPI void *lcBlockAddBarcode(void *hBlock, int BarType, double Xc, double Yc,
                              double Width, double Height, char *szText) {
  return NULL;
}
LCAPI void *lcBlockAddHatch(void *hBlock, char *szFileName, char *szPatName,
                            double Scal, double Angle) {
  return NULL;
}
LCAPI void *lcBlockAddViewport(void *hBlock, double Lef, double Bot,
                               double Width, double Height, double DrwPntX,
                               double DrwPntY, double DrwScale,
                               double DrwAngle) {
  return NULL;
}
LCAPI void *lcBlockAddFace(void *hBlock, int Flags, double x0, double y0,
                           double z0, double x1, double y1, double z1,
                           double x2, double y2, double z2) {
  return NULL;
}
LCAPI void *lcBlockAddFace4(void *hBlock, int Flags, double x0, double y0,
                            double z0, double x1, double y1, double z1,
                            double x2, double y2, double z2, double x3,
                            double y3, double z3) {
  return NULL;
}
LCAPI void *lcBlockAddLeader(void *hBlock, char *szText, double Xt, double Yt,
                             double LandDist, double Xa, double Ya, int Attach,
                             int Align) {
  return NULL;
}
LCAPI void *lcBlockAddDimLin(void *hBlock, double X0, double Y0, double X1,
                             double Y1, double Xt, double Yt, double Angle,
                             char *szText) {
  return NULL;
}
LCAPI void *lcBlockAddDimHor(void *hBlock, double X0, double Y0, double X1,
                             double Y1, double Yt, char *szText) {
  return NULL;
}
LCAPI void *lcBlockAddDimVer(void *hBlock, double X0, double Y0, double X1,
                             double Y1, double Xt, char *szText) {
  return NULL;
}
LCAPI void *lcBlockAddDimAli(void *hBlock, double X0, double Y0, double X1,
                             double Y1, double Xt, double Yt, char *szText) {
  return NULL;
}
LCAPI void *lcBlockAddDimAli2(void *hBlock, double X0, double Y0, double X1,
                              double Y1, double Dt, char *szText) {
  return NULL;
}
LCAPI void *lcBlockAddDimOrd(void *hBlock, double Xd, double Yd, double Xt,
                             double Yt, int bX, char *szText) {
  return NULL;
}
LCAPI void *lcBlockAddDimRad(void *hBlock, double Xc, double Yc, double Xr,
                             double Yr, double Xt, double Yt, char *szText) {
  return NULL;
}
LCAPI void *lcBlockAddDimRad2(void *hBlock, double Xc, double Yc, double R,
                              double Angle, double TextOff, char *szText) {
}
LCAPI void *lcBlockAddDimDia(void *hBlock, double Xc, double Yc, double Xr,
                             double Yr, double Xt, double Yt, char *szText) {
  return NULL;
}
LCAPI void *lcBlockAddDimDia2(void *hBlock, double Xc, double Yc, double R,
                              double Angle, double TextOff, char *szText) {
  return NULL;
}
LCAPI void *lcBlockAddDimAng(void *hBlock, double Xc, double Yc, double X1,
                             double Y1, double X2, double Y2, double Xa,
                             double Ya, double TextPos, char *szText) {
  return NULL;
}
LCAPI void *lcBlockAddDimAng2(void *hBlock, double X1, double Y1, double X2,
                              double Y2, double X3, double Y3, double X4,
                              double Y4, double Xa, double Ya, double TextPos,
                              char *szText) {
}
LCAPI void *lcBlockAddRPlan(void *hBlock) { return NULL; }
LCAPI void *lcBlockAddRPlan2(void *hBlock, void *hStartEnt) { return NULL; }
LCAPI void *lcBlockAddArrow(void *hBlock, double X1, double Y1, double X2,
                            double Y2) {
  return NULL;
}
LCAPI void *lcBlockAddSpiral(void *hBlock, double Xc, double Yc, double R,
                             double Turns, int bDirCW, int bClosed) {
  return NULL;
}
LCAPI void *lcBlockAddCamview(void *hBlock, double Lef, double Bot, double Width, double Height) {
  return NULL;
}
LCAPI void *lcBlockAddTIN(void *hBlock, char *szFileName, int FileType) { return NULL; }
LCAPI void *lcBlockAddClone(void *hBlock, void *hEnt) { return NULL; }
LCAPI int lcBlockBeginShape(void *hBlock) { return 0; }
LCAPI void *lcBlockAddShape(void *hBlock) { return NULL; }
LCAPI void *lcBlockAddShapeSel(void *hBlock, int bErase) { return NULL; }
LCAPI void *lcBlockRepEllipse(void *hBlock, void *hEll, int *pRetType) { return NULL; }
LCAPI int lcBlockJoinAll(void *hBlock, double Delta) { return 0; }
LCAPI int lcBlockCopyLayer(void *hBlock, void *hLayerSrc, void *hLayerDest) { return 0; }
LCAPI int lcBlockDeleteEnt(void *hBlock, void *hEnt) { return 0; }

// Retrieve graphic objects from a block
LCAPI void *lcBlockGetFirstEnt(void *hBlock) { return NULL; }
LCAPI void *lcBlockGetNextEnt(void *hBlock, void *hEnt) { return NULL; }
LCAPI void *lcBlockGetLastEnt(void *hBlock) { return NULL; }
LCAPI void *lcBlockGetPrevEnt(void *hBlock, void *hEnt) { return NULL; }
LCAPI void *lcBlockGetEntByID(void *hBlock, int Id) { return NULL; }
LCAPI void *lcBlockGetEntByIDH(void *hBlock, char *szId) { return NULL; }
LCAPI void *lcBlockGetEntByKey(void *hBlock, int Key) { return NULL; }
LCAPI void *lcBlockGetBlkRefByTag(void *hBlock, void *hBlockAtt, char *szTag,
                                  char *szValue, int bSelect) {
}
LCAPI void *lcBlockGetTIN(void *hBlock, char *szName) { return NULL; }

// Selection
LCAPI int lcBlockUnselect(void *hBlock) { return 0; }
LCAPI int lcBlockSelectEnt(void *hBlock, void *hEntity, int bSelect) { return 0; }
LCAPI int lcBlockSelErase(void *hBlock) { return 0; }
LCAPI int lcBlockSelMove(void *hBlock, double dX, double dY, int bCopy,
                         int bNewSelect) {
}
LCAPI int lcBlockSelScale(void *hBlock, double X0, double Y0, double Scal,
                          int bCopy, int bNewSelect) {
}
LCAPI int lcBlockSelRotate(void *hBlock, double X0, double Y0, double Angle,
                           int bCopy, int bNewSelect) {
}
LCAPI int lcBlockSelMirror(void *hBlock, double X1, double Y1, double X2,
                           double Y2, int bCopy, int bNewSelect) {
}
LCAPI int lcBlockSelExplode(void *hBlock) { return 0; }
LCAPI int lcBlockSelSplit(void *hBlock, int nParts) { return 0; }
LCAPI void *lcBlockSelJoin(void *hBlock, double Delta) { return NULL; }
LCAPI int lcBlockSelAlign(void *hBlock, int Mode, double X, double Y) { return 0; }
LCAPI void *lcBlockSelBlock(void *hBlock, char *szName, double X, double Y,
                            int Mode, int bOverwrite) {
}
LCAPI void *lcBlockGetFirstSel(void *hBlock) { return NULL; }
LCAPI void *lcBlockGetNextSel(void *hBlock) { return NULL; }

// change entities order by layer
LCAPI int lcBlockOrderByLayers(void *hBlock, void *hWnd) { return 0; }
LCAPI int lcBlockSortTSP(void *hBlock, void *hLayer, void *hWnd) { return 0; }
double LCAPI lcBlockGetJumpsLen(void *hBlock, void *hLayer, void *hWnd) { return 0.0f; }

// remove entities of specified layer from a block (all blocks if hBlock=0)
LCAPI int lcLayerClear(void *hLayer, void *hBlock) { return 0; }
LCAPI int lcLayerCopyProps(void *hLayer, void *hFromLayer) { return 0; }

// add line to a filling (see also lcDrwAddFilling)
LCAPI int lcFillSetLine(void *hFill, int iLine, double Dist, double Angle,
                        double W) {
}

// Mline style
LCAPI int lcMLStyleAddLine(void *hStyle, double Offset, char *szColor,
                           void *hLtype) { return 0; }
LCAPI int lcMLStyleDelLine(void *hStyle, int iLine) { return 0; }
LCAPI int lcMLStyleSortLines(void *hStyle) { return 0; }

LCAPI int lcEntType(void *hEnt, int Typ) { return 0; }

// Graphic object modify
LCAPI int lcEntErase(void *hEnt, int bErase) { return 0; }
LCAPI int lcEntMove(void *hEnt, double dX, double dY) { return 0; }
LCAPI int lcEntAlign(void *hEnt, int Alignment, double X, double Y) { return 0; }
LCAPI int lcEntScale(void *hEnt, double X0, double Y0, double Scal) { return 0; }
LCAPI int lcEntRotate(void *hEnt, double X0, double Y0, double Angle) { return 0; }
LCAPI int lcEntMirror(void *hEnt, double X1, double Y1, double X2, double Y2) { return 0; }
LCAPI int lcEntExplode(void *hEnt, int bSelect, int bErase) { return 0; }
LCAPI void *lcEntSplit(void *hEnt, int nParts, int bSelectNew, int bDeleteEnt) { return NULL; }
LCAPI void *lcEntBreak(void *hEnt, double X, double Y, double Delta,
                       int bSelectNew, int bDeleteEnt) {
}
LCAPI void *lcEntBreak2(void *hEnt, void *hPtbuf, double Delta, int bSelectNew,
                        int bDeleteEnt) {
}
LCAPI int lcEntOffset(void *hEnt, double Dist) { return 0; }
LCAPI int lcEntExtend(void *hEnt, void *hEntEdge, int bApparent) { return 0; }
LCAPI int lcEntToTop(void *hEnt) { return 0; }
LCAPI int lcEntToBottom(void *hEnt) { return 0; }
LCAPI int lcEntToAbove(void *hEnt, void *hEnt2) { return 0; }
LCAPI int lcEntToUnder(void *hEnt, void *hEnt2) { return 0; }
LCAPI int lcEntGetGrip(void *hEnt, int iGrip, double *pX, double *pY) { return 0; }
LCAPI int lcEntPutGrip(void *hEnt, int iGrip, double X, double Y) { return 0; }
LCAPI int lcEntUpdate(void *hEnt) { return 0; }
LCAPI int lcEntCopyBase(void *hEnt, void *hEntFrom) { return 0; }
LCAPI int lcEntXData(void *hEnt, int Id, int Flags, int nBytes) { return 0; }
LCAPI int lcEntContainEnt(void *hEnt, void *hEnt2) { return 0; }
LCAPI int lcEntCrossEnt(void *hEnt, void *hEnt2) { return 0; }
LCAPI int lcEntReverse(void *hEnt) { return 0; }
LCAPI int lcEntGetPoint(void *hEnt, double Dist, double *pX, double *pY,
                        double *pAngle) {
}
double LCAPI lcEntGetDist(void *hEnt, double X, double Y, double *pX2,
                          double *pY2, double *pDist) {
}
LCAPI int lcEntTransform(void *hEnt, void *hTransform) { return 0; }
LCAPI int lcIntersection(void *hEnt, void *hEnt2, int Apparent) { return 0; }
LCAPI int lcInterGetPoint(int iPoint, double *pX, double *pY) { return 0; }

LCAPI int lcLineGetPoint(void *hLine, int Mode, double Dist, double *pX,
                         double *pY) {
}

// Polyline Vertices
LCAPI void *lcPlineAddVer(void *hPline, void *hVer, double X, double Y) {
  gllc_pline_add_ver(hPline, X, Y);
  return NULL;
}
LCAPI void *lcPlineAddVer2(void *hPline, void *hVer, double X, double Y,
                           double Param, double W0, double W1) {
}
LCAPI void *lcPlineAddVerDir(void *hPline, void *hVer, double Ang,
                             double Length) {
}
LCAPI int lcPlineEnd(void *hPline) {
  gllc_pline_end((struct gllc_polyline *)hPline);
  return 1;
}
LCAPI int lcPlineFromPtbuf(void *hPline, void *hPtbuf) { return 0; }
LCAPI int lcPlineFromMpgon(void *hPline, void *hMpgon) { return 0; }
LCAPI int lcPlineFromFile(void *hPline, char *szFileName) { return 0; }
LCAPI int lcPlineDeleteVer(void *hPline, void *hVer) { return 0; }
LCAPI int lcPlineDelExVers(void *hPline, double Delta) { return 0; }
LCAPI void *lcPlineGetFirstVer(void *hPline) { return NULL; }
LCAPI void *lcPlineGetNextVer(void *hPline, void *hVer) { return NULL; }
LCAPI void *lcPlineGetLastVer(void *hPline) { return NULL; }
LCAPI void *lcPlineGetPrevVer(void *hPline, void *hVer) { return NULL; }
LCAPI void *lcPlineGetVer(void *hPline, int Index) { return NULL; }
LCAPI void *lcPlineGetVerPt(void *hPline, double X, double Y, double Delta) { return NULL; }
LCAPI void *lcPlineGetSeg(void *hPline, double X, double Y, double Delta) { return NULL; }
LCAPI int lcPlineReverse(void *hPline) { return 0; }
LCAPI int lcPlineSetStartVer(void *hPline, void *hVer) { return 0; }
LCAPI int lcPlineContainPoint(void *hPline, double X, double Y) { return 0; }
LCAPI int lcPlineGetRoundPrm(void *hPline, void *hVer, double *pX0, double *pY0,
                             double *pBulge, double *pX1,
                             double *pY1) {
} // undoc (dwg plugin)
LCAPI int lcPlineGetPoint(void *hPline, double Dist, double *pX, double *pY,
                          double *pAngle) {
}
LCAPI int lcPlineGetPointOpp(void *hPline, double Dist, double *pX, double *pY,
                             double *pAngle, double *pX2, double *pY2) {
}
double LCAPI lcPlineGetDist(void *hPline, double X, double Y, double *pX2,
                            double *pY2, double *pDist) {
}
LCAPI int lcPlineDivide(void *hPline, int nPoints, int bAngle) { return 0; }
LCAPI int lcPlineDivide2(void *hPline, double Delta, int bAngle) { return 0; }
LCAPI int lcGetDivPt(int iPnt, double *pX, double *pY, double *pAngle) { return 0; }
LCAPI int lcPlineMakeArrow(void *hPline, double Hline, double Harr) { return 0; }    // undoc
LCAPI void *lcPlineSplitBySI(void *hPline, int bSelect, int bErase) { return NULL; } // undoc

// Bezier Vertices
LCAPI void *lcBezierAddVer(void *hBez, void *hVer, double X, double Y) { return NULL; }
LCAPI int lcBezierEnd(void *hBez) { return 0; }
LCAPI int lcBezierSetVerPrm(void *hBez, void *hVer, int Side, double Leng,
                            double Ang) {
}

// Mline Vertices
LCAPI void *lcMlineAddVer(void *hMline, void *hVer, double X, double Y) { return NULL; }
LCAPI void *lcMlineAddVerDir(void *hMline, void *hVer, double Ang,
                             double Length) {
}
LCAPI int lcMlineDeleteVer(void *hMline, void *hVer) { return 0; }
LCAPI void *lcMlineGetFirstVer(void *hMline) { return NULL; }
LCAPI void *lcMlineGetNextVer(void *hMline, void *hVer) { return NULL; }
LCAPI void *lcMlineGetLastVer(void *hMline) { return NULL; }
LCAPI void *lcMlineGetPrevVer(void *hMline, void *hVer) { return NULL; }
LCAPI void *lcMlineGetVer(void *hMline, int Index) { return NULL; }
LCAPI void *lcMlineGetVerPt(void *hMline, double X, double Y, double Delta) { return NULL; }
LCAPI void *lcMlineGetSeg(void *hMline, double X, double Y,
                          double Delta) {
} // undoc
LCAPI int lcMlineReverse(void *hMline) { return 0; }

// RPlan functions
LCAPI void *lcRPlanAddVer(void *hRPlan, double X, double Y) { return NULL; }
LCAPI int lcRPlanSetCurve(void *hVer, double Radius, double LenClot1,
                          double LenClot2) {
}
LCAPI int lcRPlanSetPos(void *hVer, double X, double Y) { return 0; }
LCAPI int lcRPlanDeleteVer(void *hRPlan, void *hVer) { return 0; }
LCAPI void *lcRPlanGetFirstVer(void *hRPlan) { return NULL; }
LCAPI void *lcRPlanGetNextVer(void *hRPlan, void *hVer) { return NULL; }
LCAPI void *lcRPlanGetLastVer(void *hRPlan) { return NULL; }
LCAPI void *lcRPlanGetPrevVer(void *hRPlan, void *hVer) { return NULL; }
LCAPI void *lcRPlanGetVer(void *hRPlan, int Index) { return NULL; }
LCAPI int lcRPlanGetPoint(void *hRPlan, double Dist, double *pX, double *pY,
                          double *pAngle, int *pSide) {
}
LCAPI int lcRPlanGetDist(void *hRPlan, double X, double Y, double *pX2,
                         double *pY2, double *pDist, double *pOffset) {
}
LCAPI int lcRPlanWriteCSV(void *hRPlan, char *szFileName) { return 0; }

// Construction line
LCAPI int lcXlinePutDir(void *hXline, double X, double Y) { return 0; }

// Rectangle
LCAPI int lcRectGetPolyline(void *hRect, double *pX, double *pY,
                            double *pBulge) {
}

// Circle

// Image reference
LCAPI int lcImgRefGetPixel(void *hImgRef, int iX, int iY, double *pX,
                           double *pY, int *pColor) {
}
LCAPI int lcImgRefResize(void *hImgRef, int NewWidth, int NewHeight,
                         int Method) {
}

// Hatch
LCAPI int lcHatchSetPattern(void *hHatch, char *szFileName, char *szPatName,
                            double Scal, double Angle) {
}
LCAPI int lcHatchBoundStart(void *hHatch) { return 0; }
LCAPI int lcHatchBoundPoint(void *hHatch, double X, double Y) { return 0; }
LCAPI int lcHatchBoundEntity(void *hHatch, void *hEnt) { return 0; }
LCAPI int lcHatchBoundEndLoop(void *hHatch) { return 0; }
LCAPI int lcHatchBoundEnd(void *hHatch) { return 0; }
LCAPI int lcHatchPatStart(void *hHatch) { return 0; }
LCAPI int lcHatchPatLine(void *hHatch, double Angle, double x0, double y0,
                         double dx, double dy, int nDash, double L0, double L1,
                         double L2, double L3, double L4, double L5, double L6,
                         double L7) {
}
LCAPI int lcHatchPatEnd(void *hHatch) { return 0; }
LCAPI int lcHatchGetLoopSize(void *hHatch, int iLoop) { return 0; }
LCAPI int lcHatchGetPoint(void *hHatch, int iPnt, double *pX, double *pY) { return 0; }
LCAPI void *lcHatchGetEnt(void *hHatch, int Mode) { return NULL; }

// Viewport
LCAPI int lcVportSetView(void *hVport, double Xcen, double Ycen, double Scal,
                         double Angle) {
}
LCAPI int lcVportLayerDlg(void *hVport, void *hLcWnd) { return 0; }
LCAPI int lcVportLayerCmd(void *hVport, int Cmd, void *hLayer) { return 0; }

// Block attribute
LCAPI void *lcBlkRefAddAtt(void *hBlockRef, char *szTag,
                           char *szValue) {
} // for using in DWG plugin
LCAPI void *lcBlkRefGetFirstAtt(void *hBlockRef) { return NULL; }
LCAPI void *lcBlkRefGetNextAtt(void *hBlockRef, void *hAttrib) { return NULL; }
LCAPI void *lcBlkRefGetAtt(void *hBlockRef, char *szTag) { return NULL; }
LCAPI char *lcBlkRefGetAttVal(void *hBlockRef, char *szTag) { return NULL; }
LCAPI int lcBlkRefPutAttVal(void *hBlockRef, char *szTag, char *szValue) { return 0; }

// Shape
LCAPI int lcShapeAddEnt(void *hShape, void *hEnt, int bErase) { return 0; }
LCAPI int lcShapeEnd(void *hShape) { return 0; }
LCAPI void *lcShapeGetFirstEnt(void *hShape) { return NULL; }
LCAPI void *lcShapeGetNextEnt(void *hShape, void *hEnt) { return NULL; }
LCAPI void *lcShapeGetLastEnt(void *hShape) { return NULL; }
LCAPI void *lcShapeGetPrevEnt(void *hShape, void *hEnt) { return NULL; }

// TIN entity //(also LC_PROP_TIN_FILENAME and others, lcBlockGetTIN )
LCAPI void *lcTIN_AddPoint(void *hTIN, char *szNamePtype, double X, double Y,
                           double Z) {
}
LCAPI void *lcTIN_PtypeGetByName(void *hTIN, char *szName) { return NULL; }
LCAPI void *lcTIN_PtypeGetFirst(void *hTIN) { return NULL; }
LCAPI void *lcTIN_PtypeGetNext(void *hTIN, void *hPtype) { return NULL; }
LCAPI void *lcTIN_PntGetFirst(void *hTIN) { return NULL; }
LCAPI void *lcTIN_PntGetNext(void *hTIN, void *hPnt) { return NULL; }
LCAPI void *lcTIN_PntGetNear(void *hTIN, double X, double Y) { return NULL; }
LCAPI int lcTIN_PntDelDup(void *hTIN, double Delta, void *hLcWnd) { return 0; }
LCAPI void *lcTIN_TriGetFirst(void *hTIN) { return NULL; }
LCAPI void *lcTIN_TriGetNext(void *hTIN, void *hTrian) { return NULL; }
LCAPI void *lcTIN_TriGetByPos(void *hTIN, double X, double Y) { return NULL; }
LCAPI int lcTIN_TriGetEdge(void *hTIN, void *hTrian, int iEdge) { return 0; }
LCAPI int lcTIN_TriUpdate(void *hTIN, void *hPnt) { return 0; }
LCAPI int lcTIN_Bnd(void *hTIN, double MaxDist, void *hLcWnd) { return 0; }
LCAPI void *lcTIN_BndGetPoint(void *hTIN, int iPnt) { return NULL; }
LCAPI int lcTIN_Triangulate(void *hTIN, void *hLcWnd) { return 0; } // LC_CMD_TIN_BNDTRANG
LCAPI int lcTIN_Isolines(void *hTIN, double Zstep, int BoldStep, void *hLcWnd) { return 0; }
LCAPI void *lcTIN_IsoGetFirst(void *hTIN) { return NULL; }
LCAPI void *lcTIN_IsoGetNext(void *hTIN, void *hIso) { return NULL; }
LCAPI int lcTIN_IsoMakeLabels(void *hIso) { return 0; }
LCAPI int lcTIN_GetIsoLabel(int iLabel, double *pX, double *pY, double *pAngle,
                            int *pAlign) { return 0; }
LCAPI int lcTIN_GetZ(void *hTIN, double X, double Y, double *pZ) { return 0; }
LCAPI int lcTIN_ColorFill(void *hTIN, double Zstep, double PixelSize,
                          void *hLcWnd) { return 0; }
LCAPI int lcTIN_Save(void *hTIN, char *szFileName, int Mode, int bByBndr,
                     void *hLcWnd) { return 0; }
LCAPI int lcTIN_InterLine(void *hTIN, double X0, double Y0, double X1,
                          double Y1) {
}
LCAPI int lcTIN_InterGetPoint(void *hTIN, int iPnt, double *pX, double *pY,
                              double *pZ) {
}
LCAPI int lcTIN_Clear(void *hTIN) { return 0; }
LCAPI void *lcTIN_AddTrian(void *hTIN, int iPnt0, int iPnt1, int iPnt2) { return NULL; }
LCAPI int lcTIN_BndAddPnt(void *hTIN, int iPnt) { return 0; }
LCAPI int lcTIN_Merge(void *hTIN, char *szFileName, void *hLcWnd) { return 0; }

LCAPI int lcColorRGB(int Red, int Green, int Blue) { return 0; }
// Color from string
LCAPI int lcColorIsRGB(char *szColor) { return 0; }
LCAPI int lcColorGetRed(char *szColor) { return 0; }
LCAPI int lcColorGetGreen(char *szColor) { return 0; }
LCAPI int lcColorGetBlue(char *szColor) { return 0; }
LCAPI int lcColorGetIndex(char *szColor, int bLogicalEnabled) { return 0; }
LCAPI int lcColorToVal(char *szColor, int *pbRGB, int *pIndex, int *pR, int *pG,
                       int *pB) { return 0; }
// Color palette
LCAPI int lcColorSetPalette(int Index, int R, int G, int B) { return 0; }
LCAPI int lcColorGetPalette(int Index, int *pR, int *pG, int *pB) { return 0; }
LCAPI int lcColorSavePalette(char *szFileName, void *hWnd) { return 0; }
LCAPI int lcColorLoadPalette(char *szFileName, void *hWnd) { return 0; }

// Image
LCAPI int lcImageSetPixelRGB(void *hImage, int X, int Y, int Red, int Green,
                             int Blue) {
}
LCAPI int lcImageSetPixelI(void *hImage, int X, int Y, int iColor) { return 0; }
LCAPI int lcImageGetPixelRGB(void *hImage, int X, int Y, int *pRed, int *pGreen,
                             int *pBlue) { return 0; }
LCAPI int lcImageGetPixelI(void *hImage, int X, int Y, int *piColor) { return 0; }
LCAPI int lcImageSetPalColor(void *hImage, int iColor, int Red, int Green,
                             int Blue) {
}
LCAPI int lcImageGetPalColor(void *hImage, int iColor, int *pRed, int *pGreen,
                             int *pBlue) { return 0; }
LCAPI int lcImageLoad(void *hImage, char *szFilename, void *hWnd) { return 0; }
LCAPI int lcImageLoadDIB(void *hImage, void *hDib2) { return 0; } // undoc
LCAPI int lcImageLoadCamera(void *hImage) { return 0; }
LCAPI int lcImageCopyQuad(void *hImage, void *hImageSrc, unsigned int W,
                          unsigned int H, double x0, double y0, double x1,
                          double y1, double x2, double y2, double x3,
                          double y3) {
} // undoc
LCAPI int lcImageProc(void *hImage, int Mode) { return 0; }

// Toolbar Window

// explode entity to polylines, Flags is LC_EXP_ALL or other
LCAPI int lcExpEntity(void *hEnt, int iChar, int Flags, int bUnrotate) { return 0; }
LCAPI int lcExpGetPline(double Delta) { return 0; }
LCAPI int lcExpGetVertex(double *pX, double *pY) { return 0; }
LCAPI int lcExpBlock(void *hBlock, F_LCEVENT pFunc, int Prm1, void *Prm2) { return 0; }

LCAPI int lcGbrLoad(void *hLcWnd, char *szFileName0) { return 0; }
LCAPI int lcGbrClose(void *hLcWnd) { return 0; }

LCAPI char *lcPlugGetOption(char *szFileName, char *szKey) { return NULL; }
LCAPI int lcPlugGetOption2(char *szFileName, char *szKey) { return 0; }
LCAPI int lcPlugSetOption(char *szFileName, char *szKey, char *szValue,
                          int bSave) {
}

LCAPI int lcPrintSetup(void *hWnd) { return 0; }
LCAPI int lcPrintLayout(void *hBlock) { return 0; }
LCAPI int lcPrintBlock(void *hBlock, double X, double Y, double W, double H,
                       double Scal, double PapLef, double PapTop, int Options) {
}

LCAPI void *lcXDataBegin() { return NULL; }
LCAPI int lcXDataEnd(void *hData) { return 0; }
LCAPI int lcXDataClear(void *hData) { return 0; }
LCAPI int lcXDataSet(void *hData) { return 0; }

// NoDB mode
// ////////////////////////////////////////////////////////////////////////////////////////

// Window Tabs
LCAPI int lcWndTabClear(void *hLcWnd) { return 0; }
LCAPI int lcWndTabAdd(void *hLcWnd, int TabID, char *szLabel, char *szTipText,
                      void *hObject) { return 0; }
LCAPI int lcWndTabSelect(void *hLcWnd, int TabID) { return 0; }

// Paper
LCAPI int lcWndPaperEnable(void *hLcWnd, int bEnable) { return 0; }
LCAPI int lcWndPaperSetSize(void *hLcWnd, int Size, int Orient) { return 0; }
LCAPI int lcWndPaperSetSize2(void *hLcWnd, double Width, double Height) { return 0; }
LCAPI int lcWndPaperSetPos(void *hLcWnd, double Left, double Bottom) { return 0; }

// Grips
LCAPI int lcGripClear(void *hLcWnd) { return 0; }
LCAPI int lcGripAdd(void *hLcWnd, void *hObj, int iGrip, int Typ, double X,
                    double Y, double Ang, double X0, double Y0) {
}
LCAPI int lcGripSet(void *hLcWnd, void *hObj, int iGrip, double X, double Y,
                    double Ang, double X0, double Y0) {
}

// to draw inside of Paint event procedure
LCAPI void *lcPaint_PenCreate(void *hLcWnd, int Id, int Color, double Width,
                              int PenStyle) {
}
LCAPI int lcPaint_PenSelect(void *hLcWnd, void *hPen) { return 0; }
LCAPI int lcPaint_PenSelectID(void *hLcWnd, int IdPen) { return 0; }
LCAPI void *lcPaint_BrushCreate(void *hLcWnd, int Id, int Color, int Pattern,
                                int Alpha) {
}
LCAPI int lcPaint_BrushSelect(void *hLcWnd, void *hBrush) { return 0; }
LCAPI int lcPaint_BrushSelectID(void *hLcWnd, int IdBrush) { return 0; }

LCAPI int lcPaint_DrawPtbuf(void *hLcWnd, void *hPtbuf, int bClosed) { return 0; }
LCAPI int lcPaint_DrawMpgon(void *hLcWnd, void *hMpgon, int bFill, int bBorder) { return 0; }
LCAPI int lcPaint_DrawImage(void *hLcWnd, void *hImage, double X, double Y,
                            double PixelSize, int Transp, int TVal,
                            void *hPtbuf) { return 0; }
LCAPI int lcPaint_DrawImage2(void *hLcWnd, void *hImage, double X, double Y,
                             double W, double H, int Transp, int TVal,
                             void *hPtbuf) { return 0; }
LCAPI int lcPaint_DrawText(void *hLcWnd, double X, double Y, char *szText) { return 0; }
LCAPI int lcPaint_DrawText2(void *hLcWnd, double X1, double Y1, double X2,
                            double Y2, int Align, char *szText) {
}
LCAPI int lcPaint_DrawTextBC(void *hLcWnd, void *hMpgon, double Gap,
                             double Height, int Align, char *szText) {
}
LCAPI int lcPaint_DrawArcText(void *hLcWnd, char *szText, double X, double Y,
                              double Rad, double Ang0, int bCW, double H,
                              double WScale, int Align) {
}
LCAPI int lcPaint_DrawHatch(void *hLcWnd, void *hHatch) { return 0; }
LCAPI int lcPaint_DrawPoint(void *hLcWnd, double X, double Y, int PtMode,
                            double PtSize) {
}
LCAPI int lcPaint_DrawLine(void *hLcWnd, double X1, double Y1, double X2,
                           double Y2) {
}
LCAPI int lcPaint_DrawXline(void *hLcWnd, double X, double Y, double Angle,
                            int bRay) {
}
LCAPI int lcPaint_DrawRect(void *hLcWnd, double Xc, double Yc, double Width,
                           double Height) {
}
LCAPI int lcPaint_DrawRect2(void *hLcWnd, double X1, double Y1, double X2,
                            double Y2) {
}
LCAPI int lcPaint_DrawPickBox(void *hLcWnd) { return 0; }
LCAPI int lcPaint_DrawGrid(void *hLcWnd, void *hGrid, int bDest, int ColLine,
                           int ColNode) {
}
LCAPI int lcPaint_DrawCPrompt(void *hLcWnd, int X, int Y, int Align,
                              char *szText) {
}
void LCAPI lcPaint_SetPixel(void *hDC, int X, int Y, int Color) {
}

// Points buffer
LCAPI void *lcPaint_CreatePtbuf() { return NULL; }
LCAPI int lcPaint_DeletePtbuf(void *hPtbuf) { return 0; }
LCAPI int lcPaint_PtbufClear(void *hPtbuf) { return 0; }
LCAPI int lcPaint_PtbufAddPoint(void *hPtbuf, double X, double Y, double Prm1,
                                double Prm2, int IntPrm) {
}
LCAPI int lcPaint_PtbufAddPoint2(void *hPtbuf, double X, double Y) { return 0; }
LCAPI int lcPaint_PtbufAddPointP(void *hPtbuf, double Angle, double Dist) { return 0; }
LCAPI int lcPaint_PtbufAddLine(void *hPtbuf, double X1, double Y1, double X2,
                               double Y2) {
}
LCAPI int lcPaint_PtbufAddLineP(void *hPtbuf, double X, double Y, double Angle,
                                double Dist) {
}
LCAPI int lcPaint_PtbufAddCircle(void *hPtbuf, double Xc, double Yc, double R,
                                 int Resol) {
}
LCAPI int lcPaint_PtbufAddCircle2(void *hPtbuf, double X1, double Y1, double X2,
                                  double Y2, int Resol) {
}
LCAPI int lcPaint_PtbufAddCircle3(void *hPtbuf, double X1, double Y1, double X2,
                                  double Y2, double X3, double Y3, int bInside,
                                  int Resol) {
}
LCAPI int lcPaint_PtbufAddArc(void *hPtbuf, double Xc, double Yc, double R,
                              double StartAngle, double ArcAngle, int Resol) {
}
LCAPI int lcPaint_PtbufAddArc3p(void *hPtbuf, double X1, double Y1, double X2,
                                double Y2, double X3, double Y3, int Resol) {
}
LCAPI int lcPaint_PtbufAddArcSDE(void *hPtbuf, double Xs, double Ys,
                                 double DirAng, double Xe, double Ye,
                                 int Resol) {
}
LCAPI int lcPaint_PtbufAddArcSDAR(void *hPtbuf, double Xs, double Ys,
                                  double DirAng, double AngArc, double R,
                                  int Resol) {
}
LCAPI int lcPaint_PtbufAddArcSER(void *hPtbuf, double Xs, double Ys, double Xe,
                                 double Ye, double Radius, int bClockwise,
                                 int Resol) {
}
LCAPI int lcPaint_PtbufAddArcSEL(void *hPtbuf, double Xs, double Ys, double Xe,
                                 double Ye, double ArcLen, int bClockwise,
                                 int Resol) {
}
LCAPI int lcPaint_PtbufAddArcSEA(void *hPtbuf, double Xs, double Ys, double Xe,
                                 double Ye, double AngArc, int Resol) {
}
LCAPI int lcPaint_PtbufAddArcSEB(void *hPtbuf, double Xs, double Ys, double Xe,
                                 double Ye, double Bulge, int Resol) {
}
LCAPI int lcPaint_PtbufAddArcCSE(void *hPtbuf, double Xc, double Yc, double Xs,
                                 double Ys, double Xe, double Ye,
                                 int bClockwise, int Resol) {
}
LCAPI int lcPaint_PtbufAddArcCSA(void *hPtbuf, double Xc, double Yc, double Xs,
                                 double Ys, double AngArc, int Resol) {
}
LCAPI int lcPaint_PtbufAddArcCSL(void *hPtbuf, double Xc, double Yc, double Xs,
                                 double Ys, double ChordLen, int bClockwise,
                                 int Resol) {
}
LCAPI int lcPaint_PtbufAddArcCRAA(void *hPtbuf, double Xc, double Yc, double R,
                                  double AngStart, double AngEnd,
                                  int bClockwise, int Resol) {
}
LCAPI int lcPaint_PtbufAddEllipse(void *hPtbuf, double Xc, double Yc,
                                  double Rmaj, double Rmin, double RotAng,
                                  double StartAng, double ArcAng, int Resol) {
}
LCAPI int lcPaint_PtbufAddEllipse2(void *hPtbuf, double X1, double Y1,
                                   double X2, double Y2, int Resol) {
}
LCAPI int lcPaint_PtbufAddRect(void *hPtbuf, double Xc, double Yc, double W,
                               double H, double Angle, double R, int Resol) {
}
LCAPI int lcPaint_PtbufAddRect2(void *hPtbuf, double X1, double Y1, double X2,
                                double Y2, double R, int Resol) {
}
LCAPI int lcPaint_PtbufAddRect3(void *hPtbuf, double X1, double Y1, double X2,
                                double Y2, double W, int Align, double R,
                                int Resol) {
}
LCAPI int lcPaint_PtbufAddWline(void *hPtbuf, double X1, double Y1, double X2,
                                double Y2, double W, int Align, int bArc,
                                int Resol) {
}
LCAPI int lcPaint_PtbufAddPtbuf(void *hPtbuf, void *hPtbuf2) { return 0; }
LCAPI int lcPaint_PtbufGetPoint(void *hPtbuf, int Mode, double *pX, double *pY) { return 0; }
LCAPI int lcPaint_PtbufGetPoint2(void *hPtbuf, int Mode, double *pX, double *pY,
                                 double *pPrm1, double *pPrm2, int *pIntPrm) {
}
LCAPI int lcPaint_PtbufInterpolate(void *hPtbuf, int bClosed, void *hPtbufDest,
                                   int Mode, int Resol) {
}
LCAPI int lcPaint_PtbufMove(void *hPtbuf, double dx, double dy) { return 0; }
LCAPI int lcPaint_PtbufRotate(void *hPtbuf, double Xc, double Yc, double Angle) { return 0; }
LCAPI int lcPaint_PtbufScale(void *hPtbuf, double Xc, double Yc, double ScaleX,
                             double ScaleY) {
}
LCAPI int lcPaint_PtbufMirror(void *hPtbuf, double X1, double Y1, double X2,
                              double Y2) {
}
LCAPI int lcPaint_PtbufCopy(void *hPtbuf, void *hPtbufDest) { return 0; }

// Multipolygon
LCAPI void *lcPaint_CreateMpgon() { return NULL; }
LCAPI int lcPaint_DeleteMpgon(void *hMpgon) { return 0; }
LCAPI int lcPaint_MpgonClear(void *hMpgon) { return 0; }
LCAPI int lcPaint_MpgonAddPgon(void *hMpgon, void *hPtbuf) { return 0; }
LCAPI int lcPaint_MpgonAddText(void *hMpgon, void *hFont, double X, double Y,
                               char *szText, int Resol) {
}
LCAPI int lcPaint_MpgonAddBarcode(void *hMpgon, int BarType, double Xc,
                                  double Yc, double Width, double Height,
                                  char *szText) {
}
LCAPI int lcPaint_MpgonMove(void *hMpgon, double dx, double dy) { return 0; }
LCAPI int lcPaint_MpgonRotate(void *hMpgon, double Xc, double Yc, double Angle) { return 0; }
LCAPI int lcPaint_MpgonScale(void *hMpgon, double Xc, double Yc, double ScaleX,
                             double ScaleY) {
}
LCAPI int lcPaint_MpgonMirror(void *hMpgon, double X1, double Y1, double X2,
                              double Y2) {
}
LCAPI int lcPaint_MpgonCopy(void *hMpgon, void *hMpgonDest) { return 0; }

LCAPI int lcPaint_HatchGen(void *hMpgon, void *hHatch, double Dist,
                           double Angle, double Gap) {
}

// Image
LCAPI void *lcPaint_ImageAdd(int Id) { return NULL; }
LCAPI int lcPaint_ImageDelete(void *hImage) { return 0; }
LCAPI void *lcPaint_ImageGetFirst() { return NULL; }
LCAPI void *lcPaint_ImageGetNext(void *hImage) { return NULL; }
LCAPI void *lcPaint_ImageGetByID(int Id) { return NULL; }
LCAPI int lcPaint_ImageLoad(void *hImage, char *szFileName) { return 0; }
LCAPI int lcPaint_ImageCopy(void *hImage, void *hImageDest) { return 0; }
LCAPI int lcPaint_ImageCreate(void *hImage, int Width, int Height) { return 0; }
LCAPI int lcPaint_ImageSetPixel(void *hImage, int X, int Y, int R, int G,
                                int B) {
}
LCAPI int lcPaint_ImageFlip(void *hImage, int bHor, int bVert) { return 0; }
LCAPI int lcPaint_ImageRotate(void *hImage, double Angle) { return 0; }
LCAPI int lcPaint_ImageGray(void *hImage) { return 0; }
LCAPI int lcPaint_ImageResize(void *hImage, int NewWidth, int NewHeight,
                              int ResizeFilter) {
}
LCAPI void *lcPaint_ImageGetPtbuf(void *hImage, double RotAngle) { return NULL; }

LCAPI void *lcPaint_FontOpenLC(char *szFontName) { return NULL; }
LCAPI void *lcPaint_FontOpenTT(char *szFontName, int bBold, int bItalic) { return NULL; }
LCAPI int lcPaint_FontClose(void *hFont) { return 0; }
LCAPI int lcPaint_FontSelect(void *hLcWnd, void *hFont) { return 0; }

int lcLoadLib(char *szFileName) {
}
void lcFreeLib() {
}

int XlcWndPollEvents(void *hWnd) {
  return gllc_window_poll_events((struct gllc_window *)hWnd);
}

LCAPI void *XlcCreateWindowX11(void *hWnd, void *hPrm2, int Style) {
#if !defined(__linux__)
  fprintf(stderr, "Error: This function only for X11 context. Use lcCreateWindow instead.\n");
  return NULL;
#else
  if (!(Style == XLC_WINDOW_X11_BACKEND)) {
    fprintf(stderr, "Error: This function only for X11 context. Use lcCreateWindow instead.\n");
    return NULL;
  }
  return gllc_window_create_x11((Window)hWnd, (Display *)hPrm2, Style);
#endif
}