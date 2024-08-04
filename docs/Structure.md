
### `STRUCTURE.md`

# Project Structure

This document explains the directory structure of the Subtitle Editor project.

## Root Directory

- **`main.js`**: Entry point for the Electron application. It sets up and opens the main application window.
- **`preload.js`**: A script loaded before other renderer scripts. It can be used for secure Node.js integration.
- **`package.json`**: Configuration file for npm, including dependencies and scripts.
- **`package-lock.json`**: Automatically generated file that locks the versions of npm dependencies.
- **`README.md`**: This file, which provides an overview of the project and setup instructions.
- **`STRUCTURE.md`**: Detailed explanation of the project directory structure.
- **`LICENSE`**: License information for the project.

## `cpp/` Directory

Contains C++ code for the backend and native addon.

- **`src/`**: Source files for C++ code.
  - **`addon.cpp`**: Implements the Node.js native addon that interfaces between JavaScript and C++.
  - **`parsers/`**: Contains files for parsing subtitles (e.g., `srt_parser.cpp` and `srt_parser.h`).
  - **`models/`**: Contains C++ classes representing data models (e.g., `subtitle.cpp` and `subtitle.h`).
  - **`utils/`**: Utility functions and helpers (e.g., `time_utils.cpp` and `time_utils.h`).
- **`include/`**: Header files for public interfaces.
  - **`srt_parser.h`**: Header for subtitle parsing functions.
  - **`subtitle.h`**: Header for the `Subtitle` class.
  - **`time_utils.h`**: Header for utility functions related to time.

## `src/` Directory

Contains frontend code and assets for the Electron application.

- **`assets/`**: Static assets like styles and images.
  - **`styles/`**: CSS files for styling the frontend (e.g., `style.css`).
  - **`images/`**: Directory for images and other static files.
- **`js/`**: JavaScript files for frontend logic.
  - **`components/`**: UI components (e.g., `videoPlayer.js`, `subtitleEditor.js`).
  - **`services/`**: Services for data operations (e.g., `subtitleService.js`).
  - **`utils/`**: Utility functions (e.g., `timeUtils.js`).
  - **`renderer.js`**: Main script for initializing the frontend logic.
- **`index.html`**: Main HTML file for the frontend interface.

## Build and Start

- **Build C++ Addon**: Run `node-gyp configure` and `node-gyp build` in the `cpp` directory.
- **Start Application**: Use `npm start` to launch the Electron application.

