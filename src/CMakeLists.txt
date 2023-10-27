# Reactive_flux_correlation_function

add_executable(flux_correlation
        main.cpp
)

target_link_libraries(flux_correlation
        ${Boost_LIBRARIES}
        ${Boost_SYSTEM_LIBRARY}
        ${Boost_PROGRAM_OPTIONS_LIBRARY}
        PkgConfig::FFTW
)

install(TARGETS flux_correlation
        DESTINATION bin
)
