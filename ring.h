#pragma once

#include <cstdlib>

template <typename T, size_t ring_capacity>
class Ring{
public:
    Ring(){}
    bool put(const T& elem){
        if (is_full()){
            return false;
        }
        data_[head_] = elem;
        increase_head();
        size_++;
        return true;
    }
    bool get(T& elem){
        if (is_empty()){
            return false;
        }
        elem = data_[tail_];
        increase_tail();
        size_--;
        return true;
    }
    bool is_empty()const{
        return size_ == 0;
    }
    bool is_full() const{
        return size_ == capacity_;
    }
    size_t size() const{
        return size_;
    }
private:
    T data_[ring_capacity];
    size_t head_ = 0;
    size_t tail_ = 0;
    size_t size_ = 0;
    const size_t capacity_ = ring_capacity;
    void increase_head(){
        if (head_ == (capacity_ - 1)){
            head_ = 0;
        } else {
            head_++;
        }
    }
    void increase_tail(){
        if (tail_ == (capacity_ - 1)){
            tail_ = 0;
        } else {
            tail_++;
        }
    }
};