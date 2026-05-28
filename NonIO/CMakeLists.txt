add_subdirectory(TMDS/)
add_subdirectory(DisplayID/)
add_subdirectory(HDMI/)
set(nonio_SRCS
        NonIOComponent.cpp
)
find_package(Qt6 REQUIRED COMPONENTS Core Widgets Test Qml Quick)

add_library(nonio STATIC ${nonio_SRCS})
target_link_libraries(nonio
    Qt6::Core
)


