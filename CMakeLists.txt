cmake_minimum_required(VERSION 3.20)
project(sort_animation C)
SET(MY_LIBARY_DIRS shuffle sort)

set(CMAKE_C_STANDARD 99)

SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
SET(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

# GTK Library
FIND_PACKAGE(PkgConfig REQUIRED)
PKG_CHECK_MODULES(GTK3 REQUIRED gtk+-3.0)
add_definitions(${GTK3_CFLAGS_OTHER})

include_directories(${GTK3_INCLUDE_DIRS} ${PROJECT_SOURCE_DIR}/include)
link_directories(${GTK3_LIBRARY_DIRS} ${MY_LIBARY_DIRS})

add_subdirectory(${PROJECT_SOURCE_DIR}/src)
add_subdirectory(${PROJECT_SOURCE_DIR}/tests)

SET(EXTRA_LIBRARIES ${EXTRA_LIBRARIES} ${MY_LIBARY_DIRS})

target_link_libraries(sort_animation
        ${GTK3_LIBRARIES} ${EXTRA_LIBRARIES})