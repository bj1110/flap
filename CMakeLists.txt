cmake_minimum_required(VERSION 3.10)  # Mindestversion von CMake

project(flap)                    # Projektname

set(CMAKE_CXX_STANDARD 20)       # C++ Standard setzen

# Finde SFML, z. B. Graphics-Modul (zieht automatisch andere mit)
find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)


add_executable(flap main.cpp obstacle.cpp)   # Erstelle ein Executable aus main.cpp

# SFML-Bibliotheken zum Target linken
target_link_libraries(flap sfml-graphics sfml-window sfml-system)