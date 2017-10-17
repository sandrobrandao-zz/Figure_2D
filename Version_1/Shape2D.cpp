#include "Shape2D.h"

void
addShape(ShapeList* list, Shape2D* shape)
{
  if (list->head == nullptr)
    list->head = shape;
  else
  {
    list->tail->next = shape;
    shape->previous = list->tail;
  }
  list->tail = shape;
  list->count++;
}
