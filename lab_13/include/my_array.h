#ifndef MY_ARRAY_H_
#define MY_ARRAY_H_

#include <cstddef>
#include <stdexcept>
#include <cstring>

const int BYTE_SIZE = 8;

namespace lab_13 {

template<typename T, std::size_t N>
class my_array {
public:
    my_array() = default;

    ~my_array() = default;

    const T& at(std::size_t index) const {
        if (index >= N)
            throw std::out_of_range("Out of range: index is not valid");
        return data[index];
    }

    T& at(std::size_t index) {
        if (index >= N)
            throw std::out_of_range("Out of range: index is not valid");
        return data[index];
    }

    const T& operator[](std::size_t index) const {
        return data[index];
    }

    T& operator[](std::size_t index) {
        return data[index];
    }

    bool empty() const {
        return N == 0;
    }

    std::size_t size() const {
        return N;
    }

    void fill(T val) {
        for (std::size_t i = 0; i < N; i++) {
            data[i] = val;
        }
    }

private:
    T data[N];
};

template<std::size_t N>
class my_array<bool, N> {
private:
    struct my_array_bool_proxy {
        my_array_bool_proxy(uint8_t* data_, std::size_t bit_) : data(data_), bit(bit_) {

        }

        my_array_bool_proxy operator=(bool value) {
            *data &= ~(1 << bit);
            *data |= value << bit;
            return *this;
        }

        my_array_bool_proxy operator=(my_array_bool_proxy other) {
            *this = bool(other);
            return *this;
        }

        operator bool() const {
            return *data & (1 << bit);
        }

        uint8_t *data;
        std::size_t bit;
    };
public:
    my_array() = default;

    ~my_array() = default;

    my_array_bool_proxy at(std::size_t index) {
        if (index >= N)
            throw std::out_of_range("Out of range: index is not valid");
        return my_array_bool_proxy(&data[index / BYTE_SIZE], index % BYTE_SIZE);
    };

    bool at(std::size_t index) const {
        if (index >= N)
            throw std::out_of_range("Out of range: index is not valid");
        return data[index / BYTE_SIZE] & (1 << index % BYTE_SIZE);
    };

    my_array_bool_proxy operator[](std::size_t index) {
        return my_array_bool_proxy(&data[index / BYTE_SIZE], index % BYTE_SIZE);
    }

    bool operator[](std::size_t index) const {
        return data[index / BYTE_SIZE] & (1 << index % BYTE_SIZE);
    }

    bool empty() const {
        return N == 0;
    }

    std::size_t size() const {
        return N;
    }

    void fill(bool val) {
        if (!val)
            memset(data, val, sizeof(data));
        else
            memset(data, (1 << BYTE_SIZE) - 1, sizeof(data));
        
    }

private:
    uint8_t data[(N + BYTE_SIZE - 1) / BYTE_SIZE];
};

}  // namespace lab_13

#endif  // MY_ARRAY_H_