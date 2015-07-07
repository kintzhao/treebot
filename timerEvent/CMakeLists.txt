#find QT libraries

   find_package(Qt5Widgets REQUIRED)
   find_package(Qt5Core REQUIRED)
   find_package(Qt5Gui REQUIRED)
   find_package(Qt5SerialPort REQUIRED)



SET(timer_SOURCES ${treebot_SOURCE_DIR}/timerEvent/widget.cpp)
SET(timer_HEADERS ${treebot_SOURCE_DIR}/timerEvent/widget.h)
QT5_WRAP_CPP(timer_HEADERS_MOC ${timer_HEADERS})


INCLUDE_DIRECTORIES(${CMAKE_CURRENT_BINARY_DIR})

qt5_wrap_ui(timerEvent_UI_HEADERS ${treebot_SOURCE_DIR}/timerEvent/widget.ui)




#add_library(serialport ${serialport_SOURCES}  ${serialport_HEADERS_MOC}   ${serialport_HEADERS} ${timerEvent_UI_HEADERS}  )

add_executable(timer   ${treebot_SOURCE_DIR}/timerEvent/main.cpp  ${timer_SOURCES}  ${timer_HEADERS_MOC}   ${timer_HEADERS}  ${timerEvent_UI_HEADERS}  )
TARGET_LINK_LIBRARIES(timer ${Qt5Core_LIBRARIES}  ${Qt5Widgets_LIBRARIES}  ${Qt5SerialPort_LIBRARIES} CameraEstimation)

add_library(timerLIB    ${timer_HEADERS_MOC}  ${timer_SOURCES}   ${timer_HEADERS} ${timerEvent_UI_HEADERS}  )
TARGET_LINK_LIBRARIES(timerLIB ${Qt5Core_LIBRARIES}  ${Qt5Widgets_LIBRARIES}  ${Qt5SerialPort_LIBRARIES})


##这个错误是说你没有对包含有Q_Object的头文件没有生成对应的moc文件，或者是生成了moc文件，但是你没有给包含到工程中来。





