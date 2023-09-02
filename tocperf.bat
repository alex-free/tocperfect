@echo off
set argC=0
for %%x in (%*) do Set /A argC+=1

cd /d "%~dp0"

IF NOT "%argC%" == "1" (
	echo Incorrect number of arguments given to %0%, aborted
	echo.
	pause
	exit 1
)

IF NOT EXIST "%~f1" (
	echo Can't open the file "%~f1" for conversion, aborted..
	echo.
	pause
	exit 1
)

bin\bash.exe ./tocperf "%~f1"
pause