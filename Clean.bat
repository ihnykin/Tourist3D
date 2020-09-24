@echo off

::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

:CHECKUNREAL
tasklist /FI "IMAGENAME eq UE4Editor.exe" 2>NUL | find /I /N "UE4Editor.exe">NUL
IF %ERRORLEVEL% EQU 0 GOTO CLOSEUNREAL
tasklist /FI "IMAGENAME eq devenv.exe" 2>NUL | find /I /N "devenv.exe">NUL
IF %ERRORLEVEL% EQU 0 GOTO CLOSEVISUALSTUDIO

::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

:REMOVING
set UE4DIR=.\Tourist3D

cd %UE4DIR%

echo [Removing from Plugins]
for /d /r ./Plugins %%d in (Binaries Intermediate Saved) do @if exist "%%d" echo "Removing %%d" && rd /s/q "%%d"
::rmdir /S /Q Content\Developers
::rmdir /S /Q Content\Collections 

echo [Removing from Root]
rmdir /S /Q Binaries
rmdir /S /Q Intermediate
rmdir /S /Q Build
rmdir /S /Q Saved

rmdir /S /Q cmake-build-debug
del /F /Q CMakeLists.txt
rmdir /S /Q .vs
rmdir /S /Q .idea
del /F /Q *.sln

exit

::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

:CLOSEUNREAL
color 04
echo Please close Unreal Engine instance and restart bat file"
pause
exit

:CLOSEVISUALSTUDIO
color 04
echo Please close Visual Studio instance and restart bat file"
pause
exit
