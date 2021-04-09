#include <cstring>
#include <stdio.h>
#include "Circle.hpp"

Circle::Circle(int id, int x, int y, int radius, const char* label) : Figure(id, x, y) {
    radius_ = radius;
    label_ = new char[strlen(label) + 1];
    strcpy(label_, label);
}

Circle::~Circle() {
    delete [] label_;
}

void Circle::print() const {
    printf("Circle %d: x = %d y = %d radius = %i label = %s\n", id_, x_, y_, radius_, label_);
}

bool Circle::is_inside(int x, int y) const {
    return (x_ - x_) * (x_ - x) + (y_ - y) * (y_ - y) <= radius_ * radius_;
}

void Circle::zoom(int factor) {
    radius_ *= factor;
}
