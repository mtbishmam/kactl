@echo off
set prog=%1
g++ %prog%.cpp -o %prog% -DDeBuG -std=c++17 -g -Wall -Wshadow && .\%prog% < in > out && fc exp out && echo -e "\nAC"