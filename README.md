RobotMovil
==========
Inspirado en el trabajo de Félix Sánchez Tembleque https://github.com/brico-labs/ArduinoDCmotorDrivers


Librería básica para empezar un programa para un robot móvil y programas de ejemplo

- Arduino con la placa RedBot de Sparkfun u otra de control de motores(puede modificarse el .cpp
  y usar otras placas de motores)
- Dos motores de DC (o cuatro pareados)
- Sensores de ultrasonidos HR SR-04
- Sensores de líneas

Los archivos de librería RobotMovil.h y RobotMovil.cpp deben estar en la carpeta de librerías personales de Arduino

Las funciones de esa librería son


RobotMovil nombredelobjeto; 
    // para crear el objeto que se usará luego. Válido para el redBot

RobotMovil nombredelobjeto ((CTR_R_1, CTR_R_2, PWM_R, CTR_L_1, CTR_L_2, PWM_L); 
    // para crear el objeto que se usará luego. Configurable pin a pin


    CTR_R_1, CTR_R_2 (enteros) Patas del arduino donde estan los controles para el motor derecho
    PWM_R            (entero)  Pata de control de velocidad del motor derecho
    CTR_L_1, CTR_L_2 (enteros) Patas del arduino donde estan los controles para el motor izquierdo
    PWM_L            (entero)  Pata de control de velocidad del motor izquierdo


nombredelobjeto.forward (velocidad_L, velocidad_R, tiempo); 
    // movimiento hacia adelante con r,l velocidad de las ruedas izquierda y derecha entre 0 y 255,
       durante t tiempo en ms

nombredelobjeto.reverse (velocidad_L, velocidad_R, tiempo); 
    // idem hacia atrás

nombredelobjeto.rotate(tiempo); 
    // gira durante un tiempo t (positivo o nevativo para girar a derecha e izquierda

nombredelobjeto.brake(tiempo); 
    // para durante un tiempo t los dos motores

    velocidad_L (entero) velocidad de la rueda izquierda
    velocidad_R (entero) velocidad de la rueda derecha
    tiempo      (unsigned long) tiempo en miclisegundos


void set_velocgiro (int velocidad_giro);
	// ajusta el valor de la velocidad de giro de la función rotate. 
	// Inicialmente es 175. si resulta demasiado lenta o demasiado rapida se
	// puede ajustar con esta función. 
	
	int velocidad_giro (entero) nuevo valor de la velocidad de giro. entre 0 y 255.

Los ejemplos de uso necesitan además la librería NewPing.h
