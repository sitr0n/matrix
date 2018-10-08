#include "matrix.h"

Matrix::Matrix(int width, int height) :
	_width(width),
	_height(height)
{
	origo = new element;
	element *node = origo;
	int size = _width*_height;
	for (int i = 0; i < size; i++) {
		node->next = new element;
		node = node->next;
	}
}

Matrix::~Matrix()
{
	int size = _width*_height;
	int i = 0;
	auto *nodeToRemove = origo;
	while(true){	
		auto *trailNode = nodeToRemove->next;
		delete nodeToRemove;
		if (i >= size - 1)
			break;
		i++;
		nodeToRemove = trailNode;
	}
}

void Matrix::fillWithValue(int value)
{
	auto *node = origo;
	node->value = (data) value;
	int size = _width*_height;
	for (int i = 0; i < size - 1; i++) {
		node = node->next;
		node->value = (data) value;
	}
}

void Matrix::set(int value, int x, int y)
{
	assert(x < _width);
	assert(y < _height);

	auto *node = origo;
	int index = y*_width + x;
	for (int i = 0; i < index; i++) {
		node = node->next;
	}
	node->value = (data) value;
}

int Matrix::get(int x, int y)
{
	assert(x < _width);
	assert(y < _height);

	auto *node = origo;
	int index = y*_width + x;
	for (int i = 0; i < index; i++) {
		node = node->next;
	}
	int elementValue = (int) node->value;
	return elementValue;
}