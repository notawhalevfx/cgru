echo Clearing Houdini examples in %CD%

For /F "Tokens=*" %%I in ('dir /b "scene.hip*"') Do if not "%%I" == "scene.hip" del "%%I"

if exist "*.mov" del /f /q "*.mov"

cd render
del /f /q *