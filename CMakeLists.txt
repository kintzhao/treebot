cmake_minimum_required(VERSION 2.8)
project(treebot)
find_package( OpenCV REQUIRED )
#  set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)
#  set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)
#  set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)
#
#option(ARTK_BUILD_EXAMPLES "Build sample programs and utilies" TRUE)
option(ARTK_USE_BOOST "Compile with boost (OpenCV calibration file support)" FALSE)

#option(WINDOWS_H_ "Build sample programs and utilies" TRUE)
#option(UNIX_H_ "Build sample programs and utilies" TRUE)

if(WIN32)
	add_definitions(-D_CRT_SECURE_NO_WARNINGS -DAR_LIBRARY)
        ADD_DEFINITIONS(-DWINDOWS_H_)
endif()

if(UNIX)
        ADD_DEFINITIONS(-DUNIX_H_)
endif()





if (CMAKE_BUILD_TYPE STREQUAL "")
  set(CMAKE_BUILD_TYPE "release" CACHE STRING "" FORCE)
endif ()

if(ARTK_USE_BOOST)
    add_definitions(-DAR_WITH_BOOST)
endif(ARTK_USE_BOOST)

set(treebot_SOURCE_DIR ${PROJECT_SOURCE_DIR})
include_directories(${treebot_SOURCE_DIR}/include)
#include_directories(C:/opencv/build/include/opencv2 C:/opencv/build/include/opencv C:/opencv/build/include )

message("OpenCV_INCLUDE_DIRS = ${OpenCV_INCLUDE_DIRS}")


# ARToolkitPlus core files (headers and sources)
file(GLOB_RECURSE HEADERS_AR ${treebot_SOURCE_DIR}/include/ARToolKitPlus/*.h
                            # ${treebot_SOURCE_DIR}/camera_calibration/class/*.h
)
file(GLOB SOURCES_AR
        ${treebot_SOURCE_DIR}/src/*.cpp
        ${treebot_SOURCE_DIR}/src/core/*.cpp
        ${treebot_SOURCE_DIR}/src/extra/*.cpp
        ${treebot_SOURCE_DIR}/src/librpp/*.cpp
       # ${treebot_SOURCE_DIR}/camera_calibration/class/*.cpp
	)

message("OpenCV_LIBS = ${OpenCV_LIBS}")
#link_directories(C:/opencv/MinGW/lib)
#link_directories(C:/opencv/build/x86/vc12/lib)

#set(OPENCV_LIB C:/opencv/MinGW/lib)

add_library(ARToolKitPlus SHARED ${HEADERS_AR} ${SOURCES_AR}  )


#if(ARTK_BUILD_EXAMPLES)
 #   add_subdirectory(bin/)
#endif(ARTK_BUILD_EXAMPLES)

#add_subdirectory(serialport/)
# add_subdirectory(timerEvent/)


#find QT libraries
find_package(Qt5Widgets REQUIRED)
find_package(Qt5Core REQUIRED)
find_package(Qt5Gui REQUIRED)
find_package(Qt5SerialPort REQUIRED)

SET(serialport_SOURCES ${treebot_SOURCE_DIR}/serialport/serialport.cpp)
SET(serialport_HEADERS ${treebot_SOURCE_DIR}/serialport/serialport.h)
QT5_WRAP_CPP(serialport_HEADERS_MOC ${serialport_HEADERS})

qt5_wrap_ui(UI_HEADERS ${treebot_SOURCE_DIR}/serialport/serialport.ui)
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_BINARY_DIR})

link_directories(${LIBRARY_OUTPUT_PATH})

add_library(          serialportLIB     ${serialport_SOURCES}  ${serialport_HEADERS_MOC}   ${serialport_HEADERS} ${UI_HEADERS}  )
TARGET_LINK_LIBRARIES(serialportLIB     ${Qt5Core_LIBRARIES}  ${Qt5Widgets_LIBRARIES}  ${Qt5SerialPort_LIBRARIES})


add_library(camera_calibration          ${treebot_SOURCE_DIR}/camera_calibration/class/CameraCalibrator.cpp
                                        ${treebot_SOURCE_DIR}/camera_calibration/class/CameraCalibrator.h
                                        ${treebot_SOURCE_DIR}/camera_calibration/class/GeometryTypes.hpp
                                        ${treebot_SOURCE_DIR}/camera_calibration/class/GeometryTypes.cpp
            )
target_link_libraries( camera_calibration ${OpenCV_LIBS} )

add_library(ar_detect         ${treebot_SOURCE_DIR}/qr_detect/detectqrcode.cpp
                              ${treebot_SOURCE_DIR}/qr_detect/detectqrcode.h )
target_link_libraries( ar_detect ${OpenCV_LIBS} ARToolKitPlus camera_calibration  )


add_executable(calibrate          ${treebot_SOURCE_DIR}/camera_calibration/calibrate.cpp   )
target_link_libraries(calibrate    ARToolKitPlus camera_calibration  )

add_executable(ar_slam_main         ${treebot_SOURCE_DIR}/qrslam/main.cpp
                                    ${treebot_SOURCE_DIR}/qrslam/CameraEstimation.cpp
                                     ${treebot_SOURCE_DIR}/qrslam/CameraEstimation.h
)
target_link_libraries(ar_slam_main   ${OpenCV_LIBS} ARToolKitPlus camera_calibration ar_detect serialportLIB )


SET(timer_SOURCES ${treebot_SOURCE_DIR}/timerEvent/widget.cpp)
SET(timer_HEADERS ${treebot_SOURCE_DIR}/timerEvent/widget.h)
QT5_WRAP_CPP(timer_HEADERS_MOC ${timer_HEADERS})

INCLUDE_DIRECTORIES(${CMAKE_CURRENT_BINARY_DIR})
qt5_wrap_ui(timerEvent_UI_HEADERS ${treebot_SOURCE_DIR}/timerEvent/widget.ui)


add_library(CameraEstimation        ${treebot_SOURCE_DIR}/qrslam/CameraEstimation.cpp
                                    ${treebot_SOURCE_DIR}/qrslam/CameraEstimation.h )
target_link_libraries( CameraEstimation ${OpenCV_LIBS} ARToolKitPlus camera_calibration ar_detect )



   add_executable(timer   ${treebot_SOURCE_DIR}/timerEvent/main.cpp
                          # ${treebot_SOURCE_DIR}/qrslam/CameraEstimation.cpp
                          # ${treebot_SOURCE_DIR}/qrslam/CameraEstimation.h
                           ${timer_SOURCES}  ${timer_HEADERS_MOC}   ${timer_HEADERS}  ${timerEvent_UI_HEADERS}
    )

   TARGET_LINK_LIBRARIES(timer ${Qt5Core_LIBRARIES}  ${Qt5Widgets_LIBRARIES}  ${Qt5Gui_LIBRARIES}  ${Qt5SerialPort_LIBRARIES}
                      CameraEstimation
    )


#add_library(timerLIB    ${timer_HEADERS_MOC}  ${timer_SOURCES}   ${timer_HEADERS} ${timerEvent_UI_HEADERS}
#                                    ${treebot_SOURCE_DIR}/qrslam/CameraEstimation.cpp
#                                     ${treebot_SOURCE_DIR}/qrslam/CameraEstimation.h
#    )
#TARGET_LINK_LIBRARIES(timerLIB ${Qt5Core_LIBRARIES}  ${Qt5Widgets_LIBRARIES}  ${Qt5SerialPort_LIBRARIES}
#                                ${OpenCV_LIBS} ARToolKitPlus camera_calibration ar_detect  )
#



######################### main_src ######################
#
#   include_directories(${treebot_SOURCE_DIR}/main_src)
#
#   SET(main_src_SOURCES ${treebot_SOURCE_DIR}/main_src/mainwindow.cpp
#                    ${treebot_SOURCE_DIR}/main_src/serialport.cpp
#                    ${treebot_SOURCE_DIR}/main_src/util.cpp
#                    ${treebot_SOURCE_DIR}/main_src/slidervelocity.cpp
#     )
#
#   SET(main_src_HEADERS ${treebot_SOURCE_DIR}/main_src/mainwindow.h
#                    ${treebot_SOURCE_DIR}/main_src/serialport.h
#                    ${treebot_SOURCE_DIR}/main_src/treerobotconstant.h
#                    ${treebot_SOURCE_DIR}/main_src/slidervelocity.h
#                    ${treebot_SOURCE_DIR}/main_src/util.h
#   )
#
#   QT5_WRAP_CPP(main_src_HEADERS_MOC ${main_src_HEADERS})
#
#
#   #qt5_wrap_ui(main_src_UI_HEADERS ${treebot_SOURCE_DIR}/main_src/mainwindow.ui)
#
#   qt5_wrap_ui(main_src_UI_HEADERS ${treebot_SOURCE_DIR}/main_src/mainwindow.ui)
#
#   #qt5_wrap_ui(outfiles inputfile ... OPTIONS ...)
#   # ui_XX.h files are generated in the build directory ${CMAKE_CURRENT_BINARY_DIR}.
#   INCLUDE_DIRECTORIES(${CMAKE_CURRENT_BINARY_DIR})
#
#   add_executable(treebot   ${treebot_SOURCE_DIR}/main_src/main.cpp
#                          # ${treebot_SOURCE_DIR}/qrslam/CameraEstimation.cpp
#                          # ${treebot_SOURCE_DIR}/qrslam/CameraEstimation.h
#                           ${main_src_SOURCES}  ${main_src_HEADERS_MOC}   ${main_src_HEADERS}  ${main_src_UI_HEADERS}
#    )
#
#   TARGET_LINK_LIBRARIES(treebot ${Qt5Core_LIBRARIES}  ${Qt5Widgets_LIBRARIES}  ${Qt5Gui_LIBRARIES}  ${Qt5SerialPort_LIBRARIES}
#                         CameraEstimation
#    )
#
#
#

#   ######################### treeRobot######################
#
#   include_directories(${treebot_SOURCE_DIR}/treeRobot)
#
#   SET(treeRobot_SOURCES ${treebot_SOURCE_DIR}/treeRobot/mainwindow.cpp
#                    ${treebot_SOURCE_DIR}/treeRobot/serialport.cpp
#                    ${treebot_SOURCE_DIR}/treeRobot/util.cpp
#                    ${treebot_SOURCE_DIR}/treeRobot/slidervelocity.cpp
#     )
#
#   SET(treeRobot_HEADERS ${treebot_SOURCE_DIR}/treeRobot/mainwindow.h
#                    ${treebot_SOURCE_DIR}/treeRobot/serialport.h
#                    ${treebot_SOURCE_DIR}/treeRobot/treerobotconstant.h
#                    ${treebot_SOURCE_DIR}/treeRobot/util.h
#                    ${treebot_SOURCE_DIR}/treeRobot/slidervelocity.h
#   )
#
#   QT5_WRAP_CPP(treeRobot_HEADERS_MOC ${treeRobot_HEADERS})
#
#
#   qt5_wrap_ui(treeRobot_UI_HEADERS ${treebot_SOURCE_DIR}/treeRobot/mainwindow.ui)
#
#   #qt5_wrap_ui(outfiles inputfile ... OPTIONS ...)
#   # ui_XX.h files are generated in the build directory ${CMAKE_CURRENT_BINARY_DIR}.
#   INCLUDE_DIRECTORIES(${CMAKE_CURRENT_BINARY_DIR})
#
#   add_executable(treeRobot_run   ${treebot_SOURCE_DIR}/treeRobot/main.cpp
#                            ${treeRobot_SOURCES}  ${treeRobot_HEADERS_MOC}
#                            ${treeRobot_HEADERS}  ${treeRobot_UI_HEADERS}
#                 )
#
#   TARGET_LINK_LIBRARIES(treeRobot_run     ${Qt5Core_LIBRARIES}  ${Qt5Widgets_LIBRARIES}
#                                     ${Qt5Gui_LIBRARIES}  ${Qt5SerialPort_LIBRARIES}
#                                      CameraEstimation
#                         )
#

######################### treeRobot######################

include_directories(${treebot_SOURCE_DIR}/treeRobot3)

SET(treeRobot3_SOURCES ${treebot_SOURCE_DIR}/treeRobot3/mainwindow.cpp
                 ${treebot_SOURCE_DIR}/treeRobot3/serialport.cpp
                 ${treebot_SOURCE_DIR}/treeRobot3/util.cpp
                 ${treebot_SOURCE_DIR}/treeRobot3/slidervelocity.cpp
  )

SET(treeRobot3_HEADERS ${treebot_SOURCE_DIR}/treeRobot3/mainwindow.h
                 ${treebot_SOURCE_DIR}/treeRobot3/serialport.h
                 ${treebot_SOURCE_DIR}/treeRobot3/treerobotconstant.h
                 ${treebot_SOURCE_DIR}/treeRobot3/util.h
                 ${treebot_SOURCE_DIR}/treeRobot3/slidervelocity.h
)

QT5_WRAP_CPP(treeRobot3_HEADERS_MOC ${treeRobot3_HEADERS})


qt5_wrap_ui(treeRobot3_UI_HEADERS ${treebot_SOURCE_DIR}/treeRobot3/mainwindow.ui)

#qt5_wrap_ui(outfiles inputfile ... OPTIONS ...)
# ui_XX.h files are generated in the build directory ${CMAKE_CURRENT_BINARY_DIR}.
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_BINARY_DIR})

add_executable(treeRobot3_run   ${treebot_SOURCE_DIR}/treeRobot3/main.cpp
                         ${treeRobot3_SOURCES}  ${treeRobot3_HEADERS_MOC}
                         ${treeRobot3_HEADERS}  ${treeRobot3_UI_HEADERS}
              )

TARGET_LINK_LIBRARIES(treeRobot3_run     ${Qt5Core_LIBRARIES}  ${Qt5Widgets_LIBRARIES}
                                  ${Qt5Gui_LIBRARIES}  ${Qt5SerialPort_LIBRARIES}
                                   CameraEstimation
                      )

