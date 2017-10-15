# DAW1-ED-Bibliotecas

__Creación y Uso de Bibliotecas (libraries)__

---

## C

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
ldd  main
```

### Distribución de binario junto a biblioteca en una subcarpeta

```bash
mkdir libs
mv  libaritmetica.so  libs
gcc  -L./libs  -Wl,-rpath=libs  -Wall  -o  main  main.c  -laritmetica
ldd  main
```

Podemos copiar main y libs/libaritmetica.so juntos y main siempre encontrará a la biblioteca 



## Java
