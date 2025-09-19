cmake_minimum_required(VERSION 3.25)
project(CMakeSFMLProject LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include(FetchContent)

# --- SFML ---
FetchContent_Declare(SFML
    URL https://github.com/SFML/SFML/archive/refs/tags/3.0.2.tar.gz
)
FetchContent_MakeAvailable(SFML)

# --- ImGui ---
FetchContent_Declare(ImGui
    URL https://github.com/ocornut/imgui/archive/refs/tags/v1.91.9.tar.gz
)
FetchContent_MakeAvailable(ImGui)

# --- ImGui-SFML binding ---
# Disable SFML auto-find (we already have SFML)
set(IMGUI_SFML_FIND_SFML OFF CACHE BOOL "" FORCE)
# Point ImGui-SFML to the ImGui we fetched
set(IMGUI_DIR ${imgui_SOURCE_DIR} CACHE PATH "" FORCE)

FetchContent_Declare(ImGui-SFML
    URL https://github.com/SFML/imgui-sfml/archive/refs/heads/master.tar.gz
)
FetchContent_MakeAvailable(ImGui-SFML)

# --- Main executable ---
add_executable(main src/main.cpp)
target_compile_features(main PRIVATE cxx_std_17)

target_link_libraries(main
    PRIVATE
        sfml-graphics
        sfml-window
        sfml-system
        ImGui-SFML::ImGui-SFML
)
