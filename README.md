# AutoCAD and NanoCAD Plugin Project  

## Overview  

This C++ plugin for AutoCAD and NanoCAD introduces custom commands to enhance user interaction.  

### Available Commands  
- **`TEST_HELLO_CMD`**: Prints `"Hello CAD!"` in the command line.  
- **`TEST_CIRCLE_CMD`**: Creates a circle with a default radius at a user-specified center point.  

---

## Prerequisites  

Before setting up the project, ensure you have the following installed:  

### General Requirements  
- **[Microsoft Visual Studio](https://visualstudio.microsoft.com/)** (with C++ development tools)  

### For AutoCAD Plugin Development  
- **[AutoCAD](https://www.autodesk.com/products/autocad/overview)**  
- **[ObjectARX Library (SDK)](https://aps.autodesk.com/developer/overview/autocad-objectarx-sdk-downloads)**  
  - Extract the SDK to a known location.  
  - Ensure compatibility between AutoCAD and ObjectARX (e.g., AutoCAD 2025 requires ObjectARX 2025 SDK).  

### For NanoCAD Plugin Development  
- **[NanoCAD](https://www.nanocad.ru/products/platforma/download/)**  
- **[NanoCAD SDK](https://developer.nanocad.ru/)**  
  - Extract the SDK to a known location.  
  - Ensure compatibility between NanoCAD and the SDK (e.g., NanoCAD 2024.1 requires NanoCAD 24.1 SDK).  

---

## Setup Instructions  

Follow these steps to set up and build the plugin:  

### 1. Configure the Environment  
- Open `_OpenProject.bat` and set the following variables:  
  - `ACadExe` → Path to the AutoCAD executable  
  - `ACadSDK` → Path to the ObjectARX SDK  
  - `NCadExe` → Path to the NanoCAD executable  
  - `NCadSDK` → Path to the NanoCAD SDK  

### 2. Open the Project  
- Run `_OpenProject.bat` to launch Visual Studio with the solution file (`AutoCAD_NanoCAD_plugin.sln`).  
- In Visual Studio, select one of the following build configurations:  
  - `Debug ACAD` (for AutoCAD)  
  - `Debug NCAD` (for NanoCAD)  

### 3. Build the Plugin  
- Press <kbd>Ctrl</kbd> + <kbd>Shift</kbd> + <kbd>B</kbd> or go to **Build > Build Solution** in Visual Studio.  

### 4. Run the Plugin  
- Press <kbd>F5</kbd> to launch AutoCAD or NanoCAD from Visual Studio.  
- In AutoCAD/NanoCAD, type `APPLOAD` in the command line.  
- Select and load the compiled plugin file:  
  - `...\TestAcadProject\build\bin-x64\Debug ACAD\AutoCAD_NanoCAD_plugin.arx` (for AutoCAD)  
  - `...\TestAcadProject\build\bin-x64\Debug NCAD\AutoCAD_NanoCAD_plugin.nrx` (for NanoCAD)  

### 5. Test the Commands  
- Run:  
  ```plaintext
  TEST_HELLO
