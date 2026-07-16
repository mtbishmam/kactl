@echo off
setlocal
set "PATH=%PATH%;%USERPROFILE%\cp;C:\Program Files\CodeBlocks\MinGW\bin"
set prog=%1
g++ %prog%.cpp -o %prog% -DDeBuG -std=c++17 -g -Wall -Wshadow && .\%prog% < in > out && fc exp out && echo AC
