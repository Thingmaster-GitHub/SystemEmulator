set(tmds_SRCS
    TMDSEncoder.cpp
    TMDSControler.cpp
    TMDSEncoder.cpp
    TMDSDecoder.cpp
    TMDSComunicator.cpp
    TMDSTransmiter.cpp
    TMDSReceiver.cpp
)
find_package(Qt6 REQUIRED COMPONENTS Core Widgets Test Qml Quick)
add_library(tmds STATIC ${tmds_SRCS})
target_link_libraries(tmds
    Qt6::Core
    nonio
    tmdspins
)
