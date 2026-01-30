//
// Created by interweave on 2026/1/30.
//
#include <complex>
#include <iostream>

#include "VofaSender.hpp"

[[noreturn]] int main() {
    std::cout << "使用之前请将remote_ip设置为vofa所在电脑的ip，并确认端口是否配置正确" << std::endl;
    vofasender::TCP_Client vofa("192.168.75.1", "1347");
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