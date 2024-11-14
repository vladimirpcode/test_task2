#pragma once

#include "ring.h"
#include <iostream>

void assert_(bool expr, const std::string& msg){
    if (!expr){
        std::cout << "ASSERT: " << msg << "\n";
        exit(-1); 
    }
}

void test(){
    Ring<int, 100> ring;
    assert_(ring.is_empty(), "кольцевой буфер не пустой после создания");
    assert_(ring.size() == 0, "неверный результат метода size()");
    assert_(!ring.is_full(), "кольцевой буфер полон после создания");
    for (int i = 0; i < 99; ++i){
        bool result = ring.put(i * 100);
        assert_(result, "неверный результат операции put()");
        assert_(!ring.is_empty(), "кольцевой буфер не должен быть пустым на данный момент");
        assert_(ring.size() != 0, "неверный результат метода size()");
        assert_(!ring.is_full(), "кольцевой буфер не должен быть полным на данный момент");
    }
    bool result = ring.put(100 * 100);
    assert_(result, "неверный результат операции put()");
    assert_(!ring.is_empty(), "кольцевой буфер не должен быть пустым на данный момент");
    assert_(ring.size() != 0, "неверный результат метода size()");
    assert_(ring.is_full(), "кольцевой буфер должен быть полным на данный момент");
    for (int i = 0; i < 99; ++i){
        int n;
        bool result = ring.get(n);
        assert_(result, "неверный результат операции get()");
        assert_(n == i * 100, "неверное значение после извлечения из буфера");
        assert_(!ring.is_empty(), "кольцевой буфер не должен быть пустым на данный момент");
        assert_(ring.size() != 0, "неверный результат метода size()");
        assert_(!ring.is_full(), "кольцевой буфер не должен быть полным на данный момент");
    }
    int n;
    result = ring.get(n);
    assert_(result, "неверный результат операции get()");
    assert_(ring.is_empty(), "кольцевой буфер должен быть пустым на данный момент");
    assert_(ring.size() == 0, "неверный результат метода size()");
    assert_(!ring.is_full(), "кольцевой буфер не должен быть полным на данный момент");
    
    Ring<std::string, 1000> ring_2;
    for (int i = 0; i < 1000; ++i){
        assert_(ring_2.is_empty(), "кольцевой буфер должен быть пустым на данный момент");
        assert_(ring_2.size() == 0, "неверный результат метода size()");
        ring_2.put("str " + std::to_string(i));
        assert_(!ring_2.is_empty(), "кольцевой буфер не должен быть пустым на данный момент");
        assert_(ring_2.size() != 0, "неверный результат метода size()");
        std::string s;
        ring_2.get(s);
        assert_(s == ("str " + std::to_string(i)), "неправильное значение после извлечения из буфера");
        assert_(ring_2.is_empty(), "кольцевой буфер должен быть пустым на данный момент");
        assert_(ring_2.size() == 0, "неверный результат метода size()");
    }
}