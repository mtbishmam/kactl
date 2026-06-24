@echo off
set i=1

:loop
echo %i%
gen>in
bf<in>exp
code<in>out
fc /w exp out>nul || goto bad

set /a i+=1
goto loop

:bad
echo Bug found
type exp
echo.
type out