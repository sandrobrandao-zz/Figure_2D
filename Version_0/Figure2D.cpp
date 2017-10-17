#include <stdio.h>
#include "Figure2D.h"

void
drawLine(int x1, int y1, int x2, int y2)
{
  printf("<%d,%d> <%d,%d>\n", x1, y1, x2, y2);
}

Figure2D
createFigure2D()
{
  Figure2D f;

  f.shapes = createShapeList();
  return f;
}

void
destroyFigure2D(Figure2D* f)
{
  destroyShapeList(&f->shapes);
}

inline void
drawLine(const Line2D* l)
{
  printf("Line2D\n");
  drawLine(l->p1.x, l->p1.y, l->p2.x, l->p2.y);
}

inline void
drawRectangle(const Rectangle2D* r)
{
  printf("Rectangle2D\n");
  drawLine(r->p1.x, r->p1.y, r->p2.x, r->p1.y);
  drawLine(r->p2.x, r->p1.y, r->p2.x, r->p2.y);
  drawLine(r->p2.x, r->p2.y, r->p1.x, r->p2.y);
  drawLine(r->p1.x, r->p2.y, r->p1.x, r->p1.y);
}

void
draw(const Figure2D* f)
{
  for (Shape2D* s = f->shapes.head; s != nullptr; s = s->next)
    switch (s->type)
    {
      case Shape2D::LINE:
        drawLine((Line2D*)s);
        break;

      case Shape2D::RECTANGLE:
        drawRectangle((Rectangle2D*)s);
        break;
    }
}
