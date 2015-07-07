#find QT libraries

find_package(Qt5Widgets REQUIRED)
find_package(Qt5Core REQUIRED)
find_package(Qt5Gui REQUIRED)
find_package(Qt5SerialPort REQUIRED)



SET(serialport_SOURCES ${treebot_SOURCE_DIR}/serialport/main.cpp ${treebot_SOURCE_DIR}/serialport/serialport.cpp)
SET(serialport_HEADERS ${treebot_SOURCE_DIR}/serialport/serialport.h)
QT5_WRAP_CPP(serialport_HEADERS_MOC ${serialport_HEADERS})


#    ADD_DEFINITIONS(${Qt5Core_DEFINITIONS})
#   add_definitions(${Qt5Widgets_DEFINITIONS})
#   add_definitions(${Qt5SerialPort_DEFINITIONS})
#   INCLUDE_DIRECTORIES(${Qt5Widgets_INCLUDE_DIRS} ${Qt5Core_INCLUDE_DIRS} ${Qt5SerialPort_INCLUDE_DIRS})
#   INCLUDE_DIRECTORIES(${CMAKE_CURRENT_BINARY_DIR})

qt5_wrap_ui(UI_HEADERS ${treebot_SOURCE_DIR}/serialport/serialport.ui)


message(" Qt5Widgets_INCLUDE_DIRS =${Qt5Widgets_INCLUDE_DIRS}     ")
message(" Qt5Widgets_LIBRARIES =${Qt5Widgets_LIBRARIES}   ")

message(" Qt5Core_INCLUDE_DIRS =${Qt5Core_INCLUDE_DIRS}   ")
message(" Qt5Core_LIBRARIES =${Qt5Core_LIBRARIES}         ")

message(" Qt5SerialPort_INCLUDE_DIRS =${Qt5SerialPort_INCLUDE_DIRS}")
message(" Qt5SerialPort_LIBRARIES =${Qt5SerialPort_LIBRARIES}")

#add_library(serialport ${serialport_SOURCES}  ${serialport_HEADERS_MOC}   ${serialport_HEADERS} ${UI_HEADERS}  )

add_executable(serialport ${serialport_SOURCES}  ${serialport_HEADERS_MOC}   ${serialport_HEADERS} ${UI_HEADERS}  )
TARGET_LINK_LIBRARIES(serialport ${Qt5Core_LIBRARIES}  ${Qt5Widgets_LIBRARIES}  ${Qt5SerialPort_LIBRARIES})

add_library(serialportLIB ${treebot_SOURCE_DIR}/serialport/serialport.cpp  ${serialport_HEADERS_MOC}   ${serialport_HEADERS} ${UI_HEADERS}  )
TARGET_LINK_LIBRARIES(serialportLIB ${Qt5Core_LIBRARIES}  ${Qt5Widgets_LIBRARIES}  ${Qt5SerialPort_LIBRARIES})


##这个错误是说你没有对包含有Q_Object的头文件没有生成对应的moc文件，或者是生成了moc文件，但是你没有给包含到工程中来。





