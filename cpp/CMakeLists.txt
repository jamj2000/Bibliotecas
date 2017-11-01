CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
PROJECT(MyProject)

SET(CMAKE_BUILD_TYPE       Release)
SET(EXECUTABLE_OUTPUT_PATH bin)
SET(LIBRARY_OUTPUT_PATH    lib)

INCLUDE_DIRECTORIES (${PROJECT_SOURCE_DIR}/MyLib1  ${PROJECT_SOURCE_DIR}/MyLib2)

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
