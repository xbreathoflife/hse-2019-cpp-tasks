#include "Scheme.hpp"

Scheme::Scheme(int capacity) {
    figures_ = new Figure*[capacity];
    number_of_fugures = 0;
}

Scheme::~Scheme() {
    for (int i = 0; i < number_of_fugures; i++)
        delete figures_[i];
    delete [] figures_;
}

void Scheme::push_back_figure(Figure* fg) {
    figures_[number_of_fugures++] = fg;
}

int Scheme::find(int id) {
    int i = 0;
    while (figures_[i]->get() != id && i < number_of_fugures) {
        i++;
    }
    if (i == number_of_fugures)
        return -1;
    return i;
}

void Scheme::remove_figure(int id) {
    int i = find(id);
    if (i != -1) {
        delete figures_[i++];
        for (; i < number_of_fugures; i++) {
            figures_[i - 1] = figures_[i];
        }
        number_of_fugures--;
    }
}

void Scheme::print_all_figures() {
    for (int i = 0; i < number_of_fugures; i++)
        figures_[i]->print();
}

void Scheme::zoom_figure(int id, int factor) {
    int i = find(id);
    if (i != -1)
        figures_[i]->zoom(factor);
}

Figure* Scheme::is_inside_figure(int x, int y) {
    for (int i = 0; i < number_of_fugures; i++)
        if (figures_[i]->is_inside(x, y)) {
            return figures_[i];
            break;
        }
    return nullptr;
}

void Scheme::move(int id, int new_x, int new_y) {
    int i = find(id);
    if (i != -1) {
        figures_[i]->move(new_x, new_y);
    }
}