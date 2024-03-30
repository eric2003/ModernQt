cmake_minimum_required(VERSION 3.14)

project(game LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)
find_package(Qt6 REQUIRED COMPONENTS Multimedia)

add_executable(game
  main.cpp
  player.h player.cpp
  bullet.h bullet.cpp
  enemy.h enemy.cpp
  game.h game.cpp
  score.h score.cpp
  health.h health.cpp
  res.qrc
)

target_link_libraries(game PRIVATE Qt6::Widgets)
target_link_libraries(game PRIVATE Qt6::Multimedia)

include(GNUInstallDirs)
install(TARGETS game
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
