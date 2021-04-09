#include <iostream>
#include <algorithm>

namespace my_vector {

template<typename T>
std::size_t my_vector<T>::changeCapacity(std::size_t num) noexcept {
    if (num < 2)
        return 1;

    std::size_t new_capacity = 1;
    while (new_capacity < num) {
        new_capacity *= 2;
    }
    return new_capacity;
}

template<typename T>
my_vector<T>::my_vector_holder::my_vector_holder(std::size_t n) {
    capacity_ = changeCapacity(n);
    size_ = 0;
    array_ = reinterpret_cast<T*>(std::aligned_alloc(alignof(T), capacity_ * sizeof(T)));
}

template<typename T>
my_vector<T>::my_vector_holder::~my_vector_holder() {
    for ( ; size_ > 0; size_--)
        array_[size_ - 1].~T();
    free(reinterpret_cast<char *>(array_));
}

template<typename T>
void my_vector<T>::my_vector_holder::swap(my_vector_holder &other) {
    std::swap(array_, other.array_);
    std::swap(capacity_, other.capacity_);
    std::swap(size_, other.size_);
}

template<typename T>
my_vector<T>::my_vector(std::size_t n) : h(n) {
    while (h.size_ < n) {
        new (h.array_ + h.size_) T();
        h.size_++;
    }
}

template<typename T>
my_vector<T>::my_vector(const my_vector &other) : h(other.h.capacity_) {
    while (h.size_ < other.h.size_) {
        new (h.array_ + h.size_) T(other.h.array_[h.size_]);
        h.size_++;
    }
}

template<typename T>
my_vector<T>::my_vector(my_vector &&other) noexcept {
    h.swap(other.h);
}

template<typename T>
my_vector<T>& my_vector<T>::operator=(my_vector other) {
    if (this == &other)
        return *this;
    h.swap(other.h);
    return *this;
}

template<typename T>
my_vector<T>::~my_vector() {}

template<typename T>
std::size_t my_vector<T>::size() const noexcept {
    return h.size_;
}

template<typename T>
std::size_t my_vector<T>::capacity() const noexcept {
    return h.capacity_;
}

template<typename T>
bool my_vector<T>::empty() const noexcept {
    return h.size_ == 0;
}

template<typename T>
void my_vector<T>::resize(std::size_t n) {
    if (n < 0) {
        return;
    } else if (n < h.size_) {
        while (h.size_ > n)
            pop_back();
    } else if (n > h.size_ && n <= h.capacity_) {
        while (h.size_ < n)
            push_back(T());
    } else if (n > h.capacity_) {
        my_vector_holder newh(n);

        for (; newh.size_ < h.size_; newh.size_++)
            new (newh.array_ + newh.size_) T(std::move(h.array_[newh.size_]));
        for (; newh.size_ < n; newh.size_++)
            new (newh.array_ + newh.size_) T();
        h.swap(newh);
    }
}

template<typename T>
void my_vector<T>::reserve(std::size_t n) {
    if (n > h.capacity_) {
        my_vector_holder newh(n);
        for (; newh.size_ < h.size_; newh.size_++)
            new (newh.array_ + newh.size_) T(std::move(h.array_[newh.size_]));
        h.swap(newh);
    }
}

template<typename T>
const T& my_vector<T>::operator[](std::size_t index) const {
    return h.array_[index]; 
}

template<typename T>
T& my_vector<T>::operator[](std::size_t index) {
    return h.array_[index]; 
}

template<typename T>
void my_vector<T>::push_back(T t) {
    reserve(h.size_ + 1);
    new (h.array_ + h.size_++) T(std::move(t));
}

template<typename T>
void my_vector<T>::pop_back() {
    h.array_[--h.size_].~T();
}

template<typename T>
void my_vector<T>::clear() {
    while (h.size_ > 0)
        pop_back();
}

}

template<typename T>
std::ostream& operator<<(std::ostream& stream, const my_vector::my_vector<T>& vector) {
    for (std::size_t i = 0; i < vector.size() - 1; i++)
        stream << vector[i] << " ";
    stream << vector[vector.size() - 1];
    return stream;
}