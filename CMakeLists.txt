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
message(STATUS ${PROJECT_SOURCE_DIR})
find_package(Qt5 COMPONENTS Core Widgets Gui REQUIRED 
  #  PATH ${PROJECT_SOURCE_DIR}/lib
  # NO_DEFAULT_PATH
  )

include_directories(
  include
  )
# Populate a CMake variable with the sources
set(SRC
      KApplication.h 
    switch.cpp
    KLabel.h
    KWidget.h
    KPushButton.h
    App.h
    header.h
    window.h
    style.h
    switch.h
    Funcs.h
    KRun.h

   
    BorderLayout.h
    BorderLayout.cpp
)
#add_library(bar SHARED IMPORTED)

#set_target_properties(bar PROPERTIES
#  IMPORTED_LOCATION 
#  "${CMAKE_SOURCE_DIR}/lib/libQt5Core.so"
#  INTERFACE_INCLUDE_DIRECTORIES "${CMAKE_SOURCE_DIR}"
#)
set(TARGETS)
list(APPEND TARGETS 
  #  exe_button 
  #  exe_label 
  #  exe_target
  # exe_frame
    exe_module
  )

#link_directories("${CMAKE_SOURCE_DIR}/lib")
# Tell CMake to create the helloworld executable
#add_executable(exe_button main_button.cpp ${SRC})
#add_executable(exe_label main_label.cpp ${SRC})
#add_executable(exe_target main_target.cpp ${SRC})
#add_executable(exe_frame main_frame.cpp ${SRC})
add_executable(exe_module main_module.cpp ${SRC})

#target_link_libraries(${PROJECT_NAME} bar)

# Use the Widgets module from Qt 5
foreach(TARGET ${TARGETS})
  target_link_libraries(${TARGET} Qt5::Widgets)
  target_link_libraries(${TARGET} Qt5::Core)
  target_link_libraries(${TARGET} Qt5::Gui)
endforeach()
#link_directories(${CMAKE_CURRENT_SOURCE_DIR}/lib)

#get_target_property(OUT ${PROJECT_NAME} LINK_LIBRARIES)
#message(STATUS ${OUT})

