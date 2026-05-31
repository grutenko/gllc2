#include "litecad.h"

#include <assert.h>
#include <stdio.h>

int main()
{
        void *drawing = lcCreateDrawing();
        assert(drawing);
        void *block = lcPropGetHandle(drawing, LC_PROP_DRW_BLOCK_MODEL);
        assert(block);
        void *layer = lcDrwAddLayer(drawing, "0", "0,0,0", NULL, LC_LW_THIN);

        lcDeleteDrawing(drawing);
}