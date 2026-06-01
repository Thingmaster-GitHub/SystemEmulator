set(displayid_SRCS
    DisplayIDVariableLengthStructure.h
    BlockProductIdentification.cpp
    DisplayIDTable.cpp
)
find_package(Qt6 REQUIRED COMPONENTS Core Widgets Test Qml Quick)
add_library(displayid STATIC ${displayid_SRCS})
target_link_libraries(displayid
    Qt6::Core
)
