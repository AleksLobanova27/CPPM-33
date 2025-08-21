cmake_minimum_required(VERSION 3.22.0)
project(RaceSimulator)

# Устанавливаем стандарт C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Подключаем библиотеку и приложение
add_subdirectory(RaceSimulatorLib)
add_subdirectory(RaceSimulatorApp)