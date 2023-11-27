# Archivos JMOD

- Ruta:  /usr/lib/jvm/java-17-openjdk-amd64/jmods
- Documentación: https://www.herongyang.com/Java-Tools/jmod-The-JMOD-File-Tool.html


## Prerrequisito: Instalación de JDK

```console
sudo  apt  installl  openjdk-17-jdk
```

## Ejemplos


```console
cd /usr/lib/jvm/java-17-openjdk-amd64/jmods 
ls
jmod describe java.base.jmod
jmod list java.base.jmod

cp java.base.jmod  base.jmod

jmod extract base.jmod --dir base
cd base
tree | less
```

## Descargar Bytecode Viewer

- Releases: https://github.com/Konloch/bytecode-viewer/releases
- Bytecode-Viewer-2.11.2.jar: https://github.com/Konloch/bytecode-viewer/releases/download/v2.11.2/Bytecode-Viewer-2.11.2.jar 

Una vez descargado, para ejecutar hacer:

```console
java -jar Bytecode-Viewer-2.11.2.jar
```

## Documentación

- https://www.campusmvp.es/recursos/post/Descifrando-Java-lenguaje-plataforma-ediciones-implementaciones.aspx
- https://www.xataka.com/historia-tecnologica/asi-es-como-oracle-ha-sometido-a-sun-microsystems-a-una-muerte-larga-y-agonica
- https://stackoverflow.com/questions/44732915/why-did-java-9-introduce-the-jmod-file-format
