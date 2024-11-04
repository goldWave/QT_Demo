cmake_minimum_required(VERSION 3.5)

project(vs_qtTrans VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_MESSAGE_LOG_LEVEL "STATUS")

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets LinguistTools)  #jimbo tr
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets LinguistTools) #jimbo tr

set(TS_FILES ${CMAKE_SOURCE_DIR}/${PROJECT_NAME}_zh_CN.ts) #jimbo tr
qt_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES}) #jimbo tr

#jimbo tr
set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
        ${TS_FILES}
)

add_executable(${PROJECT_NAME} WIN32 ${PROJECT_SOURCES})


target_link_libraries(${PROJECT_NAME} PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

set_target_properties(${PROJECT_NAME} PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
    RUNTIME_OUTPUT_DIRECTORY_DEBUG $ENV{BIN_DIR}
    OUTPUT_NAME vs_qtTrans
)

install(TARGETS ${PROJECT_NAME}
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(${PROJECT_NAME})
endif()

#jimbo tr
find_program(LUPDATE_EXECUTABLE lupdate)
find_program(LRELEASE_EXECUTABLE lrelease)
message("lupdate:" ${LUPDATE_EXECUTABLE})
message("lrelease: "${LRELEASE_EXECUTABLE})
execute_process(
    COMMAND ${LUPDATE_EXECUTABLE} -recursive ${CMAKE_SOURCE_DIR} -ts ${TS_FILES}
)

find_program(WINDEPLOY_EXECUTABLE windeployqt)
add_custom_command(
    TARGET ${PROJECT_NAME}
    POST_BUILD
    COMMAND ${WINDEPLOY_EXECUTABLE} ${CMAKE_SOURCE_DIR}/bin  #拷贝qt等动态库到 bin 目录
    COMMAND  ${LRELEASE_EXECUTABLE} ${TS_FILES} # ts -> qm 文件到 source 目录
    COMMAND  "${CMAKE_COMMAND}" -E copy "${CMAKE_SOURCE_DIR}/${PROJECT_NAME}_zh_CN.qm" ${CMAKE_SOURCE_DIR}/bin # qm 从source 目录到 qm 目录
)