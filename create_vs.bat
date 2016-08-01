@echo off

SET VS_VERSION=vs2013
SET X86_OR_X64=64
SET BUILD_DIR=../%VS_VERSION%_%X86_OR_X64%

SET CMAKE_ARCH=
IF %VS_VERSION%==vs2010 (SET CMAKE_MODE_VS=10)
IF %VS_VERSION%==vs2012 (SET CMAKE_MODE_VS=11)
IF %VS_VERSION%==vs2013 (SET CMAKE_MODE_VS=12)
IF %VS_VERSION%==vs2015 (SET CMAKE_MODE_VS=14 2015)
IF %X86_OR_X64%==64 (SET CMAKE_ARCH= Win64)


::remove existing project, force to make cmake configuration files effective 
IF EXIST "%BUILD_DIR%" (echo exist build_dir=%BUILD_DIR%) & (rd /s /q %BUILD_DIR%)
md "%BUILD_DIR%"
SET BUILD_ROOT=%CD%
chdir %BUILD_DIR%
cmake  -Wno-dev -G "Visual Studio %CMAKE_MODE_VS%%CMAKE_ARCH%" %BUILD_ROOT% -DGEN9=1 -DGEN10=1 -DGEN11=1
chdir %BUILD_ROOT%

GOTO :DONE

:VS_PATH_FAILED
ECHO ******ERROR: VS2013 path does not exist******
ECHO CM Windows Mobile works with VS2013 only
GOTO :DONE

:DONE
exit /B %errorlevel%
