cmake_minimum_required(VERSION "2.8.2")

project(Berkeley)

file(GLOB berk_src src/*.cpp)

include_directories(	include
						/usr/include/irrlicht)
						
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-Wall -Wextra")

# comment this out for release builds (ugly but I don't know the better way of doing it)
add_definitions(-DDEBUG)

add_executable(berk ${berk_src})

target_link_libraries(	berk
						/usr/lib/libIrrlicht.so
					 )
