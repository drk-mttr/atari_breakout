cmake_minimum_required(VERSION 3.20.0)
project(pge)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(pge main.cpp breakout.cpp)

add_link_options(user32 gdi32 opengl32 gdiplus Shlwapi dwmapi stdc++fs)

target_include_directories(pge PUBLIC "${PROJECT_SOURCE_DIR}")