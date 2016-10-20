set PROGRAM="%~1"

rem проверяем запуск без параметров
echo run program without arguments:
%PROGRAM% > %TEMP%\output.txt
if NOT ERRORLEVEL 1 goto err
fc.exe out_files\parameters_count_error.txt %TEMP%\output.txt
if ERRORLEVEL 1 goto err

goto success

rem проверяем запуск c 1м параметром
echo run program without arguments:
%PROGRAM% oneParam.txt > %TEMP%\output.txt
if NOT ERRORLEVEL 1 goto err
fc.exe out_files\parameters_count_error.txt %TEMP%\output.txt
if ERRORLEVEL 1 goto err

:success
echo Program testing succeeded
exit 0

:err
echo Program testing failed
exit 1