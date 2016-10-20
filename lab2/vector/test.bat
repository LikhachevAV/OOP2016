set PROGRAM="%~1"

rem ��������� ������ ��� ����������
echo run program without arguments:
%PROGRAM% > %TEMP%\output.txt
if NOT ERRORLEVEL 1 goto err
fc.exe out_files\parameters_count_error.txt %TEMP%\output.txt
if ERRORLEVEL 1 goto err

goto success

rem ��������� ������ c 1� ����������
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