#ifndef ui_ptbuf_h
#define ui_ptbuf_h

struct ui_ptbuf_point
{
        double x;
        double y;
        double dist;
};

struct ui_ptbuf
{
        struct ui_ptbuf_point *pts;
        int ptscnt;
        int ptscap;
};

void ui_ptbuf_init(struct ui_ptbuf *ptbuf);
void ui_ptbuf_put_point(struct ui_ptbuf *ptbuf, const struct ui_ptbuf_point *point, int exclusive);
void ui_ptbuf_draw(struct ui_ptbuf *ptbuf);
int ui_ptbuf_snap(struct ui_ptbuf *ptbuf, double *x, double *y);
void ui_ptbuf_cleanup(struct ui_ptbuf *ptbuf);

#endif