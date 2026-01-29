//
// Created by interweave on 2026/1/27.
//

#ifndef LIVOX_TEST_VOFA_UDP_HPP
#define LIVOX_TEST_VOFA_UDP_HPP

#pragma once

#include <cstdint>
#include <cstring>
#include <vector>

#include "asio2/udp/udp_client.hpp"
#include "asio2/udp/udp_server.hpp"
#include "asio2/tcp/tcp_client.hpp"

namespace vofasender {
    /**
    * @brief UDP Client for Vofa
    * @details 用于向Vofa发送数据的UDP客户端
    * @param[in] $remote_ip 为Vofa主机远程IP地址
    * @param[in] $remote_port 为Vofa主机远程端口号
    */
    class UDP_Client {
    public:
        UDP_Client(std::string_view remote_ip = "0.0.0.0", std::string_view remote_port = "1347") {
            client_.start(remote_ip, remote_port);
        }

        ~UDP_Client() {
            client_.stop();
            client_.destroy();
        }

        template <typename... Args>
        void send(Args... args) {
            static_assert(sizeof...(args) > 0, "At least one value!");

            buffer_.clear();
            buffer_.reserve(sizeof...(args) * 4 + 4);

            ([this](auto value)
            {
                static_assert(std::is_arithmetic<decltype(value)>::value, "Vofa only supports arithmetic types");

                float v = static_cast<float>(value);
                uint8_t raw[4];
                std::memcpy(raw, &v, 4);
                buffer_.insert(buffer_.end(), raw, raw + 4);
            }(args), ...);

            buffer_.push_back(0x00);
            buffer_.push_back(0x00);
            buffer_.push_back(0x80);
            buffer_.push_back(0x7F);

            client_.async_send(buffer_);
        }

    private:
        asio2::udp_client client_;
        std::vector<uint8_t> buffer_;
    };

    class UDP_Server {
        UDP_Server() {
        };

        UDP_Server(std::string_view vofa_ip = "0.0.0.0", std::string_view vofa_port = "1346") {
        }
    };
}


#endif //LIVOX_TEST_VOFA_UDP_HPP
