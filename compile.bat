@echo off
REM Script de compilation pour Windows

echo Compilation du projet Quarto...

REM Essayer gcc d'abord
where gcc >nul 2>nul
if %ERRORLEVEL% EQU 0 (
    echo Utilisation de GCC...
    gcc -Wall -Wextra -std=c99 -g -o play.exe src/play.c src/fonctions.c
    if %ERRORLEVEL% EQU 0 (
        echo Compilation reussie! Executable: play.exe
        goto :end
    )
)

REM Essayer clang
where clang >nul 2>nul
if %ERRORLEVEL% EQU 0 (
    echo Utilisation de Clang...
    clang -Wall -Wextra -std=c99 -g -o play.exe src/play.c src/fonctions.c
    if %ERRORLEVEL% EQU 0 (
        echo Compilation reussie! Executable: play.exe
        goto :end
    )
)

REM Essayer cl (Visual Studio)
where cl >nul 2>nul
if %ERRORLEVEL% EQU 0 (
    echo Utilisation de Visual Studio Compiler...
    cl /Fe:play.exe src/play.c src/fonctions.c
    if %ERRORLEVEL% EQU 0 (
        echo Compilation reussie! Executable: play.exe
        goto :end
    )
)

echo Erreur: Aucun compilateur C trouve!
echo Veuillez installer un des compilateurs suivants:
echo - MinGW-w64 (gcc)
echo - LLVM (clang)  
echo - Visual Studio (cl)
exit /b 1

:end
echo.
echo Pour executer le programme, tapez: play.exe
pause
