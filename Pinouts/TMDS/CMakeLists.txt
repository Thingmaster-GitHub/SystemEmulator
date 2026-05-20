set(tmdspins_SRCS
    TMDS.cpp
)
find_package(Qt6 REQUIRED COMPONENTS Core Widgets Test Qml Quick)
add_library(tmdspins STATIC ${tmdspins_SRCS})
target_link_libraries(tmdspins
    Qt6::Core
    pinouts
)
