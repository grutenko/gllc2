#ifndef debug_h
#define debug_h

void fmt_impl(const char *level, const char *file, int line, const char *func, const char *fmt, ...);

#define WARN(fmt, ...) fmt_impl("WARN", __FILE__, __LINE__, __func__, fmt, ##__VA_ARGS__)
#define ERROR(fmt, ...) fmt_impl("ERROR", __FILE__, __LINE__, __func__, fmt, ##__VA_ARGS__)

#define NONULL(ptr, retval)                                \
        do                                                 \
        {                                                  \
                if ((ptr) == NULL)                         \
                {                                          \
                        WARN("NULL pointer \"%s\"", #ptr); \
                        return retval;                     \
                }                                          \
        } while (0)

#endif