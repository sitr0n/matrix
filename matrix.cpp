#include "matrix.h"


Matrix::Matrix(int width, int height) :
  _width(width),
  _height(height)
{
  Serial.begin(115200);
  origo = new element;
  element *node = origo;
  int size = _width*_height;
  for (int i = 0; i < size; i++) {
    node->next = new element;
    node = node->next;
  }
}

void Matrix::fillWithValue(int value)
{
  element *node = origo;
  (node)->value = (data) value;
  int size = _width*_height;
  for (int i = 0; i < size - 1; i++) {
    node = node->next;
    (node)->value = (data) value;
  }
}

void Matrix::set(int value, int x, int y)
{
  assert(x < _width);
  assert(y < _height);

  element *node = origo;
  
  int index = y*_width + x;
  for (int i = 0; i < index; i++) {
    node = node->next;
  }
  node->value = value;
}

int Matrix::get(int x, int y)
{
  assert(x < _width);
  assert(y < _height);
  
  element *node = origo;
  int index = y*_width + x;
  for (int i = 0; i < index; i++) {
    //Serial.println((node)->value);
    node = node->next;
  }
  int elementValue = (int) node->value;
  return elementValue;
}

