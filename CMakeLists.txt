cmake_minimum_required(VERSION 3.1.0)

project(testproject)

#############################
# Use Installed Qt pacakges #
#############################

list(APPEND CMAKE_PREFIX_PATH 
  /home/kbh/AAA/5.12.3/gcc_64/lib/cmake
  /home/kbh/AAA/5.12.3/gcc_64/lib/cmake/Qt5Widgets
  /home/kbh/AAA/5.12.3/gcc_64/lib/cmake/Qt5PaintDevice
  )


set(CMAKE_CXX_STANDARD 11)
# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed
set(CMAKE_AUTOMOC ON)

set(CMAKE_POSITION_INDEPENDENT_CODE ON)
# Find the QtWidgets library
find_package(Qt5Widgets CONFIG REQUIRED)
find_package(Qt5Core CONFIG REQUIRED)
find_package(Qt5Gui CONFIG REQUIRED)

option(spec "spec" OFF)
option(switch_2 "b" FF)
option(button "a" OFF)
option(label OFF)
option(combobox OFF)
option(target OFF)
option(module OFF)
option(frame OFF)
option(graphic OFF)
 
message(STATUS ${PROJECT_SOURCE_DIR})


set(LINKLIBS)


include_directories(
  include
    include/QtCore
    include/QtGui
  include/QtWidgets
  )
# Populate a CMake variable with the sources
set(SRC
    KApplication.h 
    KLabel.h
    KWidget.h
    KPushButton.h
    KComboBox.h
    header.h
    window.h
    style.h
    Funcs.h
    KRun.h
    switch_2.h
    KSpectrogram.h
    #  switch_2.cpp

   
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
if(label)
  list(APPEND TARGETS exe_label)
  add_executable(exe_label main_label.cpp ${SRC}) 
endif(label)
if(button)
  list(APPEND TARGETS exe_button)
  add_executable(exe_button main_button.cpp ${SRC}) 
endif(button)
if(combobox)
  list(APPEND TARGETS exe_combobox)
  add_executable(exe_combobox main_combobox.cpp ${SRC}) 
endif(combobox)
if(module)
  list(APPEND TARGETS exe_module)
  add_executable(exe_module main_module.cpp ${SRC}) 
endif(module)
if(frame)
  list(APPEND TARGETS exe_frame)
  add_executable(exe_frame main_frame.cpp ${SRC}) 
endif(frame)
if(target)
  list(APPEND TARGETS exe_target)
  add_executable(exe_target main_target.cpp ${SRC}) 
endif(target)
if(switch_2)
  list(APPEND TARGETS exe_switch_2)
  add_executable(exe_switch_2 main_switch_2.cpp ${SRC}) 
endif(switch_2)
if(spec)
  list(APPEND TARGETS exe_spec)
  add_executable(exe_spec main_spec.cpp ${SRC}) 
endif(spec)
if(graphic)
  list(APPEND TARGETS exe_graphic)
  add_executable(exe_graphic main_graphic.cpp ${SRC}) 
  message("spec ON")
endif(graphic)



#link_directories("${CMAKE_SOURCE_DIR}/lib")
# Tell CMake to create the helloworld executable

#add_executable(exe_combobox main_combobox.cpp ${SRC})

foreach(TARGET ${TARGETS})
  target_link_libraries(${TARGET} Qt5::Widgets Qt5::Core Qt5::Gui)
endforeach()

# Use the Widgets module from Qt 5

#list(APPEND CMAKE_PREFIX_PATH ${PROJECT_SOURCE_DIR}/lib)
#find_library(PATH_Qt5Core REQUIRED Qt5Core)


################################
# Use Standalone library files # 
################################
##
##if(UNIX)
##list(APPEND LINKLIBS
##  # ${PROJECT_SOURCE_DIR}/lib/libQt5Widgets.so
##  #  ${PROJECT_SOURCE_DIR}/lib/libQt5Core.so
##  #  ${PROJECT_SOURCE_DIR}/lib/libQt5Gui.so
##    )  
##	foreach(TARGET ${TARGETS})
##    target_link_libraries(${TARGET} ${LINKLIBS})
##    message("target" ${TARGET})
##
##	  target_compile_options(${TARGET} PRIVATE -fPIC)
##	endforeach()
##elseif(WIN32)
##	link_directories(${PROJECT_SOURCE_DIR}/lib)
##	foreach(TARGET ${TARGETS})
##	  target_link_libraries(${TARGET} 
##	 # ${PROJECT_SOURCE_DIR}/lib/Qt5Core.lib
##	 # ${PROJECT_SOURCE_DIR}/lib/Qt5Gui.lib
##	 # ${PROJECT_SOURCE_DIR}/lib/Qt5Widgets.lib)  
##	  ${PROJECT_SOURCE_DIR}/lib/Qt5Core.lib
##	  ${PROJECT_SOURCE_DIR}/lib/Qt5Gui.lib
##	  ${PROJECT_SOURCE_DIR}/lib/Qt5Widgets.lib
##    m
##    )  
##	  endforeach()
##	 
##endif()
##

message(${PROJECT_SOURCE_DIR})

link_directories(${CMAKE_CURRENT_SOURCE_DIR}/lib)

#get_target_property(OUT ${PROJECT_NAME} LINK_LIBRARIES)
#message(STATUS ${OUT})



