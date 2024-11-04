@echo off

setlocal

@REM user set parameter start
set QTDIR=C:\Qt\6.3.2\msvc2019_64
set GENERATOR=Visual Studio 17 2022
set COMPILER=v142
set ARCH=x64
@REM user set parameter done

set _PROJECT_DIR=%~dp0
set PROJECT_DIR=%_PROJECT_DIR:\=/%
set BIN_DIR=%PROJECT_DIR%bin
set SRC_DIR=%PROJECT_DIR%
set BUILD_DIR=%PROJECT_DIR%build
set CMAKE_BUILD_TYPE="RelWithDebInfo"

cd %~dp0
echo %PROJECT_DIR%

cmake -Wno-dev ^
	-S "%SRC_DIR%" ^
 	-B "%BUILD_DIR%" ^
	-G "%GENERATOR%" ^
	-A %ARCH% ^
	-T %COMPILER% ^
	-DCMAKE_BUILD_TYPE=%CMAKE_BUILD_TYPE% ^
	-DCMAKE_PREFIX_PATH="%QTDIR%" ^
	-DRELEASE_CANDIDATE=1.0.0.1