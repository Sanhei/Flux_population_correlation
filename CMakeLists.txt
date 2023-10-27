cmake_minimum_required(VERSION 3.1)

set(CMAKE_USER_MAKE_RULES_OVERRIDE "platform.cmake")

set(CMAKE_CXX_FLAGS, "-lboost_program_options -lm -lfftw3")
project(free_energy CXX)


find_package(Boost "1.58" QUIET REQUIRED COMPONENTS
        program_options
        system
        )

find_package(PkgConfig REQUIRED)
pkg_search_module(FFTW REQUIRED fftw3 IMPORTED_TARGET)
include_directories(PkgConfig::FFTW)



include_directories(${Boost_INCLUDE_DIR})
add_subdirectory(src)
