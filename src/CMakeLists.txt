find_package(Qt4 REQUIRED)

include_directories(${QT_INCLUDES} ${CMAKE_CURRENT_BINARY_DIR})

set(mmmc_SRCS mmmc.cpp main.cpp)
qt4_automoc(${mmmc_SRCS})
add_executable(mmmc ${mmmc_SRCS})
target_link_libraries(mmmc ${QT_QTCORE_LIBRARY} ${QT_QTGUI_LIBRARY})
install(TARGETS mmmc RUNTIME DESTINATION bin)
