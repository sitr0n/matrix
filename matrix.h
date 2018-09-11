#pragma once
#include "Arduino.h"

class Matrix {
	public:
		Matrix(int width, int height);
		void set(int value, int x, int y);
		int get(int x, int y);
		void fillWithValue(int value);

	private:
		int _width;
		int _height;

		typedef uint16_t data;
		struct element {
			data value = 0;
			element *next = NULL;
		}*origo;
};
