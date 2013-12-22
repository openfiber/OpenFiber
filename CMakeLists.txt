PROJECT(OpenFiber)

# Минимальная требуемая версия CMake

CMAKE_MINIMUM_REQUIRED(VERSION 2.8.9)

# Некоторые макросы и функции Cmake

INCLUDE(${CMAKE_SOURCE_DIR}/cmake/common.cmake)

# Инициализация проекта

INITIALISE_PROJECT()

# Версия OpenFiber

SET(SNAPSHOT ON)

SET(VERSION_MAJOR 0)
SET(VERSION_MINOR 0)
SET(VERSION_PATCH 0)

IF(SNAPSHOT)
    TRY_RUN(DATE_RUN DATE_COMPILE
            ${CMAKE_BINARY_DIR} ${CMAKE_SOURCE_DIR}/cmake/date.c
            RUN_OUTPUT_VARIABLE DATE)

    SET(VERSION ${DATE})
ELSE()
    SET(VERSION ${VERSION_MAJOR}.${VERSION_MINOR})

    IF(NOT ${VERSION_PATCH} EQUAL 0)
        SET(VERSION ${VERSION}.${VERSION_PATCH})
    ENDIF()
ENDIF()

FILE(WRITE ${CMAKE_BINARY_DIR}/version.txt ${VERSION})

# Файлы, которые составляют GUI версию  OpenFiber

SET(SOURCES
    src/main.cpp
    src/mainwindow.cpp
)

SET(HEADERS_MOC
    src/mainwindow.h
)

SET(UIS
    src/mainwindow.ui
)

SET(RESOURCES

)

# Подключаемые директории

INCLUDE_DIRECTORIES(

)

# Сборка GUI версии OpenFiber

QT5_WRAP_CPP(SOURCES_MOC ${HEADERS_MOC})
QT5_WRAP_UI(SOURCES_UIS ${UIS})
QT5_ADD_RESOURCES(SOURCES_RCS ${RESOURCES})

ADD_EXECUTABLE(${PROJECT_NAME} WIN32 MACOSX_BUNDLE
    ${SOURCES}
    ${SOURCES_MOC}
    ${SOURCES_UIS}
    ${SOURCES_RCS}
)

IF(APPLE)
    SET(QT_MODULES_EXTRAS MacExtras)
ELSE()
    SET(QT_MODULES_EXTRAS)
ENDIF()

QT5_USE_MODULES(${PROJECT_NAME}
    ${QT_MODULES_EXTRAS}
    Concurrent
    Help
    Network
    PrintSupport
    Svg
    WebKitWidgets
    Widgets
    Xml
)

IF(WIN32)
    TARGET_LINK_LIBRARIES(${PROJECT_NAME}
        ${Qt5Core_QTMAIN_LIBRARIES}
    )
ENDIF()

# Дополнительные параметры настройки компилятора и компоновщика

ADD_DEFINITIONS(-D${PROJECT_NAME}_MAIN)

SET_TARGET_PROPERTIES(${PROJECT_NAME} PROPERTIES
    LINK_FLAGS "${LINK_FLAGS_PROPERTIES}"
)


