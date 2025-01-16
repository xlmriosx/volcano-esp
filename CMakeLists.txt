cmake_minimum_required(VERSION 3.15)

# Nombre del proyecto
project(ESP LANGUAGES CXX)

# Estándar de C++
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Directorios de salida
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/build)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_SOURCE_DIR}/build/ESP-MID)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_SOURCE_DIR}/build/ESP-MID)

# Archivos fuente y cabeceras
file(GLOB_RECURSE SOURCES
    ${CMAKE_SOURCE_DIR}/src/*.cpp
    ${CMAKE_SOURCE_DIR}/external/imgui/*.cpp
)

file(GLOB_RECURSE HEADERS
    ${CMAKE_SOURCE_DIR}/src/*.h
    ${CMAKE_SOURCE_DIR}/external/imgui/*.h
)

# Crear el ejecutable
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

# Incluir directorios (DirectX SDK y otros)
target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_SOURCE_DIR}/src
    ${CMAKE_SOURCE_DIR}/external/imgui
)

# Vincular bibliotecas (DirectX)
target_link_directories(${PROJECT_NAME} PRIVATE
)
target_link_libraries(${PROJECT_NAME} d3d11)

# Configuración para Windows (subsystem y recursos)
if(WIN32)
    set_target_properties(${PROJECT_NAME} PROPERTIES
        WIN32_EXECUTABLE TRUE
    )
    target_sources(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/src/utils/Resource.rc)
    set_target_properties(${PROJECT_NAME} PROPERTIES
        LINK_FLAGS "/MANIFESTUAC:\"level='requireAdministrator' uiAccess='false'\""
    )
endif()

if(WIN32)
    # Use DirectX 11 backend on Windows
    list(APPEND SOURCES
        ${CMAKE_SOURCE_DIR}/external/imgui/imgui_impl_dx11.cpp
        ${CMAKE_SOURCE_DIR}/external/imgui/imgui_impl_win32.cpp
    )
elseif(UNIX)
    # Use OpenGL backend on Linux
    list(APPEND SOURCES
        ${CMAKE_SOURCE_DIR}/external/imgui/imgui_impl_opengl3.cpp
    )
endif()
