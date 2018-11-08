cmake_minimum_required(VERSION 3.10)
project(client)

add_definitions(-DClient)

find_package (Threads)

FILE(GLOB SNMP_FILES "./SNMP/*.cpp")
FILE(GLOB SOCKET_FILES "./Socket/*.cpp")
FILE(GLOB UTILS_FILES "./Utils/*.cpp")

set(CMAKE_CXX_STANDARD 11)
set(FILES ${SNMP_FILES} ${SOCKET_FILES} ${UTILS_FILES} Socket/DatagramSocket.h Socket/DatagramSocket.cpp)

add_executable(${PROJECT_NAME}  ${FILES})
target_link_libraries(${PROJECT_NAME} ${CMAKE_THREAD_LIBS_INIT})