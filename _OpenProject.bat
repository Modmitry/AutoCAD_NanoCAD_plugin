@echo off
setlocal

:: Define AutoCAD and SDK path
set ACadSDK=...path to AutoCAD SDK
set NCadSDK=...path to NanoCAD SDK
set ACadExe=...path to AutoCAD app
set NCadExe=...path to NanoCAD app

:: Detect installed Visual Studio using vswhere
set VSWHERE="%ProgramFiles(x86)%\Microsoft Visual Studio\Installer\vswhere.exe"

if not exist %VSWHERE% (
    echo [ERROR] vswhere.exe not found! Make sure Visual Studio is installed.
    exit /b 1
)

:: Find latest installed Visual Studio version
for /f "usebackq tokens=*" %%i in (`%VSWHERE% -latest -products * -requires Microsoft.Component.MSBuild -property installationPath`) do (
    set VSINSTALLDIR=%%i
)

if "%VSINSTALLDIR%"=="" (
    echo [ERROR] Visual Studio installation not found!
    exit /b 1
)

:: Open the project in Visual Studio
start "" "%VSINSTALLDIR%\Common7\IDE\devenv.exe" AutoCAD_NanoCAD_plugin.sln

:: Done
exit
