cmake_minimum_required(VERSION 3.10)
project(SNMPClient)

add_definitions(-D${PROJECT_NAME})

find_package(OpenMP REQUIRED)
find_package(JNI REQUIRED)
include_directories(${JNI_INCLUDE_DIRS})

FILE(GLOB SNMP_FILES "./SNMP/*.cpp")
FILE(GLOB SOCKET_FILES "./Socket/*.cpp")
FILE(GLOB UTILS_FILES "./Utils/*.cpp")

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS} -fpermissive")
set(CMAKE_CXX_STANDARD 11)
set(FILES ${SNMP_FILES} ${SOCKET_FILES} ${UTILS_FILES} main.cpp)

add_library(${PROJECT_NAME} SHARED ${FILES})
target_link_libraries(${PROJECT_NAME} ${JAVA_JVM_LIBRARY} ${CMAKE_THREAD_LIBS_INIT})
install(TARGETS ${PROJECT_NAME}
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib/static)