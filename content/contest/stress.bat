@echo off&setlocal
rem Make sure code, gen and bf are executables.
set "PATH=%PATH%;%USERPROFILE%\cp;C:\Program Files\CodeBlocks\MinGW\bin"
set i=1
:loop
echo %i%&gen>in&&bf<in>exp&&code<in>out||goto fail
fc /w exp out>nul||goto bad
set /a i+=1&goto loop
:fail
echo gen, bf or code failed&exit /b 1
:bad
echo Bug found&type exp&echo.&type out
