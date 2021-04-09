#include <algorithm>
#include "shared_ptr.hpp"

shared_ptr::Storage::Storage(Matrix* mtx) : data_(mtx) {
    ref_count_ = 1;
}

shared_ptr::Storage::~Storage() {
    delete data_;
}

void shared_ptr::Storage::incr() {
    ref_count_++;
}

void shared_ptr::Storage::decr() {
    ref_count_--;
}

int shared_ptr::Storage::getCounter() const {
    return ref_count_;
}

Matrix* shared_ptr::Storage::getObject() const {
    return data_;
}

shared_ptr::shared_ptr(Matrix* obj) {
    if (obj == nullptr)
        storage_ = nullptr;
    else
        storage_ = new Storage(obj);
}

shared_ptr::shared_ptr(const shared_ptr& other) : storage_(other.storage_){
    if (other.storage_ != nullptr)
        storage_->incr();
}

shared_ptr& shared_ptr::operator=(shared_ptr other) {
    std::swap(other.storage_, this->storage_);
    return *this;
}

shared_ptr::~shared_ptr() {
    if (storage_ != nullptr) {
        storage_->decr();
        if (storage_->getCounter() == 0)
            delete storage_;
    }
}

Matrix* shared_ptr::ptr() const {
    if (storage_ != nullptr)
        return storage_->getObject();
    return nullptr;
}

bool shared_ptr::isNull() const {
    return ptr() == nullptr;
}

void shared_ptr::reset(Matrix* obj) {
    if (storage_ != nullptr) {
        storage_->decr();
        if (storage_->getCounter() == 0)
            delete storage_;
    }
    if (obj == nullptr)
        storage_ = nullptr;
    else
        storage_ = new Storage(obj);
}

Matrix* shared_ptr::operator->() const {
    return storage_->getObject();
}

Matrix& shared_ptr::operator*() const {
    return *(storage_->getObject());
}
