#include <stdio.h>
#include "Bounds2D.h"
#include "Figure2D.h"

static int sid;

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
  f.lastSelected = nullptr;
  return f;
}

void
destroyFigure2D(Figure2D* f)
{
  destroyShapeList(&f->shapes);
}

void
addShape(Figure2D* f, Shape2D* shape)
{
  shape->id = ++sid;
  addShape(&f->shapes, shape);
}

void
draw(const Figure2D* f)
{
  for (Shape2D* s = f->shapes.head; s != nullptr; s = s->next)
    s->fpt->draw(s);
}

void
selectShapes(Figure2D* f, const Point2D& p)
{
  for (Shape2D* s = f->shapes.head; s != nullptr; s = s->next)
  {
    Bounds2D b = s->fpt->bounds(s);

    if (contains(&b, p))
    {
      s->link = f->lastSelected;
      f->lastSelected = s;
      printf("Shape %d selected\n", s->id);
    }
  }
}

void
removeShapes(Figure2D* f)
{
  while (f->lastSelected != nullptr)
  {
    Shape2D* temp = f->lastSelected;

    f->lastSelected = temp->link;
    printf("Shape %d removed\n", temp->id);
    removeShape(&f->shapes, temp);
  }
}
