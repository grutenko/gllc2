/********************************************************************
 * Project: LiteCAD DLL
 * Copyright (C) 2009-2024, Oleg Kolbaskin.
 * All rights reserved.
 *
 * API definitions and external functions
 ********************************************************************/
#ifndef _LCAPI_H
#define _LCAPI_H

#define LC_FALSE 0
#define LC_TRUE 1

// LiteCAD window styles ( lcCreateWindow )
#define LC_WS_HSCROLL 1 // Window has a horizontal scroll bar
#define LC_WS_VSCROLL 2 // Window has a vertical scroll bar
#define LC_WS_BORDER 4  // Window has a thin-line border
#define LC_WS_CLIENTEDGE 8
#define LC_WS_SUNKEN 8      // Window has a border with a sunken edge
#define LC_WS_STATICEDGE 16 // Window has a three-dimensional border style
#define LC_WS_RULERS 256    // Window has rulers
#define LC_WS_VIEWTABS \
  512 // Window has View Tabs (border frame automatically added)
#define LC_WS_FILETABS \
  1024                  // Window has File Tabs (border frame automatically added)
#define LC_WS_DEFAULT 3 // Combination of LC_WS_VSCROLL and LC_WS_HSCROLL styles

#define LC_MRU_IMAGE_W 348 // same as MRU_IMAGE_W
#define LC_MRU_IMAGE_H 273 // same as MRU_IMAGE_H

// Pen Styles ( lcPenCreate )
#define LC_PS_SOLID 0
#define LC_PS_DASH 1       // -------
#define LC_PS_DOT 2        // .......
#define LC_PS_DASHDOT 3    // _._._._
#define LC_PS_DASHDOTDOT 4 // _.._.._

// Line width display mmode ( LC_PROP_DRW_LWMODE )
#define LC_LW_THIN 0
#define LC_LW_REAL 1
#define LC_LW_PIXEL 2 // depends on LC_PROP_WND_LWSCALE

// Filling type ( LC_PROP_FILL_TYPE, lcBrushCreate )
#define LC_FILL_SOLID 0
#define LC_FILL_BDIAGONAL 1 // by LcDatabase::m_bEnableHatchBrush
#define LC_FILL_CROSS 2
#define LC_FILL_DIAGCROSS 3
#define LC_FILL_FDIAGONAL 4
#define LC_FILL_HORIZONTAL 5
#define LC_FILL_VERTICAL 6

// ResizeFilter types ( lcImageResize & lcWndToRaster )
#define LC_IMGRES_BOX \
  0                            // Box, pulse, Fourier window, 1st order (constant) B-Spline
#define LC_IMGRES_BILINEAR 1   // Bilinear filter
#define LC_IMGRES_BSPLINE 2    // 4th order (cubic) B-Spline
#define LC_IMGRES_BICUBIC 3    // Mitchell and Netravali's two-param cubic filter
#define LC_IMGRES_CATMULLROM 4 // Catmull-Rom spline, Overhauser spline
#define LC_IMGRES_LANCZOS3 5   // Lanczos-windowed sinc filter

// modes for lcImageProc
#define LC_IMGPROC_GRAY 1
#define LC_IMGPROC_FLIPHOR 2
#define LC_IMGPROC_FLIPVER 3
#define LC_IMGPROC_ROT180 4

// Grip type ( lcGripAdd )
#define LC_GRIP_POINT 0
#define LC_GRIP_CENROT 1 // center of rotation
#define LC_GRIP_ANGLE 2
#define LC_GRIP_ANGLE2 3 // same as LC_GRIP_ANGLE but more offset
#define LC_GRIP_BEZIER 4
#define LC_GRIP_BEZIER0 5
#define LC_GRIP_ARCRAD 6

// flags for LC_PROP_ENT_GRIPMODE - behavior concerning grips
#define LC_GRIP_NOMOVE 1   // disable grips for entity movement
#define LC_GRIP_NOROTATE 2 // disable grips for entity rotation
#define LC_GRIP_NOSCALE 4  // disable grips for entity scale

// Barcode type ( lcMpgonAddBarcode, LC_PROP_BARC_TYPE )
// Must be same values as BARC_TYPE_... in BaseLibs\Barcode\Barcode.h
#define LC_BARTYPE_CODE39 0
#define LC_BARTYPE_CODE93 1
#define LC_BARTYPE_CODE128 6
#define LC_BARTYPE_EAN13 7
#define LC_BARTYPE_ITF 8
#define LC_BARTYPE_EAN8 9
#define LC_BARTYPE_QR 21
#define LC_BARTYPE_MQR 22
#define LC_BARTYPE_DMATRIX 23
#define LC_BARTYPE_DM 23
#define LC_BARTYPE_DMATRIXR 24
#define LC_BARTYPE_DMR 24

// QR-code Error Correction Level (SetECLevel(), LC_PROP_G_BARC_ECL)
// Must be same values as BARC_QRECL_... in BaseLibs\Barcode\Barcode.h
#define LC_BARC_QRECL_L 0 // 01
#define LC_BARC_QRECL_M 1 // 00
#define LC_BARC_QRECL_Q 2 // 11
#define LC_BARC_QRECL_H 3 // 10

// Leader text alignment flags
#define LC_LEADER_TCENTER 0
#define LC_LEADER_TLEFT 1
#define LC_LEADER_TRIGHT 2
// Leader line attachment flags
#define LC_LEADER_VERT 1
#define LC_LEADER_CORNER 2

// commands for lcVportLayerCmd
#define LC_VPL_CLEAR 1      // delete all layers override
#define LC_VPL_ADD 2        // add viewport layer override
#define LC_VPL_DELETE 3     // delete viewport layer override
#define LC_VPL_PROP_BEGIN 4 // begin to edit layer properties
#define LC_VPL_PROP_END 5   // end to edit layer properties

// Radian -> Degree
#define LC_RAD_TO_DEG 57.2957795130823208768 // F
// Degree -> Radian
#define LC_DEG_TO_RAD 0.01745329251994329577 // F

// angles in radians
#define LC_PI 3.14159265358979323846  // F
#define LC_PI2 1.57079632679489661923 // F
#define LC_PI4 0.78539816339744830962 // F
#define LC_2PI 6.28318530717958647692 // F

// angles in degrees
#define LC_DEG1 0.01745329251994329577   // F
#define LC_DEG2 0.03490658503988659154   // F
#define LC_DEG3 0.05235987755982988731   // F
#define LC_DEG4 0.06981317007977318308   // F
#define LC_DEG5 0.08726646259971647885   // F
#define LC_DEG6 0.10471975511965977462   // F
#define LC_DEG7 0.12217304763960307038   // F
#define LC_DEG8 0.13962634015954636615   // F
#define LC_DEG9 0.15707963267948966192   // F
#define LC_DEG10 0.17453292519943295769  // F
#define LC_DEG20 0.34906585039886591538  // F
#define LC_DEG30 0.52359877559829887308  // F
#define LC_DEG40 0.69813170079773183077  // F
#define LC_DEG45 0.78539816339744830962  // F
#define LC_DEG50 0.87266462599716478846  // F
#define LC_DEG60 1.04719755119659774615  // F
#define LC_DEG70 1.22173047639603070385  // F
#define LC_DEG80 1.39626340159546366154  // F
#define LC_DEG90 1.57079632679489661923  // F
#define LC_DEG180 3.14159265358979323846 // F
#define LC_DEG270 4.71238898038468985769 // F
#define LC_DEG360 6.28318530717958647692 // F

// Drawing's units (LC_PROP_DRW_INSUNITS)
#define LC_INSUNIT_UNDEFINED 0     // Undefined
#define LC_INSUNIT_INCHES 1        // Inches
#define LC_INSUNIT_FEET 2          // Feet
#define LC_INSUNIT_MILES 3         // Miles
#define LC_INSUNIT_MILLIMETERS 4   // Millimeters
#define LC_INSUNIT_CENTIMETERS 5   // Centimeters
#define LC_INSUNIT_METERS 6        // Meters
#define LC_INSUNIT_KILOMETERS 7    // Kilometers
#define LC_INSUNIT_MICROINCHES 8   // Microinches
#define LC_INSUNIT_MILS 9          // Mils
#define LC_INSUNIT_YARDS 10        // Yards
#define LC_INSUNIT_ANGSTROMS 11    // Angstroms
#define LC_INSUNIT_NANOMETERS 12   // Nanometers
#define LC_INSUNIT_MICRONS 13      // Microns
#define LC_INSUNIT_DECIMETERS 14   // Decimeters
#define LC_INSUNIT_DEKAMETERS 15   // Dekameters
#define LC_INSUNIT_HECTOMETERS 16  // Hectometers
#define LC_INSUNIT_GIGAMETERS 17   // Gigameters
#define LC_INSUNIT_ASTRONOMICAL 18 // Astronomical
#define LC_INSUNIT_LIGHTYEARS 19   // Lightyears
#define LC_INSUNIT_PARSECS 20      // Parsecs

// LC_PROP_DRW_LUNITS
#define LC_LUNIT_SCIEN 1 // Scientific
#define LC_LUNIT_DECIM 2 // Decimal
#define LC_LUNIT_ENGIN 3 // Engineering
#define LC_LUNIT_ARCHI 4 // Architectural
#define LC_LUNIT_FRACT 5 // Fractional

// Angle units used with GUI and API (LC_PROP_DRW_AUNITS)
#define LC_AUNIT_DEGREE 0 // Decimal degrees
#define LC_AUNIT_DMS 1    // Degrees/minutes/seconds
#define LC_AUNIT_GRAD 2   // Grads
#define LC_AUNIT_RADIAN 3 // Radians
#define LC_AUNIT_SURVEY 4 // Surveyor's units
// same
#define LC_ANGLE_DEGREE 0 // Decimal degrees
#define LC_ANGLE_DMS 1    // Degrees/minutes/seconds
#define LC_ANGLE_GRAD 2   // Grads
#define LC_ANGLE_RADIAN 3 // Radians
#define LC_ANGLE_SURVEY 4 // Surveyor's units

// paper size ( lcWndPaperSetSize )
#define LC_PAPER_CUSTOM 0
#define LC_PAPER_USER 0
#define LC_PAPER_A0 1
#define LC_PAPER_A1 2
#define LC_PAPER_A2 3
#define LC_PAPER_A3 4
#define LC_PAPER_A4 5
#define LC_PAPER_A5 6
#define LC_PAPER_A6 7
#define LC_PAPER_B0 11
#define LC_PAPER_B1 12
#define LC_PAPER_B2 13
#define LC_PAPER_B3 14
#define LC_PAPER_B4 15
#define LC_PAPER_B5 16
#define LC_PAPER_B6 17
#define LC_PAPER_C0 21
#define LC_PAPER_C1 22
#define LC_PAPER_C2 23
#define LC_PAPER_C3 24
#define LC_PAPER_C4 25
#define LC_PAPER_C5 26
#define LC_PAPER_C6 27
#define LC_PAPER_ANSI_A 31
#define LC_PAPER_ANSI_B 32
#define LC_PAPER_ANSI_C 33
#define LC_PAPER_ANSI_D 34
#define LC_PAPER_ANSI_E 35
#define LC_PAPER_LETTER 36
#define LC_PAPER_LEGAL 37
#define LC_PAPER_EXECUTIVE 38
#define LC_PAPER_LEDGER 39
#define LC_PAPER_UNLIMITED 100

// Printer paper orientation
#define LC_PAPER_PORTRAIT 0
#define LC_PAPER_BOOK 0
#define LC_PAPER_LANDSCAPE 1
#define LC_PAPER_ALBUM 1

// options for lcPrintBlock
#define LC_PRN_SCALELW 1 // scale lineweights
#define LC_PRN_1COLOR 2  // force all colors to black

// text alignment types (LC_PROP_G_TEXT_ALIGN)
#define LC_TA_LEFBOT 0   // Align by left bottom corner
#define LC_TA_CENBOT 1   // Align by center of bottom line
#define LC_TA_RIGBOT 2   // Align by right bottom corner
#define LC_TA_LEFCEN 3   // Align by left side of vertical center line
#define LC_TA_CENTER 4   // Align by center of text
#define LC_TA_RIGCEN 5   // Align by right side of vertical center line
#define LC_TA_LEFTOP 6   // Align by left top corner
#define LC_TA_CENTOP 7   // Align by center of top line
#define LC_TA_RIGTOP 8   // Align by right tom corner
#define LC_TA_ALIGNED 11 // Fit text between 2 points (Adjust Height)
#define LC_TA_FIT 12     // Fit text between 2 points (Adjust Width scale)

// text flags for LC_TEXTPRM::Generation
#define LC_TEXT_BACKWARD 2
#define LC_TEXT_UPDOWN 4

// text alignment types for arc text
#define LC_ATA_LEFT 0   // Align by left side of text
#define LC_ATA_CENTER 1 // Align by center of text
#define LC_ATA_RIGHT 2  // Align by right side of text

// text alignment types for barcode text
#define LC_BTA_LEFT 0   // Align by left side of text
#define LC_BTA_CENTER 1 // Align by center of text
#define LC_BTA_RIGHT 2  // Align by right side of text

// Polyline fit types ( lcPtbufInterpolate )
#define LC_PLFIT_BULGE 0 // linear with bulges
#define LC_PLFIT_NONE 0
#define LC_PLFIT_QUAD 5      // Quadratic B-spline
#define LC_PLFIT_CUBIC 6     // Cubic B-spline
#define LC_PLFIT_BEZIER 7    // Bezier spline
#define LC_PLFIT_SPLINE 99   // spline fitted to vertices
#define LC_PLFIT_ROUND 101   // rounded vertices
#define LC_PLFIT_LINQUAD 102 // mixed linear and quadratic segments

// Point modes ( lcPaint_DrawPoint, lcBlockAddPoint2, LC_PROP_DRW_PDMODE )
#define LC_POINT_PIXEL 0 // Pixel
#define LC_POINT_NONE 1  // None
#define LC_POINT_PLUS 2  // "Plus" sign through the point.
#define LC_POINT_X 3     // "X" through the point
#define LC_POINT_TICK 4  // Vertical tick mark upward from the point.
// additional elements
#define LC_POINT_CIRCLE 32  // Circle
#define LC_POINT_SQUARE 64  // Square
#define LC_POINT_RHOMB 128  // Rhomb
#define LC_POINT_FILLED 256 // Filled shape
// extra
#define LC_POINT_BEAM0 10000
#define LC_POINT_BEAM1 10001

// values for parameter 'Mode' of lcBlockSelBlock (LcBlkCreate::m_Mode)
#define LC_BLK_ENT_RETAIN 0  // retain original entities, don't insert the block
#define LC_BLK_ENT_CONVERT 1 // delete selected entities, insert the block
#define LC_BLK_ENT_DELETE 2  // delete selected entities, don't insert the block

// entity alignment ( lcEntAlign )
#define LC_EA_LEFT 1
#define LC_EA_TOP 2
#define LC_EA_RIGHT 3
#define LC_EA_BOTTOM 4
#define LC_EA_CENTER 5
#define LC_EA_CENTERX 6
#define LC_EA_CENTERY 7

// alignment of unscalable image
#define LC_IMGA_CENTER 0 // center
#define LC_IMGA_LEFBOT 1 // left-bottom corner
#define LC_IMGA_RIGBOT 2 // right-bottom corner
#define LC_IMGA_LEFTOP 3 // left-top corner
#define LC_IMGA_RIGTOP 4 // right-top corner

// Mouse buttons
#define LC_LBUTTON 1 // Left button is pressed
#define LC_RBUTTON 2 // right button is pressed
#define LC_MBUTTON 4 // middle button is pressed

// Key state
#define LC_SHIFT 1 // SHIFT key is pressed
#define LC_CTRL 2  // CTRL key is pressed
#define LC_ALT 4   // ALT key is pressed

// keyboard type
#define LC_KBD_QWERTY 0 // QWERTY
#define LC_KBD_AZERTY 1 // AZERTY
#define LC_KBD_QWERTZ 2 // QWERTZ

// LiteCAD window cursor, to use in lcPropPutInt(0, LC_PROP_WND_CURSORARROW,
// Val)
#define LC_CURSOR_NULL 0  // no cursor
#define LC_CURSOR_ARROW 1 // Standard arrow
#define LC_CURSOR_CROSS 2 // Crosshair
#define LC_CURSOR_HAND 3  // Hand
#define LC_CURSOR_HELP 4  // Arrow and question mark
#define LC_CURSOR_NO 5    // Slashed circle
#define LC_CURSOR_WAIT 6  // Hourglass
#define LC_CURSOR_PAN1 7  // Pan start cursor
#define LC_CURSOR_PAN2 8  // Pan move cursor

// flags for lcExpEntity
#define LC_EXP_OUTLINE 1
#define LC_EXP_HATCH 2
#define LC_EXP_ALL 3
#define LC_EXP_MAXRESOL 4

// Modes of the LC_PROP_EVENT_MODE property  (lcExpBlock)
#define LC_EM_TOP 0      // top entity
#define LC_EM_ENT 1      // entity to explode
#define LC_EM_PLINE 2    // begin of entity polyline
#define LC_EM_VERTEX 3   // vertex of polyline
#define LC_EM_ENDPLINE 4 // end of entity polyline
#define LC_EM_ENDENT 5   // end of entity to explode

// values for lcWndEmulator
#define LC_EMUL_START 0
#define LC_EMUL_STOP 1
#define LC_EMUL_PARAMS 2

// magnifier zoom values
#define LC_MAG_ZOOM_4 0
#define LC_MAG_ZOOM_6 1
#define LC_MAG_ZOOM_8 2
#define LC_MAG_ZOOM_10 3
#define LC_MAG_ZOOM_12 4
#define LC_MAG_ZOOM_14 5
// magnifier flags
#define LC_MAG_CENTER 1 // draw center cross

// Mode for lcDrwExplode
#define LC_DRWEXP_L 0       // explode to lines
#define LC_DRWEXP_P 1       // explode to polylines
#define LC_DRWEXP_LA 10     // explode to lines, arcs and circles
#define LC_DRWEXP_PA 11     // explode to polylies, arcs and circles
#define LC_DRWEXP_BLOCKS 20 // explode all blocks

// ID of help file topic
#define LC_HELP_DG_PRINT 1
#define LC_HELP_DG_RASTER 2
#define LC_HELP_DG_COLOR 10
#define LC_HELP_DG_LAYERS 11
#define LC_HELP_DG_SELLTYPE 12
#define LC_HELP_DG_LINETYPES 13
#define LC_HELP_DG_LOADLINETYPE 14
#define LC_HELP_DG_TEXTSTYLES 15
#define LC_HELP_DG_PNTSTYLES 16
#define LC_HELP_DG_DIMSTYLES 17
#define LC_HELP_DG_MLSTYLES 18
#define LC_HELP_DG_HATSTYLES 19
#define LC_HELP_DG_BLOCKS 20
#define LC_HELP_DG_LAYOUTS 21
#define LC_HELP_DG_IMAGES 22
#define LC_HELP_DG_IMAGEINSERT 23
#define LC_HELP_DG_SELBLOCK 30
#define LC_HELP_DG_SELTSTYLE 31
#define LC_HELP_DG_SELPTYPE 32
#define LC_HELP_DG_CREBLOCK 33
#define LC_HELP_DG_PAGEPROP 34
#define LC_HELP_DG_SELFONT 35
#define LC_HELP_DG_TEXT 40
#define LC_HELP_DG_ARCTEXT 41
#define LC_HELP_DG_INPUTCOORD 42
#define LC_HELP_DG_WORKFIELD 43
#define LC_HELP_DG_CRBITMAP 44
#define LC_HELP_DG_INSERT 45
#define LC_HELP_DG_TSP 51
#define LC_HELP_DG_ARRAY 52
#define LC_HELP_DG_ARRAYARC 53
#define LC_HELP_DG_HATCH 54
#define LC_HELP_DG_GRID 61
#define LC_HELP_DG_PTRACK 62
#define LC_HELP_DG_OSNAP 63
#define LC_HELP_DG_KBMOVE 64
#define LC_HELP_DG_DRWPROPS 65
#define LC_HELP_DG_SYSPROPS 66
#define LC_HELP_DG_SELECTION 67
#define LC_HELP_DG_QSELECT 68
#define LC_HELP_DG_RPOLYGON 69
#define LC_HELP_DG_LIMITS 70
#define LC_HELP_DG_NDLSET 71
#define LC_HELP_DG_LMESH 72
#define LC_HELP_DG_CRECTS 73
#define LC_HELP_DG_SELLINFILL 74

// values for lcWndMessage uType parameter
#define LC_MB_OK \
  0 // 0x0000L The message box contains one push button: OK. This is the
    // default.
#define LC_MB_OKCANCEL \
  1 // 0x0001L The message box contains two push buttons: OK and Cancel.
#define LC_MB_ABORTRETRYIGNORE \
  2 // 0x0002L The message box contains three push buttons: Abort, Retry, and
    // Ignore.
#define LC_MB_YESNOCANCEL \
  3 // 0x0003L The message box contains three push buttons: Yes, No, and Cancel.
#define LC_MB_YESNO \
  4 // 0x0004L The message box contains two push buttons: Yes and No.
#define LC_MB_RETRYCANCEL \
  5 // 0x0005L The message box contains two push buttons: Retry and Cancel.
#define LC_MB_CANCELTRYCONTINUE \
  6 // 0x0006L The message box contains three push buttons: Cancel, Try Again,
    // Continue. Use this message box type instead of MB_ABORTRETRYIGNORE.
#define LC_MB_HELP \
  16384 // 0x4000L Adds a Help button to the message box. When the user clicks
        // the Help button or presses F1, the system sends a WM_HELP message to
        // the owner.
#define LC_MB_ICONSTOP \
  16 // 0x0010L A stop-sign icon appears in the message
     // box.
#define LC_MB_ICONERROR \
  16 // 0x0010L A stop-sign icon appears in the message box.
#define LC_MB_ICONHAND \
  16 // 0x0010L A stop-sign icon appears in the message
     // box.
#define LC_MB_ICONQUESTION \
  32 // 0x0020L A question-mark icon appears in the message box.
#define LC_MB_ICONEXCLAMATION \
  48 // 0x0030L An exclamation-point icon appears in the message box.
#define LC_MB_ICONWARNING \
  48 // 0x0030L An exclamation-point icon appears in the message box.
#define LC_MB_ICONINFORMATION \
  64 // 0x0040L An icon consisting of a lowercase letter i in a circle appears
     // in the message box.
#define LC_MB_ICONASTERISK \
  64 // 0x0040L An icon consisting of a lowercase letter i in a circle appears
     // in the message box.

#define LC_UNDO_BEGIN 0 // begin record
#define LC_UNDO_END 1   // end record
#define LC_UNDO_CLEAR 2 // clear undo buffer

// Error codes
#define LC_ERR_OBJTYPE 1         // wrong type of object
#define LC_ERR_NOTAG 2           // string tag is not found
#define LC_ERR_USERCANCEL 3      // user have clicked "Cancel" button
#define LC_ERR_FILENAME 4        // wrong filename
#define LC_ERR_FILELOAD 5        // can't load a file
#define LC_ERR_FILESAVE 6        // can't save a file
#define LC_ERR_UNRESBLOCKREF 7   // unresolved block reference
#define LC_ERR_UNRESVIEWREF 8    // unresolved view reference
#define LC_ERR_UNRESHATCH 9      // unresolved hatch
#define LC_ERR_FILE_TIN_SAVE 101 // can not write external TIN file

// Non-graphical objects (Named)
#define LC_OBJ_LAYER 1     // Layer
#define LC_OBJ_LINETYPE 2  // Linetype
#define LC_OBJ_TEXTSTYLE 3 // Text style
#define LC_OBJ_DIMSTYLE 4  // Dimension style
#define LC_OBJ_PNTSTYLE 5  // Point style
#define LC_OBJ_IMAGE 6     // Image
#define LC_OBJ_MLSTYLE 8   // Multiline style
#define LC_OBJ_LINFILL 9   // Filling by lines
#define LC_OBJ_BLOCK 10    // Block
#define LC_OBJ_LAYOUT 11   // Layout block (Model or Paper space)

// Graphic objects
#define LC_ENT_LINE 101     // Line
#define LC_ENT_POLYLINE 102 // Polyline
#define LC_ENT_CIRCLE 103   // Circle
#define LC_ENT_ARC 104      // Arc
#define LC_ENT_BLOCKREF 105 // Block Reference
#define LC_ENT_POINT 107    // Point
#define LC_ENT_XLINE 108    // Construction line or ray
#define LC_ENT_ELLIPSE 109  // Ellipse or elliptical arc
#define LC_ENT_TEXT 110     // Text
#define LC_ENT_TEXTWIN 111  // Text by GDI TextOut
#define LC_ENT_IMAGEREF 115 // Image Reference
#define LC_ENT_VIEWPORT 116 // Viewport
#define LC_ENT_CLIPRECT 117 // Clipping rectangle
#define LC_ENT_RECT 118     // Rectangle
#define LC_ENT_ATTDEF 120   // Attribute definition
#define LC_ENT_ECW 121      // ECW image
#define LC_ENT_MTEXT 122    // Multiline Text
#define LC_ENT_ARCTEXT 123  // Arc Text
#define LC_ENT_HATCH 124    // Hatch
#define LC_ENT_FACE 126     // 3D Face
#define LC_ENT_MLINE 127    // multiline polyline
#define LC_ENT_DIMROT 131   // Dimension Linear
#define LC_ENT_DIMLIN 131   // Dimension Linear
#define LC_ENT_DIMALI 132   // Dimension Aligned
#define LC_ENT_DIMORD 133   // Dimension Ordinate
#define LC_ENT_DIMRAD 134   // Dimension Radial
#define LC_ENT_DIMDIA 135   // Dimension Diametric
#define LC_ENT_DIMANG 136   // Dimension Angular
#define LC_ENT_LEADER 137   // Leader
#define LC_ENT_RPLAN 141    // Road plan
#define LC_ENT_TIN 142      // Triangulated Irregular Network
#define LC_ENT_BARCODE 150  // Barcode
#define LC_ENT_SHAPE 160    // Shape
#define LC_ENT_BRI 161      // Big Raster Image
#define LC_ENT_XREF 199     // External Reference
#define LC_ENT_ARROW 301    // Arrow
#define LC_ENT_SPIRAL 302   // Spiral
#define LC_ENT_CAMERA 303   // Camera
#ifdef _PTARRAY
#define LC_ENT_PTARRAY 304 // points array
#endif
#define LC_ENT_PATHTEXT 305 // Path Text
#define LC_ENT_BEZIER 306   // Bezier spline
#define LC_ENT_CUSTOM 1000
#define LC_ENT_ALL 32767 // used for bulk properties

// Lineweights
#define LC_LWEIGHT_DEFAULT \
  -3 // Default lineweight. Width is controlled by LC_PROP_DRW_LWDEFAULT
     // property.
#define LC_LWEIGHT_BYBLOCK \
  -2 // Only for entities contained in block. Universal lineweight specified
     // within a BlockRef entity.
#define LC_LWEIGHT_BYLAYER \
  -1 // Only for entities. Universal lineweight specified in the entity's layer.
#define LC_LWIDTH_DEFAULT -3
#define LC_LWIDTH_BYBLOCK -2
#define LC_LWIDTH_BYLAYER -1

// variants for LC_PROP_G_COLOR property
#define LC_COLOR_RGB 0   // RGB value (COLORREF)
#define LC_COLOR_INDEX 1 // AutoCAD Color Index (ACI)

// defined ACI Colors
#define LC_COLOR_RED 1        // Red
#define LC_COLOR_YELLOW 2     // Yellow
#define LC_COLOR_GREEN 3      // Green
#define LC_COLOR_CYAN 4       // Cyan
#define LC_COLOR_BLUE 5       // Blue
#define LC_COLOR_MAGENTA 6    // Magenta
#define LC_COLOR_FOREGROUND 7 // Foreground (contrast to background color)
#define LC_COLOR_GRAY 8       // Gray
#define LC_COLOR_LTGRAY 9     // Light gray
// logical colors for entities
#define LC_COLOR_BYBLOCK 0   // entity's color by block
#define LC_COLOR_BYLAYER 256 // entity's color by layer
#define LC_COLOR_WIPEOUT 259 // used for wipeout object

// options for LC_PROP_DRW_SELPENMODE
// #define LC_SELPEN_COLOR  0  // dotted pen, color by m_SelPenColor and
// m_SelPenColorBk #define LC_SELPEN_BYENT  1  // dottet pen, color by entity

// Multiline justification 0 = Top; 1 = Middle; 2 = Bottom
#define LC_MLINE_TOP 0
#define LC_MLINE_MIDDLE 1
#define LC_MLINE_BOTTOM 2

#define LC_TABLE_IDSET 349000349

// Plugin Interface Types
// Do not change this values, because it must be the same in plugin DLLs
#define LC_PLUG_IMPDRW \
  2                      // load a drawing from a file into LiteCAD database (in memory)
#define LC_PLUG_EXPDRW 3 // save a drawing from LiteCAD database into a file
#define LC_PLUG_IMGDIB 4 // load an image from a file into LiteCAD DIB

// values for the F_FIOPROGRESS Mode
#define LC_FP_FLOAD 0   // szFileName - a file is being loaded
#define LC_FP_FSAVE 1   // szFileName - a file is being saved
#define LC_FP_NITEMS 2  // IntVal - number of items
#define LC_FP_ITEM 3    // increment item
#define LC_FP_ITEMPOS 4 // set item position

// Snap modes ( LC_PROP_WND_OSNAP )
#define LC_OSNAP_NULL 0 // 0x00000 no snap at all
#define LC_OSNAP_NODE \
  1 // 0x00001 to a Point object, dimension definition point, or dimension text
    // origin.
#define LC_OSNAP_ENDPOINT \
  2 // 0x00002 to the closest endpoint of an Arc, Elliptical Arc, Line,
    // Multiline, Polyline segment, Ray
#define LC_OSNAP_MIDPOINT \
  4 // 0x00004 to the midpoint of an arc, ellipse, elliptical arc, line,
    // multiline, polyline segment, region, solid, spline, or xline.
#define LC_OSNAP_CENTER \
  8 // 0x00008 to the center of an arc, circle, ellipse, or elliptical arc.
#define LC_OSNAP_NEAREST \
  16 // 0x00010 to the nearest point on an arc, circle, ellipse, elliptical arc,
     // line, multiline, point, polyline, ray, spline, or xline.
#define LC_OSNAP_INTER \
  32 // 0x00020 to the intersection of an arc, circle, ellipse, elliptical arc,
     // line, multiline, polyline, ray, region, spline, or xline.
#define LC_OSNAP_PERPEND \
  64 // 0x00040 to a point perpendicular to an arc, circle, ellipse, elliptical
     // arc, line, multiline, polyline, ray, region, solid, spline, or xline
#define LC_OSNAP_TANGENT \
  128 // 0x00080 to the tangent of an arc, circle, ellipse, elliptical arc, or
      // spline.
#define LC_OSNAP_QUADRANT \
  256 // 0x00100 to a quadrant point of an arc, circle, ellipse, or elliptical
      // arc.
#define LC_OSNAP_INSERT \
  512                      // 0x00200 to the insertion point of an attribute, a block, a shape, or
                           // text.
#define LC_OSNAP_NONE 1024 // 0x00400 temporary disable object snap
#define LC_OSNAP_ALL 1023  // 0x003FF all modes

// Attribute flags
#define LC_ATTRIB_HIDDEN 1
#define LC_ATTRIB_CONST 2
#define LC_ATTRIB_VERIFY 4
#define LC_ATTRIB_PRESET 8
#define LC_ATTRIB_LOCK 16
#define LC_ATTRIB_MTEXT 32

// 3D Face flags (must be the same as in "..\odt\ad2.h"
#define LC_FACE_EDGE1INVIS 1
#define LC_FACE_EDGE2INVIS 2
#define LC_FACE_EDGE3INVIS 4
#define LC_FACE_EDGE4INVIS 8
#define LC_FACE_EDGE1HIDDEN 1
#define LC_FACE_EDGE2HIDDEN 2
#define LC_FACE_EDGE3HIDDEN 4
#define LC_FACE_EDGE4HIDDEN 8

// block overwrite mode
#define LC_BLOCK_OVERWRITENO 0
#define LC_BLOCK_OVERWRITEYES 1
#define LC_BLOCK_OVERWRITEDLG 2

// arrowhead types (for dimensions)
#define LC_ARROW_CLOSEDF 0    // Closed filled
#define LC_ARROW_CLOSEDB 1    // Closed blank
#define LC_ARROW_CLOSED 2     // Closed
#define LC_ARROW_DOT 3        // Dot
#define LC_ARROW_ARCHTICK 4   // Architectural tick
#define LC_ARROW_OBLIQUE 5    // Oblique
#define LC_ARROW_OPEN 6       // Open
#define LC_ARROW_ORIGIN 7     // Origin indicator
#define LC_ARROW_ORIGIN2 8    // Origin indicator 2
#define LC_ARROW_OPEN90 9     // Right angle
#define LC_ARROW_OPEN30 10    // Open 30
#define LC_ARROW_DOTSMALL 11  // Dot small
#define LC_ARROW_DOTB 12      // Dot blank
#define LC_ARROW_DOTSMALLB 13 // Dot small blank
#define LC_ARROW_BOX 14       // Box
#define LC_ARROW_BOXF 15      // Box filled
#define LC_ARROW_DATUM 16     // Datum triangle
#define LC_ARROW_DATUMF 17    // Datum triangle filled
#define LC_ARROW_INTEGRAL 18  // Integral
#define LC_ARROW_NONE 19      // None

// Camera color format (TISGrabberGlobalDefs.h)
#define LC_COFO_NONE 0
#define LC_COFO_Y800 1
#define LC_COFO_RGB24 2
#define LC_COFO_RGB32 3
#define LC_COFO_UYVY 4
#define LC_COFO_Y16 5
#define LC_COFO_MEGA 65536 // Borland C++ 6 compatibility

//-----------------------------------------------
// LiteCAD commands (for lcWndExeCommand)
//-----------------------------------------------

// File I/O commands
#define LC_CMD_FILESAVE \
  1                         // Save drawing to file. Call dialog "Save As" if filename is undefined
#define LC_CMD_FILESAVEAS 2 // Call dialog "Save File As"
#define LC_CMD_PRINT 3      // Call dialog "Print"
#define LC_CMD_RASTERIZE 4  // Call dialog "Export to raster image"
#define LC_CMD_FILENEW 5
#define LC_CMD_FILEOPEN 6
#define LC_CMD_FILERECENT 7
#define LC_CMD_FILEINSERT 8
#define LC_CMD_FILECLOSE 9 // close file of current file tab

// Display a drawing in design window
#define LC_CMD_VIEW__MIN 31 //------- 1-step view commands until LC_CMD_VIEWEND
#define LC_CMD_ZOOM_IN 31   // Enlarge drawing's view
#define LC_CMD_ZOOM_OUT 32  // Diminish drawing's view
#define LC_CMD_ZOOM_EXT 33  // Zoom on drawing's extents
#define LC_CMD_ZOOM_PAGE 34 // Zoom on paper sheet (only for "Paper Space" view)
#define LC_CMD_ZOOM_PREV 35 // Display the previous view
#define LC_CMD_ZOOM_LIM 36  // Zoom on limits rect
#define LC_CMD_PAN_LEFT 37  // Shift drawing to the left
#define LC_CMD_PAN_RIGHT 38 // Shift drawing to the right
#define LC_CMD_PAN_UP 39    // Shift drawing upward
#define LC_CMD_PAN_DOWN 40  // Shift drawing downward
#define LC_CMD_VIEW__MAX 40 //------------------------------------------
#define LC_CMD_ZOOM_WIN 51  // Zoom drawing using the Zoom rectangle (Zoom Box)
#define LC_CMD_ZOOM_RECT 51 // same as LC_CMD_ZOOM_WIN
#define LC_CMD_ZOOM_SEL 52  // Zoom on selected entities
#define LC_CMD_PAGENEXT 53  // Display next layout
#define LC_CMD_PAGEPREV 54  // Display previous layout
#define LC_CMD_PAGEMODEL 55 // Display "Model Space" layout
#define LC_CMD_PAGEVPORT \
  56                           // Display layout of active viewport (called by popup menu on AVP)
#define LC_CMD_VP_ACT 57       // activate viewport
#define LC_CMD_VP_DEACT 58     // deactivate viewport
#define LC_CMD_EDITMODE_ON 59  //
#define LC_CMD_EDITMODE_OFF 60 //
#define LC_CMD_MAG__MIN 71     //------------------------------------------
#define LC_CMD_MAGON 71        // magnifier ON
#define LC_CMD_MAGOFF 72       // magnifier OFF
#define LC_CMD_MAGPRM 73       // magnifier parameters
#define LC_CMD_MAGZOOM4 74     //
#define LC_CMD_MAGZOOM6 75     //
#define LC_CMD_MAGZOOM8 76     //
#define LC_CMD_MAGZOOM10 77    //
#define LC_CMD_MAGZOOM12 78    //
#define LC_CMD_MAGZOOM14 79    //
#define LC_CMD_MAG__MAX 79     //------------------------------------------

// Miscellaneous
#define LC_CMD_GRID 101    // Call dialog "Coordinate Grid"
#define LC_CMD_OSNAP 102   // Call dialog "Object Snap"
#define LC_CMD_PTRACK 103  // Call dialog "Polar Tracking"
#define LC_CMD_SELOPTS 104 // Call dialog "Selection Options"
#define LC_CMD_QSELECT 105
#define LC_CMD_KBMOVE 106 // move entities by keyboard
#define LC_CMD_DIST 111
#define LC_CMD_AREA 112
#define LC_CMD_SCALEBLK 113
//^ #define LC_CMD_JUMPLINES      115
#define LC_CMD_TSP2 116
#define LC_CMD_LIMITS 117    // Call dialog "Limits"
#define LC_CMD_SAVESTR 118   // save original strings into LNG file
#define LC_CMD_DELDUPVER 119 // delete duplicate vertices
#define LC_CMD_DELEXVER 120  // delete extra vertices (Coarse polyline)
// #define LC_CMD_BPLACE         135   // block place attributes for a point
#define LC_CMD_UNHIDE 136       // unhide hidden entities
#define LC_CMD_SHDOTS 137       // on/off shape dots (used for testing)
#define LC_CMD_SMALLVRECT 138   // display reduced view (used for testing)
#define LC_CMD_PLUGINS 141      // call dialog "Plugins"
#define LC_CMD_CENTERCURSOR 142 // set cursor at window center

#define LC_CMD_HELP 1001 // Display Context Help
#define LC_CMD_RESET \
  1003                          // Cancel currently active command, de-select all entities, redraw
                                // drawing
#define LC_CMD_SW_GRID 1011     // Toggles "Show coordinate grid" mode
#define LC_CMD_SW_GRIDSNAP 1012 // Toggles "Snap to coordinate grid" mode
#define LC_CMD_SW_OSNAP 1014    // Toggles "Object Snap" mode
#define LC_CMD_SW_PTRACK 1015   // Toggles "Polar tracking" mode
#define LC_CMD_SW_POLAR 1015    // same as LC_CMD_SW_PTRACK
#define LC_CMD_SW_ORTHO 1016    // Toggles "Ortho" mode

// Add entities
#define LC_CMD_POINT 201    // Draw Point
#define LC_CMD_LINE 202     // Draw Line
#define LC_LINE_SERIAL 1    //   serial lines
#define LC_LINE_SEPARATE 2  //   separate lines
#define LC_LINE_CONT 3      //   continue
#define LC_CMD_XLINE 203    // Draw Construction Line
#define LC_XLINE_BASE 1     //   basepoint
#define LC_XLINE_ANG 2      //   angular lines (preset by LC_PROP_WND_XLINEANG)
#define LC_XLINE_SEP 3      //   separate 2-point lines
#define LC_XLINE_RAY 4      //   select ray
#define LC_XLINE_XLINE 5    //   select xline
#define LC_CMD_LMESH 204    // Draw mesh
#define LC_CMD_POLYLINE 205 // Draw Polyline
#define LC_CMD_PLINE 205    //   same as LC_CMD_POLYLINE
#define LC_CMD_SPLINE 206   // Draw Spline (polyline with FitType=LC_PLFIT_SPLINE)
#define LC_CMD_RPOLYGON 207 // Draw regular polygon
#define LC_CMD_RECT 208     // Draw Rectangle
#define LC_RECT_2P 1        //   2 points
#define LC_RECT_3P 2        //   3 points
#define LC_RECT_CSA 3       //   Center, Size, Angle
#define LC_CMD_CIRCLE 209   // Draw Circle
#define LC_CIRCLE_CR 1      //   Center, Radius
#define LC_CIRCLE_2P 2      //   2 points
#define LC_CIRCLE_3P 3      //   3 points
#define LC_CMD_ARC 210      // Draw Arc
#define LC_ARC_SME 1        //   Start, Middle, End
#define LC_ARC_SEM 2        //   Start, End, Middle
#define LC_ARC_SEC 3        //   Start, End, Center
#define LC_ARC_SED 4        //   Start, End, Direction
#define LC_ARC_CSE 5        //   Center, Start, End
#define LC_ARC_CONT 6       //   Continue
#define LC_CMD_ELLIPSE 211  // Draw Ellipse
#define LC_ELL_AX 1         //   Axis, End
#define LC_ELL_CEN 2        //   Center
#define LC_ELL_RECT 3       //   By Rectangle
#define LC_CMD_TEXT 212     // Draw Text
#define LC_CMD_TEXTW 213    // Draw WinText
#define LC_CMD_ATEXT 214    // Draw Arc Text
#define LC_CMD_ARCTEXT 214  // Draw Arc Text (same as LC_CMD_ATEXT)
#define LC_CMD_MTEXT 215    // Draw Multiline Text
#define LC_CMD_INSERT 216   // Insert a block
#define LC_CMD_BLOCKREF 216 // Insert a block (same as LC_CMD_INSERT)
#define LC_INSERT_DLG 1
#define LC_INSERT_NODLG 2
#define LC_INSERT_RESET 3
#define LC_CMD_BARCODE 217 // Draw Barcode
#define LC_BARCODE_39 1
#define LC_BARCODE_93 2
#define LC_BARCODE_128 3
#define LC_BARCODE_EAN13 4
#define LC_BARCODE_EAN8 5
#define LC_BARCODE_ITF 6
#define LC_BARCODE_MQR 7
#define LC_BARCODE_QR 8
#define LC_BARCODE_DMATRIX 9
#define LC_BARCODE_DM 9
#define LC_BARCODE_DMATRIXR 10
#define LC_BARCODE_DMR 10
#define LC_CMD_DIMLIN 221   // Draw dimension linear
#define LC_CMD_DIMROT 221   // same as LC_CMD_DIMLIN
#define LC_CMD_DIMALI 223   // Draw dimension aligned
#define LC_CMD_DIMORD 224   // Draw dimension ordinate
#define LC_CMD_DIMRAD 225   // Draw dimension radius
#define LC_CMD_DIMDIA 226   // Draw dimension diameter
#define LC_CMD_DIMANG 227   // Draw dimension angular
#define LC_CMD_LEADER 228   // Draw leader
#define LC_CMD_ARROW 231    // Draw arrow
#define LC_CMD_SPIRAL 232   // Draw spiral
#define LC_CMD_HATCH 233    // Draw Hatch
#define LC_CMD_ECW 234      // Insert ECW image
#define LC_CMD_VPORT 236    // Draw viewport
#define LC_CMD_VIEWPORT 236 // Draw viewport (same as LC_CMD_VPORT)
#ifdef _PTARRAY
#define LC_CMD_PTARRAY 237 // Insert points array
#endif
#define LC_CMD_FACE 238   // Draw 3d face
#define LC_CMD_SHAPE 239  // Create Shape from selected entities
#define LC_CMD_SKETCH 240 // Draw polylines as a sketch
#define LC_CMD_CLOUD 241  // Draw polylines as cloud sketch
#define LC_CMD_RPLAN 242  // Draw RPLAN
#define LC_CMD_MLINE 243  // Draw multiline
#define LC_CMD_BEZIER 244 // Draw bezier spline
#define LC_CMD_BRI 245    // Insert BRI image
#define LC_CMD_CLIPRECTS 250
#define LC_CMD_CRECTS 250
#define LC_CMD_ATTDEF 251 // attribute definition

#define LC_CMD_TIN_LOAD \
  301 // Add new TIN entity by loading TIN model from a file
#define LC_CMD_TIN_LOADPT \
  302                            // Add new TIN entity by loading TIN points from a file
#define LC_CMD_TIN_ADDPT 303     // Add new TIN entity by adding points on-screen
#define LC_CMD_TIN_DELETE 304    // delete active TIN (see also lcBlockDeleteEnt )
#define LC_CMD_TIN_PROPS 305     // TIN: dialog "Properties"
#define LC_CMD_TIN_PTYPES 306    // dialog "TIN Point types"
#define LC_CMD_TIN_MOVEPT 307    // TIN: move points
#define LC_CMD_TIN_EDITPT 308    // TIN: edit points (dialog)
#define LC_CMD_TIN_DELPT 309     // TIN: delete points
#define LC_CMD_TIN_BNDDELPT 310  // TIN:
#define LC_CMD_TIN_DELPTDUP 311  // TIN: delete duplicate points
#define LC_CMD_TIN_DELTRALL 312  // TIN: delete all triangles
#define LC_CMD_TIN_DELTR 313     // TIN: delete triangles
#define LC_CMD_TIN_BNDDELTR 314  // TIN:
#define LC_CMD_TIN_SWAPTR 315    // TIN: swap triangles
#define LC_CMD_TIN_BNDAUTO 316   // TIN: autodefine boundary
#define LC_CMD_TIN_BND 317       // TIN: define boundary by hands
#define LC_CMD_TIN_BNDEDIT 318   // TIN: edit boundary
#define LC_CMD_TIN_BNDCLEAR 319  // TIN:
#define LC_CMD_TIN_BNDTRANG 320  // TIN:
#define LC_CMD_TIN_BNDTRANG2 321 // TIN: triangulate by step
#define LC_CMD_TIN_GENISO 322    // TIN: dialog "Generate TIN isolines"
#define LC_CMD_TIN_GENFILL 323   // TIN: dialog "Generate TIN filling"
#define LC_CMD_TIN_RELOAD 324    // TIN
#define LC_CMD_TIN_SAVE 325      // TIN: File save
#define LC_CMD_TIN_SAVEPT 326    // TIN: File save points
#define LC_CMD_TIN_BNDSAVE 327   // TIN:
#define LC_CMD_TIN_BNDPLINE 328  // TIN:
#define LC_CMD_TIN_Z 329         // TIN: display TIN Z-coord near cursor
#define LC_CMD_TIN_ZOOM 330      // TIN: zoom extents
#define LC_CMD_TIN_ISOTODRW 331  // TIN: copy isolines into drawing
#define LC_CMD_TIN_TILES 332     // TIN: draw TIN tiles

// Edit operations
#define LC_CMD_CBCUT 401     // Cut entities to clipboard
#define LC_CMD_CBCOPY 402    // Copy entities to clipboard
#define LC_CMD_CBPASTE 403   // Paste entities from clipboard
#define LC_CMD_UNDO 404      // Undo last change
#define LC_CMD_REDO 405      // Reverse last "undo"
#define LC_CMD_UNDOCLEAR 406 // Clear Undo buffer
#define LC_CMD_COPY 410      // Copy entities
#define LC_COPY_MOVE 1
#define LC_COPY_ROTATE 2
#define LC_COPY_SCALE 3
#define LC_COPY_MIRROR 4
#define LC_COPY_ARRRECT 5
#define LC_COPY_ARRCIRC 6
#define LC_CMD_ERASE 411   // Erase entities
#define LC_CMD_MOVE 412    // Move entities
#define LC_CMD_ROTATE 413  // Rotate entities
#define LC_CMD_SCALE 414   // Scale entities
#define LC_CMD_MIRROR 415  // Mirror entities
#define LC_CMD_EXPLODE 416 // Explode entities
#define LC_CMD_SPLIT 417   // Split entities
#define LC_CMD_JOIN 418    // Join entities
// #define LC_CMD_DEP            419  // delete extra points   // undoc
#define LC_CMD_ORDER 420 // change draw order
#define LC_ORDER_FRONT 1
#define LC_ORDER_BACK 2
#define LC_ORDER_ABOVE 3
#define LC_ORDER_UNDER 4
#define LC_ORDER_SWAP 5
#define LC_CMD_ORDER_SEQ 430 // Sequential order
#define LC_CMD_ALIGN 431     // align entities
#define LC_ALIGN_LEFT 1
#define LC_ALIGN_RIGHT 2
#define LC_ALIGN_TOP 3
#define LC_ALIGN_BOTTOM 4
#define LC_ALIGN_CENTER 5
#define LC_ALIGN_CENX 6
#define LC_ALIGN_CENY 7
#define LC_CMD_CLOSEBLOCK 439 // Close Block Editor
#define LC_CMD_BASEPOINT 440  // set block's basepoint
#define LC_CMD_TRIM 441       // Trim
#define LC_CMD_EXTEND 442     // Extend
#define LC_CMD_OFFSET 443     // Offset
#define LC_CMD_OFFSET_POINT 0
#define LC_CMD_OFFSET_DIST 1
#define LC_CMD_BREAK 444   // Break
#define LC_CMD_STRETCH 445 // Stretch
#define LC_CMD_FILLET 446  // make fillet for 2 lines
#define LC_CMD_IMGRES 451  // Change Image Resolution
#define LC_CMD_IMGPOS 452  // Set Image Position
#ifdef XUELIANG
#define LC_CMD_XHL 461 // make shape from hatch by lines
#define LC_CMD_XHP 462 // make shape from hatch by polylines
#endif
#define LC_CMD_JOINALL 465 // Join all connected entities into polylines
#define LC_CMD_ENTEXT 468  // draw entities extents on/off
#define LC_CMD_JUMPS 469   // draw jump lines on/off
#define LC_CMD_UNSIMG 470  // toggle flag "Unscalable" for selected raster images
#define LC_CMD_UPDATE 474  // update all entities or selected, in ViewBlock
#define LC_CMD_DELOVER 475 // delete overlapped lines
#define LC_CMD_CMPD 476    // compare with other drawing

// Format
#define LC_CMD_LAYER 501    // Call dialog "Layers"
#define LC_CMD_LAYERORD 502 // Call dialog "Layers order"
#define LC_CMD_COLOR \
  503                        // Call dialog "Color", CmdPrm: LC_PROP_DRW_COLOR, LC_PROP_DRW_FCOLOR,
                             // LC_PROP_ENT_COLOR, LC_PROP_ENT_FCOLOR
#define LC_CMD_FCOLOR 504    // Call dialog "Filling Color"
#define LC_CMD_LINETYPE 505  // Call dialog "Linetypes"
#define LC_CMD_TEXTSTYLE 507 // Call dialog "Text Styles"
#define LC_CMD_BLOCK 508     // Call dialog "Create Block"
#define LC_CMD_CREBLOCK 508  // same as LC_CMD_BLOCK
#define LC_CMD_BLOCKS 509    // Call dialog "Blocks"
#define LC_CMD_IMAGE 510     // Call dialog "Image Manager"
#define LC_CMD_PNTSTYLE 511  // Call dialog "Point Style"
#define LC_CMD_DIMSTYLE 512  // Call dialog "Dimension Styles"
#define LC_CMD_MLSTYLE 513   // Call dialog "Multiline Styles"
#define LC_CMD_LINFILL 515   // Call dialog "Filling Styles"
#define LC_CMD_LAYOUT 516    // Call dialog "Layouts"
#define LC_CMD_XREFS 517     // Call dialog "Xrefs"
#define LC_CMD_UNITS 521     // Call dialog "Drawing Units"
#define LC_CMD_DRWPRM 522    // Call dialog "Drawing properties"
#define LC_CMD_SYSPRM 523    // Call dialog "System properties"

// 3D
#define LC_CMD_3DVIEW \
  601                           // enable/disable 3D view (Tab). CmdPrm: 0-switch, 1-on, 2-off
#define LC_CMD_3D 601           // same as LC_CMD_3DVIEW (also see LC_PROP_DRW_3DVIEW)
#define LC_CMD_3D_STDVIEW 602   // Set default view
#define LC_CMD_3D_PARAMS 603    // Settings...
#define LC_CMD_3D_SAVEIMAGE 604 // Save Image...

#define LC_CMD_AKAGRIP 29999 // internal use
#define LC_CMD_CUSTOM 30000  // offset for custom commands

//-----------------------------------------------
//  Objects Properties
//-----------------------------------------------

// Global properties
#define LC_PROP_G_REGCODE 1 //  W string; registration code
#define LC_PROP_G_VERSION 2 // R  string; Litecad version
#define LC_PROP_G_MSGTITLE \
  3                             // RW string; title for messages (default "LiteCAD")
#define LC_PROP_G_APPFILENAME 4 //  W string; application filename
#define LC_PROP_G_DWGAPP 5      //  W string; DWG application filename
#define LC_PROP_G_DXFAPP 6      //  W string; DXF application filename
#define LC_PROP_G_HELPFILE \
  10                        // RW string; name of help file ("Litecad.chm" by default)
#define LC_PROP_G_DIRDLL 11 // R  string; directory of Litecad.dll
#define LC_PROP_G_DIRFONTS \
  13 // RW string; directory of font files (*.lcf), by default
     // <LC_PROP_G_DIRDLL>\Fonts
#define LC_PROP_G_DIRLNG \
  14 // RW string; directory of LNG files, by default
     // <LC_PROP_G_DIRDLL>\Languages
#define LC_PROP_G_DIRTPL \
  16 // RW string; directory of "New File" templates (*.lcd), by default
     // <LC_PROP_G_DIRDLL>\Templates
#define LC_PROP_G_DIRCFG \
  17                            // RW string; directory of config files (the directory must have write
                                // permit), by default <LC_PROP_G_DIRDLL>\Config
#define LC_PROP_G_ICON16 20     // RW string|void *|int; replaces icon for dialogs
#define LC_PROP_G_ICON32 21     // RW string|void *|int; replaces icon for dialogs
#define LC_PROP_G_RULERBMP 22   // W void *; bitmap for rulers corner
#define LC_PROP_G_PRNUSEBMP 25  // RW bool; use bitmap for printing
#define LC_PROP_G_PRNBMPFILE 26 // RW string; file to save the print bitmap
#define LC_PROP_G_PRNBTNRAS \
  27 // RW bool; visibility of button "Raster" in the "Print" dialog
#define LC_PROP_G_PRNBTNSRIF \
  28 // RW bool; visibility of button "Save Raster Image to File" in the
     // "Print/Raster" dialog
#define LC_PROP_G_PNTPIXSIZE \
  29 // RW bool; meaning of negative PtSize parameter of lcPaint_DrawPoint
     // function, if TRUE - size in pixels, FALSE - % of window height  // undoc
#define LC_PROP_G_GETDELENT \
  30                            // RW bool; controls if lcBlockGetEnt... function will retrieve deleted
                                // entities or not
#define LC_PROP_G_SBARHEIGHT 32 // R  int; StatusBar default height
#define LC_PROP_G_FILEPROGRESS \
  33 // RW bool; Display progress box during file load/save
#define LC_PROP_G_FILEDEFEXT \
  35                           // RW string; default extention on file open dialog
#define LC_PROP_G_FILELCD 31   // RW bool; enable *.lcd file filter
#define LC_PROP_G_DEMOTEXT 36  // RW string; demo text drawn over a window
#define LC_PROP_G_DEMOSIZE 37  // RW int; size of demo text (pixels)
#define LC_PROP_G_DEMOCOLOR 38 // RW int; RGB color of demo text
#define LC_PROP_G_TABCMDWND 39 // RW bool; command window on <Tab> key
#define LC_PROP_G_UNDOMSG \
  40 // RW bool; display a message when Undo/Redo buffer is empty
#define LC_PROP_G_MINCHARSIZE \
  41                               // RW int; 3..15 below this value a char will be drawn as a rectangle
#define LC_PROP_G_PANREDQUAL 42    // RW bool; reduce draw quality when panning
#define LC_PROP_G_ENTEXT 43        // RW bool; draw entity's extents rectangle
#define LC_PROP_G_BLKRELOADMODE 44 //  W int; resets g_BlkReloadMode
#define LC_PROP_G_TABFILE \
  45 //  W string; the file to be opened in lcCreateWindow with LC_WS_FILETABS
     //  style
#define LC_PROP_G_MSGSAVEAS \
  46                          // RW bool; display message "Saved As" in the function _lcDrwSave
#define LC_PROP_G_JUR 47      // RW bool;   // undoc
#define LC_PROP_G_FILEEXTS 48 // RW string; supported file extentions
#define LC_PROP_G_DLGVAL 50   // RW string; dialog value for lcDgGetValue
#define LC_PROP_G_STR 51      // RW string|int; g_PropStr | mode for g_StrList
#define LC_PROP_G_INT 52      // R  int;    g_PropInt
#define LC_PROP_G_FLOAT 53    // R  float;  g_PropFloat
#define LC_PROP_G_HANDLE 54    // R  void *; g_Propvoid *
#define LC_PROP_G_DELKEYERASE \
  55 // RW bool; using <Delete> key for "Erase" command (LC_CMD_ERASE)

// Selection Options
#define LC_PROP_SEL_PICKBOXSIZE \
  61 // RW int; Half-size of selecting square, in pixels
#define LC_PROP_SEL_PICKBYRECT \
  62 // RW bool; Implied windowing for objects selection (AutoCAD PICKAUTO)
#define LC_PROP_SEL_PICKDRAG \
  63 // RW bool; Selection Rect: Press and Drag (same as AutoCAD PICKDRAG system
     // variable)
#define LC_PROP_SEL_PICKADD \
  64 // RW bool; Controls whether subsequent selections replace the current
     // selection set or add to
#define LC_PROP_SEL_PICKBYLAYER \
  65 // RW bool; Select entities only on active layer
#define LC_PROP_SEL_PICKINPGON \
  66                               // RW bool; Select polygons by click on inner area
#define LC_PROP_SEL_PICKINPGONF 67 // RW bool; -/- Only filled polygons
#define LC_PROP_SEL_PICKINIMG \
  68                           // RW bool; Select images by click on inner area
#define LC_PROP_SEL_COLORL1 69 // RW int; Line Color of selected entities
#define LC_PROP_SEL_COLORL2 70 // RW int; Line Bg Color of selected entities
#define LC_PROP_SEL_COLORF 71  // RW int; Fill color of selected entities
#define LC_PROP_SEL_HATCHFILL \
  72                               // RW bool; Draw hatch filling when entity is selected
#define LC_PROP_SEL_ENABLEGRIPS 73 // RW bool; Draw grips on selected entities
#define LC_PROP_SEL_GRIPSIZE 74    // RW int; Size of grip square, in pixels
#define LC_PROP_SEL_GRIPCOLORF 75  // RW int; Grips filling color  (COLORREF)
#define LC_PROP_SEL_GRIPCOLORB 76  // RW int; Grips border color (COLORREF)
#define LC_PROP_SEL_GRIPENTLIM \
  77                           // RW int; Max number of selected entities to display grips
#define LC_PROP_SEL_GRIPNUM 78 // RW bool; Draw grips numbers (for polyline)

#define LC_PROP_G_CAMERA_COUNT 90 // R  int; number of camera devices
#define LC_PROP_G_CAMERA_I 91     // RW int; set camera index
#define LC_PROP_G_CAMERA_INAME \
  92                                  // R  string; name of camera by index (LC_PROP_G_CAMERA_I)
#define LC_PROP_G_CAMERA_CONNECTED 93 // R  bool; TRUE if camera is connected
// for connected camera:
#define LC_PROP_G_CAMERA_NAME 94   // R  string; name of connected camera
#define LC_PROP_G_CAMERA_TIME 95   // RW int; interval between camera shots (msec)
#define LC_PROP_G_CAMERA_WIDTH 96  // R  int; width of camera image (pixels)
#define LC_PROP_G_CAMERA_HEIGHT 97 // R  int; height of camera image (pixels)
#define LC_PROP_G_CAMERA_BPP 98    // R  int; bits per pixel
#define LC_PROP_G_CAMERA_COFO \
  99                               // R  int; color format (LC_COFO_RGB24 and others)
#define LC_PROP_G_CAMERA_BITS 100  // R  void *|int; pointer to image bits
#define LC_PROP_G_CAMERA_BPROW 101 // R  int; bytes per row

#define LC_PROP_G_PTBUFNEWPTS 131 // R  int; number of last added points
#define LC_PROP_G_PTBUFCLR 132    // RW bool; auto clear Ptbuf after draw
#define LC_PROP_G_MPGONCLR 133    // RW bool; auto clear Mpgon after draw

#define LC_PROP_G_TEXT_ALIGN 141  // RW int; LC_TA_LEFBOT, LC_TA_CENBOT, etc
#define LC_PROP_G_TEXT_H 142      // RW float; Text height
#define LC_PROP_G_TEXT_WS 143     // RW float; Width scale coefficient (0.1 - 10.0)
#define LC_PROP_G_TEXT_CSPACE 144 // RW float; Charspace coefficient (0.0 - 3.0)
#define LC_PROP_G_TEXT_ANG 145    // RW float; Rotation angle
#define LC_PROP_G_TEXT_OBL 146    // RW float; Oblique angle
#define LC_PROP_G_TEXT_UPDOWN 147 // RW bool; Upside-down direction
#define LC_PROP_G_TEXT_BACK 148   // RW bool; Backward direction
#define LC_PROP_G_TEXT_FILL 149   // RW bool;
#define LC_PROP_G_TEXT_BORDER 150 // RW bool;

#define LC_PROP_G_BARC_CENTER \
  161                            // RW bool; if TRUE - basepoint is a center, FALSE - left bottom corner
#define LC_PROP_G_BARC_ANGLE 162 // RW float; rotation angle around base point
#define LC_PROP_G_BARC_BELOW \
  163                             // RW float; height below baseline (for EAN8, EAN13)
#define LC_PROP_G_BARC_QZONE 164  // RW float; size of quiet space
#define LC_PROP_G_BARC_CHKSUM 165 // RW bool; add checksum digit at the end
#define LC_PROP_G_BARC_ECL \
  166                             // RW int; error correction level (LC_BARC_QRECL_M or other)
#define LC_PROP_G_BARC_INVERT 167 // RW bool; negative filling
#define LC_PROP_G_BARC_WRATIO \
  168                            // RW float; <wide bar> / <narrow bar> (varies from 2.0 to 3.0)
#define LC_PROP_G_BARC_LINEW 169 // RW float; compensation of line width

#define LC_PROP_G_BEAMCOLOR0D \
  191                             // RW int; lcPaint_DrawPoint with PtMode=LC_POINT_BEAM1
#define LC_PROP_G_BEAMCOLOR1D 192 // RW int;
#define LC_PROP_G_BEAMCOLOR2D 193 // RW int;
#define LC_PROP_G_BEAMCOLOR0U \
  194                             // RW int; lcPaint_DrawPoint with PtMode=LC_POINT_BEAM0
#define LC_PROP_G_BEAMCOLOR1U 195 // RW int;
#define LC_PROP_G_BEAMCOLOR2U 196 // RW int;

#define LC_PROP_G_NAV_LEFT 201   // RW int; Left of Navicator window
#define LC_PROP_G_NAV_TOP 202    // RW int; Top of Navicator window
#define LC_PROP_G_NAV_WIDTH 203  // RW int; Width of Navicator window
#define LC_PROP_G_NAV_HEIGHT 204 // RW int; Height of Navicator window

#define LC_PROP_G_JL_EALEN 210 // RW int; Length of entity's arrow (pixels)
#define LC_PROP_G_JL_EAW 211   // RW int; Half-width of entity's arrow (pixels)
#define LC_PROP_G_JL_JALEN 212 // RW int; Length of jump arrow (pixels)
#define LC_PROP_G_JL_JAW 213   // RW int; Half-width of jump arrow (pixels)
#define LC_PROP_G_JL_ACOLOR \
  214 // RW int; Color of jump arrow, RGB value (COLORREF)
#define LC_PROP_G_JL_NUMFONT \
  215 // RW string; Numbers font name, 0 means default GUI font
#define LC_PROP_G_JL_NUMSIZE \
  216 // RW int; Numbers font size, ignored if the font name is empty
#define LC_PROP_G_JL_NUMCOLOR \
  217                             // RW int; Color of numbers, RGB value (COLORREF)
#define LC_PROP_G_JL_DRAWJARR 218 // RW bool; Draw arrows of jump lines
#define LC_PROP_G_JL_DRAWJLINE \
  219                             // RW bool; Draw jump lines (between entities)
#define LC_PROP_G_JL_DRAWEDOT 220 // RW bool; Draw dots on entity lines
#define LC_PROP_G_JL_DRAWEARR 221 // RW bool; Draw arrows on entity lines
#define LC_PROP_G_JL_DRAWENUM 222 // RW bool; Draw numbers on entity lines

#define LC_PROP_G_OSNAP_MARK 226 // RW bool; display osnap marker
#define LC_PROP_G_OSNAP_APER 227 // RW bool; display osnap aperture box
#define LC_PROP_G_OSNAP_MARKSIZE \
  228 // RW int;  half-size of marker indicating snap point, pixels (1-15)
#define LC_PROP_G_OSNAP_APERSIZE \
  229 // RW int;  half-size of square around cursor, used for snap, pixels
      // (1-15)
#define LC_PROP_G_OSNAP_MARKCOLOR \
  230 // RW int;  color of osnap marker (COLORREF)

//^ #define LC_PROP_G_ORDSEQ_AUTO     231   // RW bool;  Auto-sort connected
// entities (LC_CMD_ORDER_SEQ)

#define LC_PROP_G_EMUL_OVERDIST \
  232                                // RW float; Min. dist to treat near lines as overlapped
#define LC_PROP_G_EMUL_OVERCOLOR 233 // RW int; Color for overlapped parts

// options of export a drawing to raster image
#define LC_PROP_G_RAS_FILL 250 // RW bool; enable filling
#define LC_PROP_G_RAS_COLOR \
  251                             // RW bool; enable colors  when save as raster image
#define LC_PROP_G_RAS_NOPRINT 252 // RW bool; enable layer "no print" option

// options for lcWndWaitPoint function
#define LC_PROP_G_WPT_TEXTX 260 // RW int; text X position relative to cursor
#define LC_PROP_G_WPT_TEXTY 261 // RW int; text Y position relative to cursor
#define LC_PROP_G_WPT_TEXTA 262 // RW int; LC_TA_LEFBOT, LC_TA_CENBOT, etc

#define LC_PROP_G_TIN_PT0 270 // R  void *; result of lcTIN_TriGetEdge
#define LC_PROP_G_TIN_PT1 271 // R  void *; result of lcTIN_TriGetEdge
#define LC_PROP_G_TIN_TR 272  // R  void *; result of lcTIN_TriGetEdge

// Design window
#define LC_PROP_WND__MIN 301
#define LC_PROP_WND_ID 301     // RW int; identifier
#define LC_PROP_WND_WIDTH 302  // R  int; Width of drawing's area (pixels)
#define LC_PROP_WND_HEIGHT 303 // R  int; Height of drawing's area (pixels)
#define LC_PROP_WND_PIXELSIZE \
  304 // RW float; Current scale of the drawing in the window, units per pixel
#define LC_PROP_WND_PICKBOXSIZE \
  305 // R  float; Half-size of selecting square (drawing's units)
#define LC_PROP_WND_CURSORX \
  306                        // R  int|float; Cursor position X (pixels)|Cursor position X (drawing's
                             // units)
#define LC_PROP_WND_CURX 306 //    LC_PROP_WND_CURSORX
#define LC_PROP_WND_CURSORY \
  307                        // R  int|float; Cursor position Y (pixels)|Cursor position Y (drawing's
                             // units)
#define LC_PROP_WND_CURY 307 // R  LC_PROP_WND_CURSORY
#define LC_PROP_WND_CURLEF \
  308 // R  float; left side of selecting square, in drawing units
#define LC_PROP_WND_CURBOT \
  309 // R  float; bottom side of selecting square, in drawing units
#define LC_PROP_WND_CURRIG \
  310 // R  float; right side of selecting square, in drawing units
#define LC_PROP_WND_CURTOP \
  311                        // R  float; top side of selecting square, in drawing units
#define LC_PROP_WND_XMIN 312 // R  float;
#define LC_PROP_WND_YMIN 313 // R  float;
#define LC_PROP_WND_XMAX 314 // R  float;
#define LC_PROP_WND_YMAX 315 // R  float;
#define LC_PROP_WND_XCEN 316 // R  float;
#define LC_PROP_WND_YCEN 317 // R  float;
#define LC_PROP_WND_DX 318   // R  float;
#define LC_PROP_WND_DY 319   // R  float;
#define LC_PROP_WND_RULERSENABLE \
  320                               // R  bool;   true if window was created with LC_WS_RULERS flag
#define LC_PROP_WND_RULERS 321      // RW bool;
#define LC_PROP_WND_SELECT 322      // RW bool; enable/disable to select objects
#define LC_PROP_WND_VIEWBLOCK 323   // R  void *; void * to active block
#define LC_PROP_WND_BLOCK 323       //  same as LC_PROP_WND_VIEWBLOCK
#define LC_PROP_WND_DRW 324         // R  void *; void * to active drawing
#define LC_PROP_WND_HWND 325        // R  void *; WinAPI void * (HWND)
#define LC_PROP_WND_HASFOCUS 326    // R  bool; Indication "Has focus"
#define LC_PROP_WND_HASFILETABS 327 // R  bool; window has File Tabs
#define LC_PROP_WND_NUMFILETABS 328 // R  int; number of drawings in the list
#define LC_PROP_WND_NUMDRW 328      // same as LC_PROP_WND_NUMFILETABS
#define LC_PROP_WND_DROPFILES \
  329                             // RW bool; Registers whether a window accepts dropped files
#define LC_PROP_WND_ZOOMWHEEL 330 // RW bool; enable zoom by wheel
//^ #define LC_PROP_WND_CRECTS_EDIT     327    // RW bool; "Edit ClipRects" mode
//^ #define LC_PROP_WND_CRECTS_VISIBLE  328    // RW bool; display cliprects
// when not active
#define LC_PROP_WND_JUMPLINES 339 // RW bool; display jump lines
#define LC_PROP_WND_MAGNIFIER \
  340                                // RW bool; display magnifier at window rig-bot corner
#define LC_PROP_WND_NAVIGATOR 341    // RW bool; display "Aerial View" window
#define LC_PROP_WND_COLORBG 342      // RW int; background color
#define LC_PROP_WND_COLORCURSOR 343  // RW int; cursor color
#define LC_PROP_WND_COLORFORE 344    // RW int; foreground color
#define LC_PROP_WND_COLORINFBG 345   // RW int; info box background color
#define LC_PROP_WND_COLORINFBORD 346 // RW int; info box border color
#define LC_PROP_WND_COLORINFTEXT 347 // RW int; info box text color
#define LC_PROP_WND_CURSORSYS 348    //    same as LC_PROP_WND_CURSORARROW
#define LC_PROP_WND_CURSORARROW \
  348                               // RW bool|int|void *; Enable arrow cursor | set cursor (LC_CURSOR_ARROW
                                    // or other)
#define LC_PROP_WND_CURSORCROSS 349 // RW bool; Enable crosshair cursor
#define LC_PROP_WND_CURSORSIZE \
  350                              // RW int; Size of crosshair cursor, % of screen, if negative - size in
                                   // pixels
#define LC_PROP_WND_CURSORPBOX 351 // RW bool; Enable cursor pickbox rect
#define LC_PROP_WND_COORDS \
  352 // RW bool; display cursor coords at left-bottom corner
#define LC_PROP_WND_ENT \
  353                            // R  void *; picked entity (see lcWndPickEnt function)
#define LC_PROP_WND_PROPWND 354  // R  void *; void * to properties window
#define LC_PROP_WND_BLOCKBPT 355 // RW bool; display block basepoint
#define LC_PROP_WND_LWMODE \
  355                           // RW int;  line width mode (LC_LW_THIN, LC_LW_REAL, LC_LW_PIXEL)
#define LC_PROP_WND_LWSCALE 356 // RW float; line width screen scale, mm / pixel
//^ #define LC_PROP_WND_BREAKPOINTS     347    // RW bool; display breakpoints
//^ #define LC_PROP_WND_BREAKPTNUMS     348    // RW bool; display numbers of
// breakpoints
#define LC_PROP_WND_ALPHABLEND \
  360 // RW bool; enable alpha blend (transparent filling)
#define LC_PROP_WND_STDBLKFRAME \
  361                             // RW bool; draw red frame around the window if standard block is active
#define LC_PROP_WND_BLKBASEPT 362 // RW bool; display block basepoint
#define LC_PROP_WND_SIZE \
  363                         // R  string; window size, pixels (format "%d x %d", PSWidth(), PSHeight()
                              // )
#define LC_PROP_WND_DTIME 364 // R  int; redraw time, milliseconds
#define LC_PROP_WND_DRAWPAPER \
  365                              // RW bool; draw paper sheet for "Paper space" blocks
#define LC_PROP_WND_FROZEN 366     // RW bool; "Frozen" mode
#define LC_PROP_WND_FROZENVIEW 367 // RW bool; if true - can't chnage view rect
#define LC_PROP_WND_COMMAND \
  368                       // R  int|void *|bool; Id of active command | void * to active command |
                            // TRUE if has active command
#define LC_PROP_WND_CMD 368 // same as LC_PROP_WND_COMMAND
#define LC_PROP_WND_CMDENT1 \
  369 // RW bool; TRUE - only one entity added by command, FALSE - several
      // entities
#define LC_PROP_WND_OSNAP \
  370 // RW int|bool; object snap mode  LC_OSNAP_NODE and others | On/Off
#define LC_PROP_WND_OSNAPMENU \
  371                                 // RW bool; display "object snap" menu on <shift>+<RBDown>
                                      // (CBaseWnd::BaseOnRButtonDown)
#define LC_PROP_WND_ORTHO 372         // RW bool; ortho mode
#define LC_PROP_WND_PTRACK 373        // RW bool; polar tracking on/off
#define LC_PROP_WND_PTRACK_ANGLE 374  // RW float; step angle for polar tracking
#define LC_PROP_WND_PTRACK_ANGREL 375 // RW bool; relative / absolute angle
#define LC_PROP_WND_PTRACK_DIST \
  376                               // RW bool|float; use distance step along polar vector | value of dist.
                                    // step
#define LC_PROP_WND_BASEPT 377      // R  bool; Has Base point   // undoc
#define LC_PROP_WND_BASEX 378       // R  float; Base point position X   // undoc
#define LC_PROP_WND_BASEY 379       // R  float; Base point position Y   // undoc
#define LC_PROP_WND_GRIDSNAP 380    // RW bool;
#define LC_PROP_WND_GRIDSHOW 381    // RW bool; Display coordinate grid
#define LC_PROP_WND_GRIDDX 382      // RW float; Grid & snap step
#define LC_PROP_WND_GRIDDY 383      // RW float;
#define LC_PROP_WND_GRIDX0 384      // RW float; Origin point
#define LC_PROP_WND_GRIDY0 385      // RW float;
#define LC_PROP_WND_GRIDBOLDX 386   // RW int; Bold step X
#define LC_PROP_WND_GRIDBOLDY 387   // RW int; Bold step Y
#define LC_PROP_WND_GRIDCOLOR 388   // RW int; Line color
#define LC_PROP_WND_GRIDDOTTED 389  // RW bool; Line is dotted
#define LC_PROP_WND_GRIDCOLOR2 390  // RW int; Bold Line color
#define LC_PROP_WND_GRIDDOTTED2 391 // RW bool; Bold Line is dotted

#define LC_PROP_WND_RSNAP 402     // RW bool; Enable snap to rectangle border
#define LC_PROP_WND_RSNAPSHOW 403 // RW bool; Display snap rectanle
#define LC_PROP_WND_RSNAPLEF 404  // RW float; X left
#define LC_PROP_WND_RSNAPBOT 405  // RW float; Y bottom
#define LC_PROP_WND_RSNAPRIG 406  // RW float; X right
#define LC_PROP_WND_RSNAPTOP 407  // RW float; Y top
#define LC_PROP_WND_RSNAPW 408    // RW float; Width (from X left)
#define LC_PROP_WND_RSNAPH 409    // RW float; Height (from Y bottom)
#define LC_PROP_WND_RSNAPCOLORM \
  410 // RW int; Rectangle filling color on Model space
#define LC_PROP_WND_RSNAPCOLORP \
  411 // RW int; Rectangle filling color on Paper space

#define LC_PROP_WND_PANSTEP 420 // RW int; Minimal step, pixels
#define LC_PROP_WND_PANLW \
  421 // RW bool; optimize line width (draw as 1pix size)
#define LC_PROP_WND_PANIMAGE \
  422 // RW bool; optimize raster images (draw as hatch)
#define LC_PROP_WND_PANFILL \
  423 // RW bool; optimize polygon filling (don't fill)
#define LC_PROP_WND_PANPIXSZ \
  424 // RW bool; reduce resolution (increase pixel size)

#define LC_PROP_WND_MEASCOLORPNT \
  430 // RW int; COLORREF for points of DIST, AREA tools
#define LC_PROP_WND_MEASCOLORLINE \
  431                                // RW int; COLORREF for lines of DIST, AREA tools
#define LC_PROP_WND_MEASLINESIZE 432 // RW int; line size for DIST, AREA tools
#define LC_PROP_WND_MEASFONTSIZE 433 // RW int; font size
#define LC_PROP_WND_MEASFILLAREA 434 // RW int; fill area polygons with hatch

#define LC_PROP_WND_KBMOVE_ENABLE 437 // RW bool; enable movement by keyboard
#define LC_PROP_WND_KBMOVE_DIST 438   // RW float; distance step
#define LC_PROP_WND_KBMOVE_ANGLE 439  // RW float; angle step
#define LC_PROP_WND_KBMOVE_SCALE 440  // RW float; scale step

#define LC_PROP_WND_XLINEANG \
  444 // RW float; direction angle for command LC_CMD_XLINE
#define LC_PROP_WND_BGIMAGE \
  445 // RW string|bool; Background image filename | Display
#define LC_PROP_WND_LTVIEWMIN \
  446 // RW int; Linetype visibility, min size of pattern, pixels
#define LC_PROP_WND_LTVIEWMAX \
  447 // RW int; Linetype visibility, max size of pattern, pixels

#define LC_PROP_WND_FRAME_LEFT \
  451 // R  int; Left position on parent window (pixels)
#define LC_PROP_WND_FRAME_TOP \
  452                                // R  int; Top position on parent window (pixels)
#define LC_PROP_WND_FRAME_WIDTH 453  // R  int; Frame width (pixels)
#define LC_PROP_WND_FRAME_HEIGHT 454 // R  int; Frame height (pixels)

// User specified data
#define LC_PROP_WND_HANDLE0 460 // RW int;
#define LC_PROP_WND_HANDLE1 461 // RW int;
#define LC_PROP_WND_HANDLE2 462 // RW int;
#define LC_PROP_WND_HANDLE3 463 // RW int;
#define LC_PROP_WND_HANDLE4 464 // RW int;
#define LC_PROP_WND_HANDLE5 465 // RW int;
#define LC_PROP_WND_HANDLE6 466 // RW int;
#define LC_PROP_WND_HANDLE7 467 // RW int;
#define LC_PROP_WND_HANDLE8 468 // RW int;
#define LC_PROP_WND_HANDLE9 469 // RW int;
#define LC_PROP_WND_INT0 470    // RW int;
#define LC_PROP_WND_INT1 471    // RW int;
#define LC_PROP_WND_INT2 472    // RW int;
#define LC_PROP_WND_INT3 473    // RW int;
#define LC_PROP_WND_INT4 474    // RW int;
#define LC_PROP_WND_INT5 475    // RW int;
#define LC_PROP_WND_INT6 476    // RW int;
#define LC_PROP_WND_INT7 477    // RW int;
#define LC_PROP_WND_INT8 478    // RW int;
#define LC_PROP_WND_INT9 479    // RW int;
#define LC_PROP_WND_FLOAT0 480  // RW float;
#define LC_PROP_WND_FLOAT1 481  // RW float;
#define LC_PROP_WND_FLOAT2 482  // RW float;
#define LC_PROP_WND_FLOAT3 483  // RW float;
#define LC_PROP_WND_FLOAT4 484  // RW float;
#define LC_PROP_WND_FLOAT5 485  // RW float;
#define LC_PROP_WND_FLOAT6 486  // RW float;
#define LC_PROP_WND_FLOAT7 487  // RW float;
#define LC_PROP_WND_FLOAT8 488  // RW float;
#define LC_PROP_WND_FLOAT9 489  // RW float;
#define LC_PROP_WND_STR0 490    // RW string;
#define LC_PROP_WND_STR1 491    // RW string;
#define LC_PROP_WND_STR2 492    // RW string;
#define LC_PROP_WND_STR3 493    // RW string;
#define LC_PROP_WND_STR4 494    // RW string;
#define LC_PROP_WND_STR5 495    // RW string;
#define LC_PROP_WND_STR6 496    // RW string;
#define LC_PROP_WND_STR7 497    // RW string;
#define LC_PROP_WND_STR8 498    // RW string;
#define LC_PROP_WND_STR9 499    // RW string;
#define LC_PROP_WND__MAX 499

// StatusBar  (see lcCreateStatbar and others)
#define LC_PROP_SBAR__MIN 501
#define LC_PROP_SBAR_H 501          // RW int; height (by default
#define LC_PROP_SBAR_FONTNAME 502   // RW string; font name
#define LC_PROP_SBAR_FONTSIZE 503   // RW int; font size
#define LC_PROP_SBAR_TEXTY 504      // RW int; dist from top of status bar
#define LC_PROP_SBAR_TEXTCOLOR 505  // RW int; text color (COLORREF)
#define LC_PROP_SBAR_BGCOLOR 506    // RW int; background color (COLORREF)
#define LC_PROP_SBAR_FRAMECOLOR 507 // RW int; frame color (COLORREF)
#define LC_PROP_SBAR__MAX 519

// Font
#define LC_PROP_FONT__MIN 601
#define LC_PROP_FONT_FILENAME 601 // R  string;
#define LC_PROP_FONT_NAME 602     // R  string;
#define LC_PROP_FONT_LCF 603      // R  bool;
#define LC_PROP_FONT_HEIGHT 604   // R  float;
#define LC_PROP_FONT_FILLED 605   // R  bool;
#define LC_PROP_FONT_TTF 606      // R  bool;
#define LC_PROP_FONT_NCHARS 607   // R  int; number of chars in a font
#define LC_PROP_FONT__MAX 629

// Multipolygon
#define LC_PROP_MPGON__MIN 631
#define LC_PROP_MPGON_XMIN 631 // R  float; Xmin
#define LC_PROP_MPGON_YMIN 632 // R  float; Ymin
#define LC_PROP_MPGON_XMAX 633 // R  float; Xmax
#define LC_PROP_MPGON_YMAX 634 // R  float; Ymax
#define LC_PROP_MPGON_XCEN 635 // R  float; X of extents center
#define LC_PROP_MPGON_YCEN 636 // R  float; Y of extents center
#define LC_PROP_MPGON_W 637    // R  float; Width of extents rect
#define LC_PROP_MPGON_H 638    // R  float; Height of extents rect
#define LC_PROP_MPGON__MAX 649

// TIN point type
#define LC_PROP_TINPTYPE__MIN 680
#define LC_PROP_TINPTYPE_NAME 680  // RW string; name of point type
#define LC_PROP_TINPTYPE_DTEXT 681 // RW string; draw text
#define LC_PROP_TINPTYPE_COLOR 682 // RW int; color of points
#define LC_PROP_TINPTYPE__MAX 699

// TIN point
#define LC_PROP_TINPNT__MIN 701
#define LC_PROP_TINPNT_TYPE 701  // RW handle; point type
#define LC_PROP_TINPNT_I 702     // R  int; index
#define LC_PROP_TINPNT_X 703     // RW float;
#define LC_PROP_TINPNT_Y 704     // RW float;
#define LC_PROP_TINPNT_Z 705     // RW float;
#define LC_PROP_TINPNT_COLOR 706 // R  int; color (from point type)
#define LC_PROP_TINPNT_NAME 707  // R  string; name (from point type)
#define LC_PROP_TINPNT_ONAME \
  708                               // RW string; own name (overrides name of point type)
#define LC_PROP_TINPNT_DESCR 709    // RW string; point description
#define LC_PROP_TINPNT_IMGFILE 715  // RW string
#define LC_PROP_TINPNT_IMGFILE2 716 // R  string; full filename with path
#define LC_PROP_TINPNT_ATTR 720     // RW string
#define LC_PROP_TINPNT_ATTR1 721    // RW string
#define LC_PROP_TINPNT_ATTR2 722    // RW string
#define LC_PROP_TINPNT_ATTR3 723    // RW string
#define LC_PROP_TINPNT_ATTR4 724    // RW string
#define LC_PROP_TINPNT_ATTR5 725    // RW string
#define LC_PROP_TINPNT_ATTR6 726    // RW string
#define LC_PROP_TINPNT_ATTR7 727    // RW string
#define LC_PROP_TINPNT_ATTR8 728    // RW string
#define LC_PROP_TINPNT_ATTR9 729    // RW string
#define LC_PROP_TINPNT__MAX 730

// TIN triangle
#define LC_PROP_TINTR__MIN 731
#define LC_PROP_TINTR_I 731        // R int; index
#define LC_PROP_TINTR_IPT0 732     // R int; point0 index
#define LC_PROP_TINTR_IPT1 733     // R int; point1 index
#define LC_PROP_TINTR_IPT2 734     // R int; point2 index
#define LC_PROP_TINTR_PT0 735      // R handle;
#define LC_PROP_TINTR_PT1 736      // R handle;
#define LC_PROP_TINTR_PT2 737      // R handle;
#define LC_PROP_TINTR_PT0X 738     // R  float; X of point0
#define LC_PROP_TINTR_PT0Y 739     // R  float; Y of point0
#define LC_PROP_TINTR_PT0Z 740     // R  float; Z of point0
#define LC_PROP_TINTR_PT1X 741     // R  float; X of point1
#define LC_PROP_TINTR_PT1Y 742     // R  float; Y of point1
#define LC_PROP_TINTR_PT1Z 743     // R  float; Z of point1
#define LC_PROP_TINTR_PT2X 744     // R  float; X of point2
#define LC_PROP_TINTR_PT2Y 745     // R  float; Y of point2
#define LC_PROP_TINTR_PT2Z 746     // R  float; Z of point2
#define LC_PROP_TINTR_XC 747       // R  float; X of center point
#define LC_PROP_TINTR_YC 748       // R  float; Y of center point
#define LC_PROP_TINTR_ZC 749       // R  float; Z of center point
#define LC_PROP_TINTR_NVX 750      // R  float; X of normal vector
#define LC_PROP_TINTR_NVY 751      // R  float; Y of normal vector
#define LC_PROP_TINTR_NVZ 752      // R  float; Z of normal vector
#define LC_PROP_TINTR_NANG 753     // R  float; normal vector angle at XY plane
#define LC_PROP_TINTR_XMIN 754     // R  float; extents
#define LC_PROP_TINTR_YMIN 755     // R  float;
#define LC_PROP_TINTR_ZMIN 756     // R  float;
#define LC_PROP_TINTR_XMAX 757     // R  float;
#define LC_PROP_TINTR_YMAX 758     // R  float;
#define LC_PROP_TINTR_ZMAX 759     // R  float;
#define LC_PROP_TINTR_DX 760       // R  float;
#define LC_PROP_TINTR_DY 761       // R  float;
#define LC_PROP_TINTR_DZ 762       // R  float;
#define LC_PROP_TINTR_FLAGS 763    // RW int; 0-255
#define LC_PROP_TINTR_MARK 764     // RW bool; marked triangle
#define LC_PROP_TINTR_EDGE_PT0 771 // R  handle; result of lcTIN_TriGetEdge
#define LC_PROP_TINTR_EDGE_PT1 772 // R  handle; result of lcTIN_TriGetEdge
#define LC_PROP_TINTR_EDGE_TR 773  // R  handle; result of lcTIN_TriGetEdge
#define LC_PROP_TINTR__MAX 780

// TIN isoline
#define LC_PROP_TINISO__MIN 781
#define LC_PROP_TINISO_Z 781      // R float; Z of isoline
#define LC_PROP_TINISO_NVERS 782  // R int; number of vertices
#define LC_PROP_TINISO_IVER 783   // RW int; index of current vertex
#define LC_PROP_TINISO_X 784      // R float; X of isoline vertex
#define LC_PROP_TINISO_Y 785      // R float; Y of isoline vertex
#define LC_PROP_TINISO_CLOSED 786 // R bool; flag "closed isoline"
#define LC_PROP_TINISO__MAX 800

// also see LC_PROP_TIN_NAME and others

// Grid (by lcGrid... functions)
#define LC_PROP_GRID__MIN 1881
#define LC_PROP_GRID_XMIN 1882   // R  float; Xmin
#define LC_PROP_GRID_XMAX 1883   // R  float; Xmax
#define LC_PROP_GRID_YMIN 1884   // R  float; Ymin
#define LC_PROP_GRID_YMAX 1885   // R  float; Ymax
#define LC_PROP_GRID_W 1886      // R  float; delta X
#define LC_PROP_GRID_H 1887      // R  float; delta Y
#define LC_PROP_GRID_NCELLX 1888 // R  int; number of cells by X
#define LC_PROP_GRID_NCELLY 1889 // R  int; number of cells by Y
#define LC_PROP_GRID__MAX 1890

// Custom command
#define LC_PROP_CMD__MIN 2001
#define LC_PROP_CMD_ID 2001          // R  int; command identifier LC_CMD_CUSTOM+n
#define LC_PROP_CMD_PARAM 2002       // R  int; parameter passed by lcWndExeCommand
#define LC_PROP_CMD_STEP 2003        // RW int; command step
#define LC_PROP_CMD_LCWND 2004       // R  handle; design window
#define LC_PROP_CMD_HWND 2005        // R  handle; HWND window void *
#define LC_PROP_CMD_DRW 2006         // R  handle; drawing
#define LC_PROP_CMD_BLOCK 2007       // R  handle; block
#define LC_PROP_CMD_CURSORCROSS 2008 // RW bool; Enable crosshair cursor
#define LC_PROP_CMD_INT0 2010        // RW int; user value
#define LC_PROP_CMD_INT1 2011        // RW int; user value
#define LC_PROP_CMD_INT2 2012        // RW int; user value
#define LC_PROP_CMD_INT3 2013        // RW int; user value
#define LC_PROP_CMD_INT4 2014        // RW int; user value
#define LC_PROP_CMD_INT5 2015        // RW int; user value
#define LC_PROP_CMD_INT6 2016        // RW int; user value
#define LC_PROP_CMD_INT7 2017        // RW int; user value
#define LC_PROP_CMD_INT8 2018        // RW int; user value
#define LC_PROP_CMD_INT9 2019        // RW int; user value
#define LC_PROP_CMD_FLOAT0 2020      // RW float; user value
#define LC_PROP_CMD_FLOAT1 2021      // RW float; user value
#define LC_PROP_CMD_FLOAT2 2022      // RW float; user value
#define LC_PROP_CMD_FLOAT3 2023      // RW float; user value
#define LC_PROP_CMD_FLOAT4 2024      // RW float; user value
#define LC_PROP_CMD_FLOAT5 2025      // RW float; user value
#define LC_PROP_CMD_FLOAT6 2026      // RW float; user value
#define LC_PROP_CMD_FLOAT7 2027      // RW float; user value
#define LC_PROP_CMD_FLOAT8 2028      // RW float; user value
#define LC_PROP_CMD_FLOAT9 2029      // RW float; user value
#define LC_PROP_CMD_HAND0 2030       // RW handle; user value
#define LC_PROP_CMD_HAND1 2031       // RW handle; user value
#define LC_PROP_CMD_HAND2 2032       // RW handle; user value
#define LC_PROP_CMD_HAND3 2033       // RW handle; user value
#define LC_PROP_CMD_HAND4 2034       // RW handle; user value
#define LC_PROP_CMD_HAND5 2035       // RW handle; user value
#define LC_PROP_CMD_HAND6 2036       // RW handle; user value
#define LC_PROP_CMD_HAND7 2037       // RW handle; user value
#define LC_PROP_CMD_HAND8 2038       // RW handle; user value
#define LC_PROP_CMD_HAND9 2039       // RW handle; user value
#define LC_PROP_CMD_STR 2040         // RW string; user value
// #define LC_PROP_CMD_OBJ          2049  // R  handle; pointer to this command
#define LC_PROP_CMD__MAX 2050

//-----------------------------------------------
// Drawing
//-----------------------------------------------
#define LC_PROP_DRW__MIN 3001
#define LC_PROP_DRW_UID 3001      // R  string; Drawing's Unique Identifier
#define LC_PROP_DRW_FILENAME 3002 // RW string; Drawing's filename
#define LC_PROP_DRW_DESCR 3003    // RW string; drawing's description
#define LC_PROP_DRW_COMMENT 3003  // sane as LC_PROP_DRW_DESCR
#define LC_PROP_DRW_READONLY 3004 // RW bool; "Readonly" flag
#define LC_PROP_DRW_DIRTY 3005    // RW bool; "Drawing was modified" flag
#define LC_PROP_DRW_IDMAX \
  3006                            // R  int64|string; max Unique Identifier    // undoc
#define LC_PROP_DRW_SYNCZOOM 3011 // RW bool; "Synchronize Layouts zoom" flag
#define LC_PROP_DRW_HASALPHABLEND \
  3013 // R  bool; true is used alpha blend (transparent filling)
#define LC_PROP_DRW_BLKREFGRIPS \
  3014                            // RW int; BlockRef grips: 0-all grips, 1-only Pos, 2-Pos&Rotation
#define LC_PROP_DRW_JL_BASE 3015  // RW bool; Begin jump lines from basepoint
#define LC_PROP_DRW_JL_BASEX 3016 // RW float; Basepoint X
#define LC_PROP_DRW_JL_BASEY 3017 // RW float; Basepoint Y
#define LC_PROP_DRW_JL_LAYER \
  3018 // RW bool; enable layers for jump lines (add column in "Layers" dialog)
#define LC_PROP_DRW_EXTOFFLAYER \
  3019                              // RW bool; enable invisible layers for extents calculation
#define LC_PROP_DRW_ENABLEUNDO 3021 // RW bool; Enable undo recording
#define LC_PROP_DRW_LOCKSEL 3022    // RW bool; enable selection on locked layers
#define LC_PROP_DRW_MAXHATDASH \
  3023 // RW int; max number of hatch dashes in Hatch entities
#define LC_PROP_DRW_PROPLINFILL \
  3024 // RW bool; if TRUE then display LinFill item in Properties window
#define LC_PROP_DRW_PROPZTH \
  3025                          // RW bool; if TRUE then display Z and Thickness items in Properties
                                // window
#define LC_PROP_DRW_3DVIEW 3026 // R  bool; has 3D view (see LC_CMD_3DVIEW)
#define LC_PROP_DRW_PBTEXT 3027 // RW string; Text of progress box

// system variables (similar names as in AutoCAD)
#define LC_PROP_DRW_LUNITS \
  3031 // RW int; Linear units (LC_LUNIT_SCIEN and others)
#define LC_PROP_DRW_LUPREC \
  3032 // RW int; Precision for linear units (number of decimal digits)
#define LC_PROP_DRW_AUNITS \
  3033 // RW int; Angle units (LC_AUNIT_DEGREE and others)
#define LC_PROP_DRW_AUPREC \
  3034                           // RW int; Precision for angular units (number of decimal digits)
#define LC_PROP_DRW_ANGBASE 3035 // RW int; base angle
#define LC_PROP_DRW_ANGDIR \
  3036                            // RW int; angle direction, 0-counterclockwise, 1-clockwise
#define LC_PROP_DRW_INSUNITS 3037 // RW int;  (LC_INSUNIT_UNDEFINED and others)
#define LC_PROP_DRW_PDMODE \
  3038 // RW int; default point draw mode, LC_POINT_PIXEL and others
#define LC_PROP_DRW_PDSIZE \
  3039 // RW float; default point size, negative value means percent of a window
#define LC_PROP_DRW_CMLJUST \
  3040                            // RW int; Current multiline justification 0 = Top; 1 = Middle; 2 =
                                  // Bottom
#define LC_PROP_DRW_CMLSCALE 3041 // RW float; Current multiline scale

// Background, foreground and cursor colors
#define LC_PROP_DRW_COLORBACKM 3051   // RW int; background color for Model Space
#define LC_PROP_DRW_COLORBACKP 3052   // RW int; background color for Paper Space
#define LC_PROP_DRW_COLORFOREM 3053   // RW int; foreground color on Model Space
#define LC_PROP_DRW_COLORFOREP 3054   // RW int; foreground color on Paper Space
#define LC_PROP_DRW_COLORCURSORM 3055 // RW int; cursor color on Model Space
#define LC_PROP_DRW_COLORCURSORP 3056 // RW int; cursor color on Paper Space
#define LC_PROP_DRW_COLORPAPER \
  3057 // RW int; color of paper sheet on Paper Space

// Active outline color
#define LC_PROP_DRW_COLOR 3061        // RW string; Active color
#define LC_PROP_DRW_COLORBYLAYER 3062 // RW bool; Color "ByLayer"
#define LC_PROP_DRW_COLORBYBLOCK 3063 // RW bool; Color "ByBlock"
#define LC_PROP_DRW_COLORI 3064       // RW int; R bool; Active Color Index
#define LC_PROP_DRW_COLORT 3065       // RW int; R bool; Active True Color

// Active fill color
#define LC_PROP_DRW_FCOLOR 3066        // RW string; Active filling color
#define LC_PROP_DRW_FCOLORBYLAYER 3067 // RW bool; filling Color "ByLayer"
#define LC_PROP_DRW_FCOLORBYBLOCK 3068 // RW bool; filling Color "ByBlock"
#define LC_PROP_DRW_FCOLORI 3069       // RW int; R bool; Active filling Color Index
#define LC_PROP_DRW_FCOLORT 3070       // RW int; R bool; Active filling True Color

// Active objects and parameters, used on creating new entities
#define LC_PROP_DRW_LAYER \
  3081 // RW handle|string; void *to active layer|Name of active layer
#define LC_PROP_DRW_LINETYPE \
  3082                           // RW handle|string; void *to active linetype|Name of active linetype
#define LC_PROP_DRW_LTSCALE 3083 // RW float; active linetype scale
#define LC_PROP_DRW_TEXTSTYLE \
  3084 // RW handle|string; void *to active text style|Name of active text style
#define LC_PROP_DRW_DIMSTYLE \
  3085 // RW handle|string; void *to active dim style|Name of active dim style
#define LC_PROP_DRW_PNTSTYLE \
  3086 // RW handle|string; void *to active point style|Name of active point
       // style
#define LC_PROP_DRW_MLSTYLE \
  3087 // RW handle|string; void *to active mline style|Name of active mline
       // style
#define LC_PROP_DRW_BLOCK \
  3089 // RW handle|string; void *to active block|Name of active block
#define LC_PROP_DRW_VISBLOCK \
  3090 // RW handle|string; void *to currently visible block|Name of currently
       // visible block
#define LC_PROP_DRW_LAYOUT \
  3091 // RW handle|string; void *to active layout (Tab)
#define LC_PROP_DRW_BARCTYPE \
  3092 // RW int; active barcode type, LC_BARTYPE_CODE39 and others
#define LC_PROP_DRW_BARCSOLID \
  3093 // RW bool; draw barcode without filling option
#define LC_PROP_DRW_LWMODE \
  3094 // RW int;  line width mode (LC_LW_THIN, LC_LW_REAL, LC_LW_PIXEL)
#define LC_PROP_DRW_LWSCALE \
  3095                          // RW float; line width screen scale, mm / pixel
#define LC_PROP_DRW_LWIDTH 3096 // RW int; active Linewidth (for new entities)
#define LC_PROP_DRW_LWDEFAULT \
  3097 // RW int; Default linewidth (if linewidth==LC_LWIDTH_DEFAULT)
#define LC_PROP_DRW_LINFILL \
  3098                          // RW handle|string; void *to active linfill|Name of active linfill
#define LC_PROP_DRW_TINPNT 3102 // R  handle; active TIN point (snapped)
#define LC_PROP_DRW_TINTR \
  3103                          // R  handle; TIN triangle used by COkTIN::GetZ(..)
#define LC_PROP_DRW_TINXY0 3104 // RW bool; normalize TIN XY coordinates to 0.0

// Explode options
#define LC_PROP_DRW_EXPLODEARC \
  3131 // RW bool; enable exploding of arcs, circles, ellipses
#define LC_PROP_DRW_EXPPLINELA \
  3132 // RW bool; explode bulge polylines: TRUE-to lines and arcs, FALSE-to
       // lines
#define LC_PROP_DRW_EXPSIMPLINE \
  3133 // RW bool; explode simple polylines to lines
#define LC_PROP_DRW_EXPTEXTSPLINE \
  3134 // RW bool; explode TT text to splines (FALSE - to lines)

// Default named objects
#define LC_PROP_DRW_BLOCK_MODEL 3151 // R  handle; void *to "*Model_Space" block
#define LC_PROP_DRW_LAYER_0 3152     // R  handle; void *to layer "0"
#define LC_PROP_DRW_LINETYPE_CONT \
  3153 // R  handle; void *to linetype "Continuous"
#define LC_PROP_DRW_LINETYPE_BYLAY \
  3154 // R  handle; void *to linetype "ByLayer"
#define LC_PROP_DRW_LINETYPE_BYBLK \
  3155 // R  handle; void *to linetype "ByBlock"
#define LC_PROP_DRW_TEXTSTYLE_STD \
  3156                              // R  handle; void *to text style "Standard"
#define LC_PROP_DRW_TSTYLE_STD 3156 // same as LC_PROP_DRW_TEXTSTYLE_STD
#define LC_PROP_DRW_PNTSTYLE_STD \
  3157 // R  handle; void *to point style "Standard"
#define LC_PROP_DRW_DIMSTYLE_STD \
  3158 // R  handle; void *to dim style "Standard"
#define LC_PROP_DRW_MLSTYLE_STD \
  3159 // R  handle; void *to mline style "Standard"

// Default resolution
#define LC_PROP_DRW_RESOLARC \
  3171                               // RW int; default resolution for arc/circle/ellipse/bulge
#define LC_PROP_DRW_RESOLSPLINE 3172 // RW int; default resolution for splines
#define LC_PROP_DRW_RESOLTEXT 3173   // RW int; default resolution for TTF text

// Limits (also lcDrwSetLimits )
#define LC_PROP_DRW_LIM_MINPIXSIZE \
  3181                              // RW float; minimal pixel size (drawing units)
#define LC_PROP_DRW_LIM_MAXLEF 3182 // RW float; Xmin of limits rect
#define LC_PROP_DRW_LIM_MAXBOT 3183 // RW float; Ymin of limits rect
#define LC_PROP_DRW_LIM_MAXRIG 3184 // RW float; Xmax of limits rect
#define LC_PROP_DRW_LIM_MAXTOP 3185 // RW float; Ymax of limits rect
#define LC_PROP_DRW_LIM_MAXON 3186  // RW bool; enable max limits

// User specified data
#define LC_PROP_DRW_XDATASIZE 3251 // RW int; size of extra data (bytes)
#define LC_PROP_DRW_XDATA 3252     // RW handle; pointer to extra data
#define LC_PROP_DRW_INT0 3260      // RW int;
#define LC_PROP_DRW_INT1 3261      // RW int;
#define LC_PROP_DRW_INT2 3262      // RW int;
#define LC_PROP_DRW_INT3 3263      // RW int;
#define LC_PROP_DRW_INT4 3264      // RW int;
#define LC_PROP_DRW_INT5 3265      // RW int;
#define LC_PROP_DRW_INT6 3266      // RW int;
#define LC_PROP_DRW_INT7 3267      // RW int;
#define LC_PROP_DRW_INT8 3268      // RW int;
#define LC_PROP_DRW_INT9 3269      // RW int;
#define LC_PROP_DRW_FLOAT0 3270    // RW float;
#define LC_PROP_DRW_FLOAT1 3271    // RW float;
#define LC_PROP_DRW_FLOAT2 3272    // RW float;
#define LC_PROP_DRW_FLOAT3 3273    // RW float;
#define LC_PROP_DRW_FLOAT4 3274    // RW float;
#define LC_PROP_DRW_FLOAT5 3275    // RW float;
#define LC_PROP_DRW_FLOAT6 3276    // RW float;
#define LC_PROP_DRW_FLOAT7 3277    // RW float;
#define LC_PROP_DRW_FLOAT8 3278    // RW float;
#define LC_PROP_DRW_FLOAT9 3279    // RW float;
#define LC_PROP_DRW_STR0 3280      // RW string;
#define LC_PROP_DRW_STR1 3281      // RW string;
#define LC_PROP_DRW_STR2 3282      // RW string;
#define LC_PROP_DRW_STR3 3283      // RW string;
#define LC_PROP_DRW_STR4 3284      // RW string;
#define LC_PROP_DRW_STR5 3285      // RW string;
#define LC_PROP_DRW_STR6 3286      // RW string;
#define LC_PROP_DRW_STR7 3287      // RW string;
#define LC_PROP_DRW_STR8 3288      // RW string;
#define LC_PROP_DRW_STR9 3289      // RW string;
#define LC_PROP_DRW__MAX 3299

//-----------------------------------------------
// Drawing's Tables
//-----------------------------------------------
#define LC_PROP_TABLE__MIN 4000

// Common properties for tables
#define LC_PROP_TABLE_ID 4001         // R  int64|string; Unique Identifier
#define LC_PROP_TABLE_NAME 4002       // R  string; Table name
#define LC_PROP_TABLE_DESC 4003       // RW string; Description
#define LC_PROP_TABLE_DESCR 4003      // RW string; Description
#define LC_PROP_TABLE_DRW 4004        // R  handle; Handler to owner drawing
#define LC_PROP_TABLE_DELETED 4005    // R  bool; "Deleted" flag
#define LC_PROP_TABLE_ODA_HANDLE 4010 // RW string; ODA table handle  // undoc
#define LC_PROP_TABLE_TYPE 4011       // R  int; object type (LC_OBJ_LAYER and others)
#define LC_PROP_TABLE_PRIORITY 4012   // RW int; priority for sorting
#define LC_PROP_TABLE_NREFS 4013      // R  int; number of references to a table
#define LC_PROP_TABLE_XDATASIZE 4051  // RW int; size of extra data (bytes)
#define LC_PROP_TABLE_XDATA 4052      // RW handle; pointer to extra data
#define LC_PROP_TABLE_XSTR 4053       // RW string; user string (uses XDATA buffer)
#define LC_PROP_TABLE_INT0 4060       // RW int; user value
#define LC_PROP_TABLE_INT1 4061       // RW int; user value
#define LC_PROP_TABLE_INT2 4062       // RW int; user value
#define LC_PROP_TABLE_INT3 4063       // RW int; user value
#define LC_PROP_TABLE_INT4 4064       // RW int; user value
#define LC_PROP_TABLE_FLOAT0 4070     // RW float; user value
#define LC_PROP_TABLE_FLOAT1 4071     // RW float; user value
#define LC_PROP_TABLE_FLOAT2 4072     // RW float; user value
#define LC_PROP_TABLE_FLOAT3 4073     // RW float; user value
#define LC_PROP_TABLE_FLOAT4 4074     // RW float; user value
#define LC_PROP_TABLEBASE__MAX 4100

// Layer ----------------------------------------
#define LC_PROP_LAYER_ID \
  4001 // R  int64|string; Unique Identifier,  same as LC_PROP_TABLE_ID
#define LC_PROP_LAYER_NAME \
  4002 // RW string; Layer Name,  same as LC_PROP_TABLE_NAME
#define LC_PROP_LAYER_DESC \
  4003                             // RW string; Description, same as LC_PROP_TABLE_DESC
#define LC_PROP_LAYER_DESCR 4003   // RW string; Description
#define LC_PROP_LAYER_DRW 4004     // R  handle; Handle to owner drawing~
#define LC_PROP_LAYER_DELETED 4005 // R  bool; "Deleted" flag
#define LC_PROP_LAYER_COLOR 4101   // RW string; Color
#define LC_PROP_LAYER_COLORI 4102  // RW int; R bool; Color Index
#define LC_PROP_LAYER_COLORT 4103  // RW int; R bool; True Color
#define LC_PROP_LAYER_FCOLOR 4104  // RW string; Filling Color
#define LC_PROP_LAYER_FCOLORI 4105 // RW int; R bool; Filling Color Index
#define LC_PROP_LAYER_FCOLORT 4106 // RW int; R bool; Filling True Color
#define LC_PROP_LAYER_LINETYPE \
  4111                             // RW handle|string; Handle to Linetype|Name of Linetype
#define LC_PROP_LAYER_LWEIGHT 4112 // RW int; Linewidth
#define LC_PROP_LAYER_LWIDTH 4112  // same as LC_PROP_LAYER_LWEIGHT
#define LC_PROP_LAYER_LOCKED 4113  // RW bool; "No edit" flag
#define LC_PROP_LAYER_NOPRINT 4114 // RW bool; "Not printed" flag
#define LC_PROP_LAYER_VISIBLE 4115 // RW bool; "Visible"; flag
#define LC_PROP_LAYER_0 4116       // R  bool; "Layer 0" flag
#define LC_PROP_LAYER_NODLG \
  4117 // RW bool; not displayed in the "Layers" dialog
#define LC_PROP_LAYER_JUMPLINES \
  4118 // RW bool; enable jump lines for entities of this layer
#define LC_PROP_LAYER_OSNAP \
  4119                              // RW bool; enable object snap for entities of this layer
#define LC_PROP_LAYER_NOEXPORT 4120 // RW bool; "Not exportable" flag

// Linetype -------------------------------------
#define LC_PROP_LINETYPE_ID 4001         // R  int64|string; same as LC_PROP_TABLE_ID
#define LC_PROP_LINETYPE_NAME 4002       // RW string; same as LC_PROP_TABLE_NAME
#define LC_PROP_LINETYPE_DESC 4003       // RW string; same as LC_PROP_TABLE_DESC
#define LC_PROP_LINETYPE_DESCR 4003      // RW string; Description
#define LC_PROP_LINETYPE_DRW 4004        // R  handle; Handle to owner drawing~
#define LC_PROP_LINETYPE_DELETED 4005    // R  bool; "Deleted" flag
#define LC_PROP_LINETYPE_DATA 4145       // RW string; Linetype data in text form
#define LC_PROP_LINETYPE_SCALE 4146      // RW float; Global scale for this linetype
#define LC_PROP_LINETYPE_CONTINUOUS 4147 // R  bool; "Continuous" flag
#define LC_PROP_LINETYPE_BYLAYER 4148    // R  bool; "By Layer" flag
#define LC_PROP_LINETYPE_BYBLOCK 4149    // R  bool; "By Block" flag
#define LC_PROP_LINETYPE_STD \
  4150                               // R  bool; standard linetype ("Continuous" or "By Layer" or "By Block")
                                     // // undoc
#define LC_PROP_LINETYPE_PATLEN 4151 // R  float; Pattern length
#define LC_PROP_LINETYPE_NELEM 4153  // R  int; number of elements
#define LC_PROP_LINETYPE_IELEM 4154  //  W int; set index of active element
#define LC_PROP_LTELEM_LEN 4155      // R  float; segment length
#define LC_PROP_LTELEM_COMPLEX \
  4156 // R  bool; TRUE - element contains shape or text
#define LC_PROP_LTELEM_SHAPE \
  4157                           // R  bool; TRUE - text style is used, FALSE - draw only szText[0] and
                                 // fontfile is used
#define LC_PROP_LTELEM_TEXT 4158 // R  string; Text
#define LC_PROP_LTELEM_STYLE \
  4159 // R  handle; text style (valid if LC_PROP_LTELEM_SHAPE is FALSE)
#define LC_PROP_LTELEM_FONTNAME \
  4160                            // R  string; fontname (valid if LC_PROP_LTELEM_SHAPE is TRUE)
#define LC_PROP_LTELEM_SCALE 4161 // R  float; shape scale
#define LC_PROP_LTELEM_ANGLE \
  4162                               // R  float; rotation angle in radians for a text element in the linetype
#define LC_PROP_LTELEM_ABSANGLE 4163 // R  bool; if TRUE - RotAngle is absolute
#define LC_PROP_LTELEM_X 4164        // R  float; x offset of a shape
#define LC_PROP_LTELEM_Y 4165        // R  float; y offset of a shape

// Text style
#define LC_PROP_TSTYLE_ID 4001        // R  int64|string; same as LC_PROP_TABLE_ID
#define LC_PROP_TSTYLE_NAME 4002      // RW string; same as LC_PROP_TABLE_NAME
#define LC_PROP_TSTYLE_DESC 4003      // RW string; same as LC_PROP_TABLE_DESC
#define LC_PROP_TSTYLE_DESCR 4003     // RW string; Description
#define LC_PROP_TSTYLE_DRW 4004       // R  handle; Handle to owner drawing
#define LC_PROP_TSTYLE_DELETED 4005   // R  bool; "Deleted" flag
#define LC_PROP_TSTYLE_FONT 4175      // RW string; Font filename
#define LC_PROP_TSTYLE_HFONT 4176     // R  handle; Handle to font
#define LC_PROP_TSTYLE_HEIGHT 4177    // RW float; Default height
#define LC_PROP_TSTYLE_WSCALE 4178    // RW float; Default width scale
#define LC_PROP_TSTYLE_OBLIQUE 4179   // RW float; Default obluque angle
#define LC_PROP_TSTYLE_ANGLE 4180     // RW float; Default rotation angle
#define LC_PROP_TSTYLE_ALIGN 4181     // RW int; Default alignment
#define LC_PROP_TSTYLE_UPDOWN 4182    // RW bool; "Upside down" flag
#define LC_PROP_TSTYLE_BACKWARD 4183  // RW bool; "Backward" flag
#define LC_PROP_TSTYLE_LINESPACE 4184 // RW float; Default linespace
#define LC_PROP_TSTYLE_CHARSPACE 4185 // RW float; Default charspace
#define LC_PROP_TSTYLE_STANDARD 4186  // R  bool; "Standard" flag
#define LC_PROP_TSTYLE_SHAPES 4187    // R  bool; "Shapes" flag
#define LC_PROP_TSTYLE_WINFONT \
  4188                             // RW bool; if TRUE - Windows True Type font is used
#define LC_PROP_TSTYLE_SOLID 4189  // RW bool; Solid text
#define LC_PROP_TSTYLE_CLOSED 4190 // R  bool; font has closed shape
#define LC_PROP_TSTYLE_HOLLOW 4191 // R  bool; not solid and closed shape
#define LC_PROP_TSTYLE_BOLD 4192   // RW bool; "Bold" flag (for LC_ENT_TEXTWIN)
#define LC_PROP_TSTYLE_ITALIC \
  4193 // RW bool; "Italic" flag (for LC_ENT_TEXTWIN)
#define LC_PROP_TSTYLE_UNDERLINE \
  4194 // RW bool; "Underline" flag (for LC_ENT_TEXTWIN)
#define LC_PROP_TSTYLE_STRIKEOUT \
  4195 // RW bool; "Strikeout" flag (for LC_ENT_TEXTWIN)
#define LC_PROP_TSTYLE_MONOWIDTH \
  4196 // RW float; Width for monospaced font (0.0 - use default)

// Dimension style
#define LC_PROP_DIMST_ID 4001       // R  int64|string; same as LC_PROP_TABLE_ID
#define LC_PROP_DIMST_NAME 4002     // RW string; same as LC_PROP_TABLE_NAME
#define LC_PROP_DIMST_DESC 4003     // RW string; same as LC_PROP_TABLE_DESC
#define LC_PROP_DIMST_DESCR 4003    // RW string;
#define LC_PROP_DIMST_DRW 4004      // R  handle;
#define LC_PROP_DIMST_DELETED 4005  // R  bool;
#define LC_PROP_DIMST_STANDARD 4205 // R  bool;
#define LC_PROP_DIMST_ADEC \
  4211 // RW int; Number of precision places displayed in angular dimensions
#define LC_PROP_DIMST_ASZ \
  4212 // RW float; Controls dimension arrowhead size and hookline size
#define LC_PROP_DIMST_AUNIT \
  4213 // RW int; Controls the angle format for angular dimensions
#define LC_PROP_DIMST_AZIN \
  4214                          // RW int; Controls suppression of zeros for angular dimensions
#define LC_PROP_DIMST_BLK1 4215 // RW int|string; arrow1 type
#define LC_PROP_DIMST_BLK2 4216 // RW int|string; arrow2 type
#define LC_PROP_DIMST_CEN \
  4217 // RW float; Determines style of center marks for arcs or circles being
       // dimensioned
#define LC_PROP_DIMST_CLRD \
  4218 // RW int; Sets color for dimension leader lines, arrowheads, dimension
       // lines and leaders
#define LC_PROP_DIMST_CLRE \
  4219                          // RW int; Sets color for dimension extension lines
#define LC_PROP_DIMST_CLRT 4220 // RW int; Sets color for dimension text
#define LC_PROP_DIMST_DEC \
  4221 // RW int; Controls the precision for a primary units dimension's
       // tolerance values
#define LC_PROP_DIMST_DSEP \
  4222 // RW int; Single-character decimal separator used when creating
       // dimensions whose unit format is decimal
#define LC_PROP_DIMST_EXE \
  4223 // RW float; Controls extension of extension line beyond dimension line
#define LC_PROP_DIMST_EXO \
  4224 // RW float; Offset of extension lines from origin points
#define LC_PROP_DIMST_GAP \
  4225                            // RW float; Determines the gap around dimension text when the dimension
                                  // line is broken to fit the text
#define LC_PROP_DIMST_LDRBLK 4226 // RW int|string; leader arrow type
#define LC_PROP_DIMST_LFAC \
  4227                         // RW float; Global scale factor for linear dimensioning measurements
#define LC_PROP_DIMST_LWD 4228 // RW int; Dimension line lineweight
#define LC_PROP_DIMST_LWE 4229 // RW int; Extension line lineweight
#define LC_PROP_DIMST_POST \
  4230 // RW string; Sets a dimension prefix or suffix for the measurement text
#define LC_PROP_DIMST_RND \
  4231 // RW float; Sets a rounding value for dimensions.
#define LC_PROP_DIMST_SCALE \
  4232 // RW float; Overall scale factor applied to dimension variables for
       // sizes, distances and offsets
#define LC_PROP_DIMST_TAD \
  4233 // RW int; Determines text vertical position relative to the dimension
       // line
#define LC_PROP_DIMST_TIH \
  4234 // RW int; If 1, text between extension lines is always drawn
       // horizontally
#define LC_PROP_DIMST_TXT \
  4235                            // RW float; Dimension text height if the current dimstyle has no fixed
                                  // text height
#define LC_PROP_DIMST_TXSTY 4236  // RW handle|string; Text style
#define LC_PROP_DIMST_TSTYLE 4236 //    LC_PROP_DIMST_TXSTY
#define LC_PROP_DIMST_LUNIT \
  4237 // RW int; Sets units for all dimension types except Angular
#define LC_PROP_DIMST_ZIN \
  4238 // RW int; Controls the suppression of zeros in the primary unit value

// Point style
#define LC_PROP_PSTYLE_ID 4001       // R  int64|string; same as LC_PROP_TABLE_ID
#define LC_PROP_PSTYLE_NAME 4002     // RW string; same as LC_PROP_TABLE_NAME
#define LC_PROP_PSTYLE_DESC 4003     // RW string; same as LC_PROP_TABLE_DESC
#define LC_PROP_PSTYLE_DESCR 4003    // RW string;
#define LC_PROP_PSTYLE_DRW 4004      // R  handle;
#define LC_PROP_PSTYLE_DELETED 4005  // R  bool;
#define LC_PROP_PSTYLE_STANDARD 4265 // R  bool;
#define LC_PROP_PSTYLE_BLOCK 4266    // RW handle|string;
#define LC_PROP_PSTYLE_BSCALE 4267   // RW float;
#define LC_PROP_PSTYLE_TSTYLE 4268   // RW handle|string;
#define LC_PROP_PSTYLE_TH 4269       // RW float;
#define LC_PROP_PSTYLE_TWS 4270      // RW float;
#define LC_PROP_PSTYLE_PTMODE 4271   // RW int;  LC_POINT_PIXEL and others
#define LC_PROP_PSTYLE_PTSIZE 4272   // RW float;
#define LC_PROP_PSTYLE_SNAP 4273     // RW bool;
#define LC_PROP_PSTYLE_FIXED 4274    // RW bool;

// Multiline style
#define LC_PROP_MLSTYLE_ID 4001        // R  int64|string; Unique Identifier
#define LC_PROP_MLSTYLE_NAME 4002      // RW string;
#define LC_PROP_MLSTYLE_DESC 4003      // RW string;
#define LC_PROP_MLSTYLE_DESCR 4003     // RW string;
#define LC_PROP_MLSTYLE_DRW 4004       // R  handle; Handle to owner drawing
#define LC_PROP_MLSTYLE_DELETED 4005   // R  bool;
#define LC_PROP_MLSTYLE_STANDARD 4281  // R  bool;
#define LC_PROP_MLSTYLE_JOINTS 4282    // RW bool; draw joins
#define LC_PROP_MLSTYLE_STARTLINE 4283 // RW bool; draw start line
#define LC_PROP_MLSTYLE_STARTARC 4284  // RW bool; draw start arc
#define LC_PROP_MLSTYLE_ENDLINE 4285   // RW bool; draw end line
#define LC_PROP_MLSTYLE_ENDARC 4286    // RW bool; draw end arc
#define LC_PROP_MLSTYLE_NLINES 4287    // R int; number of lines
#define LC_PROP_MLSTYLE_ILINE 4288     // RW int; index of current line
#define LC_PROP_MLSTYLE_OFFSET 4289    // RW float; offset of current line
#define LC_PROP_MLSTYLE_LTYPE 4290     // RW handle; linetype of current line
#define LC_PROP_MLSTYLE_COLOR 4291     // RW string; color of current line

// Raster image
#define LC_PROP_IMAGE_ID 4001       // R  int; Unique Identifier
#define LC_PROP_IMAGE_NAME 4002     // RW string; Image name
#define LC_PROP_IMAGE_DESC 4003     // RW string; Image description
#define LC_PROP_IMAGE_DESCR 4003    // RW string; Image description
#define LC_PROP_IMAGE_DRW 4004      // R  handle; Handle to owner drawing
#define LC_PROP_IMAGE_DELETED 4005  // R  bool;
#define LC_PROP_IMAGE_FILENAME 4401 // RW string; Image filename
#define LC_PROP_IMAGE_SIZE 4402     // R  int;    Image size, bytes
#define LC_PROP_IMAGE_WPIX 4403     // R  int;    Image width (pixels)
#define LC_PROP_IMAGE_W 4404
#define LC_PROP_IMAGE_HPIX 4405 // R  int;    Image height (pixels)
#define LC_PROP_IMAGE_H 4406
#define LC_PROP_IMAGE_CBIT 4407     // R  int;    Color bits
#define LC_PROP_IMAGE_RGB 4408      // R  bool;   RGB/Palette colors
#define LC_PROP_IMAGE_EMBEDDED 4409 // RW bool;  saved inside a drawing
#define LC_PROP_IMAGE_CREATED 4410  // R  bool;  // undoc
#define LC_PROP_IMAGE_COLORS 4411   // RW handle;  pointer to palette memory
#define LC_PROP_IMAGE_BITS 4412     // RW handle;  pointer to points memory
#define LC_PROP_IMAGE_DIB 4413      // R  handle;

// Filling style
#define LC_PROP_LFILL_ID 4001       // R  int64|string; Unique Identifier
#define LC_PROP_LFILL_NAME 4002     // RW string;
#define LC_PROP_LFILL_DESC 4003     // RW string;
#define LC_PROP_LFILL_DESCR 4003    // RW string;
#define LC_PROP_LFILL_DRW 4004      // R  handle; Handle to owner drawing
#define LC_PROP_LFILL_DELETED 4005  // R  bool;
#define LC_PROP_LFILL_ENABLED0 4501 // R  bool; TRUE if line is enabled
#define LC_PROP_LFILL_DIST0 4502    // R  float; dist between lines
#define LC_PROP_LFILL_ANGLE0 4503   // R  float; angle of lines
#define LC_PROP_LFILL_GAP0 4504     // R  float; gap at line end
#define LC_PROP_LFILL_ENABLED1 4505 // R  bool; TRUE if line is enabled
#define LC_PROP_LFILL_DIST1 4506    // R  float; dist between lines
#define LC_PROP_LFILL_ANGLE1 4507   // R  float; angle of lines
#define LC_PROP_LFILL_GAP1 4508     // R  float; gap at line end

//-----------------------------------------------
// Block
//-----------------------------------------------
#define LC_PROP_BLOCK_ID 4001         // R  int64|string; same as LC_PROP_TABLE_ID
#define LC_PROP_BLOCK_NAME 4002       // RW string; same as LC_PROP_TABLE_NAME
#define LC_PROP_BLOCK_DESC 4003       // RW string; same as LC_PROP_TABLE_DESC
#define LC_PROP_BLOCK_DESCR 4003      // RW string;
#define LC_PROP_BLOCK_DRW 4004        // R  handle; Handle to owner drawing
#define LC_PROP_BLOCK_DELETED 4005    // R  bool;
#define LC_PROP_BLOCK_X 4801          // RW float;
#define LC_PROP_BLOCK_Y 4802          // RW float;
#define LC_PROP_BLOCK_UFSCALING 4803  // RW bool;
#define LC_PROP_BLOCK_UNITS 4804      // RW int;   LC_INSUNIT_UNDEFINED and other
#define LC_PROP_BLOCK_UNITSCALE 4810  // R  float;
#define LC_PROP_BLOCK_MODEL 4811      // R  bool;
#define LC_PROP_BLOCK_PAPER 4812      // R  bool;
#define LC_PROP_BLOCK_LAYOUT 4813     // R  bool;  MODEL or  PAPER
#define LC_PROP_BLOCK_STANDARD 4814   // R  bool;
#define LC_PROP_BLOCK_LAYOUTNAME 4815 // RW string;
#define LC_PROP_BLOCK_LAYOUTORDER \
  4816                            // RW int; value used for window tabs order  // undoc
#define LC_PROP_BLOCK_HIDDEN 4818 // R  bool;
#define LC_PROP_BLOCK_DIM 4819    // R  bool;
#define LC_PROP_BLOCK_HATCH 4820  // R  bool;
#define LC_PROP_BLOCK_NOBJ \
  4821 // R  int; number of graphic objects (not deleted) in the block
#define LC_PROP_BLOCK_NENTS \
  4821                              // R  int; number of graphic objects (not deleted) in the block
#define LC_PROP_BLOCK_NSELOBJ 4822  // R  int; number of selected objects
#define LC_PROP_BLOCK_NSELENTS 4822 // R  int; number of selected objects
#define LC_PROP_BLOCK_ATTRIBS 4827  // R  bool;  "Block has attributes" flag
// #define LC_PROP_BLOCK_TIN            4828  // RW handle;  active TIN entity
#define LC_PROP_BLOCK_ODA_LAYOUTHANDLE \
  4829 // RW string; ODA layout handle  // undoc
#define LC_PROP_BLOCK_ODA_VPORTHANDLE \
  4830 // RW string; ODA overall viewport handle  // undoc

// #define LC_PROP_BLOCK_PLACE          4828  // RW bool; uses "block place"
// points
#define LC_PROP_BLOCK_XMIN 4831    // R  float;
#define LC_PROP_BLOCK_YMIN 4832    // R  float;
#define LC_PROP_BLOCK_XMAX 4833    // R  float;
#define LC_PROP_BLOCK_YMAX 4834    // R  float;
#define LC_PROP_BLOCK_XCEN 4835    // R  float;
#define LC_PROP_BLOCK_YCEN 4836    // R  float;
#define LC_PROP_BLOCK_DX 4837      // R  float;
#define LC_PROP_BLOCK_DY 4838      // R  float;
#define LC_PROP_BLOCK_VISLEF 4839  // R  float; Visible rect
#define LC_PROP_BLOCK_VISBOT 4840  // R  float; Visible rect
#define LC_PROP_BLOCK_VISRIG 4841  // R  float; Visible rect
#define LC_PROP_BLOCK_VISTOP 4842  // R  float; Visible rect
#define LC_PROP_BLOCK_SELXMIN 4843 // R  float; Selection rect
#define LC_PROP_BLOCK_SELYMIN 4844 // R  float;
#define LC_PROP_BLOCK_SELXMAX 4845 // R  float;
#define LC_PROP_BLOCK_SELYMAX 4846 // R  float;
#define LC_PROP_BLOCK_SELXCEN 4847 // R  float;
#define LC_PROP_BLOCK_SELYCEN 4848 // R  float;
#define LC_PROP_SHAPE_ANGLE 4849   // RW float; Shape rotation angle
#define LC_PROP_PAPER__MIN 4851    //
#define LC_PROP_PAPER_INCH \
  4851 // RW bool; original paper units (used when import drawing from DWG)
#define LC_PROP_PAPER_X0 \
  4852 // RW float; X coordinate of paper left-bottom corner
#define LC_PROP_PAPER_Y0 \
  4853                          // RW float; Y coordinate of paper left-bottom corner
#define LC_PROP_PAPER_SIZE 4854 // R  int; Paper size (LC_PAPER_A0 and others)
#define LC_PROP_PAPER_ORIENT \
  4855                       // R  int; Paper orientation (LC_PAPER_BOOK and others)
#define LC_PROP_PAPER_W 4856 // R  float; Paper width, mm
#define LC_PROP_PAPER_H 4857 // R  float; Paper height, mm

#define LC_PROP_TABLE__MAX 4999

//=== Entities (properties) =========================================
#define LC_PROP_ENT__MIN 5001 // until LC_PROP_ENT__MAX  9999
#define LC_PROP_ENT_TYPE 5030 // R  int;
#define LC_PROP_ENT_ID 5001   // R  int64|string; Unique Identifier
#define LC_PROP_ENT_KEY 5002  // RW int; User value
#define LC_PROP_ENT_BLOCK \
  5024                       // R  handle|string; Handle to Block|Name of Block
#define LC_PROP_ENT_DRW 5025 // R  handle; Handle to drawing
#define LC_PROP_ENT_LAYER \
  5020 // RW handle|string; Handle to Layer|Name of Layer
#define LC_PROP_ENT_LINETYPE \
  5021                            // RW handle|string; Handle to Linetype|Name of Linetype
#define LC_PROP_ENT_LTSCALE 5022  // RW float; Linetype scale
#define LC_PROP_ENT_LWEIGHT 5023  // RW int; Lineweight
#define LC_PROP_ENT_LWIDTH 5023   // same as LC_PROP_ENT_LWEIGHT
#define LC_PROP_ENT_PRIORITY 5040 // RW int64|string; priority for sorting
#define LC_PROP_ENT_FROMCB \
  5035 // R  bool; TRUE if entity was added from ClipBoard
// Outline Color
#define LC_PROP_ENT_COLOR 5003        // RW string|int; Color name | RGB color
#define LC_PROP_ENT_COLORI 5004       // RW int; R bool; Color Index
#define LC_PROP_ENT_COLORT 5005       // RW int; R bool; True Color
#define LC_PROP_ENT_COLORBYLAYER 5006 // RW bool; Color "ByLayer"
#define LC_PROP_ENT_COLORBYBLOCK 5007 // RW bool; Color "ByBlock"
// Entity filling (for closed entities)
#define LC_PROP_ENT_SOLIDFILL 5008     // RW bool; same as LC_PROP_ENT_FILLED
#define LC_PROP_ENT_FILLED 5008        // RW bool;
#define LC_PROP_ENT_FILLING 5008       // RW bool; same as LC_PROP_ENT_FILLED
#define LC_PROP_ENT_WIPEOUT 5011       // RW bool; filled with background color
#define LC_PROP_ENT_FCOLOR 5012        // RW string|int; Filling Color | RGB color
#define LC_PROP_ENT_FCOLORI 5013       // RW int; R bool; Filling Color Index
#define LC_PROP_ENT_FCOLORT 5014       // RW int; R bool; Filling True Color
#define LC_PROP_ENT_FCOLORBYLAYER 5015 // RW bool; Filling Color "ByLayer"
#define LC_PROP_ENT_FCOLORBYBLOCK 5016 // RW bool; Filling Color "ByBlock"
#define LC_PROP_ENT_FALPHA 5017        // RW int; Filling Color alpha value
#define LC_PROP_ENT_LINFILL \
  5018                             // RW handle|string; Handle to Lfilling type|Name of Lfilling type
#define LC_PROP_ENT_LINFILLNL 5019 // R  int; number of generated filling lines
// Flags
#define LC_PROP_ENT_LOCKED 5026   // R  bool;
#define LC_PROP_ENT_VISIBLE 5027  // R  bool;
#define LC_PROP_ENT_HIDDEN 5028   // RW bool;
#define LC_PROP_ENT_BLINK 5029    // RW bool;  ???
#define LC_PROP_ENT_DELETED 5031  // RW bool;
#define LC_PROP_ENT_IMMORTAL 5032 // RW bool; can't be deleted
#define LC_PROP_ENT_SELECTED 5033 // R  bool; TRUE if entity is selected
#define LC_PROP_ENT_GRIPMODE 5034 // RW int; forbid movement of some grips
// Geometric extents
#define LC_PROP_ENT_XMIN 5052 // R  float; Xmin of entity extents
#define LC_PROP_ENT_YMIN 5053 // R  float; Ymin of entity extents
#define LC_PROP_ENT_XMAX 5054 // R  float; Xmax of entity extents
#define LC_PROP_ENT_YMAX 5055 // R  float; Ymax of entity extents
#define LC_PROP_ENT_XCEN 5056 // R  float; X center of entity
#define LC_PROP_ENT_YCEN 5057 // R  float; Y center of entity
#define LC_PROP_ENT_DX 5058   // R  float; width of entity
#define LC_PROP_ENT_DY 5059   // R  float; height of entity
#define LC_PROP_ENT_LEN \
  5060                             // R  float; length (line, pline, arc, circle, ellipse, rect)
#define LC_PROP_ENT_Z 5061         // RW float; Z coord for 2D objects
#define LC_PROP_ENT_THICKNESS 5062 // RW float; thickness of extrusion

// Extra data
#define LC_PROP_ENT_XDATAID 5041    // R  int; type of xdata lcEntXData
#define LC_PROP_ENT_XDATAFLAGS 5042 // RW int; flags of xdata
#define LC_PROP_ENT_XDATASIZE 5043  // R  int; size of extra data (bytes)
#define LC_PROP_ENT_XDATA 5044      // RW handle; pointer to extra data
#define LC_PROP_ENT_XSTR 5045       // RW string; user string (uses XDATA buffer)
#define LC_PROP_ENTBASE__MAX 5100

// Point
#define LC_PROP_POINT_STYLE \
  5101                             // RW handle|string; Handle to Point Style|Name of Point Style
#define LC_PROP_POINT_X 5102       // RW float;
#define LC_PROP_POINT_Y 5103       // RW float;
#define LC_PROP_POINT_Z 5061       // RW float; same as LC_PROP_ENT_Z
#define LC_PROP_POINT_SIZE 5104    // RW float;
#define LC_PROP_POINT_MODE 5105    // RW int;
#define LC_PROP_POINT_BANGLE 5106  // RW float;
#define LC_PROP_POINT_TDX 5107     // RW float;
#define LC_PROP_POINT_TDY 5108     // RW float;
#define LC_PROP_POINT_TANGLE 5109  // RW float;
#define LC_PROP_POINT_TEXT 5110    // RW string;
#define LC_PROP_POINT_TEXTLEN 5111 // R  int;
// #define LC_PROP_POINT_BPLACE     5112  // RW string; Block place attributes

// Points array
#define LC_PROP_PTARR_FILENAME 5112 // R  string; full filename (with path)
#define LC_PROP_PTARR_FNAME 5113    // R  string; only filename (without path)
#define LC_PROP_PTARR_DIR 5114      // R  string; file directory
#define LC_PROP_PTARR_LOADED 5115   // R  bool; TRUE if file is loaded
#define LC_PROP_PTARR_NUM 5116      // R  int; number of points
#define LC_PROP_PTARR_NUMVIS 5117   // R  int; number of currently visible points
#define LC_PROP_PTARR_TEXTVLIM 5118 // RW float; text view limit
#define LC_PROP_PTARR_VLIM10 5119   // RW float; view limit 1/10
#define LC_PROP_PTARR_VLIM100 5120  // RW float; view limit 1/100

// Line
#define LC_PROP_LINE_X0 5131       // RW float; Start point X
#define LC_PROP_LINE_Y0 5132       // RW float; Start point Y
#define LC_PROP_LINE_Z0 5133       // RW float; Start point Z
#define LC_PROP_LINE_X1 5134       // RW float; End point X
#define LC_PROP_LINE_Y1 5135       // RW float; End point Y
#define LC_PROP_LINE_Z1 5136       // RW float; End point Z
#define LC_PROP_LINE_DX 5137       // RW float; Delta X
#define LC_PROP_LINE_DY 5138       // RW float; Delta Y
#define LC_PROP_LINE_DZ 5139       // RW float; Delta Z
#define LC_PROP_LINE_ANG 5140      // RW float; Angle
#define LC_PROP_LINE_LEN 5141      // RW float; Length
#define LC_PROP_LINE_DSARROW0 5142 // RW handle; Dim.style for start arrow
#define LC_PROP_LINE_DSARROW1 5143 // RW handle; Dim.style for end arrow
#define LC_PROP_LINE_W0 5144       // RW float; Start width
#define LC_PROP_LINE_W1 5145       // RW float; End width
#define LC_PROP_LINE_SOLID 5146    // RW bool; Solid fill (if has width)

// Construction Line
#define LC_PROP_XLINE_X0 5151   // RW float; Base point X
#define LC_PROP_XLINE_Y0 5152   // RW float; Base point Y
#define LC_PROP_XLINE_ANG 5154  // RW float; Direction angle
#define LC_PROP_XLINE_DIRX 5155 // R  float; Direction vector X
#define LC_PROP_XLINE_DIRY 5156 // R  float; Direction vector Y
#define LC_PROP_XLINE_RAY 5157  // RW bool; Ray mode

// Circle
#define LC_PROP_CIRCLE_X 5201      // RW float; Center point X
#define LC_PROP_CIRCLE_Y 5202      // RW float; Center point Y
#define LC_PROP_CIRCLE_R 5204      // RW float; Radius
#define LC_PROP_CIRCLE_RAD 5204    // RW float; Radius
#define LC_PROP_CIRCLE_RADIUS 5204 // RW float; Radius
#define LC_PROP_CIRCLE_DIAM 5205   // RW float; Diameter
#define LC_PROP_CIRCLE_LEN 5206    // RW float; Circumference length
#define LC_PROP_CIRCLE_AREA 5207   // RW float; Area
#define LC_PROP_CIRCLE_ANG0 5208   // RW float; start angle
#define LC_PROP_CIRCLE_DIRCW 5209  // RW bool; direction, 1-CW, 0-CCW
#define LC_PROP_CIRCLE_RESOL 5210  // RW int; resolution
#define LC_PROP_CIRC_X 5201        // RW float; Center point X
#define LC_PROP_CIRC_Y 5202        // RW float; Center point Y
#define LC_PROP_CIRC_R 5204        // RW float; Radius
#define LC_PROP_CIRC_RAD 5204      // RW float; Radius
#define LC_PROP_CIRC_RADIUS 5204   // RW float; Radius
#define LC_PROP_CIRC_DIAM 5205     // RW float; Diameter
#define LC_PROP_CIRC_LEN 5206      // RW float; Circumference length
#define LC_PROP_CIRC_AREA 5207     // RW float; Area
#define LC_PROP_CIRC_ANG0 5208     // RW float; start angle
#define LC_PROP_CIRC_DIRCW 5209    // RW bool; direction, 1-CW, 0-CCW
#define LC_PROP_CIRC_RESOL 5210    // RW int; resolution

// Arc
#define LC_PROP_ARC_X 5231      // RW float; Center point X
#define LC_PROP_ARC_Y 5232      // RW float; Center point Y
#define LC_PROP_ARC_R 5234      // RW float; Radius
#define LC_PROP_ARC_RAD 5234    // RW float; Radius
#define LC_PROP_ARC_RADIUS 5234 // RW float; Radius
#define LC_PROP_ARC_ANG0 5235   // RW float; Start angle
#define LC_PROP_ARC_ANGARC 5236 // RW float; Arc included angle
#define LC_PROP_ARC_ANGEND 5237 // R  float; End angle
#define LC_PROP_ARC_X0 5238     // R  float; Start point X
#define LC_PROP_ARC_Y0 5239     // R  float; Start point Y
#define LC_PROP_ARC_Z0 5240     // RW float; Start point Z
#define LC_PROP_ARC_XMID 5241   // R  float; Middle point X
#define LC_PROP_ARC_YMID 5242   // R  float; Middle point Y
#define LC_PROP_ARC_XEND 5243   // R  float; End point X
#define LC_PROP_ARC_YEND 5244   // R  float; End point Y
#define LC_PROP_ARC_ZEND 5245   // RW float; End point Z
#define LC_PROP_ARC_LEN 5246    // R  float; Length
#define LC_PROP_ARC_CHLEN 5247  // R  float; Chord length
#define LC_PROP_ARC_AREA 5248   // R  float; Area
#define LC_PROP_ARC_CCW 5249    // R  bool; "Counter-ClockWise direction" flag
#define LC_PROP_ARC_SECTOR 5250 // RW bool; Draw as sector
#define LC_PROP_ARC_RESOL 5251  // RW int; resolution

// Ellipse
#define LC_PROP_ELL_X 5261     // RW float; Center point X
#define LC_PROP_ELL_Y 5262     // RW float; Center point Y
#define LC_PROP_ELL_R1 5264    // RW float; Radius first
#define LC_PROP_ELL_R2 5265    // RW float; Radius second
#define LC_PROP_ELL_RATIO 5266 // RW float; R2/R1
#define LC_PROP_ELL_ANGLE 5267 // RW float; Rotation angle
#define LC_PROP_ELL_ANG0 5268  // RW float; Start angle (for elliptical arc)
#define LC_PROP_ELL_ANGARC \
  5269                          // RW float; Arc included angle. Positive - counter-clockwise,
#define LC_PROP_ELL_ANGEND 5270 // R  float; End angle
#define LC_PROP_ELL_X0 5271     // R  float; Start point X
#define LC_PROP_ELL_Y0 5272     // R  float; Start point Y
#define LC_PROP_ELL_XEND 5273   // R  float; End point X
#define LC_PROP_ELL_YEND 5274   // R  float; End point Y
#define LC_PROP_ELL_LEN 5276    // R  float; Length
#define LC_PROP_ELL_AREA 5277   // R  float; Area
#define LC_PROP_ELL_FULL 5278   // R  bool;  "Full ellipse" flag
#define LC_PROP_ELL_CCW 5279    // R  bool;  "CounterClockWise direction" flag
#define LC_PROP_ELL_SECTOR 5282 // RW bool;  "Draw as sector" flag
#define LC_PROP_ELL_RESOL 5283  // RW int; resolution
#define LC_PROP_ELL__MAX 5299

// Lightweight Polyline
#define LC_PROP_PLINE_FIT 5301    // RW int; Fit type
#define LC_PROP_PLINE_CLOSED 5302 // RW bool; Closed polyline
#define LC_PROP_PLINE_NVERS 5303  // R  int; Number of vertices
#define LC_PROP_PLINE_WIDTH \
  5305                            // RW float|bool; Constant width | Has const width
#define LC_PROP_PLINE_LEN 5306    // R  float; Length
#define LC_PROP_PLINE_AREA 5307   // R  float; Area
#define LC_PROP_PLINE_CW 5308     // R  bool; "ClockWise direction" flag
#define LC_PROP_PLINE_CCW 5309    // R  bool; "Counter-ClockWise direction" flag
#define LC_PROP_PLINE_Z 5310      // RW float; Evevalion (Z)
#define LC_PROP_PLINE_CONSTZ 5311 // R  bool; all vertices have same Z
#define LC_PROP_PLINE_RESOLA 5312 // RW int; resolution for arc segments
#define LC_PROP_PLINE_RESOLS 5313 // RW int; resolution for spline segments
#define LC_PROP_PLINE_RADIUS \
  5314 // RW float|bool; Constant radius (for rounded polyline) | Has const
       // radius
#define LC_PROP_PLINE_CHAMFER \
  5315                             // RW bool; Chamfer or arc (for rounded polyline)
#define LC_PROP_PLINE_HASANG0 5316 // RW bool; Has start angle (for fit spline)
#define LC_PROP_PLINE_ANG0 5317    // RW float; Start angle (for fit spline)
#define LC_PROP_PLINE_HASANG2 5318 // RW bool; Has end angle (for fit spline)
#define LC_PROP_PLINE_ANG2 5319    // RW float; End angle (for fit spline)
#define LC_PROP_PLINE_WIPEOUT 5325 // RW bool; "wipeout" type polygon
#define LC_PROP_PLINE_ODSOLID \
  5326 // RW bool; made from SOLID entity at ODA import

// Multiline Polyline
#define LC_PROP_MLINE_STYLE \
  5351                            // RW handle|string; Handle to mline style|Name of mline style
#define LC_PROP_MLINE_JUST 5352   // RW int; justification LC_MLINE_TOP and other
#define LC_PROP_MLINE_SCALE 5353  // RW float; mline scale
#define LC_PROP_MLINE_NVERS 5354  // R  int; Number of vertices
#define LC_PROP_MLINE_CLOSED 5355 // RW bool; closed polyline
#define LC_PROP_MLINE_FIT 5356    // RW int; Fit type
#define LC_PROP_MLINE_LEN 5357    // R  float; Length
#define LC_PROP_MLINE_AREA 5358   // R  float; Area

// Rectangle
#define LC_PROP_RECT_X 5371       // RW float; Center X
#define LC_PROP_RECT_Y 5372       // RW float; Center Y
#define LC_PROP_RECT_W 5374       // RW float; Width
#define LC_PROP_RECT_H 5375       // RW float; Height
#define LC_PROP_RECT_ANGLE 5376   // RW float; Rotation angle
#define LC_PROP_RECT_R 5377       // RW float; Corners radius
#define LC_PROP_RECT_RAD 5377     // RW float; Corners radius
#define LC_PROP_RECT_RADIUS 5377  // RW float; Corners radius
#define LC_PROP_RECT_CHAMFER 5378 // RW bool; Chamfer at corners
#define LC_PROP_RECT_DIRCW 5379   // RW bool; Clockwise direction
#define LC_PROP_RECT_START 5380   // RW int; Start corner, 0-3
#define LC_PROP_RECT_LEN 5381     // R  float; Perimeter
#define LC_PROP_RECT_AREA 5382    // R  float; Area
#define LC_PROP_RECT_RESOL 5383   //
#define LC_PROP_RECT_GRID 5384    // RW bool; enable grid
#define LC_PROP_RECT_GRNW 5385    // RW int; number of cells along width
#define LC_PROP_RECT_GRNH 5386    // RW int; number of cells along height
#define LC_PROP_RECT_GRDW 5387    // RW float; cell size along width
#define LC_PROP_RECT_GRDH 5388    // RW float; cell size along height

// Clip Rectangle (on Model Space) (also lcCRectsClear abd others)
#define LC_PROP_CRECT_ID 5390    // RW int; Identifier
#define LC_PROP_CRECT_NAME 5391  // RW string; Name
#define LC_PROP_CRECT_X 5392     // RW float; Center X
#define LC_PROP_CRECT_Y 5393     // RW float; Center Y
#define LC_PROP_CRECT_W 5394     // RW float; Width
#define LC_PROP_CRECT_H 5395     // RW float; Height
#define LC_PROP_CRECT_ANGLE 5396 // RW float; Rotation angle
#define LC_PROP_CRECT_LEN 5398   // R  float; Perimeter
#define LC_PROP_CRECT_AREA 5399  // R  float; Area

// Text (LC_ENT_TEXT)
#define LC_PROP_TEXT_STYLE \
  5401                        // RW handle|string; Handle to text style|Name of text style
#define LC_PROP_TEXT_STR 5402 // RW string; Text content
#define LC_PROP_TEXT_STRT \
  5403                        // R  string; Text content (with translated codes)
#define LC_PROP_TEXT_LEN 5404 // R  int; Number of characters in the Text string
#define LC_PROP_TEXT_ALIGN \
  5405 // RW int; Alignment type (LC_TA_LEFBOT and others)
#define LC_PROP_TEXT_H \
  5406                              // RW float; Height (0-ByStyle, <0-pixel height, -1-default GUI size)
#define LC_PROP_TEXT_X 5407         // RW float; Insertion point X
#define LC_PROP_TEXT_Y 5408         // RW float; Insertion point Y
#define LC_PROP_TEXT_DX 5409        // RW int; Offset X (valid if Pixel Height is true)
#define LC_PROP_TEXT_DY 5410        // RW int; Offset Y (valid if Pixel Height is true)
#define LC_PROP_TEXT_WSCALE 5412    // RW float; Width factor (horisontal scale)
#define LC_PROP_TEXT_ANGLE 5413     // RW float; Rotation angle
#define LC_PROP_TEXT_OBLIQUE 5414   // RW float; Oblique angle
#define LC_PROP_TEXT_CHARSPACE 5415 // RW float;
#define LC_PROP_TEXT_WRECT 5416     // R  float; Width of a text bounding rectange
#define LC_PROP_TEXT_X0 5417        // R  float; X coordinate of left-bottom corner
#define LC_PROP_TEXT_Y0 5418        // R  float; Y coordinate of left-bottom corner
#define LC_PROP_TEXT_XFIT 5419      // RW float;
#define LC_PROP_TEXT_YFIT 5420      // RW float;
#define LC_PROP_TEXT_UPDOWN 5421    // RW bool; Indication "Upside-down text"
#define LC_PROP_TEXT_BACKWARD 5422  // RW bool; Indication "Backward text"
#define LC_PROP_TEXT_RESOL 5423     // RW int; Resolution

// TextWin (LC_ENT_TEXTWIN)
#define LC_PROP_TEXTW_STYLE \
  5431                         // RW handle|string; Handle to text style|Name of text style
#define LC_PROP_TEXTW_STR 5432 // RW string; Text content
#define LC_PROP_TEXTW_STRT \
  5433 // R  string; Text content (with translated codes)
#define LC_PROP_TEXTW_LEN \
  5434                           // R  int; Number of characters in the Text string
#define LC_PROP_TEXTW_ALIGN 5435 // RW int; Alignment type
#define LC_PROP_TEXTW_X 5436     // RW float; Insertion point X
#define LC_PROP_TEXTW_Y 5437     // RW float; Insertion point Y
#define LC_PROP_TEXTW_H 5438     // RW float; Height
#define LC_PROP_TEXTW_DX \
  5440 // RW int; Offset X (valid if Pixel Height is true)
#define LC_PROP_TEXTW_DY \
  5441                            // RW int; Offset Y (valid if Pixel Height is true)
#define LC_PROP_TEXTW_WSCALE 5442 // RW float; Width factor (horisontal scale)
#define LC_PROP_TEXTW_ANGLE 5443  // RW float; Rotation angle

// Multitine Text (LC_ENT_MTEXT)
#define LC_PROP_MTEXT__MIN 5451
#define LC_PROP_MTEXT_STYLE 5451     // RW handle|string;
#define LC_PROP_MTEXT_STR 5452       // RW string;
#define LC_PROP_MTEXT_LEN 5453       // R  int;
#define LC_PROP_MTEXT_ALIGN 5454     // RW int;
#define LC_PROP_MTEXT_X 5455         // RW float;
#define LC_PROP_MTEXT_Y 5456         // RW float;
#define LC_PROP_MTEXT_H 5458         // RW float;
#define LC_PROP_MTEXT_WSCALE 5459    // RW float;
#define LC_PROP_MTEXT_ANGLE 5460     // RW float;
#define LC_PROP_MTEXT_OBLIQUE 5461   // RW float;
#define LC_PROP_MTEXT_WRECT 5462     // R  float;
#define LC_PROP_MTEXT_HRECT 5463     // R  float;
#define LC_PROP_MTEXT_WRAPWIDTH 5464 // RW float;
#define LC_PROP_MTEXT_LINESPACE 5465 // RW float;
#define LC_PROP_MTEXT_CHARSPACE 5466 // RW float;
#define LC_PROP_MTEXT_MIRROR 5467    // RW bool;
#define LC_PROP_MTEXT_RESOL 5468     // RW int; Resolution
#define LC_PROP_MTEXT__MAX 5470

// Arc Text (LC_ENT_ARCTEXT)
#define LC_PROP_ATEXT__MIN 5481
#define LC_PROP_ATEXT_STYLE 5481 // RW handle|string; Text style
#define LC_PROP_ATEXT_STR 5482   // RW string;
#define LC_PROP_ATEXT_STRT \
  5483                               // R  string; Text content (with translated codes)
#define LC_PROP_ATEXT_LEN 5484       // R  int;
#define LC_PROP_ATEXT_X 5485         // RW float; Center X
#define LC_PROP_ATEXT_Y 5486         // RW float; Center Y
#define LC_PROP_ATEXT_R 5487         // RW float; Radius
#define LC_PROP_ATEXT_RAD 5487       // RW float; Radius
#define LC_PROP_ATEXT_RADIUS 5487    // RW float; Radius
#define LC_PROP_ATEXT_ANGLE 5488     // RW float; text Angle
#define LC_PROP_ATEXT_ANGSTA 5489    // R  float; Start angle
#define LC_PROP_ATEXT_ANGEND 5490    // R  float; End angle
#define LC_PROP_ATEXT_CW 5491        // RW bool; Clockwise direction
#define LC_PROP_ATEXT_H 5492         // RW float; Height
#define LC_PROP_ATEXT_WSCALE 5493    // RW float; Width scale
#define LC_PROP_ATEXT_CHARSPACE 5494 // RW float; Charspace
#define LC_PROP_ATEXT_ALIGN 5495     // RW int;
#define LC_PROP_ATEXT_RESOL 5496     // RW int; Resolution
#define LC_PROP_ATEXT__MAX 5499

// Attribute definition & Attribute
#define LC_PROP_ATT_MODE 5501 // RW int;
#define LC_PROP_ATT_TSTYLE \
  5502                            // RW handle|string; Handle to text style|Name of text style
#define LC_PROP_ATT_TAG 5503      // RW string;
#define LC_PROP_ATT_PROMPT 5504   // RW string;
#define LC_PROP_ATT_VALUE 5505    // RW string;
#define LC_PROP_ATT_ALIGN 5506    // RW int; Alignment type
#define LC_PROP_ATT_X 5507        // RW float; Insertion point X
#define LC_PROP_ATT_Y 5508        // RW float; Insertion point Y
#define LC_PROP_ATT_H 5510        // RW float; Height
#define LC_PROP_ATT_WSCALE 5511   // RW float; Width factor (horisontal scale)
#define LC_PROP_ATT_ANGLE 5512    // RW float; Rotation angle
#define LC_PROP_ATT_OBLIQUE 5513  // RW float; Oblique angle
#define LC_PROP_ATT_X0 5514       // R  float; X coordinate of left-bottom corner
#define LC_PROP_ATT_Y0 5515       // R  float; Y coordinate of left-bottom corner
#define LC_PROP_ATT_XFIT 5516     // RW float;
#define LC_PROP_ATT_YFIT 5517     // RW float;
#define LC_PROP_ATT_UPDOWN 5518   // RW bool; Indication "Upside-down text"
#define LC_PROP_ATT_BACKWARD 5519 // RW bool; Indication "Backward text"
#define LC_PROP_ATT_COLOR 5521    // R str;
#define LC_PROP_ATT_LAYER 5522    // R handle;
#define LC_PROP_ATT_LINETYPE 5523 // R handle;
#define LC_PROP_ATT_LTSCALE 5524  // R float;
#define LC_PROP_ATT_LWIDTH 5525   // R int;
#define LC_PROP_ATT_INVIS 5526    // RW bool; Mode: invisible
#define LC_PROP_ATT_LOCKPOS 5527  // RW bool; Mode: locked position
#define LC_PROP_ATT_MTEXT 5528    // RW bool; Mode: multiline text

// Block Reference
#define LC_PROP_BLKREF_BLOCK \
  5531                               // RW handle|string; Handle to Block|Name of Block
#define LC_PROP_BLKREF_X 5532        // RW float; Insertion point X
#define LC_PROP_BLKREF_Y 5533        // RW float; Insertion point Y
#define LC_PROP_BLKREF_SCALE 5534    // RW float;
#define LC_PROP_BLKREF_SCX 5535      // RW float;
#define LC_PROP_BLKREF_SCY 5536      // RW float;
#define LC_PROP_BLKREF_UFSCALE 5537  // R  bool;
#define LC_PROP_BLKREF_ANGLE 5538    // RW float;
#define LC_PROP_BLKREF_ARNX 5539     // RW int;
#define LC_PROP_BLKREF_ARDX 5540     // RW float;
#define LC_PROP_BLKREF_ARNY 5541     // RW int;
#define LC_PROP_BLKREF_ARDY 5542     // RW float;
#define LC_PROP_BLKREF_ARANG 5543    // RW float;
#define LC_PROP_BLKREF_ATTRIBS 5544  // R  bool;  "Block has attributes" flag
#define LC_PROP_BLKREF_GRIPMODE 5545 // RW int;
// only for using with LC_CMD_INSERT
#define LC_PROP_BLKREF_ONS_XY 5546    // RW bool; Specify position on-screen
#define LC_PROP_BLKREF_ONS_SCALE 5547 // RW bool; Specify scale on-screen
#define LC_PROP_BLKREF_ONS_ANGLE \
  5548 // RW bool; Specify rotation angle on-screen
#define LC_PROP_BLKREF_RETURN \
  5549 // R  handle; Handle to inserted object (block reference) after execution

// Raster Image reference
#define LC_PROP_IMGREF_IMAGE \
  5551                                // RW handle|string;  Handle to Image | Name of Image
#define LC_PROP_IMGREF_XC 5552        // RW float; X coordinate of center point
#define LC_PROP_IMGREF_YC 5553        // RW float; Y coordinate of center point
#define LC_PROP_IMGREF_W 5554         // RW float; Width
#define LC_PROP_IMGREF_H 5555         // RW float; Height
#define LC_PROP_IMGREF_WPIX 5556      // R  int; Image width in pixels
#define LC_PROP_IMGREF_HPIX 5557      // R  int; Image height in pixels
#define LC_PROP_IMGREF_SCALE 5558     // RW float; uniform scale, units per pixel
#define LC_PROP_IMGREF_PIXELSIZE 5558 // same as LC_PROP_IMGREF_SCALE
#define LC_PROP_IMGREF_SCALEX 5560    // RW float; X scale, units per pixel
#define LC_PROP_IMGREF_SCALEY 5561    // RW float; Y scale, units per pixel
#define LC_PROP_IMGREF_SQPIX 5562     // RW bool; if TRUE - uniform scale for puxel
#define LC_PROP_IMGREF_ANGLE \
  5564                             // RW float; rotation angle, around left-bottom corner
#define LC_PROP_IMGREF_BORDER 5565 // RW bool;  "Draw a border" flag
#define LC_PROP_IMGREF_TRANSP \
  5566                                 // RW int; transparency: 0-none, 1-TransColor, 2-AlphaValue
#define LC_PROP_IMGREF_TRCOLOR 5567    // RW int; transparent color (COLORREF)
#define LC_PROP_IMGREF_TRALPHA 5568    // RW int; alpha value (0-255)
#define LC_PROP_IMGREF_GRAYS 5569      // RW bool;
#define LC_PROP_IMGREF_GREY 5569       // RW bool; same as LC_PROP_IMGREF_GRAYS
#define LC_PROP_IMGREF_FLIPHOR 5570    // RW bool;
#define LC_PROP_IMGREF_FLIPVER 5571    // RW bool;
#define LC_PROP_IMGREF_PATH 5573       // R  string; image full filename
#define LC_PROP_IMGREF_GP_X 5574       // R  float; result of lcImgRefGetPixel
#define LC_PROP_IMGREF_GP_Y 5575       // R  float; result of lcImgRefGetPixel
#define LC_PROP_IMGREF_GP_COLOR 5576   // R  int; result of lcImgRefGetPixel
#define LC_PROP_IMGREF_GP_GRAY 5577    // RW bool; color mode for lcImgRefGetPixel
#define LC_PROP_IMGREF_UNSCALABLE 5578 // RW bool; "Unscalable image" flag
#define LC_PROP_IMGREF_UNSSCALE 5579   // RW float; scale for unscalable image
#define LC_PROP_IMGREF_UNSALIGN \
  5580 // RW int; Alignment of unscalable image, relative to LC_PROP_IMGREF_XC,
       // LC_PROP_IMGREF_YC (LC_IMGA_CENTER or other)

// ECW / Jpeg2000 Image
#define LC_PROP_ECW_FILENAME 5581 // R  string; Image filename
#define LC_PROP_ECW_LOADED 5582   // R  bool; "Image is loaded" flag
#define LC_PROP_ECW_WPIX 5583     // R  int; Width (pixels)
#define LC_PROP_ECW_HPIX 5584     // R  int; Height (pixels)
#define LC_PROP_ECW_CBIT 5585     // R  int; Color bits
#define LC_PROP_ECW_XMIN 5586     // R  float; X coordinate of left-bottom corner
#define LC_PROP_ECW_YMIN 5587     // R  float; Y coordinate of left-bottom corner
#define LC_PROP_ECW_XMAX 5588     // R  float; X coordinate of right-top corner
#define LC_PROP_ECW_YMAX 5589     // R  float; Y coordinate of right-top corner
#define LC_PROP_ECW_W 5590        // R  float; Width (drawing units)
#define LC_PROP_ECW_H 5591        // R  float; Height (drawing units)
#define LC_PROP_ECW_SCALEX 5592   // R  float;
#define LC_PROP_ECW_SCALEY 5593   // R  float;
#define LC_PROP_ECW_BORDER 5594   // RW bool; "Draw a border" flag
#define LC_PROP_ECW_GRAYS 5595    // RW bool; "Draw as grayscale" flag
#define LC_PROP_ECW_BRIGHT 5596   // RW int;  change brightness -200...+200

// Big Raster Image
#define LC_PROP_BRI_FILENAME 5601 // R  string; Image filename
#define LC_PROP_BRI_LOADED 5602   // R  bool; "Image is loaded" flag
#define LC_PROP_BRI_WPIX 5603     // R  int; Width (pixels)
#define LC_PROP_BRI_HPIX 5604     // R  int; Height (pixels)
#define LC_PROP_BRI_XMIN 5605     // R  float; X coordinate of left-bottom corner
#define LC_PROP_BRI_YMIN 5606     // R  float; Y coordinate of left-bottom corner
#define LC_PROP_BRI_XMAX 5607     // R  float; X coordinate of right-top corner
#define LC_PROP_BRI_YMAX 5608     // R  float; Y coordinate of right-top corner
#define LC_PROP_BRI_W 5609        // R  float; Width (drawing units)
#define LC_PROP_BRI_H 5610        // R  float; Height (drawing units)
#define LC_PROP_BRI_PIXSIZE 5611  // R  float; drawing units per pixel
#define LC_PROP_BRI_BORDER 5612   // RW bool; "Draw a border" flag

// Camera view
#define LC_PROP_CAMERA_X 5621 // RW float; left of camera view rect
#define LC_PROP_CAMERA_Y 5622 // RW float; bottom of camera view rect
#define LC_PROP_CAMERA_W 5623 // RW float; width of camera view rect
#define LC_PROP_CAMERA_H 5624 // RW float; height of camera view rect

// Hatch
#define LC_PROP_HATCH_NAME 5631    // RW string; Pattern name or "SOLID"
#define LC_PROP_HATCH_PATTERN 5632 // RW string; Pattern data for custom pattern
#define LC_PROP_HATCH_SCALE 5633   // RW float; Hatch scale
#define LC_PROP_HATCH_ANGLE 5634   // RW float; Rotation angle
#define LC_PROP_HATCH_SIZE 5635    // R  float; Pattern size
#define LC_PROP_HATCH_ASSOC 5636   // RW bool; "Associative hatch" flag
#define LC_PROP_HATCH_SOLID 5637   // RW bool; Solid fill
#define LC_PROP_HATCH_CUSTOM 5638  // R  bool; Custom pattern
#define LC_PROP_HATCH_NENTS \
  5639                           // R  int; number of boundary entities (for Associative hatch)
#define LC_PROP_HATCH_NPT 5640   // R  int; number of points
#define LC_PROP_HATCH_NLOOP 5641 // R  int; number of loops
#define LC_PROP_HATCH_NHPL 5642  // R  int; number of pattern lines
#define LC_PROP_HATCH_IHPL 5643  // W  int; set index of active pattern line
#define LC_PROP_HATCH_FALPHA \
  5644                             // RW int; transparency alpha value (only for Solid hatch)
#define LC_PROP_HATCH_AREA 5645    // R  float; Area
#define LC_PROP_HATCH_NDASHES 5646 // R  int; number of hatch dashes
#define LC_PROP_HPL_ANGLE 5651     // R  float;
#define LC_PROP_HPL_X0 5652        // R  float;
#define LC_PROP_HPL_Y0 5653        // R  float;
#define LC_PROP_HPL_DX 5654        // R  float;
#define LC_PROP_HPL_DY 5655        // R  float;
#define LC_PROP_HPL_NDASH 5656     // R  int;
#define LC_PROP_HPL_DASH1 5657     // R  float;
#define LC_PROP_HPL_DASH2 5658     // R  float;
#define LC_PROP_HPL_DASH3 5659     // R  float;
#define LC_PROP_HPL_DASH4 5660     // R  float;
#define LC_PROP_HPL_DASH5 5661     // R  float;
#define LC_PROP_HPL_DASH6 5662     // R  float;
#define LC_PROP_HPL_DASH7 5663     // R  float;
#define LC_PROP_HPL_DASH8 5664     // R  float;

// Viewport on Paper Space
#define LC_PROP_VPORT_LEF 5703      // RW float; Left side
#define LC_PROP_VPORT_BOT 5704      // RW float; Bottom side
#define LC_PROP_VPORT_RIG 5705      //
#define LC_PROP_VPORT_TOP 5706      //
#define LC_PROP_VPORT_BORDER 5707   // RW bool; display border line
#define LC_PROP_VPORT_W 5711        // RW float; Width
#define LC_PROP_VPORT_H 5712        // RW float; Height
#define LC_PROP_VPORT_VX 5713       // RW float; View center X on the projection
#define LC_PROP_VPORT_VY 5714       // RW float; View center Y on the projection
#define LC_PROP_VPORT_VSCALE 5715   // RW float; View scale
#define LC_PROP_VPORT_VANGLE 5716   // RW float; View rotation angle
#define LC_PROP_VPORT_FIXSCALE 5717 // RW bool; fixed scale

// Barcode
#define LC_PROP_BARC_XC 5751  // RW float; Center point X
#define LC_PROP_BARC_X 5751   //  same as LC_PROP_BARC_XC
#define LC_PROP_BARC_YC 5752  // RW float; Center point Y
#define LC_PROP_BARC_Y 5752   //  same as LC_PROP_BARC_YC
#define LC_PROP_BARC_W 5753   // RW float; Width
#define LC_PROP_BARC_H 5754   // RW float; Height
#define LC_PROP_BARC_ANG 5755 // RW float; Rotation angle
#define LC_PROP_BARC_TYPE \
  5756                              // RW int; barcode type, LC_BARTYPE_CODE39 and others
#define LC_PROP_BARC_CODE 5757      // RW string;
#define LC_PROP_BARC_TEXT 5757      // RW string; same as LC_PROP_BARC_CODE
#define LC_PROP_BARC_CHECKSUM 5758  // RW bool; add checksum
#define LC_PROP_BARC_NCHARS 5759    // R  int;
#define LC_PROP_BARC_NUBITS 5760    // R  int; number of unused bits (free bits)
#define LC_PROP_BARC_NARSIZE 5761   // R  float;
#define LC_PROP_BARC_WIDERATIO 5762 // RW float;
#define LC_PROP_BARC_QZONE 5763     // RW float;
#define LC_PROP_BARC_OFFSET 5764    // RW float;
#define LC_PROP_BARC_INVERT 5765    // RW bool;
#define LC_PROP_BARC_HIDETEXT 5766  // RW bool; do not display text
#define LC_PROP_BARC_TSTYLE \
  5767                              // RW handle|string; Handle to text style|Name of text style
#define LC_PROP_BARC_TEXTH 5768     // RW float; text height
#define LC_PROP_BARC_TEXTW 5769     // RW float; text width scale
#define LC_PROP_BARC_TEXTCS 5770    // RW float; text charspace
#define LC_PROP_BARC_TEXTALIGN 5771 // RW int; text alignment
#define LC_PROP_BARC_TEXTRES \
  5772                             // RW int; Resolution (if 0 then use LC_PROP_DRW_RESOLTEXT)
#define LC_PROP_BARC_ECLEVEL 5773  // RW int; error correction level
#define LC_PROP_BARC_MASKPAT 5774  // R  int; mask pattern (0-7)
#define LC_PROP_BARC_DATATYPE 5775 // R  int; data type
#define LC_PROP_BARC_SIZE 5776     // R  int|string; size of 2D barcode, H x W, dots
#define LC_PROP_BARC_NBARS \
  5777                          // R  int; same as LC_PROP_BARC_NMODX (for 1D - number of bars)
#define LC_PROP_BARC_NMODX 5777 // R  int; number of horizontal modules
#define LC_PROP_BARC_NMODY 5778 // R  int; number of vertical modules

// Arrow
#define LC_PROP_ARR_X0 5801    // RW float; Start point X
#define LC_PROP_ARR_Y0 5802    // RW float; Start point Y
#define LC_PROP_ARR_X1 5803    // RW float; End point X
#define LC_PROP_ARR_Y1 5804    // RW float; End point Y
#define LC_PROP_ARR_ANG 5805   // RW float; Angle from start to end
#define LC_PROP_ARR_LEN 5806   // RW float; Distance from start to end
#define LC_PROP_ARR_W 5807     // RW float; Width coefficient
#define LC_PROP_ARR_SW 5808    // RW float; Arrow width coef.
#define LC_PROP_ARR_SL 5809    // RW float; Arrow length coef.
#define LC_PROP_ARR_TIME 5810  // RW int; Time
#define LC_PROP_ARR_SHARP 5811 // RW bool; sharp start

// Spiral
#define LC_PROP_SPIR_X 5821      // RW float;
#define LC_PROP_SPIR_Y 5822      // RW float;
#define LC_PROP_SPIR_R 5823      // RW float; radius
#define LC_PROP_SPIR_RADIUS 5823 // RW float; radius
#define LC_PROP_SPIR_R2 5824     // RW float;
#define LC_PROP_SPIR_RATIO 5825  // RW float;
#define LC_PROP_SPIR_ANGLE 5826  // RW float;
#define LC_PROP_SPIR_TURNS 5827  // RW float;
#define LC_PROP_SPIR_DIRCW 5829  // RW bool;
#define LC_PROP_SPIR_CLOSED 5830 // RW bool; TRUE - draw outer corcle
#define LC_PROP_SPIR_DSTEP 5831  // R  float; distance between spiral turns
#define LC_PROP_SPIR_RESOL 5832  // RW int; resolution

// Xref
#define LC_PROP_XREF_FILENAME 5841 // RW string; full Filename (with path)
#define LC_PROP_XREF_FNAME 5842    // RW string; short Filename (without path)
#define LC_PROP_XREF_PATH 5843     // RW string; Path to the Filename
#define LC_PROP_XREF_X 5844        // RW float;
#define LC_PROP_XREF_Y 5845        // RW float;
#define LC_PROP_XREF_SCX 5846      // RW float;
#define LC_PROP_XREF_SCY 5847      // RW float;
#define LC_PROP_XREF_ANGLE 5848    // RW float;

// Dimension
#define LC_PROP_DIM_STYLE \
  6001                        // RW handle|string; Handle to dim style|Name of dim style
#define LC_PROP_DIM_MEAS 6003 // R  float; measured value
#define LC_PROP_DIM_TEXT 6004 // RW string;

#define LC_PROP_DIMANG_STYLE 6001
#define LC_PROP_DIMANG_MEAS 6003
#define LC_PROP_DIMANG_TEXT 6004

#define LC_PROP_DIMALI_STYLE 6001
#define LC_PROP_DIMALI_MEAS 6003
#define LC_PROP_DIMALI_TEXT 6004

#define LC_PROP_DIMDIA_STYLE 6001
#define LC_PROP_DIMDIA_MEAS 6003
#define LC_PROP_DIMDIA_TEXT 6004

#define LC_PROP_DIMRAD_STYLE 6001
#define LC_PROP_DIMRAD_MEAS 6003
#define LC_PROP_DIMRAD_TEXT 6004

#define LC_PROP_DIMORD_STYLE 6001
#define LC_PROP_DIMORD_MEAS 6003
#define LC_PROP_DIMORD_TEXT 6004

#define LC_PROP_DIMROT_STYLE 6001
#define LC_PROP_DIMROT_MEAS 6003
#define LC_PROP_DIMROT_TEXT 6004
#define LC_PROP_DIMLIN_STYLE 6001
#define LC_PROP_DIMLIN_MEAS 6003
#define LC_PROP_DIMLIN_TEXT 6004

#define LC_PROP_DIMANG__MIN 6011
#define LC_PROP_DIMANG_3PNT 6011  // R  bool; "3 points" mode
#define LC_PROP_DIMANG_2LINE 6012 // R  bool; "2 lines" mode
#define LC_PROP_DIMANG_CPX 6013   // RW float; center point 1
#define LC_PROP_DIMANG_CPY 6014   // RW float;
#define LC_PROP_DIMANG_DP1X 6015  // RW float; definition point 1
#define LC_PROP_DIMANG_DP1Y 6016  // RW float;
#define LC_PROP_DIMANG_DP2X 6017  // RW float; definition point 2
#define LC_PROP_DIMANG_DP2Y 6018  // RW float;
#define LC_PROP_DIMANG_L1P1X 6021 // RW float; line 1 def.point 1
#define LC_PROP_DIMANG_L1P1Y 6022 // RW float;
#define LC_PROP_DIMANG_L1P2X 6023 // RW float; line 1 def.point 2
#define LC_PROP_DIMANG_L1P2Y 6024 // RW float;
#define LC_PROP_DIMANG_DP3X 6023
#define LC_PROP_DIMANG_DP3Y 6024
#define LC_PROP_DIMANG_L2P1X 6025 // RW float; line 2 def.point 1
#define LC_PROP_DIMANG_L2P1Y 6026 // RW float;
#define LC_PROP_DIMANG_L2P2X 6027 // RW float; line 2 def.point 2
#define LC_PROP_DIMANG_L2P2Y 6028 // RW float;
#define LC_PROP_DIMANG_DP4X 6027
#define LC_PROP_DIMANG_DP4Y 6028
#define LC_PROP_DIMANG_APX 6029  // RW float; arc point X
#define LC_PROP_DIMANG_APY 6030  // RW float; arc point Y
#define LC_PROP_DIMANG_EXT1 6031 // RW bool; visibility of extention line 1
#define LC_PROP_DIMANG_EXT2 6032 // RW bool; visibility of extention line 2
#define LC_PROP_DIMANG_RAD 6033  // R  float; radius of dim arc
#define LC_PROP_DIMANG_TPOS 6034 // RW float; text position on arc
#define LC_PROP_DIMANG__MAX 6050

#define LC_PROP_DIMALI__MIN 6051
#define LC_PROP_DIMALI_DP1X 6051 // RW float; def point 1
#define LC_PROP_DIMALI_DP1Y 6052 // RW float;
#define LC_PROP_DIMALI_DP2X 6053 // RW float; def point 2
#define LC_PROP_DIMALI_DP2Y 6054 // RW float;
#define LC_PROP_DIMALI_TPX 6055  // RW float; text point
#define LC_PROP_DIMALI_TPY 6056  // RW float;
#define LC_PROP_DIMALI__MAX 6069

#define LC_PROP_DIMDIA__MIN 6071
#define LC_PROP_DIMDIA_CPX 6071 // RW float; center point
#define LC_PROP_DIMDIA_CPY 6072 // RW float;
#define LC_PROP_DIMDIA_RPX 6073 // RW float; radial point
#define LC_PROP_DIMDIA_RPY 6074 // RW float;
#define LC_PROP_DIMDIA_FPX 6075 // R  float; far radial point
#define LC_PROP_DIMDIA_FPY 6076 // R  float;
#define LC_PROP_DIMDIA_TPX 6077 // RW float; text point
#define LC_PROP_DIMDIA_TPY 6078 // RW float;
#define LC_PROP_DIMDIA__MAX 6085

#define LC_PROP_DIMRAD__MIN 6086
#define LC_PROP_DIMRAD_CPX 6086 // RW float; center point
#define LC_PROP_DIMRAD_CPY 6087 // RW float;
#define LC_PROP_DIMRAD_RPX 6088 // RW float; radial point
#define LC_PROP_DIMRAD_RPY 6089 // RW float;
#define LC_PROP_DIMRAD_TPX 6090 // RW float; text point
#define LC_PROP_DIMRAD_TPY 6091 // RW float;
#define LC_PROP_DIMRAD__MAX 6099

#define LC_PROP_DIMORD__MIN 6101
#define LC_PROP_DIMORD_XORD \
  6101                          // RW bool; TRUE - X ordinate, FALSE - Y ordinate
#define LC_PROP_DIMORD_DPX 6102 // RW float; def point
#define LC_PROP_DIMORD_DPY 6103 // RW float;
#define LC_PROP_DIMORD_TPX 6104 // RW float; text point
#define LC_PROP_DIMORD_TPY 6105 // RW float;
#define LC_PROP_DIMORD__MAX 6119

#define LC_PROP_DIMROT__MIN 6121
#define LC_PROP_DIMROT_ANGLE 6121 // RW float; rotation angle
#define LC_PROP_DIMROT_DP1X 6122  // RW float; def point 1
#define LC_PROP_DIMROT_DP1Y 6123  // RW float;
#define LC_PROP_DIMROT_DP2X 6124  // RW float; def point 2
#define LC_PROP_DIMROT_DP2Y 6125  // RW float;
#define LC_PROP_DIMROT_TPX 6126   // RW float; text point
#define LC_PROP_DIMROT_TPY 6127   // RW float;
#define LC_PROP_DIMROT__MAX 6139

#define LC_PROP_DIMLIN__MIN 6121
#define LC_PROP_DIMLIN_ANGLE 6121 // RW float; rotation angle
#define LC_PROP_DIMLIN_DP1X 6122  // RW float; def point 1
#define LC_PROP_DIMLIN_DP1Y 6123  // RW float;
#define LC_PROP_DIMLIN_DP2X 6124  // RW float; def point 2
#define LC_PROP_DIMLIN_DP2Y 6125  // RW float;
#define LC_PROP_DIMLIN_TPX 6126   // RW float; text point
#define LC_PROP_DIMLIN_TPY 6127   // RW float;
#define LC_PROP_DIMLIN__MAX 6139

// Leader
#define LC_PROP_LEADER_STYLE \
  6202                           // RW handle|string; Handle to dim style|Name of dim style
#define LC_PROP_LEADER_TEXT 6203 // RW string;
#define LC_PROP_LEADER_ALIGN \
  6204                             // RW int; text alignment (LC_LEADER_TLEFT and other)
#define LC_PROP_LEADER_TPX 6205    // RW float; text center X
#define LC_PROP_LEADER_TPY 6206    // RW float; text center Y
#define LC_PROP_LEADER_APX 6207    // RW float; arrow endpoint X
#define LC_PROP_LEADER_APY 6208    // RW float; arrow endpoint Y
#define LC_PROP_LEADER_P1X 6209    // R  float; land point X
#define LC_PROP_LEADER_P1Y 6210    // R  float; land point Y
#define LC_PROP_LEADER_P0X 6211    // R  float; start point X
#define LC_PROP_LEADER_P0Y 6212    // R  float; start point Y
#define LC_PROP_LEADER_LDIST 6213  // RW float; landing distance
#define LC_PROP_LEADER_VERT 6214   // RW bool; vertical line
#define LC_PROP_LEADER_CORNER 6215 // RW bool; attachment at corner
#define LC_PROP_LEADER_TBW 6216    // R  float; text box width
#define LC_PROP_LEADER_TBH 6217    // R  float; text box height

// 3D face
#define LC_PROP_FACE_X0 6281    // RW float; 1st point X
#define LC_PROP_FACE_Y0 6282    // RW float; 1st point Y
#define LC_PROP_FACE_Z0 6283    // RW float; 1st point Z
#define LC_PROP_FACE_X1 6284    // RW float; 2nd point X
#define LC_PROP_FACE_Y1 6285    // RW float; 2nd point Y
#define LC_PROP_FACE_Z1 6286    // RW float; 2nd point Z
#define LC_PROP_FACE_X2 6287    // RW float; 3rd point X
#define LC_PROP_FACE_Y2 6288    // RW float; 3rd point Y
#define LC_PROP_FACE_Z2 6289    // RW float; 3rd point Z
#define LC_PROP_FACE_X3 6290    // RW float; 4th point X
#define LC_PROP_FACE_Y3 6291    // RW float; 4th point Y
#define LC_PROP_FACE_Z3 6292    // RW float; 4th point Z
#define LC_PROP_FACE_EDGE1 6293 // RW bool; 1st edge visibility
#define LC_PROP_FACE_EDGE2 6294 // RW bool; 2nd edge visibility
#define LC_PROP_FACE_EDGE3 6295 // RW bool; 3rd edge visibility
#define LC_PROP_FACE_EDGE4 6296 // RW bool; 4th edge visibility
#define LC_PROP_FACE_EDGE \
  6297                         // RW int; A combination of LC_FACE_EDGE1INVIS ... constants
#define LC_PROP_FACE_NPTS 6298 // RW int; Number of points, 3 or 4

// Road Plan
#define LC_PROP_RPLAN_LEN 6301      // R  float;
#define LC_PROP_RPLAN_MARKARC 6302  // RW bool;
#define LC_PROP_RPLAN_MARKSIZE 6303 // RW float;
#define LC_PROP_RPLAN_NVERS 6311    // R  int;
#define LC_PROP_RPLAN_IVER 6312     // RW int;

// Shape
#define LC_PROP_SHAPE_NENTS 6341  // R  int; Number of entities
#define LC_PROP_SHAPE_NPATHS 6342 // R  int; Number of paths

// Triangulated Irregular Network (TIN) (also lcTIN_AddPoint and others)
#define LC_PROP_TIN_NAME 7001      // RW string; model name
#define LC_PROP_TIN_DESCR 7002     // RW string; comment
#define LC_PROP_TIN_FILENAME 7003  // R  string; model filename
#define LC_PROP_TIN_NPTYPES 7004   // R  int
#define LC_PROP_TIN_NPOINTS 7005   // R  int
#define LC_PROP_TIN_NTRIANS 7006   // R  int
#define LC_PROP_TIN_NBNDPTS 7007   // R  int; number of boundary points
#define LC_PROP_TIN_NISOLINES 7008 // R  int; number of isolines
#define LC_PROP_TIN_HASCFILL 7009  // R  bool; has color filling
#define LC_PROP_TIN_PNTIMGDIR 7010 // RW string; directory of points images

#define LC_PROP_TIN_XMIN 7020      // R  float; Xmin
#define LC_PROP_TIN_XMAX 7021      // R  float; Xmax
#define LC_PROP_TIN_YMIN 7022      // R  float; Ymin
#define LC_PROP_TIN_YMAX 7023      // R  float; Ymax
#define LC_PROP_TIN_ZMIN 7024      // R  float; Zmin
#define LC_PROP_TIN_ZMAX 7025      // R  float; Zmax
#define LC_PROP_TIN_DX 7026        // R  float; delta X
#define LC_PROP_TIN_DY 7027        // R  float; delta Y
#define LC_PROP_TIN_DZ 7028        // R  float; delta Z
#define LC_PROP_TIN_ISOBASE 7031   // RW float; isolines Z base
#define LC_PROP_TIN_ISOSTEP 7032   // RW float; isolines Z step
#define LC_PROP_TIN_ISOBOLD 7033   // RW int; isolines bold step
#define LC_PROP_TIN_ISOSPLINE 7034 // RW bool; spline isolines
#define LC_PROP_TIN_IMG_ZSTEP 7041 // RW float; Color Filling: Z step
#define LC_PROP_TIN_IMG_PSIZE 7043 // RW float; Color Filling: pixel size
#define LC_PROP_TIN_IMG_NX 7044    // R int; Color Filling: image width (pixels)
#define LC_PROP_TIN_IMG_NY 7045    // R int; Color Filling: image height (pixels)

#define LC_PROP_TIN_VIEWPT 7051   // RW bool; point
#define LC_PROP_TIN_VIEWPTN 7052  // RW bool; point type name
#define LC_PROP_TIN_VIEWPTI 7053  // RW bool; point index
#define LC_PROP_TIN_VIEWPTZ 7054  // RW bool; point Z
#define LC_PROP_TIN_VIEWTR 7055   // RW bool; triangle
#define LC_PROP_TIN_VIEWCF 7056   // RW bool; color filling
#define LC_PROP_TIN_VIEWTRI 7058  // RW bool; triangle's index
#define LC_PROP_TIN_VIEWTRV 7059  // RW bool; triangle's waterflow vector
#define LC_PROP_TIN_VIEWBND 7060  // RW bool; boundary
#define LC_PROP_TIN_VIEWBNDI 7061 // RW bool; boundary vertex index
#define LC_PROP_TIN_VIEWISO 7062  // RW bool; isolines
#define LC_PROP_TIN_VIEWISOH 7063 // RW bool; heights of isolines
#define LC_PROP_TIN_VIEWZ 7065    // RW bool; display Z near cursor
#define LC_PROP_VIEWTINTILES 7066 // RW bool; tiles
#define LC_PROP_VIEWTINCFIR 7067  // RW bool; color filling image rectangles

#define LC_PROP_TIN_COLTR 7071   // RW int; color of triangle outline
#define LC_PROP_TIN_COLTRI 7072  // RW int; color of triangle index
#define LC_PROP_TIN_COLTRV 7073  // RW int; color of triangle norm. vector
#define LC_PROP_TIN_COLISO 7074  // RW int; color of isolines
#define LC_PROP_TIN_COLISOB 7075 // RW int; color of bold isolines
#define LC_PROP_TIN_COLISOW 7076 // RW int; color of water isolines
#define LC_PROP_TIN_COLBND 7077  // RW int; color of boundary
#define LC_PROP_TIN_COLBNDP 7078 // RW int; color of boundary point
#define LC_PROP_TIN_COLTRF \
  7079 // RW int; color of triangle filling (used in step triangulation)
#define LC_PROP_TIN_COLFRONT0 \
  7080 // RW int; color of start front line (used in step triangulation)
#define LC_PROP_TIN_COLFRONT \
  7081 // RW int; color of front line (used in step triangulation)

#define LC_PROP_TIN_LX_PRJNAME 7091 // RW string; LandXML project name
#define LC_PROP_TIN_LX_APPNAME 7092 // RW string; LandXML application name
#define LC_PROP_TIN_LX_DESCR 7093   // RW string; LandXML description
#define LC_PROP_TIN_LX_MANUF 7094   // RW string; LandXML manufacturer
#define LC_PROP_TIN_LX_VER 7095     // RW string; LandXML version
#define LC_PROP_TIN_LX_URL 7096     // RW string; LandXML URL
#define LC_PROP_TIN_LX_TIME 7097    // RW string; LandXML time
#define LC_PROP_ENT__MAX 9999       // from LC_PROP_ENT__MIN 5001
// also see LC_PROP_TINPTYPE_NAME and others

// Polyline Vertex
#define LC_PROP_VER__MIN 10001
#define LC_PROP_VER_X 10001 // RW float; Coordinate X~
#define LC_PROP_VER_Y 10002 // RW float; Coordinate Y~
#define LC_PROP_VER_Z 10003 // RW float; Coordinate Y~
#define LC_PROP_VER_FIX \
  10006                          // RW bool; "Fixed vertex" flag (for LC_PLFIT_LINQUAD).
#define LC_PROP_VER_RADIUS 10007 // RW float; Radius value~
#define LC_PROP_VER_WEIGHT 10008 // RW float; point weight
#define LC_PROP_VER_INDEX 10009  // R  int; index of the vertex
#define LC_PROP_VER_FIRST 10010  // R  bool; TRUE if first vertex
#define LC_PROP_VER_LAST 10011   // R  bool; TRUE if last vertex
// for segment from current to next vertex
#define LC_PROP_VER_W0 10012        // RW float; Start width
#define LC_PROP_VER_W1 10013        // RW float; End width
#define LC_PROP_VER_SEGDX 10014     // RW float; dx
#define LC_PROP_VER_SEGDY 10015     // RW float; dy
#define LC_PROP_VER_SEGANG 10016    // RW float; angle
#define LC_PROP_VER_SEGLEN 10017    // RW float; length
#define LC_PROP_VER_BULGE 10021     // RW float; Bulge value
#define LC_PROP_VER_SEGARCANG 10022 // RW float; included angle of arc segment
#define LC_PROP_VER_SEGARCH 10023   // RW float; height of arc segment
#define LC_PROP_VER_SEGARCLEN 10024 // R  float; length of arc segment
#define LC_PROP_VER_SEGARCRAD 10025 // R  float; radius of arc segment
#define LC_PROP_VER__MAX 10040

// RoadPlan Vertex
#define LC_PROP_RPVER__MIN 10041
#define LC_PROP_RPVER_X 10041      // R  float;
#define LC_PROP_RPVER_Y 10042      // R  float;
#define LC_PROP_RPVER_ANGLE 10043  // R  float;
#define LC_PROP_RPVER_DIRANG 10044 // R  float;
#define LC_PROP_RPVER_R 10045      // R  float;
#define LC_PROP_RPVER_L1 10046     // R  float;
#define LC_PROP_RPVER_L2 10047     // R  float;
#define LC_PROP_RPVER_ANGL1 10048  // R  float;
#define LC_PROP_RPVER_ANGARC 10049 // R  float;
#define LC_PROP_RPVER_ANGL2 10050  // R  float;
#define LC_PROP_RPVER_BISEC 10051  // R  float;
#define LC_PROP_RPVER_DOMER 10052  // R  float;
#define LC_PROP_RPVER_ARCLEN 10053 // R  float;
#define LC_PROP_RPVER_CURLEN 10054 // R  float;
#define LC_PROP_RPVER_LINE1 10055  // R  float;
#define LC_PROP_RPVER_T1 10056     // R  float;
#define LC_PROP_RPVER_T2 10057     // R  float;
#define LC_PROP_RPVER_LINE2 10058  // R  float;
#define LC_PROP_RPVER_DIST1 10059  // R  float;
#define LC_PROP_RPVER_DIST2 10060  // R  float;
#define LC_PROP_RPVER__MAX 10070

#define LC_PROP_XDATA__MIN 10901
#define LC_PROP_XDATA_BOOL 10901  // RW bool;
#define LC_PROP_XDATA_INT 10902   // RW int;
#define LC_PROP_XDATA_FLOAT 10903 // RW float;
#define LC_PROP_XDATA_STR 10907   // RW string;
#define LC_PROP_XDATA__MAX 10910

// Other
#define LC_PROP_OTHER__MIN 11001
#define LC_PROP_CMDWND_ENABLE 11001  // RW bool; Command window is enabled
#define LC_PROP_PROPWND_ENABLE 11002 // RW bool; Properties window is enabled
#define LC_PROP_PROPWND_DIVCOEF \
  11003 // RW float; ratio of the name/value columns widths
#define LC_PROP_OTHER__MAX 11999

// event parameters
#define LC_PROP_EVENT__MIN 12001
#define LC_PROP_EVENT_TYPE 12001    // R  int; event type LC_EVENT_HELP and others
#define LC_PROP_EVENT_APPPRM1 12002 // R  int;    application parameter1
#define LC_PROP_EVENT_APPPRM2 12003 // R  handle; application parameter2
#define LC_PROP_EVENT_WND 12004     // R  handle; Window
#define LC_PROP_EVENT_DRW 12005     // R  handle; Drawing
#define LC_PROP_EVENT_BLOCK 12006   // R  handle; Visible block
#define LC_PROP_EVENT_ENTITY 12007  // R  handle; entity's handle
#define LC_PROP_EVENT_ENT 12007     //    LC_PROP_EVENT_ENTITY
#define LC_PROP_EVENT_HCMD 12008    // R  handle; custom command object
#define LC_PROP_EVENT_HOBJ 12008    //    LC_PROP_EVENT_HCMD
#define LC_PROP_EVENT_HDC \
  12009                            // R  handle; device context (for LC_EVENT_PAINT)
#define LC_PROP_EVENT_MODE 12010   // RW int;
#define LC_PROP_EVENT_INT1 12021   // RW int;
#define LC_PROP_EVENT_INT2 12022   // RW int;
#define LC_PROP_EVENT_INT3 12023   // RW int;
#define LC_PROP_EVENT_INT4 12024   // RW int;
#define LC_PROP_EVENT_INT5 12025   // RW int;
#define LC_PROP_EVENT_INT6 12026   // RW int;
#define LC_PROP_EVENT_FLOAT1 12031 // RW float;
#define LC_PROP_EVENT_FLOAT2 12032 // RW float;
#define LC_PROP_EVENT_FLOAT3 12033 // RW float;
#define LC_PROP_EVENT_FLOAT4 12034 // RW float;
#define LC_PROP_EVENT_FLOAT5 12035 // RW float;
#define LC_PROP_EVENT_FLOAT6 12036 // RW float;
#define LC_PROP_EVENT_STR1 12041   // RW string;
#define LC_PROP_EVENT_STR2 12042   // RW string;
#define LC_PROP_EVENT_STR3 12043   // RW string;
#define LC_PROP_EVENT__MAX 12999

// events
#define LC_EVENT_HELP 101
#define LC_EVENT_PAINT 102
#define LC_EVENT_PAINTBG 124
#define LC_EVENT_WNDVIEW 103
#define LC_EVENT_MOUSEMOVE 105
#define LC_EVENT_LBDOWN 106
#define LC_EVENT_LBUP 107
#define LC_EVENT_LBDBLCLK 108
#define LC_EVENT_RBDOWN 109
#define LC_EVENT_RBUP 110
#define LC_EVENT_KEYDOWN 111
#define LC_EVENT_VIEWBLOCK 112
#define LC_EVENT_EXTENTS 113
#define LC_EVENT_SNAP 114
#define LC_EVENT_MAGNIFIER 115
#define LC_EVENT_NAVIGATOR 116
#define LC_EVENT_CMDINWND 117
#define LC_EVENT_GRID 118
#define LC_EVENT_OSNAP 119
#define LC_EVENT_PTRACK 120
#define LC_EVENT_ORTHO 121
#define LC_EVENT_FILETAB 122
#define LC_EVENT_WAITPOINT 123

#define LC_EVENT_FILE 131
#define LC_EVENT_ADDENTITY 132
#define LC_EVENT_WNDPROP 133
#define LC_EVENT_DRWPROP 134
#define LC_EVENT_ENTPROP 135
#define LC_EVENT_ENTMOVE 136
#define LC_EVENT_ENTSCALE 137
#define LC_EVENT_ENTROTATE 138
#define LC_EVENT_ENTMIRROR 139
#define LC_EVENT_ENTERASE 140
#define LC_EVENT_DRAWIMAGE 141
#define LC_EVENT_SELECT 145
#define LC_EVENT_PICKENT 146
#define LC_EVENT_ADDSTR 147
#define LC_EVENT_ADDCMD 148
#define LC_EVENT_CCMD 149
#define LC_EVENT_TIN 150
#define LC_EVENT_DRWFILEEXT 151
#define LC_EVENT_DRWPREVIEW 152
#define LC_EVENT_DRWLOAD 153
#define LC_EVENT_DRWSAVE 154
#define LC_EVENT_GRIPMOVE 155
#define LC_EVENT_GRIPDRAG 156
#define LC_EVENT_DIRTY 157   // undoc
#define LC_EVENT_SELENT1 161 // undoc
#define LC_EVENT_SELENTS 162 // undoc
#define LC_EVENT_GRIPPAINT 165
#define LC_EVENT_DRAWCURSOR 166
#define LC_EVENT_RULERCORNER 167
#define LC_EVENT_WNDTAB 171
#define LC_EVENT_CMD1 212   // undoc
#define LC_EVENT_LAYERS 303 // undoc

// parameter LC_PROP_EVENT_MODE of LC_EVENT_CCMD
#define LC_CCMD_CREATE 1
#define LC_CCMD_DESTROY 2
#define LC_CCMD_START 3
#define LC_CCMD_FINISH 4
#define LC_CCMD_LBDOWN 5
#define LC_CCMD_LBUP 6
#define LC_CCMD_RBDOWN 7
#define LC_CCMD_RBUP 8
#define LC_CCMD_MOUSEMOVE 9
#define LC_CCMD_PAINT 10
#define LC_CCMD_SNAP 11

// *****************************************************************************
// *****************************************************************************
//
//                        LITECAD FUNCTIONS
//
// *****************************************************************************
// *****************************************************************************
#define LCAPI __cdecl
typedef void (*F_LCEVENT)(void *hEvent);
typedef void (*F_WAITPOINT)(int FuncPrm, void *hLcWnd);
typedef void (*F_REDRAW)(void *hLcWnd, int Elapsed);
// typedef void (CALLBACK* F_EXP) (int Mode, void *hEntity, int nPaths, int
// iPath, int nPnts, int iPnt, double X, double Y);

void LCAPI lcEventSetProc(int EventType, F_LCEVENT pFunc, int Prm1, void *Prm2);
void LCAPI lcEventReturnCode(int code);
int LCAPI lcEventsEnable(int b);

// Initialization
int LCAPI lcInitialize();
int LCAPI lcUninitialize(int bSaveConfig);

// GUI strings
int LCAPI lcStrAdd(char *szTag, char *szText);
int LCAPI lcStrSet(char *szTag, char *szText);
char *LCAPI lcStrGet(char *szTag);
int LCAPI lcStrFileLoad(char *szFileName);
int LCAPI lcStrFileSave(char *szFileName, char *szLanguage);

// Objects properties
int LCAPI lcPropGetBool(void *hObject, int idProp);
int LCAPI lcPropGetInt(void *hObject, int idProp);
double LCAPI lcPropGetFloat(void *hObject, int idProp);
char *LCAPI lcPropGetStr(void *hObject, int idProp);
int LCAPI lcPropGetStrA(void *hObject, int idProp, char *szBuf, int BufSize);
int LCAPI lcPropGetStr2(void *hObject, int idProp);
int LCAPI lcPropGetChar(int iChar);
void *LCAPI lcPropGetHandle(void *hObject, int idProp);
int LCAPI lcPropPutBool(void *hObject, int idProp, int bValue);
int LCAPI lcPropPutInt(void *hObject, int idProp, int Value);
int LCAPI lcPropPutFloat(void *hObject, int idProp, double Value);
int LCAPI lcPropPutStr(void *hObject, int idProp, char *szValue);
int LCAPI lcPropPutHandle(void *hObject, int idProp, void *hValue);

// Design window
void *LCAPI lcCreateWindow(void *hWndParent, int Style);
int LCAPI lcDeleteWindow(void *hLcWnd);
int LCAPI lcWndOnClose(void *hLcWnd);
int LCAPI lcWndExeCommand(void *hLcWnd, int Command, int CmdParam);
int LCAPI lcWndExitCommand(void *hLcWnd);
int LCAPI lcWndResize(void *hLcWnd, int Left, int Top, int Width, int Height);
int LCAPI lcWndRedraw(void *hLcWnd);
int LCAPI lcWndRedrawAuto(void *hLcWnd, int Elapse, F_REDRAW pFunc);
int LCAPI lcWndSetFocus(void *hLcWnd);
int LCAPI lcWndSetExtents(void *hLcWnd, double Xmin, double Ymin, double Xmax,
                          double Ymax);
int LCAPI lcWndSetBlock(void *hLcWnd, void *hBlock);
int LCAPI lcWndSetProps(void *hLcWnd, void *hPropWnd);
int LCAPI lcWndSetCmdwin(void *hLcWnd, void *hCmdLine);
int LCAPI lcWndSetBasePoint(void *hLcWnd, int bState, double X, double Y);
int LCAPI lcWndEmulator(void *hLcWnd, int Mode);
int LCAPI lcWndMagnifier(void *hLcWnd, int bOn, int Width, int Height, int Zoom,
                         int Flags);
int LCAPI lcWndHoverText(void *hLcWnd, char *szText, int X, int Y, int Align);
int LCAPI lcWndMessage(void *hLcWnd, char *szText, int uType);
int LCAPI lcWndWaitPoint(void *hLcWnd, char *szText, double *pXdrw,
                         double *pYdrw);
int LCAPI lcWndWaitPoint2(void *hLcWnd, char *szText, double *pXdrw,
                          double *pYdrw, F_WAITPOINT pFunc, int FuncPrm);
int LCAPI lcWndInputStr(void *hLcWnd);
int LCAPI lcWndUpdate(void *hLcWnd, int Mode);
void *LCAPI lcWndDrwAdd(void *hLcWnd, char *szFileName);
int LCAPI lcWndDrwDelete(void *hLcWnd, void *hLcDrw);
void *LCAPI lcWndDrwGet(void *hLcWnd, int Index);
// zoom
int LCAPI lcWndZoomRect(void *hLcWnd, double Left, double Bottom, double Right,
                        double Top);
int LCAPI lcWndZoomScale(void *hLcWnd, double Scal);
int LCAPI lcWndZoomMove(void *hLcWnd, double DX, double DY);
int LCAPI lcWndZoomPos(void *hLcWnd, double Xc, double Yc, double PixSize);
int LCAPI lcWndZoomEnt(void *hLcWnd, void *hEnt, double Scal);
// coordinates
int LCAPI lcWndGetCursorCoord(void *hLcWnd, int *pXwin, int *pYwin,
                              double *pXdrw, double *pYdrw);
int LCAPI lcCoordDrwToWnd(void *hLcWnd, double Xdrw, double Ydrw, int *pXwnd,
                          int *pYwnd);
int LCAPI lcCoordWndToDrw(void *hLcWnd, int Xwnd, int Ywnd, double *pXdrw,
                          double *pYdrw);
int LCAPI lcWndCoordFromDrw(void *hLcWnd, double Xdrw, double Ydrw, int *pXwin,
                            int *pYwin);
int LCAPI lcWndCoordToDrw(void *hLcWnd, int Xwin, int Ywin, double *pXdrw,
                          double *pYdrw);

// retrieve entities
void *LCAPI lcWndGetEntByPoint(void *hLcWnd, int Xwin, int Ywin);
void *LCAPI lcWndGetEntByPoint2(void *hLcWnd, double X, double Y, double Delta);
int LCAPI lcWndGetEntsByPoint(void *hLcWnd, int Xwin, int Ywin, int nMaxEnts);
int LCAPI lcWndGetEntsByRect(void *hLcWnd, double Lef, double Bot, double Rig,
                             double Top, int bCross, int nMaxEnts);
void *LCAPI lcWndGetEntity(int iEnt);
void *LCAPI lcWndGetEntByID(void *hLcWnd, int Id);
void *LCAPI lcWndGetEntByIDH(void *hLcWnd, char *szId);
void *LCAPI lcWndGetEntByKey(void *hLcWnd, int Key);
int LCAPI lcWndPickEnt(void *hLcWnd, char *szTitle, char *szCursorText);

// Font functions
void *LCAPI lcFontGetFirst();
void *LCAPI lcFontGetNext(void *hFont);
void *LCAPI lcFontAddRes(char *szFontName, void *hModule, int idResource);
void *LCAPI lcFontAddFile(char *szFontName, char *szFilename,
                          char *szOutFontName);
void *LCAPI lcFontAddBin(char *szFontName, void *hData);
void *LCAPI lcFontGetChar(void *hFont, int CharCode);
char *LCAPI lcFontGetName(char *szFilename);

// Progress indicator
int LCAPI lcProgressCreate(void *hLcWnd, int W, int H, char *szTitle);
int LCAPI lcProgressSetText(char *szText);
int LCAPI lcProgressStart(int MinVal, int MaxVal);
int LCAPI lcProgressSetPos(int Val);
int LCAPI lcProgressInc();
int LCAPI lcProgressDelete();

// Quadrangle point coordinates
void *LCAPI lcQuadCreate();
int LCAPI lcQuadDelete(void *hQuad);
int LCAPI lcQuadSet(void *hQuad, double x0, double y0, double x1, double y1,
                    double x2, double y2, double x3, double y3);
int LCAPI lcQuadTransXYtoUV(void *hQuad, double X, double Y, double *pU,
                            double *pV);
int LCAPI lcQuadTransUVtoXY(void *hQuad, double U, double V, double *pX,
                            double *pY);
int LCAPI lcQuadContains(void *hQuad, double X, double Y);

// Array of Quadrangles
void *LCAPI lcGridCreate();
int LCAPI lcGridDelete(void *hGrid);
int LCAPI lcGridSet(void *hGrid, double X0, double Y0, double W, double H,
                    int Nx, int Ny);
int LCAPI lcGridSetDest(void *hGrid, int Ix, int Iy, double X, double Y);
int LCAPI lcGridUpdate(void *hGrid);
int LCAPI lcGridTrans(void *hGrid, double X, double Y, double *pXdest,
                      double *pYdest);
int LCAPI lcGridGetNode(void *hGrid, int bDest, int Ix, int Iy, double *pX,
                        double *pY);
int LCAPI lcGridGetCell(void *hGrid, double X, double Y, int *pIx, int *pIy);
int LCAPI
lcGridSetView(void *hGrid, int Mode, void *hLcWnd, int ColLine,
              int ColNode); // Mode: 0-disable, 1-original, 2-destination

// Command Window
void *LCAPI lcCreateCmdwin(void *hWndParent, int Left, int Top, int Width,
                           int Height);
int LCAPI lcCmdwinResize(void *hCmdLine, int Left, int Top, int Width,
                         int Height);
int LCAPI lcCmdwinUpdate(void *hCmdLine); // undoc

// Properties Window
void *LCAPI lcCreateProps(void *hWndParent, int Mode);
int LCAPI lcDeleteProps(void *hPropWnd);
int LCAPI lcPropsResize(void *hPropWnd, int Left, int Top, int Width,
                        int Height);
int LCAPI lcPropsUpdate(void *hPropWnd, int bSelChanged);

// Status Bar
void *LCAPI lcCreateStatbar(void *hWndParent); // also LC_PROP_SBAR_H and others
int LCAPI lcDeleteStatbar(void *hStatbar);
int LCAPI lcStatbarResize(void *hStatbar, int Left, int Top, int Width,
                          int Height);
int LCAPI lcStatbarCell(void *hStatbar, int Id, int Pos);
int LCAPI lcStatbarText(void *hStatbar, int Id, char *szText);
int LCAPI lcStatbarRedraw(void *hStatbar);

// utility functions
int LCAPI lcDgGetValue(void *hWnd, int Lef, int Top, char *szTitle,
                       char *szPrompt);
int LCAPI lcHelp(char *szTopic);
void LCAPI lcGetPolarPoint(double x0, double y0, double Angle, double Dist,
                           double *pOutX, double *pOutY);
void LCAPI lcGetPolarPrm(double x1, double y1, double x2, double y2,
                         double *pAngle, double *pDist);
int LCAPI lcGetClientSize(void *hWnd, int *pWidth, int *pHeight);
int LCAPI lcGetErrorCode();
char *LCAPI lcGetErrorStr();
int LCAPI lcGetStr(int Mode);
int LCAPI lcGetDrwXData(char *szFileName);
int LCAPI lcGetDrwPreview(char *szFileName, unsigned char *pOutDIB);
int LCAPI lcFilletSetLines(double L1x0, double L1y0, double L1x1, double L1y1,
                           double L2x0, double L2y0, double L2x1, double L2y1);
int LCAPI lcFillet(double Rad, double Bis, double Tang);
int LCAPI lcFilletGetPoint(int iPnt, double *pX, double *pY);
int LCAPI lcFileToStrA(char *szFileName, char *pBuf);

// Custom command interface
void *LCAPI lcCreateCommand(void *hLcWnd, int Id, char *szTitle);
int LCAPI lcCmdExit(void *hCmd);
int LCAPI lcCmdCursorText(void *hCmd, char *szText);
int LCAPI lcCmdMessage(void *hCmd, char *szText, int uType);
int LCAPI lcCmdResetLastPt(void *hCmd);

int LCAPI lcTIS_InitLibrary(char *szLicenseKey, int bErrMsg);
int LCAPI lcTIS_CloseLibrary();
int LCAPI lcCameraConnect(char *szName); // LC_PROP_G_CAMERA_COUNT
int LCAPI lcCameraDisconnect();
int LCAPI lcCameraShot();

//-----------------------------------------------------------------------------
// Drawing
//-----------------------------------------------------------------------------
void *LCAPI lcCreateDrawing();
int LCAPI lcDeleteDrawing(void *hDrw);
int LCAPI lcDrwNew(void *hDrw, char *szFileName, void *hLcWnd);
int LCAPI lcDrwLoad(void *hDrw, char *szFileName, void *hLcWnd);
int LCAPI lcDrwLoadMem(void *hDrw, void *hMem, void *hLcWnd);
int LCAPI lcDxfLoadMem(void *hDrw, void *hMem, void *hLcWnd);
void *LCAPI lcDrwLoadTIN(void *hDrw, char *szFileName, void *hLcWnd);
int LCAPI lcDrwSaveTIN(void *hDrw, void *hLcWnd);
int LCAPI lcDrwInsert(void *hDrw, char *szFileName, int Overwrite,
                      void *hLcWnd);
int LCAPI lcDrwInsertSHP(void *hDrw, void *hLayer, char *szFileName,
                         void *hLcWnd);
int LCAPI lcDrwCopy(void *hDrw, void *hDrwSrc);
int LCAPI lcDrwSave(void *hDrw, char *szFileName, int bBak, void *hLcWnd);
int LCAPI lcDrwSaveMem(void *hDrw, void *hMem, int MemSize);

void *LCAPI lcDrwAddLayer(void *hDrw, char *szName, char *szColor, void *hLtype,
                          int Lwidth);
void *LCAPI lcDrwAddLayer2(void *hDrw, char *szName, void *hFromLayer);
void *LCAPI lcDrwAddLinetype(void *hDrw, char *szName, char *szDefinition);
void *LCAPI lcDrwAddLinetypeF(void *hDrw, char *szName, char *szFileName,
                              char *szLtypeName);
void *LCAPI lcDrwAddTextStyle(void *hDrw, char *szName, char *szFontName,
                              int bWinFont);
void *LCAPI lcDrwAddDimStyle(void *hDrw, char *szName);
void *LCAPI lcDrwAddMlineStyle(void *hDrw, char *szName);
void *LCAPI lcDrwAddPntStyle(void *hDrw, char *szName, void *hBlock,
                             double BlockScale, void *hTStyle,
                             double TextHeight, double TextWidth);
void *LCAPI lcDrwAddFilling(void *hDrw, char *szName);
void *LCAPI lcDrwAddImage(void *hDrw, char *szName, char *szFileName);
void *LCAPI lcDrwAddImage2(void *hDrw, char *szName, int Width, int Height,
                           int nBits, void *hData, int bTopDown);
void *LCAPI lcDrwAddImage3(void *hDrw, char *szName, void *hMem);
void *LCAPI lcDrwAddImageCam(void *hDrw, char *szName);
void *LCAPI lcDrwAddBlock(void *hDrw, char *szName, double X, double Y);
void *LCAPI lcDrwAddBlockFromFile(void *hDrw, char *szName, char *szFileName,
                                  int Overwrite, void *hwParent);
void *LCAPI lcDrwAddBlockFromDrw(void *hDrw, char *szName, void *hDrw2,
                                 int Overwrite, void *hwParent);
void *LCAPI lcDrwAddBlockFile(void *hDrw, char *szName, char *szFileName,
                              int Overwrite, void *hwParent);
void *LCAPI lcDrwAddBlockPaper(void *hDrw, char *szName, int PaperSize,
                               int Orient, double Width, double Height);
void *LCAPI lcDrwAddBlockCopy(void *hDrw, char *szName, void *hSrcBlock);

int LCAPI lcDrwDeleteObject(void *hDrw, void *hObject);
int LCAPI lcDrwDeleteUnused(void *hDrw, int ObjType); // undoc
int LCAPI lcDrwCountObjects(void *hDrw, int ObjType);
int LCAPI lcDrwSortObjects(void *hDrw, int ObjType);
int LCAPI lcDrwUpdateWinFonts(void *hDrw, void *hTStyle);
int LCAPI lcDrwUpdateBlkRefs(void *hDrw, void *hBlock);
int LCAPI lcDrwUpdateTexts(void *hDrw, void *hTStyle);

void *LCAPI lcDrwGetFirstObject(void *hDrw, int ObjType);
void *LCAPI lcDrwGetNextObject(void *hDrw, void *hObject);
void *LCAPI lcDrwGetObjectByID(void *hDrw, int ObjType, int Id);
void *LCAPI lcDrwGetObjectByIDH(void *hDrw, int ObjType, char *szId);
void *LCAPI lcDrwGetObjectByName(void *hDrw, int ObjType, char *szName);
void *LCAPI lcDrwGetEntByID(void *hDrw, int Id);
void *LCAPI lcDrwGetEntByIDH(void *hDrw, char *szId);
void *LCAPI lcDrwGetEntByKey(void *hDrw, int Key);

int LCAPI lcDrwClearXData(void *hDrw, int ObjType, int Mode);
int LCAPI lcDrwPurge(void *hDrw);
int LCAPI lcDrwExplode(void *hDrw, int Mode);
int LCAPI lcDrwSetLimits(void *hDrw, double Xmin, double Ymin, double Xmax,
                         double Ymax);

int LCAPI lcDrwUndoRecord(void *hDrw, int Mode);
int LCAPI lcDrwUndo(void *hDrw, int bRedo);

// Clipping rectangles (also LC_PROP_CRECT_ID and others)
int LCAPI lcCRectsClear(void *hDrw);
int LCAPI lcCRectsAdd(void *hDrw, int ID, double Lef, double Bot, double Width,
                      double Height);
int LCAPI lcCRectsDivide(void *hDrw, int NumX, int NumY, int bClearExist);
void *LCAPI lcCRectsGetFirst(void *hDrw);
void *LCAPI lcCRectsGetNext(void *hDrw, void *hCRect);
void *LCAPI lcCRectsGetWithID(void *hDrw, int Id);
int LCAPI lcCRectsActive(void *hDrw, void *hCRect);
void *LCAPI lcCRectsGetActive(void *hDrw);
int LCAPI lcCRectsDelete(void *hDrw, void *hCRect);
int LCAPI lcCRectsSave(void *hDrw, void *hCRect, char *szFileName);
int LCAPI lcCRectsBitmap(void *hDrw, void *hCRect, char *szFileName,
                         double PixelSize);

// Block
int LCAPI lcBlockSetViewRect(void *hBlock, double Xcen, double Ycen,
                             double Width, double Height);
int LCAPI lcBlockSetViewRect2(void *hBlock, double Lef, double Bot, double Rig,
                              double Top);
int LCAPI lcBlockSetPaperSize(void *hBlock, int PaperSize, int Orient,
                              double Width, double Height);
int LCAPI lcBlockRasterize(void *hBlock, char *szFileName, double Xmin,
                           double Ymin, double Xmax, double Ymax, int ImgW,
                           int ImgH);
int LCAPI lcBlockRasterizeMem(void *hBlock, void *hMem, double Xmin,
                              double Ymin, double Xmax, double Ymax, int ImgW,
                              int ImgH);
int LCAPI lcBlockUpdate(void *hBlock, int bUpdEnts, void *hNewEnt);
int LCAPI lcBlockMove(void *hBlock, double dX, double dY, int bUpdate);
int LCAPI lcBlockScale(void *hBlock, double X, double Y, double Scal,
                       int bUpdate);
int LCAPI lcBlockRotate(void *hBlock, double X, double Y, double Angle,
                        int bUpdate);
int LCAPI lcBlockMirror(void *hBlock, double X1, double Y1, double X2,
                        double Y2, int bUpdate);

// Add graphic objects into a block
int LCAPI lcBlockClear(void *hBlock, void *hLayer);
int LCAPI lcBlockPurge(void *hBlock);
int LCAPI lcBlockSortEnts(void *hBlock, int bByLayers, void *hWnd);
int LCAPI lcBlockSortEnts2(void *hBlock, void *idEnts,
                           int nEnts); // for DWG plugin
void *LCAPI lcBlockAddPoint(void *hBlock, double X, double Y);
void *LCAPI lcBlockAddPoint2(void *hBlock, double X, double Y, int PtMode,
                             double PtSize);
void *LCAPI lcBlockAddPoint3d(void *hBlock, double X, double Y, double Z);
int LCAPI lcBlockAddPointsF(void *hBlock, char *szFileName, void *hWnd);
void *LCAPI lcBlockAddXline(void *hBlock, double X, double Y, double Angle,
                            int bRay);
void *LCAPI lcBlockAddXline2P(void *hBlock, double X, double Y, double X2,
                              double Y2, int bRay);
void *LCAPI lcBlockAddLine(void *hBlock, double X1, double Y1, double X2,
                           double Y2);
void *LCAPI lcBlockAddLineDir(void *hBlock, double X, double Y, double Angle,
                              double Dist);
void *LCAPI lcBlockAddLineTan(void *hBlock, void *hEnt1, void *hEnt2, int Mode);
void *LCAPI lcBlockAddPolyline(void *hBlock, int FitType, int bClosed,
                               int bFilled);
void *LCAPI lcBlockAddRPolygon(void *hBlock, int nVers, double Xc, double Yc,
                               double R, double Ang0, int bInscribed,
                               int bFilled);
void *LCAPI lcBlockAddSpline(void *hBlock, int bClosed, int bFilled);
void *LCAPI lcBlockAddBezier(void *hBlock);
void *LCAPI lcBlockAddMline(void *hBlock, int FitType, int bClosed);
void *LCAPI lcBlockAddRect(void *hBlock, double Xc, double Yc, double Width,
                           double Height, double Angle, int bFilled);
void *LCAPI lcBlockAddRect2(void *hBlock, double Left, double Bottom,
                            double Width, double Height, double Rad,
                            int bFilled);
void *LCAPI lcBlockAddCircle(void *hBlock, double X, double Y, double Radius,
                             int bFilled);
void *LCAPI lcBlockAddArc(void *hBlock, double X, double Y, double Radius,
                          double StartAngle, double ArcAngle);
void *LCAPI lcBlockAddArc3P(void *hBlock, double X1, double Y1, double X2,
                            double Y2, double X3, double Y3);
void *LCAPI lcBlockAddFillet(void *hBlock, void *hEnt1, void *hEnt2,
                             double Radius);
void *LCAPI lcBlockAddEllipse(void *hBlock, double X, double Y, double R1,
                              double R2, double RotAngle, double StartAngle,
                              double ArcAngle);
void *LCAPI lcBlockAddText(void *hBlock, char *szText, double X, double Y);
void *LCAPI lcBlockAddText2(void *hBlock, char *szText, double X, double Y,
                            int Align, double H, double WScale, double RotAngle,
                            double Oblique);
void *LCAPI lcBlockAddText3(void *hBlock, char *szText, double X1, double Y1,
                            double X2, double Y2, int Align, double HW,
                            double Oblique);
void *LCAPI lcBlockAddTextWin(void *hBlock, char *szText, double X, double Y);
void *LCAPI lcBlockAddTextWin2(void *hBlock, char *szText, double X, double Y,
                               int Align, double H, double WScale,
                               double RotAngle, double Oblique);
void *LCAPI lcBlockAddMText(void *hBlock, char *szText, double X, double Y,
                            double WrapWidth, int Align, double RotAngle,
                            double H, double WScale);
void *LCAPI lcBlockAddArcText(void *hBlock, char *szText, double X, double Y,
                              double Radius, double StartAngle, int bClockwise,
                              double H, double WScale, int Align);
void *LCAPI lcBlockAddBlockRef(void *hBlock, void *hRefBlock, double X,
                               double Y, double Scal, double Angle);
void *LCAPI lcBlockAddBlockRefID(void *hBlock, int idRefBlock, double X,
                                 double Y, double Scal, double Angle); // undoc
void *LCAPI lcBlockAddBlockRefIDH(void *hBlock, char *szIdRefBlock, double X,
                                  double Y, double Scal, double Angle); // undoc
void *LCAPI lcBlockAddAttDef(void *hBlock, int Mode, char *szTag,
                             char *szPrompt, char *szDefVal, double X, double Y,
                             int Align, double H, double WScale,
                             double RotAngle, double Oblique);
void *LCAPI lcBlockAddXref(void *hBlock, char *szFileName, double X, double Y,
                           double ScalX, double ScalY, double Angle);
void *LCAPI lcBlockAddImageRef(void *hBlock, void *hImage, double X, double Y,
                               double Width, double Height, int bBorder);
void *LCAPI lcBlockAddImageRefUns(void *hBlock, void *hImage, double X,
                                  double Y, double Scal, int Align,
                                  int bBorder);
void *LCAPI lcBlockAddImagePlace(void *hBlock, int Id, double X, double Y,
                                 double Width, double Height, int bBorder);
void *LCAPI lcBlockAddEcw(void *hBlock, char *szFileName);
void *LCAPI lcBlockAddBarcode(void *hBlock, int BarType, double Xc, double Yc,
                              double Width, double Height, char *szText);
void *LCAPI lcBlockAddHatch(void *hBlock, char *szFileName, char *szPatName,
                            double Scal, double Angle);
void *LCAPI lcBlockAddViewport(void *hBlock, double Lef, double Bot,
                               double Width, double Height, double DrwPntX,
                               double DrwPntY, double DrwScale,
                               double DrwAngle);
void *LCAPI lcBlockAddFace(void *hBlock, int Flags, double x0, double y0,
                           double z0, double x1, double y1, double z1,
                           double x2, double y2, double z2);
void *LCAPI lcBlockAddFace4(void *hBlock, int Flags, double x0, double y0,
                            double z0, double x1, double y1, double z1,
                            double x2, double y2, double z2, double x3,
                            double y3, double z3);
void *LCAPI lcBlockAddLeader(void *hBlock, char *szText, double Xt, double Yt,
                             double LandDist, double Xa, double Ya, int Attach,
                             int Align);
void *LCAPI lcBlockAddDimLin(void *hBlock, double X0, double Y0, double X1,
                             double Y1, double Xt, double Yt, double Angle,
                             char *szText);
void *LCAPI lcBlockAddDimHor(void *hBlock, double X0, double Y0, double X1,
                             double Y1, double Yt, char *szText);
void *LCAPI lcBlockAddDimVer(void *hBlock, double X0, double Y0, double X1,
                             double Y1, double Xt, char *szText);
void *LCAPI lcBlockAddDimAli(void *hBlock, double X0, double Y0, double X1,
                             double Y1, double Xt, double Yt, char *szText);
void *LCAPI lcBlockAddDimAli2(void *hBlock, double X0, double Y0, double X1,
                              double Y1, double Dt, char *szText);
void *LCAPI lcBlockAddDimOrd(void *hBlock, double Xd, double Yd, double Xt,
                             double Yt, int bX, char *szText);
void *LCAPI lcBlockAddDimRad(void *hBlock, double Xc, double Yc, double Xr,
                             double Yr, double Xt, double Yt, char *szText);
void *LCAPI lcBlockAddDimRad2(void *hBlock, double Xc, double Yc, double R,
                              double Angle, double TextOff, char *szText);
void *LCAPI lcBlockAddDimDia(void *hBlock, double Xc, double Yc, double Xr,
                             double Yr, double Xt, double Yt, char *szText);
void *LCAPI lcBlockAddDimDia2(void *hBlock, double Xc, double Yc, double R,
                              double Angle, double TextOff, char *szText);
void *LCAPI lcBlockAddDimAng(void *hBlock, double Xc, double Yc, double X1,
                             double Y1, double X2, double Y2, double Xa,
                             double Ya, double TextPos, char *szText);
void *LCAPI lcBlockAddDimAng2(void *hBlock, double X1, double Y1, double X2,
                              double Y2, double X3, double Y3, double X4,
                              double Y4, double Xa, double Ya, double TextPos,
                              char *szText);
void *LCAPI lcBlockAddRPlan(void *hBlock);
void *LCAPI lcBlockAddRPlan2(void *hBlock, void *hStartEnt);
void *LCAPI lcBlockAddArrow(void *hBlock, double X1, double Y1, double X2,
                            double Y2);
void *LCAPI lcBlockAddSpiral(void *hBlock, double Xc, double Yc, double R,
                             double Turns, int bDirCW, int bClosed);
void *LCAPI lcBlockAddCamview(void *hBlock, double Lef, double Bot,
                              double Width, double Height);
void *LCAPI lcBlockAddTIN(void *hBlock, char *szFileName, int FileType);
void *LCAPI lcBlockAddClone(void *hBlock, void *hEnt);
int LCAPI lcBlockBeginShape(void *hBlock);
void *LCAPI lcBlockAddShape(void *hBlock);
void *LCAPI lcBlockAddShapeSel(void *hBlock, int bErase);
void *LCAPI lcBlockRepEllipse(void *hBlock, void *hEll, int *pRetType);
int LCAPI lcBlockJoinAll(void *hBlock, double Delta);
int LCAPI lcBlockCopyLayer(void *hBlock, void *hLayerSrc, void *hLayerDest);
int LCAPI lcBlockDeleteEnt(void *hBlock, void *hEnt);

// Retrieve graphic objects from a block
void *LCAPI lcBlockGetFirstEnt(void *hBlock);
void *LCAPI lcBlockGetNextEnt(void *hBlock, void *hEnt);
void *LCAPI lcBlockGetLastEnt(void *hBlock);
void *LCAPI lcBlockGetPrevEnt(void *hBlock, void *hEnt);
void *LCAPI lcBlockGetEntByID(void *hBlock, int Id);
void *LCAPI lcBlockGetEntByIDH(void *hBlock, char *szId);
void *LCAPI lcBlockGetEntByKey(void *hBlock, int Key);
void *LCAPI lcBlockGetBlkRefByTag(void *hBlock, void *hBlockAtt, char *szTag,
                                  char *szValue, int bSelect);
void *LCAPI lcBlockGetTIN(void *hBlock, char *szName);

// Selection
int LCAPI lcBlockUnselect(void *hBlock);
int LCAPI lcBlockSelectEnt(void *hBlock, void *hEntity, int bSelect);
int LCAPI lcBlockSelErase(void *hBlock);
int LCAPI lcBlockSelMove(void *hBlock, double dX, double dY, int bCopy,
                         int bNewSelect);
int LCAPI lcBlockSelScale(void *hBlock, double X0, double Y0, double Scal,
                          int bCopy, int bNewSelect);
int LCAPI lcBlockSelRotate(void *hBlock, double X0, double Y0, double Angle,
                           int bCopy, int bNewSelect);
int LCAPI lcBlockSelMirror(void *hBlock, double X1, double Y1, double X2,
                           double Y2, int bCopy, int bNewSelect);
int LCAPI lcBlockSelExplode(void *hBlock);
int LCAPI lcBlockSelSplit(void *hBlock, int nParts);
void *LCAPI lcBlockSelJoin(void *hBlock, double Delta);
int LCAPI lcBlockSelAlign(void *hBlock, int Mode, double X, double Y);
void *LCAPI lcBlockSelBlock(void *hBlock, char *szName, double X, double Y,
                            int Mode, int bOverwrite);
void *LCAPI lcBlockGetFirstSel(void *hBlock);
void *LCAPI lcBlockGetNextSel(void *hBlock);

// change entities order by layer
int LCAPI lcBlockOrderByLayers(void *hBlock, void *hWnd);
int LCAPI lcBlockSortTSP(void *hBlock, void *hLayer, void *hWnd);
double LCAPI lcBlockGetJumpsLen(void *hBlock, void *hLayer, void *hWnd);

// remove entities of specified layer from a block (all blocks if hBlock=0)
int LCAPI lcLayerClear(void *hLayer, void *hBlock);
int LCAPI lcLayerCopyProps(void *hLayer, void *hFromLayer);

// add line to a filling (see also lcDrwAddFilling)
int LCAPI lcFillSetLine(void *hFill, int iLine, double Dist, double Angle,
                        double W);

// Mline style
int LCAPI lcMLStyleAddLine(void *hStyle, double Offset, char *szColor,
                           void *hLtype);
int LCAPI lcMLStyleDelLine(void *hStyle, int iLine);
int LCAPI lcMLStyleSortLines(void *hStyle);

int LCAPI lcEntType(void *hEnt, int Typ);

// Graphic object modify
int LCAPI lcEntErase(void *hEnt, int bErase);
int LCAPI lcEntMove(void *hEnt, double dX, double dY);
int LCAPI lcEntAlign(void *hEnt, int Alignment, double X, double Y);
int LCAPI lcEntScale(void *hEnt, double X0, double Y0, double Scal);
int LCAPI lcEntRotate(void *hEnt, double X0, double Y0, double Angle);
int LCAPI lcEntMirror(void *hEnt, double X1, double Y1, double X2, double Y2);
int LCAPI lcEntExplode(void *hEnt, int bSelect, int bErase);
void *LCAPI lcEntSplit(void *hEnt, int nParts, int bSelectNew, int bDeleteEnt);
void *LCAPI lcEntBreak(void *hEnt, double X, double Y, double Delta,
                       int bSelectNew, int bDeleteEnt);
void *LCAPI lcEntBreak2(void *hEnt, void *hPtbuf, double Delta, int bSelectNew,
                        int bDeleteEnt);
int LCAPI lcEntOffset(void *hEnt, double Dist);
int LCAPI lcEntExtend(void *hEnt, void *hEntEdge, int bApparent);
int LCAPI lcEntToTop(void *hEnt);
int LCAPI lcEntToBottom(void *hEnt);
int LCAPI lcEntToAbove(void *hEnt, void *hEnt2);
int LCAPI lcEntToUnder(void *hEnt, void *hEnt2);
int LCAPI lcEntGetGrip(void *hEnt, int iGrip, double *pX, double *pY);
int LCAPI lcEntPutGrip(void *hEnt, int iGrip, double X, double Y);
int LCAPI lcEntUpdate(void *hEnt);
int LCAPI lcEntCopyBase(void *hEnt, void *hEntFrom);
int LCAPI lcEntXData(void *hEnt, int Id, int Flags, int nBytes);
int LCAPI lcEntContainEnt(void *hEnt, void *hEnt2);
int LCAPI lcEntCrossEnt(void *hEnt, void *hEnt2);
int LCAPI lcEntReverse(void *hEnt);
int LCAPI lcEntGetPoint(void *hEnt, double Dist, double *pX, double *pY,
                        double *pAngle);
double LCAPI lcEntGetDist(void *hEnt, double X, double Y, double *pX2,
                          double *pY2, double *pDist);
int LCAPI lcEntTransform(void *hEnt, void *hTransform);
int LCAPI lcIntersection(void *hEnt, void *hEnt2, int Apparent);
int LCAPI lcInterGetPoint(int iPoint, double *pX, double *pY);

int LCAPI lcLineGetPoint(void *hLine, int Mode, double Dist, double *pX,
                         double *pY);

// Polyline Vertices
void *LCAPI lcPlineAddVer(void *hPline, void *hVer, double X, double Y);
void *LCAPI lcPlineAddVer2(void *hPline, void *hVer, double X, double Y,
                           double Param, double W0, double W1);
void *LCAPI lcPlineAddVerDir(void *hPline, void *hVer, double Ang,
                             double Length);
int LCAPI lcPlineEnd(void *hPline);
int LCAPI lcPlineFromPtbuf(void *hPline, void *hPtbuf);
int LCAPI lcPlineFromMpgon(void *hPline, void *hMpgon);
int LCAPI lcPlineFromFile(void *hPline, char *szFileName);
int LCAPI lcPlineDeleteVer(void *hPline, void *hVer);
int LCAPI lcPlineDelExVers(void *hPline, double Delta);
void *LCAPI lcPlineGetFirstVer(void *hPline);
void *LCAPI lcPlineGetNextVer(void *hPline, void *hVer);
void *LCAPI lcPlineGetLastVer(void *hPline);
void *LCAPI lcPlineGetPrevVer(void *hPline, void *hVer);
void *LCAPI lcPlineGetVer(void *hPline, int Index);
void *LCAPI lcPlineGetVerPt(void *hPline, double X, double Y, double Delta);
void *LCAPI lcPlineGetSeg(void *hPline, double X, double Y, double Delta);
int LCAPI lcPlineReverse(void *hPline);
int LCAPI lcPlineSetStartVer(void *hPline, void *hVer);
int LCAPI lcPlineContainPoint(void *hPline, double X, double Y);
int LCAPI lcPlineGetRoundPrm(void *hPline, void *hVer, double *pX0, double *pY0,
                             double *pBulge, double *pX1,
                             double *pY1); // undoc (dwg plugin)
int LCAPI lcPlineGetPoint(void *hPline, double Dist, double *pX, double *pY,
                          double *pAngle);
int LCAPI lcPlineGetPointOpp(void *hPline, double Dist, double *pX, double *pY,
                             double *pAngle, double *pX2, double *pY2);
double LCAPI lcPlineGetDist(void *hPline, double X, double Y, double *pX2,
                            double *pY2, double *pDist);
int LCAPI lcPlineDivide(void *hPline, int nPoints, int bAngle);
int LCAPI lcPlineDivide2(void *hPline, double Delta, int bAngle);
int LCAPI lcGetDivPt(int iPnt, double *pX, double *pY, double *pAngle);
int LCAPI lcPlineMakeArrow(void *hPline, double Hline, double Harr); // undoc
void *LCAPI lcPlineSplitBySI(void *hPline, int bSelect, int bErase); // undoc

// Bezier Vertices
void *LCAPI lcBezierAddVer(void *hBez, void *hVer, double X, double Y);
int LCAPI lcBezierEnd(void *hBez);
int LCAPI lcBezierSetVerPrm(void *hBez, void *hVer, int Side, double Leng,
                            double Ang);

// Mline Vertices
void *LCAPI lcMlineAddVer(void *hMline, void *hVer, double X, double Y);
void *LCAPI lcMlineAddVerDir(void *hMline, void *hVer, double Ang,
                             double Length);
int LCAPI lcMlineDeleteVer(void *hMline, void *hVer);
void *LCAPI lcMlineGetFirstVer(void *hMline);
void *LCAPI lcMlineGetNextVer(void *hMline, void *hVer);
void *LCAPI lcMlineGetLastVer(void *hMline);
void *LCAPI lcMlineGetPrevVer(void *hMline, void *hVer);
void *LCAPI lcMlineGetVer(void *hMline, int Index);
void *LCAPI lcMlineGetVerPt(void *hMline, double X, double Y, double Delta);
void *LCAPI lcMlineGetSeg(void *hMline, double X, double Y,
                          double Delta); // undoc
int LCAPI lcMlineReverse(void *hMline);

// RPlan functions
void *LCAPI lcRPlanAddVer(void *hRPlan, double X, double Y);
int LCAPI lcRPlanSetCurve(void *hVer, double Radius, double LenClot1,
                          double LenClot2);
int LCAPI lcRPlanSetPos(void *hVer, double X, double Y);
int LCAPI lcRPlanDeleteVer(void *hRPlan, void *hVer);
void *LCAPI lcRPlanGetFirstVer(void *hRPlan);
void *LCAPI lcRPlanGetNextVer(void *hRPlan, void *hVer);
void *LCAPI lcRPlanGetLastVer(void *hRPlan);
void *LCAPI lcRPlanGetPrevVer(void *hRPlan, void *hVer);
void *LCAPI lcRPlanGetVer(void *hRPlan, int Index);
int LCAPI lcRPlanGetPoint(void *hRPlan, double Dist, double *pX, double *pY,
                          double *pAngle, int *pSide);
int LCAPI lcRPlanGetDist(void *hRPlan, double X, double Y, double *pX2,
                         double *pY2, double *pDist, double *pOffset);
int LCAPI lcRPlanWriteCSV(void *hRPlan, char *szFileName);

// Construction line
int LCAPI lcXlinePutDir(void *hXline, double X, double Y);

// Rectangle
int LCAPI lcRectGetPolyline(void *hRect, double *pX, double *pY,
                            double *pBulge);

// Circle

// Image reference
int LCAPI lcImgRefGetPixel(void *hImgRef, int iX, int iY, double *pX,
                           double *pY, int *pColor);
int LCAPI lcImgRefResize(void *hImgRef, int NewWidth, int NewHeight,
                         int Method);

// Hatch
int LCAPI lcHatchSetPattern(void *hHatch, char *szFileName, char *szPatName,
                            double Scal, double Angle);
int LCAPI lcHatchBoundStart(void *hHatch);
int LCAPI lcHatchBoundPoint(void *hHatch, double X, double Y);
int LCAPI lcHatchBoundEntity(void *hHatch, void *hEnt);
int LCAPI lcHatchBoundEndLoop(void *hHatch);
int LCAPI lcHatchBoundEnd(void *hHatch);
int LCAPI lcHatchPatStart(void *hHatch);
int LCAPI lcHatchPatLine(void *hHatch, double Angle, double x0, double y0,
                         double dx, double dy, int nDash, double L0, double L1,
                         double L2, double L3, double L4, double L5, double L6,
                         double L7);
int LCAPI lcHatchPatEnd(void *hHatch);
int LCAPI lcHatchGetLoopSize(void *hHatch, int iLoop);
int LCAPI lcHatchGetPoint(void *hHatch, int iPnt, double *pX, double *pY);
void *LCAPI lcHatchGetEnt(void *hHatch, int Mode);

// Viewport
int LCAPI lcVportSetView(void *hVport, double Xcen, double Ycen, double Scal,
                         double Angle);
int LCAPI lcVportLayerDlg(void *hVport, void *hLcWnd);
int LCAPI lcVportLayerCmd(void *hVport, int Cmd, void *hLayer);

// Block attribute
void *LCAPI lcBlkRefAddAtt(void *hBlockRef, char *szTag,
                           char *szValue); // for using in DWG plugin
void *LCAPI lcBlkRefGetFirstAtt(void *hBlockRef);
void *LCAPI lcBlkRefGetNextAtt(void *hBlockRef, void *hAttrib);
void *LCAPI lcBlkRefGetAtt(void *hBlockRef, char *szTag);
char *LCAPI lcBlkRefGetAttVal(void *hBlockRef, char *szTag);
int LCAPI lcBlkRefPutAttVal(void *hBlockRef, char *szTag, char *szValue);

// Shape
int LCAPI lcShapeAddEnt(void *hShape, void *hEnt, int bErase);
int LCAPI lcShapeEnd(void *hShape);
void *LCAPI lcShapeGetFirstEnt(void *hShape);
void *LCAPI lcShapeGetNextEnt(void *hShape, void *hEnt);
void *LCAPI lcShapeGetLastEnt(void *hShape);
void *LCAPI lcShapeGetPrevEnt(void *hShape, void *hEnt);

// TIN entity //(also LC_PROP_TIN_FILENAME and others, lcBlockGetTIN )
void *LCAPI lcTIN_AddPoint(void *hTIN, char *szNamePtype, double X, double Y,
                           double Z);
void *LCAPI lcTIN_PtypeGetByName(void *hTIN, char *szName);
void *LCAPI lcTIN_PtypeGetFirst(void *hTIN);
void *LCAPI lcTIN_PtypeGetNext(void *hTIN, void *hPtype);
void *LCAPI lcTIN_PntGetFirst(void *hTIN);
void *LCAPI lcTIN_PntGetNext(void *hTIN, void *hPnt);
void *LCAPI lcTIN_PntGetNear(void *hTIN, double X, double Y);
int LCAPI lcTIN_PntDelDup(void *hTIN, double Delta, void *hLcWnd);
void *LCAPI lcTIN_TriGetFirst(void *hTIN);
void *LCAPI lcTIN_TriGetNext(void *hTIN, void *hTrian);
void *LCAPI lcTIN_TriGetByPos(void *hTIN, double X, double Y);
int LCAPI lcTIN_TriGetEdge(void *hTIN, void *hTrian, int iEdge);
int LCAPI lcTIN_TriUpdate(void *hTIN, void *hPnt);
int LCAPI lcTIN_Bnd(void *hTIN, double MaxDist, void *hLcWnd);
void *LCAPI lcTIN_BndGetPoint(void *hTIN, int iPnt);
int LCAPI lcTIN_Triangulate(void *hTIN, void *hLcWnd); // LC_CMD_TIN_BNDTRANG
int LCAPI lcTIN_Isolines(void *hTIN, double Zstep, int BoldStep, void *hLcWnd);
void *LCAPI lcTIN_IsoGetFirst(void *hTIN);
void *LCAPI lcTIN_IsoGetNext(void *hTIN, void *hIso);
int LCAPI lcTIN_IsoMakeLabels(void *hIso);
int LCAPI lcTIN_GetIsoLabel(int iLabel, double *pX, double *pY, double *pAngle,
                            int *pAlign);
int LCAPI lcTIN_GetZ(void *hTIN, double X, double Y, double *pZ);
int LCAPI lcTIN_ColorFill(void *hTIN, double Zstep, double PixelSize,
                          void *hLcWnd);
int LCAPI lcTIN_Save(void *hTIN, char *szFileName, int Mode, int bByBndr,
                     void *hLcWnd);
int LCAPI lcTIN_InterLine(void *hTIN, double X0, double Y0, double X1,
                          double Y1);
int LCAPI lcTIN_InterGetPoint(void *hTIN, int iPnt, double *pX, double *pY,
                              double *pZ);
int LCAPI lcTIN_Clear(void *hTIN);
void *LCAPI lcTIN_AddTrian(void *hTIN, int iPnt0, int iPnt1, int iPnt2);
int LCAPI lcTIN_BndAddPnt(void *hTIN, int iPnt);
int LCAPI lcTIN_Merge(void *hTIN, char *szFileName, void *hLcWnd);

int LCAPI lcColorRGB(int Red, int Green, int Blue);
// Color from string
int LCAPI lcColorIsRGB(char *szColor);
int LCAPI lcColorGetRed(char *szColor);
int LCAPI lcColorGetGreen(char *szColor);
int LCAPI lcColorGetBlue(char *szColor);
int LCAPI lcColorGetIndex(char *szColor, int bLogicalEnabled);
int LCAPI lcColorToVal(char *szColor, int *pbRGB, int *pIndex, int *pR, int *pG,
                       int *pB);
// Color palette
int LCAPI lcColorSetPalette(int Index, int R, int G, int B);
int LCAPI lcColorGetPalette(int Index, int *pR, int *pG, int *pB);
int LCAPI lcColorSavePalette(char *szFileName, void *hWnd);
int LCAPI lcColorLoadPalette(char *szFileName, void *hWnd);

// Image
int LCAPI lcImageSetPixelRGB(void *hImage, int X, int Y, int Red, int Green,
                             int Blue);
int LCAPI lcImageSetPixelI(void *hImage, int X, int Y, int iColor);
int LCAPI lcImageGetPixelRGB(void *hImage, int X, int Y, int *pRed, int *pGreen,
                             int *pBlue);
int LCAPI lcImageGetPixelI(void *hImage, int X, int Y, int *piColor);
int LCAPI lcImageSetPalColor(void *hImage, int iColor, int Red, int Green,
                             int Blue);
int LCAPI lcImageGetPalColor(void *hImage, int iColor, int *pRed, int *pGreen,
                             int *pBlue);
int LCAPI lcImageLoad(void *hImage, char *szFilename, void *hWnd);
int LCAPI lcImageLoadDIB(void *hImage, void *hDib2); // undoc
int LCAPI lcImageLoadCamera(void *hImage);
int LCAPI lcImageCopyQuad(void *hImage, void *hImageSrc, unsigned int W,
                          unsigned int H, double x0, double y0, double x1,
                          double y1, double x2, double y2, double x3,
                          double y3); // undoc
int LCAPI lcImageProc(void *hImage, int Mode);

// Toolbar Window

// explode entity to polylines, Flags is LC_EXP_ALL or other
int LCAPI lcExpEntity(void *hEnt, int iChar, int Flags, int bUnrotate);
int LCAPI lcExpGetPline(double Delta);
int LCAPI lcExpGetVertex(double *pX, double *pY);
int LCAPI lcExpBlock(void *hBlock, F_LCEVENT pFunc, int Prm1, void *Prm2);

int LCAPI lcGbrLoad(void *hLcWnd, char *szFileName0);
int LCAPI lcGbrClose(void *hLcWnd);

char *LCAPI lcPlugGetOption(char *szFileName, char *szKey);
int LCAPI lcPlugGetOption2(char *szFileName, char *szKey);
int LCAPI lcPlugSetOption(char *szFileName, char *szKey, char *szValue,
                          int bSave);

int LCAPI lcPrintSetup(void *hWnd);
int LCAPI lcPrintLayout(void *hBlock);
int LCAPI lcPrintBlock(void *hBlock, double X, double Y, double W, double H,
                       double Scal, double PapLef, double PapTop, int Options);

void *LCAPI lcXDataBegin();
int LCAPI lcXDataEnd(void *hData);
int LCAPI lcXDataClear(void *hData);
int LCAPI lcXDataSet(void *hData);

// NoDB mode
// ////////////////////////////////////////////////////////////////////////////////////////

// Window Tabs
int LCAPI lcWndTabClear(void *hLcWnd);
int LCAPI lcWndTabAdd(void *hLcWnd, int TabID, char *szLabel, char *szTipText,
                      void *hObject);
int LCAPI lcWndTabSelect(void *hLcWnd, int TabID);

// Paper
int LCAPI lcWndPaperEnable(void *hLcWnd, int bEnable);
int LCAPI lcWndPaperSetSize(void *hLcWnd, int Size, int Orient);
int LCAPI lcWndPaperSetSize2(void *hLcWnd, double Width, double Height);
int LCAPI lcWndPaperSetPos(void *hLcWnd, double Left, double Bottom);

// Grips
int LCAPI lcGripClear(void *hLcWnd);
int LCAPI lcGripAdd(void *hLcWnd, void *hObj, int iGrip, int Typ, double X,
                    double Y, double Ang, double X0, double Y0);
int LCAPI lcGripSet(void *hLcWnd, void *hObj, int iGrip, double X, double Y,
                    double Ang, double X0, double Y0);

// to draw inside of Paint event procedure
void *LCAPI lcPaint_PenCreate(void *hLcWnd, int Id, int Color, double Width,
                              int PenStyle);
int LCAPI lcPaint_PenSelect(void *hLcWnd, void *hPen);
int LCAPI lcPaint_PenSelectID(void *hLcWnd, int IdPen);
void *LCAPI lcPaint_BrushCreate(void *hLcWnd, int Id, int Color, int Pattern,
                                int Alpha);
int LCAPI lcPaint_BrushSelect(void *hLcWnd, void *hBrush);
int LCAPI lcPaint_BrushSelectID(void *hLcWnd, int IdBrush);

int LCAPI lcPaint_DrawPtbuf(void *hLcWnd, void *hPtbuf, int bClosed);
int LCAPI lcPaint_DrawMpgon(void *hLcWnd, void *hMpgon, int bFill, int bBorder);
int LCAPI lcPaint_DrawImage(void *hLcWnd, void *hImage, double X, double Y,
                            double PixelSize, int Transp, int TVal,
                            void *hPtbuf);
int LCAPI lcPaint_DrawImage2(void *hLcWnd, void *hImage, double X, double Y,
                             double W, double H, int Transp, int TVal,
                             void *hPtbuf);
int LCAPI lcPaint_DrawText(void *hLcWnd, double X, double Y, char *szText);
int LCAPI lcPaint_DrawText2(void *hLcWnd, double X1, double Y1, double X2,
                            double Y2, int Align, char *szText);
int LCAPI lcPaint_DrawTextBC(void *hLcWnd, void *hMpgon, double Gap,
                             double Height, int Align, char *szText);
int LCAPI lcPaint_DrawArcText(void *hLcWnd, char *szText, double X, double Y,
                              double Rad, double Ang0, int bCW, double H,
                              double WScale, int Align);
int LCAPI lcPaint_DrawHatch(void *hLcWnd, void *hHatch);
int LCAPI lcPaint_DrawPoint(void *hLcWnd, double X, double Y, int PtMode,
                            double PtSize);
int LCAPI lcPaint_DrawLine(void *hLcWnd, double X1, double Y1, double X2,
                           double Y2);
int LCAPI lcPaint_DrawXline(void *hLcWnd, double X, double Y, double Angle,
                            int bRay);
int LCAPI lcPaint_DrawRect(void *hLcWnd, double Xc, double Yc, double Width,
                           double Height);
int LCAPI lcPaint_DrawRect2(void *hLcWnd, double X1, double Y1, double X2,
                            double Y2);
int LCAPI lcPaint_DrawPickBox(void *hLcWnd);
int LCAPI lcPaint_DrawGrid(void *hLcWnd, void *hGrid, int bDest, int ColLine,
                           int ColNode);
int LCAPI lcPaint_DrawCPrompt(void *hLcWnd, int X, int Y, int Align,
                              char *szText);
void LCAPI lcPaint_SetPixel(void *hDC, int X, int Y, int Color);

// Points buffer
void *LCAPI lcPaint_CreatePtbuf();
int LCAPI lcPaint_DeletePtbuf(void *hPtbuf);
int LCAPI lcPaint_PtbufClear(void *hPtbuf);
int LCAPI lcPaint_PtbufAddPoint(void *hPtbuf, double X, double Y, double Prm1,
                                double Prm2, int IntPrm);
int LCAPI lcPaint_PtbufAddPoint2(void *hPtbuf, double X, double Y);
int LCAPI lcPaint_PtbufAddPointP(void *hPtbuf, double Angle, double Dist);
int LCAPI lcPaint_PtbufAddLine(void *hPtbuf, double X1, double Y1, double X2,
                               double Y2);
int LCAPI lcPaint_PtbufAddLineP(void *hPtbuf, double X, double Y, double Angle,
                                double Dist);
int LCAPI lcPaint_PtbufAddCircle(void *hPtbuf, double Xc, double Yc, double R,
                                 int Resol);
int LCAPI lcPaint_PtbufAddCircle2(void *hPtbuf, double X1, double Y1, double X2,
                                  double Y2, int Resol);
int LCAPI lcPaint_PtbufAddCircle3(void *hPtbuf, double X1, double Y1, double X2,
                                  double Y2, double X3, double Y3, int bInside,
                                  int Resol);
int LCAPI lcPaint_PtbufAddArc(void *hPtbuf, double Xc, double Yc, double R,
                              double StartAngle, double ArcAngle, int Resol);
int LCAPI lcPaint_PtbufAddArc3p(void *hPtbuf, double X1, double Y1, double X2,
                                double Y2, double X3, double Y3, int Resol);
int LCAPI lcPaint_PtbufAddArcSDE(void *hPtbuf, double Xs, double Ys,
                                 double DirAng, double Xe, double Ye,
                                 int Resol);
int LCAPI lcPaint_PtbufAddArcSDAR(void *hPtbuf, double Xs, double Ys,
                                  double DirAng, double AngArc, double R,
                                  int Resol);
int LCAPI lcPaint_PtbufAddArcSER(void *hPtbuf, double Xs, double Ys, double Xe,
                                 double Ye, double Radius, int bClockwise,
                                 int Resol);
int LCAPI lcPaint_PtbufAddArcSEL(void *hPtbuf, double Xs, double Ys, double Xe,
                                 double Ye, double ArcLen, int bClockwise,
                                 int Resol);
int LCAPI lcPaint_PtbufAddArcSEA(void *hPtbuf, double Xs, double Ys, double Xe,
                                 double Ye, double AngArc, int Resol);
int LCAPI lcPaint_PtbufAddArcSEB(void *hPtbuf, double Xs, double Ys, double Xe,
                                 double Ye, double Bulge, int Resol);
int LCAPI lcPaint_PtbufAddArcCSE(void *hPtbuf, double Xc, double Yc, double Xs,
                                 double Ys, double Xe, double Ye,
                                 int bClockwise, int Resol);
int LCAPI lcPaint_PtbufAddArcCSA(void *hPtbuf, double Xc, double Yc, double Xs,
                                 double Ys, double AngArc, int Resol);
int LCAPI lcPaint_PtbufAddArcCSL(void *hPtbuf, double Xc, double Yc, double Xs,
                                 double Ys, double ChordLen, int bClockwise,
                                 int Resol);
int LCAPI lcPaint_PtbufAddArcCRAA(void *hPtbuf, double Xc, double Yc, double R,
                                  double AngStart, double AngEnd,
                                  int bClockwise, int Resol);
int LCAPI lcPaint_PtbufAddEllipse(void *hPtbuf, double Xc, double Yc,
                                  double Rmaj, double Rmin, double RotAng,
                                  double StartAng, double ArcAng, int Resol);
int LCAPI lcPaint_PtbufAddEllipse2(void *hPtbuf, double X1, double Y1,
                                   double X2, double Y2, int Resol);
int LCAPI lcPaint_PtbufAddRect(void *hPtbuf, double Xc, double Yc, double W,
                               double H, double Angle, double R, int Resol);
int LCAPI lcPaint_PtbufAddRect2(void *hPtbuf, double X1, double Y1, double X2,
                                double Y2, double R, int Resol);
int LCAPI lcPaint_PtbufAddRect3(void *hPtbuf, double X1, double Y1, double X2,
                                double Y2, double W, int Align, double R,
                                int Resol);
int LCAPI lcPaint_PtbufAddWline(void *hPtbuf, double X1, double Y1, double X2,
                                double Y2, double W, int Align, int bArc,
                                int Resol);
int LCAPI lcPaint_PtbufAddPtbuf(void *hPtbuf, void *hPtbuf2);
int LCAPI lcPaint_PtbufGetPoint(void *hPtbuf, int Mode, double *pX, double *pY);
int LCAPI lcPaint_PtbufGetPoint2(void *hPtbuf, int Mode, double *pX, double *pY,
                                 double *pPrm1, double *pPrm2, int *pIntPrm);
int LCAPI lcPaint_PtbufInterpolate(void *hPtbuf, int bClosed, void *hPtbufDest,
                                   int Mode, int Resol);
int LCAPI lcPaint_PtbufMove(void *hPtbuf, double dx, double dy);
int LCAPI lcPaint_PtbufRotate(void *hPtbuf, double Xc, double Yc, double Angle);
int LCAPI lcPaint_PtbufScale(void *hPtbuf, double Xc, double Yc, double ScaleX,
                             double ScaleY);
int LCAPI lcPaint_PtbufMirror(void *hPtbuf, double X1, double Y1, double X2,
                              double Y2);
int LCAPI lcPaint_PtbufCopy(void *hPtbuf, void *hPtbufDest);

// Multipolygon
void *LCAPI lcPaint_CreateMpgon();
int LCAPI lcPaint_DeleteMpgon(void *hMpgon);
int LCAPI lcPaint_MpgonClear(void *hMpgon);
int LCAPI lcPaint_MpgonAddPgon(void *hMpgon, void *hPtbuf);
int LCAPI lcPaint_MpgonAddText(void *hMpgon, void *hFont, double X, double Y,
                               char *szText, int Resol);
int LCAPI lcPaint_MpgonAddBarcode(void *hMpgon, int BarType, double Xc,
                                  double Yc, double Width, double Height,
                                  char *szText);
int LCAPI lcPaint_MpgonMove(void *hMpgon, double dx, double dy);
int LCAPI lcPaint_MpgonRotate(void *hMpgon, double Xc, double Yc, double Angle);
int LCAPI lcPaint_MpgonScale(void *hMpgon, double Xc, double Yc, double ScaleX,
                             double ScaleY);
int LCAPI lcPaint_MpgonMirror(void *hMpgon, double X1, double Y1, double X2,
                              double Y2);
int LCAPI lcPaint_MpgonCopy(void *hMpgon, void *hMpgonDest);

int LCAPI lcPaint_HatchGen(void *hMpgon, void *hHatch, double Dist,
                           double Angle, double Gap);

// Image
void *LCAPI lcPaint_ImageAdd(int Id);
int LCAPI lcPaint_ImageDelete(void *hImage);
void *LCAPI lcPaint_ImageGetFirst();
void *LCAPI lcPaint_ImageGetNext(void *hImage);
void *LCAPI lcPaint_ImageGetByID(int Id);
int LCAPI lcPaint_ImageLoad(void *hImage, char *szFileName);
int LCAPI lcPaint_ImageCopy(void *hImage, void *hImageDest);
int LCAPI lcPaint_ImageCreate(void *hImage, int Width, int Height);
int LCAPI lcPaint_ImageSetPixel(void *hImage, int X, int Y, int R, int G,
                                int B);
int LCAPI lcPaint_ImageFlip(void *hImage, int bHor, int bVert);
int LCAPI lcPaint_ImageRotate(void *hImage, double Angle);
int LCAPI lcPaint_ImageGray(void *hImage);
int LCAPI lcPaint_ImageResize(void *hImage, int NewWidth, int NewHeight,
                              int ResizeFilter);
void *LCAPI lcPaint_ImageGetPtbuf(void *hImage, double RotAngle);

void *LCAPI lcPaint_FontOpenLC(char *szFontName);
void *LCAPI lcPaint_FontOpenTT(char *szFontName, int bBold, int bItalic);
int LCAPI lcPaint_FontClose(void *hFont);
int LCAPI lcPaint_FontSelect(void *hLcWnd, void *hFont);

int lcLoadLib(char *szFileName);
void lcFreeLib();

#endif
