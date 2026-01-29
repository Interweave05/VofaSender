# VofaSender

一个基于 asio2 的 header-only C++ 库，用于向 VOFA+ 通过 UDP、TCP、串口等 方式发送数据，适合机器人调试、实时曲线可视化等场景

---

## 特性

- 轻量级的 header-only 库，易于集成到现有项目中
- 支持多种通信协议：UDP、TCP、串口
- 简单易用的 API，快速上手，减少开发时间
- 高性能设计，适用于实时数据传输场景

---

## 依赖

- 使用 [asio2](https://github.com/zhllxt/asio2) 作为通信基础库。  
  asio2 基于 Asio 实现（支持 standalone Asio 或 boost::asio），在 Ubuntu 下可直接通过以下命令安装 standalone Asio：
  ```bash
  sudo apt install libasio-dev
- C++17 或更高版本

## 使用案例

在 `examples` 文件夹中，您可以找到多个使用本库的示例，帮助您快速理解如何将其集成到您的项目中

### 如何运行示例
   ```bash
   git clone https://github.com/Interweave05/VofaSender.git
   cd VofaSender
   mkdir build
   cd build
   cmake ..
   make -j10