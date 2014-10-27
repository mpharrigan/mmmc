find_package(Qt5Widgets REQUIRED)
find_package(Qt5Multimedia REQUIRED)
find_package(Taglib REQUIRED)

set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

add_subdirectory(config)

add_executable(mmmc library.cpp mainwidget.cpp song.cpp music_model.cpp mmmc.cpp main.cpp)
qt5_use_modules(mmmc Core Widgets Multimedia)

target_link_libraries(mmmc mmmc_config ${TAGLIB_LIBRARIES})

