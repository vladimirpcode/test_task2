#include "ring.h"
#include "test.h"
#include <iostream>
#include <string>
#include <ctime>
#include <cstring>

int main(){
    test();
    Ring<tm, 1000> ring;
    tm my_time;
    memset(&my_time, 0, sizeof(my_time));
    my_time.tm_hour = 6;
    ring.put(my_time);
}