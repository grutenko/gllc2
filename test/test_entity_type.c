#include "litecad.h"

#include <assert.h>

int main()
{
        void *drawing = lcCreateDrawing();
        assert(drawing);
        void *block = lcPropGetHandle(drawing, LC_PROP_DRW_BLOCK_MODEL);
        assert(block);
        assert(lcPropGetHandle(drawing, LC_PROP_DRW_BLOCK_MODEL));
        void *pline = lcBlockAddPolyline(block, 0, 0, 0);
        assert(pline);
        void *circle = lcBlockAddCircle(block, 0, 0, 0, 10);
        assert(circle);
        void *arc = lcBlockAddArc(block, 0, 0, 10, 0, 90);
        assert(arc);
        void *text = lcBlockAddText(block, "TEXT", 0, 0);
        assert(text);
        assert(lcPropGetInt(pline, LC_PROP_ENT_TYPE) == LC_ENT_POLYLINE);
        assert(lcPropGetInt(circle, LC_PROP_ENT_TYPE) == LC_ENT_CIRCLE);
        assert(lcPropGetInt(arc, LC_PROP_ENT_TYPE) == LC_ENT_ARC);
        assert(lcPropGetInt(text, LC_PROP_ENT_TYPE) == LC_ENT_TEXT);
        lcDeleteDrawing(drawing);
}