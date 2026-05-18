set(textinverter_SRCS
    main.cpp
    MainBoard.cpp
)
find_package(Qt6 REQUIRED COMPONENTS Core Widgets Test Qml Quick)

add_executable(textinverter ${textinverter_SRCS})

target_link_libraries(textinverter
    Qt6::Core
    tmds
    nonio
    pinouts
    systememulator
)
