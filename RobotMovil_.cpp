/*Open Source Licensing GPL V2
 * This is the appropriate option if you want to share the source code of your \n
 * application with everyone you distribute it to, and you also want to give them \n
 * the right to share who uses it. If you wish to use this software under Open \n
 * Source Licensing, you must contribute all your source code to the open source \n
 * community in accordance with the GPL Version 2 when your application is \n
 * distributed. See http://www.gnu.org/copyleft/gpl.html
*/
 

/* CREDITOS
	bricolabs.cc
	bricolabs@gmail.com
	
	Autores:
		Félix	
		Manuel
		Rafa
		Sergio
*/
 
 
 /*  Librería para el control básico de motores en robots sencillos 
 	con dos ruedas motrices.
	El objetivo de la librería es que sea lo suficientemente 
	sencilla como para que un usuario básico pueda entender su 
	funcionamiento y pueda atreverse a modificarla y adaptarla
	
	Funciona con drivers para motor con 6 terminales de control: 
	2 en cada motor para indicar el sentido de giro y uno para 
	la velocidad. Entre otros es compatible con los circuitos:
	
		L293D (preferible sobre L293, ya que incluye mayor protección)
		L298D (preferible sobre L298, ya que incluye mayor protección)
		TB662 	(*) incluye un terminal "Enable" que debe estar 
					conectado a +5V para que los motores giren
					
					
					
	FUNCIONES IMPLEMENTADAS
	
	RobotMovil NombreRobot;
	RobotMovil NombreRobot (pin CTR_L_1, pin CTR_L_2, pin PWM_L,
					   		pin CTR_R_1, pin CTR_R_2, pin PWM_R);

	NombreRobot.forward(velocidad_L, velocidad_R, tiempo);
	NombreRobot.reverse(velocidad_L, velocidad_R, tiempo);
	NombreRobot.brake(tiempo);
	NombreRobot.rotate(tiempo);
	NombreRobot.set_velocgiro (int velocidad_giro);
*/


#include <Arduino.h>
#include "RobotMovil.h"

	/*	RobotMovil NombreRobot;
			Crea un objeto (robot) con el patillaje del redBot de Sparkfun. 
			Se puede utilizar para cualquier robot con el mismo patillaje 
				CTR_R_1 = pin 2			CTR_L_1 = pin 7
				CTR_R_2 = pin 4			CTR_L_2 = pin 8
				PWM_R   = pin 6			PWM_L   = pin 5
	*/
RobotMovil::RobotMovil(){
  _CTR_R_1 = 2;
  _CTR_R_2 = 4;
  _PWM_R   = 6;

  _CTR_L_1 = 7;
  _CTR_L_2 = 8;
  _PWM_L   = 5;
  
  pinMode(_CTR_R_1, OUTPUT);
  pinMode(_CTR_R_2, OUTPUT);
  pinMode(_PWM_R,   OUTPUT);

  pinMode(_CTR_L_1, OUTPUT);
  pinMode(_CTR_L_2, OUTPUT);
  pinMode(_PWM_L,   OUTPUT);
}


	/*	RobotMovil NombreRobot (pin CTR_L_1, pin CTR_L_2, pin PWM_L,
					   		pin CTR_R_1, pin CTR_R_2, pin PWM_R);
			Crea un objeto (robot) con el patillaje que le indiquemos. 
	*/
RobotMovil::RobotMovil(int CTR_L_1, int CTR_L_2, int PWM_L,
					   int CTR_R_1, int CTR_R_2, int PWM_R){
  _CTR_L_1 = CTR_L_1;
  _CTR_L_2 = CTR_L_2;
  _PWM_L   = PWM_L;
  
  _CTR_R_1 = CTR_R_1;
  _CTR_R_2 = CTR_R_2;
  _PWM_R   = PWM_R;

  pinMode(_CTR_L_1, OUTPUT);
  pinMode(_CTR_L_2, OUTPUT);
  pinMode(_PWM_L,   OUTPUT);

  pinMode(_CTR_R_1, OUTPUT);
  pinMode(_CTR_R_2, OUTPUT);
  pinMode(_PWM_R,   OUTPUT);
}

	/*	NombreRobot.forward(velocidad_L, velocidad_R, tiempo);
			Mueve el robot hacia adelante con las velocidades que se indican 
			en cada una de las ruedas. El rango de velocidades va de 0 a 255,
			aunque es muy posible que con valores pequeños las ruedas no giren.
			La siguiente instrucción se ejecuta pasado el valor tiempo (en milisegundos)
	*/
void RobotMovil::forward(int velocidad_L, int velocidad_R, int tiempo)
{
  digitalWrite(_CTR_L_1, LOW);
  digitalWrite(_CTR_L_2, HIGH);
  analogWrite(_PWM_L, constrain (velocidad_L, 0, 255));

  digitalWrite(_CTR_R_1, LOW);
  digitalWrite(_CTR_R_2, HIGH);
  analogWrite(_PWM_R, constrain (velocidad_R, 0, 255));

  delay (abs (tiempo));

  brake (0);
}


	/*	NombreRobot.reverse(velocidad_L, velocidad_R, tiempo);
			Igual que en el caso anterior, pero con movimiento hacia atrás.
			La siguiente instrucción se ejecuta pasado el valor tiempo (en milisegundos)
	*/
void RobotMovil::reverse(int velocidad_L, int velocidad_R, int tiempo)
{
  digitalWrite(_CTR_L_1, HIGH);
  digitalWrite(_CTR_L_2, LOW);
  analogWrite(_PWM_L, constrain (velocidad_L, 0, 255));
  
  digitalWrite(_CTR_R_1, HIGH);
  digitalWrite(_CTR_R_2, LOW);
  analogWrite(_PWM_R, constrain (velocidad_R, 0, 255));

  delay (abs (tiempo));

  brake (0);
}

	/*	NombreRobot.brake(tiempo);
			Frena el robot. 
			La siguiente instrucción se ejecuta pasado el valor tiempo (en milisegundos)
	*/
void RobotMovil::brake(int tiempo)
{
  digitalWrite(_CTR_L_1, LOW);
  digitalWrite(_CTR_L_2, LOW);
  analogWrite(_PWM_L, 255);

  digitalWrite(_CTR_R_1, LOW);
  digitalWrite(_CTR_R_2, LOW);
  analogWrite(_PWM_R, 255);

  delay (abs (tiempo));
}


	/*	NombreRobot.rotate(tiempo);
			Gira el motor sobre su eje. Las dos ruedas giran en sentido contrario.
			Si el valor de tiempo es positivo, gira en sentido horario. Si el valor 
			de tiempo es negativo gira en sentido anti-horario. La velocidad de giro 
			se puede fijar con  set_velocgiro.
			La siguiente instrucción se ejecuta pasado el valor tiempo (en milisegundos)
	*/
void RobotMovil::rotate(int tiempo)
{
  analogWrite(_PWM_L, _velocidad_giro);
  analogWrite(_PWM_R, _velocidad_giro);

  if (tiempo > 0) {
    digitalWrite(_CTR_L_1, LOW);
    digitalWrite(_CTR_L_2, HIGH);
    digitalWrite(_CTR_R_1, HIGH);
    digitalWrite(_CTR_R_2, LOW);
   }
  else
  {
    digitalWrite(_CTR_L_1, HIGH);
    digitalWrite(_CTR_L_2, LOW);
    digitalWrite(_CTR_R_1, LOW);
    digitalWrite(_CTR_R_2, HIGH);
} 

  delay(abs(tiempo));

  brake (0);
  }


	/*	NombreRobot.set_velocgiro (int velocidad_giro);
			Fija el valor de la velocidad de giro para la función rotate.
			El valor puede estar entre 0 y 255. Inicialmente es 175.
	*/
void RobotMovil::set_velocgiro (int velocidad_giro)
{
  _velocidad_giro = constrain (velocidad_giro, 0, 255);
}