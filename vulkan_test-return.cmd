@echo off
@title Test Vulkan API with return error code

cd /d "%~dp0"

echo Return Code: %errorlevel%
echo.

vulkan_test.exe

echo.
echo.
echo Return Code: %errorlevel%
echo.
echo.

pause