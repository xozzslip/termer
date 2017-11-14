#ifndef TERMER_H
#define TERMER_H


typedef struct {
    int max_x;
    int max_y;
    int size;
    char * buf;
} RenderBuffer;


RenderBuffer * init_render_buffer(int max_x, int max_y);
void render(int fd, RenderBuffer * rb);


#endif
