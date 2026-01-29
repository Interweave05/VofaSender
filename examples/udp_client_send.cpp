//
// Created by interweave on 2026/1/29.
//

#include <complex>
#include <unistd.h>

#include "VofaSender.hpp"

[[noreturn]] int main() {
    vofasender::UDP_Client vofa("192.168.75.1", "1347");
    float i = 0;
    while (true)
    {
        i += 0.01f;
        float sin = std::sin(i);
        float cos = std::cos(i);
        vofa.send(sin,cos);
        usleep(2000);
    }
}