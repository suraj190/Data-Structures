cmake_minimum_required(VERSION 3.9)
project(HW1_2 C)

set(CMAKE_C_STANDARD 11)


set (SOURCES main.c matrix.c matrix.h) #add any other sources you have after matrix.h

#create the executable from the sources
add_executable(FindDeterminant ${SOURCES})

target_link_libraries(FindDeterminant PRIVATE m)
target_compile_options(FindDeterminant PRIVATE -Wall -Werror)

#name the executable
set_target_properties(FindDeterminant
        PROPERTIES
        OUTPUT_NAME "FindDeterminant"
        SUFFIX ".out")

