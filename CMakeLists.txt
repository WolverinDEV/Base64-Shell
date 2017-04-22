cmake_minimum_required(VERSION 3.2)
project(Base64_Commands)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -fpermissive")

set(SOURCE_FILES src/Base64Utils.h src/Base64Utils.cpp src/HexDump.h src/HexDump.cpp)


add_executable(Base64-Encode ${SOURCE_FILES} Base64Encode.cpp)
add_executable(Base64-Decode ${SOURCE_FILES} Base64Decode.cpp)

install(TARGETS Base64-Encode RUNTIME DESTINATION bin)
install(TARGETS Base64-Decode RUNTIME DESTINATION bin)