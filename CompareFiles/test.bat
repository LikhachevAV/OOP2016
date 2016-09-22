//set PROGRAM="%~1"

rem проверяем копирование пустого файла
comparefiles.exe one-line.txt %PROGRAM% one-line-notequals-line-1.txt
if ERRORLEVEL 1 goto err

echo Program testing succeeded
exit 0

:err
echo Program testing failed
exit 1