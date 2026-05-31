set(displayid_SRCS
    DisplayIDData.cpp
    BlockProductIdentification.cpp
)
find_package(Qt6 REQUIRED COMPONENTS Core Widgets Test Qml Quick)
add_library(displayid STATIC ${displayid_SRCS})
target_link_libraries(displayid
    Qt6::Core
)
