#ifndef cmd_h
#define cmd_h

struct gllc_cmd_vtable
{
};

struct gllc_cmd
{
        struct gllc_cmd_vtable *vtable;
};

#endif