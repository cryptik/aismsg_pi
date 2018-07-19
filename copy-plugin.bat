rmdir /S /Q ..\OpenCPN\build\plugins\aismsg_pi
xcopy /E data ..\OpenCPN\build\plugins\aismsg_pi\data\
copy build\Debug\aismsg_pi.dll ..\OpenCPN\build\plugins\aismsg_pi.dll
