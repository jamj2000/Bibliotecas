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


## Proceso a seguir

A continuación se indica el proceso a seguir para construir o generar el proyecto. 

1. Descarga el código fuente.

```
git  clone  
```

CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
PROJECT(MyProject)

SET(CMAKE_BUILD_TYPE       Release)
SET(EXECUTABLE_OUTPUT_PATH bin)
SET(LIBRARY_OUTPUT_PATH    lib)

INCLUDE_DIRECTORIES (${PROJECT_SOURCE_DIR}/MyApp  ${PROJECT_SOURCE_DIR}/MyLib1  ${PROJECT_SOURCE_DIR}/MyLib2)

# Ejecutable
#---------------------------------------------------------------
FILE(GLOB MyAppSrc SOURCES "MyApp/*.cpp")
ADD_EXECUTABLE(MyApplication ${MyAppSrc})


# Biblioteca dinámica
#---------------------------------------------------------------
FILE(GLOB MyLibSrc1 "MyLib1/*.cpp")
ADD_LIBRARY(MyLibrary1 SHARED ${MyLibSrc1})


# Biblioteca estática
#---------------------------------------------------------------
FILE(GLOB MyLibSrc2 "MyLib2/*.cpp")
ADD_LIBRARY(MyLibrary2 STATIC ${MyLibSrc2})


# Enlazado
#---------------------------------------------------------------
TARGET_LINK_LIBRARIES(MyApplication  MyLibrary1  MyLibrary2)

# IMPORTANTE: Establecemos RPATH para ejecutable (sirve para encontrar las bibliotecas)
SET_TARGET_PROPERTIES(MyApplication  PROPERTIES  INSTALL_RPATH ${CMAKE_INSTALL_PREFIX}/lib)


# Instalación
#---------------------------------------------------------------
INSTALL (TARGETS  MyApplication  MyLibrary1  MyLibrary2
  RUNTIME DESTINATION "${CMAKE_INSTALL_PREFIX}/bin"
  LIBRARY DESTINATION "${CMAKE_INSTALL_PREFIX}/lib"
  ARCHIVE DESTINATION "${CMAKE_INSTALL_PREFIX}/lib"
)


MESSAGE (
"\n  Resumen de construcción (build) para la aplicación."
"\n  -----------------------------------------------------------"
"\n  * Prefijo de instalación      : " ${CMAKE_INSTALL_PREFIX}
"\n  * Directorio del ejecutable   : " ${CMAKE_INSTALL_PREFIX}/bin
"\n  * Directorio de la biblioteca : " ${CMAKE_INSTALL_PREFIX}/lib
"\n  * Tipo de construcción (build): " ${CMAKE_BUILD_TYPE}
"\n  * Plataforma                  : " ${CMAKE_SYSTEM} ${CMAKE_SYSTEM_PROCESSOR}
"\n"
)
