cmake_minimum_required(VERSION 3.12)

include($ENV{PICO_SDK_PATH}/external/pico_sdk_import.cmake)

project(pico_motor_pwm_demo C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

pico_sdk_init()

link_directories(libmicroros)
add_executable(pico_motor_pwm_demo
    pico_motor_pwm_demo.c
    pico_uart_transport.c
)

add_subdirectory(/Users/kaitlinday/OneDrive\ -\ Washington\ University\ in\ St.\ Louis/ESE\ 3050/pico-arduino-compat/libs/tfli2c build-pac-tfli2c)

target_link_libraries(pico_motor_pwm_demo
    pico_stdlib
    microros
    hardware_pwm
    pac-tfli2c
)

target_include_directories(pico_motor_pwm_demo PUBLIC
    libmicroros/include
)

SET(CMAKE_C_FLAGS  "${CMAKE_C_FLAGS} -ffunction-sections -fdata-sections")
SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -ffunction-sections -fdata-sections")

# Configure Pico
pico_enable_stdio_usb(pico_motor_pwm_demo 1)
pico_enable_stdio_uart(pico_motor_pwm_demo 0)
add_compile_definitions(PICO_UART_ENABLE_CRLF_SUPPORT=0)
add_compile_definitions(PICO_STDIO_ENABLE_CRLF_SUPPORT=0)
add_compile_definitions(PICO_STDIO_DEFAULT_CRLF=0)

# Generate UF2
pico_add_extra_outputs(pico_motor_pwm_demo)
