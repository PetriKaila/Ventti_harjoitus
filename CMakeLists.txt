cmake_minimum_required(VERSION 2.80)
project(Ventti)

set(CMAKE_CXX_STANDARD 14)

include_directories(Ventti)

add_executable(Ventti
        "ventti_src/common_defs.h"
        "ventti_src/Jakaja.cpp"
        "ventti_src/Jakaja.h"
        "ventti_src/Kortti.cpp"
        "ventti_src/Kortti.h"
        "ventti_src/Lista.cpp"
        "ventti_src/Lista.h"
        "ventti_src/Pakka.cpp"
        "ventti_src/Pakka.h"
        "ventti_src/Pelaaja.cpp"
        "ventti_src/Pelaaja.h"
        "ventti_src/Peli.cpp"
        "ventti_src/Peli.h"
        "ventti_src/Valikko.cpp"
        "ventti_src/Valikko.h"
        "ventti_src/Ventti.cpp")
        
