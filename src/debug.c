#include "debug.h"
#include <stdarg.h>
#include <stdio.h>
#include <string.h>

static const char *short_file(const char *path)
{
        const char *p1 = strrchr(path, '/');
        const char *p2 = strrchr(path, '\\');
        const char *p = p1 > p2 ? p1 : p2;
        return p ? p + 1 : path;
}

void fmt_impl(const char *level, const char *file, int line, const char *func, const char *fmt, ...)
{
        fprintf(stderr, "[%s] %s:%d (%s): ", level, short_file(file), line, func);

        va_list args;
        va_start(args, fmt);
        vfprintf(stderr, fmt, args);
        va_end(args);

        fprintf(stderr, "\n");
        fflush(stderr);
}