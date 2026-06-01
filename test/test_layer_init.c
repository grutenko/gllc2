#include "litecad.h"

#include <assert.h>
#include <stdio.h>

int main()
{
        void *drawing = lcCreateDrawing();
        assert(drawing);
        assert(lcPropGetHandle(drawing, LC_PROP_DRW_BLOCK_MODEL));
        assert(lcDrwAddLayer(drawing, "0", "0,0,0", NULL, LC_LW_THIN));

        lcDeleteDrawing(drawing);
}