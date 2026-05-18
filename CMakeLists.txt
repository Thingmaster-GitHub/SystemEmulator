cmake_minimum_required(VERSION 3.16)


set(systememulator_SRCS
    MachineControler.cpp
)
project(systememulator LANGUAGES CXX)
add_subdirectory(Pinouts/)
add_subdirectory(NonIO/)
add_subdirectory(Examples/)
find_package(Qt6 REQUIRED COMPONENTS Core Widgets Test Qml Quick)
add_library(systememulator STATIC ${systememulator_SRCS})
install(TARGETS systememulator RUNTIME DESTINATION bin)

target_link_libraries(systememulator
    pinouts
    nonio
    examples
    Qt6::Core
)
