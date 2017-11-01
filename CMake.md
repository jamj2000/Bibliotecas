# Generación de archivo Makefile con CMake

CMake es una herramienta que nos permite generar archivos _Makefile_ adaptados a la plataforma de destino.  
CMake necesita un archivo de configuración __CMakeLists.txt__, el cual es independiente de la plataforma.  
El archivo _Makefile_ generado está destinado a una plataforma en concreto.

Para realizar esta práctica veremos un proyecto desarrollado en C++ donde desarrollamos una aplicación muy sencilla 
que hace uso de una biblioteca dinámica y otra estática.

La biblioteca que construiremos de forma dinámica tiene el código para realizar operaciones aritméticas básicas (suma, resta, ...).
La biblioteca que construiremos de forma estática tiene el código para realizar operaciones de potencias (cuadrado, cubo).

Todo el código fuente es accesible en el siguiente enlace:

- https://github.com/jamj2000/DAW1-ED-Bibliotecas/tree/master/cpp

El código fuente se compone de:
- [aplicación](cpp/MyApp/main.cpp)
- [biblioteca para enlazar de forma dinámica](cpp/MyLib1/aritmetica.cpp)
- [biblioteca para enlazar de forma estática](cpp/MyLib2/potencias.cpp)

El archivo __CMakeLists.txt__ es:
- [CMakeLists.txt](cpp/CMakeLists.txt)

