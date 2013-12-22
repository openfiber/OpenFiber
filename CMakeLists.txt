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
    # Основные файлы
    src/main.cpp
    src/mainwindow.cpp

    # 3rdparty/SUNDIALS/
    src/3rdparty/SUNDIALS/src/cvode/cvode.c
    src/3rdparty/SUNDIALS/src/cvode/cvode_band.c
    src/3rdparty/SUNDIALS/src/cvode/cvode_bandpre.c
    src/3rdparty/SUNDIALS/src/cvode/cvode_bbdpre.c
    src/3rdparty/SUNDIALS/src/cvode/cvode_dense.c
    src/3rdparty/SUNDIALS/src/cvode/cvode_diag.c
    src/3rdparty/SUNDIALS/src/cvode/cvode_direct.c
    src/3rdparty/SUNDIALS/src/cvode/cvode_io.c
    src/3rdparty/SUNDIALS/src/cvode/cvode_spbcgs.c
    src/3rdparty/SUNDIALS/src/cvode/cvode_spgmr.c
    src/3rdparty/SUNDIALS/src/cvode/cvode_spils.c
    src/3rdparty/SUNDIALS/src/cvode/cvode_sptfqmr.c

    src/3rdparty/SUNDIALS/src/ida/ida.c
    src/3rdparty/SUNDIALS/src/ida/ida_band.c
    src/3rdparty/SUNDIALS/src/ida/ida_bbdpre.c
    src/3rdparty/SUNDIALS/src/ida/ida_dense.c
    src/3rdparty/SUNDIALS/src/ida/ida_direct.c
    src/3rdparty/SUNDIALS/src/ida/ida_ic.c
    src/3rdparty/SUNDIALS/src/ida/ida_io.c
    src/3rdparty/SUNDIALS/src/ida/ida_spbcgs.c
    src/3rdparty/SUNDIALS/src/ida/ida_spgmr.c
    src/3rdparty/SUNDIALS/src/ida/ida_spils.c
    src/3rdparty/SUNDIALS/src/ida/ida_sptfqmr.c

    src/3rdparty/SUNDIALS/src/kinsol/kinsol.c
    src/3rdparty/SUNDIALS/src/kinsol/kinsol_band.c
    src/3rdparty/SUNDIALS/src/kinsol/kinsol_bbdpre.c
    src/3rdparty/SUNDIALS/src/kinsol/kinsol_dense.c
    src/3rdparty/SUNDIALS/src/kinsol/kinsol_direct.c
    src/3rdparty/SUNDIALS/src/kinsol/kinsol_io.c
    src/3rdparty/SUNDIALS/src/kinsol/kinsol_spbcgs.c
    src/3rdparty/SUNDIALS/src/kinsol/kinsol_spgmr.c
    src/3rdparty/SUNDIALS/src/kinsol/kinsol_spils.c
    src/3rdparty/SUNDIALS/src/kinsol/kinsol_sptfqmr.c

    src/3rdparty/SUNDIALS/src/nvec_ser/nvector_serial.c

    src/3rdparty/SUNDIALS/src/sundials/sundials_band.c
    src/3rdparty/SUNDIALS/src/sundials/sundials_dense.c
    src/3rdparty/SUNDIALS/src/sundials/sundials_direct.c
    src/3rdparty/SUNDIALS/src/sundials/sundials_iterative.c
    src/3rdparty/SUNDIALS/src/sundials/sundials_math.c
    src/3rdparty/SUNDIALS/src/sundials/sundials_nvector.c
    src/3rdparty/SUNDIALS/src/sundials/sundials_spbcgs.c
    src/3rdparty/SUNDIALS/src/sundials/sundials_spgmr.c
    src/3rdparty/SUNDIALS/src/sundials/sundials_sptfqmr.c

    # solver/CoreSolver

    src/solver/CoreSolver/src/coresolver.cpp
    src/solver/CoreSolver/src/coreodesolver.cpp
)

SET(HEADERS_MOC
    # Основные файлы

    src/mainwindow.h

    # solver/CoreSolver

    src/solver/CoreSolver/src/coresolver.h


)

SET(UIS
    src/mainwindow.ui
)

SET(RESOURCES

)

# Подключаемые директории

INCLUDE_DIRECTORIES(

    # 3rdparty/SUNDIALS/

    src/3rdparty/SUNDIALS/include
    src/3rdparty/SUNDIALS/src

    # solver/CoreSolver

    src/solver/CoreSolver/src/
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


