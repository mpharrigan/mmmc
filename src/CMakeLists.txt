find_package(Qt5Core REQUIRED)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5Multimedia REQUIRED)
find_package(Taglib REQUIRED)


include_directories(${Qt5Core_INCLUDE_DIRS} ${Qt5Widgets_INCLUDE_DIRS} ${Qt5Multimedia_INCLUDE_DIRS} ${CMAKE_CURRENT_BINARY_DIR})

set(mmmc_SRCS mainwidget.cpp song.cpp music_model.cpp mmmc.cpp main.cpp)
set(CMAKE_AUTOMOC ON)
add_executable(mmmc ${mmmc_SRCS})


target_link_libraries(mmmc ${TAGLIB_LIBRARIES} Qt5::Core Qt5::Widgets Qt5::Multimedia)
install(TARGETS mmmc RUNTIME DESTINATION bin)
