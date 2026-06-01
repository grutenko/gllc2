#include "litecad.h"

#include <assert.h>

int main()
{
        void *drawing = lcCreateDrawing();
        assert(drawing);
        assert(lcPropGetHandle(drawing, LC_PROP_DRW_BLOCK_MODEL));

        lcDeleteDrawing(drawing);
}