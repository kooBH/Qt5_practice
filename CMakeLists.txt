cmake_minimum_required(VERSION 3.1.0)

project(testproject)
set(CMAKE_CXX_STANDARD 11)
# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed
set(CMAKE_AUTOMOC ON)
# Create code from a list of Qt designer ui files
set(CMAKE_AUTOUIC ON)

# Find the QtWidgets library
#find_package(Qt5Widgets CONFIG REQUIRED)
#find_package(Qt5Core CONFIG REQUIRED)
#find_package(Qt5PaintDevice CONFIG REQUIRED)
find_package(Qt5 COMPONENTS Core Widgets Gui REQUIRED)

# Populate a CMake variable with the sources
set(SRC
    header.h
    window.h
    style.h
    switch.h
    switch.cpp
    main.cpp
)
# Tell CMake to create the helloworld executable
add_executable(${PROJECT_NAME} ${SRC})
# Use the Widgets module from Qt 5
target_link_libraries(${PROJECT_NAME} Qt5::Widgets)
target_link_libraries(${PROJECT_NAME} Qt5::Core)
#link_directories(${CMAKE_CURRENT_SOURCE_DIR}/lib)
target_link_libraries(${PROJECT_NAME} Qt5Widgets)

