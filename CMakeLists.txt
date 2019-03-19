cmake_minimum_required(VERSION 3.1.0)

project(testproject)

LIST(APPEND CMAKE_PROGRAM_PATH  "C:\\Qt\\5.12.1\\msvc2017_64\\bin")

set(CMAKE_CXX_STANDARD 11)
# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed
#set(CMAKE_AUTOMOC ON)
# Create code from a list of Qt designer ui files
#set(CMAKE_AUTOUIC ON)

set(CMAKE_POSITION_INDEPENDENT_CODE ON)
# Find the QtWidgets library
#find_package(Qt5Widgets CONFIG REQUIRED)
#find_package(Qt5Core CONFIG REQUIRED)
#find_package(Qt5PaintDevice CONFIG REQUIRED)
message(STATUS ${PROJECT_SOURCE_DIR})


include_directories(
  include
  include/QtCore
  include/QtGui
  include/QtWidgets
  )
# Populate a CMake variable with the sources
set(SRC
    KApplication.h 
    switch.cpp
    KLabel.h
    KWidget.h
    KPushButton.h
    KComboBox.h
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
    exe_combobox
  )

#link_directories("${CMAKE_SOURCE_DIR}/lib")
# Tell CMake to create the helloworld executable
#add_executable(exe_button main_button.cpp ${SRC})
#add_executable(exe_label main_label.cpp ${SRC})
#add_executable(exe_target main_target.cpp ${SRC})
#add_executable(exe_frame main_frame.cpp ${SRC})
add_executable(exe_module main_module.cpp ${SRC})

add_executable(exe_combobox main_combobox.cpp ${SRC})

#target_link_libraries(${PROJECT_NAME} bar)

# Use the Widgets module from Qt 5

#list(APPEND CMAKE_PREFIX_PATH ${PROJECT_SOURCE_DIR}/lib)
#find_library(PATH_Qt5Core REQUIRED Qt5Core)

if(UNIX)
	foreach(TARGET ${TARGETS})
	  #  target_link_libraries(${TARGET} Qt5::Widgets)
	  # target_link_libraries(${TARGET} Qt5::Core)
	  #target_link_libraries(${TARGET} Qt5::Gui)
	  target_link_libraries(${TARGET} 
	  ${PROJECT_SOURCE_DIR}/lib/libQt5Widgets.so
	  ${PROJECT_SOURCE_DIR}/lib/libQt5Core.so
	  ${PROJECT_SOURCE_DIR}/lib/libQt5Gui.so)  

	  target_compile_options(${TARGET} PRIVATE -fPIC)
	endforeach()
elseif(WIN32)
	link_directories(${PROJECT_SOURCE_DIR}/lib)
	foreach(TARGET ${TARGETS})
	  target_link_libraries(${TARGET} 
	 # ${PROJECT_SOURCE_DIR}/lib/Qt5Core.lib
	 # ${PROJECT_SOURCE_DIR}/lib/Qt5Gui.lib
	 # ${PROJECT_SOURCE_DIR}/lib/Qt5Widgets.lib)  
	  ${PROJECT_SOURCE_DIR}/lib/Qt5Core.lib
	  ${PROJECT_SOURCE_DIR}/lib/Qt5Gui.lib
	  ${PROJECT_SOURCE_DIR}/lib/Qt5Widgets.lib)  
	  endforeach()
	 
endif()
message(${PROJECT_SOURCE_DIR})

#link_directories(${CMAKE_CURRENT_SOURCE_DIR}/lib)

#get_target_property(OUT ${PROJECT_NAME} LINK_LIBRARIES)
#message(STATUS ${OUT})



