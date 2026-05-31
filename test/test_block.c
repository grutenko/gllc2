#include "litecad.h"

#include <assert.h>

int main()
{
        void *drawing = lcCreateDrawing();
        assert(drawing);
        void *block = lcPropGetHandle(drawing, LC_PROP_DRW_BLOCK_MODEL);
        assert(block);

        lcDeleteDrawing(drawing);
}