set PROGRAM="%~1"

rem ��������� ������ ��� ����������
%PROGRAM% > %TEMP%\output.txt
if NOT ERRORLEVEL 1 goto err
fc.exe out_files\parameters_count_error.txt %TEMP%\output.txt
if ERRORLEVEL 1 goto err

rem �������� ������� � ������, ������ 33 � �������� ���������
%PROGRAM% 111111111111111111111111111111111 > %TEMP%\output.txt
if NOT ERRORLEVEL 1 goto err
fc.exe out_files\number_length_owerflow.txt %TEMP%\output.txt
if ERRORLEVEL 1 goto err

rem �������� ������� �� � �������� ������ � �������� ���������
%PROGRAM% 11a > %TEMP%\output.txt
if NOT ERRORLEVEL 1 goto err
fc.exe out_files\argument_type_error %TEMP%\output.txt
if ERRORLEVEL 1 goto err

rem �������� ������� �� � �������� ������ � �������� ���������
%PROGRAM% 211 > %TEMP%\output.txt
if NOT ERRORLEVEL 1 goto err
fc.exe out_files\argument_type_error %TEMP%\output.txt
if ERRORLEVEL 1 goto err


rem �������� ������� � ������ 110010000(b) = 400(dec) � �������� ����������
%PROGRAM% 110010000 > %TEMP%\output.txt
if ERRORLEVEL 1 goto err
fc.exe out_files\400.txt %TEMP%\output.txt
if ERRORLEVEL 1 goto err

rem �������� ����� ������� ������� (� ������ 0 � �������� ����������)
%PROGRAM% 0 > %TEMP%\output.txt
if ERRORLEVEL 1 goto err
fc.exe out_files\0.txt %TEMP%\output.txt
if ERRORLEVEL 1 goto err

rem �������� ������ ������� ������� (� ������ 11111111111111111111111111111110 � �������� ����������)
%PROGRAM% 11111111111111111111111111111110 > %TEMP%\output.txt
if ERRORLEVEL 1 goto err
fc.exe out_files\ULONG_MAX.txt %TEMP%\output.txt
if ERRORLEVEL 1 goto err


goto success

rem �������� ������� � ������� ������������� ������� � �������� ����������
%PROGRAM% one_line.txt one_line_different_line_1.txt > %TEMP%\output.txt
if NOT ERRORLEVEL 1 goto err
fc.exe out_files\defferent_files_line_1 %TEMP%\output.txt
if ERRORLEVEL 1 goto err

rem �������� ������� � ����������� �������������� ������� � �������� ����������
%PROGRAM% multiline.txt multiline_equals.txt > %TEMP%\output.txt
if ERRORLEVEL 1 goto err
fc.exe out_files\equal_files.txt %TEMP%\output.txt
if ERRORLEVEL 1 goto err

rem �������� ������� � ������ �������������� ������� � �������� ���������� � �������� � 3� ������
%PROGRAM% multiline.txt multiline_different_line_3.txt > %TEMP%\output.txt
if NOT ERRORLEVEL 1 goto err
fc.exe out_files\defferent_files_line_3 %TEMP%\output.txt
if ERRORLEVEL 1 goto err

rem �������� ������� � ������� ������ ����� � �������� ���������� � �������� �� 2� ������
%PROGRAM% multiline.txt multiline_different_size_line2.txt > %TEMP%\output.txt
if NOT ERRORLEVEL 1 goto err
fc.exe out_files\defferent_files_line_2 %TEMP%\output.txt
if ERRORLEVEL 1 goto err

rem �������� ������� � ������� ������ ����� � �������� ���������� � �������� �� 2� ������
%PROGRAM% multiline_different_size_line2.txt multiline.txt > %TEMP%\output.txt
if NOT ERRORLEVEL 1 goto err
fc.exe out_files\defferent_files_line_2 %TEMP%\output.txt
if ERRORLEVEL 1 goto err

:success

echo Program testing succeeded
exit 0

:err
echo Program testing failed
exit 1