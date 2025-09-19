# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Build Commands

### Initial Build Setup
```bash
./rebuild.sh  # Clean build from scratch (removes build/ directory)
```

### Regular Build
```bash
./build.sh    # Incremental build using existing build directory
```

### Run Application
```bash
./run.sh      # Execute the built application
```

### Manual Commands
```bash
# Configure and generate build files
cmake -S . -B build

# Build the project
cmake --build build

# Run the executable
./build/bin/main
```

## Project Architecture

This is a C++ project using CMake with SFML for graphics and ImGui for UI components.

### Dependencies
- **SFML 3.0.2**: Graphics, window management, and system utilities
- **ImGui 1.91.9**: Immediate mode GUI library
- **ImGui-SFML**: Binding library for ImGui integration with SFML

All dependencies are fetched automatically via CMake's FetchContent using archive downloads (not Git repositories) to avoid Git tracking issues.

### Project Structure
- `src/main.cpp`: Main application entry point with basic SFML window setup
- `CMakeLists.txt`: Build configuration with dependency management
- `build/`: Generated build files and compiled binaries (git-ignored)
- `build/bin/main`: Final executable output

### Build Configuration
- C++17 standard required
- Executable output directed to `build/bin/`
- Links against: sfml-graphics, sfml-window, sfml-system, ImGui-SFML
- Framerate limited to 144 FPS in the main application