#include <stdio.h>
#include "Line2D.h"

void drawLine(int, int, int, int);

Bounds2D
bounds(const Line2D* l)
{
  return createBounds2D(l->p1, l->p2);
}

void
draw(const Line2D* l)
{
  printf("Line2D %d\n", ((Shape2D*)l)->id);
  drawLine(l->p1.x, l->p1.y, l->p2.x, l->p2.y);
}

static Shape2D::FPT lineFPT =
{
  (Shape2D::BoundsFunc)bounds,
  (Shape2D::DrawFunc)draw
};

Line2D*
createLine2D(const Point2D& p1, const Point2D& p2)
{
  Line2D* l = new Line2D();

  l->shape.fpt = &lineFPT;
  l->shape.next = l->shape.previous = nullptr;
  l->p1 = p1;
  l->p2 = p2;
  // TODO: set color
  return l;
}
