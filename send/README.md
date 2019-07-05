Archivos necesarios para enviar archivos a otro computador mediante sockets. 

Antes de todo, debe editar el archivo y agregar el IP de la máquina a la que desea enviar los archivos, verificar que los nombres de los archivos correspondan a los que desea enviar y que se ubiquen en el directorio indicado. 

Liego, para compilar el código, debe posicionarse mediante la terminal de linux en el directorio donde se ubican estos y correr el siguiente comando:

	g++ Socket.h Socket.cpp main.cpp -o send

Este generará un ejetutable llamado send el cual puede ejecutar mediante el comando:

	./send 

Y de esta manera iniciará el envío de los archivos.

