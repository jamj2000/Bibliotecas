# DAW1-ED-Bibliotecas

__Creación y Uso de Bibliotecas (libraries)__

Minitutorial para crear y usar bibliotecas propias.

Como ejemplo se crea una biblioteca llamada `aritmetica` con las cuatro operaciones básicas: `suma`, `resta`, `multiplicacion` y `division`.

Se realiza para los lenguajes:
- C
- Java

---

## C

Codigo de biblioteca en:

- [Archivo de cabecera -especificación-](c/aritmetica.h)
- [Archivo de código -implementación-](c/aritmetica.c)

A continuación veremos como:
- Crear una biblioteca estática
- Crear una biblioteca dinámica
- Usar la biblioteca dinámica como plugin
- Hacer enlace estático
- Hacer enlace dinámico

Cuando desarrollamos un programa, éste, además de compilarse, necesita enlazarse con la biblioteca estándar del lenguaje y otras bibliotecas propias del desarrollador. 

En los lenguajes compilados se distingue dos __tipos de enlazado con una biblioteca__:
- __Estático__
  El enlazado estático incluye el código de la biblioteca dentro del programa que hace uso de ella.
  Ventajas: 
    - Programa autocontenido.
    - Las actualizaciones de la biblioteca no le afectan.
  Desventajas:
    - Mayor tamaño del programa.
    - El programa no se beneficia de las actualizaciones de la biblioteca.

- __Dinámico__
  El enlazado dinámico __NO__ incluye el código de la biblioteca dentro del programa que hace uso de ella. En su lugar se realiza un vínculo a la biblioteca dinámica.
  Ventajas: 
    - Menor tamaño del programa.
    - El programa se beneficia de las actualizaciones de la biblioteca.
  Desventajas:
    - Programa __NO__ autocontenido.
    - Las actualizaciones de la biblioteca le afectan para bien y para mal.

Hay una tercera forma de uso:
- __Plugins__: Carga de biblioteca en tiempo de ejecución.
  Es muy parecido al enlazado dinámico, con la salvedad que se carga la biblioteca en tiempo de ejecución. Esto permite, en un caso dado, comprobar si dicha biblioteca está disponible y hacer un uso de ella según el caso. Así prevenimos el error de carga del programa que se produce cuando no se encuentra la biblioteca enlazada dinámicamente.


### Crear biblioteca estática

1. Compilamos a código objeto estático

```
gcc  -c  aritmetica.c
```
  Se habrá generado un archivo `aritmetica.o` con código objeto estático.

2. Empaquetamos en biblioteca estática `libaritmetica.a` 

```
ar  cr  libaritmetica.a  aritmetica.o 
```

3. Instalamos biblioteca en el sistema.

  Desde el punto de vista del programa desarrollado, este paso no es necesario. Pero resulta adecuado si deseamos hacer disponible la biblioteca para que otros programas puedan hacer uso de ella durante su compilación y enlazado.

  Para instalar dicha biblioteca en el sistema debemos copiar `libaritmetica.a` a algún directorio de sistema donde se alojan las librerias (p.ej: `/lib` o `/usr/lib`)

```bash
cp  libaritmetica.a  /lib
```

### Crear biblioteca dinámica

1. Compilamos a código objeto dinámico
```
gcc  -c  -fPIC  aritmetica.c
```
  Se habrá generado un archivo `aritmetica.o` con código objeto dinámico.

2. Empaquetamos en biblioteca dinámica `libaritmetica.so` 
```
gcc  -shared  -fPIC  -o  libaritmetica.so  aritmetica.o
```

3. Instalamos biblioteca en el sistema

  Para instalar dicha biblioteca en el sistema debemos copiar `libaritmetica.so` a algún directorio de sistema donde se alojan las librerias (p.ej: `/lib` o `/usr/lib`)

```bash
cp  libaritmetica.so  /lib
```

### Utilizar biblioteca dinámica como plugin

Codigo en:

- [Archivo plug.c](c/plug.c)

1. Compilamos y enlazamos, generando un ejecutable `plug`

```
gcc  -o  plug  plug.c  -ldl
```
  Además de enlazar con la biblioteca estándar de C, debemos enlazar con la biblioteca adicional `dl` que nos permite la carga de código binario en tiempo de ejecución.

2. Ejecutamos programa `plug`

```
./plug
```

### Crear ejecutable con enlace estático

Codigo en:

- [Archivo main.c](c/main.c)

1. Compilamos y enlazamos, generando un ejecutable `main` y enlace estático a `libarimetica.a`

```
gcc  -o  main  main.c  libaritmetica.a 
```

2. Comprobamos vínculos dinámicos

```
ldd  main
```
  Observamos que __NO__ aparece la biblioteca `libaritmetica.a` como enlace dinámico.


### Crear ejecutable con enlace dinámico

Codigo en:

- [Archivo main.c](c/main.c)

1. Compilamos y enlazamos, generando un ejecutable `main` y enlace dinámico a `libarimetica.so`

```
gcc  -o  main  main.c  libaritmetica.so 
```

2. Comprobamos vínculos dinámicos

```
ldd  main
```
  Observamos que __SÍ__ aparece la biblioteca `libaritmetica.so` como enlace dinámico.


### Distribución de binario junto a biblioteca en la misma carpeta

Una forma de distribuir un programa con enlace dinámico de forma autocontenida es distribuir la biblioteca junto al programa y hacer el enlazado con una ruta relativa. En este caso la biblioteca está en el mismo directorio que el programa.

1. Compilamos y enlazamos, indicando el directorio donde está localizada la biblioteca, en este caso `.` (el propio directorio)

```
gcc  -L.  -Wl,-rpath=.  -Wall  -o  main  main.c  -laritmetica
```

```
NOTA: Se hacen uso de las siguientes opciones:

- -Wl,rpath=.    Directorio donde el enlazador debe buscar la biblioteca
- -L.            Directorio donde se hallan los archivos de cabecera
- -laritmetica   Biblioteca a enlazar (libaritmetica.so: observa que se elimina el prefijo lib y el sufijo .so)
```

2. Comprobamos vínculos dinámicos

```
ldd  main
```

Ya podemos copiar `main` y `libaritmetica.so` juntos y `main` siempre encontrará a la biblioteca.


### Distribución de binario junto a biblioteca en una subcarpeta

Una forma de distribuir un programa con enlace dinámico de forma autocontenida es distribuir la biblioteca junto al programa y hacer el enlazado con una ruta relativa. En este caso organizaremos un poco la información, pondremos la biblioteca en un subdirectorio llamado `libs`.

0. Creamos subdirectorio y movemos biblioteca a él.
```
mkdir  libs
mv  libaritmetica.so  libs
```

1. Compilamos y enlazamos, indicando el directorio donde está localizada la biblioteca, en este caso `./libs` (el subdirectorio del mismo nombre)
```
gcc  -L./libs  -Wl,-rpath=libs  -Wall  -o  main  main.c  -laritmetica
```

2. Comprobamos vínculos dinámicos

```
ldd  main
```

Ya podemos copiar `main` y `libs/libaritmetica.so` juntos y `main` siempre encontrará a la biblioteca.


## Java

Codigo de biblioteca en:

- [Archivo de código -implementación-](java/Aritmetica.java)



