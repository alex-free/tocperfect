@echo off

cd /d "%~dp0"

rmdir /S /Q msys2-bin-8-22-2023 2> nul
mkdir msys2-bin-8-22-2023
copy C:\msys64\usr\bin\head.exe msys2-bin-8-22-2023
copy C:\msys64\usr\bin\cat.exe msys2-bin-8-22-2023
copy C:\msys64\usr\bin\dirname.exe msys2-bin-8-22-2023
copy C:\msys64\usr\bin\bash.exe msys2-bin-8-22-2023
copy C:\msys64\usr\bin\dirname.exe msys2-bin-8-22-2023
copy C:\msys64\usr\bin\basename.exe msys2-bin-8-22-2023
copy C:\msys64\usr\bin\grep.exe msys2-bin-8-22-2023
copy C:\msys64\usr\bin\rm.exe msys2-bin-8-22-2023
copy C:\msys64\usr\bin\mkdir.exe msys2-bin-8-22-2023
copy C:\msys64\usr\bin\sed.exe msys2-bin-8-22-2023
copy C:\msys64\usr\bin\cp.exe msys2-bin-8-22-2023
copy C:\msys64\usr\bin\find.exe msys2-bin-8-22-2023
copy C:\msys64\usr\bin\msys-*.dll msys2-bin-8-22-2023
pause