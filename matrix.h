#pragma once
#include <cassert>

class Matrix {
	public:
		Matrix(int width, int height);
		~Matrix();
		void set(int value, int x, int y);
		int get(int x, int y);
		void fillWithValue(int value);

	private:
		int _width;
		int _height;

		typedef int data;
		struct element {
			data value = 0;
			element *next = nullptr;
		}*origo;
};