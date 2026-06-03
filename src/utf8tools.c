#include "utf8tools.h"

#include <string.h>
#include <utf8proc.h>

int is_overlong(const utf8proc_uint8_t *p, utf8proc_ssize_t len)
{
        if (len == 2)
        {
                return (p[0] & 0xFE) == 0xC0; // C0, C1
        }
        else if (len == 3)
        {
                return (p[0] == 0xE0 && (p[1] & 0xE0) == 0x80);
        }
        else if (len == 4)
        {
                return (p[0] == 0xF0 && (p[1] & 0xF0) == 0x80);
        }
        return false;
}

int utf8check(const char *str, int len)
{
        size_t bytes_left = len;
        const utf8proc_uint8_t *ptr = (const utf8proc_uint8_t *)str;
        utf8proc_int32_t codepoint;
        utf8proc_ssize_t advance;

        while (bytes_left > 0)
        {
                advance = utf8proc_iterate(ptr, bytes_left, &codepoint);
                if (advance <= 0)
                {
                        return false;
                }
                if (is_overlong(ptr, advance))
                {
                        return false;
                }
                ptr += advance;
                bytes_left -= advance;
        }
        return true;
}

int utf8caseicmp(const char *s0, const char *s1)
{
        if (!s0 || !s1)
                return 0;
        utf8proc_uint8_t *s0p = (utf8proc_uint8_t *)s0;
        utf8proc_uint8_t *s1p = (utf8proc_uint8_t *)s1;
        utf8proc_ssize_t s0left = strlen(s0);
        utf8proc_ssize_t s1left = strlen(s1);
        while (s0left > 0 && s1left > 0)
        {
                utf8proc_int32_t c0;
                utf8proc_int32_t c1;
                utf8proc_ssize_t l0;
                utf8proc_ssize_t l1;
                l0 = utf8proc_iterate(s0p, s0left, &c0);
                l1 = utf8proc_iterate(s1p, s1left, &c1);
                if (l0 < 0 || l1 < 0)
                        return 0;
                if (utf8proc_tolower(c0) != utf8proc_tolower(c1))
                        return 0;
                s0p += l0;
                s1p += l1;
                s0left -= l0;
                s1left -= l1;
        }
        return s0left == 0 && s1left == 0;
}