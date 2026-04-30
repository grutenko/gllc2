import ctypes as ct
import ctypes.wintypes as wt
litecad = ct.WinDLL("./litecad64.dll")

#  Project: LiteCAD DLL


#  Copyright (C) 2009-2023, Oleg Kolbaskin.


#  All rights reserved.


# 


#  API definitions and external functions


# *******************************************************************/

LC_FALSE =    0  
LC_TRUE =     1 

#  LiteCAD window styles ( lcCreateWindow )

LC_WS_HSCROLL =     1    #  Window has a horizontal scroll bar
LC_WS_VSCROLL =     2    #  Window has a vertical scroll bar
LC_WS_BORDER =      4    #  Window has a thin-line border
LC_WS_CLIENTEDGE =  8    
LC_WS_SUNKEN =      8    #  Window has a border with a sunken edge
LC_WS_STATICEDGE =  16   #  Window has a three-dimensional border style
LC_WS_RULERS =      256  #  Window has rulers
LC_WS_VIEWTABS =    512  #  Window has View Tabs (border frame automatically added)
LC_WS_FILETABS =    1024 #  Window has File Tabs (border frame automatically added)
LC_WS_DEFAULT =     3    #  Combination of LC_WS_VSCROLL and LC_WS_HSCROLL styles
LC_MRU_IMAGE_W =  348    #  same as MRU_IMAGE_W
LC_MRU_IMAGE_H =  273    #  same as MRU_IMAGE_H

#  Pen Styles ( lcPenCreate )

LC_PS_SOLID =           0
LC_PS_DASH =            1       #  ------- 
LC_PS_DOT =             2       #  ....... 
LC_PS_DASHDOT =         3       #  _._._._ 
LC_PS_DASHDOTDOT =      4       #  _.._.._ 

#  Line width display mmode ( LC_PROP_DRW_LWMODE )

LC_LW_THIN =   0
LC_LW_REAL =   1
LC_LW_PIXEL =  2   #  depends on LC_PROP_WND_LWSCALE

#  Filling type ( LC_PROP_FILL_TYPE, lcBrushCreate )

LC_FILL_SOLID =        0
LC_FILL_BDIAGONAL =    1    #  by LcDatabase::m_bEnableHatchBrush
LC_FILL_CROSS =        2
LC_FILL_DIAGCROSS =    3
LC_FILL_FDIAGONAL =    4
LC_FILL_HORIZONTAL =   5
LC_FILL_VERTICAL =     6

#  ResizeFilter types ( lcImageResize & lcWndToRaster )

LC_IMGRES_BOX =         0  #  Box, pulse, Fourier window, 1st order (constant) B-Spline
LC_IMGRES_BILINEAR =    1  #  Bilinear filter
LC_IMGRES_BSPLINE =     2  #  4th order (cubic) B-Spline
LC_IMGRES_BICUBIC =     3  #  Mitchell and Netravali's two-param cubic filter
LC_IMGRES_CATMULLROM =  4  #  Catmull-Rom spline, Overhauser spline
LC_IMGRES_LANCZOS3 =    5  #  Lanczos-windowed sinc filter

#  modes for lcImageProc

LC_IMGPROC_GRAY =       1
LC_IMGPROC_FLIPHOR =    2
LC_IMGPROC_FLIPVER =    3
LC_IMGPROC_ROT180 =     4

#  Grip type ( lcGripAdd )

LC_GRIP_POINT =    0
LC_GRIP_CENROT =   1   #  center of rotation
LC_GRIP_ANGLE =    2
LC_GRIP_ANGLE2 =   3   #  same as LC_GRIP_ANGLE but more offset
LC_GRIP_BEZIER =   4
LC_GRIP_BEZIER0 =  5
LC_GRIP_ARCRAD =   6

#  flags for LC_PROP_ENT_GRIPMODE - behavior concerning grips

LC_GRIP_NOMOVE =    1   #  disable grips for entity movement
LC_GRIP_NOROTATE =  2   #  disable grips for entity rotation
LC_GRIP_NOSCALE =   4   #  disable grips for entity scale

#  Barcode type ( lcMpgonAddBarcode, LC_PROP_BARC_TYPE )


#  Must be same values as BARC_TYPE_... in BaseLibs\Barcode\Barcode.h

LC_BARTYPE_CODE39 =    0
LC_BARTYPE_CODE93 =    1
LC_BARTYPE_CODE128 =   6
LC_BARTYPE_EAN13 =     7
LC_BARTYPE_ITF =       8
LC_BARTYPE_EAN8 =      9
LC_BARTYPE_QR =        21
LC_BARTYPE_MQR =       22
LC_BARTYPE_DMATRIX =   23
LC_BARTYPE_DM =        23
LC_BARTYPE_DMATRIXR =  24
LC_BARTYPE_DMR =       24

#  QR-code Error Correction Level (SetECLevel(), LC_PROP_G_BARC_ECL)


#  Must be same values as BARC_QRECL_... in BaseLibs\Barcode\Barcode.h

LC_BARC_QRECL_L =   0  #  01
LC_BARC_QRECL_M =   1  #  00
LC_BARC_QRECL_Q =   2  #  11
LC_BARC_QRECL_H =   3  #  10

#  Leader text alignment flags

LC_LEADER_TCENTER =     0
LC_LEADER_TLEFT =       1
LC_LEADER_TRIGHT =      2

#  Leader line attachment flags

LC_LEADER_VERT =        1
LC_LEADER_CORNER =      2

#  commands for lcVportLayerCmd

LC_VPL_CLEAR =          1  #  delete all layers override
LC_VPL_ADD =            2  #  add viewport layer override
LC_VPL_DELETE =         3  #  delete viewport layer override
LC_VPL_PROP_BEGIN =     4  #  begin to edit layer properties
LC_VPL_PROP_END =       5  #  end to edit layer properties

#  Radian -> Degree

LC_RAD_TO_DEG =  57.2957795130823208768  #  F

#  Degree -> Radian

LC_DEG_TO_RAD =   0.01745329251994329577  #  F

#  angles in radians

LC_PI =      3.14159265358979323846  #  F
LC_PI2 =     1.57079632679489661923  #  F
LC_PI4 =     0.78539816339744830962  #  F
LC_2PI =     6.28318530717958647692  #  F

#  angles in degrees

LC_DEG1 =    0.01745329251994329577  #  F
LC_DEG2 =    0.03490658503988659154  #  F
LC_DEG3 =    0.05235987755982988731  #  F
LC_DEG4 =    0.06981317007977318308  #  F
LC_DEG5 =    0.08726646259971647885  #  F
LC_DEG6 =    0.10471975511965977462  #  F
LC_DEG7 =    0.12217304763960307038  #  F
LC_DEG8 =    0.13962634015954636615  #  F
LC_DEG9 =    0.15707963267948966192  #  F
LC_DEG10 =   0.17453292519943295769  #  F
LC_DEG20 =   0.34906585039886591538  #  F
LC_DEG30 =   0.52359877559829887308  #  F
LC_DEG40 =   0.69813170079773183077  #  F
LC_DEG45 =   0.78539816339744830962  #  F
LC_DEG50 =   0.87266462599716478846  #  F
LC_DEG60 =   1.04719755119659774615  #  F
LC_DEG70 =   1.22173047639603070385  #  F
LC_DEG80 =   1.39626340159546366154  #  F
LC_DEG90 =   1.57079632679489661923  #  F
LC_DEG180 =  3.14159265358979323846  #  F
LC_DEG270 =  4.71238898038468985769  #  F
LC_DEG360 =  6.28318530717958647692  #  F

#  Drawing's units (LC_PROP_DRW_INSUNITS)

LC_INSUNIT_UNDEFINED =     0    #  Undefined
LC_INSUNIT_INCHES =        1    #  Inches
LC_INSUNIT_FEET =          2    #  Feet
LC_INSUNIT_MILES =         3    #  Miles
LC_INSUNIT_MILLIMETERS =   4    #  Millimeters
LC_INSUNIT_CENTIMETERS =   5    #  Centimeters
LC_INSUNIT_METERS =        6    #  Meters
LC_INSUNIT_KILOMETERS =    7    #  Kilometers
LC_INSUNIT_MICROINCHES =   8    #  Microinches
LC_INSUNIT_MILS =          9    #  Mils
LC_INSUNIT_YARDS =         10   #  Yards
LC_INSUNIT_ANGSTROMS =     11   #  Angstroms
LC_INSUNIT_NANOMETERS =    12   #  Nanometers
LC_INSUNIT_MICRONS =       13   #  Microns
LC_INSUNIT_DECIMETERS =    14   #  Decimeters
LC_INSUNIT_DEKAMETERS =    15   #  Dekameters
LC_INSUNIT_HECTOMETERS =   16   #  Hectometers
LC_INSUNIT_GIGAMETERS =    17   #  Gigameters
LC_INSUNIT_ASTRONOMICAL =  18   #  Astronomical
LC_INSUNIT_LIGHTYEARS =    19   #  Lightyears
LC_INSUNIT_PARSECS =       20   #  Parsecs

#  LC_PROP_DRW_LUNITS

LC_LUNIT_SCIEN =  1  #  Scientific
LC_LUNIT_DECIM =  2  #  Decimal
LC_LUNIT_ENGIN =  3  #  Engineering
LC_LUNIT_ARCHI =  4  #  Architectural
LC_LUNIT_FRACT =  5  #  Fractional

#  Angle units used with GUI and API (LC_PROP_DRW_AUNITS)

LC_AUNIT_DEGREE =  0  #  Decimal degrees
LC_AUNIT_DMS =     1  #  Degrees/minutes/seconds
LC_AUNIT_GRAD =    2  #  Grads
LC_AUNIT_RADIAN =  3  #  Radians
LC_AUNIT_SURVEY =  4  #  Surveyor's units

#  same

LC_ANGLE_DEGREE =  0  #  Decimal degrees
LC_ANGLE_DMS =     1  #  Degrees/minutes/seconds
LC_ANGLE_GRAD =    2  #  Grads
LC_ANGLE_RADIAN =  3  #  Radians
LC_ANGLE_SURVEY =  4  #  Surveyor's units

#  paper size ( lcWndPaperSetSize )

LC_PAPER_CUSTOM =     0
LC_PAPER_USER =       0
LC_PAPER_A0 =         1
LC_PAPER_A1 =         2
LC_PAPER_A2 =         3
LC_PAPER_A3 =         4
LC_PAPER_A4 =         5
LC_PAPER_A5 =         6
LC_PAPER_A6 =         7
LC_PAPER_B0 =         11
LC_PAPER_B1 =         12
LC_PAPER_B2 =         13
LC_PAPER_B3 =         14
LC_PAPER_B4 =         15
LC_PAPER_B5 =         16
LC_PAPER_B6 =         17
LC_PAPER_C0 =         21
LC_PAPER_C1 =         22
LC_PAPER_C2 =         23
LC_PAPER_C3 =         24
LC_PAPER_C4 =         25
LC_PAPER_C5 =         26
LC_PAPER_C6 =         27
LC_PAPER_ANSI_A =     31
LC_PAPER_ANSI_B =     32
LC_PAPER_ANSI_C =     33
LC_PAPER_ANSI_D =     34
LC_PAPER_ANSI_E =     35
LC_PAPER_LETTER =     36
LC_PAPER_LEGAL =      37
LC_PAPER_EXECUTIVE =  38
LC_PAPER_LEDGER =     39
LC_PAPER_UNLIMITED =  100

#  Printer paper orientation

LC_PAPER_PORTRAIT =     0
LC_PAPER_BOOK =         0
LC_PAPER_LANDSCAPE =    1
LC_PAPER_ALBUM =        1

#  options for lcPrintBlock

LC_PRN_SCALELW =        1  #  scale lineweights
LC_PRN_1COLOR =         2  #  force all colors to black

#  text alignment types (LC_PROP_G_TEXT_ALIGN)

LC_TA_LEFBOT =          0   #  Align by left bottom corner
LC_TA_CENBOT =          1   #  Align by center of bottom line
LC_TA_RIGBOT =          2   #  Align by right bottom corner
LC_TA_LEFCEN =          3   #  Align by left side of vertical center line
LC_TA_CENTER =          4   #  Align by center of text
LC_TA_RIGCEN =          5   #  Align by right side of vertical center line
LC_TA_LEFTOP =          6   #  Align by left top corner
LC_TA_CENTOP =          7   #  Align by center of top line
LC_TA_RIGTOP =          8   #  Align by right tom corner
LC_TA_ALIGNED =         11  #  Fit text between 2 points (Adjust Height)
LC_TA_FIT =             12  #  Fit text between 2 points (Adjust Width scale)

#  text flags for LC_TEXTPRM::Generation

LC_TEXT_BACKWARD =      2 
LC_TEXT_UPDOWN =        4

#  text alignment types for arc text

LC_ATA_LEFT =           0   #  Align by left side of text
LC_ATA_CENTER =         1   #  Align by center of text
LC_ATA_RIGHT =          2   #  Align by right side of text

#  text alignment types for barcode text

LC_BTA_LEFT =           0   #  Align by left side of text
LC_BTA_CENTER =         1   #  Align by center of text
LC_BTA_RIGHT =          2   #  Align by right side of text

#  Polyline fit types ( lcPtbufInterpolate )

LC_PLFIT_BULGE =        0      #  linear with bulges
LC_PLFIT_NONE =         0
LC_PLFIT_QUAD =         5      #  Quadratic B-spline
LC_PLFIT_CUBIC =        6      #  Cubic B-spline
LC_PLFIT_BEZIER =       7      #  Bezier spline
LC_PLFIT_SPLINE =       99     #  spline fitted to vertices
LC_PLFIT_ROUND =        101    #  rounded vertices
LC_PLFIT_LINQUAD =      102    #  mixed linear and quadratic segments

#  Point modes ( lcPaint_DrawPoint, lcBlockAddPoint2, LC_PROP_DRW_PDMODE )

LC_POINT_PIXEL =        0     #  Pixel
LC_POINT_NONE =         1     #  None
LC_POINT_PLUS =         2     #  "Plus" sign through the point.
LC_POINT_X =            3     #  "X" through the point
LC_POINT_TICK =         4     #  Vertical tick mark upward from the point.

#  additional elements     

LC_POINT_CIRCLE =       32    #  Circle 
LC_POINT_SQUARE =       64    #  Square
LC_POINT_RHOMB =        128   #  Rhomb
LC_POINT_FILLED =       256   #  Filled shape

#  extra

LC_POINT_BEAM0 =        10000
LC_POINT_BEAM1 =        10001

#  values for parameter 'Mode' of lcBlockSelBlock (LcBlkCreate::m_Mode)

LC_BLK_ENT_RETAIN =    0    #  retain original entities, don't insert the block
LC_BLK_ENT_CONVERT =   1    #  delete selected entities, insert the block
LC_BLK_ENT_DELETE =    2    #  delete selected entities, don't insert the block

#  entity alignment ( lcEntAlign )

LC_EA_LEFT =     1   
LC_EA_TOP =      2   
LC_EA_RIGHT =    3   
LC_EA_BOTTOM =   4
LC_EA_CENTER =   5
LC_EA_CENTERX =  6
LC_EA_CENTERY =  7   

#  alignment of unscalable image

LC_IMGA_CENTER =   0   #  center
LC_IMGA_LEFBOT =   1   #  left-bottom corner
LC_IMGA_RIGBOT =   2   #  right-bottom corner
LC_IMGA_LEFTOP =   3   #  left-top corner
LC_IMGA_RIGTOP =   4   #  right-top corner

#  Mouse buttons

LC_LBUTTON =  1   #  Left button is pressed
LC_RBUTTON =  2   #  right button is pressed
LC_MBUTTON =  4   #  middle button is pressed

#  Key state

LC_SHIFT =  1   #  SHIFT key is pressed
LC_CTRL =   2   #  CTRL key is pressed
LC_ALT =    4   #  ALT key is pressed

#  keyboard type

LC_KBD_QWERTY =  0  #  QWERTY
LC_KBD_AZERTY =  1  #  AZERTY
LC_KBD_QWERTZ =  2  #  QWERTZ

#  LiteCAD window cursor, to use in lcPropPutInt(0, LC_PROP_WND_CURSORARROW, Val)

LC_CURSOR_NULL =    0    #  no cursor
LC_CURSOR_ARROW =   1    #  Standard arrow
LC_CURSOR_CROSS =   2    #  Crosshair
LC_CURSOR_HAND =    3    #  Hand
LC_CURSOR_HELP =    4    #  Arrow and question mark
LC_CURSOR_NO =      5    #  Slashed circle
LC_CURSOR_WAIT =    6    #  Hourglass
LC_CURSOR_PAN1 =    7    #  Pan start cursor
LC_CURSOR_PAN2 =    8    #  Pan move cursor

#  flags for lcExpEntity

LC_EXP_OUTLINE =    1
LC_EXP_HATCH =      2
LC_EXP_ALL =        3
LC_EXP_MAXRESOL =   4

#  values for lcWndEmulator

LC_EMUL_START =     0
LC_EMUL_STOP =      1
LC_EMUL_PARAMS =    2

#  magnifier zoom values

LC_MAG_ZOOM_4 =     0
LC_MAG_ZOOM_6 =     1
LC_MAG_ZOOM_8 =     2
LC_MAG_ZOOM_10 =    3
LC_MAG_ZOOM_12 =    4
LC_MAG_ZOOM_14 =    5

#  magnifier flags

LC_MAG_CENTER =     1  #  draw center cross

#  Mode for lcDrwExplode

LC_DRWEXP_L =     0   #  explode to lines
LC_DRWEXP_P =     1   #  explode to polylines
LC_DRWEXP_LA =   10   #  explode to lines, arcs and circles
LC_DRWEXP_PA =   11   #  explode to polylies, arcs and circles

#  ID of help file topic

LC_HELP_DG_PRINT =        1
LC_HELP_DG_RASTER =       2
LC_HELP_DG_COLOR =        10
LC_HELP_DG_LAYERS =       11
LC_HELP_DG_SELLTYPE =     12
LC_HELP_DG_LINETYPES =    13
LC_HELP_DG_LOADLINETYPE = 14 
LC_HELP_DG_TEXTSTYLES =   15
LC_HELP_DG_PNTSTYLES =    16
LC_HELP_DG_DIMSTYLES =    17
LC_HELP_DG_MLSTYLES =     18
LC_HELP_DG_HATSTYLES =    19
LC_HELP_DG_BLOCKS =       20
LC_HELP_DG_LAYOUTS =      21
LC_HELP_DG_IMAGES =       22
LC_HELP_DG_IMAGEINSERT =  23
LC_HELP_DG_SELBLOCK =     30
LC_HELP_DG_SELTSTYLE =    31
LC_HELP_DG_SELPTYPE =     32
LC_HELP_DG_CREBLOCK =     33 
LC_HELP_DG_PAGEPROP =     34
LC_HELP_DG_SELFONT =      35
LC_HELP_DG_TEXT =         40
LC_HELP_DG_ARCTEXT =      41
LC_HELP_DG_INPUTCOORD =   42
LC_HELP_DG_WORKFIELD =    43
LC_HELP_DG_CRBITMAP =     44
LC_HELP_DG_INSERT =       45
LC_HELP_DG_TSP =          51
LC_HELP_DG_ARRAY =        52
LC_HELP_DG_ARRAYARC =     53
LC_HELP_DG_HATCH =        54
LC_HELP_DG_GRID =         61
LC_HELP_DG_PTRACK =       62
LC_HELP_DG_OSNAP =        63
LC_HELP_DG_KBMOVE =       64
LC_HELP_DG_DRWPROPS =     65
LC_HELP_DG_SYSPROPS =     66
LC_HELP_DG_SELECTION =    67
LC_HELP_DG_QSELECT =      68
LC_HELP_DG_RPOLYGON =     69
LC_HELP_DG_LIMITS =       70
LC_HELP_DG_NDLSET =       71
LC_HELP_DG_LMESH =        72
LC_HELP_DG_CRECTS =       73
LC_HELP_DG_SELLINFILL =   74

#  values for lcWndMessage uType parameter

LC_MB_OK =                0     # 0x0000L The message box contains one push button: OK. This is the default.
LC_MB_OKCANCEL =          1     # 0x0001L The message box contains two push buttons: OK and Cancel.
LC_MB_ABORTRETRYIGNORE =  2     # 0x0002L The message box contains three push buttons: Abort, Retry, and Ignore.
LC_MB_YESNOCANCEL =       3     # 0x0003L The message box contains three push buttons: Yes, No, and Cancel.
LC_MB_YESNO =             4     # 0x0004L The message box contains two push buttons: Yes and No.
LC_MB_RETRYCANCEL =       5     # 0x0005L The message box contains two push buttons: Retry and Cancel.
LC_MB_CANCELTRYCONTINUE = 6     # 0x0006L The message box contains three push buttons: Cancel, Try Again, Continue. Use this message box type instead of MB_ABORTRETRYIGNORE.
LC_MB_HELP =              16384 # 0x4000L Adds a Help button to the message box. When the user clicks the Help button or presses F1, the system sends a WM_HELP message to the owner.
LC_MB_ICONSTOP =          16    # 0x0010L A stop-sign icon appears in the message box.
LC_MB_ICONERROR =         16    # 0x0010L A stop-sign icon appears in the message box.
LC_MB_ICONHAND =          16    # 0x0010L A stop-sign icon appears in the message box.
LC_MB_ICONQUESTION =      32    # 0x0020L A question-mark icon appears in the message box. 
LC_MB_ICONEXCLAMATION =   48    # 0x0030L An exclamation-point icon appears in the message box.
LC_MB_ICONWARNING =       48    # 0x0030L An exclamation-point icon appears in the message box.
LC_MB_ICONINFORMATION =   64    # 0x0040L An icon consisting of a lowercase letter i in a circle appears in the message box.
LC_MB_ICONASTERISK =      64    # 0x0040L An icon consisting of a lowercase letter i in a circle appears in the message box.
LC_UNDO_BEGIN =  0   #  begin record
LC_UNDO_END =    1   #  end record
LC_UNDO_CLEAR =  2   #  clear undo buffer

#  Error codes

LC_ERR_OBJTYPE =        1    #  wrong type of object
LC_ERR_NOTAG =          2    #  string tag is not found
LC_ERR_USERCANCEL =     3    #  user have clicked "Cancel" button
LC_ERR_FILENAME =       4    #  wrong filename
LC_ERR_FILELOAD =       5    #  can't load a file
LC_ERR_FILESAVE =       6    #  can't save a file
LC_ERR_UNRESBLOCKREF =  7    #  unresolved block reference
LC_ERR_UNRESVIEWREF =   8    #  unresolved view reference
LC_ERR_UNRESHATCH =     9    #  unresolved hatch 
LC_ERR_FILE_TIN_SAVE =  101  #  can not write external TIN file

#  Non-graphical objects (Named)

LC_OBJ_LAYER =       1    #  Layer
LC_OBJ_LINETYPE =    2    #  Linetype
LC_OBJ_TEXTSTYLE =   3    #  Text style
LC_OBJ_DIMSTYLE =    4    #  Dimension style
LC_OBJ_PNTSTYLE =    5    #  Point style
LC_OBJ_IMAGE =       6    #  Image
LC_OBJ_MLSTYLE =     8    #  Multiline style
LC_OBJ_LINFILL =     9    #  Filling by lines
LC_OBJ_BLOCK =       10   #  Block
LC_OBJ_LAYOUT =      11   #  Layout block (Model or Paper space)

#  Graphic objects

LC_ENT_LINE =        101  #  Line
LC_ENT_POLYLINE =    102  #  Polyline
LC_ENT_CIRCLE =      103  #  Circle
LC_ENT_ARC =         104  #  Arc
LC_ENT_BLOCKREF =    105  #  Block Reference
LC_ENT_POINT =       107  #  Point
LC_ENT_XLINE =       108  #  Construction line or ray
LC_ENT_ELLIPSE =     109  #  Ellipse or elliptical arc
LC_ENT_TEXT =        110  #  Text
LC_ENT_TEXTWIN =     111  #  Text by GDI TextOut
LC_ENT_IMAGEREF =    115  #  Image Reference
LC_ENT_VIEWPORT =    116  #  Viewport
LC_ENT_CLIPRECT =    117  #  Clipping rectangle
LC_ENT_RECT =        118  #  Rectangle
LC_ENT_ATTDEF =      120  #  Attribute definition
LC_ENT_ECW =         121  #  ECW image
LC_ENT_MTEXT =       122  #  Multiline Text
LC_ENT_ARCTEXT =     123  #  Arc Text
LC_ENT_HATCH =       124  #  Hatch
LC_ENT_FACE =        126  #  3D Face
LC_ENT_MLINE =       127  #  multiline polyline
LC_ENT_DIMROT =      131  #  Dimension Linear 
LC_ENT_DIMLIN =      131  #  Dimension Linear
LC_ENT_DIMALI =      132  #  Dimension Aligned
LC_ENT_DIMORD =      133  #  Dimension Ordinate
LC_ENT_DIMRAD =      134  #  Dimension Radial
LC_ENT_DIMDIA =      135  #  Dimension Diametric
LC_ENT_DIMANG =      136  #  Dimension Angular
LC_ENT_LEADER =      137  #  Leader
LC_ENT_RPLAN =       141  #  Road plan
LC_ENT_TIN =         142  #  Triangulated Irregular Network
LC_ENT_BARCODE =     150  #  Barcode
LC_ENT_SHAPE =       160  #  Shape
LC_ENT_BRI =         161  #  Big Raster Image
LC_ENT_XREF =        199  #  External Reference
LC_ENT_ARROW =       301  #  Arrow
LC_ENT_SPIRAL =      302  #  Spiral
LC_ENT_CAMERA =      303  #  Camera
LC_ENT_PTARRAY =     304  #  points array      
LC_ENT_PATHTEXT =    305  #  Path Text
LC_ENT_BEZIER =      306  #  Bezier spline
LC_ENT_CUSTOM =      1000
LC_ENT_ALL =         32767   #  used for bulk properties

#  Lineweights

LC_LWEIGHT_DEFAULT =  -3     #  Default lineweight. Width is controlled by LC_PROP_DRW_LWDEFAULT property.
LC_LWEIGHT_BYBLOCK =  -2     #  Only for entities contained in block. Universal lineweight specified within a BlockRef entity.
LC_LWEIGHT_BYLAYER =  -1     #  Only for entities. Universal lineweight specified in the entity's layer.
LC_LWIDTH_DEFAULT =   -3     
LC_LWIDTH_BYBLOCK =   -2     
LC_LWIDTH_BYLAYER =   -1     

#  variants for LC_PROP_G_COLOR property

LC_COLOR_RGB =        0  #  RGB value (COLORREF)
LC_COLOR_INDEX =      1  #  AutoCAD Color Index (ACI)

#  defined ACI Colors

LC_COLOR_RED =          1  #  Red
LC_COLOR_YELLOW =       2  #  Yellow
LC_COLOR_GREEN =        3  #  Green
LC_COLOR_CYAN =         4  #  Cyan
LC_COLOR_BLUE =         5  #  Blue
LC_COLOR_MAGENTA =      6  #  Magenta
LC_COLOR_FOREGROUND =   7  #  Foreground (contrast to background color)
LC_COLOR_GRAY =         8  #  Gray
LC_COLOR_LTGRAY =       9  #  Light gray

#  logical colors for entities

LC_COLOR_BYBLOCK =      0     #  entity's color by block
LC_COLOR_BYLAYER =      256   #  entity's color by layer
LC_COLOR_WIPEOUT =      259   #  used for wipeout object

#  options for LC_PROP_DRW_SELPENMODE


#  #define LC_SELPEN_COLOR  0  // dotted pen, color by m_SelPenColor and m_SelPenColorBk


#  #define LC_SELPEN_BYENT  1  // dottet pen, color by entity


#  Multiline justification 0 = Top; 1 = Middle; 2 = Bottom

LC_MLINE_TOP =          0
LC_MLINE_MIDDLE =       1
LC_MLINE_BOTTOM =       2
LC_TABLE_IDSET =     349000349

#  Plugin Interface Types


#  Do not change this values, because it must be the same in plugin DLLs

LC_PLUG_IMPDRW =        2   #  load a drawing from a file into LiteCAD database (in memory)
LC_PLUG_EXPDRW =        3   #  save a drawing from LiteCAD database into a file
LC_PLUG_IMGDIB =        4   #  load an image from a file into LiteCAD DIB

#  values for the F_FIOPROGRESS Mode

LC_FP_FLOAD =           0   #  szFileName - a file is being loaded
LC_FP_FSAVE =           1   #  szFileName - a file is being saved
LC_FP_NITEMS =          2   #  IntVal - number of items
LC_FP_ITEM =            3   #  increment item
LC_FP_ITEMPOS =         4   #  set item position

#  Snap modes ( LC_PROP_WND_OSNAP )

LC_OSNAP_NULL =          0      # 0x00000 no snap at all
LC_OSNAP_NODE =          1      # 0x00001 to a Point object, dimension definition point, or dimension text origin.
LC_OSNAP_ENDPOINT =      2      # 0x00002 to the closest endpoint of an Arc, Elliptical Arc, Line, Multiline, Polyline segment, Ray
LC_OSNAP_MIDPOINT =      4      # 0x00004 to the midpoint of an arc, ellipse, elliptical arc, line, multiline, polyline segment, region, solid, spline, or xline.
LC_OSNAP_CENTER =        8      # 0x00008 to the center of an arc, circle, ellipse, or elliptical arc.
LC_OSNAP_NEAREST =       16     # 0x00010 to the nearest point on an arc, circle, ellipse, elliptical arc, line, multiline, point, polyline, ray, spline, or xline.
LC_OSNAP_INTER =         32     # 0x00020 to the intersection of an arc, circle, ellipse, elliptical arc, line, multiline, polyline, ray, region, spline, or xline.
LC_OSNAP_PERPEND =       64     # 0x00040 to a point perpendicular to an arc, circle, ellipse, elliptical arc, line, multiline, polyline, ray, region, solid, spline, or xline
LC_OSNAP_TANGENT =       128    # 0x00080 to the tangent of an arc, circle, ellipse, elliptical arc, or spline.
LC_OSNAP_QUADRANT =      256    # 0x00100 to a quadrant point of an arc, circle, ellipse, or elliptical arc.
LC_OSNAP_INSERT =        512    # 0x00200 to the insertion point of an attribute, a block, a shape, or text.
LC_OSNAP_NONE =          1024   # 0x00400 temporary disable object snap
LC_OSNAP_ALL =           1023   # 0x003FF all modes

#  Attribute flags

LC_ATTRIB_HIDDEN =      1
LC_ATTRIB_CONST =       2
LC_ATTRIB_VERIFY =      4
LC_ATTRIB_PRESET =      8
LC_ATTRIB_LOCK =        16
LC_ATTRIB_MTEXT =       32

#  3D Face flags (must be the same as in "..\odt\ad2.h"

LC_FACE_EDGE1INVIS =     1
LC_FACE_EDGE2INVIS =     2
LC_FACE_EDGE3INVIS =     4
LC_FACE_EDGE4INVIS =     8
LC_FACE_EDGE1HIDDEN =    1
LC_FACE_EDGE2HIDDEN =    2
LC_FACE_EDGE3HIDDEN =    4
LC_FACE_EDGE4HIDDEN =    8

#  block overwrite mode

LC_BLOCK_OVERWRITENO =   0
LC_BLOCK_OVERWRITEYES =  1
LC_BLOCK_OVERWRITEDLG =  2

#  arrowhead types (for dimensions)         

LC_ARROW_CLOSEDF =      0    #  Closed filled
LC_ARROW_CLOSEDB =      1    #  Closed blank
LC_ARROW_CLOSED =       2    #  Closed
LC_ARROW_DOT =          3    #  Dot
LC_ARROW_ARCHTICK =     4    #  Architectural tick
LC_ARROW_OBLIQUE =      5    #  Oblique
LC_ARROW_OPEN =         6    #  Open
LC_ARROW_ORIGIN =       7    #  Origin indicator
LC_ARROW_ORIGIN2 =      8    #  Origin indicator 2
LC_ARROW_OPEN90 =       9    #  Right angle
LC_ARROW_OPEN30 =       10   #  Open 30
LC_ARROW_DOTSMALL =     11   #  Dot small
LC_ARROW_DOTB =         12   #  Dot blank
LC_ARROW_DOTSMALLB =    13   #  Dot small blank
LC_ARROW_BOX =          14   #  Box
LC_ARROW_BOXF =         15   #  Box filled
LC_ARROW_DATUM =        16   #  Datum triangle
LC_ARROW_DATUMF =       17   #  Datum triangle filled
LC_ARROW_INTEGRAL =     18   #  Integral
LC_ARROW_NONE =         19   #  None

#  Camera color format (TISGrabberGlobalDefs.h)

LC_COFO_NONE =    0
LC_COFO_Y800 =    1
LC_COFO_RGB24 =   2
LC_COFO_RGB32 =   3
LC_COFO_UYVY =    4
LC_COFO_Y16 =     5
LC_COFO_MEGA =    65536  #  Borland C++ 6 compatibility

# -----------------------------------------------


#  LiteCAD commands (for lcWndExeCommand)


# -----------------------------------------------


#  File I/O commands

LC_CMD_FILESAVE =       1    #  Save drawing to file. Call dialog "Save As" if filename is undefined
LC_CMD_FILESAVEAS =     2    #  Call dialog "Save File As"
LC_CMD_PRINT =          3    #  Call dialog "Print"
LC_CMD_RASTERIZE =      4    #  Call dialog "Export to raster image"
LC_CMD_FILENEW =        5
LC_CMD_FILEOPEN =       6
LC_CMD_FILERECENT =     7
LC_CMD_FILEINSERT =     8
LC_CMD_FILECLOSE =      9    #  close file of current file tab

#  Display a drawing in design window

LC_CMD_VIEW__MIN =      31  # ------- 1-step view commands until LC_CMD_VIEWEND
LC_CMD_ZOOM_IN =        31  #  Enlarge drawing's view
LC_CMD_ZOOM_OUT =       32  #  Diminish drawing's view
LC_CMD_ZOOM_EXT =       33  #  Zoom on drawing's extents
LC_CMD_ZOOM_PAGE =      34  #  Zoom on paper sheet (only for "Paper Space" view)
LC_CMD_ZOOM_PREV =      35  #  Display the previous view
LC_CMD_ZOOM_LIM =       36  #  Zoom on limits rect
LC_CMD_PAN_LEFT =       37  #  Shift drawing to the left
LC_CMD_PAN_RIGHT =      38  #  Shift drawing to the right
LC_CMD_PAN_UP =         39  #  Shift drawing upward
LC_CMD_PAN_DOWN =       40  #  Shift drawing downward
LC_CMD_VIEW__MAX =      40  # ------------------------------------------
LC_CMD_ZOOM_WIN =       51  #  Zoom drawing using the Zoom rectangle (Zoom Box)
LC_CMD_ZOOM_RECT =      51  #  same as LC_CMD_ZOOM_WIN
LC_CMD_ZOOM_SEL =       52  #  Zoom on selected entities
LC_CMD_PAGENEXT =       53  #  Display next layout
LC_CMD_PAGEPREV =       54  #  Display previous layout
LC_CMD_PAGEMODEL =      55  #  Display "Model Space" layout
LC_CMD_PAGEVPORT =      56  #  Display layout of active viewport (called by popup menu on AVP)
LC_CMD_VP_ACT =         57  #  activate viewport
LC_CMD_VP_DEACT =       58  #  deactivate viewport
LC_CMD_EDITMODE_ON =    59  #  
LC_CMD_EDITMODE_OFF =   60  #  
LC_CMD_MAG__MIN =       71  # ------------------------------------------
LC_CMD_MAGON =          71  #  magnifier ON
LC_CMD_MAGOFF =         72  #  magnifier OFF
LC_CMD_MAGPRM =         73  #  magnifier parameters  
LC_CMD_MAGZOOM4 =       74  # 
LC_CMD_MAGZOOM6 =       75  # 
LC_CMD_MAGZOOM8 =       76  # 
LC_CMD_MAGZOOM10 =      77  # 
LC_CMD_MAGZOOM12 =      78  # 
LC_CMD_MAGZOOM14 =      79  # 
LC_CMD_MAG__MAX =       79  # ------------------------------------------

#  Miscellaneous 

LC_CMD_GRID =           101  #  Call dialog "Coordinate Grid"
LC_CMD_OSNAP =          102  #  Call dialog "Object Snap"
LC_CMD_PTRACK =         103  #  Call dialog "Polar Tracking"
LC_CMD_SELOPTS =        104  #  Call dialog "Selection Options"
LC_CMD_QSELECT =        105
LC_CMD_KBMOVE =         106   #  move entities by keyboard
LC_CMD_DIST =           111
LC_CMD_AREA =           112
LC_CMD_SCALEBLK =       113

# ^ #define LC_CMD_JUMPLINES      115

LC_CMD_TSP2 =           116
LC_CMD_LIMITS =         117   #  Call dialog "Limits"
LC_CMD_SAVESTR =        118   #  save original strings into LNG file
LC_CMD_DELDUPVER =      119   #  delete duplicate vertices
LC_CMD_DELEXVER =       120   #  delete extra vertices (Coarse polyline)

#  #define LC_CMD_BPLACE         135   // block place attributes for a point

LC_CMD_UNHIDE =         136   #  unhide hidden entities
LC_CMD_PLUGINS =        141   #  call dialog "Plugins"
LC_CMD_CENTERCURSOR =   142   #  set cursor at window center
LC_CMD_HELP =           1001  #  Display Context Help
LC_CMD_RESET =          1003  #  Cancel currently active command, de-select all entities, redraw drawing
LC_CMD_SW_GRID =        1011  #  Toggles "Show coordinate grid" mode
LC_CMD_SW_GRIDSNAP =    1012  #  Toggles "Snap to coordinate grid" mode
LC_CMD_SW_OSNAP =       1014  #  Toggles "Object Snap" mode
LC_CMD_SW_PTRACK =      1015  #  Toggles "Polar tracking" mode
LC_CMD_SW_POLAR =       1015  #  same as LC_CMD_SW_PTRACK
LC_CMD_SW_ORTHO =       1016  #  Toggles "Ortho" mode

#  Add entities

LC_CMD_POINT =          201   #  Draw Point
LC_CMD_LINE =           202   #  Draw Line
LC_LINE_SERIAL =        1     #    serial lines
LC_LINE_SEPARATE =      2     #    separate lines
LC_LINE_CONT =          3     #    continue
LC_CMD_XLINE =          203   #  Draw Construction Line
LC_XLINE_BASE =         1     #    basepoint
LC_XLINE_ANG =          2     #    angular lines (preset by LC_PROP_WND_XLINEANG)
LC_XLINE_SEP =          3     #    separate 2-point lines
LC_XLINE_RAY =          4     #    select ray
LC_XLINE_XLINE =        5     #    select xline
LC_CMD_LMESH =          204   #  Draw mesh 
LC_CMD_POLYLINE =       205   #  Draw Polyline
LC_CMD_PLINE =          205   #    same as LC_CMD_POLYLINE
LC_CMD_SPLINE =         206   #  Draw Spline (polyline with FitType=LC_PLFIT_SPLINE)
LC_CMD_RPOLYGON =       207   #  Draw regular polygon
LC_CMD_RECT =           208   #  Draw Rectangle
LC_RECT_2P =            1     #    2 points
LC_RECT_3P =            2     #    3 points
LC_RECT_CSA =           3     #    Center, Size, Angle
LC_CMD_CIRCLE =         209   #  Draw Circle
LC_CIRCLE_CR =          1     #    Center, Radius
LC_CIRCLE_2P =          2     #    2 points
LC_CIRCLE_3P =          3     #    3 points
LC_CMD_ARC =            210   #  Draw Arc
LC_ARC_SME =            1     #    Start, Middle, End
LC_ARC_SEM =            2     #    Start, End, Middle
LC_ARC_SEC =            3     #    Start, End, Center
LC_ARC_SED =            4     #    Start, End, Direction
LC_ARC_CSE =            5     #    Center, Start, End
LC_ARC_CONT =           6     #    Continue
LC_CMD_ELLIPSE =        211   #  Draw Ellipse
LC_ELL_AX =             1     #    Axis, End
LC_ELL_CEN =            2     #    Center
LC_ELL_RECT =           3     #    By Rectangle
LC_CMD_TEXT =           212   #  Draw Text
LC_CMD_TEXTW =          213   #  Draw WinText
LC_CMD_ATEXT =          214   #  Draw Arc Text
LC_CMD_ARCTEXT =        214   #  Draw Arc Text (same as LC_CMD_ATEXT)
LC_CMD_MTEXT =          215   #  Draw Multiline Text
LC_CMD_INSERT =         216   #  Insert a block
LC_CMD_BLOCKREF =       216   #  Insert a block (same as LC_CMD_INSERT)
LC_INSERT_DLG =         1 
LC_INSERT_NODLG =       2
LC_INSERT_RESET =       3
LC_CMD_BARCODE =        217   #  Draw Barcode
LC_BARCODE_39 =         1
LC_BARCODE_93 =         2   
LC_BARCODE_128 =        3   
LC_BARCODE_EAN13 =      4   
LC_BARCODE_EAN8 =       5   
LC_BARCODE_ITF =        6   
LC_BARCODE_MQR =        7   
LC_BARCODE_QR =         8   
LC_BARCODE_DMATRIX =    9   
LC_BARCODE_DM =         9   
LC_BARCODE_DMATRIXR =   10   
LC_BARCODE_DMR =        10   
LC_CMD_DIMLIN =         221   #  Draw dimension linear
LC_CMD_DIMROT =         221   #  same as LC_CMD_DIMLIN
LC_CMD_DIMALI =         223   #  Draw dimension aligned
LC_CMD_DIMORD =         224   #  Draw dimension ordinate
LC_CMD_DIMRAD =         225   #  Draw dimension radius
LC_CMD_DIMDIA =         226   #  Draw dimension diameter
LC_CMD_DIMANG =         227   #  Draw dimension angular
LC_CMD_LEADER =         228   #  Draw leader
LC_CMD_ARROW =          231   #  Draw arrow
LC_CMD_SPIRAL =         232   #  Draw spiral
LC_CMD_HATCH =          233   #  Draw Hatch
LC_CMD_ECW =            234   #  Insert ECW image
LC_CMD_VPORT =          236   #  Draw viewport
LC_CMD_VIEWPORT =       236   #  Draw viewport (same as LC_CMD_VPORT)
LC_CMD_PTARRAY =        237   #  Insert points array
LC_CMD_FACE =           238   #  Draw 3d face
LC_CMD_SHAPE =          239   #  Create Shape from selected entities
LC_CMD_SKETCH =         240   #  Draw polylines as a sketch
LC_CMD_CLOUD =          241   #  Draw polylines as cloud sketch
LC_CMD_RPLAN =          242   #  Draw RPLAN
LC_CMD_MLINE =          243   #  Draw multiline
LC_CMD_BEZIER =         244   #  Draw bezier spline
LC_CMD_BRI =            245   #  Insert BRI image
LC_CMD_CLIPRECTS =      250
LC_CMD_CRECTS =         250
LC_CMD_ATTDEF =         251   #  attribute definition
LC_CMD_TIN_LOAD =       301   #  Add new TIN entity by loading TIN model from a file
LC_CMD_TIN_LOADPT =     302   #  Add new TIN entity by loading TIN points from a file
LC_CMD_TIN_ADDPT =      303   #  Add new TIN entity by adding points on-screen
LC_CMD_TIN_DELETE =     304   #  delete active TIN (see also lcBlockDeleteEnt )
LC_CMD_TIN_PROPS =      305   #  TIN: dialog "Properties"
LC_CMD_TIN_PTYPES =     306   #  dialog "TIN Point types"
LC_CMD_TIN_MOVEPT =     307   #  TIN: move points
LC_CMD_TIN_EDITPT =     308   #  TIN: edit points (dialog)
LC_CMD_TIN_DELPT =      309   #  TIN: delete points
LC_CMD_TIN_BNDDELPT =   310   #  TIN: 
LC_CMD_TIN_DELPTDUP =   311   #  TIN: delete duplicate points
LC_CMD_TIN_DELTRALL =   312   #  TIN: delete all triangles
LC_CMD_TIN_DELTR =      313   #  TIN: delete triangles
LC_CMD_TIN_BNDDELTR =   314   #  TIN: 
LC_CMD_TIN_SWAPTR =     315   #  TIN: swap triangles
LC_CMD_TIN_BNDAUTO =    316   #  TIN: autodefine boundary
LC_CMD_TIN_BND =        317   #  TIN: define boundary by hands
LC_CMD_TIN_BNDEDIT =    318   #  TIN: edit boundary
LC_CMD_TIN_BNDCLEAR =   319   #  TIN: 
LC_CMD_TIN_BNDTRANG =   320   #  TIN: 
LC_CMD_TIN_BNDTRANG2 =  321   #  TIN: triangulate by step
LC_CMD_TIN_GENISO =     322   #  TIN: dialog "Generate TIN isolines"
LC_CMD_TIN_GENFILL =    323   #  TIN: dialog "Generate TIN filling"
LC_CMD_TIN_RELOAD =     324   #  TIN
LC_CMD_TIN_SAVE =       325   #  TIN: File save
LC_CMD_TIN_SAVEPT =     326   #  TIN: File save points
LC_CMD_TIN_BNDSAVE =    327   #  TIN: 
LC_CMD_TIN_Z =          328   #  TIN: display TIN Z-coord near cursor
LC_CMD_TIN_ZOOM =       329   #  TIN: zoom extents
LC_CMD_TIN_ISOTODRW =   330   #  TIN: copy isolines into drawing
LC_CMD_TIN_TILES =      331   #  TIN: draw TIN tiles

#  Edit operations

LC_CMD_CBCUT =          401  #  Cut entities to clipboard
LC_CMD_CBCOPY =         402  #  Copy entities to clipboard
LC_CMD_CBPASTE =        403  #  Paste entities from clipboard
LC_CMD_UNDO =           404  #  Undo last change
LC_CMD_REDO =           405  #  Reverse last "undo"
LC_CMD_UNDOCLEAR =      406  #  Clear Undo buffer
LC_CMD_COPY =           410  #  Copy entities
LC_COPY_MOVE =          1
LC_COPY_ROTATE =        2
LC_COPY_SCALE =         3
LC_COPY_MIRROR =        4
LC_COPY_ARRRECT =       5
LC_COPY_ARRCIRC =       6
LC_CMD_ERASE =          411  #  Erase entities
LC_CMD_MOVE =           412  #  Move entities
LC_CMD_ROTATE =         413  #  Rotate entities
LC_CMD_SCALE =          414  #  Scale entities
LC_CMD_MIRROR =         415  #  Mirror entities
LC_CMD_EXPLODE =        416  #  Explode entities
LC_CMD_SPLIT =          417  #  Split entities
LC_CMD_JOIN =           418  #  Join entities
LC_CMD_DEP =            419  #  delete extra points   // undoc
LC_CMD_ORDER =          420  #  change draw order
LC_ORDER_FRONT =        1 
LC_ORDER_BACK =         2 
LC_ORDER_ABOVE =        3 
LC_ORDER_UNDER =        4 
LC_ORDER_SWAP =         5
LC_CMD_ORDER_SEQ =      430  #  Sequential order 
LC_CMD_ALIGN =          431  #  align entities
LC_ALIGN_LEFT =         1
LC_ALIGN_RIGHT =        2
LC_ALIGN_TOP =          3
LC_ALIGN_BOTTOM =       4
LC_ALIGN_CENTER =       5
LC_ALIGN_CENX =         6
LC_ALIGN_CENY =         7
LC_CMD_CLOSEBLOCK =     439  #  Close Block Editor
LC_CMD_BASEPOINT =      440  #  set block's basepoint 
LC_CMD_TRIM =           441  #  Trim
LC_CMD_EXTEND =         442  #  Extend
LC_CMD_OFFSET =         443  #  Offset
LC_CMD_OFFSET_POINT =   0 
LC_CMD_OFFSET_DIST =    1
LC_CMD_BREAK =          444  #  Break
LC_CMD_STRETCH =        445  #  Stretch
LC_CMD_FILLET =         446  #  make fillet for 2 lines
LC_CMD_IMGRES =         451  #  Change Image Resolution
LC_CMD_IMGPOS =         452  #  Set Image Position
LC_CMD_XHL =            461  #  make shape from hatch by lines
LC_CMD_XHP =            462  #  make shape from hatch by polylines
LC_CMD_JOINALL =        465  #  Join all connected entities into polylines
LC_CMD_ENTEXT =         468  #  draw entities extents on/off
LC_CMD_JUMPS =          469  #  draw jump lines on/off
LC_CMD_UNSIMG =         470  #  toggle flag "Unscalable" for selected raster images
LC_CMD_UPDATE =         474  #  update all entities or selected, in ViewBlock
LC_CMD_DELOVER =        475  #  delete overlapped lines
LC_CMD_CMPD =           476  #  compare with other drawing

#  Format 

LC_CMD_LAYER =          501  #  Call dialog "Layers"
LC_CMD_LAYERORD =       502  #  Call dialog "Layers order"
LC_CMD_COLOR =          503  #  Call dialog "Color", CmdPrm: LC_PROP_DRW_COLOR, LC_PROP_DRW_FCOLOR, LC_PROP_ENT_COLOR, LC_PROP_ENT_FCOLOR
LC_CMD_FCOLOR =         504  #  Call dialog "Filling Color"
LC_CMD_LINETYPE =       505  #  Call dialog "Linetypes"
LC_CMD_TEXTSTYLE =      507  #  Call dialog "Text Styles"
LC_CMD_BLOCK =          508  #  Call dialog "Create Block"
LC_CMD_CREBLOCK =       508  #  same as LC_CMD_BLOCK
LC_CMD_BLOCKS =         509  #  Call dialog "Blocks"
LC_CMD_IMAGE =          510  #  Call dialog "Image Manager"
LC_CMD_PNTSTYLE =       511  #  Call dialog "Point Style"
LC_CMD_DIMSTYLE =       512  #  Call dialog "Dimension Styles"
LC_CMD_MLSTYLE =        513  #  Call dialog "Multiline Styles"
LC_CMD_LINFILL =        515  #  Call dialog "Filling Styles"
LC_CMD_LAYOUT =         516  #  Call dialog "Layouts"
LC_CMD_XREFS =          517  #  Call dialog "Xrefs"
LC_CMD_UNITS =          521  #  Call dialog "Drawing Units"
LC_CMD_DRWPRM =         522  #  Call dialog "Drawing properties"
LC_CMD_SYSPRM =         523  #  Call dialog "System properties"

#  3D

LC_CMD_3DVIEW =         601   #  enable/disable 3D view (Tab). CmdPrm: 0-switch, 1-on, 2-off
LC_CMD_3D =             601   #  same as LC_CMD_3DVIEW (also see LC_PROP_DRW_3DVIEW)
LC_CMD_3D_STDVIEW =     602   #  Set default view
LC_CMD_3D_PARAMS =      603   #  Settings...
LC_CMD_3D_SAVEIMAGE =   604   #  Save Image...
LC_CMD_AKAGRIP =  29999   #  internal use
LC_CMD_CUSTOM =   30000   #  offset for custom commands

# -----------------------------------------------


#   Objects Properties


# -----------------------------------------------


#  Global properties

LC_PROP_G_REGCODE =       1    #   W string; registration code
LC_PROP_G_VERSION =       2    #  R  string; Litecad version
LC_PROP_G_MSGTITLE =      3    #  RW string; title for messages (default "LiteCAD")
LC_PROP_G_APPFILENAME =   4    #   W string; application filename
LC_PROP_G_DWGAPP =        5    #   W string; DWG application filename
LC_PROP_G_DXFAPP =        6    #   W string; DXF application filename
LC_PROP_G_HELPFILE =      10   #  RW string; name of help file ("Litecad.chm" by default)
LC_PROP_G_DIRDLL =        11   #  R  string; directory of Litecad.dll
LC_PROP_G_DIRFONTS =      13   #  RW string; directory of font files (*.lcf), by default <LC_PROP_G_DIRDLL>\Fonts
LC_PROP_G_DIRLNG =        14   #  RW string; directory of LNG files, by default <LC_PROP_G_DIRDLL>\Languages
LC_PROP_G_DIRTPL =        16   #  RW string; directory of "New File" templates (*.lcd), by default <LC_PROP_G_DIRDLL>\Templates
LC_PROP_G_DIRCFG =        17   #  RW string; directory of config files (the directory must have write permit), by default <LC_PROP_G_DIRDLL>\Config
LC_PROP_G_ICON16 =        20   #  RW string|handle|int; replaces icon for dialogs
LC_PROP_G_ICON32 =        21   #  RW string|handle|int; replaces icon for dialogs
LC_PROP_G_RULERBMP =      22   #  W handle; bitmap for rulers corner
LC_PROP_G_PRNUSEBMP =     25   #  RW bool; use bitmap for printing
LC_PROP_G_PRNBMPFILE =    26   #  RW string; file to save the print bitmap
LC_PROP_G_PRNBTNRAS =     27   #  RW bool; visibility of button "Raster" in the "Print" dialog
LC_PROP_G_PRNBTNSRIF =    28   #  RW bool; visibility of button "Save Raster Image to File" in the "Print/Raster" dialog
LC_PROP_G_PNTPIXSIZE =    29   #  RW bool; meaning of negative PtSize parameter of lcPaint_DrawPoint function, if TRUE - size in pixels, FALSE - % of window height  // undoc
LC_PROP_G_GETDELENT =     30   #  RW bool; controls if lcBlockGetEnt... function will retrieve deleted entities or not
LC_PROP_G_SBARHEIGHT =    32   #  R  int; StatusBar default height
LC_PROP_G_FILEPROGRESS =  33   #  RW bool; Display progress box during file load/save
LC_PROP_G_FILEDEFEXT =    35   #  RW string; default extention on file open dialog
LC_PROP_G_FILELCD =       31   #  RW bool; enable *.lcd file filter
LC_PROP_G_DEMOTEXT =      36   #  RW string; demo text drawn over a window
LC_PROP_G_DEMOSIZE =      37   #  RW int; size of demo text (pixels)
LC_PROP_G_DEMOCOLOR =     38   #  RW int; RGB color of demo text
LC_PROP_G_TABCMDWND =     39   #  RW bool; command window on <Tab> key
LC_PROP_G_UNDOMSG =       40   #  RW bool; display a message when Undo/Redo buffer is empty
LC_PROP_G_MINCHARSIZE =   41   #  RW int; 3..15 below this value a char will be drawn as a rectangle
LC_PROP_G_PANREDQUAL =    42   #  RW bool; reduce draw quality when panning
LC_PROP_G_ENTEXT =        43   #  RW bool; draw entity's extents rectangle
LC_PROP_G_BLKRELOADMODE = 44   #   W int; resets g_BlkReloadMode
LC_PROP_G_TABFILE =       45   #   W string; the file to be opened in lcCreateWindow with LC_WS_FILETABS style
LC_PROP_G_MSGSAVEAS =     46   #  RW bool; display message "Saved As" in the function _lcDrwSave
LC_PROP_G_JUR =           47   #  RW bool;   // undoc
LC_PROP_G_FILEEXTS =      48   #  RW string; supported file extentions
LC_PROP_G_DLGVAL =        50   #  RW string; dialog value for lcDgGetValue
LC_PROP_G_STR =           51   #  RW string|int; g_PropStr | mode for g_StrList
LC_PROP_G_INT =           52   #  R  int;    g_PropInt
LC_PROP_G_FLOAT =         53   #  R  float;  g_PropFloat
LC_PROP_G_HANDLE =        54   #  R  handle; g_PropHandle
LC_PROP_G_DELKEYERASE =   55   #  RW bool; using <Delete> key for "Erase" command (LC_CMD_ERASE)

#  Selection Options

LC_PROP_SEL_PICKBOXSIZE =   61   #  RW int; Half-size of selecting square, in pixels
LC_PROP_SEL_PICKBYRECT =    62   #  RW bool; Implied windowing for objects selection (AutoCAD PICKAUTO)
LC_PROP_SEL_PICKDRAG =      63   #  RW bool; Selection Rect: Press and Drag (same as AutoCAD PICKDRAG system variable)
LC_PROP_SEL_PICKADD =       64   #  RW bool; Controls whether subsequent selections replace the current selection set or add to 
LC_PROP_SEL_PICKBYLAYER =   65   #  RW bool; Select entities only on active layer
LC_PROP_SEL_PICKINPGON =    66   #  RW bool; Select polygons by click on inner area
LC_PROP_SEL_PICKINPGONF =   67   #  RW bool; -/- Only filled polygons
LC_PROP_SEL_PICKINIMG =     68   #  RW bool; Select images by click on inner area
LC_PROP_SEL_COLORL1 =       69   #  RW int; Line Color of selected entities
LC_PROP_SEL_COLORL2 =       70   #  RW int; Line Bg Color of selected entities
LC_PROP_SEL_COLORF =        71   #  RW int; Fill color of selected entities
LC_PROP_SEL_HATCHFILL =     72   #  RW bool; Draw hatch filling when entity is selected
LC_PROP_SEL_ENABLEGRIPS =   73   #  RW bool; Draw grips on selected entities
LC_PROP_SEL_GRIPSIZE =      74   #  RW int; Size of grip square, in pixels
LC_PROP_SEL_GRIPCOLORF =    75   #  RW int; Grips filling color  (COLORREF)
LC_PROP_SEL_GRIPCOLORB =    76   #  RW int; Grips border color (COLORREF)
LC_PROP_SEL_GRIPENTLIM =    77   #  RW int; Max number of selected entities to display grips
LC_PROP_SEL_GRIPNUM =       78   #  RW bool; Draw grips numbers (for polyline)
LC_PROP_G_CAMERA_COUNT =  90   #  R  int; number of camera devices
LC_PROP_G_CAMERA_I =      91   #  RW int; set camera index
LC_PROP_G_CAMERA_INAME =  92   #  R  string; name of camera by index (LC_PROP_G_CAMERA_I)
LC_PROP_G_CAMERA_CONNECTED =  93   #  R  bool; TRUE if camera is connected

#  for connected camera:

LC_PROP_G_CAMERA_NAME =   94   #  R  string; name of connected camera
LC_PROP_G_CAMERA_TIME =   95   #  RW int; interval between camera shots (msec)
LC_PROP_G_CAMERA_WIDTH =  96   #  R  int; width of camera image (pixels)
LC_PROP_G_CAMERA_HEIGHT = 97   #  R  int; height of camera image (pixels)
LC_PROP_G_CAMERA_BPP =    98   #  R  int; bits per pixel
LC_PROP_G_CAMERA_COFO =   99   #  R  int; color format (LC_COFO_RGB24 and others)
LC_PROP_G_CAMERA_BITS =   100  #  R  handle|int; pointer to image bits
LC_PROP_G_CAMERA_BPROW =  101  #  R  int; bytes per row
LC_PROP_G_PTBUFNEWPTS =   131  #  R  int; number of last added points
LC_PROP_G_PTBUFCLR =      132  #  RW bool; auto clear Ptbuf after draw
LC_PROP_G_MPGONCLR =      133  #  RW bool; auto clear Mpgon after draw
LC_PROP_G_TEXT_ALIGN =    141  #  RW int; LC_TA_LEFBOT, LC_TA_CENBOT, etc
LC_PROP_G_TEXT_H =        142  #  RW float; Text height 
LC_PROP_G_TEXT_WS =       143  #  RW float; Width scale coefficient (0.1 - 10.0)
LC_PROP_G_TEXT_CSPACE =   144  #  RW float; Charspace coefficient (0.0 - 3.0) 
LC_PROP_G_TEXT_ANG =      145  #  RW float; Rotation angle 
LC_PROP_G_TEXT_OBL =      146  #  RW float; Oblique angle 
LC_PROP_G_TEXT_UPDOWN =   147  #  RW bool; Upside-down direction
LC_PROP_G_TEXT_BACK =     148  #  RW bool; Backward direction 
LC_PROP_G_TEXT_FILL =     149  #  RW bool;
LC_PROP_G_TEXT_BORDER =   150  #  RW bool;
LC_PROP_G_BARC_CENTER =   161  #  RW bool; if TRUE - basepoint is a center, FALSE - left bottom corner
LC_PROP_G_BARC_ANGLE =    162  #  RW float; rotation angle around base point
LC_PROP_G_BARC_BELOW =    163  #  RW float; height below baseline (for EAN8, EAN13)
LC_PROP_G_BARC_QZONE =    164  #  RW float; size of quiet space
LC_PROP_G_BARC_CHKSUM =   165  #  RW bool; add checksum digit at the end
LC_PROP_G_BARC_ECL =      166  #  RW int; error correction level (LC_BARC_QRECL_M or other)
LC_PROP_G_BARC_INVERT =   167  #  RW bool; negative filling
LC_PROP_G_BARC_WRATIO =   168  #  RW float; <wide bar> / <narrow bar> (varies from 2.0 to 3.0)
LC_PROP_G_BARC_LINEW =    169  #  RW float; compensation of line width
LC_PROP_G_BEAMCOLOR0D =   191  #  RW int; lcPaint_DrawPoint with PtMode=LC_POINT_BEAM1
LC_PROP_G_BEAMCOLOR1D =   192  #  RW int; 
LC_PROP_G_BEAMCOLOR2D =   193  #  RW int; 
LC_PROP_G_BEAMCOLOR0U =   194  #  RW int; lcPaint_DrawPoint with PtMode=LC_POINT_BEAM0
LC_PROP_G_BEAMCOLOR1U =   195  #  RW int; 
LC_PROP_G_BEAMCOLOR2U =   196  #  RW int; 
LC_PROP_G_NAV_LEFT =      201  #  RW int; Left of Navicator window
LC_PROP_G_NAV_TOP =       202  #  RW int; Top of Navicator window
LC_PROP_G_NAV_WIDTH =     203  #  RW int; Width of Navicator window
LC_PROP_G_NAV_HEIGHT =    204  #  RW int; Height of Navicator window
LC_PROP_G_JL_EALEN =      210  #  RW int; Length of entity's arrow (pixels) 
LC_PROP_G_JL_EAW =        211  #  RW int; Half-width of entity's arrow (pixels) 
LC_PROP_G_JL_JALEN =      212  #  RW int; Length of jump arrow (pixels) 
LC_PROP_G_JL_JAW =        213  #  RW int; Half-width of jump arrow (pixels) 
LC_PROP_G_JL_ACOLOR =     214  #  RW int; Color of jump arrow, RGB value (COLORREF) 
LC_PROP_G_JL_NUMFONT =    215  #  RW string; Numbers font name, 0 means default GUI font
LC_PROP_G_JL_NUMSIZE =    216  #  RW int; Numbers font size, ignored if the font name is empty
LC_PROP_G_JL_NUMCOLOR =   217  #  RW int; Color of numbers, RGB value (COLORREF) 
LC_PROP_G_JL_DRAWJARR =   218  #  RW bool; Draw arrows of jump lines 
LC_PROP_G_JL_DRAWJLINE =  219  #  RW bool; Draw jump lines (between entities)
LC_PROP_G_JL_DRAWEDOT =   220  #  RW bool; Draw dots on entity lines
LC_PROP_G_JL_DRAWEARR =   221  #  RW bool; Draw arrows on entity lines
LC_PROP_G_JL_DRAWENUM =   222  #  RW bool; Draw numbers on entity lines
LC_PROP_G_OSNAP_MARK =       226   #  RW bool; display osnap marker
LC_PROP_G_OSNAP_APER =       227   #  RW bool; display osnap aperture box
LC_PROP_G_OSNAP_MARKSIZE =   228   #  RW int;  half-size of marker indicating snap point, pixels (1-15)
LC_PROP_G_OSNAP_APERSIZE =   229   #  RW int;  half-size of square around cursor, used for snap, pixels (1-15)
LC_PROP_G_OSNAP_MARKCOLOR =  230   #  RW int;  color of osnap marker (COLORREF)

# ^ #define LC_PROP_G_ORDSEQ_AUTO     231   // RW bool;  Auto-sort connected entities (LC_CMD_ORDER_SEQ)

LC_PROP_G_EMUL_OVERDIST =   232   #  RW float; Min. dist to treat near lines as overlapped
LC_PROP_G_EMUL_OVERCOLOR =  233   #  RW int; Color for overlapped parts

#  options of export a drawing to raster image

LC_PROP_G_RAS_FILL =        250   #  RW bool; enable filling 
LC_PROP_G_RAS_COLOR =       251   #  RW bool; enable colors  when save as raster image
LC_PROP_G_RAS_NOPRINT =     252   #  RW bool; enable layer "no print" option

#  options for lcWndWaitPoint function

LC_PROP_G_WPT_TEXTX =      260   #  RW int; text X position relative to cursor
LC_PROP_G_WPT_TEXTY =      261   #  RW int; text Y position relative to cursor
LC_PROP_G_WPT_TEXTA =      262   #  RW int; LC_TA_LEFBOT, LC_TA_CENBOT, etc
LC_PROP_G_TIN_PT0 =  270  #  R  handle; result of lcTIN_TriGetEdge
LC_PROP_G_TIN_PT1 =  271  #  R  handle; result of lcTIN_TriGetEdge
LC_PROP_G_TIN_TR =   272  #  R  handle; result of lcTIN_TriGetEdge

#  Design window

LC_PROP_WND__MIN =            301
LC_PROP_WND_ID =              301    #  RW int; identifier
LC_PROP_WND_WIDTH =           302    #  R  int; Width of drawing's area (pixels)
LC_PROP_WND_HEIGHT =          303    #  R  int; Height of drawing's area (pixels)
LC_PROP_WND_PIXELSIZE =       304    #  RW float; Current scale of the drawing in the window, units per pixel
LC_PROP_WND_PICKBOXSIZE =     305    #  R  float; Half-size of selecting square (drawing's units)
LC_PROP_WND_CURSORX =         306    #  R  int|float; Cursor position X (pixels)|Cursor position X (drawing's units)
LC_PROP_WND_CURX =            306    #     LC_PROP_WND_CURSORX
LC_PROP_WND_CURSORY =         307    #  R  int|float; Cursor position Y (pixels)|Cursor position Y (drawing's units)
LC_PROP_WND_CURY =            307    #  R  LC_PROP_WND_CURSORY
LC_PROP_WND_CURLEF =          308    #  R  float; left side of selecting square, in drawing units
LC_PROP_WND_CURBOT =          309    #  R  float; bottom side of selecting square, in drawing units
LC_PROP_WND_CURRIG =          310    #  R  float; right side of selecting square, in drawing units
LC_PROP_WND_CURTOP =          311    #  R  float; top side of selecting square, in drawing units
LC_PROP_WND_XMIN =            312    #  R  float;
LC_PROP_WND_YMIN =            313    #  R  float;
LC_PROP_WND_XMAX =            314    #  R  float;
LC_PROP_WND_YMAX =            315    #  R  float;
LC_PROP_WND_XCEN =            316    #  R  float;
LC_PROP_WND_YCEN =            317    #  R  float;
LC_PROP_WND_DX =              318    #  R  float;
LC_PROP_WND_DY =              319    #  R  float;
LC_PROP_WND_RULERSENABLE =    320    #  R  bool;   true if window was created with LC_WS_RULERS flag
LC_PROP_WND_RULERS =          321    #  RW bool;
LC_PROP_WND_SELECT =          322    #  RW bool; enable/disable to select objects
LC_PROP_WND_VIEWBLOCK =       323    #  R  handle; Handle to active block
LC_PROP_WND_BLOCK =           323    #   same as LC_PROP_WND_VIEWBLOCK
LC_PROP_WND_DRW =             324    #  R  handle; Handle to active drawing
LC_PROP_WND_HWND =            325    #  R  handle; WinAPI handle (HWND)
LC_PROP_WND_HASFOCUS =        326    #  R  bool; Indication "Has focus"
LC_PROP_WND_HASFILETABS =     327    #  R  bool; window has File Tabs
LC_PROP_WND_NUMFILETABS =     328    #  R  int; number of drawings in the list
LC_PROP_WND_NUMDRW =          328    #  same as LC_PROP_WND_NUMFILETABS

# ^ #define LC_PROP_WND_CRECTS_EDIT     327    // RW bool; "Edit ClipRects" mode


# ^ #define LC_PROP_WND_CRECTS_VISIBLE  328    // RW bool; display cliprects when not active

LC_PROP_WND_JUMPLINES =       329    #  RW bool; display jump lines
LC_PROP_WND_MAGNIFIER =       330    #  RW bool; display magnifier at window rig-bot corner
LC_PROP_WND_NAVIGATOR =       331    #  RW bool; display "Aerial View" window
LC_PROP_WND_COLORBG =         332    #  RW int; background color
LC_PROP_WND_COLORCURSOR =     333    #  RW int; cursor color
LC_PROP_WND_COLORFORE =       334    #  RW int; foreground color
LC_PROP_WND_COLORINFBG =      335    #  RW int; info box background color
LC_PROP_WND_COLORINFBORD =    336    #  RW int; info box border color
LC_PROP_WND_COLORINFTEXT =    337    #  RW int; info box text color
LC_PROP_WND_CURSORSYS =       338    #     same as LC_PROP_WND_CURSORARROW
LC_PROP_WND_CURSORARROW =     338    #  RW bool|int|handle; Enable arrow cursor | set cursor (LC_CURSOR_ARROW or other)
LC_PROP_WND_CURSORCROSS =     339    #  RW bool; Enable crosshair cursor
LC_PROP_WND_CURSORSIZE =      340    #  RW int; Size of crosshair cursor, % of screen, if negative - size in pixels
LC_PROP_WND_CURSORPBOX =      341    #  RW bool; Enable cursor pickbox rect
LC_PROP_WND_COORDS =          342    #  RW bool; display cursor coords at left-bottom corner
LC_PROP_WND_ENT =             343    #  R  handle; picked entity (see lcWndPickEnt function)
LC_PROP_WND_PROPWND =         344    #  R  handle; Handle to properties window

# ^ #define LC_PROP_WND_BREAKPOINTS     347    // RW bool; display breakpoints


# ^ #define LC_PROP_WND_BREAKPTNUMS     348    // RW bool; display numbers of breakpoints

LC_PROP_WND_ALPHABLEND =      350    #  RW bool; enable alpha blend (transparent filling)
LC_PROP_WND_STDBLKFRAME =     351    #  RW bool; draw red frame around the window if standard block is active
LC_PROP_WND_BLKBASEPT =       352    #  RW bool; display block basepoint
LC_PROP_WND_SIZE =            353    #  R  string; window size, pixels (format "%d x %d", PSWidth(), PSHeight() )
LC_PROP_WND_DTIME =           354    #  R  int; redraw time, milliseconds
LC_PROP_WND_DRAWPAPER =       355    #  RW bool; draw paper sheet for "Paper space" blocks
LC_PROP_WND_FROZEN =          356    #  RW bool; "Frozen" mode
LC_PROP_WND_FROZENVIEW =      357    #  RW bool; if true - can't chnage view rect
LC_PROP_WND_COMMAND =         358    #  R  int|handle|bool; Id of active command | handle to active command | TRUE if has active command
LC_PROP_WND_CMD =             358    #  same as LC_PROP_WND_COMMAND
LC_PROP_WND_CMDENT1 =         359    #  RW bool; TRUE - only one entity added by command, FALSE - several entities
LC_PROP_WND_OSNAP =           360    #  RW int|bool; object snap mode  LC_OSNAP_NODE and others | On/Off
LC_PROP_WND_OSNAPMENU =       361    #  RW bool; display "object snap" menu on <shift>+<RBDown> (CBaseWnd::BaseOnRButtonDown)
LC_PROP_WND_ORTHO =           362    #  RW bool; ortho mode
LC_PROP_WND_PTRACK =          363    #  RW bool; polar tracking on/off
LC_PROP_WND_PTRACK_ANGLE =    364    #  RW float; step angle for polar tracking
LC_PROP_WND_PTRACK_ANGREL =   365    #  RW bool; relative / absolute angle
LC_PROP_WND_PTRACK_DIST =     366    #  RW bool|float; use distance step along polar vector | value of dist. step
LC_PROP_WND_BASEPT =          367    #  R  bool; Has Base point   // undoc
LC_PROP_WND_BASEX =           368    #  R  float; Base point position X   // undoc
LC_PROP_WND_BASEY =           369    #  R  float; Base point position Y   // undoc
LC_PROP_WND_GRIDSNAP =        370    #  RW bool; 
LC_PROP_WND_GRIDSHOW =        371    #  RW bool; Display coordinate grid
LC_PROP_WND_GRIDDX =          372    #  RW float; Grid & snap step
LC_PROP_WND_GRIDDY =          373    #  RW float;
LC_PROP_WND_GRIDX0 =          374    #  RW float; Origin point
LC_PROP_WND_GRIDY0 =          375    #  RW float;
LC_PROP_WND_GRIDBOLDX =       376    #  RW int; Bold step X
LC_PROP_WND_GRIDBOLDY =       377    #  RW int; Bold step Y
LC_PROP_WND_GRIDCOLOR =       378    #  RW int; Line color
LC_PROP_WND_GRIDDOTTED =      379    #  RW bool; Line is dotted
LC_PROP_WND_GRIDCOLOR2 =      380    #  RW int; Bold Line color
LC_PROP_WND_GRIDDOTTED2 =     381    #  RW bool; Bold Line is dotted
LC_PROP_WND_RSNAP =           382    #  RW bool; Enable snap to rectangle border
LC_PROP_WND_RSNAPSHOW =       383    #  RW bool; Display snap rectanle
LC_PROP_WND_RSNAPLEF =        384    #  RW float; X left
LC_PROP_WND_RSNAPBOT =        385    #  RW float; Y bottom
LC_PROP_WND_RSNAPRIG =        386    #  RW float; X right
LC_PROP_WND_RSNAPTOP =        387    #  RW float; Y top
LC_PROP_WND_RSNAPW =          388    #  RW float; Width (from X left)
LC_PROP_WND_RSNAPH =          389    #  RW float; Height (from Y bottom)
LC_PROP_WND_RSNAPCOLORM =     390    #  RW int; Rectangle filling color on Model space
LC_PROP_WND_RSNAPCOLORP =     391    #  RW int; Rectangle filling color on Paper space
LC_PROP_WND_PANSTEP =         400    #  RW int; Minimal step, pixels
LC_PROP_WND_PANLW =           401    #  RW bool; optimize line width (draw as 1pix size)
LC_PROP_WND_PANIMAGE =        402    #  RW bool; optimize raster images (draw as hatch)
LC_PROP_WND_PANFILL =         403    #  RW bool; optimize polygon filling (don't fill)
LC_PROP_WND_PANPIXSZ =        404    #  RW bool; reduce resolution (increase pixel size)
LC_PROP_WND_MEASCOLORPNT =    410    #  RW int; COLORREF for points of DIST, AREA tools
LC_PROP_WND_MEASCOLORLINE =   411    #  RW int; COLORREF for lines of DIST, AREA tools
LC_PROP_WND_MEASLINESIZE =    412    #  RW int; line size for DIST, AREA tools
LC_PROP_WND_MEASFONTSIZE =    413    #  RW int; font size
LC_PROP_WND_MEASFILLAREA =    414    #  RW int; fill area polygons with hatch
LC_PROP_WND_KBMOVE_ENABLE =   417    #  RW bool; enable movement by keyboard
LC_PROP_WND_KBMOVE_DIST =     418    #  RW float; distance step
LC_PROP_WND_KBMOVE_ANGLE =    419    #  RW float; angle step
LC_PROP_WND_KBMOVE_SCALE =    420    #  RW float; scale step
LC_PROP_WND_XLINEANG =        424    #  RW float; direction angle for command LC_CMD_XLINE
LC_PROP_WND_BGIMAGE =         425    #  RW string|bool; Background image filename | Display
LC_PROP_WND_LTVIEWMIN =       426    #  RW int; Linetype visibility, min size of pattern, pixels
LC_PROP_WND_LTVIEWMAX =       427    #  RW int; Linetype visibility, max size of pattern, pixels
LC_PROP_WND_FRAME_LEFT =      431    #  R  int; Left position on parent window (pixels)
LC_PROP_WND_FRAME_TOP =       432    #  R  int; Top position on parent window (pixels)
LC_PROP_WND_FRAME_WIDTH =     433    #  R  int; Frame width (pixels)
LC_PROP_WND_FRAME_HEIGHT =    434    #  R  int; Frame height (pixels)

#  User specified data 

LC_PROP_WND_HANDLE0 =         460    #  RW int;   
LC_PROP_WND_HANDLE1 =         461    #  RW int;   
LC_PROP_WND_HANDLE2 =         462    #  RW int;   
LC_PROP_WND_HANDLE3 =         463    #  RW int;   
LC_PROP_WND_HANDLE4 =         464    #  RW int;   
LC_PROP_WND_HANDLE5 =         465    #  RW int;   
LC_PROP_WND_HANDLE6 =         466    #  RW int;   
LC_PROP_WND_HANDLE7 =         467    #  RW int;   
LC_PROP_WND_HANDLE8 =         468    #  RW int;   
LC_PROP_WND_HANDLE9 =         469    #  RW int;   
LC_PROP_WND_INT0 =            470    #  RW int;   
LC_PROP_WND_INT1 =            471    #  RW int;   
LC_PROP_WND_INT2 =            472    #  RW int;   
LC_PROP_WND_INT3 =            473    #  RW int;   
LC_PROP_WND_INT4 =            474    #  RW int;   
LC_PROP_WND_INT5 =            475    #  RW int;   
LC_PROP_WND_INT6 =            476    #  RW int;   
LC_PROP_WND_INT7 =            477    #  RW int;   
LC_PROP_WND_INT8 =            478    #  RW int;   
LC_PROP_WND_INT9 =            479    #  RW int;   
LC_PROP_WND_FLOAT0 =          480    #  RW float; 
LC_PROP_WND_FLOAT1 =          481    #  RW float; 
LC_PROP_WND_FLOAT2 =          482    #  RW float; 
LC_PROP_WND_FLOAT3 =          483    #  RW float; 
LC_PROP_WND_FLOAT4 =          484    #  RW float; 
LC_PROP_WND_FLOAT5 =          485    #  RW float; 
LC_PROP_WND_FLOAT6 =          486    #  RW float; 
LC_PROP_WND_FLOAT7 =          487    #  RW float; 
LC_PROP_WND_FLOAT8 =          488    #  RW float; 
LC_PROP_WND_FLOAT9 =          489    #  RW float; 
LC_PROP_WND_STR0 =            490    #  RW string;
LC_PROP_WND_STR1 =            491    #  RW string;
LC_PROP_WND_STR2 =            492    #  RW string;
LC_PROP_WND_STR3 =            493    #  RW string;
LC_PROP_WND_STR4 =            494    #  RW string;
LC_PROP_WND_STR5 =            495    #  RW string;
LC_PROP_WND_STR6 =            496    #  RW string;
LC_PROP_WND_STR7 =            497    #  RW string;
LC_PROP_WND_STR8 =            498    #  RW string;
LC_PROP_WND_STR9 =            499    #  RW string;
LC_PROP_WND__MAX =            499

#  StatusBar  (see lcCreateStatbar and others)

LC_PROP_SBAR__MIN =           501
LC_PROP_SBAR_H =              501       #  RW int; height (by default 
LC_PROP_SBAR_FONTNAME =       502       #  RW string; font name
LC_PROP_SBAR_FONTSIZE =       503       #  RW int; font size
LC_PROP_SBAR_TEXTY =          504       #  RW int; dist from top of status bar
LC_PROP_SBAR_TEXTCOLOR =      505       #  RW int; text color (COLORREF)
LC_PROP_SBAR_BGCOLOR =        506       #  RW int; background color (COLORREF)
LC_PROP_SBAR_FRAMECOLOR =     507       #  RW int; frame color (COLORREF)
LC_PROP_SBAR__MAX =           519

#  Font

LC_PROP_FONT__MIN =           601  
LC_PROP_FONT_FILENAME =       601    #  R  string;  
LC_PROP_FONT_NAME =           602    #  R  string;  
LC_PROP_FONT_LCF =            603    #  R  bool;
LC_PROP_FONT_HEIGHT =         604    #  R  float;  
LC_PROP_FONT_FILLED =         605    #  R  bool;  
LC_PROP_FONT_TTF =            606    #  R  bool;  
LC_PROP_FONT_NCHARS =         607    #  R  int; number of chars in a font 
LC_PROP_FONT__MAX =           629

#  Multipolygon

LC_PROP_MPGON__MIN =          631    
LC_PROP_MPGON_XMIN =          631    #  R  float; Xmin
LC_PROP_MPGON_YMIN =          632    #  R  float; Ymin
LC_PROP_MPGON_XMAX =          633    #  R  float; Xmax 
LC_PROP_MPGON_YMAX =          634    #  R  float; Ymax
LC_PROP_MPGON_XCEN =          635    #  R  float; X of extents center
LC_PROP_MPGON_YCEN =          636    #  R  float; Y of extents center
LC_PROP_MPGON_W =             637    #  R  float; Width of extents rect
LC_PROP_MPGON_H =             638    #  R  float; Height of extents rect
LC_PROP_MPGON__MAX =          649

#  TIN point type

LC_PROP_TINPTYPE__MIN =    680
LC_PROP_TINPTYPE_NAME =    680  #  RW string; name of point type
LC_PROP_TINPTYPE_DTEXT =   681  #  RW string; draw text
LC_PROP_TINPTYPE_COLOR =   682  #  RW int; color of points
LC_PROP_TINPTYPE__MAX =    699

#  TIN point

LC_PROP_TINPNT__MIN =     701
LC_PROP_TINPNT_TYPE =     701  #  RW handle; point type
LC_PROP_TINPNT_I =        702  #  R  int; index
LC_PROP_TINPNT_X =        703  #  RW float; 
LC_PROP_TINPNT_Y =        704  #  RW float; 
LC_PROP_TINPNT_Z =        705  #  RW float; 
LC_PROP_TINPNT_COLOR =    706  #  R  int; color (from point type)
LC_PROP_TINPNT_NAME =     707  #  R  string; name (from point type)
LC_PROP_TINPNT_ONAME =    708  #  RW string; own name (overrides name of point type)
LC_PROP_TINPNT_DESCR =    709  #  RW string; point description
LC_PROP_TINPNT_IMGFILE =  715  #  RW string
LC_PROP_TINPNT_IMGFILE2 = 716  #  R  string; full filename with path
LC_PROP_TINPNT_ATTR =     720  #  RW string
LC_PROP_TINPNT_ATTR1 =    721  #  RW string
LC_PROP_TINPNT_ATTR2 =    722  #  RW string
LC_PROP_TINPNT_ATTR3 =    723  #  RW string
LC_PROP_TINPNT_ATTR4 =    724  #  RW string
LC_PROP_TINPNT_ATTR5 =    725  #  RW string
LC_PROP_TINPNT_ATTR6 =    726  #  RW string
LC_PROP_TINPNT_ATTR7 =    727  #  RW string
LC_PROP_TINPNT_ATTR8 =    728  #  RW string
LC_PROP_TINPNT_ATTR9 =    729  #  RW string
LC_PROP_TINPNT__MAX =     730

#  TIN triangle

LC_PROP_TINTR__MIN =      731
LC_PROP_TINTR_I =         731  #  R int; index
LC_PROP_TINTR_IPT0 =      732  #  R int; point0 index
LC_PROP_TINTR_IPT1 =      733  #  R int; point1 index
LC_PROP_TINTR_IPT2 =      734  #  R int; point2 index
LC_PROP_TINTR_PT0 =       735  #  R handle; 
LC_PROP_TINTR_PT1 =       736  #  R handle; 
LC_PROP_TINTR_PT2 =       737  #  R handle; 
LC_PROP_TINTR_PT0X =      738  #  R  float; X of point0
LC_PROP_TINTR_PT0Y =      739  #  R  float; Y of point0 
LC_PROP_TINTR_PT0Z =      740  #  R  float; Z of point0 
LC_PROP_TINTR_PT1X =      741  #  R  float; X of point1
LC_PROP_TINTR_PT1Y =      742  #  R  float; Y of point1  
LC_PROP_TINTR_PT1Z =      743  #  R  float; Z of point1  
LC_PROP_TINTR_PT2X =      744  #  R  float; X of point2 
LC_PROP_TINTR_PT2Y =      745  #  R  float; Y of point2  
LC_PROP_TINTR_PT2Z =      746  #  R  float; Z of point2  
LC_PROP_TINTR_XC =        747  #  R  float; X of center point
LC_PROP_TINTR_YC =        748  #  R  float; Y of center point
LC_PROP_TINTR_ZC =        749  #  R  float; Z of center point
LC_PROP_TINTR_NVX =       750  #  R  float; X of normal vector
LC_PROP_TINTR_NVY =       751  #  R  float; Y of normal vector
LC_PROP_TINTR_NVZ =       752  #  R  float; Z of normal vector
LC_PROP_TINTR_NANG =      753  #  R  float; normal vector angle at XY plane
LC_PROP_TINTR_XMIN =      754  #  R  float; extents
LC_PROP_TINTR_YMIN =      755  #  R  float; 
LC_PROP_TINTR_ZMIN =      756  #  R  float; 
LC_PROP_TINTR_XMAX =      757  #  R  float; 
LC_PROP_TINTR_YMAX =      758  #  R  float; 
LC_PROP_TINTR_ZMAX =      759  #  R  float; 
LC_PROP_TINTR_DX =        760  #  R  float; 
LC_PROP_TINTR_DY =        761  #  R  float; 
LC_PROP_TINTR_DZ =        762  #  R  float; 
LC_PROP_TINTR_FLAGS =     763  #  RW int; 0-255 
LC_PROP_TINTR_MARK =      764  #  RW bool; marked triangle
LC_PROP_TINTR_EDGE_PT0 =  771  #  R  handle; result of lcTIN_TriGetEdge
LC_PROP_TINTR_EDGE_PT1 =  772  #  R  handle; result of lcTIN_TriGetEdge
LC_PROP_TINTR_EDGE_TR =   773  #  R  handle; result of lcTIN_TriGetEdge
LC_PROP_TINTR__MAX =      780

#  TIN isoline

LC_PROP_TINISO__MIN =     781
LC_PROP_TINISO_Z =        781  #  R float; Z of isoline
LC_PROP_TINISO_NVERS =    782  #  R int; number of vertices
LC_PROP_TINISO_IVER =     783  #  RW int; index of current vertex
LC_PROP_TINISO_X =        784  #  R float; X of isoline vertex
LC_PROP_TINISO_Y =        785  #  R float; Y of isoline vertex
LC_PROP_TINISO_CLOSED =   786  #  R bool; flag "closed isoline"
LC_PROP_TINISO__MAX =     800

#  also see LC_PROP_TIN_NAME and others


#  Grid (by lcGrid... functions)

LC_PROP_GRID__MIN =        1881
LC_PROP_GRID_XMIN =        1882  #  R  float; Xmin
LC_PROP_GRID_XMAX =        1883  #  R  float; Xmax
LC_PROP_GRID_YMIN =        1884  #  R  float; Ymin
LC_PROP_GRID_YMAX =        1885  #  R  float; Ymax
LC_PROP_GRID_W =           1886  #  R  float; delta X
LC_PROP_GRID_H =           1887  #  R  float; delta Y
LC_PROP_GRID_NCELLX =      1888  #  R  int; number of cells by X
LC_PROP_GRID_NCELLY =      1889  #  R  int; number of cells by Y
LC_PROP_GRID__MAX =        1890  

#  Custom command

LC_PROP_CMD__MIN =         2001
LC_PROP_CMD_ID =           2001  #  R  int; command identifier LC_CMD_CUSTOM+n
LC_PROP_CMD_PARAM =        2002  #  R  int; parameter passed by lcWndExeCommand
LC_PROP_CMD_STEP =         2003  #  RW int; command step
LC_PROP_CMD_LCWND =        2004  #  R  handle; design window
LC_PROP_CMD_HWND =         2005  #  R  handle; HWND window handle 
LC_PROP_CMD_DRW =          2006  #  R  handle; drawing 
LC_PROP_CMD_BLOCK =        2007  #  R  handle; block 
LC_PROP_CMD_CURSORCROSS =  2008  #  RW bool; Enable crosshair cursor
LC_PROP_CMD_INT0 =         2010  #  RW int; user value
LC_PROP_CMD_INT1 =         2011  #  RW int; user value
LC_PROP_CMD_INT2 =         2012  #  RW int; user value
LC_PROP_CMD_INT3 =         2013  #  RW int; user value
LC_PROP_CMD_INT4 =         2014  #  RW int; user value
LC_PROP_CMD_INT5 =         2015  #  RW int; user value
LC_PROP_CMD_INT6 =         2016  #  RW int; user value
LC_PROP_CMD_INT7 =         2017  #  RW int; user value
LC_PROP_CMD_INT8 =         2018  #  RW int; user value
LC_PROP_CMD_INT9 =         2019  #  RW int; user value
LC_PROP_CMD_FLOAT0 =       2020  #  RW float; user value
LC_PROP_CMD_FLOAT1 =       2021  #  RW float; user value
LC_PROP_CMD_FLOAT2 =       2022  #  RW float; user value
LC_PROP_CMD_FLOAT3 =       2023  #  RW float; user value
LC_PROP_CMD_FLOAT4 =       2024  #  RW float; user value
LC_PROP_CMD_FLOAT5 =       2025  #  RW float; user value
LC_PROP_CMD_FLOAT6 =       2026  #  RW float; user value
LC_PROP_CMD_FLOAT7 =       2027  #  RW float; user value
LC_PROP_CMD_FLOAT8 =       2028  #  RW float; user value
LC_PROP_CMD_FLOAT9 =       2029  #  RW float; user value
LC_PROP_CMD_HAND0 =        2030  #  RW handle; user value
LC_PROP_CMD_HAND1 =        2031  #  RW handle; user value
LC_PROP_CMD_HAND2 =        2032  #  RW handle; user value
LC_PROP_CMD_HAND3 =        2033  #  RW handle; user value
LC_PROP_CMD_HAND4 =        2034  #  RW handle; user value
LC_PROP_CMD_HAND5 =        2035  #  RW handle; user value
LC_PROP_CMD_HAND6 =        2036  #  RW handle; user value
LC_PROP_CMD_HAND7 =        2037  #  RW handle; user value
LC_PROP_CMD_HAND8 =        2038  #  RW handle; user value
LC_PROP_CMD_HAND9 =        2039  #  RW handle; user value
LC_PROP_CMD_STR =          2040  #  RW string; user value

# #define LC_PROP_CMD_OBJ          2049  // R  handle; pointer to this command

LC_PROP_CMD__MAX =         2050

# -----------------------------------------------


#  Drawing


# -----------------------------------------------

LC_PROP_DRW__MIN =            3001
LC_PROP_DRW_UID =             3001    #  R  string; Drawing's Unique Identifier
LC_PROP_DRW_FILENAME =        3002    #  RW string; Drawing's filename
LC_PROP_DRW_DESCR =           3003    #  RW string; drawing's description
LC_PROP_DRW_COMMENT =         3003    #  sane as LC_PROP_DRW_DESCR  
LC_PROP_DRW_READONLY =        3004    #  RW bool; "Readonly" flag
LC_PROP_DRW_DIRTY =           3005    #  RW bool; "Drawing was modified" flag
LC_PROP_DRW_IDMAX =           3006    #  R  int64|string; max Unique Identifier    // undoc
LC_PROP_DRW_SYNCZOOM =        3011    #  RW bool; "Synchronize Layouts zoom" flag
LC_PROP_DRW_HASALPHABLEND =   3013    #  R  bool; true is used alpha blend (transparent filling)
LC_PROP_DRW_BLKREFGRIPS =     3014    #  RW int; BlockRef grips: 0-all grips, 1-only Pos, 2-Pos&Rotation
LC_PROP_DRW_JL_BASE =         3015    #  RW bool; Begin jump lines from basepoint
LC_PROP_DRW_JL_BASEX =        3016    #  RW float; Basepoint X
LC_PROP_DRW_JL_BASEY =        3017    #  RW float; Basepoint Y
LC_PROP_DRW_JL_LAYER =        3018    #  RW bool; enable layers for jump lines (add column in "Layers" dialog)
LC_PROP_DRW_EXTOFFLAYER =     3019    #  RW bool; enable invisible layers for extents calculation
LC_PROP_DRW_ENABLEUNDO =      3021    #  RW bool; Enable undo recording
LC_PROP_DRW_LOCKSEL =         3022    #  RW bool; enable selection on locked layers
LC_PROP_DRW_MAXHATDASH =      3023    #  RW int; max number of hatch dashes in Hatch entities
LC_PROP_DRW_PROPLINFILL =     3024    #  RW bool; if TRUE then display LinFill item in Properties window
LC_PROP_DRW_PROPZTH =         3025    #  RW bool; if TRUE then display Z and Thickness items in Properties window
LC_PROP_DRW_3DVIEW =          3026    #  R  bool; has 3D view (see LC_CMD_3DVIEW)

#  system variables (similar names as in AutoCAD)

LC_PROP_DRW_LUNITS =          3031   #  RW int; Linear units (LC_LUNIT_SCIEN and others)
LC_PROP_DRW_LUPREC =          3032   #  RW int; Precision for linear units (number of decimal digits)
LC_PROP_DRW_AUNITS =          3033   #  RW int; Angle units (LC_AUNIT_DEGREE and others)
LC_PROP_DRW_AUPREC =          3034   #  RW int; Precision for angular units (number of decimal digits)
LC_PROP_DRW_ANGBASE =         3035   #  RW int; base angle
LC_PROP_DRW_ANGDIR =          3036   #  RW int; angle direction, 0-counterclockwise, 1-clockwise
LC_PROP_DRW_INSUNITS =        3037   #  RW int;  (LC_INSUNIT_UNDEFINED and others)
LC_PROP_DRW_PDMODE =          3038   #  RW int; default point draw mode, LC_POINT_PIXEL and others   
LC_PROP_DRW_PDSIZE =          3039   #  RW float; default point size, negative value means percent of a window
LC_PROP_DRW_CMLJUST =         3040   #  RW int; Current multiline justification 0 = Top; 1 = Middle; 2 = Bottom
LC_PROP_DRW_CMLSCALE =        3041   #  RW float; Current multiline scale

#  Background, foreground and cursor colors 

LC_PROP_DRW_COLORBACKM =      3051    #  RW int; background color for Model Space
LC_PROP_DRW_COLORBACKP =      3052    #  RW int; background color for Paper Space
LC_PROP_DRW_COLORFOREM =      3053    #  RW int; foreground color on Model Space
LC_PROP_DRW_COLORFOREP =      3054    #  RW int; foreground color on Paper Space
LC_PROP_DRW_COLORCURSORM =    3055    #  RW int; cursor color on Model Space
LC_PROP_DRW_COLORCURSORP =    3056    #  RW int; cursor color on Paper Space
LC_PROP_DRW_COLORPAPER =      3057    #  RW int; color of paper sheet on Paper Space

#  Active outline color 

LC_PROP_DRW_COLOR =           3061    #  RW string; Active color
LC_PROP_DRW_COLORBYLAYER =    3062    #  RW bool; Color "ByLayer"
LC_PROP_DRW_COLORBYBLOCK =    3063    #  RW bool; Color "ByBlock"
LC_PROP_DRW_COLORI =          3064    #  RW int; R bool; Active Color Index
LC_PROP_DRW_COLORT =          3065    #  RW int; R bool; Active True Color

#  Active fill color 

LC_PROP_DRW_FCOLOR =          3066    #  RW string; Active filling color
LC_PROP_DRW_FCOLORBYLAYER =   3067    #  RW bool; filling Color "ByLayer"
LC_PROP_DRW_FCOLORBYBLOCK =   3068    #  RW bool; filling Color "ByBlock"
LC_PROP_DRW_FCOLORI =         3069    #  RW int; R bool; Active filling Color Index
LC_PROP_DRW_FCOLORT =         3070    #  RW int; R bool; Active filling True Color

#  Active objects and parameters, used on creating new entities 

LC_PROP_DRW_LAYER =           3081    #  RW handle|string; Handle to active layer|Name of active layer
LC_PROP_DRW_LINETYPE =        3082    #  RW handle|string; Handle to active linetype|Name of active linetype
LC_PROP_DRW_LTSCALE =         3083    #  RW float; active linetype scale
LC_PROP_DRW_TEXTSTYLE =       3084    #  RW handle|string; Handle to active text style|Name of active text style
LC_PROP_DRW_DIMSTYLE =        3085    #  RW handle|string; Handle to active dim style|Name of active dim style
LC_PROP_DRW_PNTSTYLE =        3086    #  RW handle|string; Handle to active point style|Name of active point style
LC_PROP_DRW_MLSTYLE =         3087    #  RW handle|string; Handle to active mline style|Name of active mline style
LC_PROP_DRW_BLOCK =           3089    #  RW handle|string; Handle to active block|Name of active block
LC_PROP_DRW_VISBLOCK =        3090    #  RW handle|string; Handle to currently visible block|Name of currently visible block
LC_PROP_DRW_LAYOUT =          3091    #  RW handle|string; Handle to active layout (Tab)
LC_PROP_DRW_BARCTYPE =        3092    #  RW int; active barcode type, LC_BARTYPE_CODE39 and others
LC_PROP_DRW_BARCSOLID =       3093    #  RW bool; draw barcode without filling option
LC_PROP_DRW_LWMODE =          3094    #  RW int;  line width mode (LC_LW_THIN, LC_LW_REAL, LC_LW_PIXEL)
LC_PROP_DRW_LWSCALE =         3095    #  RW float; line width screen scale, mm / pixel
LC_PROP_DRW_LWIDTH =          3096    #  RW int; active Linewidth (for new entities)
LC_PROP_DRW_LWDEFAULT =       3097    #  RW int; Default linewidth (if linewidth==LC_LWIDTH_DEFAULT)
LC_PROP_DRW_LINFILL =         3098    #  RW handle|string; Handle to active linfill|Name of active linfill
LC_PROP_DRW_TINPNT =          3102    #  R  handle; active TIN point (snapped) 
LC_PROP_DRW_TINTR =           3103    #  R  handle; TIN triangle used by COkTIN::GetZ(..)
LC_PROP_DRW_TINXY0 =          3104    #  RW bool; normalize TIN XY coordinates to 0.0

#  Explode options 

LC_PROP_DRW_EXPLODEARC =      3131    #  RW bool; enable exploding of arcs, circles, ellipses
LC_PROP_DRW_EXPPLINELA =      3132    #  RW bool; explode bulge polylines: TRUE-to lines and arcs, FALSE-to lines
LC_PROP_DRW_EXPSIMPLINE =     3133    #  RW bool; explode simple polylines to lines
LC_PROP_DRW_EXPTEXTSPLINE =   3134    #  RW bool; explode TT text to splines (FALSE - to lines)

#  Default named objects 

LC_PROP_DRW_BLOCK_MODEL =     3151    #  R  handle; Handle to "*Model_Space" block
LC_PROP_DRW_LAYER_0 =         3152    #  R  handle; Handle to layer "0"
LC_PROP_DRW_LINETYPE_CONT =   3153    #  R  handle; Handle to linetype "Continuous"
LC_PROP_DRW_LINETYPE_BYLAY =  3154    #  R  handle; Handle to linetype "ByLayer"
LC_PROP_DRW_LINETYPE_BYBLK =  3155    #  R  handle; Handle to linetype "ByBlock"
LC_PROP_DRW_TEXTSTYLE_STD =   3156    #  R  handle; Handle to text style "Standard"
LC_PROP_DRW_TSTYLE_STD =      3156    #  same as LC_PROP_DRW_TEXTSTYLE_STD
LC_PROP_DRW_PNTSTYLE_STD =    3157    #  R  handle; Handle to point style "Standard"
LC_PROP_DRW_DIMSTYLE_STD =    3158    #  R  handle; Handle to dim style "Standard"
LC_PROP_DRW_MLSTYLE_STD =     3159    #  R  handle; Handle to mline style "Standard"

#  Default resolution 

LC_PROP_DRW_RESOLARC =        3171    #  RW int; default resolution for arc/circle/ellipse/bulge
LC_PROP_DRW_RESOLSPLINE =     3172    #  RW int; default resolution for splines
LC_PROP_DRW_RESOLTEXT =       3173    #  RW int; default resolution for TTF text 

#  Limits (also lcDrwSetLimits )

LC_PROP_DRW_LIM_MINPIXSIZE =  3181    #  RW float; minimal pixel size (drawing units)
LC_PROP_DRW_LIM_MAXLEF =      3182    #  RW float; Xmin of limits rect
LC_PROP_DRW_LIM_MAXBOT =      3183    #  RW float; Ymin of limits rect
LC_PROP_DRW_LIM_MAXRIG =      3184    #  RW float; Xmax of limits rect
LC_PROP_DRW_LIM_MAXTOP =      3185    #  RW float; Ymax of limits rect
LC_PROP_DRW_LIM_MAXON =       3186    #  RW bool; enable max limits

#  User specified data 

LC_PROP_DRW_XDATASIZE =       3251    #  RW int; size of extra data (bytes)     
LC_PROP_DRW_XDATA =           3252    #  RW handle; pointer to extra data       
LC_PROP_DRW_INT0 =            3260    #  RW int;   
LC_PROP_DRW_INT1 =            3261    #  RW int;   
LC_PROP_DRW_INT2 =            3262    #  RW int;   
LC_PROP_DRW_INT3 =            3263    #  RW int;   
LC_PROP_DRW_INT4 =            3264    #  RW int;   
LC_PROP_DRW_INT5 =            3265    #  RW int;   
LC_PROP_DRW_INT6 =            3266    #  RW int;   
LC_PROP_DRW_INT7 =            3267    #  RW int;   
LC_PROP_DRW_INT8 =            3268    #  RW int;   
LC_PROP_DRW_INT9 =            3269    #  RW int;   
LC_PROP_DRW_FLOAT0 =          3270    #  RW float; 
LC_PROP_DRW_FLOAT1 =          3271    #  RW float; 
LC_PROP_DRW_FLOAT2 =          3272    #  RW float; 
LC_PROP_DRW_FLOAT3 =          3273    #  RW float; 
LC_PROP_DRW_FLOAT4 =          3274    #  RW float; 
LC_PROP_DRW_FLOAT5 =          3275    #  RW float; 
LC_PROP_DRW_FLOAT6 =          3276    #  RW float; 
LC_PROP_DRW_FLOAT7 =          3277    #  RW float; 
LC_PROP_DRW_FLOAT8 =          3278    #  RW float; 
LC_PROP_DRW_FLOAT9 =          3279    #  RW float; 
LC_PROP_DRW_STR0 =            3280    #  RW string;
LC_PROP_DRW_STR1 =            3281    #  RW string;
LC_PROP_DRW_STR2 =            3282    #  RW string;
LC_PROP_DRW_STR3 =            3283    #  RW string;
LC_PROP_DRW_STR4 =            3284    #  RW string;
LC_PROP_DRW_STR5 =            3285    #  RW string;
LC_PROP_DRW_STR6 =            3286    #  RW string;
LC_PROP_DRW_STR7 =            3287    #  RW string;
LC_PROP_DRW_STR8 =            3288    #  RW string;
LC_PROP_DRW_STR9 =            3289    #  RW string;
LC_PROP_DRW__MAX =            3299

# -----------------------------------------------


#  Drawing's Tables


# -----------------------------------------------

LC_PROP_TABLE__MIN =          4000 

#  Common properties for tables

LC_PROP_TABLE_ID =            4001  #  R  int64|string; Unique Identifier
LC_PROP_TABLE_NAME =          4002  #  R  string; Table name      
LC_PROP_TABLE_DESC =          4003  #  RW string; Description     
LC_PROP_TABLE_DESCR =         4003  #  RW string; Description     
LC_PROP_TABLE_DRW =           4004  #  R  handle; Handler to owner drawing 
LC_PROP_TABLE_DELETED =       4005  #  R  bool; "Deleted" flag    
LC_PROP_TABLE_ODA_HANDLE =    4010  #  RW string; ODA table handle  // undoc
LC_PROP_TABLE_TYPE =          4011  #  R  int; object type (LC_OBJ_LAYER and others)    
LC_PROP_TABLE_PRIORITY =      4012  #  RW int; priority for sorting   
LC_PROP_TABLE_NREFS =         4013  #  R  int; number of references to a table
LC_PROP_TABLE_XDATASIZE =     4051  #  RW int; size of extra data (bytes)
LC_PROP_TABLE_XDATA =         4052  #  RW handle; pointer to extra data  
LC_PROP_TABLE_XSTR =          4053  #  RW string; user string (uses XDATA buffer) 
LC_PROP_TABLE_INT0 =          4060  #  RW int; user value  
LC_PROP_TABLE_INT1 =          4061  #  RW int; user value  
LC_PROP_TABLE_INT2 =          4062  #  RW int; user value  
LC_PROP_TABLE_INT3 =          4063  #  RW int; user value  
LC_PROP_TABLE_INT4 =          4064  #  RW int; user value  
LC_PROP_TABLE_FLOAT0 =        4070  #  RW float; user value
LC_PROP_TABLE_FLOAT1 =        4071  #  RW float; user value
LC_PROP_TABLE_FLOAT2 =        4072  #  RW float; user value
LC_PROP_TABLE_FLOAT3 =        4073  #  RW float; user value
LC_PROP_TABLE_FLOAT4 =        4074  #  RW float; user value
LC_PROP_TABLEBASE__MAX =      4100

#  Layer ----------------------------------------

LC_PROP_LAYER_ID =            4001  #  R  int64|string; Unique Identifier,  same as LC_PROP_TABLE_ID
LC_PROP_LAYER_NAME =          4002  #  RW string; Layer Name,  same as LC_PROP_TABLE_NAME
LC_PROP_LAYER_DESC =          4003  #  RW string; Description, same as LC_PROP_TABLE_DESC
LC_PROP_LAYER_DESCR =         4003  #  RW string; Description
LC_PROP_LAYER_DRW =           4004  #  R  handle; Handle to owner drawing~
LC_PROP_LAYER_DELETED =       4005  #  R  bool; "Deleted" flag
LC_PROP_LAYER_COLOR =         4101  #  RW string; Color
LC_PROP_LAYER_COLORI =        4102  #  RW int; R bool; Color Index
LC_PROP_LAYER_COLORT =        4103  #  RW int; R bool; True Color
LC_PROP_LAYER_FCOLOR =        4104  #  RW string; Filling Color  
LC_PROP_LAYER_FCOLORI =       4105  #  RW int; R bool; Filling Color Index
LC_PROP_LAYER_FCOLORT =       4106  #  RW int; R bool; Filling True Color
LC_PROP_LAYER_LINETYPE =      4111  #  RW handle|string; Handle to Linetype|Name of Linetype
LC_PROP_LAYER_LWEIGHT =       4112  #  RW int; Linewidth
LC_PROP_LAYER_LWIDTH =        4112  #  same as LC_PROP_LAYER_LWEIGHT
LC_PROP_LAYER_LOCKED =        4113  #  RW bool; "No edit" flag
LC_PROP_LAYER_NOPRINT =       4114  #  RW bool; "Not printed" flag
LC_PROP_LAYER_VISIBLE =       4115  #  RW bool; "Visible"; flag
LC_PROP_LAYER_0 =             4116  #  R  bool; "Layer 0" flag
LC_PROP_LAYER_NODLG =         4117  #  RW bool; not displayed in the "Layers" dialog 
LC_PROP_LAYER_JUMPLINES =     4118  #  RW bool; enable jump lines for entities of this layer
LC_PROP_LAYER_OSNAP =         4119  #  RW bool; enable object snap for entities of this layer
LC_PROP_LAYER_NOEXPORT =      4120  #  RW bool; "Not exportable" flag

#  Linetype -------------------------------------

LC_PROP_LINETYPE_ID =         4001  #  R  int64|string; same as LC_PROP_TABLE_ID
LC_PROP_LINETYPE_NAME =       4002  #  RW string; same as LC_PROP_TABLE_NAME
LC_PROP_LINETYPE_DESC =       4003  #  RW string; same as LC_PROP_TABLE_DESC
LC_PROP_LINETYPE_DESCR =      4003  #  RW string; Description
LC_PROP_LINETYPE_DRW =        4004  #  R  handle; Handle to owner drawing~
LC_PROP_LINETYPE_DELETED =    4005  #  R  bool; "Deleted" flag
LC_PROP_LINETYPE_DATA =       4145  #  RW string; Linetype data in text form
LC_PROP_LINETYPE_SCALE =      4146  #  RW float; Global scale for this linetype
LC_PROP_LINETYPE_CONTINUOUS = 4147  #  R  bool; "Continuous" flag
LC_PROP_LINETYPE_BYLAYER =    4148  #  R  bool; "By Layer" flag
LC_PROP_LINETYPE_BYBLOCK =    4149  #  R  bool; "By Block" flag
LC_PROP_LINETYPE_STD =        4150  #  R  bool; standard linetype ("Continuous" or "By Layer" or "By Block")     // undoc
LC_PROP_LINETYPE_PATLEN =     4151  #  R  float; Pattern length
LC_PROP_LINETYPE_NELEM =      4153  #  R  int; number of elements
LC_PROP_LINETYPE_IELEM =      4154  #   W int; set index of active element
LC_PROP_LTELEM_LEN =          4155  #  R  float; segment length
LC_PROP_LTELEM_COMPLEX =      4156  #  R  bool; TRUE - element contains shape or text
LC_PROP_LTELEM_SHAPE =        4157  #  R  bool; TRUE - text style is used, FALSE - draw only szText[0] and fontfile is used
LC_PROP_LTELEM_TEXT =         4158  #  R  string; Text
LC_PROP_LTELEM_STYLE =        4159  #  R  handle; text style (valid if LC_PROP_LTELEM_SHAPE is FALSE)
LC_PROP_LTELEM_FONTNAME =     4160  #  R  string; fontname (valid if LC_PROP_LTELEM_SHAPE is TRUE)
LC_PROP_LTELEM_SCALE =        4161  #  R  float; shape scale
LC_PROP_LTELEM_ANGLE =        4162  #  R  float; rotation angle in radians for a text element in the linetype
LC_PROP_LTELEM_ABSANGLE =     4163  #  R  bool; if TRUE - RotAngle is absolute 
LC_PROP_LTELEM_X =            4164  #  R  float; x offset of a shape
LC_PROP_LTELEM_Y =            4165  #  R  float; y offset of a shape

#  Text style

LC_PROP_TSTYLE_ID =           4001  #  R  int64|string; same as LC_PROP_TABLE_ID
LC_PROP_TSTYLE_NAME =         4002  #  RW string; same as LC_PROP_TABLE_NAME
LC_PROP_TSTYLE_DESC =         4003  #  RW string; same as LC_PROP_TABLE_DESC
LC_PROP_TSTYLE_DESCR =        4003  #  RW string; Description
LC_PROP_TSTYLE_DRW =          4004  #  R  handle; Handle to owner drawing
LC_PROP_TSTYLE_DELETED =      4005  #  R  bool; "Deleted" flag
LC_PROP_TSTYLE_FONT =         4175  #  RW string; Font filename
LC_PROP_TSTYLE_HFONT =        4176  #  R  handle; Handle to font
LC_PROP_TSTYLE_HEIGHT =       4177  #  RW float; Default height
LC_PROP_TSTYLE_WSCALE =       4178  #  RW float; Default width scale
LC_PROP_TSTYLE_OBLIQUE =      4179  #  RW float; Default obluque angle
LC_PROP_TSTYLE_ANGLE =        4180  #  RW float; Default rotation angle
LC_PROP_TSTYLE_ALIGN =        4181  #  RW int; Default alignment
LC_PROP_TSTYLE_UPDOWN =       4182  #  RW bool; "Upside down" flag
LC_PROP_TSTYLE_BACKWARD =     4183  #  RW bool; "Backward" flag
LC_PROP_TSTYLE_LINESPACE =    4184  #  RW float; Default linespace
LC_PROP_TSTYLE_CHARSPACE =    4185  #  RW float; Default charspace
LC_PROP_TSTYLE_STANDARD =     4186  #  R  bool; "Standard" flag
LC_PROP_TSTYLE_SHAPES =       4187  #  R  bool; "Shapes" flag
LC_PROP_TSTYLE_WINFONT =      4188  #  RW bool; if TRUE - Windows True Type font is used
LC_PROP_TSTYLE_SOLID =        4189  #  RW bool; Solid text
LC_PROP_TSTYLE_CLOSED =       4190  #  R  bool; font has closed shape
LC_PROP_TSTYLE_HOLLOW =       4191  #  R  bool; not solid and closed shape
LC_PROP_TSTYLE_BOLD =         4192  #  RW bool; "Bold" flag (for LC_ENT_TEXTWIN)
LC_PROP_TSTYLE_ITALIC =       4193  #  RW bool; "Italic" flag (for LC_ENT_TEXTWIN)
LC_PROP_TSTYLE_UNDERLINE =    4194  #  RW bool; "Underline" flag (for LC_ENT_TEXTWIN)
LC_PROP_TSTYLE_STRIKEOUT =    4195  #  RW bool; "Strikeout" flag (for LC_ENT_TEXTWIN)
LC_PROP_TSTYLE_MONOWIDTH =    4196  #  RW float; Width for monospaced font (0.0 - use default)

#  Dimension style

LC_PROP_DIMST_ID =            4001  #  R  int64|string; same as LC_PROP_TABLE_ID
LC_PROP_DIMST_NAME =          4002  #  RW string; same as LC_PROP_TABLE_NAME
LC_PROP_DIMST_DESC =          4003  #  RW string; same as LC_PROP_TABLE_DESC
LC_PROP_DIMST_DESCR =         4003  #  RW string;
LC_PROP_DIMST_DRW =           4004  #  R  handle;
LC_PROP_DIMST_DELETED =       4005  #  R  bool;
LC_PROP_DIMST_STANDARD =      4205  #  R  bool;
LC_PROP_DIMST_ADEC =          4211  #  RW int; Number of precision places displayed in angular dimensions
LC_PROP_DIMST_ASZ =           4212  #  RW float; Controls dimension arrowhead size and hookline size
LC_PROP_DIMST_AUNIT =         4213  #  RW int; Controls the angle format for angular dimensions
LC_PROP_DIMST_AZIN =          4214  #  RW int; Controls suppression of zeros for angular dimensions
LC_PROP_DIMST_BLK1 =          4215  #  RW int|string; arrow1 type
LC_PROP_DIMST_BLK2 =          4216  #  RW int|string; arrow2 type
LC_PROP_DIMST_CEN =           4217  #  RW float; Determines style of center marks for arcs or circles being dimensioned
LC_PROP_DIMST_CLRD =          4218  #  RW int; Sets color for dimension leader lines, arrowheads, dimension lines and leaders
LC_PROP_DIMST_CLRE =          4219  #  RW int; Sets color for dimension extension lines
LC_PROP_DIMST_CLRT =          4220  #  RW int; Sets color for dimension text
LC_PROP_DIMST_DEC =           4221  #  RW int; Controls the precision for a primary units dimension's tolerance values
LC_PROP_DIMST_DSEP =          4222  #  RW int; Single-character decimal separator used when creating dimensions whose unit format is decimal
LC_PROP_DIMST_EXE =           4223  #  RW float; Controls extension of extension line beyond dimension line
LC_PROP_DIMST_EXO =           4224  #  RW float; Offset of extension lines from origin points
LC_PROP_DIMST_GAP =           4225  #  RW float; Determines the gap around dimension text when the dimension line is broken to fit the text
LC_PROP_DIMST_LDRBLK =        4226  #  RW int|string; leader arrow type
LC_PROP_DIMST_LFAC =          4227  #  RW float; Global scale factor for linear dimensioning measurements
LC_PROP_DIMST_LWD =           4228  #  RW int; Dimension line lineweight 
LC_PROP_DIMST_LWE =           4229  #  RW int; Extension line lineweight
LC_PROP_DIMST_POST =          4230  #  RW string; Sets a dimension prefix or suffix for the measurement text
LC_PROP_DIMST_RND =           4231  #  RW float; Sets a rounding value for dimensions.
LC_PROP_DIMST_SCALE =         4232  #  RW float; Overall scale factor applied to dimension variables for sizes, distances and offsets
LC_PROP_DIMST_TAD =           4233  #  RW int; Determines text vertical position relative to the dimension line
LC_PROP_DIMST_TIH =           4234  #  RW int; If 1, text between extension lines is always drawn horizontally
LC_PROP_DIMST_TXT =           4235  #  RW float; Dimension text height if the current dimstyle has no fixed text height
LC_PROP_DIMST_TXSTY =         4236  #  RW handle|string; Text style      
LC_PROP_DIMST_TSTYLE =        4236  #     LC_PROP_DIMST_TXSTY
LC_PROP_DIMST_LUNIT =         4237  #  RW int; Sets units for all dimension types except Angular
LC_PROP_DIMST_ZIN =           4238  #  RW int; Controls the suppression of zeros in the primary unit value

#  Point style

LC_PROP_PSTYLE_ID =           4001  #  R  int64|string; same as LC_PROP_TABLE_ID
LC_PROP_PSTYLE_NAME =         4002  #  RW string; same as LC_PROP_TABLE_NAME
LC_PROP_PSTYLE_DESC =         4003  #  RW string; same as LC_PROP_TABLE_DESC
LC_PROP_PSTYLE_DESCR =        4003  #  RW string;
LC_PROP_PSTYLE_DRW =          4004  #  R  handle;
LC_PROP_PSTYLE_DELETED =      4005  #  R  bool;
LC_PROP_PSTYLE_STANDARD =     4265  #  R  bool;
LC_PROP_PSTYLE_BLOCK =        4266  #  RW handle|string;
LC_PROP_PSTYLE_BSCALE =       4267  #  RW float;
LC_PROP_PSTYLE_TSTYLE =       4268  #  RW handle|string;
LC_PROP_PSTYLE_TH =           4269  #  RW float;
LC_PROP_PSTYLE_TWS =          4270  #  RW float;
LC_PROP_PSTYLE_PTMODE =       4271  #  RW int;  LC_POINT_PIXEL and others
LC_PROP_PSTYLE_PTSIZE =       4272  #  RW float;
LC_PROP_PSTYLE_SNAP =         4273  #  RW bool;
LC_PROP_PSTYLE_FIXED =        4274  #  RW bool;

#  Multiline style

LC_PROP_MLSTYLE_ID =          4001  #  R  int64|string; Unique Identifier
LC_PROP_MLSTYLE_NAME =        4002  #  RW string;
LC_PROP_MLSTYLE_DESC =        4003  #  RW string;
LC_PROP_MLSTYLE_DESCR =       4003  #  RW string;
LC_PROP_MLSTYLE_DRW =         4004  #  R  handle; Handle to owner drawing 
LC_PROP_MLSTYLE_DELETED =     4005  #  R  bool;
LC_PROP_MLSTYLE_STANDARD =    4281  #  R  bool;
LC_PROP_MLSTYLE_JOINTS =      4282  #  RW bool; draw joins
LC_PROP_MLSTYLE_STARTLINE =   4283  #  RW bool; draw start line
LC_PROP_MLSTYLE_STARTARC =    4284  #  RW bool; draw start arc
LC_PROP_MLSTYLE_ENDLINE =     4285  #  RW bool; draw end line
LC_PROP_MLSTYLE_ENDARC =      4286  #  RW bool; draw end arc
LC_PROP_MLSTYLE_NLINES =      4287  #  R int; number of lines
LC_PROP_MLSTYLE_ILINE =       4288  #  RW int; index of current line
LC_PROP_MLSTYLE_OFFSET =      4289  #  RW float; offset of current line
LC_PROP_MLSTYLE_LTYPE =       4290  #  RW handle; linetype of current line
LC_PROP_MLSTYLE_COLOR =       4291  #  RW string; color of current line

#  Raster image

LC_PROP_IMAGE_ID =            4001  #  R  int; Unique Identifier
LC_PROP_IMAGE_NAME =          4002  #  RW string; Image name 
LC_PROP_IMAGE_DESC =          4003  #  RW string; Image description 
LC_PROP_IMAGE_DESCR =         4003  #  RW string; Image description 
LC_PROP_IMAGE_DRW =           4004  #  R  handle; Handle to owner drawing 
LC_PROP_IMAGE_DELETED =       4005  #  R  bool;
LC_PROP_IMAGE_FILENAME =      4401  #  RW string; Image filename 
LC_PROP_IMAGE_SIZE =          4402  #  R  int;    Image size, bytes 
LC_PROP_IMAGE_WPIX =          4403  #  R  int;    Image width (pixels) 
LC_PROP_IMAGE_W =             4404
LC_PROP_IMAGE_HPIX =          4405  #  R  int;    Image height (pixels) 
LC_PROP_IMAGE_H =             4406
LC_PROP_IMAGE_CBIT =          4407  #  R  int;    Color bits 
LC_PROP_IMAGE_RGB =           4408  #  R  bool;   RGB/Palette colors 
LC_PROP_IMAGE_EMBEDDED =      4409  #  RW bool;  saved inside a drawing   
LC_PROP_IMAGE_CREATED =       4410  #  R  bool;  // undoc
LC_PROP_IMAGE_COLORS =        4411  #  RW handle;  pointer to palette memory
LC_PROP_IMAGE_BITS =          4412  #  RW handle;  pointer to points memory 
LC_PROP_IMAGE_DIB =           4413  #  R  handle;

#  Filling style

LC_PROP_LFILL_ID =          4001  #  R  int64|string; Unique Identifier
LC_PROP_LFILL_NAME =        4002  #  RW string;
LC_PROP_LFILL_DESC =        4003  #  RW string;
LC_PROP_LFILL_DESCR =       4003  #  RW string;
LC_PROP_LFILL_DRW =         4004  #  R  handle; Handle to owner drawing 
LC_PROP_LFILL_DELETED =     4005  #  R  bool;
LC_PROP_LFILL_ENABLED0 =    4501  #  R  bool; TRUE if line is enabled
LC_PROP_LFILL_DIST0 =       4502  #  R  float; dist between lines
LC_PROP_LFILL_ANGLE0 =      4503  #  R  float; angle of lines
LC_PROP_LFILL_GAP0 =        4504  #  R  float; gap at line end
LC_PROP_LFILL_ENABLED1 =    4505  #  R  bool; TRUE if line is enabled
LC_PROP_LFILL_DIST1 =       4506  #  R  float; dist between lines
LC_PROP_LFILL_ANGLE1 =      4507  #  R  float; angle of lines
LC_PROP_LFILL_GAP1 =        4508  #  R  float; gap at line end

# -----------------------------------------------


#  Block


# -----------------------------------------------

LC_PROP_BLOCK_ID =             4001  #  R  int64|string; same as LC_PROP_TABLE_ID
LC_PROP_BLOCK_NAME =           4002  #  RW string; same as LC_PROP_TABLE_NAME
LC_PROP_BLOCK_DESC =           4003  #  RW string; same as LC_PROP_TABLE_DESC
LC_PROP_BLOCK_DESCR =          4003  #  RW string;
LC_PROP_BLOCK_DRW =            4004  #  R  handle; Handle to owner drawing
LC_PROP_BLOCK_DELETED =        4005  #  R  bool;
LC_PROP_BLOCK_X =              4801  #  RW float;
LC_PROP_BLOCK_Y =              4802  #  RW float;
LC_PROP_BLOCK_UFSCALING =      4803  #  RW bool;
LC_PROP_BLOCK_UNITS =          4804  #  RW int;   LC_INSUNIT_UNDEFINED and other
LC_PROP_BLOCK_UNITSCALE =      4810  #  R  float;
LC_PROP_BLOCK_MODEL =          4811  #  R  bool;
LC_PROP_BLOCK_PAPER =          4812  #  R  bool;
LC_PROP_BLOCK_LAYOUT =         4813  #  R  bool;  MODEL or  PAPER
LC_PROP_BLOCK_STANDARD =       4814  #  R  bool;
LC_PROP_BLOCK_LAYOUTNAME =     4815  #  RW string;
LC_PROP_BLOCK_LAYOUTORDER =    4816  #  RW int; value used for window tabs order  // undoc
LC_PROP_BLOCK_HIDDEN =         4818  #  R  bool;
LC_PROP_BLOCK_DIM =            4819  #  R  bool;
LC_PROP_BLOCK_HATCH =          4820  #  R  bool;
LC_PROP_BLOCK_NOBJ =           4821  #  R  int; number of graphic objects (not deleted) in the block
LC_PROP_BLOCK_NENTS =          4821  #  R  int; number of graphic objects (not deleted) in the block
LC_PROP_BLOCK_NSELOBJ =        4822  #  R  int; number of selected objects
LC_PROP_BLOCK_NSELENTS =       4822  #  R  int; number of selected objects
LC_PROP_BLOCK_ATTRIBS =        4827  #  R  bool;  "Block has attributes" flag

#  #define LC_PROP_BLOCK_TIN            4828  // RW handle;  active TIN entity

LC_PROP_BLOCK_ODA_LAYOUTHANDLE = 4829  #  RW string; ODA layout handle  // undoc
LC_PROP_BLOCK_ODA_VPORTHANDLE =  4830  #  RW string; ODA overall viewport handle  // undoc

#  #define LC_PROP_BLOCK_PLACE          4828  // RW bool; uses "block place" points

LC_PROP_BLOCK_XMIN =           4831  #  R  float;
LC_PROP_BLOCK_YMIN =           4832  #  R  float;
LC_PROP_BLOCK_XMAX =           4833  #  R  float;
LC_PROP_BLOCK_YMAX =           4834  #  R  float;
LC_PROP_BLOCK_XCEN =           4835  #  R  float;
LC_PROP_BLOCK_YCEN =           4836  #  R  float;
LC_PROP_BLOCK_DX =             4837  #  R  float;
LC_PROP_BLOCK_DY =             4838  #  R  float;
LC_PROP_BLOCK_VISLEF =         4839  #  R  float; Visible rect
LC_PROP_BLOCK_VISBOT =         4840  #  R  float; Visible rect
LC_PROP_BLOCK_VISRIG =         4841  #  R  float; Visible rect
LC_PROP_BLOCK_VISTOP =         4842  #  R  float; Visible rect
LC_PROP_BLOCK_SELXMIN =        4843  #  R  float; Selection rect
LC_PROP_BLOCK_SELYMIN =        4844  #  R  float;
LC_PROP_BLOCK_SELXMAX =        4845  #  R  float;
LC_PROP_BLOCK_SELYMAX =        4846  #  R  float;
LC_PROP_BLOCK_SELXCEN =        4847  #  R  float;
LC_PROP_BLOCK_SELYCEN =        4848  #  R  float;
LC_PROP_SHAPE_ANGLE =          4849  #  RW float; Shape rotation angle
LC_PROP_PAPER__MIN =           4851  #  
LC_PROP_PAPER_INCH =           4851  #  RW bool; original paper units (used when import drawing from DWG)
LC_PROP_PAPER_X0 =             4852  #  RW float; X coordinate of paper left-bottom corner 
LC_PROP_PAPER_Y0 =             4853  #  RW float; Y coordinate of paper left-bottom corner 
LC_PROP_PAPER_SIZE =           4854  #  R  int; Paper size (LC_PAPER_A0 and others)
LC_PROP_PAPER_ORIENT =         4855  #  R  int; Paper orientation (LC_PAPER_BOOK and others)
LC_PROP_PAPER_W =              4856  #  R  float; Paper width, mm 
LC_PROP_PAPER_H =              4857  #  R  float; Paper height, mm 
LC_PROP_TABLE__MAX =          4999 

# === Entities (properties) =========================================

LC_PROP_ENT__MIN =          5001  #  until LC_PROP_ENT__MAX  9999
LC_PROP_ENT_TYPE =          5030  #  R  int;
LC_PROP_ENT_ID =            5001  #  R  int64|string; Unique Identifier
LC_PROP_ENT_KEY =           5002  #  RW int; User value
LC_PROP_ENT_BLOCK =         5024  #  R  handle|string; Handle to Block|Name of Block
LC_PROP_ENT_DRW =           5025  #  R  handle; Handle to drawing
LC_PROP_ENT_LAYER =         5020  #  RW handle|string; Handle to Layer|Name of Layer
LC_PROP_ENT_LINETYPE =      5021  #  RW handle|string; Handle to Linetype|Name of Linetype
LC_PROP_ENT_LTSCALE =       5022  #  RW float; Linetype scale
LC_PROP_ENT_LWEIGHT =       5023  #  RW int; Lineweight
LC_PROP_ENT_LWIDTH =        5023  #  same as LC_PROP_ENT_LWEIGHT
LC_PROP_ENT_PRIORITY =      5040  #  RW int64|string; priority for sorting
LC_PROP_ENT_FROMCB =        5035  #  R  bool; TRUE if entity was added from ClipBoard

#  Outline Color 

LC_PROP_ENT_COLOR =         5003  #  RW string|int; Color name | RGB color
LC_PROP_ENT_COLORI =        5004  #  RW int; R bool; Color Index
LC_PROP_ENT_COLORT =        5005  #  RW int; R bool; True Color
LC_PROP_ENT_COLORBYLAYER =  5006  #  RW bool; Color "ByLayer"
LC_PROP_ENT_COLORBYBLOCK =  5007  #  RW bool; Color "ByBlock"

#  Entity filling (for closed entities)

LC_PROP_ENT_SOLIDFILL =     5008  #  RW bool; same as LC_PROP_ENT_FILLED
LC_PROP_ENT_FILLED =        5008  #  RW bool;  
LC_PROP_ENT_FILLING =       5008  #  RW bool; same as LC_PROP_ENT_FILLED
LC_PROP_ENT_WIPEOUT =       5011  #  RW bool; filled with background color
LC_PROP_ENT_FCOLOR =        5012  #  RW string|int; Filling Color | RGB color
LC_PROP_ENT_FCOLORI =       5013  #  RW int; R bool; Filling Color Index
LC_PROP_ENT_FCOLORT =       5014  #  RW int; R bool; Filling True Color
LC_PROP_ENT_FCOLORBYLAYER = 5015  #  RW bool; Filling Color "ByLayer"
LC_PROP_ENT_FCOLORBYBLOCK = 5016  #  RW bool; Filling Color "ByBlock"
LC_PROP_ENT_FALPHA =        5017  #  RW int; Filling Color alpha value
LC_PROP_ENT_LINFILL =       5018  #  RW handle|string; Handle to Lfilling type|Name of Lfilling type
LC_PROP_ENT_LINFILLNL =     5019  #  R  int; number of generated filling lines

#  Flags

LC_PROP_ENT_LOCKED =        5026  #  R  bool;
LC_PROP_ENT_VISIBLE =       5027  #  R  bool;
LC_PROP_ENT_HIDDEN =        5028  #  RW bool;
LC_PROP_ENT_BLINK =         5029  #  RW bool;  ???
LC_PROP_ENT_DELETED =       5031  #  RW bool;
LC_PROP_ENT_IMMORTAL =      5032  #  RW bool; can't be deleted
LC_PROP_ENT_SELECTED =      5033  #  R  bool; TRUE if entity is selected
LC_PROP_ENT_GRIPMODE =      5034  #  RW int; forbid movement of some grips

#  Geometric extents

LC_PROP_ENT_XMIN =          5052  #  R  float; Xmin of entity extents
LC_PROP_ENT_YMIN =          5053  #  R  float; Ymin of entity extents
LC_PROP_ENT_XMAX =          5054  #  R  float; Xmax of entity extents
LC_PROP_ENT_YMAX =          5055  #  R  float; Ymax of entity extents
LC_PROP_ENT_XCEN =          5056  #  R  float; X center of entity
LC_PROP_ENT_YCEN =          5057  #  R  float; Y center of entity
LC_PROP_ENT_DX =            5058  #  R  float; width of entity
LC_PROP_ENT_DY =            5059  #  R  float; height of entity
LC_PROP_ENT_LEN =           5060  #  R  float; length (line, pline, arc, circle, ellipse, rect)
LC_PROP_ENT_Z =             5061  #  RW float; Z coord for 2D objects
LC_PROP_ENT_THICKNESS =     5062  #  RW float; thickness of extrusion

#  Extra data

LC_PROP_ENT_XDATAID =       5041  #  R  int; type of xdata lcEntXData
LC_PROP_ENT_XDATAFLAGS =    5042  #  RW int; flags of xdata
LC_PROP_ENT_XDATASIZE =     5043  #  R  int; size of extra data (bytes)
LC_PROP_ENT_XDATA =         5044  #  RW handle; pointer to extra data  
LC_PROP_ENT_XSTR =          5045  #  RW string; user string (uses XDATA buffer) 
LC_PROP_ENTBASE__MAX =      5100

#  Point 

LC_PROP_POINT_STYLE =      5101  #  RW handle|string; Handle to Point Style|Name of Point Style
LC_PROP_POINT_X =          5102  #  RW float;
LC_PROP_POINT_Y =          5103  #  RW float;
LC_PROP_POINT_Z =          5051  #  RW float; same as LC_PROP_ENT_Z
LC_PROP_POINT_SIZE =       5104  #  RW float;
LC_PROP_POINT_MODE =       5105  #  RW int;
LC_PROP_POINT_BANGLE =     5106  #  RW float;
LC_PROP_POINT_TDX =        5107  #  RW float;
LC_PROP_POINT_TDY =        5108  #  RW float;
LC_PROP_POINT_TANGLE =     5109  #  RW float;
LC_PROP_POINT_TEXT =       5110  #  RW string;
LC_PROP_POINT_TEXTLEN =    5111  #  R  int;

#  #define LC_PROP_POINT_BPLACE     5112  // RW string; Block place attributes


#  Points array

LC_PROP_PTARR_FILENAME =   5112  #  R  string; full filename (with path)
LC_PROP_PTARR_FNAME =      5113  #  R  string; only filename (without path)
LC_PROP_PTARR_DIR =        5114  #  R  string; file directory
LC_PROP_PTARR_LOADED =     5115  #  R  bool; TRUE if file is loaded
LC_PROP_PTARR_NUM =        5116  #  R  int; number of points
LC_PROP_PTARR_NUMVIS =     5117  #  R  int; number of currently visible points
LC_PROP_PTARR_TEXTVLIM =   5118  #  RW float; text view limit
LC_PROP_PTARR_VLIM10 =     5119  #  RW float; view limit 1/10
LC_PROP_PTARR_VLIM100 =    5120  #  RW float; view limit 1/100

#  Line

LC_PROP_LINE_X0 =          5131  #  RW float; Start point X
LC_PROP_LINE_Y0 =          5132  #  RW float; Start point Y
LC_PROP_LINE_Z0 =          5133  #  RW float; Start point Z
LC_PROP_LINE_X1 =          5134  #  RW float; End point X
LC_PROP_LINE_Y1 =          5135  #  RW float; End point Y
LC_PROP_LINE_Z1 =          5136  #  RW float; End point Z
LC_PROP_LINE_DX =          5137  #  RW float; Delta X
LC_PROP_LINE_DY =          5138  #  RW float; Delta Y
LC_PROP_LINE_DZ =          5139  #  RW float; Delta Z
LC_PROP_LINE_ANG =         5140  #  RW float; Angle 
LC_PROP_LINE_LEN =         5141  #  RW float; Length
LC_PROP_LINE_DSARROW0 =    5142  #  RW handle; Dim.style for start arrow
LC_PROP_LINE_DSARROW1 =    5143  #  RW handle; Dim.style for end arrow
LC_PROP_LINE_W0 =          5144  #  RW float; Start width
LC_PROP_LINE_W1 =          5145  #  RW float; End width
LC_PROP_LINE_SOLID =       5146  #  RW bool; Solid fill (if has width)

#  Construction Line

LC_PROP_XLINE_X0 =         5151  #  RW float; Base point X
LC_PROP_XLINE_Y0 =         5152  #  RW float; Base point Y
LC_PROP_XLINE_ANG =        5154  #  RW float; Direction angle
LC_PROP_XLINE_DIRX =       5155  #  R  float; Direction vector X
LC_PROP_XLINE_DIRY =       5156  #  R  float; Direction vector Y
LC_PROP_XLINE_RAY =        5157  #  RW bool; Ray mode

#  Circle

LC_PROP_CIRCLE_X =         5201  #  RW float; Center point X
LC_PROP_CIRCLE_Y =         5202  #  RW float; Center point Y
LC_PROP_CIRCLE_R =         5204  #  RW float; Radius
LC_PROP_CIRCLE_RAD =       5204  #  RW float; Radius
LC_PROP_CIRCLE_RADIUS =    5204  #  RW float; Radius
LC_PROP_CIRCLE_DIAM =      5205  #  RW float; Diameter
LC_PROP_CIRCLE_LEN =       5206  #  RW float; Circumference length
LC_PROP_CIRCLE_AREA =      5207  #  RW float; Area
LC_PROP_CIRCLE_ANG0 =      5208  #  RW float; start angle
LC_PROP_CIRCLE_DIRCW =     5209  #  RW bool; direction, 1-CW, 0-CCW
LC_PROP_CIRCLE_RESOL =     5210  #  RW int; resolution
LC_PROP_CIRC_X =           5201  #  RW float; Center point X
LC_PROP_CIRC_Y =           5202  #  RW float; Center point Y
LC_PROP_CIRC_R =           5204  #  RW float; Radius
LC_PROP_CIRC_RAD =         5204  #  RW float; Radius
LC_PROP_CIRC_RADIUS =      5204  #  RW float; Radius
LC_PROP_CIRC_DIAM =        5205  #  RW float; Diameter
LC_PROP_CIRC_LEN =         5206  #  RW float; Circumference length
LC_PROP_CIRC_AREA =        5207  #  RW float; Area
LC_PROP_CIRC_ANG0 =        5208  #  RW float; start angle
LC_PROP_CIRC_DIRCW =       5209  #  RW bool; direction, 1-CW, 0-CCW
LC_PROP_CIRC_RESOL =       5210  #  RW int; resolution

#  Arc

LC_PROP_ARC_X =            5231  #  RW float; Center point X
LC_PROP_ARC_Y =            5232  #  RW float; Center point Y
LC_PROP_ARC_R =            5234  #  RW float; Radius
LC_PROP_ARC_RAD =          5234  #  RW float; Radius
LC_PROP_ARC_RADIUS =       5234  #  RW float; Radius
LC_PROP_ARC_ANG0 =         5235  #  RW float; Start angle
LC_PROP_ARC_ANGARC =       5236  #  RW float; Arc included angle
LC_PROP_ARC_ANGEND =       5237  #  R  float; End angle
LC_PROP_ARC_X0 =           5238  #  R  float; Start point X
LC_PROP_ARC_Y0 =           5239  #  R  float; Start point Y
LC_PROP_ARC_Z0 =           5240  #  RW float; Start point Z
LC_PROP_ARC_XMID =         5241  #  R  float; Middle point X
LC_PROP_ARC_YMID =         5242  #  R  float; Middle point Y
LC_PROP_ARC_XEND =         5243  #  R  float; End point X
LC_PROP_ARC_YEND =         5244  #  R  float; End point Y
LC_PROP_ARC_ZEND =         5245  #  RW float; End point Z
LC_PROP_ARC_LEN =          5246  #  R  float; Length
LC_PROP_ARC_CHLEN =        5247  #  R  float; Chord length
LC_PROP_ARC_AREA =         5248  #  R  float; Area
LC_PROP_ARC_CCW =          5249  #  R  bool; "Counter-ClockWise direction" flag
LC_PROP_ARC_SECTOR =       5250  #  RW bool; Draw as sector
LC_PROP_ARC_RESOL =        5251  #  RW int; resolution

#  Ellipse

LC_PROP_ELL_X =            5261  #  RW float; Center point X 
LC_PROP_ELL_Y =            5262  #  RW float; Center point Y 
LC_PROP_ELL_R1 =           5264  #  RW float; Radius first 
LC_PROP_ELL_R2 =           5265  #  RW float; Radius second 
LC_PROP_ELL_RATIO =        5266  #  RW float; R2/R1
LC_PROP_ELL_ANGLE =        5267  #  RW float; Rotation angle 
LC_PROP_ELL_ANG0 =         5268  #  RW float; Start angle (for elliptical arc) 
LC_PROP_ELL_ANGARC =       5269  #  RW float; Arc included angle. Positive - counter-clockwise,
LC_PROP_ELL_ANGEND =       5270  #  R  float; End angle
LC_PROP_ELL_X0 =           5271  #  R  float; Start point X
LC_PROP_ELL_Y0 =           5272  #  R  float; Start point Y
LC_PROP_ELL_XEND =         5273  #  R  float; End point X
LC_PROP_ELL_YEND =         5274  #  R  float; End point Y
LC_PROP_ELL_LEN =          5276  #  R  float; Length 
LC_PROP_ELL_AREA =         5277  #  R  float; Area 
LC_PROP_ELL_FULL =         5278  #  R  bool;  "Full ellipse" flag 
LC_PROP_ELL_CCW =          5279  #  R  bool;  "CounterClockWise direction" flag 
LC_PROP_ELL_SECTOR =       5282  #  RW bool;  "Draw as sector" flag 
LC_PROP_ELL_RESOL =        5283  #  RW int; resolution
LC_PROP_ELL__MAX =         5299

#  Lightweight Polyline 

LC_PROP_PLINE_FIT =        5301  #  RW int; Fit type
LC_PROP_PLINE_CLOSED =     5302  #  RW bool; Closed polyline
LC_PROP_PLINE_NVERS =      5303  #  R  int; Number of vertices
LC_PROP_PLINE_WIDTH =      5305  #  RW float|bool; Constant width | Has const width
LC_PROP_PLINE_LEN =        5306  #  R  float; Length
LC_PROP_PLINE_AREA =       5307  #  R  float; Area
LC_PROP_PLINE_CW =         5308  #  R  bool; "ClockWise direction" flag
LC_PROP_PLINE_CCW =        5309  #  R  bool; "Counter-ClockWise direction" flag
LC_PROP_PLINE_Z =          5310  #  RW float; Evevalion (Z)
LC_PROP_PLINE_CONSTZ =     5311  #  R  bool; all vertices have same Z
LC_PROP_PLINE_RESOLA =     5312  #  RW int; resolution for arc segments
LC_PROP_PLINE_RESOLS =     5313  #  RW int; resolution for spline segments
LC_PROP_PLINE_RADIUS =     5314  #  RW float|bool; Constant radius (for rounded polyline) | Has const radius
LC_PROP_PLINE_CHAMFER =    5315  #  RW bool; Chamfer or arc (for rounded polyline)
LC_PROP_PLINE_HASANG0 =    5316  #  RW bool; Has start angle (for fit spline)
LC_PROP_PLINE_ANG0 =       5317  #  RW float; Start angle (for fit spline)
LC_PROP_PLINE_HASANG2 =    5318  #  RW bool; Has end angle (for fit spline)
LC_PROP_PLINE_ANG2 =       5319  #  RW float; End angle (for fit spline)
LC_PROP_PLINE_WIPEOUT =    5325  #  RW bool; "wipeout" type polygon
LC_PROP_PLINE_ODSOLID =    5326  #  RW bool; made from SOLID entity at ODA import

#  Multiline Polyline 

LC_PROP_MLINE_STYLE =      5351  #  RW handle|string; Handle to mline style|Name of mline style
LC_PROP_MLINE_JUST =       5352  #  RW int; justification LC_MLINE_TOP and other
LC_PROP_MLINE_SCALE =      5353  #  RW float; mline scale
LC_PROP_MLINE_NVERS =      5354  #  R  int; Number of vertices
LC_PROP_MLINE_CLOSED =     5355  #  RW bool; closed polyline
LC_PROP_MLINE_FIT =        5356  #  RW int; Fit type
LC_PROP_MLINE_LEN =        5357  #  R  float; Length
LC_PROP_MLINE_AREA =       5358  #  R  float; Area

#  Rectangle

LC_PROP_RECT_X =           5371  #  RW float; Center X
LC_PROP_RECT_Y =           5372  #  RW float; Center Y 
LC_PROP_RECT_W =           5374  #  RW float; Width 
LC_PROP_RECT_H =           5375  #  RW float; Height 
LC_PROP_RECT_ANGLE =       5376  #  RW float; Rotation angle 
LC_PROP_RECT_R =           5377  #  RW float; Corners radius 
LC_PROP_RECT_RAD =         5377  #  RW float; Corners radius 
LC_PROP_RECT_RADIUS =      5377  #  RW float; Corners radius 
LC_PROP_RECT_CHAMFER =     5378  #  RW bool; Chamfer at corners 
LC_PROP_RECT_DIRCW =       5379  #  RW bool; Clockwise direction
LC_PROP_RECT_START =       5380  #  RW int; Start corner, 0-3
LC_PROP_RECT_LEN =         5381  #  R  float; Perimeter 
LC_PROP_RECT_AREA =        5382  #  R  float; Area 
LC_PROP_RECT_RESOL =       5383  # 
LC_PROP_RECT_GRID =        5384  #  RW bool; enable grid
LC_PROP_RECT_GRNW =        5385  #  RW int; number of cells along width
LC_PROP_RECT_GRNH =        5386  #  RW int; number of cells along height
LC_PROP_RECT_GRDW =        5387  #  RW float; cell size along width
LC_PROP_RECT_GRDH =        5388  #  RW float; cell size along height

#  Clip Rectangle (on Model Space) (also lcCRectsClear abd others)

LC_PROP_CRECT_ID =         5390  #  RW int; Identifier
LC_PROP_CRECT_NAME =       5391  #  RW string; Name
LC_PROP_CRECT_X =          5392  #  RW float; Center X
LC_PROP_CRECT_Y =          5393  #  RW float; Center Y 
LC_PROP_CRECT_W =          5394  #  RW float; Width 
LC_PROP_CRECT_H =          5395  #  RW float; Height 
LC_PROP_CRECT_ANGLE =      5396  #  RW float; Rotation angle 
LC_PROP_CRECT_LEN =        5398  #  R  float; Perimeter 
LC_PROP_CRECT_AREA =       5399  #  R  float; Area 

#  Text (LC_ENT_TEXT)

LC_PROP_TEXT_STYLE =       5401  #  RW handle|string; Handle to text style|Name of text style
LC_PROP_TEXT_STR =         5402  #  RW string; Text content
LC_PROP_TEXT_STRT =        5403  #  R  string; Text content (with translated codes)
LC_PROP_TEXT_LEN =         5404  #  R  int; Number of characters in the Text string
LC_PROP_TEXT_ALIGN =       5405  #  RW int; Alignment type (LC_TA_LEFBOT and others)
LC_PROP_TEXT_H =           5406  #  RW float; Height (0-ByStyle, <0-pixel height, -1-default GUI size) 
LC_PROP_TEXT_X =           5407  #  RW float; Insertion point X
LC_PROP_TEXT_Y =           5408  #  RW float; Insertion point Y
LC_PROP_TEXT_DX =          5409  #  RW int; Offset X (valid if Pixel Height is true)
LC_PROP_TEXT_DY =          5410  #  RW int; Offset Y (valid if Pixel Height is true)
LC_PROP_TEXT_WSCALE =      5412  #  RW float; Width factor (horisontal scale)
LC_PROP_TEXT_ANGLE =       5413  #  RW float; Rotation angle
LC_PROP_TEXT_OBLIQUE =     5414  #  RW float; Oblique angle
LC_PROP_TEXT_CHARSPACE =   5415  #  RW float;
LC_PROP_TEXT_WRECT =       5416  #  R  float; Width of a text bounding rectange
LC_PROP_TEXT_X0 =          5417  #  R  float; X coordinate of left-bottom corner
LC_PROP_TEXT_Y0 =          5418  #  R  float; Y coordinate of left-bottom corner
LC_PROP_TEXT_XFIT =        5419  #  RW float; 
LC_PROP_TEXT_YFIT =        5420  #  RW float;
LC_PROP_TEXT_UPDOWN =      5421  #  RW bool; Indication "Upside-down text"
LC_PROP_TEXT_BACKWARD =    5422  #  RW bool; Indication "Backward text"
LC_PROP_TEXT_RESOL =       5423  #  RW int; Resolution

#  TextWin (LC_ENT_TEXTWIN)

LC_PROP_TEXTW_STYLE =      5431  #  RW handle|string; Handle to text style|Name of text style
LC_PROP_TEXTW_STR =        5432  #  RW string; Text content
LC_PROP_TEXTW_STRT =       5433  #  R  string; Text content (with translated codes)
LC_PROP_TEXTW_LEN =        5434  #  R  int; Number of characters in the Text string
LC_PROP_TEXTW_ALIGN =      5435  #  RW int; Alignment type
LC_PROP_TEXTW_X =          5436  #  RW float; Insertion point X
LC_PROP_TEXTW_Y =          5437  #  RW float; Insertion point Y
LC_PROP_TEXTW_H =          5438  #  RW float; Height
LC_PROP_TEXTW_DX =         5440  #  RW int; Offset X (valid if Pixel Height is true)
LC_PROP_TEXTW_DY =         5441  #  RW int; Offset Y (valid if Pixel Height is true)
LC_PROP_TEXTW_WSCALE =     5442  #  RW float; Width factor (horisontal scale)
LC_PROP_TEXTW_ANGLE =      5443  #  RW float; Rotation angle

#  Multitine Text (LC_ENT_MTEXT)

LC_PROP_MTEXT__MIN =       5451
LC_PROP_MTEXT_STYLE =      5451  #  RW handle|string;
LC_PROP_MTEXT_STR =        5452  #  RW string;
LC_PROP_MTEXT_LEN =        5453  #  R  int;
LC_PROP_MTEXT_ALIGN =      5454  #  RW int;
LC_PROP_MTEXT_X =          5455  #  RW float;
LC_PROP_MTEXT_Y =          5456  #  RW float;
LC_PROP_MTEXT_H =          5458  #  RW float;
LC_PROP_MTEXT_WSCALE =     5459  #  RW float;
LC_PROP_MTEXT_ANGLE =      5460  #  RW float;
LC_PROP_MTEXT_OBLIQUE =    5461  #  RW float;
LC_PROP_MTEXT_WRECT =      5462  #  R  float;
LC_PROP_MTEXT_HRECT =      5463  #  R  float;
LC_PROP_MTEXT_WRAPWIDTH =  5464  #  RW float;
LC_PROP_MTEXT_LINESPACE =  5465  #  RW float;
LC_PROP_MTEXT_CHARSPACE =  5466  #  RW float;
LC_PROP_MTEXT_MIRROR =     5467  #  RW bool;
LC_PROP_MTEXT_RESOL =      5468  #  RW int; Resolution
LC_PROP_MTEXT__MAX =       5470

#  Arc Text (LC_ENT_ARCTEXT)

LC_PROP_ATEXT__MIN =       5481
LC_PROP_ATEXT_STYLE =      5481  #  RW handle|string; Text style
LC_PROP_ATEXT_STR =        5482  #  RW string;
LC_PROP_ATEXT_STRT =       5483  #  R  string; Text content (with translated codes)
LC_PROP_ATEXT_LEN =        5484  #  R  int;
LC_PROP_ATEXT_X =          5485  #  RW float; Center X
LC_PROP_ATEXT_Y =          5486  #  RW float; Center Y
LC_PROP_ATEXT_R =          5487  #  RW float; Radius
LC_PROP_ATEXT_RAD =        5487  #  RW float; Radius
LC_PROP_ATEXT_RADIUS =     5487  #  RW float; Radius
LC_PROP_ATEXT_ANGLE =      5488  #  RW float; text Angle
LC_PROP_ATEXT_ANGSTA =     5489  #  R  float; Start angle
LC_PROP_ATEXT_ANGEND =     5490  #  R  float; End angle
LC_PROP_ATEXT_CW =         5491  #  RW bool; Clockwise direction
LC_PROP_ATEXT_H =          5492  #  RW float; Height
LC_PROP_ATEXT_WSCALE =     5493  #  RW float; Width scale
LC_PROP_ATEXT_CHARSPACE =  5494  #  RW float; Charspace
LC_PROP_ATEXT_ALIGN =      5495  #  RW int;
LC_PROP_ATEXT_RESOL =      5496  #  RW int; Resolution
LC_PROP_ATEXT__MAX =       5499

#  Attribute definition & Attribute

LC_PROP_ATT_MODE =         5501  #  RW int; 
LC_PROP_ATT_TSTYLE =       5502  #  RW handle|string; Handle to text style|Name of text style
LC_PROP_ATT_TAG =          5503  #  RW string;
LC_PROP_ATT_PROMPT =       5504  #  RW string;
LC_PROP_ATT_VALUE =        5505  #  RW string;
LC_PROP_ATT_ALIGN =        5506  #  RW int; Alignment type
LC_PROP_ATT_X =            5507  #  RW float; Insertion point X
LC_PROP_ATT_Y =            5508  #  RW float; Insertion point Y
LC_PROP_ATT_H =            5510  #  RW float; Height
LC_PROP_ATT_WSCALE =       5511  #  RW float; Width factor (horisontal scale)
LC_PROP_ATT_ANGLE =        5512  #  RW float; Rotation angle
LC_PROP_ATT_OBLIQUE =      5513  #  RW float; Oblique angle
LC_PROP_ATT_X0 =           5514  #  R  float; X coordinate of left-bottom corner
LC_PROP_ATT_Y0 =           5515  #  R  float; Y coordinate of left-bottom corner
LC_PROP_ATT_XFIT =         5516  #  RW float; 
LC_PROP_ATT_YFIT =         5517  #  RW float;
LC_PROP_ATT_UPDOWN =       5518  #  RW bool; Indication "Upside-down text"
LC_PROP_ATT_BACKWARD =     5519  #  RW bool; Indication "Backward text"
LC_PROP_ATT_COLOR =        5521  #  R str; 
LC_PROP_ATT_LAYER =        5522  #  R handle; 
LC_PROP_ATT_LINETYPE =     5523  #  R handle; 
LC_PROP_ATT_LTSCALE =      5524  #  R float; 
LC_PROP_ATT_LWIDTH =       5525  #  R int; 
LC_PROP_ATT_INVIS =        5526  #  RW bool; Mode: invisible
LC_PROP_ATT_LOCKPOS =      5527  #  RW bool; Mode: locked position
LC_PROP_ATT_MTEXT =        5528  #  RW bool; Mode: multiline text

#  Block Reference

LC_PROP_BLKREF_BLOCK =     5531  #  RW handle|string; Handle to Block|Name of Block
LC_PROP_BLKREF_X =         5532  #  RW float; Insertion point X
LC_PROP_BLKREF_Y =         5533  #  RW float; Insertion point Y
LC_PROP_BLKREF_SCALE =     5534  #  RW float;
LC_PROP_BLKREF_SCX =       5535  #  RW float;
LC_PROP_BLKREF_SCY =       5536  #  RW float;
LC_PROP_BLKREF_UFSCALE =   5537  #  R  bool;
LC_PROP_BLKREF_ANGLE =     5538  #  RW float;
LC_PROP_BLKREF_ARNX =      5539  #  RW int;
LC_PROP_BLKREF_ARDX =      5540  #  RW float;
LC_PROP_BLKREF_ARNY =      5541  #  RW int;
LC_PROP_BLKREF_ARDY =      5542  #  RW float;
LC_PROP_BLKREF_ARANG =     5543  #  RW float;
LC_PROP_BLKREF_ATTRIBS =   5544  #  R  bool;  "Block has attributes" flag
LC_PROP_BLKREF_GRIPMODE =  5545  #  RW int;   "Block has attributes" flag

#  only for using with LC_CMD_INSERT

LC_PROP_BLKREF_ONS_XY =    5546  #  RW bool; Specify position on-screen
LC_PROP_BLKREF_ONS_SCALE = 5547  #  RW bool; Specify scale on-screen
LC_PROP_BLKREF_ONS_ANGLE = 5548  #  RW bool; Specify rotation angle on-screen
LC_PROP_BLKREF_RETURN =    5549  #  R  handle; Handle to inserted object (block reference) after  execution

#  Raster Image reference

LC_PROP_IMGREF_IMAGE =     5551  #  RW handle|string;  Handle to Image | Name of Image 
LC_PROP_IMGREF_XC =        5552  #  RW float; X coordinate of center point 
LC_PROP_IMGREF_YC =        5553  #  RW float; Y coordinate of center point
LC_PROP_IMGREF_W =         5554  #  RW float; Width 
LC_PROP_IMGREF_H =         5555  #  RW float; Height 
LC_PROP_IMGREF_WPIX =      5556  #  R  int; Image width in pixels
LC_PROP_IMGREF_HPIX =      5557  #  R  int; Image height in pixels 
LC_PROP_IMGREF_SCALE =     5558  #  RW float; uniform scale, units per pixel 
LC_PROP_IMGREF_PIXELSIZE = 5558  #  same as LC_PROP_IMGREF_SCALE
LC_PROP_IMGREF_SCALEX =    5560  #  RW float; X scale, units per pixel 
LC_PROP_IMGREF_SCALEY =    5561  #  RW float; Y scale, units per pixel
LC_PROP_IMGREF_SQPIX =     5562  #  RW bool; if TRUE - uniform scale for puxel
LC_PROP_IMGREF_ANGLE =     5564  #  RW float; rotation angle, around left-bottom corner 
LC_PROP_IMGREF_BORDER =    5565  #  RW bool;  "Draw a border" flag 
LC_PROP_IMGREF_TRANSP =    5566  #  RW int; transparency: 0-none, 1-TransColor, 2-AlphaValue
LC_PROP_IMGREF_TRCOLOR =   5567  #  RW int; transparent color (COLORREF)
LC_PROP_IMGREF_TRALPHA =   5568  #  RW int; alpha value (0-255)
LC_PROP_IMGREF_GRAYS =     5569  #  RW bool;
LC_PROP_IMGREF_GREY =      5569  #  RW bool; same as LC_PROP_IMGREF_GRAYS
LC_PROP_IMGREF_FLIPHOR =   5570  #  RW bool;
LC_PROP_IMGREF_FLIPVER =   5571  #  RW bool;
LC_PROP_IMGREF_PATH =      5573  #  R  string; image full filename
LC_PROP_IMGREF_GP_X =      5574  #  R  float; result of lcImgRefGetPixel
LC_PROP_IMGREF_GP_Y =      5575  #  R  float; result of lcImgRefGetPixel
LC_PROP_IMGREF_GP_COLOR =  5576  #  R  int; result of lcImgRefGetPixel
LC_PROP_IMGREF_GP_GRAY =   5577  #  RW bool; color mode for lcImgRefGetPixel
LC_PROP_IMGREF_UNSCALABLE = 5578  #  RW bool; "Unscalable image" flag
LC_PROP_IMGREF_UNSSCALE =   5579  #  RW float; scale for unscalable image 
LC_PROP_IMGREF_UNSALIGN =   5580  #  RW int; Alignment of unscalable image, relative to LC_PROP_IMGREF_XC, LC_PROP_IMGREF_YC (LC_IMGA_CENTER or other)

#  ECW / Jpeg2000 Image

LC_PROP_ECW_FILENAME =     5581  #  R  string; Image filename
LC_PROP_ECW_LOADED =       5582  #  R  bool; "Image is loaded" flag 
LC_PROP_ECW_WPIX =         5583  #  R  int; Width (pixels)
LC_PROP_ECW_HPIX =         5584  #  R  int; Height (pixels)
LC_PROP_ECW_CBIT =         5585  #  R  int; Color bits
LC_PROP_ECW_XMIN =         5586  #  R  float; X coordinate of left-bottom corner
LC_PROP_ECW_YMIN =         5587  #  R  float; Y coordinate of left-bottom corner
LC_PROP_ECW_XMAX =         5588  #  R  float; X coordinate of right-top corner
LC_PROP_ECW_YMAX =         5589  #  R  float; Y coordinate of right-top corner
LC_PROP_ECW_W =            5590  #  R  float; Width (drawing units)
LC_PROP_ECW_H =            5591  #  R  float; Height (drawing units)
LC_PROP_ECW_SCALEX =       5592  #  R  float;
LC_PROP_ECW_SCALEY =       5593  #  R  float;
LC_PROP_ECW_BORDER =       5594  #  RW bool; "Draw a border" flag 
LC_PROP_ECW_GRAYS =        5595  #  RW bool; "Draw as grayscale" flag
LC_PROP_ECW_BRIGHT =       5596  #  RW int;  change brightness -200...+200

#  Big Raster Image

LC_PROP_BRI_FILENAME =     5601  #  R  string; Image filename
LC_PROP_BRI_LOADED =       5602  #  R  bool; "Image is loaded" flag 
LC_PROP_BRI_WPIX =         5603  #  R  int; Width (pixels)
LC_PROP_BRI_HPIX =         5604  #  R  int; Height (pixels)
LC_PROP_BRI_XMIN =         5605  #  R  float; X coordinate of left-bottom corner
LC_PROP_BRI_YMIN =         5606  #  R  float; Y coordinate of left-bottom corner
LC_PROP_BRI_XMAX =         5607  #  R  float; X coordinate of right-top corner
LC_PROP_BRI_YMAX =         5608  #  R  float; Y coordinate of right-top corner
LC_PROP_BRI_W =            5609  #  R  float; Width (drawing units)
LC_PROP_BRI_H =            5610  #  R  float; Height (drawing units)
LC_PROP_BRI_PIXSIZE =      5611  #  R  float; drawing units per pixel
LC_PROP_BRI_BORDER =       5612  #  RW bool; "Draw a border" flag 

#  Camera view

LC_PROP_CAMERA_X =         5621  #  RW float; left of camera view rect
LC_PROP_CAMERA_Y =         5622  #  RW float; bottom of camera view rect
LC_PROP_CAMERA_W =         5623  #  RW float; width of camera view rect
LC_PROP_CAMERA_H =         5624  #  RW float; height of camera view rect

#  Hatch

LC_PROP_HATCH_NAME =       5631  #  RW string; Pattern name or "SOLID"
LC_PROP_HATCH_PATTERN =    5632  #  RW string; Pattern data for custom pattern
LC_PROP_HATCH_SCALE =      5633  #  RW float; Hatch scale 
LC_PROP_HATCH_ANGLE =      5634  #  RW float; Rotation angle 
LC_PROP_HATCH_SIZE =       5635  #  R  float; Pattern size
LC_PROP_HATCH_ASSOC =      5636  #  RW bool; "Associative hatch" flag 
LC_PROP_HATCH_SOLID =      5637  #  RW bool; Solid fill
LC_PROP_HATCH_CUSTOM =     5638  #  R  bool; Custom pattern
LC_PROP_HATCH_NENTS =      5639  #  R  int; number of boundary entities (for Associative hatch)
LC_PROP_HATCH_NPT =        5640  #  R  int; number of points
LC_PROP_HATCH_NLOOP =      5641  #  R  int; number of loops
LC_PROP_HATCH_NHPL =       5642  #  R  int; number of pattern lines
LC_PROP_HATCH_IHPL =       5643  #  W  int; set index of active pattern line
LC_PROP_HATCH_FALPHA =     5644  #  RW int; transparency alpha value (only for Solid hatch)
LC_PROP_HATCH_AREA =       5645  #  R  float; Area 
LC_PROP_HATCH_NDASHES =    5646  #  R  int; number of hatch dashes
LC_PROP_HPL_ANGLE =        5651  #  R  float;
LC_PROP_HPL_X0 =           5652  #  R  float;
LC_PROP_HPL_Y0 =           5653  #  R  float;
LC_PROP_HPL_DX =           5654  #  R  float;
LC_PROP_HPL_DY =           5655  #  R  float;
LC_PROP_HPL_NDASH =        5656  #  R  int;
LC_PROP_HPL_DASH1 =        5657  #  R  float;
LC_PROP_HPL_DASH2 =        5658  #  R  float;
LC_PROP_HPL_DASH3 =        5659  #  R  float;
LC_PROP_HPL_DASH4 =        5660  #  R  float;
LC_PROP_HPL_DASH5 =        5661  #  R  float;
LC_PROP_HPL_DASH6 =        5662  #  R  float;
LC_PROP_HPL_DASH7 =        5663  #  R  float;
LC_PROP_HPL_DASH8 =        5664  #  R  float;

#  Viewport on Paper Space

LC_PROP_VPORT_LEF =        5703  #  RW float; Left side
LC_PROP_VPORT_BOT =        5704  #  RW float; Bottom side
LC_PROP_VPORT_RIG =        5705  # 
LC_PROP_VPORT_TOP =        5706  # 
LC_PROP_VPORT_BORDER =     5707  #  RW bool; display border line
LC_PROP_VPORT_W =          5711  #  RW float; Width
LC_PROP_VPORT_H =          5712  #  RW float; Height
LC_PROP_VPORT_VX =         5713  #  RW float; View center X on the projection
LC_PROP_VPORT_VY =         5714  #  RW float; View center Y on the projection
LC_PROP_VPORT_VSCALE =     5715  #  RW float; View scale
LC_PROP_VPORT_VANGLE =     5716  #  RW float; View rotation angle
LC_PROP_VPORT_FIXSCALE =   5717  #  RW bool; fixed scale

#  Barcode

LC_PROP_BARC_XC =          5751  #  RW float; Center point X
LC_PROP_BARC_X =           5751  #   same as LC_PROP_BARC_XC
LC_PROP_BARC_YC =          5752  #  RW float; Center point Y
LC_PROP_BARC_Y =           5752  #   same as LC_PROP_BARC_YC
LC_PROP_BARC_W =           5753  #  RW float; Width
LC_PROP_BARC_H =           5754  #  RW float; Height
LC_PROP_BARC_ANG =         5755  #  RW float; Rotation angle
LC_PROP_BARC_TYPE =        5756  #  RW int; barcode type, LC_BARTYPE_CODE39 and others
LC_PROP_BARC_CODE =        5757  #  RW string;
LC_PROP_BARC_TEXT =        5757  #  RW string; same as LC_PROP_BARC_CODE
LC_PROP_BARC_CHECKSUM =    5758  #  RW bool; add checksum
LC_PROP_BARC_NCHARS =      5759  #  R  int;
LC_PROP_BARC_NUBITS =      5760  #  R  int; number of unused bits (free bits)
LC_PROP_BARC_NARSIZE =     5761  #  R  float;
LC_PROP_BARC_WIDERATIO =   5762  #  RW float;
LC_PROP_BARC_QZONE =       5763  #  RW float;
LC_PROP_BARC_OFFSET =      5764  #  RW float;
LC_PROP_BARC_INVERT =      5765  #  RW bool;
LC_PROP_BARC_HIDETEXT =    5766  #  RW bool; do not display text
LC_PROP_BARC_TSTYLE =      5767  #  RW handle|string; Handle to text style|Name of text style
LC_PROP_BARC_TEXTH =       5768  #  RW float; text height
LC_PROP_BARC_TEXTW =       5769  #  RW float; text width scale
LC_PROP_BARC_TEXTCS =      5770  #  RW float; text charspace
LC_PROP_BARC_TEXTALIGN =   5771  #  RW int; text alignment
LC_PROP_BARC_TEXTRES =     5772  #  RW int; Resolution (if 0 then use LC_PROP_DRW_RESOLTEXT)
LC_PROP_BARC_ECLEVEL =     5773  #  RW int; error correction level
LC_PROP_BARC_MASKPAT =     5774  #  R  int; mask pattern (0-7)
LC_PROP_BARC_DATATYPE =    5775  #  R  int; data type
LC_PROP_BARC_SIZE =        5776  #  R  int|string; size of 2D barcode, H x W, dots
LC_PROP_BARC_NBARS =       5777  #  R  int; same as LC_PROP_BARC_NMODX (for 1D - number of bars)
LC_PROP_BARC_NMODX =       5777  #  R  int; number of horizontal modules
LC_PROP_BARC_NMODY =       5778  #  R  int; number of vertical modules

#  Arrow

LC_PROP_ARR_X0 =           5801  #  RW float; Start point X
LC_PROP_ARR_Y0 =           5802  #  RW float; Start point Y
LC_PROP_ARR_X1 =           5803  #  RW float; End point X
LC_PROP_ARR_Y1 =           5804  #  RW float; End point Y
LC_PROP_ARR_ANG =          5805  #  RW float; Angle from start to end
LC_PROP_ARR_LEN =          5806  #  RW float; Distance from start to end
LC_PROP_ARR_W =            5807  #  RW float; Width coefficient
LC_PROP_ARR_SW =           5808  #  RW float; Arrow width coef.
LC_PROP_ARR_SL =           5809  #  RW float; Arrow length coef.
LC_PROP_ARR_TIME =         5810  #  RW int; Time
LC_PROP_ARR_SHARP =        5811  #  RW bool; sharp start

#  Spiral

LC_PROP_SPIR_X =           5821  #  RW float;
LC_PROP_SPIR_Y =           5822  #  RW float;
LC_PROP_SPIR_R =           5823  #  RW float; radius
LC_PROP_SPIR_RADIUS =      5823  #  RW float; radius
LC_PROP_SPIR_R2 =          5824  #  RW float;
LC_PROP_SPIR_RATIO =       5825  #  RW float;
LC_PROP_SPIR_ANGLE =       5826  #  RW float;
LC_PROP_SPIR_TURNS =       5827  #  RW float;
LC_PROP_SPIR_DIRCW =       5829  #  RW bool;
LC_PROP_SPIR_CLOSED =      5830  #  RW bool; TRUE - draw outer corcle
LC_PROP_SPIR_DSTEP =       5831  #  R  float; distance between spiral turns
LC_PROP_SPIR_RESOL =       5832  #  RW int; resolution

#  Xref

LC_PROP_XREF_FILENAME =    5841  #  RW string; full Filename (with path)
LC_PROP_XREF_FNAME =       5842  #  RW string; short Filename (without path)
LC_PROP_XREF_PATH =        5843  #  RW string; Path to the Filename
LC_PROP_XREF_X =           5844  #  RW float;
LC_PROP_XREF_Y =           5845  #  RW float;
LC_PROP_XREF_SCX =         5846  #  RW float;
LC_PROP_XREF_SCY =         5847  #  RW float;
LC_PROP_XREF_ANGLE =       5848  #  RW float;

#  Dimension

LC_PROP_DIM_STYLE =        6001  #  RW handle|string; Handle to dim style|Name of dim style
LC_PROP_DIM_MEAS =         6003  #  R  float; measured value
LC_PROP_DIM_TEXT =         6004  #  RW string; 
LC_PROP_DIMANG_STYLE =     6001  
LC_PROP_DIMANG_MEAS =      6003  
LC_PROP_DIMANG_TEXT =      6004  
LC_PROP_DIMALI_STYLE =     6001  
LC_PROP_DIMALI_MEAS =      6003  
LC_PROP_DIMALI_TEXT =      6004  
LC_PROP_DIMDIA_STYLE =     6001
LC_PROP_DIMDIA_MEAS =      6003
LC_PROP_DIMDIA_TEXT =      6004
LC_PROP_DIMRAD_STYLE =     6001
LC_PROP_DIMRAD_MEAS =      6003
LC_PROP_DIMRAD_TEXT =      6004
LC_PROP_DIMORD_STYLE =     6001
LC_PROP_DIMORD_MEAS =      6003
LC_PROP_DIMORD_TEXT =      6004
LC_PROP_DIMROT_STYLE =     6001
LC_PROP_DIMROT_MEAS =      6003
LC_PROP_DIMROT_TEXT =      6004
LC_PROP_DIMLIN_STYLE =     6001
LC_PROP_DIMLIN_MEAS =      6003
LC_PROP_DIMLIN_TEXT =      6004
LC_PROP_DIMANG__MIN =      6011
LC_PROP_DIMANG_3PNT =      6011  #  R  bool; "3 points" mode
LC_PROP_DIMANG_2LINE =     6012  #  R  bool; "2 lines" mode
LC_PROP_DIMANG_CPX =       6013  #  RW float; center point 1
LC_PROP_DIMANG_CPY =       6014  #  RW float; 
LC_PROP_DIMANG_DP1X =      6015  #  RW float; definition point 1
LC_PROP_DIMANG_DP1Y =      6016  #  RW float; 
LC_PROP_DIMANG_DP2X =      6017  #  RW float; definition point 2
LC_PROP_DIMANG_DP2Y =      6018  #  RW float; 
LC_PROP_DIMANG_L1P1X =     6021  #  RW float; line 1 def.point 1
LC_PROP_DIMANG_L1P1Y =     6022  #  RW float; 
LC_PROP_DIMANG_L1P2X =     6023  #  RW float; line 1 def.point 2
LC_PROP_DIMANG_L1P2Y =     6024  #  RW float; 
LC_PROP_DIMANG_DP3X =      6023
LC_PROP_DIMANG_DP3Y =      6024
LC_PROP_DIMANG_L2P1X =     6025  #  RW float; line 2 def.point 1
LC_PROP_DIMANG_L2P1Y =     6026  #  RW float; 
LC_PROP_DIMANG_L2P2X =     6027  #  RW float; line 2 def.point 2
LC_PROP_DIMANG_L2P2Y =     6028  #  RW float; 
LC_PROP_DIMANG_DP4X =      6027
LC_PROP_DIMANG_DP4Y =      6028
LC_PROP_DIMANG_APX =       6029  #  RW float; arc point X
LC_PROP_DIMANG_APY =       6030  #  RW float; arc point Y
LC_PROP_DIMANG_EXT1 =      6031  #  RW bool; visibility of extention line 1
LC_PROP_DIMANG_EXT2 =      6032  #  RW bool; visibility of extention line 2
LC_PROP_DIMANG_RAD =       6033  #  R  float; radius of dim arc
LC_PROP_DIMANG_TPOS =      6034  #  RW float; text position on arc
LC_PROP_DIMANG__MAX =      6050
LC_PROP_DIMALI__MIN =      6051
LC_PROP_DIMALI_DP1X =      6051  #  RW float; def point 1
LC_PROP_DIMALI_DP1Y =      6052  #  RW float;
LC_PROP_DIMALI_DP2X =      6053  #  RW float; def point 2
LC_PROP_DIMALI_DP2Y =      6054  #  RW float;
LC_PROP_DIMALI_TPX =       6055  #  RW float; text point
LC_PROP_DIMALI_TPY =       6056  #  RW float;
LC_PROP_DIMALI__MAX =      6069
LC_PROP_DIMDIA__MIN =      6071
LC_PROP_DIMDIA_CPX =       6071  #  RW float; center point
LC_PROP_DIMDIA_CPY =       6072  #  RW float;
LC_PROP_DIMDIA_RPX =       6073  #  RW float; radial point
LC_PROP_DIMDIA_RPY =       6074  #  RW float;
LC_PROP_DIMDIA_FPX =       6075  #  R  float; far radial point
LC_PROP_DIMDIA_FPY =       6076  #  R  float;
LC_PROP_DIMDIA_TPX =       6077  #  RW float; text point
LC_PROP_DIMDIA_TPY =       6078  #  RW float;
LC_PROP_DIMDIA__MAX =      6085
LC_PROP_DIMRAD__MIN =      6086
LC_PROP_DIMRAD_CPX =       6086  #  RW float; center point
LC_PROP_DIMRAD_CPY =       6087  #  RW float;
LC_PROP_DIMRAD_RPX =       6088  #  RW float; radial point
LC_PROP_DIMRAD_RPY =       6089  #  RW float;
LC_PROP_DIMRAD_TPX =       6090  #  RW float; text point
LC_PROP_DIMRAD_TPY =       6091  #  RW float;
LC_PROP_DIMRAD__MAX =      6099
LC_PROP_DIMORD__MIN =      6101 
LC_PROP_DIMORD_XORD =      6101  #  RW bool; TRUE - X ordinate, FALSE - Y ordinate
LC_PROP_DIMORD_DPX =       6102  #  RW float; def point
LC_PROP_DIMORD_DPY =       6103  #  RW float; 
LC_PROP_DIMORD_TPX =       6104  #  RW float; text point
LC_PROP_DIMORD_TPY =       6105  #  RW float;
LC_PROP_DIMORD__MAX =      6119
LC_PROP_DIMROT__MIN =      6121
LC_PROP_DIMROT_ANGLE =     6121  #  RW float; rotation angle
LC_PROP_DIMROT_DP1X =      6122  #  RW float; def point 1
LC_PROP_DIMROT_DP1Y =      6123  #  RW float;
LC_PROP_DIMROT_DP2X =      6124  #  RW float; def point 2
LC_PROP_DIMROT_DP2Y =      6125  #  RW float;
LC_PROP_DIMROT_TPX =       6126  #  RW float; text point
LC_PROP_DIMROT_TPY =       6127  #  RW float;
LC_PROP_DIMROT__MAX =      6139
LC_PROP_DIMLIN__MIN =      6121
LC_PROP_DIMLIN_ANGLE =     6121  #  RW float; rotation angle
LC_PROP_DIMLIN_DP1X =      6122  #  RW float; def point 1
LC_PROP_DIMLIN_DP1Y =      6123  #  RW float;
LC_PROP_DIMLIN_DP2X =      6124  #  RW float; def point 2
LC_PROP_DIMLIN_DP2Y =      6125  #  RW float;
LC_PROP_DIMLIN_TPX =       6126  #  RW float; text point
LC_PROP_DIMLIN_TPY =       6127  #  RW float;
LC_PROP_DIMLIN__MAX =      6139

#  Leader

LC_PROP_LEADER_STYLE =     6202  #  RW handle|string; Handle to dim style|Name of dim style
LC_PROP_LEADER_TEXT =      6203  #  RW string; 
LC_PROP_LEADER_ALIGN =     6204  #  RW int; text alignment (LC_LEADER_TLEFT and other)
LC_PROP_LEADER_TPX =       6205  #  RW float; text center X
LC_PROP_LEADER_TPY =       6206  #  RW float; text center Y
LC_PROP_LEADER_APX =       6207  #  RW float; arrow endpoint X
LC_PROP_LEADER_APY =       6208  #  RW float; arrow endpoint Y
LC_PROP_LEADER_P1X =       6209  #  R  float; land point X
LC_PROP_LEADER_P1Y =       6210  #  R  float; land point Y
LC_PROP_LEADER_P0X =       6211  #  R  float; start point X
LC_PROP_LEADER_P0Y =       6212  #  R  float; start point Y
LC_PROP_LEADER_LDIST =     6213  #  RW float; landing distance
LC_PROP_LEADER_VERT =      6214  #  RW bool; vertical line
LC_PROP_LEADER_CORNER =    6215  #  RW bool; attachment at corner
LC_PROP_LEADER_TBW =       6216  #  R  float; text box width
LC_PROP_LEADER_TBH =       6217  #  R  float; text box height

#  3D face

LC_PROP_FACE_X0 =          6281  #  RW float; 1st point X 
LC_PROP_FACE_Y0 =          6282  #  RW float; 1st point Y 
LC_PROP_FACE_Z0 =          6283  #  RW float; 1st point Z 
LC_PROP_FACE_X1 =          6284  #  RW float; 2nd point X 
LC_PROP_FACE_Y1 =          6285  #  RW float; 2nd point Y 
LC_PROP_FACE_Z1 =          6286  #  RW float; 2nd point Z 
LC_PROP_FACE_X2 =          6287  #  RW float; 3rd point X 
LC_PROP_FACE_Y2 =          6288  #  RW float; 3rd point Y 
LC_PROP_FACE_Z2 =          6289  #  RW float; 3rd point Z 
LC_PROP_FACE_X3 =          6290  #  RW float; 4th point X 
LC_PROP_FACE_Y3 =          6291  #  RW float; 4th point Y 
LC_PROP_FACE_Z3 =          6292  #  RW float; 4th point Z 
LC_PROP_FACE_EDGE1 =       6293  #  RW bool; 1st edge visibility
LC_PROP_FACE_EDGE2 =       6294  #  RW bool; 2nd edge visibility
LC_PROP_FACE_EDGE3 =       6295  #  RW bool; 3rd edge visibility
LC_PROP_FACE_EDGE4 =       6296  #  RW bool; 4th edge visibility
LC_PROP_FACE_EDGE =        6297  #  RW int; A combination of LC_FACE_EDGE1INVIS ... constants
LC_PROP_FACE_NPTS =        6298  #  RW int; Number of points, 3 or 4

#  Road Plan

LC_PROP_RPLAN_LEN =        6301  #  R  float;
LC_PROP_RPLAN_MARKARC =    6302  #  RW bool;
LC_PROP_RPLAN_MARKSIZE =   6303  #  RW float;
LC_PROP_RPLAN_NVERS =      6311  #  R  int;
LC_PROP_RPLAN_IVER =       6312  #  RW int;

#  Shape

LC_PROP_SHAPE_NENTS =      6341  #  R  int; Number of entities
LC_PROP_SHAPE_NPATHS =     6342  #  R  int; Number of paths

#  Triangulated Irregular Network (TIN) (also lcTIN_AddPoint and others)

LC_PROP_TIN_NAME =         7001  #  RW string; model name
LC_PROP_TIN_DESCR =        7002  #  RW string; comment
LC_PROP_TIN_FILENAME =     7003  #  R  string; model filename
LC_PROP_TIN_NPTYPES =      7004  #  R  int
LC_PROP_TIN_NPOINTS =      7005  #  R  int
LC_PROP_TIN_NTRIANS =      7006  #  R  int
LC_PROP_TIN_NBNDPTS =      7007  #  R  int; number of boundary points
LC_PROP_TIN_NISOLINES =    7008  #  R  int; number of isolines
LC_PROP_TIN_HASCFILL =     7009  #  R  bool; has color filling
LC_PROP_TIN_PNTIMGDIR =    7010  #  RW string; directory of points images
LC_PROP_TIN_XMIN =         7020  #  R  float; Xmin
LC_PROP_TIN_XMAX =         7021  #  R  float; Xmax
LC_PROP_TIN_YMIN =         7022  #  R  float; Ymin
LC_PROP_TIN_YMAX =         7023  #  R  float; Ymax
LC_PROP_TIN_ZMIN =         7024  #  R  float; Zmin
LC_PROP_TIN_ZMAX =         7025  #  R  float; Zmax
LC_PROP_TIN_DX =           7026  #  R  float; delta X
LC_PROP_TIN_DY =           7027  #  R  float; delta Y
LC_PROP_TIN_DZ =           7028  #  R  float; delta Z
LC_PROP_TIN_ISOBASE =      7031  #  RW float; isolines Z base
LC_PROP_TIN_ISOSTEP =      7032  #  RW float; isolines Z step
LC_PROP_TIN_ISOBOLD =      7033  #  RW int; isolines bold step
LC_PROP_TIN_ISOSPLINE =    7034  #  RW bool; spline isolines
LC_PROP_TIN_IMG_ZSTEP =    7041  #  RW float; Color Filling: Z step
LC_PROP_TIN_IMG_PSIZE =    7043  #  RW float; Color Filling: pixel size
LC_PROP_TIN_IMG_NX =       7044  #  R int; Color Filling: image width (pixels)
LC_PROP_TIN_IMG_NY =       7045  #  R int; Color Filling: image height (pixels)
LC_PROP_TIN_VIEWPT =       7051  #  RW bool; point
LC_PROP_TIN_VIEWPTN =      7052  #  RW bool; point type name
LC_PROP_TIN_VIEWPTI =      7053  #  RW bool; point index
LC_PROP_TIN_VIEWPTZ =      7054  #  RW bool; point Z
LC_PROP_TIN_VIEWTR =       7055  #  RW bool; triangle
LC_PROP_TIN_VIEWCF =       7056  #  RW bool; color filling
LC_PROP_TIN_VIEWTRI =      7058  #  RW bool; triangle's index
LC_PROP_TIN_VIEWTRV =      7059  #  RW bool; triangle's waterflow vector
LC_PROP_TIN_VIEWBND =      7060  #  RW bool; boundary
LC_PROP_TIN_VIEWBNDI =     7061  #  RW bool; boundary vertex index
LC_PROP_TIN_VIEWISO =      7062  #  RW bool; isolines
LC_PROP_TIN_VIEWISOH =     7063  #  RW bool; heights of isolines
LC_PROP_TIN_VIEWZ =        7065  #  RW bool; display Z near cursor
LC_PROP_VIEWTINTILES =     7066  #  RW bool; tiles
LC_PROP_VIEWTINCFIR =      7067  #  RW bool; color filling image rectangles
LC_PROP_TIN_COLTR =        7071  #  RW int; color of triangle outline
LC_PROP_TIN_COLTRI =       7072  #  RW int; color of triangle index
LC_PROP_TIN_COLTRV =       7073  #  RW int; color of triangle norm. vector
LC_PROP_TIN_COLISO =       7074  #  RW int; color of isolines
LC_PROP_TIN_COLISOB =      7075  #  RW int; color of bold isolines
LC_PROP_TIN_COLISOW =      7076  #  RW int; color of water isolines
LC_PROP_TIN_COLBND =       7077  #  RW int; color of boundary
LC_PROP_TIN_COLBNDP =      7078  #  RW int; color of boundary point
LC_PROP_TIN_COLTRF =       7079  #  RW int; color of triangle filling (used in step triangulation)
LC_PROP_TIN_COLFRONT0 =    7080  #  RW int; color of start front line (used in step triangulation)
LC_PROP_TIN_COLFRONT =     7081  #  RW int; color of front line (used in step triangulation)
LC_PROP_TIN_LX_PRJNAME =   7091  #  RW string; LandXML project name
LC_PROP_TIN_LX_APPNAME =   7092  #  RW string; LandXML application name
LC_PROP_TIN_LX_DESCR =     7093  #  RW string; LandXML description
LC_PROP_TIN_LX_MANUF =     7094  #  RW string; LandXML manufacturer
LC_PROP_TIN_LX_VER =       7095  #  RW string; LandXML version
LC_PROP_TIN_LX_URL =       7096  #  RW string; LandXML URL
LC_PROP_TIN_LX_TIME =      7097  #  RW string; LandXML time
LC_PROP_ENT__MAX =         9999    #  from LC_PROP_ENT__MIN 5001

#  also see LC_PROP_TINPTYPE_NAME and others


#  Polyline Vertex 

LC_PROP_VER__MIN =         10001
LC_PROP_VER_X =            10001  #  RW float; Coordinate X~
LC_PROP_VER_Y =            10002  #  RW float; Coordinate Y~
LC_PROP_VER_Z =            10003  #  RW float; Coordinate Y~
LC_PROP_VER_FIX =          10006  #  RW bool; "Fixed vertex" flag (for LC_PLFIT_LINQUAD). 
LC_PROP_VER_RADIUS =       10007  #  RW float; Radius value~
LC_PROP_VER_WEIGHT =       10008  #  RW float; point weight
LC_PROP_VER_INDEX =        10009  #  R  int; index of the vertex 
LC_PROP_VER_FIRST =        10010  #  R  bool; TRUE if first vertex
LC_PROP_VER_LAST =         10011  #  R  bool; TRUE if last vertex

#  for segment from current to next vertex

LC_PROP_VER_W0 =           10012  #  RW float; Start width
LC_PROP_VER_W1 =           10013  #  RW float; End width
LC_PROP_VER_SEGDX =        10014  #  RW float; dx
LC_PROP_VER_SEGDY =        10015  #  RW float; dy
LC_PROP_VER_SEGANG =       10016  #  RW float; angle
LC_PROP_VER_SEGLEN =       10017  #  RW float; length
LC_PROP_VER_BULGE =        10021  #  RW float; Bulge value
LC_PROP_VER_SEGARCANG =    10022  #  RW float; included angle of arc segment
LC_PROP_VER_SEGARCH =      10023  #  RW float; height of arc segment
LC_PROP_VER_SEGARCLEN =    10024  #  R  float; length of arc segment 
LC_PROP_VER_SEGARCRAD =    10025  #  R  float; radius of arc segment 
LC_PROP_VER__MAX =         10040

#  RoadPlan Vertex 

LC_PROP_RPVER__MIN =       10041   
LC_PROP_RPVER_X =          10041  #  R  float;
LC_PROP_RPVER_Y =          10042  #  R  float;
LC_PROP_RPVER_ANGLE =      10043  #  R  float;
LC_PROP_RPVER_DIRANG =     10044  #  R  float;
LC_PROP_RPVER_R =          10045  #  R  float;
LC_PROP_RPVER_L1 =         10046  #  R  float;
LC_PROP_RPVER_L2 =         10047  #  R  float;
LC_PROP_RPVER_ANGL1 =      10048  #  R  float;
LC_PROP_RPVER_ANGARC =     10049  #  R  float;
LC_PROP_RPVER_ANGL2 =      10050  #  R  float;
LC_PROP_RPVER_BISEC =      10051  #  R  float;
LC_PROP_RPVER_DOMER =      10052  #  R  float;
LC_PROP_RPVER_ARCLEN =     10053  #  R  float;
LC_PROP_RPVER_CURLEN =     10054  #  R  float;
LC_PROP_RPVER_LINE1 =      10055  #  R  float;
LC_PROP_RPVER_T1 =         10056  #  R  float;
LC_PROP_RPVER_T2 =         10057  #  R  float;
LC_PROP_RPVER_LINE2 =      10058  #  R  float;
LC_PROP_RPVER_DIST1 =      10059  #  R  float;
LC_PROP_RPVER_DIST2 =      10060  #  R  float;
LC_PROP_RPVER__MAX =       10070  
LC_PROP_XDATA__MIN =       10901  
LC_PROP_XDATA_BOOL =       10901  #  RW bool;
LC_PROP_XDATA_INT =        10902  #  RW int;
LC_PROP_XDATA_FLOAT =      10903  #  RW float;
LC_PROP_XDATA_STR =        10907  #  RW string;
LC_PROP_XDATA__MAX =       10910  

#  Other

LC_PROP_OTHER__MIN =       11001
LC_PROP_CMDWND_ENABLE =    11001    #  RW bool; Command window is enabled
LC_PROP_PROPWND_ENABLE =   11002    #  RW bool; Properties window is enabled
LC_PROP_PROPWND_DIVCOEF =  11003    #  RW float; ratio of the name/value columns widths
LC_PROP_OTHER__MAX =       11999

#  event parameters

LC_PROP_EVENT__MIN =       12001
LC_PROP_EVENT_TYPE =       12001   #  R  int; event type LC_EVENT_HELP and others
LC_PROP_EVENT_APPPRM1 =    12002   #  R  int;    application parameter1
LC_PROP_EVENT_APPPRM2 =    12003   #  R  handle; application parameter2
LC_PROP_EVENT_WND =        12004   #  R  handle; Window 
LC_PROP_EVENT_DRW =        12005   #  R  handle; Drawing
LC_PROP_EVENT_BLOCK =      12006   #  R  handle; Visible block
LC_PROP_EVENT_ENTITY =     12007   #  R  handle; entity's handle
LC_PROP_EVENT_ENT =        12007   #     LC_PROP_EVENT_ENTITY
LC_PROP_EVENT_HCMD =       12008   #  R  handle; custom command object
LC_PROP_EVENT_HOBJ =       12008   #     LC_PROP_EVENT_HCMD
LC_PROP_EVENT_HDC =        12009   #  R  handle; device context (for LC_EVENT_PAINT)
LC_PROP_EVENT_MODE =       12010   #  RW int;
LC_PROP_EVENT_INT1 =       12021   #  RW int;
LC_PROP_EVENT_INT2 =       12022   #  RW int;
LC_PROP_EVENT_INT3 =       12023   #  RW int;
LC_PROP_EVENT_INT4 =       12024   #  RW int;
LC_PROP_EVENT_INT5 =       12025   #  RW int;
LC_PROP_EVENT_INT6 =       12026   #  RW int;
LC_PROP_EVENT_FLOAT1 =     12031   #  RW float;
LC_PROP_EVENT_FLOAT2 =     12032   #  RW float;
LC_PROP_EVENT_FLOAT3 =     12033   #  RW float;
LC_PROP_EVENT_FLOAT4 =     12034   #  RW float;
LC_PROP_EVENT_FLOAT5 =     12035   #  RW float;
LC_PROP_EVENT_FLOAT6 =     12036   #  RW float;
LC_PROP_EVENT_STR1 =       12041   #  RW string;
LC_PROP_EVENT_STR2 =       12042   #  RW string;
LC_PROP_EVENT_STR3 =       12043   #  RW string;
LC_PROP_EVENT__MAX =       12999

#  events

LC_EVENT_HELP =            101
LC_EVENT_PAINT =           102
LC_EVENT_PAINTBG =         124
LC_EVENT_WNDVIEW =         103
LC_EVENT_MOUSEMOVE =       105
LC_EVENT_LBDOWN =          106
LC_EVENT_LBUP =            107
LC_EVENT_LBDBLCLK =        108
LC_EVENT_RBDOWN =          109 
LC_EVENT_RBUP =            110
LC_EVENT_KEYDOWN =         111
LC_EVENT_VIEWBLOCK =       112
LC_EVENT_EXTENTS =         113
LC_EVENT_SNAP =            114
LC_EVENT_MAGNIFIER =       115
LC_EVENT_NAVIGATOR =       116
LC_EVENT_CMDINWND =        117
LC_EVENT_GRID =            118
LC_EVENT_OSNAP =           119
LC_EVENT_PTRACK =          120
LC_EVENT_ORTHO =           121
LC_EVENT_FILETAB =         122
LC_EVENT_WAITPOINT =       123
LC_EVENT_FILE =            131
LC_EVENT_ADDENTITY =       132
LC_EVENT_WNDPROP =         133
LC_EVENT_DRWPROP =         134
LC_EVENT_ENTPROP =         135
LC_EVENT_ENTMOVE =         136
LC_EVENT_ENTSCALE =        137
LC_EVENT_ENTROTATE =       138
LC_EVENT_ENTMIRROR =       139
LC_EVENT_ENTERASE =        140
LC_EVENT_DRAWIMAGE =       141
LC_EVENT_SELECT =          145
LC_EVENT_PICKENT =         146
LC_EVENT_ADDSTR =          147
LC_EVENT_ADDCMD =          148
LC_EVENT_CCMD =            149
LC_EVENT_TIN =             150
LC_EVENT_DRWFILEEXT =      151
LC_EVENT_DRWPREVIEW =      152
LC_EVENT_DRWLOAD =         153
LC_EVENT_DRWSAVE =         154
LC_EVENT_GRIPMOVE =        155
LC_EVENT_GRIPDRAG =        156
LC_EVENT_DIRTY =           157    #  undoc
LC_EVENT_SELENT1 =         161    #  undoc
LC_EVENT_SELENTS =         162    #  undoc
LC_EVENT_GRIPPAINT =       165
LC_EVENT_DRAWCURSOR =      166
LC_EVENT_RULERCORNER =     167
LC_EVENT_WNDTAB =          171
LC_EVENT_CMD1 =            212    #  undoc
LC_EVENT_LAYERS =          303    #  undoc

#  parameter LC_PROP_EVENT_MODE of LC_EVENT_CCMD

LC_CCMD_CREATE =      1
LC_CCMD_DESTROY =     2
LC_CCMD_START =       3
LC_CCMD_FINISH =      4
LC_CCMD_LBDOWN =      5
LC_CCMD_LBUP =        6
LC_CCMD_RBDOWN =      7
LC_CCMD_RBUP =        8
LC_CCMD_MOUSEMOVE =   9
LC_CCMD_PAINT =       10
LC_CCMD_SNAP =        11

#  *****************************************************************************


#  *****************************************************************************


# 


#                         LITECAD FUNCTIONS


# 


#  *****************************************************************************


#  *****************************************************************************

lcEventSetProc = litecad.lcEventSetProc
lcEventSetProc.restype = None
lcEventSetProc.argtypes = [ct.c_int, ct.c_void_p, ct.c_int, wt.HANDLE]

lcEventReturnCode = litecad.lcEventReturnCode
lcEventReturnCode.restype = None
lcEventReturnCode.argtypes = [ct.c_int]

lcEventsEnable = litecad.lcEventsEnable
lcEventsEnable.restype = wt.BOOL
lcEventsEnable.argtypes = [wt.BOOL]


#  Initialization

lcInitialize = litecad.lcInitialize
lcInitialize.restype = wt.BOOL

lcUninitialize = litecad.lcUninitialize
lcUninitialize.restype = wt.BOOL
lcUninitialize.argtypes = [wt.BOOL]


#  GUI strings

lcStrAdd = litecad.lcStrAdd
lcStrAdd.restype = wt.BOOL
lcStrAdd.argtypes = [wt.LPCWSTR, wt.LPCWSTR]

lcStrSet = litecad.lcStrSet
lcStrSet.restype = wt.BOOL
lcStrSet.argtypes = [wt.LPCWSTR, wt.LPCWSTR]

lcStrGet = litecad.lcStrGet
lcStrGet.restype = wt.LPCWSTR
lcStrGet.argtypes = [wt.LPCWSTR]

lcStrFileLoad = litecad.lcStrFileLoad
lcStrFileLoad.restype = wt.BOOL
lcStrFileLoad.argtypes = [wt.LPCWSTR]

lcStrFileSave = litecad.lcStrFileSave
lcStrFileSave.restype = wt.BOOL
lcStrFileSave.argtypes = [wt.LPCWSTR, wt.LPCWSTR]


#  Objects properties

lcPropGetBool = litecad.lcPropGetBool
lcPropGetBool.restype = wt.BOOL
lcPropGetBool.argtypes = [wt.HANDLE, ct.c_int]

lcPropGetInt = litecad.lcPropGetInt
lcPropGetInt.restype = ct.c_int
lcPropGetInt.argtypes = [wt.HANDLE, ct.c_int]

lcPropGetFloat = litecad.lcPropGetFloat
lcPropGetFloat.restype = ct.c_double
lcPropGetFloat.argtypes = [wt.HANDLE, ct.c_int]

lcPropGetStr = litecad.lcPropGetStr
lcPropGetStr.restype = wt.LPCWSTR
lcPropGetStr.argtypes = [wt.HANDLE, ct.c_int]

lcPropGetStrA = litecad.lcPropGetStrA
lcPropGetStrA.restype = ct.c_int
lcPropGetStrA.argtypes = [wt.HANDLE, ct.c_int, ct.c_char_p, ct.c_int]

lcPropGetStr2 = litecad.lcPropGetStr2
lcPropGetStr2.restype = ct.c_int
lcPropGetStr2.argtypes = [wt.HANDLE, ct.c_int]

lcPropGetChar = litecad.lcPropGetChar
lcPropGetChar.restype = ct.c_int
lcPropGetChar.argtypes = [ct.c_int]

lcPropGetHandle = litecad.lcPropGetHandle
lcPropGetHandle.restype = wt.HANDLE
lcPropGetHandle.argtypes = [wt.HANDLE, ct.c_int]

lcPropPutBool = litecad.lcPropPutBool
lcPropPutBool.restype = wt.BOOL
lcPropPutBool.argtypes = [wt.HANDLE, ct.c_int, wt.BOOL]

lcPropPutInt = litecad.lcPropPutInt
lcPropPutInt.restype = wt.BOOL
lcPropPutInt.argtypes = [wt.HANDLE, ct.c_int, ct.c_int]

lcPropPutFloat = litecad.lcPropPutFloat
lcPropPutFloat.restype = wt.BOOL
lcPropPutFloat.argtypes = [wt.HANDLE, ct.c_int, ct.c_double]

lcPropPutStr = litecad.lcPropPutStr
lcPropPutStr.restype = wt.BOOL
lcPropPutStr.argtypes = [wt.HANDLE, ct.c_int, wt.LPCWSTR]

lcPropPutHandle = litecad.lcPropPutHandle
lcPropPutHandle.restype = wt.BOOL
lcPropPutHandle.argtypes = [wt.HANDLE, ct.c_int, wt.HANDLE]


#  Design window

lcCreateWindow = litecad.lcCreateWindow
lcCreateWindow.restype = wt.HANDLE
lcCreateWindow.argtypes = [wt.HWND, ct.c_int]

lcDeleteWindow = litecad.lcDeleteWindow
lcDeleteWindow.restype = wt.BOOL
lcDeleteWindow.argtypes = [wt.HANDLE]

lcWndOnClose = litecad.lcWndOnClose
lcWndOnClose.restype = wt.BOOL
lcWndOnClose.argtypes = [wt.HANDLE]

lcWndExeCommand = litecad.lcWndExeCommand
lcWndExeCommand.restype = wt.BOOL
lcWndExeCommand.argtypes = [wt.HANDLE, ct.c_int, ct.c_int]

lcWndResize = litecad.lcWndResize
lcWndResize.restype = wt.BOOL
lcWndResize.argtypes = [wt.HANDLE, ct.c_int, ct.c_int, ct.c_int, ct.c_int]

lcWndRedraw = litecad.lcWndRedraw
lcWndRedraw.restype = wt.BOOL
lcWndRedraw.argtypes = [wt.HANDLE]

lcWndRedrawAuto = litecad.lcWndRedrawAuto
lcWndRedrawAuto.restype = wt.BOOL
lcWndRedrawAuto.argtypes = [wt.HANDLE, ct.c_int, ct.c_void_p]

lcWndSetFocus = litecad.lcWndSetFocus
lcWndSetFocus.restype = wt.BOOL
lcWndSetFocus.argtypes = [wt.HANDLE]

lcWndSetExtents = litecad.lcWndSetExtents
lcWndSetExtents.restype = wt.BOOL
lcWndSetExtents.argtypes = [wt.HANDLE, ct.c_double, ct.c_double, ct.c_double, ct.c_double]

lcWndSetBlock = litecad.lcWndSetBlock
lcWndSetBlock.restype = wt.BOOL
lcWndSetBlock.argtypes = [wt.HANDLE, wt.HANDLE]

lcWndSetProps = litecad.lcWndSetProps
lcWndSetProps.restype = wt.BOOL
lcWndSetProps.argtypes = [wt.HANDLE, wt.HANDLE]

lcWndSetCmdwin = litecad.lcWndSetCmdwin
lcWndSetCmdwin.restype = wt.BOOL
lcWndSetCmdwin.argtypes = [wt.HANDLE, wt.HANDLE]

lcWndSetBasePoint = litecad.lcWndSetBasePoint
lcWndSetBasePoint.restype = wt.BOOL
lcWndSetBasePoint.argtypes = [wt.HANDLE, wt.BOOL, ct.c_double, ct.c_double]

lcWndEmulator = litecad.lcWndEmulator
lcWndEmulator.restype = wt.BOOL
lcWndEmulator.argtypes = [wt.HANDLE, ct.c_int]

lcWndMagnifier = litecad.lcWndMagnifier
lcWndMagnifier.restype = wt.BOOL
lcWndMagnifier.argtypes = [wt.HANDLE, wt.BOOL, ct.c_int, ct.c_int, ct.c_int, ct.c_int]

lcWndHoverText = litecad.lcWndHoverText
lcWndHoverText.restype = wt.BOOL
lcWndHoverText.argtypes = [wt.HANDLE, wt.LPCWSTR, ct.c_int, ct.c_int, ct.c_int]

lcWndMessage = litecad.lcWndMessage
lcWndMessage.restype = ct.c_int
lcWndMessage.argtypes = [wt.HANDLE, wt.LPCWSTR, ct.c_int]

lcWndWaitPoint = litecad.lcWndWaitPoint
lcWndWaitPoint.restype = wt.BOOL
lcWndWaitPoint.argtypes = [wt.HANDLE, wt.LPCWSTR, ct.POINTER(ct.c_double), ct.POINTER(ct.c_double)]

lcWndWaitPoint2 = litecad.lcWndWaitPoint2
lcWndWaitPoint2.restype = wt.BOOL
lcWndWaitPoint2.argtypes = [wt.HANDLE, wt.LPCWSTR, ct.POINTER(ct.c_double), ct.POINTER(ct.c_double), ct.c_void_p, ct.c_int]

lcWndInputStr = litecad.lcWndInputStr
lcWndInputStr.restype = wt.BOOL
lcWndInputStr.argtypes = [wt.HANDLE]

lcWndUpdate = litecad.lcWndUpdate
lcWndUpdate.restype = wt.BOOL
lcWndUpdate.argtypes = [wt.HANDLE, ct.c_int]

lcWndDrwAdd = litecad.lcWndDrwAdd
lcWndDrwAdd.restype = wt.HANDLE
lcWndDrwAdd.argtypes = [wt.HANDLE, wt.LPCWSTR]

lcWndDrwDelete = litecad.lcWndDrwDelete
lcWndDrwDelete.restype = wt.BOOL
lcWndDrwDelete.argtypes = [wt.HANDLE, wt.HANDLE]

lcWndDrwGet = litecad.lcWndDrwGet
lcWndDrwGet.restype = wt.HANDLE
lcWndDrwGet.argtypes = [wt.HANDLE, ct.c_int]


#  zoom

lcWndZoomRect = litecad.lcWndZoomRect
lcWndZoomRect.restype = wt.BOOL
lcWndZoomRect.argtypes = [wt.HANDLE, ct.c_double, ct.c_double, ct.c_double, ct.c_double]

lcWndZoomScale = litecad.lcWndZoomScale
lcWndZoomScale.restype = wt.BOOL
lcWndZoomScale.argtypes = [wt.HANDLE, ct.c_double]

lcWndZoomMove = litecad.lcWndZoomMove
lcWndZoomMove.restype = wt.BOOL
lcWndZoomMove.argtypes = [wt.HANDLE, ct.c_double, ct.c_double]

lcWndZoomPos = litecad.lcWndZoomPos
lcWndZoomPos.restype = wt.BOOL
lcWndZoomPos.argtypes = [wt.HANDLE, ct.c_double, ct.c_double, ct.c_double]

lcWndZoomEnt = litecad.lcWndZoomEnt
lcWndZoomEnt.restype = wt.BOOL
lcWndZoomEnt.argtypes = [wt.HANDLE, wt.HANDLE, ct.c_double]


#  coordinates

lcWndGetCursorCoord = litecad.lcWndGetCursorCoord
lcWndGetCursorCoord.restype = wt.BOOL
lcWndGetCursorCoord.argtypes = [wt.HANDLE, ct.POINTER(ct.c_int), ct.POINTER(ct.c_int), ct.POINTER(ct.c_double), ct.POINTER(ct.c_double)]

lcCoordDrwToWnd = litecad.lcCoordDrwToWnd
lcCoordDrwToWnd.restype = wt.BOOL
lcCoordDrwToWnd.argtypes = [wt.HANDLE, ct.c_double, ct.c_double, ct.POINTER(ct.c_int), ct.POINTER(ct.c_int)]

lcCoordWndToDrw = litecad.lcCoordWndToDrw
lcCoordWndToDrw.restype = wt.BOOL
lcCoordWndToDrw.argtypes = [wt.HANDLE, ct.c_int, ct.c_int, ct.POINTER(ct.c_double), ct.POINTER(ct.c_double)]

lcWndCoordFromDrw = litecad.lcWndCoordFromDrw
lcWndCoordFromDrw.restype = wt.BOOL
lcWndCoordFromDrw.argtypes = [wt.HANDLE, ct.c_double, ct.c_double, ct.POINTER(ct.c_int), ct.POINTER(ct.c_int)]

lcWndCoordToDrw = litecad.lcWndCoordToDrw
lcWndCoordToDrw.restype = wt.BOOL
lcWndCoordToDrw.argtypes = [wt.HANDLE, ct.c_int, ct.c_int, ct.POINTER(ct.c_double), ct.POINTER(ct.c_double)]


#  retrieve entities

lcWndGetEntByPoint = litecad.lcWndGetEntByPoint
lcWndGetEntByPoint.restype = wt.HANDLE
lcWndGetEntByPoint.argtypes = [wt.HANDLE, ct.c_int, ct.c_int]

lcWndGetEntByPoint2 = litecad.lcWndGetEntByPoint2
lcWndGetEntByPoint2.restype = wt.HANDLE
lcWndGetEntByPoint2.argtypes = [wt.HANDLE, ct.c_double, ct.c_double, ct.c_double]

lcWndGetEntsByPoint = litecad.lcWndGetEntsByPoint
lcWndGetEntsByPoint.restype = ct.c_int
lcWndGetEntsByPoint.argtypes = [wt.HANDLE, ct.c_int, ct.c_int, ct.c_int]

lcWndGetEntsByRect = litecad.lcWndGetEntsByRect
lcWndGetEntsByRect.restype = ct.c_int
lcWndGetEntsByRect.argtypes = [wt.HANDLE, ct.c_double, ct.c_double, ct.c_double, ct.c_double, wt.BOOL, ct.c_int]

lcWndGetEntity = litecad.lcWndGetEntity
lcWndGetEntity.restype = wt.HANDLE
lcWndGetEntity.argtypes = [ct.c_int]

lcWndGetEntByID = litecad.lcWndGetEntByID
lcWndGetEntByID.restype = wt.HANDLE
lcWndGetEntByID.argtypes = [wt.HANDLE, ct.c_int]

lcWndGetEntByIDH = litecad.lcWndGetEntByIDH
lcWndGetEntByIDH.restype = wt.HANDLE
lcWndGetEntByIDH.argtypes = [wt.HANDLE, wt.LPCWSTR]

lcWndGetEntByKey = litecad.lcWndGetEntByKey
lcWndGetEntByKey.restype = wt.HANDLE
lcWndGetEntByKey.argtypes = [wt.HANDLE, ct.c_int]

lcWndPickEnt = litecad.lcWndPickEnt
lcWndPickEnt.restype = ct.c_int
lcWndPickEnt.argtypes = [wt.HANDLE, wt.LPCWSTR, wt.LPCWSTR]


#  Font functions

lcFontGetFirst = litecad.lcFontGetFirst
lcFontGetFirst.restype = wt.HANDLE

lcFontGetNext = litecad.lcFontGetNext
lcFontGetNext.restype = wt.HANDLE
lcFontGetNext.argtypes = [wt.HANDLE]

lcFontAddRes = litecad.lcFontAddRes
lcFontAddRes.restype = wt.HANDLE
lcFontAddRes.argtypes = [wt.LPCWSTR, wt.HANDLE, ct.c_int]

lcFontAddFile = litecad.lcFontAddFile
lcFontAddFile.restype = wt.HANDLE
lcFontAddFile.argtypes = [wt.LPCWSTR, wt.LPCWSTR, ct.POINTER(ct.c_wchar)]

lcFontAddBin = litecad.lcFontAddBin
lcFontAddBin.restype = wt.HANDLE
lcFontAddBin.argtypes = [wt.LPCWSTR, wt.HANDLE]

lcFontGetChar = litecad.lcFontGetChar
lcFontGetChar.restype = wt.HANDLE
lcFontGetChar.argtypes = [wt.HANDLE, ct.c_int]

lcFontGetName = litecad.lcFontGetName
lcFontGetName.restype = wt.LPCWSTR
lcFontGetName.argtypes = [wt.LPCWSTR]


#  Progress indicator

lcProgressCreate = litecad.lcProgressCreate
lcProgressCreate.restype = wt.BOOL
lcProgressCreate.argtypes = [wt.HANDLE, ct.c_int, ct.c_int, wt.LPCWSTR]

lcProgressSetText = litecad.lcProgressSetText
lcProgressSetText.restype = wt.BOOL
lcProgressSetText.argtypes = [wt.LPCWSTR]

lcProgressStart = litecad.lcProgressStart
lcProgressStart.restype = wt.BOOL
lcProgressStart.argtypes = [ct.c_int, ct.c_int]

lcProgressSetPos = litecad.lcProgressSetPos
lcProgressSetPos.restype = wt.BOOL
lcProgressSetPos.argtypes = [ct.c_int]

lcProgressInc = litecad.lcProgressInc
lcProgressInc.restype = wt.BOOL

lcProgressDelete = litecad.lcProgressDelete
lcProgressDelete.restype = wt.BOOL


#  Quadrangle point coordinates

lcQuadCreate = litecad.lcQuadCreate
lcQuadCreate.restype = wt.HANDLE

lcQuadDelete = litecad.lcQuadDelete
lcQuadDelete.restype = wt.BOOL
lcQuadDelete.argtypes = [wt.HANDLE]

lcQuadSet = litecad.lcQuadSet
lcQuadSet.restype = wt.BOOL
lcQuadSet.argtypes = [wt.HANDLE, ct.c_double, ct.c_double, ct.c_double, ct.c_double, ct.c_double, ct.c_double, ct.c_double, ct.c_double]

lcQuadTransXYtoUV = litecad.lcQuadTransXYtoUV
lcQuadTransXYtoUV.restype = wt.BOOL
lcQuadTransXYtoUV.argtypes = [wt.HANDLE, ct.c_double, ct.c_double, ct.POINTER(ct.c_double), ct.POINTER(ct.c_double)]

lcQuadTransUVtoXY = litecad.lcQuadTransUVtoXY
lcQuadTransUVtoXY.restype = wt.BOOL
lcQuadTransUVtoXY.argtypes = [wt.HANDLE, ct.c_double, ct.c_double, ct.POINTER(ct.c_double), ct.POINTER(ct.c_double)]

lcQuadContains = litecad.lcQuadContains
lcQuadContains.restype = wt.BOOL
lcQuadContains.argtypes = [wt.HANDLE, ct.c_double, ct.c_double]


#  Array of Quadrangles

lcGridCreate = litecad.lcGridCreate
lcGridCreate.restype = wt.HANDLE

lcGridDelete = litecad.lcGridDelete
lcGridDelete.restype = wt.BOOL
lcGridDelete.argtypes = [wt.HANDLE]

lcGridSet = litecad.lcGridSet
lcGridSet.restype = wt.BOOL
lcGridSet.argtypes = [wt.HANDLE, ct.c_double, ct.c_double, ct.c_double, ct.c_double, ct.c_int, ct.c_int]

lcGridSetDest = litecad.lcGridSetDest
lcGridSetDest.restype = wt.BOOL
lcGridSetDest.argtypes = [wt.HANDLE, ct.c_int, ct.c_int, ct.c_double, ct.c_double]

lcGridUpdate = litecad.lcGridUpdate
lcGridUpdate.restype = wt.BOOL
lcGridUpdate.argtypes = [wt.HANDLE]

lcGridTrans = litecad.lcGridTrans
lcGridTrans.restype = wt.BOOL
lcGridTrans.argtypes = [wt.HANDLE, ct.c_double, ct.c_double, ct.POINTER(ct.c_double), ct.POINTER(ct.c_double)]

lcGridGetNode = litecad.lcGridGetNode
lcGridGetNode.restype = wt.BOOL
lcGridGetNode.argtypes = [wt.HANDLE, wt.BOOL, ct.c_int, ct.c_int, ct.POINTER(ct.c_double), ct.POINTER(ct.c_double)]

lcGridGetCell = litecad.lcGridGetCell
lcGridGetCell.restype = wt.BOOL
lcGridGetCell.argtypes = [wt.HANDLE, ct.c_double, ct.c_double, ct.POINTER(ct.c_int), ct.POINTER(ct.c_int)]

lcGridSetView = litecad.lcGridSetView
lcGridSetView.restype = wt.BOOL
lcGridSetView.argtypes = [wt.HANDLE, ct.c_int, wt.HANDLE, wt.COLORREF, wt.COLORREF]


#  Command Window

lcCreateCmdwin = litecad.lcCreateCmdwin
lcCreateCmdwin.restype = wt.HANDLE
lcCreateCmdwin.argtypes = [wt.HWND, ct.c_int, ct.c_int, ct.c_int, ct.c_int]

lcCmdwinResize = litecad.lcCmdwinResize
lcCmdwinResize.restype = wt.BOOL
lcCmdwinResize.argtypes = [wt.HANDLE, ct.c_int, ct.c_int, ct.c_int, ct.c_int]

lcCmdwinUpdate = litecad.lcCmdwinUpdate
lcCmdwinUpdate.restype = wt.BOOL
lcCmdwinUpdate.argtypes = [wt.HANDLE]


#  Properties Window

lcCreateProps = litecad.lcCreateProps
lcCreateProps.restype = wt.HANDLE
lcCreateProps.argtypes = [wt.HWND, ct.c_int]

lcDeleteProps = litecad.lcDeleteProps
lcDeleteProps.restype = wt.BOOL
lcDeleteProps.argtypes = [wt.HANDLE]

lcPropsResize = litecad.lcPropsResize
lcPropsResize.restype = wt.BOOL
lcPropsResize.argtypes = [wt.HANDLE, ct.c_int, ct.c_int, ct.c_int, ct.c_int]

lcPropsUpdate = litecad.lcPropsUpdate
lcPropsUpdate.restype = wt.BOOL
lcPropsUpdate.argtypes = [wt.HANDLE, wt.BOOL]


#  Status Bar

lcCreateStatbar = litecad.lcCreateStatbar
lcCreateStatbar.restype = wt.HANDLE
lcCreateStatbar.argtypes = [wt.HWND]

lcDeleteStatbar = litecad.lcDeleteStatbar
lcDeleteStatbar.restype = wt.BOOL
lcDeleteStatbar.argtypes = [wt.HANDLE]

lcStatbarResize = litecad.lcStatbarResize
lcStatbarResize.restype = wt.BOOL
lcStatbarResize.argtypes = [wt.HANDLE, ct.c_int, ct.c_int, ct.c_int, ct.c_int]

lcStatbarCell = litecad.lcStatbarCell
lcStatbarCell.restype = wt.BOOL
lcStatbarCell.argtypes = [wt.HANDLE, ct.c_int, ct.c_int]

lcStatbarText = litecad.lcStatbarText
lcStatbarText.restype = wt.BOOL
lcStatbarText.argtypes = [wt.HANDLE, ct.c_int, wt.LPCWSTR]

lcStatbarRedraw = litecad.lcStatbarRedraw
lcStatbarRedraw.restype = wt.BOOL
lcStatbarRedraw.argtypes = [wt.HANDLE]


#  utility functions

lcDgGetValue = litecad.lcDgGetValue
lcDgGetValue.restype = wt.BOOL
lcDgGetValue.argtypes = [wt.HANDLE, ct.c_int, ct.c_int, wt.LPCWSTR, wt.LPCWSTR]

lcHelp = litecad.lcHelp
lcHelp.restype = wt.BOOL
lcHelp.argtypes = [wt.LPCWSTR]

lcGetPolarPoint = litecad.lcGetPolarPoint
lcGetPolarPoint.restype = None
lcGetPolarPoint.argtypes = [ct.c_double, ct.c_double, ct.c_double, ct.c_double, ct.POINTER(ct.c_double), ct.POINTER(ct.c_double)]

lcGetPolarPrm = litecad.lcGetPolarPrm
lcGetPolarPrm.restype = None
lcGetPolarPrm.argtypes = [ct.c_double, ct.c_double, ct.c_double, ct.c_double, ct.POINTER(ct.c_double), ct.POINTER(ct.c_double)]

lcGetClientSize = litecad.lcGetClientSize
lcGetClientSize.restype = wt.BOOL
lcGetClientSize.argtypes = [wt.HWND, ct.POINTER(ct.c_int), ct.POINTER(ct.c_int)]

lcGetErrorCode = litecad.lcGetErrorCode
lcGetErrorCode.restype = ct.c_int

lcGetErrorStr = litecad.lcGetErrorStr
lcGetErrorStr.restype = wt.LPCWSTR

lcGetStr = litecad.lcGetStr
lcGetStr.restype = wt.BOOL
lcGetStr.argtypes = [ct.c_int]

lcGetDrwXData = litecad.lcGetDrwXData
lcGetDrwXData.restype = wt.BOOL
lcGetDrwXData.argtypes = [wt.LPCWSTR]

lcGetDrwPreview = litecad.lcGetDrwPreview
lcGetDrwPreview.restype = ct.c_int
lcGetDrwPreview.argtypes = [wt.LPCWSTR, ct.c_void_p]

lcFilletSetLines = litecad.lcFilletSetLines
lcFilletSetLines.restype = wt.BOOL
lcFilletSetLines.argtypes = [ct.c_double, ct.c_double, ct.c_double, ct.c_double, ct.c_double, ct.c_double, ct.c_double, ct.c_double]

lcFillet = litecad.lcFillet
lcFillet.restype = wt.BOOL
lcFillet.argtypes = [ct.c_double, ct.c_double, ct.c_double]

lcFilletGetPoint = litecad.lcFilletGetPoint
lcFilletGetPoint.restype = wt.BOOL
lcFilletGetPoint.argtypes = [ct.c_int, ct.POINTER(ct.c_double), ct.POINTER(ct.c_double)]

lcFileToStrA = litecad.lcFileToStrA
lcFileToStrA.restype = ct.c_int
lcFileToStrA.argtypes = [wt.LPCWSTR, ct.c_char_p]


#  Custom command interface

lcCreateCommand = litecad.lcCreateCommand
lcCreateCommand.restype = wt.HANDLE
lcCreateCommand.argtypes = [wt.HANDLE, ct.c_int, wt.LPCWSTR]

lcCmdExit = litecad.lcCmdExit
lcCmdExit.restype = wt.BOOL
lcCmdExit.argtypes = [wt.HANDLE]

lcCmdCursorText = litecad.lcCmdCursorText
lcCmdCursorText.restype = wt.BOOL
lcCmdCursorText.argtypes = [wt.HANDLE, wt.LPCWSTR]

lcCmdMessage = litecad.lcCmdMessage
lcCmdMessage.restype = ct.c_int
lcCmdMessage.argtypes = [wt.HANDLE, wt.LPCWSTR, ct.c_int]

lcCmdResetLastPt = litecad.lcCmdResetLastPt
lcCmdResetLastPt.restype = wt.BOOL
lcCmdResetLastPt.argtypes = [wt.HANDLE]

lcTIS_InitLibrary = litecad.lcTIS_InitLibrary
lcTIS_InitLibrary.restype = wt.BOOL
lcTIS_InitLibrary.argtypes = [wt.LPCWSTR, wt.BOOL]

lcTIS_CloseLibrary = litecad.lcTIS_CloseLibrary
lcTIS_CloseLibrary.restype = wt.BOOL

lcCameraConnect = litecad.lcCameraConnect
lcCameraConnect.restype = wt.BOOL
lcCameraConnect.argtypes = [wt.LPCWSTR]

lcCameraDisconnect = litecad.lcCameraDisconnect
lcCameraDisconnect.restype = wt.BOOL

lcCameraShot = litecad.lcCameraShot
lcCameraShot.restype = wt.BOOL


# -----------------------------------------------------------------------------


#  Drawing


# -----------------------------------------------------------------------------

lcCreateDrawing = litecad.lcCreateDrawing
lcCreateDrawing.restype = wt.HANDLE

lcDeleteDrawing = litecad.lcDeleteDrawing
lcDeleteDrawing.restype = wt.BOOL
lcDeleteDrawing.argtypes = [wt.HANDLE]

lcDrwNew = litecad.lcDrwNew
lcDrwNew.restype = wt.BOOL
lcDrwNew.argtypes = [wt.HANDLE, wt.LPCWSTR, wt.HANDLE]

lcDrwLoad = litecad.lcDrwLoad
lcDrwLoad.restype = wt.BOOL
lcDrwLoad.argtypes = [wt.HANDLE, wt.LPCWSTR, wt.HANDLE]

lcDrwLoadMem = litecad.lcDrwLoadMem
lcDrwLoadMem.restype = wt.BOOL
lcDrwLoadMem.argtypes = [wt.HANDLE, wt.HANDLE, wt.HANDLE]

lcDxfLoadMem = litecad.lcDxfLoadMem
lcDxfLoadMem.restype = wt.BOOL
lcDxfLoadMem.argtypes = [wt.HANDLE, wt.HANDLE, wt.HANDLE]

lcDrwLoadTIN = litecad.lcDrwLoadTIN
lcDrwLoadTIN.restype = wt.HANDLE
lcDrwLoadTIN.argtypes = [wt.HANDLE, wt.LPCWSTR, wt.HANDLE]

lcDrwSaveTIN = litecad.lcDrwSaveTIN
lcDrwSaveTIN.restype = wt.BOOL
lcDrwSaveTIN.argtypes = [wt.HANDLE, wt.HANDLE]

lcDrwInsert = litecad.lcDrwInsert
lcDrwInsert.restype = wt.BOOL
lcDrwInsert.argtypes = [wt.HANDLE, wt.LPCWSTR, ct.c_int, wt.HANDLE]

lcDrwInsertSHP = litecad.lcDrwInsertSHP
lcDrwInsertSHP.restype = wt.BOOL
lcDrwInsertSHP.argtypes = [wt.HANDLE, wt.HANDLE, wt.LPCWSTR, wt.HANDLE]

lcDrwCopy = litecad.lcDrwCopy
lcDrwCopy.restype = wt.BOOL
lcDrwCopy.argtypes = [wt.HANDLE, wt.HANDLE]

lcDrwSave = litecad.lcDrwSave
lcDrwSave.restype = wt.BOOL
lcDrwSave.argtypes = [wt.HANDLE, wt.LPCWSTR, wt.BOOL, wt.HANDLE]

lcDrwSaveMem = litecad.lcDrwSaveMem
lcDrwSaveMem.restype = ct.c_int
lcDrwSaveMem.argtypes = [wt.HANDLE, wt.HANDLE, ct.c_int]

lcDrwAddLayer = litecad.lcDrwAddLayer
lcDrwAddLayer.restype = wt.HANDLE
lcDrwAddLayer.argtypes = [wt.HANDLE, wt.LPCWSTR, wt.LPCWSTR, wt.HANDLE, ct.c_int]

lcDrwAddLayer2 = litecad.lcDrwAddLayer2
lcDrwAddLayer2.restype = wt.HANDLE
lcDrwAddLayer2.argtypes = [wt.HANDLE, wt.LPCWSTR, wt.HANDLE]

lcDrwAddLinetype = litecad.lcDrwAddLinetype
lcDrwAddLinetype.restype = wt.HANDLE
lcDrwAddLinetype.argtypes = [wt.HANDLE, wt.LPCWSTR, wt.LPCWSTR]

lcDrwAddLinetypeF = litecad.lcDrwAddLinetypeF
lcDrwAddLinetypeF.restype = wt.HANDLE
lcDrwAddLinetypeF.argtypes = [wt.HANDLE, wt.LPCWSTR, wt.LPCWSTR, wt.LPCWSTR]

lcDrwAddTextStyle = litecad.lcDrwAddTextStyle
lcDrwAddTextStyle.restype = wt.HANDLE
lcDrwAddTextStyle.argtypes = [wt.HANDLE, wt.LPCWSTR, wt.LPCWSTR, wt.BOOL]

lcDrwAddDimStyle = litecad.lcDrwAddDimStyle
lcDrwAddDimStyle.restype = wt.HANDLE
lcDrwAddDimStyle.argtypes = [wt.HANDLE, wt.LPCWSTR]

lcDrwAddMlineStyle = litecad.lcDrwAddMlineStyle
lcDrwAddMlineStyle.restype = wt.HANDLE
lcDrwAddMlineStyle.argtypes = [wt.HANDLE, wt.LPCWSTR]

lcDrwAddPntStyle = litecad.lcDrwAddPntStyle
lcDrwAddPntStyle.restype = wt.HANDLE
lcDrwAddPntStyle.argtypes = [wt.HANDLE, wt.LPCWSTR, wt.HANDLE, ct.c_double, wt.HANDLE, ct.c_double, ct.c_double]

lcDrwAddFilling = litecad.lcDrwAddFilling
lcDrwAddFilling.restype = wt.HANDLE
lcDrwAddFilling.argtypes = [wt.HANDLE, wt.LPCWSTR]

lcDrwAddImage = litecad.lcDrwAddImage
lcDrwAddImage.restype = wt.HANDLE
lcDrwAddImage.argtypes = [wt.HANDLE, wt.LPCWSTR, wt.LPCWSTR]

lcDrwAddImage2 = litecad.lcDrwAddImage2
lcDrwAddImage2.restype = wt.HANDLE
lcDrwAddImage2.argtypes = [wt.HANDLE, wt.LPCWSTR, ct.c_int, ct.c_int, ct.c_int, wt.HANDLE, wt.BOOL]

lcDrwAddImage3 = litecad.lcDrwAddImage3
lcDrwAddImage3.restype = wt.HANDLE
lcDrwAddImage3.argtypes = [wt.HANDLE, wt.LPCWSTR, wt.HANDLE]

lcDrwAddImageCam = litecad.lcDrwAddImageCam
lcDrwAddImageCam.restype = wt.HANDLE
lcDrwAddImageCam.argtypes = [wt.HANDLE, wt.LPCWSTR]

lcDrwAddBlock = litecad.lcDrwAddBlock
lcDrwAddBlock.restype = wt.HANDLE
lcDrwAddBlock.argtypes = [wt.HANDLE, wt.LPCWSTR, ct.c_double, ct.c_double]

lcDrwAddBlockFromFile = litecad.lcDrwAddBlockFromFile
lcDrwAddBlockFromFile.restype = wt.HANDLE
lcDrwAddBlockFromFile.argtypes = [wt.HANDLE, wt.LPCWSTR, wt.LPCWSTR, ct.c_int, wt.HWND]

lcDrwAddBlockFromDrw = litecad.lcDrwAddBlockFromDrw
lcDrwAddBlockFromDrw.restype = wt.HANDLE
lcDrwAddBlockFromDrw.argtypes = [wt.HANDLE, wt.LPCWSTR, wt.HANDLE, ct.c_int, wt.HWND]

lcDrwAddBlockFile = litecad.lcDrwAddBlockFile
lcDrwAddBlockFile.restype = wt.HANDLE
lcDrwAddBlockFile.argtypes = [wt.HANDLE, wt.LPCWSTR, wt.LPCWSTR, ct.c_int, wt.HWND]

lcDrwAddBlockPaper = litecad.lcDrwAddBlockPaper
lcDrwAddBlockPaper.restype = wt.HANDLE
lcDrwAddBlockPaper.argtypes = [wt.HANDLE, wt.LPCWSTR, ct.c_int, ct.c_int, ct.c_double, ct.c_double]

lcDrwAddBlockCopy = litecad.lcDrwAddBlockCopy
lcDrwAddBlockCopy.restype = wt.HANDLE
lcDrwAddBlockCopy.argtypes = [wt.HANDLE, wt.LPCWSTR, wt.HANDLE]

lcDrwDeleteObject = litecad.lcDrwDeleteObject
lcDrwDeleteObject.restype = wt.BOOL
lcDrwDeleteObject.argtypes = [wt.HANDLE, wt.HANDLE]

lcDrwDeleteUnused = litecad.lcDrwDeleteUnused
lcDrwDeleteUnused.restype = ct.c_int
lcDrwDeleteUnused.argtypes = [wt.HANDLE, ct.c_int]

lcDrwCountObjects = litecad.lcDrwCountObjects
lcDrwCountObjects.restype = ct.c_int
lcDrwCountObjects.argtypes = [wt.HANDLE, ct.c_int]

lcDrwSortObjects = litecad.lcDrwSortObjects
lcDrwSortObjects.restype = wt.BOOL
lcDrwSortObjects.argtypes = [wt.HANDLE, ct.c_int]

lcDrwUpdateWinFonts = litecad.lcDrwUpdateWinFonts
lcDrwUpdateWinFonts.restype = wt.BOOL
lcDrwUpdateWinFonts.argtypes = [wt.HANDLE, wt.HANDLE]

lcDrwUpdateBlkRefs = litecad.lcDrwUpdateBlkRefs
lcDrwUpdateBlkRefs.restype = wt.BOOL
lcDrwUpdateBlkRefs.argtypes = [wt.HANDLE, wt.HANDLE]

lcDrwGetFirstObject = litecad.lcDrwGetFirstObject
lcDrwGetFirstObject.restype = wt.HANDLE
lcDrwGetFirstObject.argtypes = [wt.HANDLE, ct.c_int]

lcDrwGetNextObject = litecad.lcDrwGetNextObject
lcDrwGetNextObject.restype = wt.HANDLE
lcDrwGetNextObject.argtypes = [wt.HANDLE, wt.HANDLE]

lcDrwGetObjectByID = litecad.lcDrwGetObjectByID
lcDrwGetObjectByID.restype = wt.HANDLE
lcDrwGetObjectByID.argtypes = [wt.HANDLE, ct.c_int, ct.c_int]

lcDrwGetObjectByIDH = litecad.lcDrwGetObjectByIDH
lcDrwGetObjectByIDH.restype = wt.HANDLE
lcDrwGetObjectByIDH.argtypes = [wt.HANDLE, ct.c_int, wt.LPCWSTR]

lcDrwGetObjectByName = litecad.lcDrwGetObjectByName
lcDrwGetObjectByName.restype = wt.HANDLE
lcDrwGetObjectByName.argtypes = [wt.HANDLE, ct.c_int, wt.LPCWSTR]

lcDrwGetEntByID = litecad.lcDrwGetEntByID
lcDrwGetEntByID.restype = wt.HANDLE
lcDrwGetEntByID.argtypes = [wt.HANDLE, ct.c_int]

lcDrwGetEntByIDH = litecad.lcDrwGetEntByIDH
lcDrwGetEntByIDH.restype = wt.HANDLE
lcDrwGetEntByIDH.argtypes = [wt.HANDLE, wt.LPCWSTR]

lcDrwGetEntByKey = litecad.lcDrwGetEntByKey
lcDrwGetEntByKey.restype = wt.HANDLE
lcDrwGetEntByKey.argtypes = [wt.HANDLE, ct.c_int]

lcDrwClearXData = litecad.lcDrwClearXData
lcDrwClearXData.restype = wt.BOOL
lcDrwClearXData.argtypes = [wt.HANDLE, ct.c_int, ct.c_int]

lcDrwPurge = litecad.lcDrwPurge
lcDrwPurge.restype = wt.BOOL
lcDrwPurge.argtypes = [wt.HANDLE]

lcDrwExplode = litecad.lcDrwExplode
lcDrwExplode.restype = wt.BOOL
lcDrwExplode.argtypes = [wt.HANDLE, ct.c_int]

lcDrwSetLimits = litecad.lcDrwSetLimits
lcDrwSetLimits.restype = wt.BOOL
lcDrwSetLimits.argtypes = [wt.HANDLE, ct.c_double, ct.c_double, ct.c_double, ct.c_double]

lcDrwUndoRecord = litecad.lcDrwUndoRecord
lcDrwUndoRecord.restype = wt.BOOL
lcDrwUndoRecord.argtypes = [wt.HANDLE, ct.c_int]

lcDrwUndo = litecad.lcDrwUndo
lcDrwUndo.restype = wt.BOOL
lcDrwUndo.argtypes = [wt.HANDLE, wt.BOOL]


#  Clipping rectangles (also LC_PROP_CRECT_ID and others)

lcCRectsClear = litecad.lcCRectsClear
lcCRectsClear.restype = wt.BOOL
lcCRectsClear.argtypes = [wt.HANDLE]

lcCRectsAdd = litecad.lcCRectsAdd
lcCRectsAdd.restype = wt.BOOL
lcCRectsAdd.argtypes = [wt.HANDLE, ct.c_int, ct.c_double, ct.c_double, ct.c_double, ct.c_double]

lcCRectsDivide = litecad.lcCRectsDivide
lcCRectsDivide.restype = ct.c_int
lcCRectsDivide.argtypes = [wt.HANDLE, ct.c_int, ct.c_int, wt.BOOL]

lcCRectsGetFirst = litecad.lcCRectsGetFirst
lcCRectsGetFirst.restype = wt.HANDLE
lcCRectsGetFirst.argtypes = [wt.HANDLE]

lcCRectsGetNext = litecad.lcCRectsGetNext
lcCRectsGetNext.restype = wt.HANDLE
lcCRectsGetNext.argtypes = [wt.HANDLE, wt.HANDLE]

lcCRectsGetWithID = litecad.lcCRectsGetWithID
lcCRectsGetWithID.restype = wt.HANDLE
lcCRectsGetWithID.argtypes = [wt.HANDLE, ct.c_int]

lcCRectsActive = litecad.lcCRectsActive
lcCRectsActive.restype = wt.BOOL
lcCRectsActive.argtypes = [wt.HANDLE, wt.HANDLE]

lcCRectsGetActive = litecad.lcCRectsGetActive
lcCRectsGetActive.restype = wt.HANDLE
lcCRectsGetActive.argtypes = [wt.HANDLE]

lcCRectsDelete = litecad.lcCRectsDelete
lcCRectsDelete.restype = wt.BOOL
lcCRectsDelete.argtypes = [wt.HANDLE, wt.HANDLE]

lcCRectsSave = litecad.lcCRectsSave
lcCRectsSave.restype = wt.BOOL
lcCRectsSave.argtypes = [wt.HANDLE, wt.HANDLE, wt.LPCWSTR]

lcCRectsBitmap = litecad.lcCRectsBitmap
lcCRectsBitmap.restype = wt.BOOL
lcCRectsBitmap.argtypes = [wt.HANDLE, wt.HANDLE, wt.LPCWSTR, ct.c_double]


#  Block

lcBlockSetViewRect = litecad.lcBlockSetViewRect
lcBlockSetViewRect.restype = wt.BOOL
lcBlockSetViewRect.argtypes = [wt.HANDLE, ct.c_double, ct.c_double, ct.c_double, ct.c_double]

lcBlockSetViewRect2 = litecad.lcBlockSetViewRect2
lcBlockSetViewRect2.restype = wt.BOOL
lcBlockSetViewRect2.argtypes = [wt.HANDLE, ct.c_double, ct.c_double, ct.c_double, ct.c_double]

lcBlockSetPaperSize = litecad.lcBlockSetPaperSize
lcBlockSetPaperSize.restype = wt.BOOL
lcBlockSetPaperSize.argtypes = [wt.HANDLE, ct.c_int, ct.c_int, ct.c_double, ct.c_double]

lcBlockRasterize = litecad.lcBlockRasterize
lcBlockRasterize.restype = wt.BOOL
lcBlockRasterize.argtypes = [wt.HANDLE, wt.LPCWSTR, ct.c_double, ct.c_double, ct.c_double, ct.c_double, ct.c_int, ct.c_int]

lcBlockRasterizeMem = litecad.lcBlockRasterizeMem
lcBlockRasterizeMem.restype = ct.c_int
lcBlockRasterizeMem.argtypes = [wt.HANDLE, wt.HANDLE, ct.c_double, ct.c_double, ct.c_double, ct.c_double, ct.c_int, ct.c_int]

lcBlockUpdate = litecad.lcBlockUpdate
lcBlockUpdate.restype = wt.BOOL
lcBlockUpdate.argtypes = [wt.HANDLE, wt.BOOL, wt.HANDLE]

lcBlockMove = litecad.lcBlockMove
lcBlockMove.restype = wt.BOOL
lcBlockMove.argtypes = [wt.HANDLE, ct.c_double, ct.c_double, wt.BOOL]

lcBlockScale = litecad.lcBlockScale
lcBlockScale.restype = wt.BOOL
lcBlockScale.argtypes = [wt.HANDLE, ct.c_double, ct.c_double, ct.c_double, wt.BOOL]

lcBlockRotate = litecad.lcBlockRotate
lcBlockRotate.restype = wt.BOOL
lcBlockRotate.argtypes = [wt.HANDLE, ct.c_double, ct.c_double, ct.c_double, wt.BOOL]

lcBlockMirror = litecad.lcBlockMirror
lcBlockMirror.restype = wt.BOOL
lcBlockMirror.argtypes = [wt.HANDLE, ct.c_double, ct.c_double, ct.c_double, ct.c_double, wt.BOOL]


#  Add graphic objects into a block

lcBlockClear = litecad.lcBlockClear
lcBlockClear.restype = wt.BOOL
lcBlockClear.argtypes = [wt.HANDLE, wt.HANDLE]

lcBlockPurge = litecad.lcBlockPurge
lcBlockPurge.restype = wt.BOOL
lcBlockPurge.argtypes = [wt.HANDLE]

lcBlockSortEnts = litecad.lcBlockSortEnts
lcBlockSortEnts.restype = wt.BOOL
lcBlockSortEnts.argtypes = [wt.HANDLE, wt.BOOL, wt.HWND]

lcBlockSortEnts2 = litecad.lcBlockSortEnts2
lcBlockSortEnts2.restype = wt.BOOL
lcBlockSortEnts2.argtypes = [wt.HANDLE, wt.HANDLE, ct.c_int]

lcBlockAddPoint = litecad.lcBlockAddPoint
lcBlockAddPoint.restype = wt.HANDLE
lcBlockAddPoint.argtypes = [wt.HANDLE, ct.c_double, ct.c_double]

lcBlockAddPoint2 = litecad.lcBlockAddPoint2
lcBlockAddPoint2.restype = wt.HANDLE
lcBlockAddPoint2.argtypes = [wt.HANDLE, ct.c_double, ct.c_double, ct.c_int, ct.c_double]

lcBlockAddPoint3d = litecad.lcBlockAddPoint3d
lcBlockAddPoint3d.restype = wt.HANDLE
lcBlockAddPoint3d.argtypes = [wt.HANDLE, ct.c_double, ct.c_double, ct.c_double]

lcBlockAddPointsF = litecad.lcBlockAddPointsF
lcBlockAddPointsF.restype = ct.c_int
lcBlockAddPointsF.argtypes = [wt.HANDLE, wt.LPCWSTR, wt.HWND]

lcBlockAddPtArray = litecad.lcBlockAddPtArray
lcBlockAddPtArray.restype = wt.HANDLE
lcBlockAddPtArray.argtypes = [wt.HANDLE, wt.LPCWSTR, wt.HWND]

lcBlockAddXline = litecad.lcBlockAddXline
lcBlockAddXline.restype = wt.HANDLE
lcBlockAddXline.argtypes = [wt.HANDLE, ct.c_double, ct.c_double, ct.c_double, wt.BOOL]

lcBlockAddXline2P = litecad.lcBlockAddXline2P
lcBlockAddXline2P.restype = wt.HANDLE
lcBlockAddXline2P.argtypes = [wt.HANDLE, ct.c_double, ct.c_double, ct.c_double, ct.c_double, wt.BOOL]

lcBlockAddLine = litecad.lcBlockAddLine
lcBlockAddLine.restype = wt.HANDLE
lcBlockAddLine.argtypes = [wt.HANDLE, ct.c_double, ct.c_double, ct.c_double, ct.c_double]

lcBlockAddLineDir = litecad.lcBlockAddLineDir
lcBlockAddLineDir.restype = wt.HANDLE
lcBlockAddLineDir.argtypes = [wt.HANDLE, ct.c_double, ct.c_double, ct.c_double, ct.c_double]

lcBlockAddLineTan = litecad.lcBlockAddLineTan
lcBlockAddLineTan.restype = wt.HANDLE
lcBlockAddLineTan.argtypes = [wt.HANDLE, wt.HANDLE, wt.HANDLE, ct.c_int]

lcBlockAddPolyline = litecad.lcBlockAddPolyline
lcBlockAddPolyline.restype = wt.HANDLE
lcBlockAddPolyline.argtypes = [wt.HANDLE, ct.c_int, wt.BOOL, wt.BOOL]

lcBlockAddRPolygon = litecad.lcBlockAddRPolygon
lcBlockAddRPolygon.restype = wt.HANDLE
lcBlockAddRPolygon.argtypes = [wt.HANDLE, ct.c_int, ct.c_double, ct.c_double, ct.c_double, ct.c_double, wt.BOOL, wt.BOOL]

lcBlockAddSpline = litecad.lcBlockAddSpline
lcBlockAddSpline.restype = wt.HANDLE
lcBlockAddSpline.argtypes = [wt.HANDLE, wt.BOOL, wt.BOOL]

lcBlockAddBezier = litecad.lcBlockAddBezier
lcBlockAddBezier.restype = wt.HANDLE
lcBlockAddBezier.argtypes = [wt.HANDLE]

lcBlockAddMline = litecad.lcBlockAddMline
lcBlockAddMline.restype = wt.HANDLE
lcBlockAddMline.argtypes = [wt.HANDLE, ct.c_int, wt.BOOL]

lcBlockAddRect = litecad.lcBlockAddRect
lcBlockAddRect.restype = wt.HANDLE
lcBlockAddRect.argtypes = [wt.HANDLE, ct.c_double, ct.c_double, ct.c_double, ct.c_double, ct.c_double, wt.BOOL]

lcBlockAddRect2 = litecad.lcBlockAddRect2
lcBlockAddRect2.restype = wt.HANDLE
lcBlockAddRect2.argtypes = [wt.HANDLE, ct.c_double, ct.c_double, ct.c_double, ct.c_double, ct.c_double, wt.BOOL]

lcBlockAddCircle = litecad.lcBlockAddCircle
lcBlockAddCircle.restype = wt.HANDLE
lcBlockAddCircle.argtypes = [wt.HANDLE, ct.c_double, ct.c_double, ct.c_double, wt.BOOL]

lcBlockAddArc = litecad.lcBlockAddArc
lcBlockAddArc.restype = wt.HANDLE
lcBlockAddArc.argtypes = [wt.HANDLE, ct.c_double, ct.c_double, ct.c_double, ct.c_double, ct.c_double]

lcBlockAddArc3P = litecad.lcBlockAddArc3P
lcBlockAddArc3P.restype = wt.HANDLE
lcBlockAddArc3P.argtypes = [wt.HANDLE, ct.c_double, ct.c_double, ct.c_double, ct.c_double, ct.c_double, ct.c_double]

lcBlockAddFillet = litecad.lcBlockAddFillet
lcBlockAddFillet.restype = wt.HANDLE
lcBlockAddFillet.argtypes = [wt.HANDLE, wt.HANDLE, wt.HANDLE, ct.c_double]

lcBlockAddEllipse = litecad.lcBlockAddEllipse
lcBlockAddEllipse.restype = wt.HANDLE
lcBlockAddEllipse.argtypes = [wt.HANDLE, ct.c_double, ct.c_double, ct.c_double, ct.c_double, ct.c_double, ct.c_double, ct.c_double]

lcBlockAddText = litecad.lcBlockAddText
lcBlockAddText.restype = wt.HANDLE
lcBlockAddText.argtypes = [wt.HANDLE, wt.LPCWSTR, ct.c_double, ct.c_double]

lcBlockAddText2 = litecad.lcBlockAddText2
lcBlockAddText2.restype = wt.HANDLE
lcBlockAddText2.argtypes = [wt.HANDLE, wt.LPCWSTR, ct.c_double, ct.c_double, ct.c_int, ct.c_double, ct.c_double, ct.c_double, ct.c_double]

lcBlockAddText3 = litecad.lcBlockAddText3
lcBlockAddText3.restype = wt.HANDLE
lcBlockAddText3.argtypes = [wt.HANDLE, wt.LPCWSTR, ct.c_double, ct.c_double, ct.c_double, ct.c_double, ct.c_int, ct.c_double, ct.c_double]

lcBlockAddTextWin = litecad.lcBlockAddTextWin
lcBlockAddTextWin.restype = wt.HANDLE
lcBlockAddTextWin.argtypes = [wt.HANDLE, wt.LPCWSTR, ct.c_double, ct.c_double]

lcBlockAddTextWin2 = litecad.lcBlockAddTextWin2
lcBlockAddTextWin2.restype = wt.HANDLE
lcBlockAddTextWin2.argtypes = [wt.HANDLE, wt.LPCWSTR, ct.c_double, ct.c_double, ct.c_int, ct.c_double, ct.c_double, ct.c_double, ct.c_double]

lcBlockAddMText = litecad.lcBlockAddMText
lcBlockAddMText.restype = wt.HANDLE
lcBlockAddMText.argtypes = [wt.HANDLE, wt.LPCWSTR, ct.c_double, ct.c_double, ct.c_double, ct.c_int, ct.c_double, ct.c_double, ct.c_double]

lcBlockAddArcText = litecad.lcBlockAddArcText
lcBlockAddArcText.restype = wt.HANDLE
lcBlockAddArcText.argtypes = [wt.HANDLE, wt.LPCWSTR, ct.c_double, ct.c_double, ct.c_double, ct.c_double, wt.BOOL, ct.c_double, ct.c_double, ct.c_int]

lcBlockAddBlockRef = litecad.lcBlockAddBlockRef
lcBlockAddBlockRef.restype = wt.HANDLE
lcBlockAddBlockRef.argtypes = [wt.HANDLE, wt.HANDLE, ct.c_double, ct.c_double, ct.c_double, ct.c_double]

lcBlockAddBlockRefID = litecad.lcBlockAddBlockRefID
lcBlockAddBlockRefID.restype = wt.HANDLE
lcBlockAddBlockRefID.argtypes = [wt.HANDLE, ct.c_int, ct.c_double, ct.c_double, ct.c_double, ct.c_double]

lcBlockAddBlockRefIDH = litecad.lcBlockAddBlockRefIDH
lcBlockAddBlockRefIDH.restype = wt.HANDLE
lcBlockAddBlockRefIDH.argtypes = [wt.HANDLE, wt.LPCWSTR, ct.c_double, ct.c_double, ct.c_double, ct.c_double]

lcBlockAddAttDef = litecad.lcBlockAddAttDef
lcBlockAddAttDef.restype = wt.HANDLE
lcBlockAddAttDef.argtypes = [wt.HANDLE, ct.c_int, wt.LPCWSTR, wt.LPCWSTR, wt.LPCWSTR, ct.c_double, ct.c_double, ct.c_int, ct.c_double, ct.c_double, ct.c_double, ct.c_double]

lcBlockAddXref = litecad.lcBlockAddXref
lcBlockAddXref.restype = wt.HANDLE
lcBlockAddXref.argtypes = [wt.HANDLE, wt.LPCWSTR, ct.c_double, ct.c_double, ct.c_double, ct.c_double, ct.c_double]

lcBlockAddImageRef = litecad.lcBlockAddImageRef
lcBlockAddImageRef.restype = wt.HANDLE
lcBlockAddImageRef.argtypes = [wt.HANDLE, wt.HANDLE, ct.c_double, ct.c_double, ct.c_double, ct.c_double, wt.BOOL]

lcBlockAddImageRefUns = litecad.lcBlockAddImageRefUns
lcBlockAddImageRefUns.restype = wt.HANDLE
lcBlockAddImageRefUns.argtypes = [wt.HANDLE, wt.HANDLE, ct.c_double, ct.c_double, ct.c_double, ct.c_int, wt.BOOL]

lcBlockAddImagePlace = litecad.lcBlockAddImagePlace
lcBlockAddImagePlace.restype = wt.HANDLE
lcBlockAddImagePlace.argtypes = [wt.HANDLE, ct.c_int, ct.c_double, ct.c_double, ct.c_double, ct.c_double, wt.BOOL]

lcBlockAddEcw = litecad.lcBlockAddEcw
lcBlockAddEcw.restype = wt.HANDLE
lcBlockAddEcw.argtypes = [wt.HANDLE, wt.LPCWSTR]

lcBlockAddBarcode = litecad.lcBlockAddBarcode
lcBlockAddBarcode.restype = wt.HANDLE
lcBlockAddBarcode.argtypes = [wt.HANDLE, ct.c_int, ct.c_double, ct.c_double, ct.c_double, ct.c_double, wt.LPCWSTR]

lcBlockAddHatch = litecad.lcBlockAddHatch
lcBlockAddHatch.restype = wt.HANDLE
lcBlockAddHatch.argtypes = [wt.HANDLE, wt.LPCWSTR, wt.LPCWSTR, ct.c_double, ct.c_double]

lcBlockAddViewport = litecad.lcBlockAddViewport
lcBlockAddViewport.restype = wt.HANDLE
lcBlockAddViewport.argtypes = [wt.HANDLE, ct.c_double, ct.c_double, ct.c_double, ct.c_double, ct.c_double, ct.c_double, ct.c_double, ct.c_double]

lcBlockAddFace = litecad.lcBlockAddFace
lcBlockAddFace.restype = wt.HANDLE
lcBlockAddFace.argtypes = [wt.HANDLE, ct.c_int, ct.c_double, ct.c_double, ct.c_double, ct.c_double, ct.c_double, ct.c_double, ct.c_double, ct.c_double, ct.c_double]

lcBlockAddFace4 = litecad.lcBlockAddFace4
lcBlockAddFace4.restype = wt.HANDLE
lcBlockAddFace4.argtypes = [wt.HANDLE, ct.c_int, ct.c_double, ct.c_double, ct.c_double, ct.c_double, ct.c_double, ct.c_double, ct.c_double, ct.c_double, ct.c_double, ct.c_double, ct.c_double, ct.c_double]

lcBlockAddLeader = litecad.lcBlockAddLeader
lcBlockAddLeader.restype = wt.HANDLE
lcBlockAddLeader.argtypes = [wt.HANDLE, wt.LPCWSTR, ct.c_double, ct.c_double, ct.c_double, ct.c_double, ct.c_double, ct.c_int, ct.c_int]

lcBlockAddDimLin = litecad.lcBlockAddDimLin
lcBlockAddDimLin.restype = wt.HANDLE
lcBlockAddDimLin.argtypes = [wt.HANDLE, ct.c_double, ct.c_double, ct.c_double, ct.c_double, ct.c_double, ct.c_double, ct.c_double, wt.LPCWSTR]

lcBlockAddDimHor = litecad.lcBlockAddDimHor
lcBlockAddDimHor.restype = wt.HANDLE
lcBlockAddDimHor.argtypes = [wt.HANDLE, ct.c_double, ct.c_double, ct.c_double, ct.c_double, ct.c_double, wt.LPCWSTR]

lcBlockAddDimVer = litecad.lcBlockAddDimVer
lcBlockAddDimVer.restype = wt.HANDLE
lcBlockAddDimVer.argtypes = [wt.HANDLE, ct.c_double, ct.c_double, ct.c_double, ct.c_double, ct.c_double, wt.LPCWSTR]

lcBlockAddDimAli = litecad.lcBlockAddDimAli
lcBlockAddDimAli.restype = wt.HANDLE
lcBlockAddDimAli.argtypes = [wt.HANDLE, ct.c_double, ct.c_double, ct.c_double, ct.c_double, ct.c_double, ct.c_double, wt.LPCWSTR]

lcBlockAddDimAli2 = litecad.lcBlockAddDimAli2
lcBlockAddDimAli2.restype = wt.HANDLE
lcBlockAddDimAli2.argtypes = [wt.HANDLE, ct.c_double, ct.c_double, ct.c_double, ct.c_double, ct.c_double, wt.LPCWSTR]

lcBlockAddDimOrd = litecad.lcBlockAddDimOrd
lcBlockAddDimOrd.restype = wt.HANDLE
lcBlockAddDimOrd.argtypes = [wt.HANDLE, ct.c_double, ct.c_double, ct.c_double, ct.c_double, wt.BOOL, wt.LPCWSTR]

lcBlockAddDimRad = litecad.lcBlockAddDimRad
lcBlockAddDimRad.restype = wt.HANDLE
lcBlockAddDimRad.argtypes = [wt.HANDLE, ct.c_double, ct.c_double, ct.c_double, ct.c_double, ct.c_double, ct.c_double, wt.LPCWSTR]

lcBlockAddDimRad2 = litecad.lcBlockAddDimRad2
lcBlockAddDimRad2.restype = wt.HANDLE
lcBlockAddDimRad2.argtypes = [wt.HANDLE, ct.c_double, ct.c_double, ct.c_double, ct.c_double, ct.c_double, wt.LPCWSTR]

lcBlockAddDimDia = litecad.lcBlockAddDimDia
lcBlockAddDimDia.restype = wt.HANDLE
lcBlockAddDimDia.argtypes = [wt.HANDLE, ct.c_double, ct.c_double, ct.c_double, ct.c_double, ct.c_double, ct.c_double, wt.LPCWSTR]

lcBlockAddDimDia2 = litecad.lcBlockAddDimDia2
lcBlockAddDimDia2.restype = wt.HANDLE
lcBlockAddDimDia2.argtypes = [wt.HANDLE, ct.c_double, ct.c_double, ct.c_double, ct.c_double, ct.c_double, wt.LPCWSTR]

lcBlockAddDimAng = litecad.lcBlockAddDimAng
lcBlockAddDimAng.restype = wt.HANDLE
lcBlockAddDimAng.argtypes = [wt.HANDLE, ct.c_double, ct.c_double, ct.c_double, ct.c_double, ct.c_double, ct.c_double, ct.c_double, ct.c_double, ct.c_double, wt.LPCWSTR]

lcBlockAddDimAng2 = litecad.lcBlockAddDimAng2
lcBlockAddDimAng2.restype = wt.HANDLE
lcBlockAddDimAng2.argtypes = [wt.HANDLE, ct.c_double, ct.c_double, ct.c_double, ct.c_double, ct.c_double, ct.c_double, ct.c_double, ct.c_double, ct.c_double, ct.c_double, ct.c_double, wt.LPCWSTR]

lcBlockAddRPlan = litecad.lcBlockAddRPlan
lcBlockAddRPlan.restype = wt.HANDLE
lcBlockAddRPlan.argtypes = [wt.HANDLE]

lcBlockAddRPlan2 = litecad.lcBlockAddRPlan2
lcBlockAddRPlan2.restype = wt.HANDLE
lcBlockAddRPlan2.argtypes = [wt.HANDLE, wt.HANDLE]

lcBlockAddArrow = litecad.lcBlockAddArrow
lcBlockAddArrow.restype = wt.HANDLE
lcBlockAddArrow.argtypes = [wt.HANDLE, ct.c_double, ct.c_double, ct.c_double, ct.c_double]

lcBlockAddSpiral = litecad.lcBlockAddSpiral
lcBlockAddSpiral.restype = wt.HANDLE
lcBlockAddSpiral.argtypes = [wt.HANDLE, ct.c_double, ct.c_double, ct.c_double, ct.c_double, wt.BOOL, wt.BOOL]

lcBlockAddCamview = litecad.lcBlockAddCamview
lcBlockAddCamview.restype = wt.HANDLE
lcBlockAddCamview.argtypes = [wt.HANDLE, ct.c_double, ct.c_double, ct.c_double, ct.c_double]

lcBlockAddTIN = litecad.lcBlockAddTIN
lcBlockAddTIN.restype = wt.HANDLE
lcBlockAddTIN.argtypes = [wt.HANDLE, wt.LPCWSTR, ct.c_int]

lcBlockAddClone = litecad.lcBlockAddClone
lcBlockAddClone.restype = wt.HANDLE
lcBlockAddClone.argtypes = [wt.HANDLE, wt.HANDLE]

lcBlockBeginShape = litecad.lcBlockBeginShape
lcBlockBeginShape.restype = wt.BOOL
lcBlockBeginShape.argtypes = [wt.HANDLE]

lcBlockAddShape = litecad.lcBlockAddShape
lcBlockAddShape.restype = wt.HANDLE
lcBlockAddShape.argtypes = [wt.HANDLE]

lcBlockAddShapeSel = litecad.lcBlockAddShapeSel
lcBlockAddShapeSel.restype = wt.HANDLE
lcBlockAddShapeSel.argtypes = [wt.HANDLE, wt.BOOL]

lcBlockRepEllipse = litecad.lcBlockRepEllipse
lcBlockRepEllipse.restype = wt.HANDLE
lcBlockRepEllipse.argtypes = [wt.HANDLE, wt.HANDLE, ct.POINTER(ct.c_int)]

lcBlockJoinAll = litecad.lcBlockJoinAll
lcBlockJoinAll.restype = wt.HANDLE
lcBlockJoinAll.argtypes = [wt.HANDLE, ct.c_double]

lcBlockCopyLayer = litecad.lcBlockCopyLayer
lcBlockCopyLayer.restype = ct.c_int
lcBlockCopyLayer.argtypes = [wt.HANDLE, wt.HANDLE, wt.HANDLE]

lcBlockDeleteEnt = litecad.lcBlockDeleteEnt
lcBlockDeleteEnt.restype = wt.BOOL
lcBlockDeleteEnt.argtypes = [wt.HANDLE, wt.HANDLE]


#  Retrieve graphic objects from a block

lcBlockGetFirstEnt = litecad.lcBlockGetFirstEnt
lcBlockGetFirstEnt.restype = wt.HANDLE
lcBlockGetFirstEnt.argtypes = [wt.HANDLE]

lcBlockGetNextEnt = litecad.lcBlockGetNextEnt
lcBlockGetNextEnt.restype = wt.HANDLE
lcBlockGetNextEnt.argtypes = [wt.HANDLE, wt.HANDLE]

lcBlockGetLastEnt = litecad.lcBlockGetLastEnt
lcBlockGetLastEnt.restype = wt.HANDLE
lcBlockGetLastEnt.argtypes = [wt.HANDLE]

lcBlockGetPrevEnt = litecad.lcBlockGetPrevEnt
lcBlockGetPrevEnt.restype = wt.HANDLE
lcBlockGetPrevEnt.argtypes = [wt.HANDLE, wt.HANDLE]

lcBlockGetEntByID = litecad.lcBlockGetEntByID
lcBlockGetEntByID.restype = wt.HANDLE
lcBlockGetEntByID.argtypes = [wt.HANDLE, ct.c_int]

lcBlockGetEntByIDH = litecad.lcBlockGetEntByIDH
lcBlockGetEntByIDH.restype = wt.HANDLE
lcBlockGetEntByIDH.argtypes = [wt.HANDLE, wt.LPCWSTR]

lcBlockGetEntByKey = litecad.lcBlockGetEntByKey
lcBlockGetEntByKey.restype = wt.HANDLE
lcBlockGetEntByKey.argtypes = [wt.HANDLE, ct.c_int]

lcBlockGetBlkRefByTag = litecad.lcBlockGetBlkRefByTag
lcBlockGetBlkRefByTag.restype = wt.HANDLE
lcBlockGetBlkRefByTag.argtypes = [wt.HANDLE, wt.HANDLE, wt.LPCWSTR, wt.LPCWSTR, wt.BOOL]

lcBlockGetTIN = litecad.lcBlockGetTIN
lcBlockGetTIN.restype = wt.HANDLE
lcBlockGetTIN.argtypes = [wt.HANDLE, wt.LPCWSTR]


#  Selection

lcBlockUnselect = litecad.lcBlockUnselect
lcBlockUnselect.restype = wt.BOOL
lcBlockUnselect.argtypes = [wt.HANDLE]

lcBlockSelectEnt = litecad.lcBlockSelectEnt
lcBlockSelectEnt.restype = wt.BOOL
lcBlockSelectEnt.argtypes = [wt.HANDLE, wt.HANDLE, wt.BOOL]

lcBlockSelErase = litecad.lcBlockSelErase
lcBlockSelErase.restype = wt.BOOL
lcBlockSelErase.argtypes = [wt.HANDLE]

lcBlockSelMove = litecad.lcBlockSelMove
lcBlockSelMove.restype = wt.BOOL
lcBlockSelMove.argtypes = [wt.HANDLE, ct.c_double, ct.c_double, wt.BOOL, wt.BOOL]

lcBlockSelScale = litecad.lcBlockSelScale
lcBlockSelScale.restype = wt.BOOL
lcBlockSelScale.argtypes = [wt.HANDLE, ct.c_double, ct.c_double, ct.c_double, wt.BOOL, wt.BOOL]

lcBlockSelRotate = litecad.lcBlockSelRotate
lcBlockSelRotate.restype = wt.BOOL
lcBlockSelRotate.argtypes = [wt.HANDLE, ct.c_double, ct.c_double, ct.c_double, wt.BOOL, wt.BOOL]

lcBlockSelMirror = litecad.lcBlockSelMirror
lcBlockSelMirror.restype = wt.BOOL
lcBlockSelMirror.argtypes = [wt.HANDLE, ct.c_double, ct.c_double, ct.c_double, ct.c_double, wt.BOOL, wt.BOOL]

lcBlockSelExplode = litecad.lcBlockSelExplode
lcBlockSelExplode.restype = wt.BOOL
lcBlockSelExplode.argtypes = [wt.HANDLE]

lcBlockSelSplit = litecad.lcBlockSelSplit
lcBlockSelSplit.restype = wt.BOOL
lcBlockSelSplit.argtypes = [wt.HANDLE, ct.c_int]

lcBlockSelJoin = litecad.lcBlockSelJoin
lcBlockSelJoin.restype = wt.HANDLE
lcBlockSelJoin.argtypes = [wt.HANDLE, ct.c_double]

lcBlockSelAlign = litecad.lcBlockSelAlign
lcBlockSelAlign.restype = wt.BOOL
lcBlockSelAlign.argtypes = [wt.HANDLE, ct.c_int, ct.c_double, ct.c_double]

lcBlockSelBlock = litecad.lcBlockSelBlock
lcBlockSelBlock.restype = wt.HANDLE
lcBlockSelBlock.argtypes = [wt.HANDLE, wt.LPCWSTR, ct.c_double, ct.c_double, ct.c_int, wt.BOOL]

lcBlockGetFirstSel = litecad.lcBlockGetFirstSel
lcBlockGetFirstSel.restype = wt.HANDLE
lcBlockGetFirstSel.argtypes = [wt.HANDLE]

lcBlockGetNextSel = litecad.lcBlockGetNextSel
lcBlockGetNextSel.restype = wt.HANDLE
lcBlockGetNextSel.argtypes = [wt.HANDLE]


#  change entities order by layer

lcBlockOrderByLayers = litecad.lcBlockOrderByLayers
lcBlockOrderByLayers.restype = wt.BOOL
lcBlockOrderByLayers.argtypes = [wt.HANDLE, wt.HWND]

lcBlockSortTSP = litecad.lcBlockSortTSP
lcBlockSortTSP.restype = wt.BOOL
lcBlockSortTSP.argtypes = [wt.HANDLE, wt.HANDLE, wt.HWND]

lcBlockGetJumpsLen = litecad.lcBlockGetJumpsLen
lcBlockGetJumpsLen.restype = ct.c_double
lcBlockGetJumpsLen.argtypes = [wt.HANDLE, wt.HANDLE, wt.HWND]


#  remove entities of specified layer from a block (all blocks if hBlock=0)

lcLayerClear = litecad.lcLayerClear
lcLayerClear.restype = wt.BOOL
lcLayerClear.argtypes = [wt.HANDLE, wt.HANDLE]

lcLayerCopyProps = litecad.lcLayerCopyProps
lcLayerCopyProps.restype = wt.BOOL
lcLayerCopyProps.argtypes = [wt.HANDLE, wt.HANDLE]


#  add line to a filling (see also lcDrwAddFilling)

lcFillSetLine = litecad.lcFillSetLine
lcFillSetLine.restype = wt.BOOL
lcFillSetLine.argtypes = [wt.HANDLE, ct.c_int, ct.c_double, ct.c_double, ct.c_double]


#  Mline style

lcMLStyleAddLine = litecad.lcMLStyleAddLine
lcMLStyleAddLine.restype = wt.BOOL
lcMLStyleAddLine.argtypes = [wt.HANDLE, ct.c_double, wt.LPCWSTR, wt.HANDLE]

lcMLStyleDelLine = litecad.lcMLStyleDelLine
lcMLStyleDelLine.restype = wt.BOOL
lcMLStyleDelLine.argtypes = [wt.HANDLE, ct.c_int]

lcMLStyleSortLines = litecad.lcMLStyleSortLines
lcMLStyleSortLines.restype = wt.BOOL
lcMLStyleSortLines.argtypes = [wt.HANDLE]

lcEntType = litecad.lcEntType
lcEntType.restype = wt.BOOL
lcEntType.argtypes = [wt.HANDLE, ct.c_int]


#  Graphic object modify

lcEntErase = litecad.lcEntErase
lcEntErase.restype = wt.BOOL
lcEntErase.argtypes = [wt.HANDLE, wt.BOOL]

lcEntMove = litecad.lcEntMove
lcEntMove.restype = wt.BOOL
lcEntMove.argtypes = [wt.HANDLE, ct.c_double, ct.c_double]

lcEntAlign = litecad.lcEntAlign
lcEntAlign.restype = wt.BOOL
lcEntAlign.argtypes = [wt.HANDLE, ct.c_int, ct.c_double, ct.c_double]

lcEntScale = litecad.lcEntScale
lcEntScale.restype = wt.BOOL
lcEntScale.argtypes = [wt.HANDLE, ct.c_double, ct.c_double, ct.c_double]

lcEntRotate = litecad.lcEntRotate
lcEntRotate.restype = wt.BOOL
lcEntRotate.argtypes = [wt.HANDLE, ct.c_double, ct.c_double, ct.c_double]

lcEntMirror = litecad.lcEntMirror
lcEntMirror.restype = wt.BOOL
lcEntMirror.argtypes = [wt.HANDLE, ct.c_double, ct.c_double, ct.c_double, ct.c_double]

lcEntExplode = litecad.lcEntExplode
lcEntExplode.restype = wt.BOOL
lcEntExplode.argtypes = [wt.HANDLE, wt.BOOL, wt.BOOL]

lcEntSplit = litecad.lcEntSplit
lcEntSplit.restype = wt.HANDLE
lcEntSplit.argtypes = [wt.HANDLE, ct.c_int, wt.BOOL, wt.BOOL]

lcEntBreak = litecad.lcEntBreak
lcEntBreak.restype = wt.HANDLE
lcEntBreak.argtypes = [wt.HANDLE, ct.c_double, ct.c_double, ct.c_double, wt.BOOL, wt.BOOL]

lcEntBreak2 = litecad.lcEntBreak2
lcEntBreak2.restype = wt.HANDLE
lcEntBreak2.argtypes = [wt.HANDLE, wt.HANDLE, ct.c_double, wt.BOOL, wt.BOOL]

lcEntOffset = litecad.lcEntOffset
lcEntOffset.restype = wt.BOOL
lcEntOffset.argtypes = [wt.HANDLE, ct.c_double]

lcEntExtend = litecad.lcEntExtend
lcEntExtend.restype = wt.BOOL
lcEntExtend.argtypes = [wt.HANDLE, wt.HANDLE, wt.BOOL]

lcEntToTop = litecad.lcEntToTop
lcEntToTop.restype = wt.BOOL
lcEntToTop.argtypes = [wt.HANDLE]

lcEntToBottom = litecad.lcEntToBottom
lcEntToBottom.restype = wt.BOOL
lcEntToBottom.argtypes = [wt.HANDLE]

lcEntToAbove = litecad.lcEntToAbove
lcEntToAbove.restype = wt.BOOL
lcEntToAbove.argtypes = [wt.HANDLE, wt.HANDLE]

lcEntToUnder = litecad.lcEntToUnder
lcEntToUnder.restype = wt.BOOL
lcEntToUnder.argtypes = [wt.HANDLE, wt.HANDLE]

lcEntGetGrip = litecad.lcEntGetGrip
lcEntGetGrip.restype = wt.BOOL
lcEntGetGrip.argtypes = [wt.HANDLE, ct.c_int, ct.POINTER(ct.c_double), ct.POINTER(ct.c_double)]

lcEntPutGrip = litecad.lcEntPutGrip
lcEntPutGrip.restype = wt.BOOL
lcEntPutGrip.argtypes = [wt.HANDLE, ct.c_int, ct.c_double, ct.c_double]

lcEntUpdate = litecad.lcEntUpdate
lcEntUpdate.restype = wt.BOOL
lcEntUpdate.argtypes = [wt.HANDLE]

lcEntCopyBase = litecad.lcEntCopyBase
lcEntCopyBase.restype = wt.BOOL
lcEntCopyBase.argtypes = [wt.HANDLE, wt.HANDLE]

lcEntXData = litecad.lcEntXData
lcEntXData.restype = wt.BOOL
lcEntXData.argtypes = [wt.HANDLE, ct.c_int, ct.c_int, ct.c_int]

lcEntContainEnt = litecad.lcEntContainEnt
lcEntContainEnt.restype = wt.BOOL
lcEntContainEnt.argtypes = [wt.HANDLE, wt.HANDLE]

lcEntCrossEnt = litecad.lcEntCrossEnt
lcEntCrossEnt.restype = wt.BOOL
lcEntCrossEnt.argtypes = [wt.HANDLE, wt.HANDLE]

lcEntReverse = litecad.lcEntReverse
lcEntReverse.restype = wt.BOOL
lcEntReverse.argtypes = [wt.HANDLE]

lcEntGetPoint = litecad.lcEntGetPoint
lcEntGetPoint.restype = wt.BOOL
lcEntGetPoint.argtypes = [wt.HANDLE, ct.c_double, ct.POINTER(ct.c_double), ct.POINTER(ct.c_double), ct.POINTER(ct.c_double)]

lcEntGetDist = litecad.lcEntGetDist
lcEntGetDist.restype = ct.c_double
lcEntGetDist.argtypes = [wt.HANDLE, ct.c_double, ct.c_double, ct.POINTER(ct.c_double), ct.POINTER(ct.c_double), ct.POINTER(ct.c_double)]

lcEntTransform = litecad.lcEntTransform
lcEntTransform.restype = wt.BOOL
lcEntTransform.argtypes = [wt.HANDLE, wt.HANDLE]

lcIntersection = litecad.lcIntersection
lcIntersection.restype = ct.c_int
lcIntersection.argtypes = [wt.HANDLE, wt.HANDLE, ct.c_int]

lcInterGetPoint = litecad.lcInterGetPoint
lcInterGetPoint.restype = wt.BOOL
lcInterGetPoint.argtypes = [ct.c_int, ct.POINTER(ct.c_double), ct.POINTER(ct.c_double)]

lcLineGetPoint = litecad.lcLineGetPoint
lcLineGetPoint.restype = wt.BOOL
lcLineGetPoint.argtypes = [wt.HANDLE, ct.c_int, ct.c_double, ct.POINTER(ct.c_double), ct.POINTER(ct.c_double)]


#  Polyline Vertices

lcPlineAddVer = litecad.lcPlineAddVer
lcPlineAddVer.restype = wt.HANDLE
lcPlineAddVer.argtypes = [wt.HANDLE, wt.HANDLE, ct.c_double, ct.c_double]

lcPlineAddVer2 = litecad.lcPlineAddVer2
lcPlineAddVer2.restype = wt.HANDLE
lcPlineAddVer2.argtypes = [wt.HANDLE, wt.HANDLE, ct.c_double, ct.c_double, ct.c_double, ct.c_double, ct.c_double]

lcPlineAddVerDir = litecad.lcPlineAddVerDir
lcPlineAddVerDir.restype = wt.HANDLE
lcPlineAddVerDir.argtypes = [wt.HANDLE, wt.HANDLE, ct.c_double, ct.c_double]

lcPlineEnd = litecad.lcPlineEnd
lcPlineEnd.restype = wt.BOOL
lcPlineEnd.argtypes = [wt.HANDLE]

lcPlineFromPtbuf = litecad.lcPlineFromPtbuf
lcPlineFromPtbuf.restype = wt.BOOL
lcPlineFromPtbuf.argtypes = [wt.HANDLE, wt.HANDLE]

lcPlineFromMpgon = litecad.lcPlineFromMpgon
lcPlineFromMpgon.restype = wt.BOOL
lcPlineFromMpgon.argtypes = [wt.HANDLE, wt.HANDLE]

lcPlineFromFile = litecad.lcPlineFromFile
lcPlineFromFile.restype = wt.BOOL
lcPlineFromFile.argtypes = [wt.HANDLE, wt.LPCWSTR]

lcPlineDeleteVer = litecad.lcPlineDeleteVer
lcPlineDeleteVer.restype = wt.BOOL
lcPlineDeleteVer.argtypes = [wt.HANDLE, wt.HANDLE]

lcPlineDelExVers = litecad.lcPlineDelExVers
lcPlineDelExVers.restype = ct.c_int
lcPlineDelExVers.argtypes = [wt.HANDLE, ct.c_double]

lcPlineGetFirstVer = litecad.lcPlineGetFirstVer
lcPlineGetFirstVer.restype = wt.HANDLE
lcPlineGetFirstVer.argtypes = [wt.HANDLE]

lcPlineGetNextVer = litecad.lcPlineGetNextVer
lcPlineGetNextVer.restype = wt.HANDLE
lcPlineGetNextVer.argtypes = [wt.HANDLE, wt.HANDLE]

lcPlineGetLastVer = litecad.lcPlineGetLastVer
lcPlineGetLastVer.restype = wt.HANDLE
lcPlineGetLastVer.argtypes = [wt.HANDLE]

lcPlineGetPrevVer = litecad.lcPlineGetPrevVer
lcPlineGetPrevVer.restype = wt.HANDLE
lcPlineGetPrevVer.argtypes = [wt.HANDLE, wt.HANDLE]

lcPlineGetVer = litecad.lcPlineGetVer
lcPlineGetVer.restype = wt.HANDLE
lcPlineGetVer.argtypes = [wt.HANDLE, ct.c_int]

lcPlineGetVerPt = litecad.lcPlineGetVerPt
lcPlineGetVerPt.restype = wt.HANDLE
lcPlineGetVerPt.argtypes = [wt.HANDLE, ct.c_double, ct.c_double, ct.c_double]

lcPlineGetSeg = litecad.lcPlineGetSeg
lcPlineGetSeg.restype = wt.HANDLE
lcPlineGetSeg.argtypes = [wt.HANDLE, ct.c_double, ct.c_double, ct.c_double]

lcPlineReverse = litecad.lcPlineReverse
lcPlineReverse.restype = wt.BOOL
lcPlineReverse.argtypes = [wt.HANDLE]

lcPlineSetStartVer = litecad.lcPlineSetStartVer
lcPlineSetStartVer.restype = wt.BOOL
lcPlineSetStartVer.argtypes = [wt.HANDLE, wt.HANDLE]

lcPlineContainPoint = litecad.lcPlineContainPoint
lcPlineContainPoint.restype = ct.c_int
lcPlineContainPoint.argtypes = [wt.HANDLE, ct.c_double, ct.c_double]

lcPlineGetRoundPrm = litecad.lcPlineGetRoundPrm
lcPlineGetRoundPrm.restype = wt.BOOL
lcPlineGetRoundPrm.argtypes = [wt.HANDLE, wt.HANDLE, ct.POINTER(ct.c_double), ct.POINTER(ct.c_double), ct.POINTER(ct.c_double), ct.POINTER(ct.c_double), ct.POINTER(ct.c_double)]

lcPlineGetPoint = litecad.lcPlineGetPoint
lcPlineGetPoint.restype = wt.BOOL
lcPlineGetPoint.argtypes = [wt.HANDLE, ct.c_double, ct.POINTER(ct.c_double), ct.POINTER(ct.c_double), ct.POINTER(ct.c_double)]

lcPlineGetPointOpp = litecad.lcPlineGetPointOpp
lcPlineGetPointOpp.restype = wt.BOOL
lcPlineGetPointOpp.argtypes = [wt.HANDLE, ct.c_double, ct.POINTER(ct.c_double), ct.POINTER(ct.c_double), ct.POINTER(ct.c_double), ct.POINTER(ct.c_double), ct.POINTER(ct.c_double)]

lcPlineGetDist = litecad.lcPlineGetDist
lcPlineGetDist.restype = ct.c_double
lcPlineGetDist.argtypes = [wt.HANDLE, ct.c_double, ct.c_double, ct.POINTER(ct.c_double), ct.POINTER(ct.c_double), ct.POINTER(ct.c_double)]

lcPlineDivide = litecad.lcPlineDivide
lcPlineDivide.restype = ct.c_int
lcPlineDivide.argtypes = [wt.HANDLE, ct.c_int, wt.BOOL]

lcPlineDivide2 = litecad.lcPlineDivide2
lcPlineDivide2.restype = ct.c_int
lcPlineDivide2.argtypes = [wt.HANDLE, ct.c_double, wt.BOOL]

lcGetDivPt = litecad.lcGetDivPt
lcGetDivPt.restype = wt.BOOL
lcGetDivPt.argtypes = [ct.c_int, ct.POINTER(ct.c_double), ct.POINTER(ct.c_double), ct.POINTER(ct.c_double)]

lcPlineMakeArrow = litecad.lcPlineMakeArrow
lcPlineMakeArrow.restype = wt.BOOL
lcPlineMakeArrow.argtypes = [wt.HANDLE, ct.c_double, ct.c_double]

lcPlineSplitBySI = litecad.lcPlineSplitBySI
lcPlineSplitBySI.restype = wt.HANDLE
lcPlineSplitBySI.argtypes = [wt.HANDLE, wt.BOOL, wt.BOOL]


#  Bezier Vertices

lcBezierAddVer = litecad.lcBezierAddVer
lcBezierAddVer.restype = wt.HANDLE
lcBezierAddVer.argtypes = [wt.HANDLE, wt.HANDLE, ct.c_double, ct.c_double]

lcBezierEnd = litecad.lcBezierEnd
lcBezierEnd.restype = wt.BOOL
lcBezierEnd.argtypes = [wt.HANDLE]

lcBezierSetVerPrm = litecad.lcBezierSetVerPrm
lcBezierSetVerPrm.restype = wt.BOOL
lcBezierSetVerPrm.argtypes = [wt.HANDLE, wt.HANDLE, ct.c_int, ct.c_double, ct.c_double]


#  Mline Vertices

lcMlineAddVer = litecad.lcMlineAddVer
lcMlineAddVer.restype = wt.HANDLE
lcMlineAddVer.argtypes = [wt.HANDLE, wt.HANDLE, ct.c_double, ct.c_double]

lcMlineAddVerDir = litecad.lcMlineAddVerDir
lcMlineAddVerDir.restype = wt.HANDLE
lcMlineAddVerDir.argtypes = [wt.HANDLE, wt.HANDLE, ct.c_double, ct.c_double]

lcMlineDeleteVer = litecad.lcMlineDeleteVer
lcMlineDeleteVer.restype = wt.BOOL
lcMlineDeleteVer.argtypes = [wt.HANDLE, wt.HANDLE]

lcMlineGetFirstVer = litecad.lcMlineGetFirstVer
lcMlineGetFirstVer.restype = wt.HANDLE
lcMlineGetFirstVer.argtypes = [wt.HANDLE]

lcMlineGetNextVer = litecad.lcMlineGetNextVer
lcMlineGetNextVer.restype = wt.HANDLE
lcMlineGetNextVer.argtypes = [wt.HANDLE, wt.HANDLE]

lcMlineGetLastVer = litecad.lcMlineGetLastVer
lcMlineGetLastVer.restype = wt.HANDLE
lcMlineGetLastVer.argtypes = [wt.HANDLE]

lcMlineGetPrevVer = litecad.lcMlineGetPrevVer
lcMlineGetPrevVer.restype = wt.HANDLE
lcMlineGetPrevVer.argtypes = [wt.HANDLE, wt.HANDLE]

lcMlineGetVer = litecad.lcMlineGetVer
lcMlineGetVer.restype = wt.HANDLE
lcMlineGetVer.argtypes = [wt.HANDLE, ct.c_int]

lcMlineGetVerPt = litecad.lcMlineGetVerPt
lcMlineGetVerPt.restype = wt.HANDLE
lcMlineGetVerPt.argtypes = [wt.HANDLE, ct.c_double, ct.c_double, ct.c_double]

lcMlineGetSeg = litecad.lcMlineGetSeg
lcMlineGetSeg.restype = wt.HANDLE
lcMlineGetSeg.argtypes = [wt.HANDLE, ct.c_double, ct.c_double, ct.c_double]

lcMlineReverse = litecad.lcMlineReverse
lcMlineReverse.restype = wt.BOOL
lcMlineReverse.argtypes = [wt.HANDLE]


#  RPlan functions

lcRPlanAddVer = litecad.lcRPlanAddVer
lcRPlanAddVer.restype = wt.HANDLE
lcRPlanAddVer.argtypes = [wt.HANDLE, ct.c_double, ct.c_double]

lcRPlanSetCurve = litecad.lcRPlanSetCurve
lcRPlanSetCurve.restype = wt.BOOL
lcRPlanSetCurve.argtypes = [wt.HANDLE, ct.c_double, ct.c_double, ct.c_double]

lcRPlanSetPos = litecad.lcRPlanSetPos
lcRPlanSetPos.restype = wt.BOOL
lcRPlanSetPos.argtypes = [wt.HANDLE, ct.c_double, ct.c_double]

lcRPlanDeleteVer = litecad.lcRPlanDeleteVer
lcRPlanDeleteVer.restype = wt.BOOL
lcRPlanDeleteVer.argtypes = [wt.HANDLE, wt.HANDLE]

lcRPlanGetFirstVer = litecad.lcRPlanGetFirstVer
lcRPlanGetFirstVer.restype = wt.HANDLE
lcRPlanGetFirstVer.argtypes = [wt.HANDLE]

lcRPlanGetNextVer = litecad.lcRPlanGetNextVer
lcRPlanGetNextVer.restype = wt.HANDLE
lcRPlanGetNextVer.argtypes = [wt.HANDLE, wt.HANDLE]

lcRPlanGetLastVer = litecad.lcRPlanGetLastVer
lcRPlanGetLastVer.restype = wt.HANDLE
lcRPlanGetLastVer.argtypes = [wt.HANDLE]

lcRPlanGetPrevVer = litecad.lcRPlanGetPrevVer
lcRPlanGetPrevVer.restype = wt.HANDLE
lcRPlanGetPrevVer.argtypes = [wt.HANDLE, wt.HANDLE]

lcRPlanGetVer = litecad.lcRPlanGetVer
lcRPlanGetVer.restype = wt.HANDLE
lcRPlanGetVer.argtypes = [wt.HANDLE, ct.c_int]

lcRPlanGetPoint = litecad.lcRPlanGetPoint
lcRPlanGetPoint.restype = wt.BOOL
lcRPlanGetPoint.argtypes = [wt.HANDLE, ct.c_double, ct.POINTER(ct.c_double), ct.POINTER(ct.c_double), ct.POINTER(ct.c_double), ct.POINTER(ct.c_int)]

lcRPlanGetDist = litecad.lcRPlanGetDist
lcRPlanGetDist.restype = wt.BOOL
lcRPlanGetDist.argtypes = [wt.HANDLE, ct.c_double, ct.c_double, ct.POINTER(ct.c_double), ct.POINTER(ct.c_double), ct.POINTER(ct.c_double), ct.POINTER(ct.c_double)]

lcRPlanWriteCSV = litecad.lcRPlanWriteCSV
lcRPlanWriteCSV.restype = wt.BOOL
lcRPlanWriteCSV.argtypes = [wt.HANDLE, wt.LPCWSTR]


#  Construction line

lcXlinePutDir = litecad.lcXlinePutDir
lcXlinePutDir.restype = wt.BOOL
lcXlinePutDir.argtypes = [wt.HANDLE, ct.c_double, ct.c_double]


#  Rectangle

lcRectGetPolyline = litecad.lcRectGetPolyline
lcRectGetPolyline.restype = ct.c_int
lcRectGetPolyline.argtypes = [wt.HANDLE, ct.POINTER(ct.c_double), ct.POINTER(ct.c_double), ct.POINTER(ct.c_double)]


#  Circle


#  Image reference 

lcImgRefGetPixel = litecad.lcImgRefGetPixel
lcImgRefGetPixel.restype = wt.BOOL
lcImgRefGetPixel.argtypes = [wt.HANDLE, ct.c_int, ct.c_int, ct.POINTER(ct.c_double), ct.POINTER(ct.c_double), ct.POINTER(ct.c_int)]

lcImgRefResize = litecad.lcImgRefResize
lcImgRefResize.restype = wt.BOOL
lcImgRefResize.argtypes = [wt.HANDLE, ct.c_int, ct.c_int, ct.c_int]


#  Hatch

lcHatchSetPattern = litecad.lcHatchSetPattern
lcHatchSetPattern.restype = wt.BOOL
lcHatchSetPattern.argtypes = [wt.HANDLE, wt.LPCWSTR, wt.LPCWSTR, ct.c_double, ct.c_double]

lcHatchBoundStart = litecad.lcHatchBoundStart
lcHatchBoundStart.restype = wt.BOOL
lcHatchBoundStart.argtypes = [wt.HANDLE]

lcHatchBoundPoint = litecad.lcHatchBoundPoint
lcHatchBoundPoint.restype = wt.BOOL
lcHatchBoundPoint.argtypes = [wt.HANDLE, ct.c_double, ct.c_double]

lcHatchBoundEntity = litecad.lcHatchBoundEntity
lcHatchBoundEntity.restype = wt.BOOL
lcHatchBoundEntity.argtypes = [wt.HANDLE, wt.HANDLE]

lcHatchBoundEndLoop = litecad.lcHatchBoundEndLoop
lcHatchBoundEndLoop.restype = wt.BOOL
lcHatchBoundEndLoop.argtypes = [wt.HANDLE]

lcHatchBoundEnd = litecad.lcHatchBoundEnd
lcHatchBoundEnd.restype = wt.BOOL
lcHatchBoundEnd.argtypes = [wt.HANDLE]

lcHatchPatStart = litecad.lcHatchPatStart
lcHatchPatStart.restype = wt.BOOL
lcHatchPatStart.argtypes = [wt.HANDLE]

lcHatchPatLine = litecad.lcHatchPatLine
lcHatchPatLine.restype = wt.BOOL
lcHatchPatLine.argtypes = [wt.HANDLE, ct.c_double, ct.c_double, ct.c_double, ct.c_double, ct.c_double, ct.c_int, ct.c_double, ct.c_double, ct.c_double, ct.c_double, ct.c_double, ct.c_double, ct.c_double, ct.c_double]

lcHatchPatEnd = litecad.lcHatchPatEnd
lcHatchPatEnd.restype = wt.BOOL
lcHatchPatEnd.argtypes = [wt.HANDLE]

lcHatchGetLoopSize = litecad.lcHatchGetLoopSize
lcHatchGetLoopSize.restype = ct.c_int
lcHatchGetLoopSize.argtypes = [wt.HANDLE, ct.c_int]

lcHatchGetPoint = litecad.lcHatchGetPoint
lcHatchGetPoint.restype = wt.BOOL
lcHatchGetPoint.argtypes = [wt.HANDLE, ct.c_int, ct.POINTER(ct.c_double), ct.POINTER(ct.c_double)]

lcHatchGetEnt = litecad.lcHatchGetEnt
lcHatchGetEnt.restype = wt.HANDLE
lcHatchGetEnt.argtypes = [wt.HANDLE, ct.c_int]


#  Viewport

lcVportSetView = litecad.lcVportSetView
lcVportSetView.restype = wt.BOOL
lcVportSetView.argtypes = [wt.HANDLE, ct.c_double, ct.c_double, ct.c_double, ct.c_double]

lcVportLayerDlg = litecad.lcVportLayerDlg
lcVportLayerDlg.restype = wt.BOOL
lcVportLayerDlg.argtypes = [wt.HANDLE, wt.HANDLE]

lcVportLayerCmd = litecad.lcVportLayerCmd
lcVportLayerCmd.restype = wt.BOOL
lcVportLayerCmd.argtypes = [wt.HANDLE, ct.c_int, wt.HANDLE]


#  Block attribute

lcBlkRefAddAtt = litecad.lcBlkRefAddAtt
lcBlkRefAddAtt.restype = wt.HANDLE
lcBlkRefAddAtt.argtypes = [wt.HANDLE, wt.LPCWSTR, wt.LPCWSTR]

lcBlkRefGetFirstAtt = litecad.lcBlkRefGetFirstAtt
lcBlkRefGetFirstAtt.restype = wt.HANDLE
lcBlkRefGetFirstAtt.argtypes = [wt.HANDLE]

lcBlkRefGetNextAtt = litecad.lcBlkRefGetNextAtt
lcBlkRefGetNextAtt.restype = wt.HANDLE
lcBlkRefGetNextAtt.argtypes = [wt.HANDLE, wt.HANDLE]

lcBlkRefGetAtt = litecad.lcBlkRefGetAtt
lcBlkRefGetAtt.restype = wt.HANDLE
lcBlkRefGetAtt.argtypes = [wt.HANDLE, wt.LPCWSTR]

lcBlkRefGetAttVal = litecad.lcBlkRefGetAttVal
lcBlkRefGetAttVal.restype = wt.LPCWSTR
lcBlkRefGetAttVal.argtypes = [wt.HANDLE, wt.LPCWSTR]

lcBlkRefPutAttVal = litecad.lcBlkRefPutAttVal
lcBlkRefPutAttVal.restype = wt.BOOL
lcBlkRefPutAttVal.argtypes = [wt.HANDLE, wt.LPCWSTR, wt.LPCWSTR]


#  Shape

lcShapeAddEnt = litecad.lcShapeAddEnt
lcShapeAddEnt.restype = wt.BOOL
lcShapeAddEnt.argtypes = [wt.HANDLE, wt.HANDLE, wt.BOOL]

lcShapeEnd = litecad.lcShapeEnd
lcShapeEnd.restype = wt.BOOL
lcShapeEnd.argtypes = [wt.HANDLE]

lcShapeGetFirstEnt = litecad.lcShapeGetFirstEnt
lcShapeGetFirstEnt.restype = wt.HANDLE
lcShapeGetFirstEnt.argtypes = [wt.HANDLE]

lcShapeGetNextEnt = litecad.lcShapeGetNextEnt
lcShapeGetNextEnt.restype = wt.HANDLE
lcShapeGetNextEnt.argtypes = [wt.HANDLE, wt.HANDLE]

lcShapeGetLastEnt = litecad.lcShapeGetLastEnt
lcShapeGetLastEnt.restype = wt.HANDLE
lcShapeGetLastEnt.argtypes = [wt.HANDLE]

lcShapeGetPrevEnt = litecad.lcShapeGetPrevEnt
lcShapeGetPrevEnt.restype = wt.HANDLE
lcShapeGetPrevEnt.argtypes = [wt.HANDLE, wt.HANDLE]


#  TIN entity //(also LC_PROP_TIN_FILENAME and others, lcBlockGetTIN )

lcTIN_AddPoint = litecad.lcTIN_AddPoint
lcTIN_AddPoint.restype = wt.HANDLE
lcTIN_AddPoint.argtypes = [wt.HANDLE, wt.LPCWSTR, ct.c_double, ct.c_double, ct.c_double]

lcTIN_PtypeGetByName = litecad.lcTIN_PtypeGetByName
lcTIN_PtypeGetByName.restype = wt.HANDLE
lcTIN_PtypeGetByName.argtypes = [wt.HANDLE, wt.LPCWSTR]

lcTIN_PtypeGetFirst = litecad.lcTIN_PtypeGetFirst
lcTIN_PtypeGetFirst.restype = wt.HANDLE
lcTIN_PtypeGetFirst.argtypes = [wt.HANDLE]

lcTIN_PtypeGetNext = litecad.lcTIN_PtypeGetNext
lcTIN_PtypeGetNext.restype = wt.HANDLE
lcTIN_PtypeGetNext.argtypes = [wt.HANDLE, wt.HANDLE]

lcTIN_PntGetFirst = litecad.lcTIN_PntGetFirst
lcTIN_PntGetFirst.restype = wt.HANDLE
lcTIN_PntGetFirst.argtypes = [wt.HANDLE]

lcTIN_PntGetNext = litecad.lcTIN_PntGetNext
lcTIN_PntGetNext.restype = wt.HANDLE
lcTIN_PntGetNext.argtypes = [wt.HANDLE, wt.HANDLE]

lcTIN_PntGetNear = litecad.lcTIN_PntGetNear
lcTIN_PntGetNear.restype = wt.HANDLE
lcTIN_PntGetNear.argtypes = [wt.HANDLE, ct.c_double, ct.c_double]

lcTIN_PntDelDup = litecad.lcTIN_PntDelDup
lcTIN_PntDelDup.restype = ct.c_int
lcTIN_PntDelDup.argtypes = [wt.HANDLE, ct.c_double, wt.HANDLE]

lcTIN_TriGetFirst = litecad.lcTIN_TriGetFirst
lcTIN_TriGetFirst.restype = wt.HANDLE
lcTIN_TriGetFirst.argtypes = [wt.HANDLE]

lcTIN_TriGetNext = litecad.lcTIN_TriGetNext
lcTIN_TriGetNext.restype = wt.HANDLE
lcTIN_TriGetNext.argtypes = [wt.HANDLE, wt.HANDLE]

lcTIN_TriGetByPos = litecad.lcTIN_TriGetByPos
lcTIN_TriGetByPos.restype = wt.HANDLE
lcTIN_TriGetByPos.argtypes = [wt.HANDLE, ct.c_double, ct.c_double]

lcTIN_TriGetEdge = litecad.lcTIN_TriGetEdge
lcTIN_TriGetEdge.restype = wt.BOOL
lcTIN_TriGetEdge.argtypes = [wt.HANDLE, wt.HANDLE, ct.c_int]

lcTIN_TriUpdate = litecad.lcTIN_TriUpdate
lcTIN_TriUpdate.restype = ct.c_int
lcTIN_TriUpdate.argtypes = [wt.HANDLE, wt.HANDLE]

lcTIN_Bnd = litecad.lcTIN_Bnd
lcTIN_Bnd.restype = wt.BOOL
lcTIN_Bnd.argtypes = [wt.HANDLE, ct.c_double, wt.HANDLE]

lcTIN_BndGetPoint = litecad.lcTIN_BndGetPoint
lcTIN_BndGetPoint.restype = wt.HANDLE
lcTIN_BndGetPoint.argtypes = [wt.HANDLE, ct.c_int]

lcTIN_Triangulate = litecad.lcTIN_Triangulate
lcTIN_Triangulate.restype = wt.BOOL
lcTIN_Triangulate.argtypes = [wt.HANDLE, wt.HANDLE]

lcTIN_Isolines = litecad.lcTIN_Isolines
lcTIN_Isolines.restype = ct.c_int
lcTIN_Isolines.argtypes = [wt.HANDLE, ct.c_double, ct.c_int, wt.HANDLE]

lcTIN_IsoGetFirst = litecad.lcTIN_IsoGetFirst
lcTIN_IsoGetFirst.restype = wt.HANDLE
lcTIN_IsoGetFirst.argtypes = [wt.HANDLE]

lcTIN_IsoGetNext = litecad.lcTIN_IsoGetNext
lcTIN_IsoGetNext.restype = wt.HANDLE
lcTIN_IsoGetNext.argtypes = [wt.HANDLE, wt.HANDLE]

lcTIN_IsoMakeLabels = litecad.lcTIN_IsoMakeLabels
lcTIN_IsoMakeLabels.restype = ct.c_int
lcTIN_IsoMakeLabels.argtypes = [wt.HANDLE]

lcTIN_GetIsoLabel = litecad.lcTIN_GetIsoLabel
lcTIN_GetIsoLabel.restype = wt.BOOL
lcTIN_GetIsoLabel.argtypes = [ct.c_int, ct.POINTER(ct.c_double), ct.POINTER(ct.c_double), ct.POINTER(ct.c_double), ct.POINTER(ct.c_int)]

lcTIN_GetZ = litecad.lcTIN_GetZ
lcTIN_GetZ.restype = wt.BOOL
lcTIN_GetZ.argtypes = [wt.HANDLE, ct.c_double, ct.c_double, ct.POINTER(ct.c_double)]

lcTIN_ColorFill = litecad.lcTIN_ColorFill
lcTIN_ColorFill.restype = wt.BOOL
lcTIN_ColorFill.argtypes = [wt.HANDLE, ct.c_double, ct.c_double, wt.HANDLE]

lcTIN_Save = litecad.lcTIN_Save
lcTIN_Save.restype = wt.BOOL
lcTIN_Save.argtypes = [wt.HANDLE, wt.LPCWSTR, ct.c_int, wt.BOOL, wt.HANDLE]

lcTIN_InterLine = litecad.lcTIN_InterLine
lcTIN_InterLine.restype = ct.c_int
lcTIN_InterLine.argtypes = [wt.HANDLE, ct.c_double, ct.c_double, ct.c_double, ct.c_double]

lcTIN_InterGetPoint = litecad.lcTIN_InterGetPoint
lcTIN_InterGetPoint.restype = wt.BOOL
lcTIN_InterGetPoint.argtypes = [wt.HANDLE, ct.c_int, ct.POINTER(ct.c_double), ct.POINTER(ct.c_double), ct.POINTER(ct.c_double)]

lcTIN_Clear = litecad.lcTIN_Clear
lcTIN_Clear.restype = wt.BOOL
lcTIN_Clear.argtypes = [wt.HANDLE]

lcTIN_AddTrian = litecad.lcTIN_AddTrian
lcTIN_AddTrian.restype = wt.HANDLE
lcTIN_AddTrian.argtypes = [wt.HANDLE, ct.c_int, ct.c_int, ct.c_int]

lcTIN_BndAddPnt = litecad.lcTIN_BndAddPnt
lcTIN_BndAddPnt.restype = wt.BOOL
lcTIN_BndAddPnt.argtypes = [wt.HANDLE, ct.c_int]

lcTIN_Merge = litecad.lcTIN_Merge
lcTIN_Merge.restype = wt.BOOL
lcTIN_Merge.argtypes = [wt.HANDLE, wt.LPCWSTR, wt.HANDLE]

lcColorRGB = litecad.lcColorRGB
lcColorRGB.restype = ct.c_int
lcColorRGB.argtypes = [ct.c_int, ct.c_int, ct.c_int]


#  Color from string

lcColorIsRGB = litecad.lcColorIsRGB
lcColorIsRGB.restype = wt.BOOL
lcColorIsRGB.argtypes = [wt.LPCWSTR]

lcColorGetRed = litecad.lcColorGetRed
lcColorGetRed.restype = ct.c_int
lcColorGetRed.argtypes = [wt.LPCWSTR]

lcColorGetGreen = litecad.lcColorGetGreen
lcColorGetGreen.restype = ct.c_int
lcColorGetGreen.argtypes = [wt.LPCWSTR]

lcColorGetBlue = litecad.lcColorGetBlue
lcColorGetBlue.restype = ct.c_int
lcColorGetBlue.argtypes = [wt.LPCWSTR]

lcColorGetIndex = litecad.lcColorGetIndex
lcColorGetIndex.restype = ct.c_int
lcColorGetIndex.argtypes = [wt.LPCWSTR, wt.BOOL]

lcColorToVal = litecad.lcColorToVal
lcColorToVal.restype = wt.BOOL
lcColorToVal.argtypes = [wt.LPCWSTR, ct.POINTER(ct.c_int), ct.POINTER(ct.c_int), ct.POINTER(ct.c_int), ct.POINTER(ct.c_int), ct.POINTER(ct.c_int)]


#  Color palette

lcColorSetPalette = litecad.lcColorSetPalette
lcColorSetPalette.restype = wt.BOOL
lcColorSetPalette.argtypes = [ct.c_int, ct.c_int, ct.c_int, ct.c_int]

lcColorGetPalette = litecad.lcColorGetPalette
lcColorGetPalette.restype = wt.BOOL
lcColorGetPalette.argtypes = [ct.c_int, ct.POINTER(ct.c_int), ct.POINTER(ct.c_int), ct.POINTER(ct.c_int)]

lcColorSavePalette = litecad.lcColorSavePalette
lcColorSavePalette.restype = wt.BOOL
lcColorSavePalette.argtypes = [wt.LPCWSTR, wt.HANDLE]

lcColorLoadPalette = litecad.lcColorLoadPalette
lcColorLoadPalette.restype = wt.BOOL
lcColorLoadPalette.argtypes = [wt.LPCWSTR, wt.HANDLE]


#  Image

lcImageSetPixelRGB = litecad.lcImageSetPixelRGB
lcImageSetPixelRGB.restype = wt.BOOL
lcImageSetPixelRGB.argtypes = [wt.HANDLE, ct.c_int, ct.c_int, ct.c_int, ct.c_int, ct.c_int]

lcImageSetPixelI = litecad.lcImageSetPixelI
lcImageSetPixelI.restype = wt.BOOL
lcImageSetPixelI.argtypes = [wt.HANDLE, ct.c_int, ct.c_int, ct.c_int]

lcImageGetPixelRGB = litecad.lcImageGetPixelRGB
lcImageGetPixelRGB.restype = wt.BOOL
lcImageGetPixelRGB.argtypes = [wt.HANDLE, ct.c_int, ct.c_int, ct.POINTER(ct.c_int), ct.POINTER(ct.c_int), ct.POINTER(ct.c_int)]

lcImageGetPixelI = litecad.lcImageGetPixelI
lcImageGetPixelI.restype = wt.BOOL
lcImageGetPixelI.argtypes = [wt.HANDLE, ct.c_int, ct.c_int, ct.POINTER(ct.c_int)]

lcImageSetPalColor = litecad.lcImageSetPalColor
lcImageSetPalColor.restype = wt.BOOL
lcImageSetPalColor.argtypes = [wt.HANDLE, ct.c_int, ct.c_int, ct.c_int, ct.c_int]

lcImageGetPalColor = litecad.lcImageGetPalColor
lcImageGetPalColor.restype = wt.BOOL
lcImageGetPalColor.argtypes = [wt.HANDLE, ct.c_int, ct.POINTER(ct.c_int), ct.POINTER(ct.c_int), ct.POINTER(ct.c_int)]

lcImageLoad = litecad.lcImageLoad
lcImageLoad.restype = wt.BOOL
lcImageLoad.argtypes = [wt.HANDLE, wt.LPCWSTR, wt.HANDLE]

lcImageLoadDIB = litecad.lcImageLoadDIB
lcImageLoadDIB.restype = wt.BOOL
lcImageLoadDIB.argtypes = [wt.HANDLE, wt.HANDLE]

lcImageLoadCamera = litecad.lcImageLoadCamera
lcImageLoadCamera.restype = wt.BOOL
lcImageLoadCamera.argtypes = [wt.HANDLE]

lcImageCopyQuad = litecad.lcImageCopyQuad
lcImageCopyQuad.restype = wt.BOOL
lcImageCopyQuad.argtypes = [wt.HANDLE, wt.HANDLE, wt.UINT, wt.UINT, ct.c_double, ct.c_double, ct.c_double, ct.c_double, ct.c_double, ct.c_double, ct.c_double, ct.c_double]

lcImageProc = litecad.lcImageProc
lcImageProc.restype = wt.BOOL
lcImageProc.argtypes = [wt.HANDLE, ct.c_int]


#  Toolbar Window


#  explode entity to polylines, Flags is LC_EXP_ALL or other

lcExpEntity = litecad.lcExpEntity
lcExpEntity.restype = ct.c_int
lcExpEntity.argtypes = [wt.HANDLE, ct.c_int, ct.c_int, wt.BOOL]

lcExpGetPline = litecad.lcExpGetPline
lcExpGetPline.restype = ct.c_int
lcExpGetPline.argtypes = [ct.c_double]

lcExpGetVertex = litecad.lcExpGetVertex
lcExpGetVertex.restype = wt.BOOL
lcExpGetVertex.argtypes = [ct.POINTER(ct.c_double), ct.POINTER(ct.c_double)]

lcGbrLoad = litecad.lcGbrLoad
lcGbrLoad.restype = wt.BOOL
lcGbrLoad.argtypes = [wt.HANDLE, wt.LPCWSTR]

lcGbrClose = litecad.lcGbrClose
lcGbrClose.restype = wt.BOOL
lcGbrClose.argtypes = [wt.HANDLE]

lcPlugGetOption = litecad.lcPlugGetOption
lcPlugGetOption.restype = wt.LPCWSTR
lcPlugGetOption.argtypes = [wt.LPCWSTR, wt.LPCWSTR]

lcPlugGetOption2 = litecad.lcPlugGetOption2
lcPlugGetOption2.restype = wt.BOOL
lcPlugGetOption2.argtypes = [wt.LPCWSTR, wt.LPCWSTR]

lcPlugSetOption = litecad.lcPlugSetOption
lcPlugSetOption.restype = wt.BOOL
lcPlugSetOption.argtypes = [wt.LPCWSTR, wt.LPCWSTR, wt.LPCWSTR, wt.BOOL]

lcPrintSetup = litecad.lcPrintSetup
lcPrintSetup.restype = ct.c_int
lcPrintSetup.argtypes = [wt.HANDLE]

lcPrintLayout = litecad.lcPrintLayout
lcPrintLayout.restype = wt.BOOL
lcPrintLayout.argtypes = [wt.HANDLE]

lcPrintBlock = litecad.lcPrintBlock
lcPrintBlock.restype = wt.BOOL
lcPrintBlock.argtypes = [wt.HANDLE, ct.c_double, ct.c_double, ct.c_double, ct.c_double, ct.c_double, ct.c_double, ct.c_double, ct.c_int]

lcXDataBegin = litecad.lcXDataBegin
lcXDataBegin.restype = wt.HANDLE

lcXDataEnd = litecad.lcXDataEnd
lcXDataEnd.restype = ct.c_int
lcXDataEnd.argtypes = [wt.HANDLE]

lcXDataClear = litecad.lcXDataClear
lcXDataClear.restype = wt.BOOL
lcXDataClear.argtypes = [wt.HANDLE]

lcXDataSet = litecad.lcXDataSet
lcXDataSet.restype = wt.BOOL
lcXDataSet.argtypes = [wt.HANDLE]


#  NoDB mode ////////////////////////////////////////////////////////////////////////////////////////


#  Window Tabs

lcWndTabClear = litecad.lcWndTabClear
lcWndTabClear.restype = wt.BOOL
lcWndTabClear.argtypes = [wt.HANDLE]

lcWndTabAdd = litecad.lcWndTabAdd
lcWndTabAdd.restype = wt.BOOL
lcWndTabAdd.argtypes = [wt.HANDLE, ct.c_int, wt.LPCWSTR, wt.LPCWSTR, wt.HANDLE]

lcWndTabSelect = litecad.lcWndTabSelect
lcWndTabSelect.restype = wt.BOOL
lcWndTabSelect.argtypes = [wt.HANDLE, ct.c_int]


#  Paper

lcWndPaperEnable = litecad.lcWndPaperEnable
lcWndPaperEnable.restype = wt.BOOL
lcWndPaperEnable.argtypes = [wt.HANDLE, wt.BOOL]

lcWndPaperSetSize = litecad.lcWndPaperSetSize
lcWndPaperSetSize.restype = wt.BOOL
lcWndPaperSetSize.argtypes = [wt.HANDLE, ct.c_int, ct.c_int]

lcWndPaperSetSize2 = litecad.lcWndPaperSetSize2
lcWndPaperSetSize2.restype = wt.BOOL
lcWndPaperSetSize2.argtypes = [wt.HANDLE, ct.c_double, ct.c_double]

lcWndPaperSetPos = litecad.lcWndPaperSetPos
lcWndPaperSetPos.restype = wt.BOOL
lcWndPaperSetPos.argtypes = [wt.HANDLE, ct.c_double, ct.c_double]


#  Grips

lcGripClear = litecad.lcGripClear
lcGripClear.restype = wt.BOOL
lcGripClear.argtypes = [wt.HANDLE]

lcGripAdd = litecad.lcGripAdd
lcGripAdd.restype = wt.BOOL
lcGripAdd.argtypes = [wt.HANDLE, wt.HANDLE, ct.c_int, ct.c_int, ct.c_double, ct.c_double, ct.c_double, ct.c_double, ct.c_double]

lcGripSet = litecad.lcGripSet
lcGripSet.restype = wt.BOOL
lcGripSet.argtypes = [wt.HANDLE, wt.HANDLE, ct.c_int, ct.c_double, ct.c_double, ct.c_double, ct.c_double, ct.c_double]


#  to draw inside of Paint event procedure

lcPaint_PenCreate = litecad.lcPaint_PenCreate
lcPaint_PenCreate.restype = wt.HANDLE
lcPaint_PenCreate.argtypes = [wt.HANDLE, ct.c_int, wt.COLORREF, ct.c_double, ct.c_int]

lcPaint_PenSelect = litecad.lcPaint_PenSelect
lcPaint_PenSelect.restype = wt.BOOL
lcPaint_PenSelect.argtypes = [wt.HANDLE, wt.HANDLE]

lcPaint_PenSelectID = litecad.lcPaint_PenSelectID
lcPaint_PenSelectID.restype = wt.BOOL
lcPaint_PenSelectID.argtypes = [wt.HANDLE, ct.c_int]

lcPaint_BrushCreate = litecad.lcPaint_BrushCreate
lcPaint_BrushCreate.restype = wt.HANDLE
lcPaint_BrushCreate.argtypes = [wt.HANDLE, ct.c_int, wt.COLORREF, ct.c_int, ct.c_int]

lcPaint_BrushSelect = litecad.lcPaint_BrushSelect
lcPaint_BrushSelect.restype = wt.BOOL
lcPaint_BrushSelect.argtypes = [wt.HANDLE, wt.HANDLE]

lcPaint_BrushSelectID = litecad.lcPaint_BrushSelectID
lcPaint_BrushSelectID.restype = wt.BOOL
lcPaint_BrushSelectID.argtypes = [wt.HANDLE, ct.c_int]

lcPaint_DrawPtbuf = litecad.lcPaint_DrawPtbuf
lcPaint_DrawPtbuf.restype = wt.BOOL
lcPaint_DrawPtbuf.argtypes = [wt.HANDLE, wt.HANDLE, wt.BOOL]

lcPaint_DrawMpgon = litecad.lcPaint_DrawMpgon
lcPaint_DrawMpgon.restype = wt.BOOL
lcPaint_DrawMpgon.argtypes = [wt.HANDLE, wt.HANDLE, wt.BOOL, wt.BOOL]

lcPaint_DrawImage = litecad.lcPaint_DrawImage
lcPaint_DrawImage.restype = wt.BOOL
lcPaint_DrawImage.argtypes = [wt.HANDLE, wt.HANDLE, ct.c_double, ct.c_double, ct.c_double, ct.c_int, ct.c_int, wt.HANDLE]

lcPaint_DrawImage2 = litecad.lcPaint_DrawImage2
lcPaint_DrawImage2.restype = wt.BOOL
lcPaint_DrawImage2.argtypes = [wt.HANDLE, wt.HANDLE, ct.c_double, ct.c_double, ct.c_double, ct.c_double, ct.c_int, ct.c_int, wt.HANDLE]

lcPaint_DrawText = litecad.lcPaint_DrawText
lcPaint_DrawText.restype = wt.BOOL
lcPaint_DrawText.argtypes = [wt.HANDLE, ct.c_double, ct.c_double, wt.LPCWSTR]

lcPaint_DrawText2 = litecad.lcPaint_DrawText2
lcPaint_DrawText2.restype = wt.BOOL
lcPaint_DrawText2.argtypes = [wt.HANDLE, ct.c_double, ct.c_double, ct.c_double, ct.c_double, ct.c_int, wt.LPCWSTR]

lcPaint_DrawTextBC = litecad.lcPaint_DrawTextBC
lcPaint_DrawTextBC.restype = wt.BOOL
lcPaint_DrawTextBC.argtypes = [wt.HANDLE, wt.HANDLE, ct.c_double, ct.c_double, ct.c_int, wt.LPCWSTR]

lcPaint_DrawArcText = litecad.lcPaint_DrawArcText
lcPaint_DrawArcText.restype = wt.BOOL
lcPaint_DrawArcText.argtypes = [wt.HANDLE, wt.LPCWSTR, ct.c_double, ct.c_double, ct.c_double, ct.c_double, wt.BOOL, ct.c_double, ct.c_double, ct.c_int]

lcPaint_DrawHatch = litecad.lcPaint_DrawHatch
lcPaint_DrawHatch.restype = wt.BOOL
lcPaint_DrawHatch.argtypes = [wt.HANDLE, wt.HANDLE]

lcPaint_DrawPoint = litecad.lcPaint_DrawPoint
lcPaint_DrawPoint.restype = wt.BOOL
lcPaint_DrawPoint.argtypes = [wt.HANDLE, ct.c_double, ct.c_double, ct.c_int, ct.c_double]

lcPaint_DrawLine = litecad.lcPaint_DrawLine
lcPaint_DrawLine.restype = wt.BOOL
lcPaint_DrawLine.argtypes = [wt.HANDLE, ct.c_double, ct.c_double, ct.c_double, ct.c_double]

lcPaint_DrawXline = litecad.lcPaint_DrawXline
lcPaint_DrawXline.restype = wt.BOOL
lcPaint_DrawXline.argtypes = [wt.HANDLE, ct.c_double, ct.c_double, ct.c_double, wt.BOOL]

lcPaint_DrawRect = litecad.lcPaint_DrawRect
lcPaint_DrawRect.restype = wt.BOOL
lcPaint_DrawRect.argtypes = [wt.HANDLE, ct.c_double, ct.c_double, ct.c_double, ct.c_double]

lcPaint_DrawRect2 = litecad.lcPaint_DrawRect2
lcPaint_DrawRect2.restype = wt.BOOL
lcPaint_DrawRect2.argtypes = [wt.HANDLE, ct.c_double, ct.c_double, ct.c_double, ct.c_double]

lcPaint_DrawPickBox = litecad.lcPaint_DrawPickBox
lcPaint_DrawPickBox.restype = wt.BOOL
lcPaint_DrawPickBox.argtypes = [wt.HANDLE]

lcPaint_DrawGrid = litecad.lcPaint_DrawGrid
lcPaint_DrawGrid.restype = wt.BOOL
lcPaint_DrawGrid.argtypes = [wt.HANDLE, wt.HANDLE, wt.BOOL, wt.COLORREF, wt.COLORREF]

lcPaint_DrawCPrompt = litecad.lcPaint_DrawCPrompt
lcPaint_DrawCPrompt.restype = wt.BOOL
lcPaint_DrawCPrompt.argtypes = [wt.HANDLE, ct.c_int, ct.c_int, ct.c_int, wt.LPCWSTR]

lcPaint_SetPixel = litecad.lcPaint_SetPixel
lcPaint_SetPixel.restype = None
lcPaint_SetPixel.argtypes = [wt.HANDLE, ct.c_int, ct.c_int, wt.COLORREF]


#  Points buffer 

lcPaint_CreatePtbuf = litecad.lcPaint_CreatePtbuf
lcPaint_CreatePtbuf.restype = wt.HANDLE

lcPaint_DeletePtbuf = litecad.lcPaint_DeletePtbuf
lcPaint_DeletePtbuf.restype = wt.BOOL
lcPaint_DeletePtbuf.argtypes = [wt.HANDLE]

lcPaint_PtbufClear = litecad.lcPaint_PtbufClear
lcPaint_PtbufClear.restype = wt.BOOL
lcPaint_PtbufClear.argtypes = [wt.HANDLE]

lcPaint_PtbufAddPoint = litecad.lcPaint_PtbufAddPoint
lcPaint_PtbufAddPoint.restype = wt.BOOL
lcPaint_PtbufAddPoint.argtypes = [wt.HANDLE, ct.c_double, ct.c_double, ct.c_double, ct.c_double, ct.c_int]

lcPaint_PtbufAddPoint2 = litecad.lcPaint_PtbufAddPoint2
lcPaint_PtbufAddPoint2.restype = wt.BOOL
lcPaint_PtbufAddPoint2.argtypes = [wt.HANDLE, ct.c_double, ct.c_double]

lcPaint_PtbufAddPointP = litecad.lcPaint_PtbufAddPointP
lcPaint_PtbufAddPointP.restype = wt.BOOL
lcPaint_PtbufAddPointP.argtypes = [wt.HANDLE, ct.c_double, ct.c_double]

lcPaint_PtbufAddLine = litecad.lcPaint_PtbufAddLine
lcPaint_PtbufAddLine.restype = wt.BOOL
lcPaint_PtbufAddLine.argtypes = [wt.HANDLE, ct.c_double, ct.c_double, ct.c_double, ct.c_double]

lcPaint_PtbufAddLineP = litecad.lcPaint_PtbufAddLineP
lcPaint_PtbufAddLineP.restype = wt.BOOL
lcPaint_PtbufAddLineP.argtypes = [wt.HANDLE, ct.c_double, ct.c_double, ct.c_double, ct.c_double]

lcPaint_PtbufAddCircle = litecad.lcPaint_PtbufAddCircle
lcPaint_PtbufAddCircle.restype = wt.BOOL
lcPaint_PtbufAddCircle.argtypes = [wt.HANDLE, ct.c_double, ct.c_double, ct.c_double, ct.c_int]

lcPaint_PtbufAddCircle2 = litecad.lcPaint_PtbufAddCircle2
lcPaint_PtbufAddCircle2.restype = wt.BOOL
lcPaint_PtbufAddCircle2.argtypes = [wt.HANDLE, ct.c_double, ct.c_double, ct.c_double, ct.c_double, ct.c_int]

lcPaint_PtbufAddCircle3 = litecad.lcPaint_PtbufAddCircle3
lcPaint_PtbufAddCircle3.restype = wt.BOOL
lcPaint_PtbufAddCircle3.argtypes = [wt.HANDLE, ct.c_double, ct.c_double, ct.c_double, ct.c_double, ct.c_double, ct.c_double, wt.BOOL, ct.c_int]

lcPaint_PtbufAddArc = litecad.lcPaint_PtbufAddArc
lcPaint_PtbufAddArc.restype = wt.BOOL
lcPaint_PtbufAddArc.argtypes = [wt.HANDLE, ct.c_double, ct.c_double, ct.c_double, ct.c_double, ct.c_double, ct.c_int]

lcPaint_PtbufAddArc3p = litecad.lcPaint_PtbufAddArc3p
lcPaint_PtbufAddArc3p.restype = wt.BOOL
lcPaint_PtbufAddArc3p.argtypes = [wt.HANDLE, ct.c_double, ct.c_double, ct.c_double, ct.c_double, ct.c_double, ct.c_double, ct.c_int]

lcPaint_PtbufAddArcSDE = litecad.lcPaint_PtbufAddArcSDE
lcPaint_PtbufAddArcSDE.restype = wt.BOOL
lcPaint_PtbufAddArcSDE.argtypes = [wt.HANDLE, ct.c_double, ct.c_double, ct.c_double, ct.c_double, ct.c_double, ct.c_int]

lcPaint_PtbufAddArcSDAR = litecad.lcPaint_PtbufAddArcSDAR
lcPaint_PtbufAddArcSDAR.restype = wt.BOOL
lcPaint_PtbufAddArcSDAR.argtypes = [wt.HANDLE, ct.c_double, ct.c_double, ct.c_double, ct.c_double, ct.c_double, ct.c_int]

lcPaint_PtbufAddArcSER = litecad.lcPaint_PtbufAddArcSER
lcPaint_PtbufAddArcSER.restype = wt.BOOL
lcPaint_PtbufAddArcSER.argtypes = [wt.HANDLE, ct.c_double, ct.c_double, ct.c_double, ct.c_double, ct.c_double, wt.BOOL, ct.c_int]

lcPaint_PtbufAddArcSEL = litecad.lcPaint_PtbufAddArcSEL
lcPaint_PtbufAddArcSEL.restype = wt.BOOL
lcPaint_PtbufAddArcSEL.argtypes = [wt.HANDLE, ct.c_double, ct.c_double, ct.c_double, ct.c_double, ct.c_double, wt.BOOL, ct.c_int]

lcPaint_PtbufAddArcSEA = litecad.lcPaint_PtbufAddArcSEA
lcPaint_PtbufAddArcSEA.restype = wt.BOOL
lcPaint_PtbufAddArcSEA.argtypes = [wt.HANDLE, ct.c_double, ct.c_double, ct.c_double, ct.c_double, ct.c_double, ct.c_int]

lcPaint_PtbufAddArcSEB = litecad.lcPaint_PtbufAddArcSEB
lcPaint_PtbufAddArcSEB.restype = wt.BOOL
lcPaint_PtbufAddArcSEB.argtypes = [wt.HANDLE, ct.c_double, ct.c_double, ct.c_double, ct.c_double, ct.c_double, ct.c_int]

lcPaint_PtbufAddArcCSE = litecad.lcPaint_PtbufAddArcCSE
lcPaint_PtbufAddArcCSE.restype = wt.BOOL
lcPaint_PtbufAddArcCSE.argtypes = [wt.HANDLE, ct.c_double, ct.c_double, ct.c_double, ct.c_double, ct.c_double, ct.c_double, wt.BOOL, ct.c_int]

lcPaint_PtbufAddArcCSA = litecad.lcPaint_PtbufAddArcCSA
lcPaint_PtbufAddArcCSA.restype = wt.BOOL
lcPaint_PtbufAddArcCSA.argtypes = [wt.HANDLE, ct.c_double, ct.c_double, ct.c_double, ct.c_double, ct.c_double, ct.c_int]

lcPaint_PtbufAddArcCSL = litecad.lcPaint_PtbufAddArcCSL
lcPaint_PtbufAddArcCSL.restype = wt.BOOL
lcPaint_PtbufAddArcCSL.argtypes = [wt.HANDLE, ct.c_double, ct.c_double, ct.c_double, ct.c_double, ct.c_double, wt.BOOL, ct.c_int]

lcPaint_PtbufAddArcCRAA = litecad.lcPaint_PtbufAddArcCRAA
lcPaint_PtbufAddArcCRAA.restype = wt.BOOL
lcPaint_PtbufAddArcCRAA.argtypes = [wt.HANDLE, ct.c_double, ct.c_double, ct.c_double, ct.c_double, ct.c_double, wt.BOOL, ct.c_int]

lcPaint_PtbufAddEllipse = litecad.lcPaint_PtbufAddEllipse
lcPaint_PtbufAddEllipse.restype = wt.BOOL
lcPaint_PtbufAddEllipse.argtypes = [wt.HANDLE, ct.c_double, ct.c_double, ct.c_double, ct.c_double, ct.c_double, ct.c_double, ct.c_double, ct.c_int]

lcPaint_PtbufAddEllipse2 = litecad.lcPaint_PtbufAddEllipse2
lcPaint_PtbufAddEllipse2.restype = wt.BOOL
lcPaint_PtbufAddEllipse2.argtypes = [wt.HANDLE, ct.c_double, ct.c_double, ct.c_double, ct.c_double, ct.c_int]

lcPaint_PtbufAddRect = litecad.lcPaint_PtbufAddRect
lcPaint_PtbufAddRect.restype = wt.BOOL
lcPaint_PtbufAddRect.argtypes = [wt.HANDLE, ct.c_double, ct.c_double, ct.c_double, ct.c_double, ct.c_double, ct.c_double, ct.c_int]

lcPaint_PtbufAddRect2 = litecad.lcPaint_PtbufAddRect2
lcPaint_PtbufAddRect2.restype = wt.BOOL
lcPaint_PtbufAddRect2.argtypes = [wt.HANDLE, ct.c_double, ct.c_double, ct.c_double, ct.c_double, ct.c_double, ct.c_int]

lcPaint_PtbufAddRect3 = litecad.lcPaint_PtbufAddRect3
lcPaint_PtbufAddRect3.restype = wt.BOOL
lcPaint_PtbufAddRect3.argtypes = [wt.HANDLE, ct.c_double, ct.c_double, ct.c_double, ct.c_double, ct.c_double, ct.c_int, ct.c_double, ct.c_int]

lcPaint_PtbufAddWline = litecad.lcPaint_PtbufAddWline
lcPaint_PtbufAddWline.restype = wt.BOOL
lcPaint_PtbufAddWline.argtypes = [wt.HANDLE, ct.c_double, ct.c_double, ct.c_double, ct.c_double, ct.c_double, ct.c_int, wt.BOOL, ct.c_int]

lcPaint_PtbufAddPtbuf = litecad.lcPaint_PtbufAddPtbuf
lcPaint_PtbufAddPtbuf.restype = wt.BOOL
lcPaint_PtbufAddPtbuf.argtypes = [wt.HANDLE, wt.HANDLE]

lcPaint_PtbufGetPoint = litecad.lcPaint_PtbufGetPoint
lcPaint_PtbufGetPoint.restype = wt.BOOL
lcPaint_PtbufGetPoint.argtypes = [wt.HANDLE, ct.c_int, ct.POINTER(ct.c_double), ct.POINTER(ct.c_double)]

lcPaint_PtbufGetPoint2 = litecad.lcPaint_PtbufGetPoint2
lcPaint_PtbufGetPoint2.restype = wt.BOOL
lcPaint_PtbufGetPoint2.argtypes = [wt.HANDLE, ct.c_int, ct.POINTER(ct.c_double), ct.POINTER(ct.c_double), ct.POINTER(ct.c_double), ct.POINTER(ct.c_double), ct.POINTER(ct.c_int)]

lcPaint_PtbufInterpolate = litecad.lcPaint_PtbufInterpolate
lcPaint_PtbufInterpolate.restype = wt.BOOL
lcPaint_PtbufInterpolate.argtypes = [wt.HANDLE, wt.BOOL, wt.HANDLE, ct.c_int, ct.c_int]

lcPaint_PtbufMove = litecad.lcPaint_PtbufMove
lcPaint_PtbufMove.restype = wt.BOOL
lcPaint_PtbufMove.argtypes = [wt.HANDLE, ct.c_double, ct.c_double]

lcPaint_PtbufRotate = litecad.lcPaint_PtbufRotate
lcPaint_PtbufRotate.restype = wt.BOOL
lcPaint_PtbufRotate.argtypes = [wt.HANDLE, ct.c_double, ct.c_double, ct.c_double]

lcPaint_PtbufScale = litecad.lcPaint_PtbufScale
lcPaint_PtbufScale.restype = wt.BOOL
lcPaint_PtbufScale.argtypes = [wt.HANDLE, ct.c_double, ct.c_double, ct.c_double, ct.c_double]

lcPaint_PtbufMirror = litecad.lcPaint_PtbufMirror
lcPaint_PtbufMirror.restype = wt.BOOL
lcPaint_PtbufMirror.argtypes = [wt.HANDLE, ct.c_double, ct.c_double, ct.c_double, ct.c_double]

lcPaint_PtbufCopy = litecad.lcPaint_PtbufCopy
lcPaint_PtbufCopy.restype = wt.BOOL
lcPaint_PtbufCopy.argtypes = [wt.HANDLE, wt.HANDLE]


#  Multipolygon 

lcPaint_CreateMpgon = litecad.lcPaint_CreateMpgon
lcPaint_CreateMpgon.restype = wt.HANDLE

lcPaint_DeleteMpgon = litecad.lcPaint_DeleteMpgon
lcPaint_DeleteMpgon.restype = wt.BOOL
lcPaint_DeleteMpgon.argtypes = [wt.HANDLE]

lcPaint_MpgonClear = litecad.lcPaint_MpgonClear
lcPaint_MpgonClear.restype = wt.BOOL
lcPaint_MpgonClear.argtypes = [wt.HANDLE]

lcPaint_MpgonAddPgon = litecad.lcPaint_MpgonAddPgon
lcPaint_MpgonAddPgon.restype = wt.BOOL
lcPaint_MpgonAddPgon.argtypes = [wt.HANDLE, wt.HANDLE]

lcPaint_MpgonAddText = litecad.lcPaint_MpgonAddText
lcPaint_MpgonAddText.restype = wt.BOOL
lcPaint_MpgonAddText.argtypes = [wt.HANDLE, wt.HANDLE, ct.c_double, ct.c_double, wt.LPCWSTR, ct.c_int]

lcPaint_MpgonAddBarcode = litecad.lcPaint_MpgonAddBarcode
lcPaint_MpgonAddBarcode.restype = wt.BOOL
lcPaint_MpgonAddBarcode.argtypes = [wt.HANDLE, ct.c_int, ct.c_double, ct.c_double, ct.c_double, ct.c_double, wt.LPCWSTR]

lcPaint_MpgonMove = litecad.lcPaint_MpgonMove
lcPaint_MpgonMove.restype = wt.BOOL
lcPaint_MpgonMove.argtypes = [wt.HANDLE, ct.c_double, ct.c_double]

lcPaint_MpgonRotate = litecad.lcPaint_MpgonRotate
lcPaint_MpgonRotate.restype = wt.BOOL
lcPaint_MpgonRotate.argtypes = [wt.HANDLE, ct.c_double, ct.c_double, ct.c_double]

lcPaint_MpgonScale = litecad.lcPaint_MpgonScale
lcPaint_MpgonScale.restype = wt.BOOL
lcPaint_MpgonScale.argtypes = [wt.HANDLE, ct.c_double, ct.c_double, ct.c_double, ct.c_double]

lcPaint_MpgonMirror = litecad.lcPaint_MpgonMirror
lcPaint_MpgonMirror.restype = wt.BOOL
lcPaint_MpgonMirror.argtypes = [wt.HANDLE, ct.c_double, ct.c_double, ct.c_double, ct.c_double]

lcPaint_MpgonCopy = litecad.lcPaint_MpgonCopy
lcPaint_MpgonCopy.restype = wt.BOOL
lcPaint_MpgonCopy.argtypes = [wt.HANDLE, wt.HANDLE]

lcPaint_HatchGen = litecad.lcPaint_HatchGen
lcPaint_HatchGen.restype = wt.BOOL
lcPaint_HatchGen.argtypes = [wt.HANDLE, wt.HANDLE, ct.c_double, ct.c_double, ct.c_double]


#  Image 

lcPaint_ImageAdd = litecad.lcPaint_ImageAdd
lcPaint_ImageAdd.restype = wt.HANDLE
lcPaint_ImageAdd.argtypes = [ct.c_int]

lcPaint_ImageDelete = litecad.lcPaint_ImageDelete
lcPaint_ImageDelete.restype = wt.BOOL
lcPaint_ImageDelete.argtypes = [wt.HANDLE]

lcPaint_ImageGetFirst = litecad.lcPaint_ImageGetFirst
lcPaint_ImageGetFirst.restype = wt.HANDLE

lcPaint_ImageGetNext = litecad.lcPaint_ImageGetNext
lcPaint_ImageGetNext.restype = wt.HANDLE
lcPaint_ImageGetNext.argtypes = [wt.HANDLE]

lcPaint_ImageGetByID = litecad.lcPaint_ImageGetByID
lcPaint_ImageGetByID.restype = wt.HANDLE
lcPaint_ImageGetByID.argtypes = [ct.c_int]

lcPaint_ImageLoad = litecad.lcPaint_ImageLoad
lcPaint_ImageLoad.restype = wt.BOOL
lcPaint_ImageLoad.argtypes = [wt.HANDLE, wt.LPCWSTR]

lcPaint_ImageCopy = litecad.lcPaint_ImageCopy
lcPaint_ImageCopy.restype = wt.BOOL
lcPaint_ImageCopy.argtypes = [wt.HANDLE, wt.HANDLE]

lcPaint_ImageCreate = litecad.lcPaint_ImageCreate
lcPaint_ImageCreate.restype = wt.BOOL
lcPaint_ImageCreate.argtypes = [wt.HANDLE, ct.c_int, ct.c_int]

lcPaint_ImageSetPixel = litecad.lcPaint_ImageSetPixel
lcPaint_ImageSetPixel.restype = wt.BOOL
lcPaint_ImageSetPixel.argtypes = [wt.HANDLE, ct.c_int, ct.c_int, ct.c_int, ct.c_int, ct.c_int]

lcPaint_ImageFlip = litecad.lcPaint_ImageFlip
lcPaint_ImageFlip.restype = wt.BOOL
lcPaint_ImageFlip.argtypes = [wt.HANDLE, wt.BOOL, wt.BOOL]

lcPaint_ImageRotate = litecad.lcPaint_ImageRotate
lcPaint_ImageRotate.restype = wt.BOOL
lcPaint_ImageRotate.argtypes = [wt.HANDLE, ct.c_double]

lcPaint_ImageGray = litecad.lcPaint_ImageGray
lcPaint_ImageGray.restype = wt.BOOL
lcPaint_ImageGray.argtypes = [wt.HANDLE]

lcPaint_ImageResize = litecad.lcPaint_ImageResize
lcPaint_ImageResize.restype = wt.BOOL
lcPaint_ImageResize.argtypes = [wt.HANDLE, ct.c_int, ct.c_int, ct.c_int]

lcPaint_ImageGetPtbuf = litecad.lcPaint_ImageGetPtbuf
lcPaint_ImageGetPtbuf.restype = wt.HANDLE
lcPaint_ImageGetPtbuf.argtypes = [wt.HANDLE, ct.c_double]

lcPaint_FontOpenLC = litecad.lcPaint_FontOpenLC
lcPaint_FontOpenLC.restype = wt.HANDLE
lcPaint_FontOpenLC.argtypes = [wt.LPCWSTR]

lcPaint_FontOpenTT = litecad.lcPaint_FontOpenTT
lcPaint_FontOpenTT.restype = wt.HANDLE
lcPaint_FontOpenTT.argtypes = [wt.LPCWSTR, wt.BOOL, wt.BOOL]

lcPaint_FontClose = litecad.lcPaint_FontClose
lcPaint_FontClose.restype = wt.BOOL
lcPaint_FontClose.argtypes = [wt.HANDLE]

lcPaint_FontSelect = litecad.lcPaint_FontSelect
lcPaint_FontSelect.restype = wt.BOOL
lcPaint_FontSelect.argtypes = [wt.HANDLE, wt.HANDLE]

#(LPCWSTR = litecad.(LPCWSTR
#(LPCWSTR.restype = wt.BOOL
#(LPCWSTR.argtypes = [wt.LPCWSTR]

# void lcFreeLib ();
