# Media Player.

## Explicación.  

Este programa emula un reproductor de vídeo para formatos .mp4 y .avi, además puede iniciar la cámara del ordenador  

Este archivo Programa ha sido creado con QT Creator 4.2.1 (QT 5.8).  
	
## Pasos.
 
 1. Dentro de la carpeta *Media_Player* encontraremos los archivos necesarios para compilar.
 2. Al Compilar el programa saldrá una ventana, con un tamaño predefinido con 5 botones
	* Play -> Abrir o reproducir un vídeo.
	* Iniciar Webcam -> Iniciar la cámara web.
	* Stop -> Cierra el archivo de vídeo cargado.
	* Rewind X% -> Decelera la reproducción del vídeo a la cantidad descrita X (cada vez se va dividiendo entre dos).
	* Forwad Y% -> Acelera la reproducción del vídeo a la cantidad descrita por Y ( cada vez se va multiplicando por dos).
 
## Interacciones.

 1. Inicio -> Al iniciar la aplicación, aunque podemos interactuar con todos los botones solo tendrán efecto "Play" e "Iniciar Webcam"
 2. Play -> Al clicar en Play, por primera vez se no abrirá un cuadro de diálogo para de busca de nuestro SO para buscar un archivo .mp4 o .avi y reproducirlo
	* Mientras exista un vídeo activo, este botón tendrá las funciones de:
		* Play -> en caso del que el vídeo esté pausado, lo reproducirá.
		* Pause -> en caso de que el vídeo se encuentre en reproducción, lo pausará.
		* al Clicar, se cambiará al valor necesario.
 3. Iniciar Webcam -> Al clicar en este se abrirá la cámara y reproducirá lo que esta capture
  * Mientras esté en modo captura, el botón cambiará a "Cerrar Webcam" y parará la captura de la misma, Cambiando de nuevo al valor "Iniciar Webcam".
 4. Reproducción - Webcam.
 No podremos iniciar la Webcam en caso de que exista un vídeo activo.  
 De igual forma, si tenemos la Webcam activada, no podremos reproducir ningún vídeo.
 
## Errores

 1. Error de vídeo.
   *En caso de que no sea un error crítico, podrás intentar abrir otro archivo, en otro caso se cerrará el programa.
 2. Error de webcam.
   *En caso de que exista algún error con la WebCam, esta volverá a estar lista para usarse.
