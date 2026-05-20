set(hdmipins_SRCS
    HDMI.cpp
)
find_package(Qt6 REQUIRED COMPONENTS Core Widgets Test Qml Quick)
add_library(hdmipins STATIC ${hdmipins_SRCS})
target_link_libraries(tmdspins
    Qt6::Core
    pinouts
)
