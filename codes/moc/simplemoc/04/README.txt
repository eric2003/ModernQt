cmake .. -D CMAKE_PREFIX_PATH:PATH=C:/local/Qt/6.3.2/msvc2019_64/
cmake  .. -D CMAKE_TOOLCHAIN_FILE="c:/dev/vcpkg/scripts/buildsystems/vcpkg.cmake" `
-D CMAKE_PREFIX_PATH:PATH=C:/local/Qt/6.3.2/msvc2019_64/
cmake .. -D CMAKE_PREFIX_PATH:PATH=C:/local/Qt/Qt6.4.0/6.4.0/msvc2019_64/
cmake --build .
C:\local\Qt\6.3.2\msvc2019_64\bin\windeployqt.exe .\Debug\testprj.exe
C:\local\Qt\Qt6.4.0\6.4.0\msvc2019_64\bin\windeployqt.exe .\Debug\testprj.exe
.\Debug\testprj.exe

c:\dev\vcpkg\installed\x64-windows\tools\Qt6\bin\windeployqt.debug.bat `
d:\work\qt_2022_work\ModernQt\codes\sql\vcpkg\mysql\01\build\Debug\testprj.exe

Usage: C:\local\Qt\Qt6.4.0\6.4.0\msvc2019_64\bin\moc.exe [options] [header-file] [@option-file] [MOC generated json file]

C:\local\Qt\Qt6.4.0\6.4.0\msvc2019_64\bin\moc.exe ../Sender.h
C:\local\Qt\Qt6.4.0\6.4.0\msvc2019_64\bin\moc.exe -o mymoc.cpp ../Sender.h