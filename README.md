One Time Pad
-----------
### Compilación
Con el comando `make` crea un ejecutable llamado `onetimepad`.

### Cifrar un archivo
Para cifrar un archivo coloque el comando `./onetimepad --cipher filename.ext`. El comando crea dos archivos:
1. `cipher` que contiene la cadena cifrada.
2. `key` que contiene la clave que se utilizó para cifrar el archivo.

### descifrar un archivo
Para recuperar el archivo coloque el comando `./onetimepad --decipher cipher_file --key key_file`. El comando crea un archivo:
1. `decipher` que contiene la cadena original. 

<hr>
Elaborado por Edilson Fernando Gonzalez - UNITEC - Mayo 2015
