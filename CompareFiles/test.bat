set PROGRAM="%~1"

rem проверяем запуск без параметров
%PROGRAM% > %TEMP%\output.txt
if NOT ERRORLEVEL 1 goto err
fc.exe out_files\parameters_count_error.txt %TEMP%\output.txt
if ERRORLEVEL 1 goto err

rem проверка запуска с несуществующим файлом1 в качестве параметра
%PROGRAM% not_existing_file.txt one_line.txt > %TEMP%\output.txt
if NOT ERRORLEVEL 1 goto err
fc.exe out_files\no_file.txt %TEMP%\output.txt
if ERRORLEVEL 1 goto err

rem проверка запуска с несуществующим файлом2 в качестве параметра
%PROGRAM% one_line.txt not_existing_file.txt > %TEMP%\output.txt
if NOT ERRORLEVEL 1 goto err
fc.exe out_files\no_file.txt %TEMP%\output.txt
if ERRORLEVEL 1 goto err

rem проверка запуска с одинаковыми однострочными файлами в качестве параметров
%PROGRAM% one_line.txt one_line_equals.txt > %TEMP%\output.txt
if ERRORLEVEL 1 goto err
fc.exe out_files\equal_files.txt %TEMP%\output.txt
if ERRORLEVEL 1 goto err

rem проверка запуска с разными однострочными файлами в качестве параметров
%PROGRAM% one_line.txt one_line_different_line_1.txt > %TEMP%\output.txt
if NOT ERRORLEVEL 1 goto err
fc.exe out_files\defferent_files_line_1 %TEMP%\output.txt
if ERRORLEVEL 1 goto err

echo Program testing succeeded
exit 0

:err
echo Program testing failed
exit 1