# DAW1-ED-Bibliotecas

__Creación y Uso de Bibliotecas (libraries)__

Minitutorial para crear y usar bibliotecas propias.

Se crea una biblioteca llamada `aritmetica` con las cuatro operaciones básicas: `suma`, `resta`, `multiplicacion` y `division`.

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




### Crear biblioteca estática

```bash
gcc  -c  aritmetica.c
ar  cr  libaritmetica.a  aritmetica.o 
```

### Crear biblioteca dinámica

```bash
gcc  -c  -fPIC  aritmetica.c
gcc  -shared  -fPIC  -o  libaritmetica.so  aritmetica.o
```

### Utilizar biblioteca dinámica como plugin

```bash
gcc  -o  plug  plug.c  -ldl
./plug
```

### Crear ejecutable con enlace estático

```bash
gcc  -o  main  main.c  libaritmetica.a 
ldd  main
```

### Crear ejecutable con enlace dinámico

```bash
gcc  -o  main  main.c  libaritmetica.so 
# cp  libaritmetica.so  /lib
ldd  main
```

### Distribución de binario junto a biblioteca en la misma carpeta

```bash
gcc  -L.  -Wl,-rpath=.  -Wall  -o  main  main.c  -laritmetica
```

Comprobamos vínculos dinámicos
```bash
ldd  main
```

### Distribución de binario junto a biblioteca en una subcarpeta

```bash
mkdir  libs
mv  libaritmetica.so  libs
gcc  -L./libs  -Wl,-rpath=libs  -Wall  -o  main  main.c  -laritmetica
```

Comprobamos vínculos dinámicos

```bash
ldd  main
```

Podemos copiar `main` y `libs/libaritmetica.so` juntos y `main` siempre encontrará a la biblioteca.


## Java

Codigo de biblioteca en:

- [Archivo de código -implementación-](java/Aritmetica.java)



