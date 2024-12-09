cmake_minimum_required(VERSION 3.29)

string(REPLACE "\\" "/" VCPKG_ROOT "$ENV{VCPKG_ROOT}")

# Set the vcpkg toolchain file and C++ standard
set(CMAKE_TOOLCHAIN_FILE "${VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake")
set(CMAKE_CXX_STANDARD 20)

project(opengl-cpp-engine)

# Find packages
find_package(glad CONFIG REQUIRED)
find_package(glfw3 CONFIG REQUIRED)
find_package(glm CONFIG REQUIRED)
find_package(OpenGL REQUIRED COMPONENTS OpenGL)
# Since STB is a header-only library, it doesn't need to be included in this file.

# Add executable
add_library(opengl-cpp-engine STATIC
        src/window.cpp
        src/window.h
        src/Texture2D.cpp
        src/Texture2D.h
        src/ShaderProgram.cpp
        src/ShaderProgram.h
        src/QuadMesh.cpp
        src/QuadMesh.h
        src/Renderer.cpp
        src/Renderer.h
        src/Texture2DRegion.cpp
        src/Texture2DRegion.h
)

# Link libraries to the test executable
target_link_libraries(opengl-cpp-engine
        PRIVATE glad::glad
        PRIVATE glfw
        PRIVATE glm::glm-header-only
        PRIVATE OpenGL::GL
)
target_include_directories(opengl-cpp-engine PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src")
