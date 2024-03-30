cmake_minimum_required(VERSION 3.14)

project(game LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
# find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

add_executable(game
  main.cpp
)
#target_link_libraries(game Qt${QT_VERSION_MAJOR}::Core)
target_link_libraries(game PRIVATE Qt6::Widgets)

include(GNUInstallDirs)
install(TARGETS game
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
