# Hack the Holidays with CO/DE (2018)
Hack your way through Santa's x86 Workshop and uncover the `five keys of Christmas` needed to unlock Santa's vault - the home of his coveted list of good little boys and girls. Of course, with all that hacking you've been doing, you're on the naughty list. We'll fix that. Come Christmas morning you can tell Santa where to shove that coal as you unwrap all your toys!

# Santa's Workshop
This reverse engineering project is broken down into five challenges within a single challenge binary (`SantasWorkshop.exe`). Each challenge is designed to teach a set of different skills and concepts related to binary reverse engineering.

# YouTube
Check out the [CO/DE YouTube channel](https://www.youtube.com/playlist?list=PLCJoIC7hiEqbvS5D0hnWL9JuiQQTyx-CW) for a series of videos that cover a version of this material.

# Platform
This project is designed for Windows. Much of the code will translate to Linux and MacOS, but there is use of Windows-specific APIs and structures that will prevent it from working if build for non-Windows platforms.

# Building
This project was compiled using [MinGW](http://www.mingw.org/), the Minimalist GNU for Windows. To build this project, install MinGW and use the following build command:
```
gcc -m32 -o SantasWorkshop.exe src\*.c
```

# License and Solution Posting Policy
This project is MIT licensed so do whatever you want with it.  CO/DE's policy on posting solutions online is `have fun`, post away! 
