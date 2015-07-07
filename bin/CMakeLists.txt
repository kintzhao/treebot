link_directories(${LIBRARY_OUTPUT_PATH})

# examples
add_executable(simple ${AR_SOURCE_DIR}/sample/simple/main.cpp)
target_link_libraries(simple ARToolKitPlus)

add_executable(multi ${AR_SOURCE_DIR}/sample/multi/main.cpp)
target_link_libraries(multi ARToolKitPlus)

# tools
add_executable(patt2ppm ${AR_SOURCE_DIR}/tools/patt2ppm/main.cpp)
target_link_libraries(patt2ppm ARToolKitPlus)

add_executable(ppm2patt ${AR_SOURCE_DIR}/tools/ppm2patt/main.cpp)
target_link_libraries(ppm2patt ARToolKitPlus)

set(PAT_GEN_DIR ${AR_SOURCE_DIR}/tools/IdPatGen)
add_executable(idpatgen ${PAT_GEN_DIR}/main.cpp ${PAT_GEN_DIR}/PN/Image.cpp ${PAT_GEN_DIR}/PN/ImageTool.cpp)
target_link_libraries(idpatgen ARToolKitPlus)

# test program
add_executable(test ${AR_SOURCE_DIR}/tools/test/main.cpp)
target_link_libraries(test ARToolKitPlus)

add_library(AR2         ${AR_SOURCE_DIR}/camera_calibration/class/CameraCalibrator.cpp
                        ${AR_SOURCE_DIR}/camera_calibration/class/CameraCalibrator.h
                        ${AR_SOURCE_DIR}/camera_calibration/class/GeometryTypes.hpp
                        ${AR_SOURCE_DIR}/camera_calibration/class/GeometryTypes.cpp
 )
target_link_libraries( AR2 ${OpenCV_LIBS} )


# test program
add_executable(calibrate ${AR_SOURCE_DIR}/camera_calibration/calibrate.cpp   )
target_link_libraries(calibrate ARToolKitPlus AR2  )


add_library(AR_DETECT         ${AR_SOURCE_DIR}/qr_detect/detectqrcode.cpp
                              ${AR_SOURCE_DIR}/qr_detect/detectqrcode.h )
target_link_libraries( AR_DETECT ${OpenCV_LIBS} ARToolKitPlus AR2  )


add_executable(ar_slam_main ${AR_SOURCE_DIR}/qrslam/main.cpp
                            ${AR_SOURCE_DIR}/qrslam/CameraEstimation.cpp
                            ${AR_SOURCE_DIR}/qrslam/CameraEstimation.h
)
target_link_libraries(ar_slam_main ${OpenCV_LIBS} ARToolKitPlus AR2 AR_DETECT serialportLIB )
