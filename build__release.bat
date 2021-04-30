@REM call .\build__clean.bat
@REM cmake -B ./build -S .
del .\build\Release\starter_project.exe
cmake --build ./build --config Release
cd build/Release
dem_converter.exe C:\gui2one\CODE\DEM_files\K11\N42W118.hgt