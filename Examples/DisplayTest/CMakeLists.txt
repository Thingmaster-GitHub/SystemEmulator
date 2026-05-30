set(displaytest_SRCS
    main.cpp
    MainBoard.cpp
)
find_package(Qt6 REQUIRED COMPONENTS Core Widgets Test Qml Quick)

add_executable(displaytest ${displaytest_SRCS})

target_link_libraries(displaytest
    Qt6::Core
    nonio
    pinouts
    systememulator
)
