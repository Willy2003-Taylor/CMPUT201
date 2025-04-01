#include <stdio.h>

struct Rect {
  int x, y, w, h;
};

void translate(struct Rect *p, int x, int y) {
  p->x = p->x + x;
  p->y = p->y + y;
}

int main() {
  struct Rect r;
  r.x = 0;
  r.y = 0;
  r.w = 5;
  r.h = 3;
  printf("Rectangle at (%d, %d) with width %d and height %d\n", r.x, r.y, r.w, r.h);
  translate(&r, 2, -3);
  printf("Rectangle at (%d, %d) with width %d and height %d\n", r.x, r.y, r.w, r.h);

}
