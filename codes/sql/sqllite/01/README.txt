cmake .. -D CMAKE_PREFIX_PATH:PATH=C:/local/Qt/6.3.2/msvc2019_64/
cmake --build .
C:\local\Qt\6.3.2\msvc2019_64\bin\windeployqt.exe .\Debug\testprj.exe
.\Debug\testprj.exe

PS D:\work\qt_2022_work\ModernQt\codes\sql\sqllite\01\build> .\Debug\testprj.exe
haha
"QSQLITE"
"QODBC"
"QPSQL"

PS D:\work\qt_2022_work\ModernQt\codes\sql\sqllite\01\build> .\Debug\testprj.exe
haha
"QSQLITE"
"QMARIADB"
"QMYSQL"
"QODBC"
"QPSQL"