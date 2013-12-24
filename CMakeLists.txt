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

    # main
    src/main.cpp
    src/mainwindow.cpp
    src/settings.cpp

    # misc/Core
    src/misc/Core/src/cliutils.cpp
    src/misc/Core/src/commonwidget.cpp
    src/misc/Core/src/centralwidget.cpp

    # model
    src/model/src/cell.cpp
    src/model/src/parameters.cpp
    src/model/src/tissue.cpp
    src/model/src/runtime.cpp
    src/model/src/test_cell.cpp


    # simulation
    src/simulation/src/simulationview.cpp
    src/simulation/src/simulationworker.cpp

    # 3rdparty/SUNDIALS
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

    # 3rdparty/Qwt
    src/3rdparty/Qwt/src/qwt_abstract_legend.cpp
    src/3rdparty/Qwt/src/qwt_abstract_scale.cpp
    src/3rdparty/Qwt/src/qwt_abstract_scale_draw.cpp
    src/3rdparty/Qwt/src/qwt_abstract_slider.cpp
    src/3rdparty/Qwt/src/qwt_analog_clock.cpp
    src/3rdparty/Qwt/src/qwt_arrow_button.cpp
    src/3rdparty/Qwt/src/qwt_clipper.cpp
    src/3rdparty/Qwt/src/qwt_color_map.cpp
    src/3rdparty/Qwt/src/qwt_column_symbol.cpp
    src/3rdparty/Qwt/src/qwt_compass.cpp
    src/3rdparty/Qwt/src/qwt_compass_rose.cpp
    src/3rdparty/Qwt/src/qwt_counter.cpp
    src/3rdparty/Qwt/src/qwt_curve_fitter.cpp
    src/3rdparty/Qwt/src/qwt_date.cpp
    src/3rdparty/Qwt/src/qwt_date_scale_draw.cpp
    src/3rdparty/Qwt/src/qwt_date_scale_engine.cpp
    src/3rdparty/Qwt/src/qwt_dial.cpp
    src/3rdparty/Qwt/src/qwt_dial_needle.cpp
    src/3rdparty/Qwt/src/qwt_dyngrid_layout.cpp
    src/3rdparty/Qwt/src/qwt_event_pattern.cpp
    src/3rdparty/Qwt/src/qwt_graphic.cpp
    src/3rdparty/Qwt/src/qwt_interval.cpp
    src/3rdparty/Qwt/src/qwt_interval_symbol.cpp
    src/3rdparty/Qwt/src/qwt_knob.cpp
    src/3rdparty/Qwt/src/qwt_legend.cpp
    src/3rdparty/Qwt/src/qwt_legend_data.cpp
    src/3rdparty/Qwt/src/qwt_legend_label.cpp
    src/3rdparty/Qwt/src/qwt_magnifier.cpp
    src/3rdparty/Qwt/src/qwt_math.cpp
    src/3rdparty/Qwt/src/qwt_matrix_raster_data.cpp
    src/3rdparty/Qwt/src/qwt_null_paintdevice.cpp
    src/3rdparty/Qwt/src/qwt_painter.cpp
    src/3rdparty/Qwt/src/qwt_painter_command.cpp
    src/3rdparty/Qwt/src/qwt_panner.cpp
    src/3rdparty/Qwt/src/qwt_picker.cpp
    src/3rdparty/Qwt/src/qwt_picker_machine.cpp
    src/3rdparty/Qwt/src/qwt_pixel_matrix.cpp
    src/3rdparty/Qwt/src/qwt_plot.cpp
    src/3rdparty/Qwt/src/qwt_plot_abstract_barchart.cpp
    src/3rdparty/Qwt/src/qwt_plot_axis.cpp
    src/3rdparty/Qwt/src/qwt_plot_barchart.cpp
    src/3rdparty/Qwt/src/qwt_plot_canvas.cpp
    src/3rdparty/Qwt/src/qwt_plot_curve.cpp
    src/3rdparty/Qwt/src/qwt_plot_dict.cpp
    src/3rdparty/Qwt/src/qwt_plot_directpainter.cpp
    src/3rdparty/Qwt/src/qwt_plot_glcanvas.cpp
    src/3rdparty/Qwt/src/qwt_plot_grid.cpp
    src/3rdparty/Qwt/src/qwt_plot_histogram.cpp
    src/3rdparty/Qwt/src/qwt_plot_intervalcurve.cpp
    src/3rdparty/Qwt/src/qwt_plot_item.cpp
    src/3rdparty/Qwt/src/qwt_plot_layout.cpp
    src/3rdparty/Qwt/src/qwt_plot_legenditem.cpp
    src/3rdparty/Qwt/src/qwt_plot_magnifier.cpp
    src/3rdparty/Qwt/src/qwt_plot_marker.cpp
    src/3rdparty/Qwt/src/qwt_plot_multi_barchart.cpp
    src/3rdparty/Qwt/src/qwt_plot_panner.cpp
    src/3rdparty/Qwt/src/qwt_plot_picker.cpp
    src/3rdparty/Qwt/src/qwt_plot_rasteritem.cpp
    src/3rdparty/Qwt/src/qwt_plot_renderer.cpp
    src/3rdparty/Qwt/src/qwt_plot_rescaler.cpp
    src/3rdparty/Qwt/src/qwt_plot_scaleitem.cpp
    src/3rdparty/Qwt/src/qwt_plot_seriesitem.cpp
    src/3rdparty/Qwt/src/qwt_plot_shapeitem.cpp
    src/3rdparty/Qwt/src/qwt_plot_spectrocurve.cpp
    src/3rdparty/Qwt/src/qwt_plot_spectrogram.cpp
    src/3rdparty/Qwt/src/qwt_plot_svgitem.cpp
    src/3rdparty/Qwt/src/qwt_plot_textlabel.cpp
    src/3rdparty/Qwt/src/qwt_plot_tradingcurve.cpp
    src/3rdparty/Qwt/src/qwt_plot_xml.cpp
    src/3rdparty/Qwt/src/qwt_plot_zoneitem.cpp
    src/3rdparty/Qwt/src/qwt_plot_zoomer.cpp
    src/3rdparty/Qwt/src/qwt_point_3d.cpp
    src/3rdparty/Qwt/src/qwt_point_data.cpp
    src/3rdparty/Qwt/src/qwt_point_mapper.cpp
    src/3rdparty/Qwt/src/qwt_point_polar.cpp
    src/3rdparty/Qwt/src/qwt_raster_data.cpp
    src/3rdparty/Qwt/src/qwt_round_scale_draw.cpp
    src/3rdparty/Qwt/src/qwt_sampling_thread.cpp
    src/3rdparty/Qwt/src/qwt_scale_div.cpp
    src/3rdparty/Qwt/src/qwt_scale_draw.cpp
    src/3rdparty/Qwt/src/qwt_scale_engine.cpp
    src/3rdparty/Qwt/src/qwt_scale_map.cpp
    src/3rdparty/Qwt/src/qwt_scale_widget.cpp
    src/3rdparty/Qwt/src/qwt_series_data.cpp
    src/3rdparty/Qwt/src/qwt_slider.cpp
    src/3rdparty/Qwt/src/qwt_spline.cpp
    src/3rdparty/Qwt/src/qwt_symbol.cpp
    src/3rdparty/Qwt/src/qwt_system_clock.cpp
    src/3rdparty/Qwt/src/qwt_text.cpp
    src/3rdparty/Qwt/src/qwt_text_engine.cpp
    src/3rdparty/Qwt/src/qwt_text_label.cpp
    src/3rdparty/Qwt/src/qwt_thermo.cpp
    src/3rdparty/Qwt/src/qwt_transform.cpp
    src/3rdparty/Qwt/src/qwt_wheel.cpp
    src/3rdparty/Qwt/src/qwt_widget_overlay.cpp

    src/3rdparty/Qwt/textengines/mathml/qwt_mathml_text_engine.cpp
    src/3rdparty/Qwt/textengines/mathml/qwt_mml_document.cpp
    src/3rdparty/Qwt/textengines/mathml/qwt_mml_entity_table.cpp

    # solver/CoreSolver
    src/solver/CoreSolver/src/coresolver.cpp
    src/solver/CoreSolver/src/coreodesolver.cpp
    src/solver/CoreSolver/src/corevoisolver.cpp
    src/solver/CoreSolver/src/corenlasolver.cpp

    # solver/ForwardEulerSolver
    src/solver/ForwardEulerSolver/src/forwardeulersolver.cpp

    # solver/SecondOrderRungeKuttaSolver
    src/solver/SecondOrderRungeKuttaSolver/src/secondorderrungekuttasolver.cpp

    # solver/FourthOrderRungeKuttaSolver
    src/solver/FourthOrderRungeKuttaSolver/src/fourthorderrungekuttasolver.cpp

    # solver/CVODESolver
    src/solver/CVODESolver/src/cvodesolver.cpp

    # solver/KINSOLSolver
    src/solver/KINSOLSolver/src/kinsolsolver.cpp

)

SET(HEADERS_MOC

    # main
    src/mainwindow.h

    # misc/Core
    src/misc/Core/src/centralwidget.h

    # model
    src/model/src/cell.h
    src/model/src/parameters.h
    src/model/src/tissue.h
    src/model/src/runtime.h
    src/model/src/test_cell.h

    # simulation
    src/simulation/src/simulationview.h
    src/simulation/src/simulationworker.h

    # 3rdparty/Qwt
    src/3rdparty/Qwt/src/qwt_abstract_legend.h
    src/3rdparty/Qwt/src/qwt_abstract_scale.h
    src/3rdparty/Qwt/src/qwt_abstract_slider.h
    src/3rdparty/Qwt/src/qwt_analog_clock.h
    src/3rdparty/Qwt/src/qwt_compass.h
    src/3rdparty/Qwt/src/qwt_counter.h
    src/3rdparty/Qwt/src/qwt_dial.h
    src/3rdparty/Qwt/src/qwt_dyngrid_layout.h
    src/3rdparty/Qwt/src/qwt_knob.h
    src/3rdparty/Qwt/src/qwt_legend.h
    src/3rdparty/Qwt/src/qwt_legend_label.h
    src/3rdparty/Qwt/src/qwt_magnifier.h
    src/3rdparty/Qwt/src/qwt_panner.h
    src/3rdparty/Qwt/src/qwt_picker.h
    src/3rdparty/Qwt/src/qwt_plot.h
    src/3rdparty/Qwt/src/qwt_plot_canvas.h
    src/3rdparty/Qwt/src/qwt_plot_glcanvas.h
    src/3rdparty/Qwt/src/qwt_plot_magnifier.h
    src/3rdparty/Qwt/src/qwt_plot_panner.h
    src/3rdparty/Qwt/src/qwt_plot_picker.h
    src/3rdparty/Qwt/src/qwt_plot_renderer.h
    src/3rdparty/Qwt/src/qwt_plot_zoomer.h
    src/3rdparty/Qwt/src/qwt_sampling_thread.h
    src/3rdparty/Qwt/src/qwt_scale_widget.h
    src/3rdparty/Qwt/src/qwt_slider.h
    src/3rdparty/Qwt/src/qwt_text_label.h
    src/3rdparty/Qwt/src/qwt_thermo.h
    src/3rdparty/Qwt/src/qwt_wheel.h

    # solver/CoreSolver
    src/solver/CoreSolver/src/coresolver.h


)

SET(UIS

    # main
    src/mainwindow.ui

    # misc/Core
    src/misc/Core/src/centralwidget.ui
)

SET(RESOURCES

    # main
    res/ui.qrc
    res/common.qrc
)

# Подключаемые директории

INCLUDE_DIRECTORIES(

    # main
    src

    # model
    src/model/src


    # simulation
    src/simulation/src

    # misc/Core
    src/misc/Core/src

    # 3rdparty/SUNDIALS/
    src/3rdparty/SUNDIALS/include
    src/3rdparty/SUNDIALS/src

    # 3rdparty/Qwt
    src/3rdparty/Qwt/src
    src/3rdparty/Qwt/textengines/mathml

    # solver/CoreSolver
    src/solver/CoreSolver/src

    # solver/ForwardEulerSolver
    src/solver/ForwardEulerSolver/src

    #solver/SecondOrderRungeKuttaSolver
    src/solver/SecondOrderRungeKuttaSolver/src

    # solver/FourthOrderRungeKuttaSolver
    src/solver/FourthOrderRungeKuttaSolver/src

    # solver/CVODESolver
    src/solver/CVODESolver/src

    # solver/KINSOLSolver
    src/solver/KINSOLSolver/src
)

# Обновление файлов перевода (.ts)  и генерация файла язык (.qm),
# который будет в дальнейшем встроен в исполнительный в качестве ресурса

UPDATE_LANGUAGE_FILES(${PROJECT_NAME} TRUE)

# Сборка GUI версии OpenFiber

QT5_WRAP_CPP(SOURCES_MOC ${HEADERS_MOC})
QT5_WRAP_UI(SOURCES_UIS ${UIS})
QT5_ADD_RESOURCES(SOURCES_RCS ${RESOURCES})

ADD_EXECUTABLE(${PROJECT_NAME} WIN32
    ${SOURCES}
    ${SOURCES_MOC}
    ${SOURCES_UIS}
    ${SOURCES_RCS}
)


SET(QT_MODULES_EXTRAS)


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


