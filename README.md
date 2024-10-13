# 坦克智能小车项目

## 项目简介

该项目基于 Arduino主板 + PS2手柄 + L298N 来控制小车的移动。能够通过手柄的按钮和摇杆控制小车的运动和速度。

## 目录

- [功能概述](#功能概述)
- [硬件连接](#硬件连接)
- [使用方法](#使用方法)
- [代码结构](#代码结构)
- [贡献](#贡献)

## 功能概述

- **PS2控制器支持**：连接并读取 PS2 手柄的输入。
- **小车运动控制**：通过按钮和摇杆控制小车的前进、后退、左右移动和转向。
- **速度调节**：使用 L2 和 R2 按钮调节小车速度。
- **振动反馈**：根据 X 按钮的压力控制 PS2 手柄的振动强度。

## 硬件连接

确保按以下引脚连接 PS2 控制器和电机驱动器：

| PS2 控制器引脚 | Arduino 引脚 |
|-----------|------------|
| CLK       | A2         |
| CMD       | A3         |
| SEL       | A5         |
| DAT       | A4         |

| 电机驱动器引脚 | Arduino 引脚 |
|-------|------------|
| EN_A  | 3          |
| EN_B  | 6          |
| IN1_A | 4          |
| IN2_A | 5          |
| IN1_B | 7          |
| IN2_B | 8          |

## 使用方法

1. **下载项目**：将代码克隆或下载到本地。
2. **打开 CLion IDE**：在 IDE 中打开 `main.cpp` 文件。
4. **上传代码**：点击“上传”按钮，将代码上传到 Arduino。
5. **连接 PS2 控制器**：确保 PS2 控制器连接正确，电源打开。
6. **运行程序**：打开串口监视器，您将看到控制器连接状态和小车运动状态的反馈。

## 代码结构

```
arduino_tank/
├── .gitignore                # Git 忽略文件
├── platformio.ini           # PlatformIO 项目配置文件
├── src/
│   ├── main.cpp             # 主程序文件
│   ├── ps2x_control.cpp     # PS2 控制器类实现
│   └── motor_control.cpp    # 电机控制类实现
├── include/
│   ├── ps2x_control.h       # PS2 控制器类头文件
│   └── motor_control.h      # 电机控制类头文件
└── lib/
    └── PS2X_lib/        # PS2X 库文件
```

- .gitignore: 指定 Git 忽略的文件和文件夹，例如编译生成的文件。
- platformio.ini: PlatformIO 的项目配置文件，用于指定开发板、库和其他设置。
- src/: 源代码目录，包含所有的源文件和头文件。
    - main.cpp: 主程序文件，包含 setup() 和 loop() 函数。
    - ps2x_control.cpp 和 ps2x_control.h: 用于实现和定义 PS2 控制器的逻辑。
    - motor_control.cpp 和 motor_control.h: 用于实现和定义电机控制的逻辑。
- lib/: 库目录，用于存放项目所需的第三方库。
  - PS2X_lib/: PS2X 库文件夹，包含库的实现和头文件。

## 贡献

欢迎提交问题和功能请求。请提交合并请求时遵循以下步骤：

1. Fork 该仓库
2. 创建您的特性分支 (`git checkout -b feature—xxx`)
3. 提交您的更改 (`git commit -m 'Add some feature—xxx'`)
4. 推送到分支 (`git push origin feature—xxx`)
5. 创建合并请求
