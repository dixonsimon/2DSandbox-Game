cmake_minimum_required(VERSION 3.10)
project(2DSandbox)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find the SFML package using the modern method
set(SFML_DIR "C:/dev/SFML-3.0.1/lib/cmake/SFML")
find_package(SFML 3.0 REQUIRED COMPONENTS Graphics Window System)

# Find all our .cpp source files
file(GLOB SOURCES "*.cpp")

# Create the executable from our source files
add_executable(2DSandbox ${SOURCES})

# Link the executable to the SFML libraries using the modern imported targets.
# This automatically handles include directories, linking, and compile definitions.
target_link_libraries(2DSandbox PRIVATE SFML::Graphics SFML::Window SFML::System)

# --- FINAL STEP: AUTOMATICALLY COPY DLLS ---
# This command runs after every successful build and copies the necessary SFML DLLs
# to the same folder as your .exe file, which solves the 0xC0000139 runtime error.
add_custom_command(
        TARGET 2DSandbox POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        # List of SFML DLLs to copy
        "C:/dev/SFML-3.0.1/bin/sfml-graphics-d-3.dll"
        "C:/dev/SFML-3.0.1/bin/sfml-window-d-3.dll"
        "C:/dev/SFML-3.0.1/bin/sfml-system-d-3.dll"
        # The destination directory (where the .exe is)
        $<TARGET_FILE_DIR:2DSandbox>
)

