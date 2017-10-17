#include <stdio.h>
#include "Figure2D.h"

int
main()
{
  Figure2D f = createFigure2D();
  Point2D p1 = createPoint2D(100, 100);
  Point2D p2 = createPoint2D(300, 300);
  Point2D p3 = createPoint2D(400, 400);

  addLine(&f, p1, p2);
  addRectangle(&f, p1, p3);
  addLine(&f, p2, p3);
  draw(&f);
  destroyFigure2D(&f);
  puts("Press any key to exit...");
  getchar();
  return 0;
}
