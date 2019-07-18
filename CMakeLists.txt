cmake_minimum_required(VERSION 3.14.0)

project(traveling-wav)
enable_language(CXX)

set(CMAKE_CONFIGURATION_TYPES Debug Release)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG "${CMAKE_BINARY_DIR}/Debug")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG "${CMAKE_BINARY_DIR}/Debug")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG "${CMAKE_BINARY_DIR}/Debug")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_BINARY_DIR}/Release")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELEASE "${CMAKE_BINARY_DIR}/Release")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE "${CMAKE_BINARY_DIR}/Release")

file(GLOB TVGW_SRC "script/cpp/src/*.cpp" )
file(GLOB TVGW_HEADER "script/cpp/includes")

message(STATUS "TVGW_SRC VAL is ${TVGW_SRC}")
message(STATUS "TVGW_HEADER VAL is ${TVGW_HEADER}")

include_directories(${TVGW_HEADER})

add_library(tvgw SHARED ${TVGW_SRC})
add_library(tvgw_static STATIC ${TVGW_SRC})

if(MSVC)
    set_target_properties(tvgw
        PROPERTIES
            OUTPUT_NAME "travelingwav"
            SUFFIX ".dll"
        )
    set_target_properties(tvgw_static
        PROPERTIES
            OUTPUT_NAME "tvgw-static"
            SUFFIX ".lib"
        )
else()
    set_target_properties(tvgw
        PROPERTIES 
            PREFIX "lib"
            OUTPUT_NAME "travelingwav"
            SUFFIX ".so"
        )
    set_target_properties(tvgw_static
        PROPERTIES 
            PREFIX "lib"
            OUTPUT_NAME "tvgw-static"
            SUFFIX ".a"
        )
endif()
