# Construcción o generación de ejecutables

La construcción o generación de ejecutables es más conocida por el término en inglés __build__.

Corresponde a un proceso donde __se compilan__ todos los archivos que forman la aplicación 
y __se enlazan__ con la biblioteca estándar y otras bibliotecas adicionales para obtener un archivo ejecutable.

Este proceso se puede automatizar mediante el uso de herramientas de construcción. Existen muchas, las más utilizadas son:

  - __make__, ninja (C, C++)
  - __ant__, maven, gradle (Java)
  - grunt, gulp (Javascript)
  - rake (ruby)

Estas herramientas necesitan un archivo de construcción (__buildfile__) donde indicamos las operaciones a realizar.
A continuación se muestra la herramienta y su buildfile asociado.

  - make: __Makefile__
  - ninja: build.ninja
  - ant: __build.xml__
  - maven: pom.xml
  - gradle: build.gradle
  - grunt: Gruntfile.js
  - gulp: gulpfile.js
  - rake: Rakefile

En dicho archivo creamos una serie de __reglas__ que se componen de 3 partes:
- __objetivo (target)__
- __dependencias (depends)__
- __comandos__ a ejecutar

Siempre existe una regla por defecto, que es la que se ejecuta si ejecutamos make, ant o similar sin argumentos.

El objetivo es el archivo u operación que se persigue.  
Las dependencias son los archivos u operaciones que es necesario obtener o realizar previamente para obtener dicho objetivo.  
Los comandos son las operaciones necesarias (compilación, enlazado, eliminación, ...)

Si para alcanzar un objetivo es necesario satisfacer dependencias, entonces se resuelven previamente dichas dependencias.

A continuación veremos como realizar la construcción de un programa y su biblioteca asociada. Se muestran 2 ejemplos, uno para el lenguaje C y otro para Java.

## C

- [Makefile ](c/Makefile)
- [codigo fuente](c)

En el caso del archivo _Makefile_, la primera regla es la regla por defecto, en este caso la hemos llamado _all_.
Sirve para compilar y enlazar todo, generando el ejecutable y la biblioteca asociada. 
Si ejecutamos `make` sin argumentos, se ejecutará la regla por defecto y obtendremos la siguiente salida:

```
make
```

```
gcc -O  -c  main.c
gcc -O  -c  -fPIC  aritmetica.c
gcc -O  -shared  -fPIC  -o  libaritmetica.so  aritmetica.o
gcc -O  -Wl,-rpath=/usr/local/lib  main.o  libaritmetica.so  -o  programa
```


Entre otras, hemos declarado también las reglas para los objetivos siguientes:

- `help`:  muestra un mensaje de ayuda
- `clean`:  elimina los archivos resultantes de una construcción anterior
- `install`:  instala el ejecutable y la biblioteca en el sistema

Para obtener dichos objetivos escribimos el comando `make` seguido del objetivo como argumento. 

Por ejemplo, para ver la ayuda escribimos:

```
make  help
```

Por ejemplo, para instalar escribimos:

```
make  install
```


--- 

__Para ver como se puede generar un Makefile haciendo uso de CMake consulta el [siguiente enlace](https://github.com/jamj2000/DAW1-ED-Bibliotecas/blob/master/CMake.md)__

--- 



## Java

- [build.xml ](java/build.xml) 
- [código fuente](java)


En el caso del archivo _build.xml_, la regla por defecto es la que viene indicada en la etiqueta "project" en su atributo "default", en este caso la hemos llamado _jar_.
Sirve para compilar y enlazar todo, generando el bytecode del ejecutable y la biblioteca asociada y guardándolo todo en un archivo .jar. 
Si ejecutamos `ant` sin argumentos, se ejecutará la regla por defecto y obtendremos la siguiente salida:
```
ant
```

```
Buildfile: /home/jose/Proyectos/DAW1-ED-Bibliotecas/java/build.xml

init:
    [mkdir] Created dir: /home/jose/Proyectos/DAW1-ED-Bibliotecas/java/build/classes
    [mkdir] Created dir: /home/jose/Proyectos/DAW1-ED-Bibliotecas/java/build/jar

compile:
    [javac] Compiling 2 source files to /home/jose/Proyectos/DAW1-ED-Bibliotecas/java/build/classes

jar:
      [jar] Building jar: /home/jose/Proyectos/DAW1-ED-Bibliotecas/java/build/jar/programa.jar

BUILD SUCCESSFUL
Total time: 2 seconds
```

Entre otras, hemos declarado también las reglas para los objetivos siguientes:

- `help`:  muestra un mensaje de ayuda
- `clean`:  elimina los archivos resultantes de una construcción anterior
- `run`:  ejecuta el ejecutable, el cual hace uso de la biblioteca

Para obtener dichos objetivos escribimos el comando `ant` seguido del objetivo como argumento. 

Por ejemplo, para ver la ayuda escribimos:

```
ant  help
```

Por ejemplo, para ejecutar escribimos:

```
ant  run
```

---

__Para ver como construir un proyecto Java con Maven, consulta el [siguiente enlace](https://github.com/jamj2000/DAW1-ED-Bibliotecas/blob/master/Maven.md)__

---

__Para ver como construir un proyecto Java con Gradle, consulta el [siguiente enlace](https://github.com/jamj2000/DAW1-ED-Bibliotecas/blob/master/Gradle.md)__

---
