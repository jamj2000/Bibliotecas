# Generación de archivo Makefile con CMake

CMake es una herramienta que nos permite generar archivos _Makefile_ adaptados a la plataforma de destino.  
CMake necesita un archivo de configuración __CMakeLists.txt__, el cual es independiente de la plataforma.  
El archivo _Makefile_ generado está destinado a una plataforma en concreto.

Para poner en práctica ontinuación veremos un proyecto desarrollado en C++. Todo el código fuente es accesible en el siguiente enlace:

- https://github.com/jamj2000/DAW1-ED-Bibliotecas/cpp

El archivo __CMakeLists.txt__ es:
- [CMakeLists.txt](cpp/CMakeLists.txt)

El código fuente se compone de:
- [programa principal](cpp/MyApp/main.cpp)
- [biblioteca para enlazar de forma dinámica](cpp/MyLib1/aritmetica.cpp)
- [biblioteca para enlazar de forma estática](cpp/MyLib2/potencias.cpp)

