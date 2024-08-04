### easySRT

Desktop application for modifying SRT subtitle files. It features a graphical user interface built with Electron and a powerful backend implemented in C++.

## Project Structure

For a detailed explanation of the directory structure, see *soon-to-be*.

## Getting Started

Follow these steps to initialize and run the project:

### Prerequisites

- Node.js (12.x or later)
- npm (6.x or later)
- C++ build tools (for native addon compilation)

### Initial Setup

1. **Clone the Repository**

   ```bash
   git clone https://your-repository-url.git
   cd subtitle-editor
   ```

2. **Install Dependencies**

   - Install Electron and other dependencies:

     ```bash
     npm install
     ```

   - Install `node-gyp` globally (required for building native addons):

     ```bash
     npm install -g node-gyp
     ```

3. **Build the C++ Addon**

   Navigate to the `cpp/src` directory and build the native addon:

   ```bash
   cd cpp
   node-gyp configure
   node-gyp build
   cd ../../
   ```

4. **Start the Application**

   Run the Electron application:

   ```bash
   npm start
   ```

### Contributing

Feel free to submit issues or pull requests. 
