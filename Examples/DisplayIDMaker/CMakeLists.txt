set(displayidmaker_SRCS
    main.cpp
)
find_package(Qt6 REQUIRED COMPONENTS Core Widgets Test Qml Quick)

add_executable(displayidmaker ${displayidmaker_SRCS})

target_link_libraries(displayidmaker
    Qt6::Core
    systememulator
    displayid
)
