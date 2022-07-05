# COPYRIGHT NOTICE: (c) 2022 Irnas. All rights reserved.

cmake_minimum_required(VERSION 3.13.1)

find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})

project(sentek_iot_probe_nrf52840_firmware)

zephyr_compile_options(-fdiagnostics-color=always)

target_sources(app PRIVATE
  src/main.c
)
