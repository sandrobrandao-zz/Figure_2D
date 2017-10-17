#include <stdio.h>
#include "Rectangle2D.h"

void drawLine(int, int, int, int);

Bounds2D
bounds(const Shape2D* s)
{
  Rectangle2D* r = (Rectangle2D*)s;
  return createBounds2D(r->p1, r->p2);
}

void
draw(const Shape2D* s)
{
  Rectangle2D* r = (Rectangle2D*)s;

  printf("Rectangle2D %d\n", s->id);
  drawLine(r->p1.x, r->p1.y, r->p2.x, r->p1.y);
  drawLine(r->p2.x, r->p1.y, r->p2.x, r->p2.y);
  drawLine(r->p2.x, r->p2.y, r->p1.x, r->p2.y);
  drawLine(r->p1.x, r->p2.y, r->p1.x, r->p1.y);
}

static Shape2D::FPT rectFPT =
{
  bounds,
  draw
};

Rectangle2D*
createRectangle2D(const Point2D& p1, const Point2D& p2)
{
  Rectangle2D* r = new Rectangle2D();

  r->shape.fpt = &rectFPT;
  r->shape.next = r->shape.previous = nullptr;
  // TODO: set corners
  r->p1 = p1;
  r->p2 = p2;
  // TODO: set color
  return r;
}
