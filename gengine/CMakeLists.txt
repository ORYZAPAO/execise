# 各ディレクトリにCMakeLists.txtを作る

# ------------------------------------------
# ${PROJECT_HOME}/
#   ./CMakeLists.txt(1) <- new
#   ./main.cpp
#   ./mod1.hpp
#   ./mod1/
#      CMakeLists.txt(2) <- new
#      func1.cpp
#      func2.cpp
#   ./mod2.hpp
#   ./mod2/
#      CMakeLists.txt(3) <- new
#      func1.cpp
#      func2.cpp
# 
# ------------------------------------------
# -- ./CMakeLists.txt(1)
# ------------------------------------------
# cmake_minimum_required(VERSION 2.8)
# add_subdirectory(mod1)                # <- new
# add_subdirectory(mod2)                # <- new
# add_executable(Main main.cpp)
# target_link_libraries(Main Mod1 Mod2) # <- new
#
# ------------------------------------------
# -- ./mod1/CMakeLists.txt(2)
# --   Generate Library 'Mod1'
# ------------------------------------------
# cmake_minimum_required(VERSION 2.8)
# add_library(Mod1 STATIC 
#   func1.cpp
#   func2.cpp
# )
#
# ------------------------------------------
# -- ./mod2/CMakeLists.txt(3)
# --   Generate Library 'Mod2'
# ------------------------------------------ 
# cmake_minimum_required(VERSION 2.8)
# add_library(Mod2 STATIC
#   func1.cpp
#   func2.cpp
# )
project(gengine)

cmake_minimum_required(VERSION 2.8)
#add_subdirectory(mod1)                # <- new
#add_subdirectory(mod2)                # <- new
#
#execute_process( 外部コマンドを呼び出す
#        COMMAND make -f exec_flex.mak 
#        WORKING_DIRECTORY lex)
#
add_executable(gengine main.cpp)
add_definitions("-Wall -g") 


# OpenGL、Boost、SDL2ライブラリを検索
find_package(PkgConfig)
find_package(Boost REQUIRED COMPONENTS system iostreams filesystem)
#find_package(SDL2 REQUIRED sdl2)
#find_package(SDL2_image REQUIRED SDL2_image)

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


set(LINK_OPT "")
if(WIN32)
  message("WIN32")
elseif(UNIX)
  if(APPLE)
    message("APPLE")
    set(LINK_OPT "-L /usr/local/lib")
  else()
    message("UNIX/LINUX")
  endif()
endif()

target_link_libraries(
  gengine
  ${LINK_OPT}
  ${SDL2_LIBRARIES}
  ${SDL2IMAGE_LIBRARY} SDL2_image
  ) 
