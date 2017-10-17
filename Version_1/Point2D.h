#ifndef __Point2D_h
#define __Point2D_h

struct Point2D
{
  int x;
  int y;

}; // Point2D

inline Point2D
createPoint2D(int x, int y)
{
  Point2D p;

  p.x = x;
  p.y = y;
  return p;
}

#endif // __Point2D_h
