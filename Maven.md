# Generando proyectos Java con Maven


Maven es una herramienta para la gestión y construcción de proyectos Java.

Maven utiliza un Project Object Model (POM) para describir el proyecto de software a construir, sus dependencias de otros módulos y componentes externos, y el orden de construcción de los elementos. Viene con objetivos predefinidos para realizar ciertas tareas claramente definidas, como la compilación del código y su empaquetado. 

Una característica clave de Maven es que está listo para usar en red. Maven provee soporte no solo para obtener archivos de su repositorio, sino también para subir artefactos al repositorio al final de la construcción de la aplicación, dejándola al acceso de todos los usuarios.

Maven está construido usando una arquitectura basada en plugins.

## Creación de proyecto

```
mvn archetype:generate -DgroupId=com.mycompany.app -DartifactId=myapp -Dversion=1.0.0 \
      -DarchetypeArtifactId=maven-archetype-quickstart -DinteractiveMode=false
```

- `groupId` corresponde al paquete, en este caso com.mycompany.app
- `artifactId` corresponde al componente java desarrollado (como podría ser una biblioteca)


El comando anterior genera una estructura de directorios como la mostrada a continuación:

```
tree

.
├── pom.xml
└──src
    ├── main
    │   └── java
    │       └── com
    │           └── miempresa
    │               └── app
    │                   └── App.java
    └── test
        └── java
            └── com
                └── miempresa
                    └── app
                        └── AppTest.java
```

El archivo `pom.xml` tiene un contenido similar a este:

```xml
<project>
  <modelVersion>4.0.0</modelVersion>
  <groupId>com.mycompany.app</groupId>
  <artifactId>myapp</artifactId>
  <packaging>jar</packaging>
  <version>1.0.0</version>
</project>
```

La etiqueta _modelVersion_ hace referencia a la propia estructura del fichero Maven (actualmente es la 4).  
La etiqueta _packaging_ indica la forma de empaquetado. Por defecto es .jar.



## Objetivos o metas (goals)

Maven ya tiene predefinidas una serie de metas (goals, en terminología de maven). Son las siguientes:

Las metas que forman parte del ciclo de vida principal del proyecto Maven son:

- `compile`: Genera los ficheros .class compilando los fuentes .java
- `test`: Ejecuta los test automáticos de JUnit existentes, abortando el proceso si alguno de ellos falla.
- `package`: Genera el fichero .jar con los .class compilados
- `install`: Copia el fichero .jar a un directorio de nuestro ordenador donde maven deja todos los .jar. De esta forma esos .jar pueden utilizarse en otros proyectos maven en el mismo ordenador.
- `deploy`: Copia el fichero .jar a un servidor remoto, poniéndolo disponible para cualquier proyecto maven con acceso a ese servidor remoto.

Cuando se ejecuta cualquiera de los comandos maven, por ejemplo, si ejecutamos mvn install, maven irá verificando todas las fases del ciclo de vida desde la primera hasta la del comando, ejecutando solo aquellas que no se hayan ejecutado previamente.

También existen algunas objetivos o metas que están fuera del ciclo de vida que pueden ser llamadas, pero Maven asume que estas metas no son parte del ciclo de vida por defecto (no tienen que ser siempre realizadas). Estas metas son:

- `clean`: Elimina todos los .class y .jar generados. Después de este comando se puede comenzar un compilado desde cero.
- `site`: Genera un sitio web con la información de nuestro proyecto. 


Por ejemplo, para compilar ejecutaremos:

```
mvn  compile
```

y para generar un archivo .jar

```
mvn  package
```

Todos los archivos generados durante la construcción se guardan en la carpeta `target`. 


## Ejemplo práctico

Vamos a crear una aplicación llamada `mi-app`. Constará de 2 clases, una principal y otra con la funcionalidad para realizar las cuatro operaciones aritméticas básicas. 

Para ello realiza los siguientes pasos:

0. Entra en tu carpeta de proyectos: 

```
cd  ~/Proyectos
```

1. Crea la estructura de carpetas con maven:

```
mvn  archetype:generate  -DgroupId=com.miempresa.app  -DartifactId=mi-app  -Dversion=1.0.0 \
       -DarchetypeArtifactId=maven-archetype-quickstart  -DinteractiveMode=false
```

2. Entra en la carpeta mi-app. Veras un archivo `pom.xml` ya creado con una configuración básica.

```
cd  mi-app  &&  ls
cat  pom.xml
```

3. Genera el siguiente código fuente:

__Crea 2 clases dentro de la ruta `src/main/java/com/miempresa/app`__:

```
nano  src/main/java/com/miempresa/app/App.java
```


```java
package com.miempresa.app;

public class App {

  private static final int NUM1 = 5;
  private static final int NUM2 = 2;


  public static void main (String[] args) {
    System.out.println ("Dados los números " + NUM1 + " y " + NUM2 );
    System.out.println ("La suma es " + Aritmetica.suma(NUM1, NUM2) );
    System.out.println ("La resta es " + Aritmetica.resta(NUM1, NUM2) );
    System.out.println ("La multiplicación es " + Aritmetica.multiplicacion(NUM1, NUM2) );
    System.out.println ("La división es " + Aritmetica.division(NUM1, NUM2) );
  }
}
```

```
nano  src/main/java/com/miempresa/app/Aritmetica.java
```


```java
package com.miempresa.app;

public class Aritmetica {

  public static int suma (int sumando1, int sumando2) {
        return (sumando1+sumando2);
  }

  public static int resta  (int minuendo, int sustraendo) {
        return (minuendo-sustraendo);
  }

  public static int multiplicacion (int  numero1, int numero2) {
        return (numero1*numero2);
  }

  public static float division (int dividendo, int divisor) {
        return (dividendo/(float)divisor);
  }

}
```


__Crea 2 clases dentro de la ruta `src/test/java/com/miempresa/app`__:


```
nano  src/test/java/com/miempresa/app/AppTest.java
```

```
package com.miempresa.app;

import org.junit.Test;
import static org.junit.Assert.*;

public class AppTest {

  @Test
  public void testMain() {
      // Prueba vacía
  }

}
```


```
nano  src/test/java/com/miempresa/app/AritmeticaTest.java
```

```
package com.miempresa.app;
                                                                                                                             
import org.junit.Test;                                                                                                       
import static org.junit.Assert.*;                                                                                           
                                                                                                                             
public class AritmeticaTest {                                                                                               

    @Test
    public void testSuma() {
        assertEquals("Suma (2,3) = 5", 5, Aritmetica.suma(2,3));
    }
}
```

4. Edita el archivo `pom.xml` para que aparezca tal como se muestra a continuación:

```
nano  pom.xml
```

```xml
<project>

  <modelVersion>4.0.0</modelVersion>
  <groupId>com.miempresa.app</groupId>
  <artifactId>mi-app</artifactId>
  <version>1.0.0</version>
  <name>mi-app</name>

  <build>
    <plugins>
      <plugin>
        <!-- Para construir un JAR ejecutable -->
        <groupId>org.apache.maven.plugins</groupId>
        <artifactId>maven-jar-plugin</artifactId>
        <version>3.0.2</version>
        <configuration>
          <archive>   
            <manifest>
              <addClasspath>true</addClasspath>
              <classpathPrefix>./</classpathPrefix>
              <mainClass>com.miempresa.app.App</mainClass>
            </manifest>
          </archive>
        </configuration>
      </plugin>

      <plugin>
        <!-- Para ejecutar el JAR creado --> 
        <groupId>org.codehaus.mojo</groupId>
          <artifactId>exec-maven-plugin</artifactId>
          <version>1.2.1</version>
          <configuration>
            <mainClass>com.miempresa.app.App</mainClass>
          </configuration>
       </plugin>
    </plugins>
  </build>

  <dependencies>
    <dependency>
      <!-- Prueba de unidades -->
      <groupId>junit</groupId>
      <artifactId>junit</artifactId>
      <version>4.12</version>
      <scope>test</scope>
    </dependency>
  </dependencies>

</project>

```

5. Para compilar hacemos:

```
mvn  compile
```

En la carpeta `target/classes` obtendremos el bytecode correspondiente a cada clase.


Una forma de ejecutar el bytecode es:

```bash
cd target/classes  &&  java com.miempresa.app.App  &&  cd ../..
```


6. Para empaquetar en JAR hacemos:

```
mvn  package
```

El archivo .jar se guarda en la carpeta `target`. Para ejecutar dicho archivo .jar:

```
mvn  exec:java
```

Otra forma de ejecutar el archivo .jar es:

```bash
java  -jar  target/mi-app-1.0.0.jar
```

7. Para ejecutar las pruebas unitarias:

```bash
mvn  test
```


Si obtenemos algún error, podemos limpiar la construcción con `mvn  clean`. Revisaremos el código y volveremos a empezar.


---

> Referencias: 
> - https://es.wikipedia.org/wiki/Maven
> - https://maven.apache.org/guides/getting-started/maven-in-five-minutes.html
> - https://www.arquitecturajava.com/?s=maven
> - http://maven.apache.org/guides/introduction/introduction-to-the-pom.html

