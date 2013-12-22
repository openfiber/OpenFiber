# Определение каталога сборки

SET(PROJECT_BUILD_DIR ${CMAKE_BINARY_DIR})

IF(NOT "${CMAKE_CFG_INTDIR}" STREQUAL ".")
    SET(PROJECT_BUILD_DIR ${PROJECT_BUILD_DIR}/${CMAKE_CFG_INTDIR})
ENDIF()

#===============================================================================

MACRO(UPDATE_POLICIES)
    # Убеждаемся, что все политики CMake,
    # которые минимально необходимы CMake версии (т.е. 2.8.9) совместимы

    IF(NOT CMAKE_VERSION VERSION_LESS 2.8.11)
        CMAKE_POLICY(SET CMP0020 OLD)
    ENDIF()
ENDMACRO()

#===============================================================================

MACRO(INITIALISE_PROJECT)

#   SET(CMAKE_VERBOSE_MAKEFILE ON)
    SET(CMAKE_INCLUDE_CURRENT_DIR ON)

    # Убеждаемся в обнавленной политике

    UPDATE_POLICIES()

    # Убеждаемся в поддержке архитектуры (32-bit или 64-bit)

    IF(EXISTS ${CMAKE_SOURCE_DIR}/cmake)
        SET(ARCHITECTURE_FILENAME ${CMAKE_SOURCE_DIR}/cmake/architecture.c)
    ELSE()
        SET(ARCHITECTURE_FILENAME ${CMAKE_SOURCE_DIR}/../cmake/architecture.c)
    ENDIF()

    TRY_RUN(ARCHITECTURE_RUN ARCHITECTURE_COMPILE
            ${CMAKE_BINARY_DIR} ${ARCHITECTURE_FILENAME}
            RUN_OUTPUT_VARIABLE ARCHITECTURE)

    IF(NOT ${ARCHITECTURE} EQUAL 32 AND NOT ${ARCHITECTURE} EQUAL 64)
        MESSAGE(FATAL_ERROR "OpenFiber can only be built in 32-bit or 64-bit mode...")
    ENDIF()

    # По умолчанию, собирается релизная версия выпуска OpenFiber, если не будет
    # явно прописана отладочной версии

    IF("${CMAKE_BUILD_TYPE}" STREQUAL "Debug")
        MESSAGE("Building a ${ARCHITECTURE}-bit debug version...")

        SET(RELEASE_MODE OFF)
    ELSE()
        MESSAGE("Building a ${ARCHITECTURE}-bit release version...")

        SET(RELEASE_MODE ON)
    ENDIF()

    # Необходимые пакеты

    FIND_PACKAGE(Qt5Widgets REQUIRED)

    # Отслеживание некоторой информации о Qt

    SET(QT_BINARY_DIR ${_qt5Widgets_install_prefix}/bin)
    SET(QT_LIBRARY_DIR ${_qt5Widgets_install_prefix}/lib)
    SET(QT_PLUGINS_DIR ${_qt5Widgets_install_prefix}/plugins)
    SET(QT_VERSION_MAJOR ${Qt5Widgets_VERSION_MAJOR})
    SET(QT_VERSION_MINOR ${Qt5Widgets_VERSION_MINOR})
    SET(QT_VERSION_PATCH ${Qt5Widgets_VERSION_PATCH})

    # Некоторые основные настройки сборки проекта

ENDMACRO()
