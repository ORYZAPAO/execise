# OpenGL、Boost、SDL2ライブラリを検索
#find_package(PkgConfig)
#find_package(Boost REQUIRED COMPONENTS system iostreams filesystem)

# pkg-configによるモジュールの追加
include(FindPkgConfig)
#pkg_search_module(Boost REQUIRED COMPONENTS system iostreams filesystem)
pkg_search_module(SDL2 REQUIRED sdl2)
pkg_search_module(SDL2_image REQUIRED SDL2_image)

# OpenGL、Boost、SDL2をincludeパスに設定
include_directories(SYSTEM
 ${Boost_INCLUDE_DIRS}
 ${SDL2_INCLUDE_DIRS}
 ${SDL2IMAGE_INCLUDE_DIRS}
 )
#include_directories(
#  ${CMAKE_CURRENT_SOURCE_DIR}/include/)

add_library(src STATIC
  surface.cpp
  init.cpp
)
