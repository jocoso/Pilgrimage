cmake_minimum_required(VERSION 3.10)
project(Pilgrimage)

set(CMAKE_CXX_STANDARD 14)

# Find SFML
find_package(SFML 2.5.1 REQUIRED COMPONENTS graphics window system)

# Add source files
set(SRC_FILES 
	main.cc
	src/system.cpp
	src/component.cpp
	src/iocomponent.cpp
)

# Add libraries if needed
add_library(system src/system.cpp)
add_library(component src/component.cpp)
add_library(iocomponent src/iocomponent.cpp)

# Add executable
add_executable(${PROJECT_NAME} ${SRC_FILES})

# Link libraries
target_link_libraries(${PROJECT_NAME} component iocomponent system sfml-graphics sfml-window sfml-system) 

# Include SFML headers and local include directory
target_include_directories(${PROJECT_NAME} 
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include 
    ${SFML_INCLUDE_DIRS}
)

# Add tests if needed
# enable_testing()
# add_executable(tests test/test.cpp)
# target_link_libraries(tests ${SFML_LIBRARIES})
# add_test(NAME test COMMAND tests)

