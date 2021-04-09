#include <stdio.h>
#include <cmath>
#include "Rectangle.hpp"

Rectangle::Rectangle(int id, int x, int y, int width, int height) : Figure(id, x, y) {
    width_ = width;
    height_ = height;
}

Rectangle::~Rectangle() {
    
}

void Rectangle::print() const {
    printf("Rectangle %d: x = %d y = %d width = %i height = %d\n", id_, x_, y_, width_, height_);
}

bool Rectangle::is_inside(int x, int y) const {
    return 2 * abs(x_ - x) <= width_ && 2 * abs(y_ - y) <= height_;  
}

void Rectangle::zoom(int factor) {
    height_ *= factor;
    width_ *= factor;
}