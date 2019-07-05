Archivos necesarios para recibir archivos mediante sockets. 

Para compilar debe posicionarse mediante la terminal de linux en el directorio donde esto se encuentran y ejecutar el siguiente comando en consola:

	g++ Socket.h Socket.cpp main.cpp -o receive

el cual generará un archivo ejecutable llamado receive que debe correr mediante el comando:

	./receive

Y en otra computadora iniciar el envío de archivos.
