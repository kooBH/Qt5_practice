cmake_minimum_required(VERSION 3.1.0)

project(testproject)

#############################
# Use Installed Qt pacakges #
#############################


set(CMAKE_CXX_STANDARD 14)
# Find includes in corresponding build directories

# Find the QtWidgets library

option(textedit  OFF)
option(graphic "graphic" OFF)
option(spec "spec" OFF)
option(switch_2 "b" OFF)
option(button "a" OFF)
option(label OFF)
option(combobox OFF)
option(target OFF)
option(module OFF)
option(frame OFF)
option(web ON)
 
message(STATUS ${PROJECT_SOURCE_DIR})


set(LINKLIBS)

include_directories(
  include
  include/QtCore
  include/QtGui
  include/QtWidgets

  include/QtWebEngine
  include/QtWebEngineCore
  include/QtWebEngineWidgets
  include/QtQml
  include/QtNetwork
  include/QtQuick
  include/QtPositioning
  include/QtWebChannel
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
    KGl.h
    KGl.cpp
   
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
endif(graphic)
if(textedit)
  list(APPEND TARGETS exe_graphic)
  add_executable(exe_graphic main_graphic.cpp ${SRC}) 
endif(textedit)
if(web)
  list(APPEND TARGETS exe_web)
  add_executable(exe_web main_web.cpp ${SRC})
endif(web)

#link_directories("${CMAKE_SOURCE_DIR}/lib")
# Tell CMake to create the helloworld executable

#add_executable(exe_combobox main_combobox.cpp ${SRC})

set(LINKLIBS)
set(COMPILE_OPTION)

	list(APPEND LINKLIBS
	    ${PROJECT_SOURCE_DIR}/lib/libQt5Widgets.so.5
	    ${PROJECT_SOURCE_DIR}/lib/libQt5Core.so.5
	    ${PROJECT_SOURCE_DIR}/lib/libQt5Gui.so.5
	    ${PROJECT_SOURCE_DIR}/lib/libQt5XcbQpa.so.5
	    ${PROJECT_SOURCE_DIR}/lib/platforms/libqxcb.so

      ${PROJECT_SOURCE_DIR}/lib/libQt5WebEngine.so.5
      ${PROJECT_SOURCE_DIR}/lib/libQt5WebEngineCore.so.5
      ${PROJECT_SOURCE_DIR}/lib/libQt5WebEngineWidgets.so.5
      ${PROJECT_SOURCE_DIR}/lib/libQt5Qml.so.5
      ${PROJECT_SOURCE_DIR}/lib/libQt5Quick.so.5
      ${PROJECT_SOURCE_DIR}/lib/libQt5QuickWidgets.so.5
      ${PROJECT_SOURCE_DIR}/lib/libQt5Network.so.5
      ${PROJECT_SOURCE_DIR}/lib/libQt5WebChannel.so.5
      ${PROJECT_SOURCE_DIR}/lib/libQt5Positioning.so.5
      ${PROJECT_SOURCE_DIR}/lib/libQt5PositioningQuick.so.5
      ${PROJECT_SOURCE_DIR}/lib/libQt5PrintSupport.so.5


      #	    ${PROJECT_SOURCE_DIR}/lib/xcbglintegrations/libqxcb-egl-integration.so
      #${PROJECT_SOURCE_DIR}/lib/xcbglintegrations/libqxcb-glx-integration.so


	    )  


list(APPEND COMPILE_OPTION -fPIC)


foreach(TARGET ${TARGETS})
  target_link_libraries(${TARGET} ${LINKLIBS})
  message(STATUS ${TARGET} " -- " ${LINKLIBS})
  target_compile_options(${TARGET} PRIVATE ${COMPILE_OPTION} )
endforeach()



# Use the Widgets module from Qt 5

#list(APPEND CMAKE_PREFIX_PATH ${PROJECT_SOURCE_DIR}/lib)
#find_library(PATH_Qt5Core REQUIRED Qt5Core)


message(${PROJECT_SOURCE_DIR})

link_directories(${CMAKE_CURRENT_SOURCE_DIR}/lib)

#get_target_property(OUT ${PROJECT_NAME} LINK_LIBRARIES)
#message(STATUS ${OUT})



