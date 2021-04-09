#include <iostream>
#include <string.h>
#include <assert.h>
#include "my_vector.h"

namespace product {

class Product {
public:
    Product(const char* name, int quantity, double price) {
        name_ = new char[strlen(name) + 1];
        strcpy(name_, name);
        quantity_ = quantity;
        price_ = price; 
    }

    Product() {
        name_ = nullptr;
    }

    Product(const Product &other) {
        name_ = new char[strlen(other.name_) + 1];
        strcpy(name_, other.name_);
        quantity_ = other.quantity_;
        price_ = other.price_;
    }

    Product(Product &&tmp) : name_(tmp.name_), quantity_(tmp.quantity_), price_(tmp.price_) {
        tmp.name_ = nullptr;
    }

    void swap(Product &other) {
        std::swap(name_, other.name_);
        std::swap(quantity_, other.quantity_);
        std::swap(price_, other.price_);
    }

    Product& operator=(const Product& other) {
        if (this == &other)
            return *this;
        Product tmp(other);
        tmp.swap(*this);

        return *this;
    }

    ~Product() {
        delete [] name_;
    }

    friend std::ostream& operator<<(std::ostream& stream, const Product& prod);

private:
    char *name_;  // Указатель владеет C-style строкой, на которую указывает.
    int quantity_;
    double price_;
};

std::ostream& operator<<(std::ostream& stream, const Product& prod) {
    stream << prod.name_ << " " << prod.quantity_ << " " << prod.price_;

    return stream;
}

}  // namespace product

namespace test {

template<typename T>
void test_my_vector(T a, T b) {
    try {
        my_vector::my_vector<T> v;

        assert(v.size() == 0);
        assert(v.capacity() == 1);
        assert(v.empty());

        v.push_back(a);
       v.push_back(b);
        v.push_back(b);
        assert(v.size() == 3);
        assert(v.capacity() == 4);

        v.pop_back();
        assert(v.size() == 2);
        assert(v.capacity() == 4);

        my_vector::my_vector u = v;
        assert(u.size() == 2);
        assert(u.capacity() == 4);

        u.reserve(7);
        assert(u.size() == 2);
        assert(u.capacity() == 8);

        u.reserve(3);
        assert(u.size() == 2);
        assert(u.capacity() == 8);

        v.resize(8);
        assert(v.size() == 8);
        assert(v.capacity() == 8);

        v.resize(3);
        assert(v.size() == 3);
        assert(v.capacity() == 8); 

        v.clear();
        v.resize(10);
    } catch(std::bad_alloc &b) {
        std::cout << "BAD_ALLOC: can't allocate memory: " << b.what() << "\n";
    }
} 

template<typename T>
void test_my_vector_default_constructible() {
    try {
        my_vector::my_vector<T> v(7);
        assert(v.size() == 7);
        assert(v.capacity() == 8);
        
        v.resize(30);
        assert(v.size() == 30);
        assert(v.capacity() == 32);
    
        v.resize(3);
        assert(v.size() == 3);
        assert(v.capacity() == 32);

        v.resize(8);
        assert(v.size() == 8);
        assert(v.capacity() == 32);
    } catch(const std::bad_alloc& b) {
        std::cout << "BAD_ALLOC: can't allocate memory: " << b.what() << "\n";
    }
}

} // namespace test

int main() {
    test::test_my_vector<int>(5, 10);
    test::test_my_vector<product::Product>(product::Product("asdf", 4, 12.0), product::Product("qwe", -1, 7.5));
    test::test_my_vector_default_constructible<int>();
    std::cout << "Success!!!\n";
    return 0;
}