cmake_minimum_required(VERSION 3.10)
project(Pilgrimage)

set(CMAKE_CXX_STANDARD 14)

# Add source files
set(SRC_FILES 
	main.cc
	src/system.cpp
	src/component.cpp
	src/iocomponent.cpp
)

# Add libraries if needed
add_library(component src/component.cpp)
add_library(iocomponent src/iocomponent.cpp)
add_library(system src/system.cpp)

# Add executable
add_executable(${PROJECT_NAME} ${SRC_FILES})

# Link libraries
target_link_libraries(${PROJECT_NAME} component iocomponent system)

target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)


