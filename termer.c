#include <termios.h>
#include <unistd.h>
#include <string.h>


typedef struct {
	int max_x;
	int max_y;
	int size;
	char * buf;
} RenderBuffer;


RenderBuffer * init_render_buffer(int max_x, int max_y) {
	RenderBuffer * rb = malloc(sizeof(RenderBuffer));
	rb->max_x = max_x;
	rb->max_y = max_y;
	rb->size = (max_x + 1) * max_y;
	rb->buf = malloc(sizeof(char) * rb->size);
}


void flush(RenderBuffer * rb) {
	int i;
	memset(0, rb->buf, sizeof(char) * rb->size);
	for (i = 1; i <= rb->max_y; i++) {
		rb->buf[(max_x + 1) * i - 1] = '\n';
	}
}


void render(int fd, RenderBuffer * rb) {
	write(fd, rb->buf, rb->size);
	flush(rb);
}
