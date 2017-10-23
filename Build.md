# Construcción o generación de ejecutables

La construcción o generación de ejecutables es más conocida por el término en inglés __build__.

Corresponde a un proceso donde __se compilan__ todos los archivos que forman la aplicación 
y __se enlazan__ con la biblioteca estándar y otras bibliotecas adicionales para obtener un archivo ejecutable.

Este proceso se puede automatizar mediante el uso de herramientas de construcción. Existen muchas, las más utilizadas son:

  - make, ninja (C, C++)
  - ant, maven, gradle (Java)
  - grunt, gulp (Javascript)
  - rake (ruby)

Estas herramientas necesitan un archivo de construcción (__buildfile__) donde indicamos las operaciones a realizar.
A continuación se muestra la herramienta y su buildfile asociado.

  - make: __Makefile__
  - ninja: __build.ninja__
  - ant: __build.xml__
  - maven: __pom.xml__
  - gradle: __build.gradle__
  - grunt: __Gruntfile.js__
  - gulp: __gulpfile.js__
  - rake: __Rakefile__

A continuación se muestran 2 ejemplos, uno para el lenguaje C y otro para Java.

## C

- [buildfile utilzado: Makefile ](c/Makefile)
- [codigo fuente](c)






## Java

- [buildfile utilzado: build.xml ](java/build.xml) 
- [código fuente](java)
