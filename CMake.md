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

0. En tu equipo, entra en la carpeta donde guardas tus proyectos.

```bash
cd
mkdir Proyectos  
cd Proyectos
```

1. Descarga el código fuente.

```bash
git  clone  https://github.com/jamj2000/DAW1-ED-Bibliotecas.git
```

2. Entra en el directorio DAW1-ED-Bibliotecas/cpp

```bash
cd  DAW1-ED-Bibliotecas/cpp
```

3. Crea un directorio de construcción y entra en él.

```bash
mkdir  build  &&  cd  build
```

En este directorio se generará el archivo _Makefile_ y el ejecutable y bibliotecas.


4. Para generar el archivo _Makefile_ ejecuta:

```bash
cmake  ..
```

El `..` indica el directorio padre. Es el directorio donde `cmake` debe leer el archivo de configuración `CMakeLists.txt`.

Por defecto, en Linux, para `cmake` el directorio donde se instalará el ejecutable y las bibliotecas se almacena en la variable `CMAKE_INSTALL_PREFIX` cuyo valor es `/usr/local`. Podemos cambiar este valor por otro. Por ejemplo para indicar que el directorio donde se instalará el ejecutable y las bibliotecas sea `/usr`, ejecutamos: 

```bash
cmake  ..  -DCMAKE_INSTALL_PREFIX=/usr
```

5. Comprobamos que se ha generado un archivo __`Makefile`__.

```bash
ls 
cat Makefile
```

6. Ahora podemos realizar el proceso de construcción con el comando `make`:

```bash
make
```

7. Si deseamos realizar la instalación de los archivos generados, hacemos:

```bash
sudo  make  install
```


## Comentarios acerca del archivo CMakeLists.txt

A continuación se comenta cada una de las secciones del archivo __`CMakeLists.txt`__

__Indicamos la versión de cmake requerida y el nombre del proyecto.__
```
CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
PROJECT(MyProject)
```

__Indicamos el tipo de construcción y los directorios donde se almacenarán los archivos resultantes.__  

En este caso el ejecutable se guardará en `build/bin` y las bibliotecas en `build/lib`.  

Los tipos de construcción son:
- Debug 
- Release
- RelWithDebInfo (Release with Debug Information) 
- MinSizeRel     (Release with Minimum Size)

```
SET(CMAKE_BUILD_TYPE       Release)
SET(EXECUTABLE_OUTPUT_PATH bin)
SET(LIBRARY_OUTPUT_PATH    lib)
```

__Directorios donde se hallan archivos de cabecera .h__
```
INCLUDE_DIRECTORIES (${PROJECT_SOURCE_DIR}/MyApp  ${PROJECT_SOURCE_DIR}/MyLib1  ${PROJECT_SOURCE_DIR}/MyLib2)
```

__Código fuente para el ejecutable__
```
# Ejecutable
#---------------------------------------------------------------
FILE(GLOB MyAppSrc SOURCES "MyApp/*.cpp")
ADD_EXECUTABLE(MyApplication ${MyAppSrc})
```

__Código fuente para la biblioteca dinámica__
```
# Biblioteca dinámica
#---------------------------------------------------------------
FILE(GLOB MyLibSrc1 "MyLib1/*.cpp")
ADD_LIBRARY(MyLibrary1 SHARED ${MyLibSrc1})
```

__Código fuente para la biblioteca estática__
```
# Biblioteca estática
#---------------------------------------------------------------
FILE(GLOB MyLibSrc2 "MyLib2/*.cpp")
ADD_LIBRARY(MyLibrary2 STATIC ${MyLibSrc2})
```

__Proceso de enlazado__
```
# Enlazado
#---------------------------------------------------------------
TARGET_LINK_LIBRARIES(MyApplication  MyLibrary1  MyLibrary2)

# IMPORTANTE: Establecemos RPATH para ejecutable (sirve para encontrar las bibliotecas)
SET_TARGET_PROPERTIES(MyApplication  PROPERTIES  INSTALL_RPATH ${CMAKE_INSTALL_PREFIX}/lib)
```

En el primer comando `TARGET_LINK_LIBRARIES` indicamos el ejecutable y las bibliotecas con las cual se enlaza.  
En el segundo comando `SET_TARGET_PROPERTIES(MyApplication  PROPERTIES  INSTALL_RPATH  ... )` indicamos el directorio
donde el ejecutable, una vez instalado, debería buscar las bibliotecas dinámicas, una vez instaladas también.


__Archivos resultantes y directorios de instalación__
```
# Instalación
#---------------------------------------------------------------
INSTALL (TARGETS  MyApplication  MyLibrary1  MyLibrary2
  RUNTIME DESTINATION "${CMAKE_INSTALL_PREFIX}/bin"
  LIBRARY DESTINATION "${CMAKE_INSTALL_PREFIX}/lib"
  ARCHIVE DESTINATION "${CMAKE_INSTALL_PREFIX}/lib"
)
``` 
Suponiendo que la variable `CMAKE_INSTALL_PREFIX` tiene el valor por defecto `/usr/local`, en caso de realizar `sudo  make  install` se copiarán los siguientes archivos a los siguientes directorios:

- `MyApplication` a `/usr/local/bin` 
- `MyLibrary1` a `/usr/local/lib`
- `MyLibrary2` a `/usr/local/lib`

Si `CMAKE_INSTALL_PREFIX` tiene otro valor, el directorio resultante dependerá de dicho valor.

Los tipos de destinos son:

- `RUNTIME DESTINATION`: para archivos ejecutables  (en este caso `MyApplication`)
- `LIBRARY DESTINATION`: para bibliotecas dinámicas (en este caso `MyLibrary1`)
- `ARCHIVE DESTINATION`: para bibliotecas estáticas (en este caso `MyLibrary2`)

>En realidad los archivos de biblioteca que se instalarán tiene la forma:
>- libMyLibrary1.so
>- libMyLibrary2.a


__Mensaje que se mostrará al final de la ejecución de `cmake ..`__
```
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
```
