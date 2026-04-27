#include "litecad.h"
#include "block.h"
#include "drawing.h"
#include "event.h"
#include "object.h"
#include "polyline.h"
#include "window.h"

void LCAPI lcEventSetProc(int EventType, F_LCEVENT pFunc, int Prm1, void *Prm2) {
  gllc_event_set_proc(EventType, (void (*)(struct gllc_event *))pFunc, Prm1, Prm2);
}

void LCAPI lcEventReturnCode(int code) {
}

int LCAPI lcEventsEnable(int b) { return 0; }

// Initialization
int LCAPI lcInitialize() {
#ifdef DEBUG
  printf("DEBUG build\n");
#endif

#ifdef NDEBUG
  printf("RELEASE build\n");
#endif
  return 0;
}

int LCAPI lcUninitialize(int bSaveConfig) {
  return 0;
}

// GUI strings
int LCAPI lcStrAdd(char *szTag, char *szText) {
  return 0;
}

int LCAPI lcStrSet(char *szTag, char *szText) {
  return 0;
}

char *LCAPI lcStrGet(char *szTag) {
  return 0;
}

int LCAPI lcStrFileLoad(char *szFileName) {
  return 0;
}

int LCAPI lcStrFileSave(char *szFileName, char *szLanguage) {
  return 0;
}

// Objects properties
int LCAPI lcPropGetBool(void *hObject, int idProp) {
  return gllc_prop_get_bool((struct gllc_object *)hObject, idProp);
}

int LCAPI lcPropGetInt(void *hObject, int idProp) {
  return gllc_prop_get_int((struct gllc_object *)hObject, idProp);
}

double LCAPI lcPropGetFloat(void *hObject, int idProp) {
  return gllc_prop_get_float((struct gllc_object *)hObject, idProp);
}
char *LCAPI lcPropGetStr(void *hObject, int idProp) {
  return gllc_prop_get_string((struct gllc_object *)hObject, idProp);
}

int LCAPI lcPropGetStrA(void *hObject, int idProp, char *szBuf, int BufSize) { return 0; }
int LCAPI lcPropGetStr2(void *hObject, int idProp) { return 0; }
int LCAPI lcPropGetChar(int iChar) { return 0; }

void *LCAPI lcPropGetHandle(void *hObject, int idProp) {
  return gllc_prop_get_handle((struct gllc_object *)hObject, idProp);
}
int LCAPI lcPropPutBool(void *hObject, int idProp, int bValue) {
  return gllc_prop_put_bool((struct gllc_object *)hObject, idProp, bValue);
}

int LCAPI lcPropPutInt(void *hObject, int idProp, int Value) {
  return gllc_prop_put_int((struct gllc_object *)hObject, idProp, Value);
}

int LCAPI lcPropPutFloat(void *hObject, int idProp, double Value) {
  return gllc_prop_put_float((struct gllc_object *)hObject, idProp, Value);
}

int LCAPI lcPropPutStr(void *hObject, int idProp, char *szValue) {
  return gllc_prop_put_string((struct gllc_object *)hObject, idProp, szValue);
}

int LCAPI lcPropPutHandle(void *hObject, int idProp, void *hValue) {
  return gllc_prop_put_handle((struct gllc_object *)hObject, idProp, hValue);
}

// Design window
void *LCAPI lcCreateWindow(void *hWndParent, int Style) {
  return gllc_window_create(hWndParent);
}

int LCAPI lcDeleteWindow(void *hLcWnd) {
  return gllc_window_destroy((struct gllc_window *)hLcWnd);
}

int LCAPI lcWndOnClose(void *hLcWnd) {
  return 1;
}

int LCAPI lcWndExeCommand(void *hLcWnd, int Command, int CmdParam) {
  return 1;
}

int LCAPI lcWndExitCommand(void *hLcWnd) {
  return 1;
}

int LCAPI lcWndResize(void *hLcWnd, int Left, int Top, int Width, int Height) {
  return gllc_window_resize((struct gllc_window *)hLcWnd, Left, Top, Width, Height);
}

int LCAPI lcWndRedraw(void *hLcWnd) {
  return gllc_window_redraw((struct gllc_window *)hLcWnd);
}

int LCAPI lcWndRedrawAuto(void *hLcWnd, int Elapse, F_REDRAW pFunc) {
  return gllc_window_redraw((struct gllc_window *)hLcWnd);
}

int LCAPI lcWndSetFocus(void *hLcWnd) {
  return 1;
}

int LCAPI lcWndSetExtents(void *hLcWnd, double Xmin, double Ymin, double Xmax, double Ymax) {
  return 1;
}

int LCAPI lcWndSetBlock(void *hLcWnd, void *hBlock) {
  return gllc_window_set_block((struct gllc_window *)hLcWnd, (struct gllc_block *)hBlock);
}

int LCAPI lcWndSetProps(void *hLcWnd, void *hPropWnd) {
  return 1;
}

int LCAPI lcWndSetCmdwin(void *hLcWnd, void *hCmdLine) {
  return 1;
}

int LCAPI lcWndSetBasePoint(void *hLcWnd, int bState, double X, double Y) {
  return 1;
}

int LCAPI lcWndEmulator(void *hLcWnd, int Mode) {
  return 1;
}

int LCAPI lcWndMagnifier(void *hLcWnd, int bOn, int Width, int Height, int Zoom, int Flags) {
  return 1;
}

int LCAPI lcWndHoverText(void *hLcWnd, char *szText, int X, int Y, int Align) {
  return 1;
}

int LCAPI lcWndMessage(void *hLcWnd, char *szText, int uType) {
  return 1;
}

int LCAPI lcWndWaitPoint(void *hLcWnd, char *szText, double *pXdrw, double *pYdrw) {
  return 1;
}

int LCAPI lcWndWaitPoint2(void *hLcWnd, char *szText, double *pXdrw, double *pYdrw, F_WAITPOINT pFunc, int FuncPrm) {
  return 1;
}

int LCAPI lcWndInputStr(void *hLcWnd) {
  return 1;
}

int LCAPI lcWndUpdate(void *hLcWnd, int Mode) {
  return 1;
}

void *LCAPI lcWndDrwAdd(void *hLcWnd, char *szFileName) {
  return NULL;
}

int LCAPI lcWndDrwDelete(void *hLcWnd, void *hLcDrw) {
  return 1;
}

void *LCAPI lcWndDrwGet(void *hLcWnd, int Index) {
  return NULL;
}

// zoom
int LCAPI lcWndZoomRect(void *hLcWnd, double Left, double Bottom, double Right, double Top) {
  return 1;
}

int LCAPI lcWndZoomScale(void *hLcWnd, double Scal) {
  return 1;
}

int LCAPI lcWndZoomMove(void *hLcWnd, double DX, double DY) {
  return 1;
}

int LCAPI lcWndZoomPos(void *hLcWnd, double Xc, double Yc, double PixSize) {
  return 1;
}

int LCAPI lcWndZoomEnt(void *hLcWnd, void *hEnt, double Scal) {
  return 1;
}

// coordinates
int LCAPI lcWndGetCursorCoord(void *hLcWnd, int *pXwin, int *pYwin, double *pXdrw, double *pYdrw) {
  return 1;
}

int LCAPI lcCoordDrwToWnd(void *hLcWnd, double Xdrw, double Ydrw, int *pXwnd, int *pYwnd) {
  return 1;
}

int LCAPI lcCoordWndToDrw(void *hLcWnd, int Xwnd, int Ywnd, double *pXdrw, double *pYdrw) {
  return 1;
}

int LCAPI lcWndCoordFromDrw(void *hLcWnd, double Xdrw, double Ydrw, int *pXwin, int *pYwin) {
  return 1;
}

int LCAPI lcWndCoordToDrw(void *hLcWnd, int Xwin, int Ywin, double *pXdrw, double *pYdrw) {
  return 1;
}

// retrieve entities
void *LCAPI lcWndGetEntByPoint(void *hLcWnd, int Xwin, int Ywin) {
  return NULL;
}

void *LCAPI lcWndGetEntByPoint2(void *hLcWnd, double X, double Y, double Delta) { return NULL; }
int LCAPI lcWndGetEntsByPoint(void *hLcWnd, int Xwin, int Ywin, int nMaxEnts) { return 0; }
int LCAPI lcWndGetEntsByRect(void *hLcWnd, double Lef, double Bot, double Rig, double Top, int bCross, int nMaxEnts) { return 0; }
void *LCAPI lcWndGetEntity(int iEnt) { return NULL; }
void *LCAPI lcWndGetEntByID(void *hLcWnd, int Id) { return NULL; }
void *LCAPI lcWndGetEntByIDH(void *hLcWnd, char *szId) { return NULL; }
void *LCAPI lcWndGetEntByKey(void *hLcWnd, int Key) { return NULL; }
int LCAPI lcWndPickEnt(void *hLcWnd, char *szTitle, char *szCursorText) { return 0; }

// Font functions
void *LCAPI lcFontGetFirst() { return NULL; }
void *LCAPI lcFontGetNext(void *hFont) { return NULL; }
void *LCAPI lcFontAddRes(char *szFontName, void *hModule, int idResource) { return NULL; }
void *LCAPI lcFontAddFile(char *szFontName, char *szFilename, char *szOutFontName) { return NULL; }
void *LCAPI lcFontAddBin(char *szFontName, void *hData) { return NULL; }
void *LCAPI lcFontGetChar(void *hFont, int CharCode) { return NULL; }
char *LCAPI lcFontGetName(char *szFilename) { return NULL; }

// Progress indicator
int LCAPI lcProgressCreate(void *hLcWnd, int W, int H, char *szTitle) { return 0; }
int LCAPI lcProgressSetText(char *szText) { return 0; }
int LCAPI lcProgressStart(int MinVal, int MaxVal) { return 0; }
int LCAPI lcProgressSetPos(int Val) { return 0; }
int LCAPI lcProgressInc() { return 0; }
int LCAPI lcProgressDelete() { return 0; }

// Quadrangle point coordinates
void *LCAPI lcQuadCreate() { return NULL; }
int LCAPI lcQuadDelete(void *hQuad) { return 0; }
int LCAPI lcQuadSet(void *hQuad, double x0, double y0, double x1, double y1, double x2, double y2, double x3, double y3) { return 0; }
int LCAPI lcQuadTransXYtoUV(void *hQuad, double X, double Y, double *pU, double *pV) { return 0; }
int LCAPI lcQuadTransUVtoXY(void *hQuad, double U, double V, double *pX, double *pY) { return 0; }
int LCAPI lcQuadContains(void *hQuad, double X, double Y) { return 0; }

// Array of Quadrangles
void *LCAPI lcGridCreate() { return NULL; }
int LCAPI lcGridDelete(void *hGrid) { return 0; }
int LCAPI lcGridSet(void *hGrid, double X0, double Y0, double W, double H, int Nx, int Ny) { return 0; }
int LCAPI lcGridSetDest(void *hGrid, int Ix, int Iy, double X, double Y) { return 0; }
int LCAPI lcGridUpdate(void *hGrid) { return 0; }
int LCAPI lcGridTrans(void *hGrid, double X, double Y, double *pXdest, double *pYdest) { return 0; }
int LCAPI lcGridGetNode(void *hGrid, int bDest, int Ix, int Iy, double *pX, double *pY) { return 0; }
int LCAPI lcGridGetCell(void *hGrid, double X, double Y, int *pIx, int *pIy) { return 0; }
int LCAPI lcGridSetView(void *hGrid, int Mode, void *hLcWnd, int ColLine, int ColNode) { return 0; } // Mode: 0-disable, 1-original, 2-destination

// Command Window
void *LCAPI lcCreateCmdwin(void *hWndParent, int Left, int Top, int Width, int Height) { return NULL; }
int LCAPI lcCmdwinResize(void *hCmdLine, int Left, int Top, int Width, int Height) { return 0; }
int LCAPI lcCmdwinUpdate(void *hCmdLine) { return 0; } // undoc

// Properties Window
void *LCAPI lcCreateProps(void *hWndParent, int Mode) { return NULL; }
int LCAPI lcDeleteProps(void *hPropWnd) { return 0; }
int LCAPI lcPropsResize(void *hPropWnd, int Left, int Top, int Width, int Height) { return 0; }
int LCAPI lcPropsUpdate(void *hPropWnd, int bSelChanged) { return 0; }

// Status Bar
void *LCAPI lcCreateStatbar(void *hWndParent) { return NULL; } // also LC_PROP_SBAR_H and others
int LCAPI lcDeleteStatbar(void *hStatbar) { return 0; }
int LCAPI lcStatbarResize(void *hStatbar, int Left, int Top, int Width, int Height) { return 0; }
int LCAPI lcStatbarCell(void *hStatbar, int Id, int Pos) { return 0; }
int LCAPI lcStatbarText(void *hStatbar, int Id, char *szText) { return 0; }
int LCAPI lcStatbarRedraw(void *hStatbar) { return 0; }

// utility functions
int LCAPI lcDgGetValue(void *hWnd, int Lef, int Top, char *szTitle, char *szPrompt) { return 0; }
int LCAPI lcHelp(char *szTopic) { return 0; }
void LCAPI lcGetPolarPoint(double x0, double y0, double Angle, double Dist, double *pOutX, double *pOutY) {
}
void LCAPI lcGetPolarPrm(double x1, double y1, double x2, double y2, double *pAngle, double *pDist) {
}
int LCAPI lcGetClientSize(void *hWnd, int *pWidth, int *pHeight) { return 0; }
int LCAPI lcGetErrorCode() { return 0; }
char *LCAPI lcGetErrorStr() { return NULL; }
int LCAPI lcGetStr(int Mode) { return 0; }
int LCAPI lcGetDrwXData(char *szFileName) { return 0; }
int LCAPI lcGetDrwPreview(char *szFileName, unsigned char *pOutDIB) { return 0; }
int LCAPI lcFilletSetLines(double L1x0, double L1y0, double L1x1, double L1y1, double L2x0, double L2y0, double L2x1, double L2y1) { return 0; }
int LCAPI lcFillet(double Rad, double Bis, double Tang) { return 0; }
int LCAPI lcFilletGetPoint(int iPnt, double *pX, double *pY) { return 0; }
int LCAPI lcFileToStrA(char *szFileName, char *pBuf) { return 0; }

// Custom command interface
void *LCAPI lcCreateCommand(void *hLcWnd, int Id, char *szTitle) { return NULL; }
int LCAPI lcCmdExit(void *hCmd) { return 0; }
int LCAPI lcCmdCursorText(void *hCmd, char *szText) { return 0; }
int LCAPI lcCmdMessage(void *hCmd, char *szText, int uType) { return 0; }
int LCAPI lcCmdResetLastPt(void *hCmd) { return 0; }

int LCAPI lcTIS_InitLibrary(char *szLicenseKey, int bErrMsg) { return 0; }
int LCAPI lcTIS_CloseLibrary() { return 0; }
int LCAPI lcCameraConnect(char *szName) { return 0; } // LC_PROP_G_CAMERA_COUNT
int LCAPI lcCameraDisconnect() { return 0; }
int LCAPI lcCameraShot() { return 0; }

//-----------------------------------------------------------------------------
// Drawing
//-----------------------------------------------------------------------------
void *LCAPI lcCreateDrawing() {
  return gllc_drw_create();
}
int LCAPI lcDeleteDrawing(void *hDrw) { return 0; }
int LCAPI lcDrwNew(void *hDrw, char *szFileName, void *hLcWnd) { return 0; }
int LCAPI lcDrwLoad(void *hDrw, char *szFileName, void *hLcWnd) { return 0; }
int LCAPI lcDrwLoadMem(void *hDrw, void *hMem, void *hLcWnd) { return 0; }
int LCAPI lcDxfLoadMem(void *hDrw, void *hMem, void *hLcWnd) { return 0; }
void *LCAPI lcDrwLoadTIN(void *hDrw, char *szFileName, void *hLcWnd) { return NULL; }
int LCAPI lcDrwSaveTIN(void *hDrw, void *hLcWnd) { return 0; }
int LCAPI lcDrwInsert(void *hDrw, char *szFileName, int Overwrite,
                      void *hLcWnd) { return 0; }
int LCAPI lcDrwInsertSHP(void *hDrw, void *hLayer, char *szFileName,
                         void *hLcWnd) { return 0; }
int LCAPI lcDrwCopy(void *hDrw, void *hDrwSrc) { return 0; }
int LCAPI lcDrwSave(void *hDrw, char *szFileName, int bBak, void *hLcWnd) { return 0; }
int LCAPI lcDrwSaveMem(void *hDrw, void *hMem, int MemSize) { return 0; }

void *LCAPI lcDrwAddLayer(void *hDrw, char *szName, char *szColor, void *hLtype,
                          int Lwidth) {
}
void *LCAPI lcDrwAddLayer2(void *hDrw, char *szName, void *hFromLayer) { return NULL; }
void *LCAPI lcDrwAddLinetype(void *hDrw, char *szName, char *szDefinition) { return NULL; }
void *LCAPI lcDrwAddLinetypeF(void *hDrw, char *szName, char *szFileName,
                              char *szLtypeName) {
}
void *LCAPI lcDrwAddTextStyle(void *hDrw, char *szName, char *szFontName,
                              int bWinFont) {
}
void *LCAPI lcDrwAddDimStyle(void *hDrw, char *szName) { return NULL; }
void *LCAPI lcDrwAddMlineStyle(void *hDrw, char *szName) { return NULL; }
void *LCAPI lcDrwAddPntStyle(void *hDrw, char *szName, void *hBlock,
                             double BlockScale, void *hTStyle,
                             double TextHeight, double TextWidth) {
}
void *LCAPI lcDrwAddFilling(void *hDrw, char *szName) { return NULL; }
void *LCAPI lcDrwAddImage(void *hDrw, char *szName, char *szFileName) { return NULL; }
void *LCAPI lcDrwAddImage2(void *hDrw, char *szName, int Width, int Height,
                           int nBits, void *hData, int bTopDown) {
}
void *LCAPI lcDrwAddImage3(void *hDrw, char *szName, void *hMem) { return NULL; }
void *LCAPI lcDrwAddImageCam(void *hDrw, char *szName) { return NULL; }
void *LCAPI lcDrwAddBlock(void *hDrw, char *szName, double X, double Y) {
  return gllc_drw_add_block(hDrw, szName, X, Y);
}
void *LCAPI lcDrwAddBlockFromFile(void *hDrw, char *szName, char *szFileName,
                                  int Overwrite, void *hwParent) {
}
void *LCAPI lcDrwAddBlockFromDrw(void *hDrw, char *szName, void *hDrw2,
                                 int Overwrite, void *hwParent) {
}
void *LCAPI lcDrwAddBlockFile(void *hDrw, char *szName, char *szFileName,
                              int Overwrite, void *hwParent) {
}
void *LCAPI lcDrwAddBlockPaper(void *hDrw, char *szName, int PaperSize,
                               int Orient, double Width, double Height) {
}
void *LCAPI lcDrwAddBlockCopy(void *hDrw, char *szName, void *hSrcBlock) { return NULL; }

int LCAPI lcDrwDeleteObject(void *hDrw, void *hObject) { return 0; }
int LCAPI lcDrwDeleteUnused(void *hDrw, int ObjType) { return 0; } // undoc
int LCAPI lcDrwCountObjects(void *hDrw, int ObjType) { return 0; }
int LCAPI lcDrwSortObjects(void *hDrw, int ObjType) { return 0; }
int LCAPI lcDrwUpdateWinFonts(void *hDrw, void *hTStyle) { return 0; }
int LCAPI lcDrwUpdateBlkRefs(void *hDrw, void *hBlock) { return 0; }
int LCAPI lcDrwUpdateTexts(void *hDrw, void *hTStyle) { return 0; }

void *LCAPI lcDrwGetFirstObject(void *hDrw, int ObjType) { return NULL; }
void *LCAPI lcDrwGetNextObject(void *hDrw, void *hObject) { return NULL; }
void *LCAPI lcDrwGetObjectByID(void *hDrw, int ObjType, int Id) { return NULL; }
void *LCAPI lcDrwGetObjectByIDH(void *hDrw, int ObjType, char *szId) { return NULL; }
void *LCAPI lcDrwGetObjectByName(void *hDrw, int ObjType, char *szName) { return NULL; }
void *LCAPI lcDrwGetEntByID(void *hDrw, int Id) { return NULL; }
void *LCAPI lcDrwGetEntByIDH(void *hDrw, char *szId) { return NULL; }
void *LCAPI lcDrwGetEntByKey(void *hDrw, int Key) { return NULL; }

int LCAPI lcDrwClearXData(void *hDrw, int ObjType, int Mode) { return 0; }
int LCAPI lcDrwPurge(void *hDrw) { return 0; }
int LCAPI lcDrwExplode(void *hDrw, int Mode) { return 0; }
int LCAPI lcDrwSetLimits(void *hDrw, double Xmin, double Ymin, double Xmax,
                         double Ymax) {
}

int LCAPI lcDrwUndoRecord(void *hDrw, int Mode) { return 0; }
int LCAPI lcDrwUndo(void *hDrw, int bRedo) { return 0; }

// Clipping rectangles (also LC_PROP_CRECT_ID and others)
int LCAPI lcCRectsClear(void *hDrw) { return 0; }
int LCAPI lcCRectsAdd(void *hDrw, int ID, double Lef, double Bot, double Width,
                      double Height) {
}
int LCAPI lcCRectsDivide(void *hDrw, int NumX, int NumY, int bClearExist) { return 0; }
void *LCAPI lcCRectsGetFirst(void *hDrw) { return NULL; }
void *LCAPI lcCRectsGetNext(void *hDrw, void *hCRect) { return NULL; }
void *LCAPI lcCRectsGetWithID(void *hDrw, int Id) { return NULL; }
int LCAPI lcCRectsActive(void *hDrw, void *hCRect) { return 0; }
void *LCAPI lcCRectsGetActive(void *hDrw) { return NULL; }
int LCAPI lcCRectsDelete(void *hDrw, void *hCRect) { return 0; }
int LCAPI lcCRectsSave(void *hDrw, void *hCRect, char *szFileName) { return 0; }
int LCAPI lcCRectsBitmap(void *hDrw, void *hCRect, char *szFileName,
                         double PixelSize) {
}

// Block
int LCAPI lcBlockSetViewRect(void *hBlock, double Xcen, double Ycen,
                             double Width, double Height) {
}
int LCAPI lcBlockSetViewRect2(void *hBlock, double Lef, double Bot, double Rig,
                              double Top) {
}
int LCAPI lcBlockSetPaperSize(void *hBlock, int PaperSize, int Orient,
                              double Width, double Height) {
}
int LCAPI lcBlockRasterize(void *hBlock, char *szFileName, double Xmin,
                           double Ymin, double Xmax, double Ymax, int ImgW,
                           int ImgH) {
}
int LCAPI lcBlockRasterizeMem(void *hBlock, void *hMem, double Xmin,
                              double Ymin, double Xmax, double Ymax, int ImgW,
                              int ImgH) {
}
int LCAPI lcBlockUpdate(void *hBlock, int bUpdEnts, void *hNewEnt) {
  gllc_block_update(hBlock);
  return 1;
}
int LCAPI lcBlockMove(void *hBlock, double dX, double dY, int bUpdate) { return 0; }
int LCAPI lcBlockScale(void *hBlock, double X, double Y, double Scal,
                       int bUpdate) {
}
int LCAPI lcBlockRotate(void *hBlock, double X, double Y, double Angle,
                        int bUpdate) {
}
int LCAPI lcBlockMirror(void *hBlock, double X1, double Y1, double X2,
                        double Y2, int bUpdate) {
}

// Add graphic objects into a block
int LCAPI lcBlockClear(void *hBlock, void *hLayer) { return 0; }
int LCAPI lcBlockPurge(void *hBlock) { return 0; }
int LCAPI lcBlockSortEnts(void *hBlock, int bByLayers, void *hWnd) { return 0; }
int LCAPI lcBlockSortEnts2(void *hBlock, void *idEnts,
                           int nEnts) {
} // for DWG plugin
void *LCAPI lcBlockAddPoint(void *hBlock, double X, double Y) { return NULL; }
void *LCAPI lcBlockAddPoint2(void *hBlock, double X, double Y, int PtMode,
                             double PtSize) {
}
void *LCAPI lcBlockAddPoint3d(void *hBlock, double X, double Y, double Z) { return NULL; }
int LCAPI lcBlockAddPointsF(void *hBlock, char *szFileName, void *hWnd) { return 0; }
void *LCAPI lcBlockAddXline(void *hBlock, double X, double Y, double Angle,
                            int bRay) {
}
void *LCAPI lcBlockAddXline2P(void *hBlock, double X, double Y, double X2,
                              double Y2, int bRay) {
}
void *LCAPI lcBlockAddLine(void *hBlock, double X1, double Y1, double X2,
                           double Y2) {
  double p0[2] = {X1, Y1};
  double p1[2] = {X2, Y2};
  return gllc_block_add_line((struct gllc_block *)hBlock, p0, p1);
}
void *LCAPI lcBlockAddLineDir(void *hBlock, double X, double Y, double Angle,
                              double Dist) {
}
void *LCAPI lcBlockAddLineTan(void *hBlock, void *hEnt1, void *hEnt2, int Mode) { return NULL; }
void *LCAPI lcBlockAddPolyline(void *hBlock, int FitType, int bClosed,
                               int bFilled) {
  return gllc_block_add_polyline(hBlock, bClosed, bFilled);
}
void *LCAPI lcBlockAddRPolygon(void *hBlock, int nVers, double Xc, double Yc,
                               double R, double Ang0, int bInscribed,
                               int bFilled) {
}
void *LCAPI lcBlockAddSpline(void *hBlock, int bClosed, int bFilled) { return NULL; }
void *LCAPI lcBlockAddBezier(void *hBlock) { return NULL; }
void *LCAPI lcBlockAddMline(void *hBlock, int FitType, int bClosed) { return NULL; }
void *LCAPI lcBlockAddRect(void *hBlock, double Xc, double Yc, double Width,
                           double Height, double Angle, int bFilled) {
}
void *LCAPI lcBlockAddRect2(void *hBlock, double Left, double Bottom,
                            double Width, double Height, double Rad,
                            int bFilled) {
}
void *LCAPI lcBlockAddCircle(void *hBlock, double X, double Y, double Radius,
                             int bFilled) {
}
void *LCAPI lcBlockAddArc(void *hBlock, double X, double Y, double Radius,
                          double StartAngle, double ArcAngle) {
  return gllc_block_add_arc((struct gllc_block *)hBlock, X, Y, Radius, StartAngle, ArcAngle);
}
void *LCAPI lcBlockAddArc3P(void *hBlock, double X1, double Y1, double X2,
                            double Y2, double X3, double Y3) {
}
void *LCAPI lcBlockAddFillet(void *hBlock, void *hEnt1, void *hEnt2,
                             double Radius) {
}
void *LCAPI lcBlockAddEllipse(void *hBlock, double X, double Y, double R1,
                              double R2, double RotAngle, double StartAngle,
                              double ArcAngle) {
}
void *LCAPI lcBlockAddText(void *hBlock, char *szText, double X, double Y) { return NULL; }
void *LCAPI lcBlockAddText2(void *hBlock, char *szText, double X, double Y,
                            int Align, double H, double WScale, double RotAngle,
                            double Oblique) {
}
void *LCAPI lcBlockAddText3(void *hBlock, char *szText, double X1, double Y1,
                            double X2, double Y2, int Align, double HW,
                            double Oblique) {
}
void *LCAPI lcBlockAddTextWin(void *hBlock, char *szText, double X, double Y) { return NULL; }
void *LCAPI lcBlockAddTextWin2(void *hBlock, char *szText, double X, double Y,
                               int Align, double H, double WScale,
                               double RotAngle, double Oblique) {
}
void *LCAPI lcBlockAddMText(void *hBlock, char *szText, double X, double Y,
                            double WrapWidth, int Align, double RotAngle,
                            double H, double WScale) {
}
void *LCAPI lcBlockAddArcText(void *hBlock, char *szText, double X, double Y,
                              double Radius, double StartAngle, int bClockwise,
                              double H, double WScale, int Align) {
}
void *LCAPI lcBlockAddBlockRef(void *hBlock, void *hRefBlock, double X,
                               double Y, double Scal, double Angle) {
}
void *LCAPI lcBlockAddBlockRefID(void *hBlock, int idRefBlock, double X,
                                 double Y, double Scal, double Angle) {
} // undoc
void *LCAPI lcBlockAddBlockRefIDH(void *hBlock, char *szIdRefBlock, double X,
                                  double Y, double Scal, double Angle) {
} // undoc
void *LCAPI lcBlockAddAttDef(void *hBlock, int Mode, char *szTag,
                             char *szPrompt, char *szDefVal, double X, double Y,
                             int Align, double H, double WScale,
                             double RotAngle, double Oblique) {
}
void *LCAPI lcBlockAddXref(void *hBlock, char *szFileName, double X, double Y,
                           double ScalX, double ScalY, double Angle) {
}
void *LCAPI lcBlockAddImageRef(void *hBlock, void *hImage, double X, double Y,
                               double Width, double Height, int bBorder) {
}
void *LCAPI lcBlockAddImageRefUns(void *hBlock, void *hImage, double X,
                                  double Y, double Scal, int Align,
                                  int bBorder) {
}
void *LCAPI lcBlockAddImagePlace(void *hBlock, int Id, double X, double Y,
                                 double Width, double Height, int bBorder) {
}
void *LCAPI lcBlockAddEcw(void *hBlock, char *szFileName) { return NULL; }
void *LCAPI lcBlockAddBarcode(void *hBlock, int BarType, double Xc, double Yc,
                              double Width, double Height, char *szText) {
}
void *LCAPI lcBlockAddHatch(void *hBlock, char *szFileName, char *szPatName,
                            double Scal, double Angle) {
}
void *LCAPI lcBlockAddViewport(void *hBlock, double Lef, double Bot,
                               double Width, double Height, double DrwPntX,
                               double DrwPntY, double DrwScale,
                               double DrwAngle) {
}
void *LCAPI lcBlockAddFace(void *hBlock, int Flags, double x0, double y0,
                           double z0, double x1, double y1, double z1,
                           double x2, double y2, double z2) {
}
void *LCAPI lcBlockAddFace4(void *hBlock, int Flags, double x0, double y0,
                            double z0, double x1, double y1, double z1,
                            double x2, double y2, double z2, double x3,
                            double y3, double z3) {
}
void *LCAPI lcBlockAddLeader(void *hBlock, char *szText, double Xt, double Yt,
                             double LandDist, double Xa, double Ya, int Attach,
                             int Align) {
}
void *LCAPI lcBlockAddDimLin(void *hBlock, double X0, double Y0, double X1,
                             double Y1, double Xt, double Yt, double Angle,
                             char *szText) {
}
void *LCAPI lcBlockAddDimHor(void *hBlock, double X0, double Y0, double X1,
                             double Y1, double Yt, char *szText) {
}
void *LCAPI lcBlockAddDimVer(void *hBlock, double X0, double Y0, double X1,
                             double Y1, double Xt, char *szText) {
}
void *LCAPI lcBlockAddDimAli(void *hBlock, double X0, double Y0, double X1,
                             double Y1, double Xt, double Yt, char *szText) {
}
void *LCAPI lcBlockAddDimAli2(void *hBlock, double X0, double Y0, double X1,
                              double Y1, double Dt, char *szText) {
}
void *LCAPI lcBlockAddDimOrd(void *hBlock, double Xd, double Yd, double Xt,
                             double Yt, int bX, char *szText) {
}
void *LCAPI lcBlockAddDimRad(void *hBlock, double Xc, double Yc, double Xr,
                             double Yr, double Xt, double Yt, char *szText) {
}
void *LCAPI lcBlockAddDimRad2(void *hBlock, double Xc, double Yc, double R,
                              double Angle, double TextOff, char *szText) {
}
void *LCAPI lcBlockAddDimDia(void *hBlock, double Xc, double Yc, double Xr,
                             double Yr, double Xt, double Yt, char *szText) {
}
void *LCAPI lcBlockAddDimDia2(void *hBlock, double Xc, double Yc, double R,
                              double Angle, double TextOff, char *szText) {
}
void *LCAPI lcBlockAddDimAng(void *hBlock, double Xc, double Yc, double X1,
                             double Y1, double X2, double Y2, double Xa,
                             double Ya, double TextPos, char *szText) {
}
void *LCAPI lcBlockAddDimAng2(void *hBlock, double X1, double Y1, double X2,
                              double Y2, double X3, double Y3, double X4,
                              double Y4, double Xa, double Ya, double TextPos,
                              char *szText) {
}
void *LCAPI lcBlockAddRPlan(void *hBlock) { return NULL; }
void *LCAPI lcBlockAddRPlan2(void *hBlock, void *hStartEnt) { return NULL; }
void *LCAPI lcBlockAddArrow(void *hBlock, double X1, double Y1, double X2,
                            double Y2) {
}
void *LCAPI lcBlockAddSpiral(void *hBlock, double Xc, double Yc, double R,
                             double Turns, int bDirCW, int bClosed) {
}
void *LCAPI lcBlockAddCamview(void *hBlock, double Lef, double Bot,
                              double Width, double Height) {
}
void *LCAPI lcBlockAddTIN(void *hBlock, char *szFileName, int FileType) { return NULL; }
void *LCAPI lcBlockAddClone(void *hBlock, void *hEnt) { return NULL; }
int LCAPI lcBlockBeginShape(void *hBlock) { return 0; }
void *LCAPI lcBlockAddShape(void *hBlock) { return NULL; }
void *LCAPI lcBlockAddShapeSel(void *hBlock, int bErase) { return NULL; }
void *LCAPI lcBlockRepEllipse(void *hBlock, void *hEll, int *pRetType) { return NULL; }
int LCAPI lcBlockJoinAll(void *hBlock, double Delta) { return 0; }
int LCAPI lcBlockCopyLayer(void *hBlock, void *hLayerSrc, void *hLayerDest) { return 0; }
int LCAPI lcBlockDeleteEnt(void *hBlock, void *hEnt) { return 0; }

// Retrieve graphic objects from a block
void *LCAPI lcBlockGetFirstEnt(void *hBlock) { return NULL; }
void *LCAPI lcBlockGetNextEnt(void *hBlock, void *hEnt) { return NULL; }
void *LCAPI lcBlockGetLastEnt(void *hBlock) { return NULL; }
void *LCAPI lcBlockGetPrevEnt(void *hBlock, void *hEnt) { return NULL; }
void *LCAPI lcBlockGetEntByID(void *hBlock, int Id) { return NULL; }
void *LCAPI lcBlockGetEntByIDH(void *hBlock, char *szId) { return NULL; }
void *LCAPI lcBlockGetEntByKey(void *hBlock, int Key) { return NULL; }
void *LCAPI lcBlockGetBlkRefByTag(void *hBlock, void *hBlockAtt, char *szTag,
                                  char *szValue, int bSelect) {
}
void *LCAPI lcBlockGetTIN(void *hBlock, char *szName) { return NULL; }

// Selection
int LCAPI lcBlockUnselect(void *hBlock) { return 0; }
int LCAPI lcBlockSelectEnt(void *hBlock, void *hEntity, int bSelect) { return 0; }
int LCAPI lcBlockSelErase(void *hBlock) { return 0; }
int LCAPI lcBlockSelMove(void *hBlock, double dX, double dY, int bCopy,
                         int bNewSelect) {
}
int LCAPI lcBlockSelScale(void *hBlock, double X0, double Y0, double Scal,
                          int bCopy, int bNewSelect) {
}
int LCAPI lcBlockSelRotate(void *hBlock, double X0, double Y0, double Angle,
                           int bCopy, int bNewSelect) {
}
int LCAPI lcBlockSelMirror(void *hBlock, double X1, double Y1, double X2,
                           double Y2, int bCopy, int bNewSelect) {
}
int LCAPI lcBlockSelExplode(void *hBlock) { return 0; }
int LCAPI lcBlockSelSplit(void *hBlock, int nParts) { return 0; }
void *LCAPI lcBlockSelJoin(void *hBlock, double Delta) { return NULL; }
int LCAPI lcBlockSelAlign(void *hBlock, int Mode, double X, double Y) { return 0; }
void *LCAPI lcBlockSelBlock(void *hBlock, char *szName, double X, double Y,
                            int Mode, int bOverwrite) {
}
void *LCAPI lcBlockGetFirstSel(void *hBlock) { return NULL; }
void *LCAPI lcBlockGetNextSel(void *hBlock) { return NULL; }

// change entities order by layer
int LCAPI lcBlockOrderByLayers(void *hBlock, void *hWnd) { return 0; }
int LCAPI lcBlockSortTSP(void *hBlock, void *hLayer, void *hWnd) { return 0; }
double LCAPI lcBlockGetJumpsLen(void *hBlock, void *hLayer, void *hWnd) { return 0.0f; }

// remove entities of specified layer from a block (all blocks if hBlock=0)
int LCAPI lcLayerClear(void *hLayer, void *hBlock) { return 0; }
int LCAPI lcLayerCopyProps(void *hLayer, void *hFromLayer) { return 0; }

// add line to a filling (see also lcDrwAddFilling)
int LCAPI lcFillSetLine(void *hFill, int iLine, double Dist, double Angle,
                        double W) {
}

// Mline style
int LCAPI lcMLStyleAddLine(void *hStyle, double Offset, char *szColor,
                           void *hLtype) { return 0; }
int LCAPI lcMLStyleDelLine(void *hStyle, int iLine) { return 0; }
int LCAPI lcMLStyleSortLines(void *hStyle) { return 0; }

int LCAPI lcEntType(void *hEnt, int Typ) { return 0; }

// Graphic object modify
int LCAPI lcEntErase(void *hEnt, int bErase) { return 0; }
int LCAPI lcEntMove(void *hEnt, double dX, double dY) { return 0; }
int LCAPI lcEntAlign(void *hEnt, int Alignment, double X, double Y) { return 0; }
int LCAPI lcEntScale(void *hEnt, double X0, double Y0, double Scal) { return 0; }
int LCAPI lcEntRotate(void *hEnt, double X0, double Y0, double Angle) { return 0; }
int LCAPI lcEntMirror(void *hEnt, double X1, double Y1, double X2, double Y2) { return 0; }
int LCAPI lcEntExplode(void *hEnt, int bSelect, int bErase) { return 0; }
void *LCAPI lcEntSplit(void *hEnt, int nParts, int bSelectNew, int bDeleteEnt) { return NULL; }
void *LCAPI lcEntBreak(void *hEnt, double X, double Y, double Delta,
                       int bSelectNew, int bDeleteEnt) {
}
void *LCAPI lcEntBreak2(void *hEnt, void *hPtbuf, double Delta, int bSelectNew,
                        int bDeleteEnt) {
}
int LCAPI lcEntOffset(void *hEnt, double Dist) { return 0; }
int LCAPI lcEntExtend(void *hEnt, void *hEntEdge, int bApparent) { return 0; }
int LCAPI lcEntToTop(void *hEnt) { return 0; }
int LCAPI lcEntToBottom(void *hEnt) { return 0; }
int LCAPI lcEntToAbove(void *hEnt, void *hEnt2) { return 0; }
int LCAPI lcEntToUnder(void *hEnt, void *hEnt2) { return 0; }
int LCAPI lcEntGetGrip(void *hEnt, int iGrip, double *pX, double *pY) { return 0; }
int LCAPI lcEntPutGrip(void *hEnt, int iGrip, double X, double Y) { return 0; }
int LCAPI lcEntUpdate(void *hEnt) { return 0; }
int LCAPI lcEntCopyBase(void *hEnt, void *hEntFrom) { return 0; }
int LCAPI lcEntXData(void *hEnt, int Id, int Flags, int nBytes) { return 0; }
int LCAPI lcEntContainEnt(void *hEnt, void *hEnt2) { return 0; }
int LCAPI lcEntCrossEnt(void *hEnt, void *hEnt2) { return 0; }
int LCAPI lcEntReverse(void *hEnt) { return 0; }
int LCAPI lcEntGetPoint(void *hEnt, double Dist, double *pX, double *pY,
                        double *pAngle) {
}
double LCAPI lcEntGetDist(void *hEnt, double X, double Y, double *pX2,
                          double *pY2, double *pDist) {
}
int LCAPI lcEntTransform(void *hEnt, void *hTransform) { return 0; }
int LCAPI lcIntersection(void *hEnt, void *hEnt2, int Apparent) { return 0; }
int LCAPI lcInterGetPoint(int iPoint, double *pX, double *pY) { return 0; }

int LCAPI lcLineGetPoint(void *hLine, int Mode, double Dist, double *pX,
                         double *pY) {
}

// Polyline Vertices
void *LCAPI lcPlineAddVer(void *hPline, void *hVer, double X, double Y) {
  gllc_pline_add_ver(hPline, X, Y);
  return NULL;
}
void *LCAPI lcPlineAddVer2(void *hPline, void *hVer, double X, double Y,
                           double Param, double W0, double W1) {
}
void *LCAPI lcPlineAddVerDir(void *hPline, void *hVer, double Ang,
                             double Length) {
}
int LCAPI lcPlineEnd(void *hPline) {
  gllc_pline_end((struct gllc_polyline *)hPline);
  return 1;
}
int LCAPI lcPlineFromPtbuf(void *hPline, void *hPtbuf) { return 0; }
int LCAPI lcPlineFromMpgon(void *hPline, void *hMpgon) { return 0; }
int LCAPI lcPlineFromFile(void *hPline, char *szFileName) { return 0; }
int LCAPI lcPlineDeleteVer(void *hPline, void *hVer) { return 0; }
int LCAPI lcPlineDelExVers(void *hPline, double Delta) { return 0; }
void *LCAPI lcPlineGetFirstVer(void *hPline) { return NULL; }
void *LCAPI lcPlineGetNextVer(void *hPline, void *hVer) { return NULL; }
void *LCAPI lcPlineGetLastVer(void *hPline) { return NULL; }
void *LCAPI lcPlineGetPrevVer(void *hPline, void *hVer) { return NULL; }
void *LCAPI lcPlineGetVer(void *hPline, int Index) { return NULL; }
void *LCAPI lcPlineGetVerPt(void *hPline, double X, double Y, double Delta) { return NULL; }
void *LCAPI lcPlineGetSeg(void *hPline, double X, double Y, double Delta) { return NULL; }
int LCAPI lcPlineReverse(void *hPline) { return 0; }
int LCAPI lcPlineSetStartVer(void *hPline, void *hVer) { return 0; }
int LCAPI lcPlineContainPoint(void *hPline, double X, double Y) { return 0; }
int LCAPI lcPlineGetRoundPrm(void *hPline, void *hVer, double *pX0, double *pY0,
                             double *pBulge, double *pX1,
                             double *pY1) {
} // undoc (dwg plugin)
int LCAPI lcPlineGetPoint(void *hPline, double Dist, double *pX, double *pY,
                          double *pAngle) {
}
int LCAPI lcPlineGetPointOpp(void *hPline, double Dist, double *pX, double *pY,
                             double *pAngle, double *pX2, double *pY2) {
}
double LCAPI lcPlineGetDist(void *hPline, double X, double Y, double *pX2,
                            double *pY2, double *pDist) {
}
int LCAPI lcPlineDivide(void *hPline, int nPoints, int bAngle) { return 0; }
int LCAPI lcPlineDivide2(void *hPline, double Delta, int bAngle) { return 0; }
int LCAPI lcGetDivPt(int iPnt, double *pX, double *pY, double *pAngle) { return 0; }
int LCAPI lcPlineMakeArrow(void *hPline, double Hline, double Harr) { return 0; }    // undoc
void *LCAPI lcPlineSplitBySI(void *hPline, int bSelect, int bErase) { return NULL; } // undoc

// Bezier Vertices
void *LCAPI lcBezierAddVer(void *hBez, void *hVer, double X, double Y) { return NULL; }
int LCAPI lcBezierEnd(void *hBez) { return 0; }
int LCAPI lcBezierSetVerPrm(void *hBez, void *hVer, int Side, double Leng,
                            double Ang) {
}

// Mline Vertices
void *LCAPI lcMlineAddVer(void *hMline, void *hVer, double X, double Y) { return NULL; }
void *LCAPI lcMlineAddVerDir(void *hMline, void *hVer, double Ang,
                             double Length) {
}
int LCAPI lcMlineDeleteVer(void *hMline, void *hVer) { return 0; }
void *LCAPI lcMlineGetFirstVer(void *hMline) { return NULL; }
void *LCAPI lcMlineGetNextVer(void *hMline, void *hVer) { return NULL; }
void *LCAPI lcMlineGetLastVer(void *hMline) { return NULL; }
void *LCAPI lcMlineGetPrevVer(void *hMline, void *hVer) { return NULL; }
void *LCAPI lcMlineGetVer(void *hMline, int Index) { return NULL; }
void *LCAPI lcMlineGetVerPt(void *hMline, double X, double Y, double Delta) { return NULL; }
void *LCAPI lcMlineGetSeg(void *hMline, double X, double Y,
                          double Delta) {
} // undoc
int LCAPI lcMlineReverse(void *hMline) { return 0; }

// RPlan functions
void *LCAPI lcRPlanAddVer(void *hRPlan, double X, double Y) { return NULL; }
int LCAPI lcRPlanSetCurve(void *hVer, double Radius, double LenClot1,
                          double LenClot2) {
}
int LCAPI lcRPlanSetPos(void *hVer, double X, double Y) { return 0; }
int LCAPI lcRPlanDeleteVer(void *hRPlan, void *hVer) { return 0; }
void *LCAPI lcRPlanGetFirstVer(void *hRPlan) { return NULL; }
void *LCAPI lcRPlanGetNextVer(void *hRPlan, void *hVer) { return NULL; }
void *LCAPI lcRPlanGetLastVer(void *hRPlan) { return NULL; }
void *LCAPI lcRPlanGetPrevVer(void *hRPlan, void *hVer) { return NULL; }
void *LCAPI lcRPlanGetVer(void *hRPlan, int Index) { return NULL; }
int LCAPI lcRPlanGetPoint(void *hRPlan, double Dist, double *pX, double *pY,
                          double *pAngle, int *pSide) {
}
int LCAPI lcRPlanGetDist(void *hRPlan, double X, double Y, double *pX2,
                         double *pY2, double *pDist, double *pOffset) {
}
int LCAPI lcRPlanWriteCSV(void *hRPlan, char *szFileName) { return 0; }

// Construction line
int LCAPI lcXlinePutDir(void *hXline, double X, double Y) { return 0; }

// Rectangle
int LCAPI lcRectGetPolyline(void *hRect, double *pX, double *pY,
                            double *pBulge) {
}

// Circle

// Image reference
int LCAPI lcImgRefGetPixel(void *hImgRef, int iX, int iY, double *pX,
                           double *pY, int *pColor) {
}
int LCAPI lcImgRefResize(void *hImgRef, int NewWidth, int NewHeight,
                         int Method) {
}

// Hatch
int LCAPI lcHatchSetPattern(void *hHatch, char *szFileName, char *szPatName,
                            double Scal, double Angle) {
}
int LCAPI lcHatchBoundStart(void *hHatch) { return 0; }
int LCAPI lcHatchBoundPoint(void *hHatch, double X, double Y) { return 0; }
int LCAPI lcHatchBoundEntity(void *hHatch, void *hEnt) { return 0; }
int LCAPI lcHatchBoundEndLoop(void *hHatch) { return 0; }
int LCAPI lcHatchBoundEnd(void *hHatch) { return 0; }
int LCAPI lcHatchPatStart(void *hHatch) { return 0; }
int LCAPI lcHatchPatLine(void *hHatch, double Angle, double x0, double y0,
                         double dx, double dy, int nDash, double L0, double L1,
                         double L2, double L3, double L4, double L5, double L6,
                         double L7) {
}
int LCAPI lcHatchPatEnd(void *hHatch) { return 0; }
int LCAPI lcHatchGetLoopSize(void *hHatch, int iLoop) { return 0; }
int LCAPI lcHatchGetPoint(void *hHatch, int iPnt, double *pX, double *pY) { return 0; }
void *LCAPI lcHatchGetEnt(void *hHatch, int Mode) { return NULL; }

// Viewport
int LCAPI lcVportSetView(void *hVport, double Xcen, double Ycen, double Scal,
                         double Angle) {
}
int LCAPI lcVportLayerDlg(void *hVport, void *hLcWnd) { return 0; }
int LCAPI lcVportLayerCmd(void *hVport, int Cmd, void *hLayer) { return 0; }

// Block attribute
void *LCAPI lcBlkRefAddAtt(void *hBlockRef, char *szTag,
                           char *szValue) {
} // for using in DWG plugin
void *LCAPI lcBlkRefGetFirstAtt(void *hBlockRef) { return NULL; }
void *LCAPI lcBlkRefGetNextAtt(void *hBlockRef, void *hAttrib) { return NULL; }
void *LCAPI lcBlkRefGetAtt(void *hBlockRef, char *szTag) { return NULL; }
char *LCAPI lcBlkRefGetAttVal(void *hBlockRef, char *szTag) { return NULL; }
int LCAPI lcBlkRefPutAttVal(void *hBlockRef, char *szTag, char *szValue) { return 0; }

// Shape
int LCAPI lcShapeAddEnt(void *hShape, void *hEnt, int bErase) { return 0; }
int LCAPI lcShapeEnd(void *hShape) { return 0; }
void *LCAPI lcShapeGetFirstEnt(void *hShape) { return NULL; }
void *LCAPI lcShapeGetNextEnt(void *hShape, void *hEnt) { return NULL; }
void *LCAPI lcShapeGetLastEnt(void *hShape) { return NULL; }
void *LCAPI lcShapeGetPrevEnt(void *hShape, void *hEnt) { return NULL; }

// TIN entity //(also LC_PROP_TIN_FILENAME and others, lcBlockGetTIN )
void *LCAPI lcTIN_AddPoint(void *hTIN, char *szNamePtype, double X, double Y,
                           double Z) {
}
void *LCAPI lcTIN_PtypeGetByName(void *hTIN, char *szName) { return NULL; }
void *LCAPI lcTIN_PtypeGetFirst(void *hTIN) { return NULL; }
void *LCAPI lcTIN_PtypeGetNext(void *hTIN, void *hPtype) { return NULL; }
void *LCAPI lcTIN_PntGetFirst(void *hTIN) { return NULL; }
void *LCAPI lcTIN_PntGetNext(void *hTIN, void *hPnt) { return NULL; }
void *LCAPI lcTIN_PntGetNear(void *hTIN, double X, double Y) { return NULL; }
int LCAPI lcTIN_PntDelDup(void *hTIN, double Delta, void *hLcWnd) { return 0; }
void *LCAPI lcTIN_TriGetFirst(void *hTIN) { return NULL; }
void *LCAPI lcTIN_TriGetNext(void *hTIN, void *hTrian) { return NULL; }
void *LCAPI lcTIN_TriGetByPos(void *hTIN, double X, double Y) { return NULL; }
int LCAPI lcTIN_TriGetEdge(void *hTIN, void *hTrian, int iEdge) { return 0; }
int LCAPI lcTIN_TriUpdate(void *hTIN, void *hPnt) { return 0; }
int LCAPI lcTIN_Bnd(void *hTIN, double MaxDist, void *hLcWnd) { return 0; }
void *LCAPI lcTIN_BndGetPoint(void *hTIN, int iPnt) { return NULL; }
int LCAPI lcTIN_Triangulate(void *hTIN, void *hLcWnd) { return 0; } // LC_CMD_TIN_BNDTRANG
int LCAPI lcTIN_Isolines(void *hTIN, double Zstep, int BoldStep, void *hLcWnd) { return 0; }
void *LCAPI lcTIN_IsoGetFirst(void *hTIN) { return NULL; }
void *LCAPI lcTIN_IsoGetNext(void *hTIN, void *hIso) { return NULL; }
int LCAPI lcTIN_IsoMakeLabels(void *hIso) { return 0; }
int LCAPI lcTIN_GetIsoLabel(int iLabel, double *pX, double *pY, double *pAngle,
                            int *pAlign) { return 0; }
int LCAPI lcTIN_GetZ(void *hTIN, double X, double Y, double *pZ) { return 0; }
int LCAPI lcTIN_ColorFill(void *hTIN, double Zstep, double PixelSize,
                          void *hLcWnd) { return 0; }
int LCAPI lcTIN_Save(void *hTIN, char *szFileName, int Mode, int bByBndr,
                     void *hLcWnd) { return 0; }
int LCAPI lcTIN_InterLine(void *hTIN, double X0, double Y0, double X1,
                          double Y1) {
}
int LCAPI lcTIN_InterGetPoint(void *hTIN, int iPnt, double *pX, double *pY,
                              double *pZ) {
}
int LCAPI lcTIN_Clear(void *hTIN) { return 0; }
void *LCAPI lcTIN_AddTrian(void *hTIN, int iPnt0, int iPnt1, int iPnt2) { return NULL; }
int LCAPI lcTIN_BndAddPnt(void *hTIN, int iPnt) { return 0; }
int LCAPI lcTIN_Merge(void *hTIN, char *szFileName, void *hLcWnd) { return 0; }

int LCAPI lcColorRGB(int Red, int Green, int Blue) { return 0; }
// Color from string
int LCAPI lcColorIsRGB(char *szColor) { return 0; }
int LCAPI lcColorGetRed(char *szColor) { return 0; }
int LCAPI lcColorGetGreen(char *szColor) { return 0; }
int LCAPI lcColorGetBlue(char *szColor) { return 0; }
int LCAPI lcColorGetIndex(char *szColor, int bLogicalEnabled) { return 0; }
int LCAPI lcColorToVal(char *szColor, int *pbRGB, int *pIndex, int *pR, int *pG,
                       int *pB) { return 0; }
// Color palette
int LCAPI lcColorSetPalette(int Index, int R, int G, int B) { return 0; }
int LCAPI lcColorGetPalette(int Index, int *pR, int *pG, int *pB) { return 0; }
int LCAPI lcColorSavePalette(char *szFileName, void *hWnd) { return 0; }
int LCAPI lcColorLoadPalette(char *szFileName, void *hWnd) { return 0; }

// Image
int LCAPI lcImageSetPixelRGB(void *hImage, int X, int Y, int Red, int Green,
                             int Blue) {
}
int LCAPI lcImageSetPixelI(void *hImage, int X, int Y, int iColor) { return 0; }
int LCAPI lcImageGetPixelRGB(void *hImage, int X, int Y, int *pRed, int *pGreen,
                             int *pBlue) { return 0; }
int LCAPI lcImageGetPixelI(void *hImage, int X, int Y, int *piColor) { return 0; }
int LCAPI lcImageSetPalColor(void *hImage, int iColor, int Red, int Green,
                             int Blue) {
}
int LCAPI lcImageGetPalColor(void *hImage, int iColor, int *pRed, int *pGreen,
                             int *pBlue) { return 0; }
int LCAPI lcImageLoad(void *hImage, char *szFilename, void *hWnd) { return 0; }
int LCAPI lcImageLoadDIB(void *hImage, void *hDib2) { return 0; } // undoc
int LCAPI lcImageLoadCamera(void *hImage) { return 0; }
int LCAPI lcImageCopyQuad(void *hImage, void *hImageSrc, unsigned int W,
                          unsigned int H, double x0, double y0, double x1,
                          double y1, double x2, double y2, double x3,
                          double y3) {
} // undoc
int LCAPI lcImageProc(void *hImage, int Mode) { return 0; }

// Toolbar Window

// explode entity to polylines, Flags is LC_EXP_ALL or other
int LCAPI lcExpEntity(void *hEnt, int iChar, int Flags, int bUnrotate) { return 0; }
int LCAPI lcExpGetPline(double Delta) { return 0; }
int LCAPI lcExpGetVertex(double *pX, double *pY) { return 0; }
int LCAPI lcExpBlock(void *hBlock, F_LCEVENT pFunc, int Prm1, void *Prm2) { return 0; }

int LCAPI lcGbrLoad(void *hLcWnd, char *szFileName0) { return 0; }
int LCAPI lcGbrClose(void *hLcWnd) { return 0; }

char *LCAPI lcPlugGetOption(char *szFileName, char *szKey) { return NULL; }
int LCAPI lcPlugGetOption2(char *szFileName, char *szKey) { return 0; }
int LCAPI lcPlugSetOption(char *szFileName, char *szKey, char *szValue,
                          int bSave) {
}

int LCAPI lcPrintSetup(void *hWnd) { return 0; }
int LCAPI lcPrintLayout(void *hBlock) { return 0; }
int LCAPI lcPrintBlock(void *hBlock, double X, double Y, double W, double H,
                       double Scal, double PapLef, double PapTop, int Options) {
}

void *LCAPI lcXDataBegin() { return NULL; }
int LCAPI lcXDataEnd(void *hData) { return 0; }
int LCAPI lcXDataClear(void *hData) { return 0; }
int LCAPI lcXDataSet(void *hData) { return 0; }

// NoDB mode
// ////////////////////////////////////////////////////////////////////////////////////////

// Window Tabs
int LCAPI lcWndTabClear(void *hLcWnd) { return 0; }
int LCAPI lcWndTabAdd(void *hLcWnd, int TabID, char *szLabel, char *szTipText,
                      void *hObject) { return 0; }
int LCAPI lcWndTabSelect(void *hLcWnd, int TabID) { return 0; }

// Paper
int LCAPI lcWndPaperEnable(void *hLcWnd, int bEnable) { return 0; }
int LCAPI lcWndPaperSetSize(void *hLcWnd, int Size, int Orient) { return 0; }
int LCAPI lcWndPaperSetSize2(void *hLcWnd, double Width, double Height) { return 0; }
int LCAPI lcWndPaperSetPos(void *hLcWnd, double Left, double Bottom) { return 0; }

// Grips
int LCAPI lcGripClear(void *hLcWnd) { return 0; }
int LCAPI lcGripAdd(void *hLcWnd, void *hObj, int iGrip, int Typ, double X,
                    double Y, double Ang, double X0, double Y0) {
}
int LCAPI lcGripSet(void *hLcWnd, void *hObj, int iGrip, double X, double Y,
                    double Ang, double X0, double Y0) {
}

// to draw inside of Paint event procedure
void *LCAPI lcPaint_PenCreate(void *hLcWnd, int Id, int Color, double Width,
                              int PenStyle) {
}
int LCAPI lcPaint_PenSelect(void *hLcWnd, void *hPen) { return 0; }
int LCAPI lcPaint_PenSelectID(void *hLcWnd, int IdPen) { return 0; }
void *LCAPI lcPaint_BrushCreate(void *hLcWnd, int Id, int Color, int Pattern,
                                int Alpha) {
}
int LCAPI lcPaint_BrushSelect(void *hLcWnd, void *hBrush) { return 0; }
int LCAPI lcPaint_BrushSelectID(void *hLcWnd, int IdBrush) { return 0; }

int LCAPI lcPaint_DrawPtbuf(void *hLcWnd, void *hPtbuf, int bClosed) { return 0; }
int LCAPI lcPaint_DrawMpgon(void *hLcWnd, void *hMpgon, int bFill, int bBorder) { return 0; }
int LCAPI lcPaint_DrawImage(void *hLcWnd, void *hImage, double X, double Y,
                            double PixelSize, int Transp, int TVal,
                            void *hPtbuf) { return 0; }
int LCAPI lcPaint_DrawImage2(void *hLcWnd, void *hImage, double X, double Y,
                             double W, double H, int Transp, int TVal,
                             void *hPtbuf) { return 0; }
int LCAPI lcPaint_DrawText(void *hLcWnd, double X, double Y, char *szText) { return 0; }
int LCAPI lcPaint_DrawText2(void *hLcWnd, double X1, double Y1, double X2,
                            double Y2, int Align, char *szText) {
}
int LCAPI lcPaint_DrawTextBC(void *hLcWnd, void *hMpgon, double Gap,
                             double Height, int Align, char *szText) {
}
int LCAPI lcPaint_DrawArcText(void *hLcWnd, char *szText, double X, double Y,
                              double Rad, double Ang0, int bCW, double H,
                              double WScale, int Align) {
}
int LCAPI lcPaint_DrawHatch(void *hLcWnd, void *hHatch) { return 0; }
int LCAPI lcPaint_DrawPoint(void *hLcWnd, double X, double Y, int PtMode,
                            double PtSize) {
}
int LCAPI lcPaint_DrawLine(void *hLcWnd, double X1, double Y1, double X2,
                           double Y2) {
}
int LCAPI lcPaint_DrawXline(void *hLcWnd, double X, double Y, double Angle,
                            int bRay) {
}
int LCAPI lcPaint_DrawRect(void *hLcWnd, double Xc, double Yc, double Width,
                           double Height) {
}
int LCAPI lcPaint_DrawRect2(void *hLcWnd, double X1, double Y1, double X2,
                            double Y2) {
}
int LCAPI lcPaint_DrawPickBox(void *hLcWnd) { return 0; }
int LCAPI lcPaint_DrawGrid(void *hLcWnd, void *hGrid, int bDest, int ColLine,
                           int ColNode) {
}
int LCAPI lcPaint_DrawCPrompt(void *hLcWnd, int X, int Y, int Align,
                              char *szText) {
}
void LCAPI lcPaint_SetPixel(void *hDC, int X, int Y, int Color) {
}

// Points buffer
void *LCAPI lcPaint_CreatePtbuf() { return NULL; }
int LCAPI lcPaint_DeletePtbuf(void *hPtbuf) { return 0; }
int LCAPI lcPaint_PtbufClear(void *hPtbuf) { return 0; }
int LCAPI lcPaint_PtbufAddPoint(void *hPtbuf, double X, double Y, double Prm1,
                                double Prm2, int IntPrm) {
}
int LCAPI lcPaint_PtbufAddPoint2(void *hPtbuf, double X, double Y) { return 0; }
int LCAPI lcPaint_PtbufAddPointP(void *hPtbuf, double Angle, double Dist) { return 0; }
int LCAPI lcPaint_PtbufAddLine(void *hPtbuf, double X1, double Y1, double X2,
                               double Y2) {
}
int LCAPI lcPaint_PtbufAddLineP(void *hPtbuf, double X, double Y, double Angle,
                                double Dist) {
}
int LCAPI lcPaint_PtbufAddCircle(void *hPtbuf, double Xc, double Yc, double R,
                                 int Resol) {
}
int LCAPI lcPaint_PtbufAddCircle2(void *hPtbuf, double X1, double Y1, double X2,
                                  double Y2, int Resol) {
}
int LCAPI lcPaint_PtbufAddCircle3(void *hPtbuf, double X1, double Y1, double X2,
                                  double Y2, double X3, double Y3, int bInside,
                                  int Resol) {
}
int LCAPI lcPaint_PtbufAddArc(void *hPtbuf, double Xc, double Yc, double R,
                              double StartAngle, double ArcAngle, int Resol) {
}
int LCAPI lcPaint_PtbufAddArc3p(void *hPtbuf, double X1, double Y1, double X2,
                                double Y2, double X3, double Y3, int Resol) {
}
int LCAPI lcPaint_PtbufAddArcSDE(void *hPtbuf, double Xs, double Ys,
                                 double DirAng, double Xe, double Ye,
                                 int Resol) {
}
int LCAPI lcPaint_PtbufAddArcSDAR(void *hPtbuf, double Xs, double Ys,
                                  double DirAng, double AngArc, double R,
                                  int Resol) {
}
int LCAPI lcPaint_PtbufAddArcSER(void *hPtbuf, double Xs, double Ys, double Xe,
                                 double Ye, double Radius, int bClockwise,
                                 int Resol) {
}
int LCAPI lcPaint_PtbufAddArcSEL(void *hPtbuf, double Xs, double Ys, double Xe,
                                 double Ye, double ArcLen, int bClockwise,
                                 int Resol) {
}
int LCAPI lcPaint_PtbufAddArcSEA(void *hPtbuf, double Xs, double Ys, double Xe,
                                 double Ye, double AngArc, int Resol) {
}
int LCAPI lcPaint_PtbufAddArcSEB(void *hPtbuf, double Xs, double Ys, double Xe,
                                 double Ye, double Bulge, int Resol) {
}
int LCAPI lcPaint_PtbufAddArcCSE(void *hPtbuf, double Xc, double Yc, double Xs,
                                 double Ys, double Xe, double Ye,
                                 int bClockwise, int Resol) {
}
int LCAPI lcPaint_PtbufAddArcCSA(void *hPtbuf, double Xc, double Yc, double Xs,
                                 double Ys, double AngArc, int Resol) {
}
int LCAPI lcPaint_PtbufAddArcCSL(void *hPtbuf, double Xc, double Yc, double Xs,
                                 double Ys, double ChordLen, int bClockwise,
                                 int Resol) {
}
int LCAPI lcPaint_PtbufAddArcCRAA(void *hPtbuf, double Xc, double Yc, double R,
                                  double AngStart, double AngEnd,
                                  int bClockwise, int Resol) {
}
int LCAPI lcPaint_PtbufAddEllipse(void *hPtbuf, double Xc, double Yc,
                                  double Rmaj, double Rmin, double RotAng,
                                  double StartAng, double ArcAng, int Resol) {
}
int LCAPI lcPaint_PtbufAddEllipse2(void *hPtbuf, double X1, double Y1,
                                   double X2, double Y2, int Resol) {
}
int LCAPI lcPaint_PtbufAddRect(void *hPtbuf, double Xc, double Yc, double W,
                               double H, double Angle, double R, int Resol) {
}
int LCAPI lcPaint_PtbufAddRect2(void *hPtbuf, double X1, double Y1, double X2,
                                double Y2, double R, int Resol) {
}
int LCAPI lcPaint_PtbufAddRect3(void *hPtbuf, double X1, double Y1, double X2,
                                double Y2, double W, int Align, double R,
                                int Resol) {
}
int LCAPI lcPaint_PtbufAddWline(void *hPtbuf, double X1, double Y1, double X2,
                                double Y2, double W, int Align, int bArc,
                                int Resol) {
}
int LCAPI lcPaint_PtbufAddPtbuf(void *hPtbuf, void *hPtbuf2) { return 0; }
int LCAPI lcPaint_PtbufGetPoint(void *hPtbuf, int Mode, double *pX, double *pY) { return 0; }
int LCAPI lcPaint_PtbufGetPoint2(void *hPtbuf, int Mode, double *pX, double *pY,
                                 double *pPrm1, double *pPrm2, int *pIntPrm) {
}
int LCAPI lcPaint_PtbufInterpolate(void *hPtbuf, int bClosed, void *hPtbufDest,
                                   int Mode, int Resol) {
}
int LCAPI lcPaint_PtbufMove(void *hPtbuf, double dx, double dy) { return 0; }
int LCAPI lcPaint_PtbufRotate(void *hPtbuf, double Xc, double Yc, double Angle) { return 0; }
int LCAPI lcPaint_PtbufScale(void *hPtbuf, double Xc, double Yc, double ScaleX,
                             double ScaleY) {
}
int LCAPI lcPaint_PtbufMirror(void *hPtbuf, double X1, double Y1, double X2,
                              double Y2) {
}
int LCAPI lcPaint_PtbufCopy(void *hPtbuf, void *hPtbufDest) { return 0; }

// Multipolygon
void *LCAPI lcPaint_CreateMpgon() { return NULL; }
int LCAPI lcPaint_DeleteMpgon(void *hMpgon) { return 0; }
int LCAPI lcPaint_MpgonClear(void *hMpgon) { return 0; }
int LCAPI lcPaint_MpgonAddPgon(void *hMpgon, void *hPtbuf) { return 0; }
int LCAPI lcPaint_MpgonAddText(void *hMpgon, void *hFont, double X, double Y,
                               char *szText, int Resol) {
}
int LCAPI lcPaint_MpgonAddBarcode(void *hMpgon, int BarType, double Xc,
                                  double Yc, double Width, double Height,
                                  char *szText) {
}
int LCAPI lcPaint_MpgonMove(void *hMpgon, double dx, double dy) { return 0; }
int LCAPI lcPaint_MpgonRotate(void *hMpgon, double Xc, double Yc, double Angle) { return 0; }
int LCAPI lcPaint_MpgonScale(void *hMpgon, double Xc, double Yc, double ScaleX,
                             double ScaleY) {
}
int LCAPI lcPaint_MpgonMirror(void *hMpgon, double X1, double Y1, double X2,
                              double Y2) {
}
int LCAPI lcPaint_MpgonCopy(void *hMpgon, void *hMpgonDest) { return 0; }

int LCAPI lcPaint_HatchGen(void *hMpgon, void *hHatch, double Dist,
                           double Angle, double Gap) {
}

// Image
void *LCAPI lcPaint_ImageAdd(int Id) { return NULL; }
int LCAPI lcPaint_ImageDelete(void *hImage) { return 0; }
void *LCAPI lcPaint_ImageGetFirst() { return NULL; }
void *LCAPI lcPaint_ImageGetNext(void *hImage) { return NULL; }
void *LCAPI lcPaint_ImageGetByID(int Id) { return NULL; }
int LCAPI lcPaint_ImageLoad(void *hImage, char *szFileName) { return 0; }
int LCAPI lcPaint_ImageCopy(void *hImage, void *hImageDest) { return 0; }
int LCAPI lcPaint_ImageCreate(void *hImage, int Width, int Height) { return 0; }
int LCAPI lcPaint_ImageSetPixel(void *hImage, int X, int Y, int R, int G,
                                int B) {
}
int LCAPI lcPaint_ImageFlip(void *hImage, int bHor, int bVert) { return 0; }
int LCAPI lcPaint_ImageRotate(void *hImage, double Angle) { return 0; }
int LCAPI lcPaint_ImageGray(void *hImage) { return 0; }
int LCAPI lcPaint_ImageResize(void *hImage, int NewWidth, int NewHeight,
                              int ResizeFilter) {
}
void *LCAPI lcPaint_ImageGetPtbuf(void *hImage, double RotAngle) { return NULL; }

void *LCAPI lcPaint_FontOpenLC(char *szFontName) { return NULL; }
void *LCAPI lcPaint_FontOpenTT(char *szFontName, int bBold, int bItalic) { return NULL; }
int LCAPI lcPaint_FontClose(void *hFont) { return 0; }
int LCAPI lcPaint_FontSelect(void *hLcWnd, void *hFont) { return 0; }

int lcLoadLib(char *szFileName) {
}
void lcFreeLib() {
}
