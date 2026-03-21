#ifndef engine_h
#define engine_h

struct eng_vertex {};

struct eng_mesh {
  int flags;
  struct eng_vertex *vertices;
  int vertices_count;
};

struct engine {
  struct eng_mesh *mesh_head;
  struct eng_mesh *mesh_tail;
};

#endif