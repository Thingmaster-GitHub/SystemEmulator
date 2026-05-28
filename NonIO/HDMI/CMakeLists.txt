
set(hdmi_SRCS
    HDMIIn.cpp
    HDMIOut.cpp
)
find_package(Qt6 REQUIRED COMPONENTS Core Widgets Test Qml Quick)
add_library(hdmi STATIC ${hdmi_SRCS})
target_link_libraries(hdmi
    Qt6::Core
    nonio
    hdmipins
)
