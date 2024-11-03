cmake_minimum_required(VERSION 3.5)

project(qtTrans VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets LinguistTools)  #jimbo tr
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets LinguistTools) #jimbo tr

set(TS_FILES ${CMAKE_SOURCE_DIR}/qtTrans_zh_CN.ts) #jimbo tr
qt_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES}) #jimbo tr

#jimbo tr
set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
        ${TS_FILES}
)

qt_add_executable(qtTrans
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
)


target_link_libraries(qtTrans PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

set_target_properties(qtTrans PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

install(TARGETS qtTrans
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(qtTrans)
endif()

#jimbo tr
find_program(LUPDATE_EXECUTABLE lupdate)
find_program(LRELEASE_EXECUTABLE lrelease)
message("lupdate:" ${LUPDATE_EXECUTABLE})
message("lrelease: "${LRELEASE_EXECUTABLE})
execute_process(
    COMMAND ${LUPDATE_EXECUTABLE} -recursive ${CMAKE_SOURCE_DIR} -ts ${TS_FILES}
)
execute_process(
    COMMAND ${LRELEASE_EXECUTABLE} ${TS_FILES}
)

add_custom_command(
    TARGET qtTrans
    POST_BUILD
    COMMAND  "${CMAKE_COMMAND}" -E copy "${CMAKE_SOURCE_DIR}/qtTrans_zh_CN.qm" "${qtTrans_BINARY_DIR}/qtTrans_zh_CN.qm"
)

