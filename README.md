![AutoCAD Plugin](https://img.shields.io/badge/AutoCAD-Plugin-blue)
![NanoCAD Plugin](https://img.shields.io/badge/NanoCAD-Plugin-green)
![C++](https://img.shields.io/badge/C++-17-blue)
![Visual Studio](https://img.shields.io/badge/Visual%20Studio-2022-purple)

# AutoCAD and NanoCAD Plugin Project  

## Overview  

This C++ plugin for AutoCAD and NanoCAD introduces custom commands to enhance user interaction.  

### Available Commands  
- **`TEST_HELLO`**: Prints `"Hello CAD!"` in the command line.  
- **`TEST_CIRCLE`**: Creates a circle with a default radius at a user-specified center point.  

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

### 1. Download the project:
- git clone https://github.com/Modmitry/Plugin-for-AutoCAD-and-NanoCAD.git
### 2. Configure the Environment  
- Open `_OpenProject.bat` and set the following variables:  
  - `ACadExe` → Path to the AutoCAD executable  
  - `ACadSDK` → Path to the ObjectARX SDK  
  - `NCadExe` → Path to the NanoCAD executable  
  - `NCadSDK` → Path to the NanoCAD SDK  

### 3. Open the Project  
- Run `_OpenProject.bat` to launch Visual Studio with the solution file (`AutoCAD_NanoCAD_plugin.sln`).  
- In Visual Studio, select one of the following build configurations:  
  - `Debug ACAD` (for AutoCAD)  
  - `Debug NCAD` (for NanoCAD)  

### 4. Build the Plugin  
- Press <kbd>Ctrl</kbd> + <kbd>Shift</kbd> + <kbd>B</kbd> or go to **Build > Build Solution** in Visual Studio.  

### 5. Run the Plugin  
- Press <kbd>F5</kbd> to launch AutoCAD or NanoCAD from Visual Studio.  
- In AutoCAD/NanoCAD, type `APPLOAD` in the command line.  
- Select and load the compiled plugin file:  
  - `...\Plugin-for-AutoCAD-and-NanoCAD\build\bin-x64\Debug ACAD\AutoCAD_NanoCAD_plugin.arx` (for AutoCAD)  
  - `...\Plugin-for-AutoCAD-and-NanoCAD\build\bin-x64\Debug NCAD\AutoCAD_NanoCAD_plugin.nrx` (for NanoCAD)  

### 6. Test the Commands  
 - Run TEST_HELLO to print "Hello CAD!".
 - Run TEST_CIRCLE to create a circle at a user-defined center point.

### 7. Notes
 - **Administrator Access:** Running AutoCAD/NanoCAD with administrator privileges may be required.
 - **Code Customization:** Modify main.cpp to add or extend functionality.
 - **64-bit Requirements:** for SDK, AutoCAD/NanoCAD version and Windows.

### 8. Troubleshooting
### ❌ Issue: Plugin Fails to Load in AutoCAD/NanoCAD  
✅ **Solution**: Ensure the correct `.arx` or `.nrx` file is loaded via `APPLOAD`.  

---

### ❌ Issue: Visual Studio Cannot Find SDK  
✅ **Solution**: Double-check `_OpenProject.bat` and verify the paths to `ACadSDK` or `NCadSDK`.  

---

### ❌ Issue: Compilation Errors Related to Dependencies  
✅ **Solution**:  
- Ensure you are using the correct **ObjectARX SDK** or **NanoCAD SDK** version.  
- Install any missing **Visual Studio components** (`C++ Desktop Development`).

### Keywords  
AutoCAD, NanoCAD, C++, Plugin, ObjectARX, SDK, CAD Development, Visual Studio, ARX, CAD Automation, CAD API, AutoCAD Extensions, AutoCAD Programming
