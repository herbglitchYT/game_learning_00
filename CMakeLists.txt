cmake_minimum_required(VERSION 3.10)

project(game)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g -ggdb -DARC_SDL -DARC_DEBUG -DARC_DEFAULT_CONFIG")
set(CMAKE_CXX_FLAGS "${CMAKE_C_FLAGS} -g -ggdb -DARC_SDL -DARC_DEBUG")

set(ARC_CPP_OVERLAY
    lib/arc_cpp_overlay/src/archeus.cpp
    lib/arc_cpp_overlay/src/config.cpp
    lib/arc_cpp_overlay/src/engine.cpp
    lib/arc_cpp_overlay/src/entity.cpp
    lib/arc_cpp_overlay/src/keybinds.cpp
    lib/arc_cpp_overlay/src/quadtree.cpp
    lib/arc_cpp_overlay/src/sprite.cpp
    lib/arc_cpp_overlay/src/state.cpp
)

set(ARC_C
    lib/arc/src/std/config.c
    lib/arc/src/std/handler.c
    lib/arc/src/std/hashtable.c
    lib/arc/src/std/io.c
    lib/arc/src/std/string.c
    lib/arc/src/std/vector.c
    lib/arc/src/std/defaults/config.c

    lib/arc/src/math/rectangle.c

    lib/arc/src/input/sdl/keyboard.c
    lib/arc/src/input/sdl/mouse.c

    lib/arc/src/graphics/sdl/config.c
    lib/arc/src/graphics/sdl/line.c
    lib/arc/src/graphics/sdl/rectangle.c
    lib/arc/src/graphics/sdl/renderer.c
    lib/arc/src/graphics/sdl/sprite.c
    lib/arc/src/graphics/sdl/window.c

    lib/arc/src/engine/engine.c
    lib/arc/src/engine/state.c
)

add_executable(game
    src/main.cpp

    src/game/game.cpp

    ${ARC_C}
    ${ARC_CPP_OVERLAY}
)

if(NOT PNG AND WIN32 AND NOT MSVC)
    set(PNG_LIBRARY "C:/Program Files(x86)/libpng")
    set(PNG_PNG_INCLUDE_DIR "C:/Program Files(x86)/libpng/include")
endif()

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)

target_include_directories(game
    PUBLIC lib/arc/include
    PUBLIC lib/arc_cpp_overlay/include
    PUBLIC ${SDL2_INCLUDE_DIRS}
    PUBLIC ${SDL2IMAGE_INCLUDE_DIRS}
)

if(WIN32 AND NOT MSVC)
    target_link_libraries(game PUBLIC ${SDL2_LIBRARIES} SDL2_image::SDL2_image mingw32)
else()
    target_link_libraries(game PUBLIC ${SDL2_LIBRARIES} SDL2_image::SDL2_image)
endif()