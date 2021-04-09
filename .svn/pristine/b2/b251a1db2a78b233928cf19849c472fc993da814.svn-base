#ifndef MY_VECTOR_H_
#define MY_VECTOR_H_

#include <cstddef>

namespace my_vector {

template<typename T>
class my_vector {
public:
    my_vector() = default;
    explicit my_vector(std::size_t n);
    my_vector(const my_vector &other);
    my_vector(my_vector &&other) noexcept;
    my_vector& operator=( my_vector other);
    ~my_vector();

    std::size_t size() const noexcept;
    std::size_t capacity() const noexcept;
    bool empty() const noexcept;

    void resize(std::size_t n);
    void reserve(std::size_t n);

    const T & operator[](std::size_t index) const;
    T& operator[](std::size_t index);

    void push_back(T t);
    void pop_back();
    void clear();

private:
    struct my_vector_holder {
        T* array_;
        size_t capacity_;
        size_t size_;
        void swap(my_vector_holder &other);

        my_vector_holder(size_t n = 0);
        ~my_vector_holder();
        my_vector_holder(const my_vector_holder&) = delete;
        my_vector_holder& operator=(const my_vector_holder&) = delete;
    };
    my_vector_holder h;
    static std::size_t changeCapacity(std::size_t num) noexcept;
    
};

}

#include "my_vector_impl.h"

#endif  // MY_VECTOR_H_