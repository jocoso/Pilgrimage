cmake_minimum_required(VERSION 3.14)
project(Pilgrimage)

set(CMAKE_CXX_STANDARD 17)

# Use FetchContent to manage SFML
include(FetchContent)
FetchContent_Declare(
    sfml
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG        2.5.1
)
FetchContent_MakeAvailable(sfml)

# Add source files
set(SRC_FILES 
    main.cc
    src/system.cpp
    src/component.cpp
    src/iocomponent.cpp
    src/ccsystem.cpp
)

# Add libraries if needed
add_library(system src/system.cpp)
add_library(component src/component.cpp)
add_library(iocomponent src/iocomponent.cpp)
add_library(ccsystem src/ccsystem.cpp)

# Add executable
add_executable(${PROJECT_NAME} ${SRC_FILES})

# Add include directories for all targets
target_include_directories(${PROJECT_NAME} PRIVATE ${SFML_INCLUDE_DIRS})
target_include_directories(system PRIVATE ${SFML_INCLUDE_DIRS})
target_include_directories(component PRIVATE ${SFML_INCLUDE_DIRS})
target_include_directories(iocomponent PRIVATE ${SFML_INCLUDE_DIRS})
target_include_directories(ccsystem PRIVATE ${SFML_INCLUDE_DIRS})

# Ensure your own header files are included
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/include)
target_include_directories(system PRIVATE ${CMAKE_SOURCE_DIR}/include)
target_include_directories(component PRIVATE ${CMAKE_SOURCE_DIR}/include)
target_include_directories(iocomponent PRIVATE ${CMAKE_SOURCE_DIR}/include)
target_include_directories(ccsystem PRIVATE ${CMAKE_SOURCE_DIR}/include)

# Link SFML libraries to all targets
target_link_libraries(${PROJECT_NAME} 
    component 
    iocomponent 
    system 
    sfml-graphics 
    sfml-window 
    sfml-system
)

# Link SFML with individual targets
target_link_libraries(system sfml-graphics sfml-window sfml-system)
target_link_libraries(component sfml-graphics sfml-window sfml-system)
target_link_libraries(iocomponent sfml-graphics sfml-window sfml-system)
target_link_libraries(ccsystem sfml-graphics sfml-window sfml-system)
