# Crear un zip con todos los archivos de la carpeta del proyecto (*.cpp, *.h, *.sln, *.vcxproj.*, etc)

## WINDOWS:
- Se recomienda borrar las siguientes subcarpetas y archivos del ZIP luego de crearlo.
  Abrirlo en Winzip o similar y borrar:Todas las subcarpetas que se encuentren con el nombre Debug, Release, ipch, .vs (menos SalidasDeLasPruebas)

Si luego de borrar estas carpetas y generar el zip el archivo tiene más de 5 MB entonces no quedó borrado correctamente. Otra prueba:
- Habilitar mostrar archivos ocultos y borrar las carpetas antes de hacer el zip (https://mejorantivirus.net/cmo-mostrar-archivos-ocultos-en-windows-10/)
---
## MAC:
- Se recomienda copiar la carpeta de SalidasDeLasPruebas al zip además de todos los archivos .cpp y .h (OPCIONAL).
Nos da la idea de cual fue la última ejecución en sus computadoras si tuvimos problemas al correrlo.
