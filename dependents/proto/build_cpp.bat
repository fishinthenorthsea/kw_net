@echo off
setlocal enabledelayedexpansion

set outfile=output_path_cpp.txt
if not exist %~dp0%outfile% (
    goto exit_error1
)
echo.
echo =========================== 1. proto ===========================
set csnum=0
for /f %%a in (%outfile%) do (
    echo Output '%%a'
    del /q %%a\*.*
    for %%f in (%~dp0files\*.proto) do (
        echo %%f | findstr "save" >nul 2>nul || %~dp0protoc.exe %%f --proto_path=%~dp0files --cpp_out=%%a && set /a csnum=csnum+1 && echo [Build] !csnum! %%f
    )
)






set outsavefile=output_save_path_cpp.txt
if not exist %~dp0%outsavefile% (
    goto exit_error2
)
echo.
echo.
echo =========================== 2. save_proto ===========================
set dsnum=0
for /f %%a in (%outsavefile%) do (
    echo Output '%%a'
    del /q %%a\*.*
    for %%f in (%~dp0files\*.proto) do (
        echo %%f | findstr "save" >nul && %~dp0protoc.exe %%f --proto_path=%~dp0files --cpp_out=%%a && set /a dsnum=dsnum+1 && echo [Build] !dsnum! %%f
    )
)




echo =========================== Done ===========================
goto quit

:exit_error1
    echo 配置文件 %outfile%  不存在
    goto quit_pause

:exit_error2
    echo 配置文件 %outsavefile%  不存在
    goto quit_pause


:quit_pause
    pause


:quit
pause