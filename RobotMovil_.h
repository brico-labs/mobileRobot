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
		L298
		TB6612 	(*) incluye un terminal "Enable" que debe estar 
					conectado a +5V para que los motores giren
					
					
					
	FUNCIONES IMPLEMENTADAS
	
	RobotMovil NombreRobot;
			Crea un objeto (robot) con el patillaje del redBot de Sparkfun. 
			Se puede utilizar para cualquier robot con el mismo patillaje.
				CTR_R_1 = pin 2			CTR_L_1 = pin 7
				CTR_R_2 = pin 4			CTR_L_2 = pin 8
				PWM_R   = pin 6			PWM_L   = pin 5
				
	RobotMovil NombreRobot (pin CTR_L_1, pin CTR_L_2, pin PWM_L,
					   		pin CTR_R_1, pin CTR_R_2, pin PWM_R);
			Crea un objeto (robot) con el patillaje que le indiquemos. Los pines 
			PWM_L y PWM_R deben ser capaces de generar una salida PWM.

	NombreRobot.forward(velocidad_L, velocidad_R, tiempo);
			Mueve el robot hacia adelante con las velocidades que se indican 
			en cada una de las ruedas. El rango de velocidades va de 0 a 255,
			aunque es muy posible que con valores pequeños las ruedas no giren.
			La siguiente instrucción se ejecuta pasado el valor tiempo (en milisegundos)

	NombreRobot.reverse(velocidad_L, velocidad_R, tiempo);
			Igual que en el caso anterior, pero con movimiento hacia atrás.
			La siguiente instrucción se ejecuta pasado el valor tiempo (en milisegundos)
		
		
	NombreRobot.brake(tiempo);
			Frena el robot. 
			La siguiente instrucción se ejecuta pasado el valor tiempo (en milisegundos)

	NombreRobot.rotate(tiempo);
			Gira el motor sobre su eje. Las dos ruedas giran en sentido contrario.
			Si el valor de tiempo es positivo, gira en sentido horario. Si el valor 
			de tiempo es negativo gira en sentido anti-horario. La velocidad de giro 
			se puede fijar con  set_velocgiro.
			La siguiente instrucción se ejecuta pasado el valor tiempo (en milisegundos)

	NombreRobot.set_velocgiro (int velocidad_giro);
			Fija el valor de la velocidad de giro para la función rotate.
			El valor puede estar entre 0 y 255. Inicialmente es 175.
	
*/


 #ifndef RobotMovil_
 #define RobotMovil_

class RobotMovil {
  public:  
    RobotMovil ();
    RobotMovil (int CTR_L_1, int CTR_L_2, int PWM_L, int CTR_R_1, int CTR_R_2, int PWM_R);
        
    void forward(int velocidad_L, int velocidad_R, int tiempo);
    void reverse(int velocidad_L, int velocidad_R, int tiempo);
    void rotate (int tiempo);
    void brake  (int tiempo);
   
    void set_velocgiro (int velocidad_giro);
    
    								//      L293D		L298D	   TB6612
		// Motor derecho
    int _CTR_R_1; // pin control de giro      1A		 in1		AIN1
    int _CTR_R_2; // pin control de giro      2A		 in2		AIN2
    int _PWM_R;   // pin velocidad PWM      1,2EN		Ena A		PWMA
		// Motor izquierdo
    int _CTR_L_1; // pin control de giro      3A		 in3		BIN1
    int _CTR_L_2; // pin control de giro      4A		 in4		BIN2
    int _PWM_L;   // pin velocidad PWM      3,4EN		Ena B		PWMB
    
    int _velocidad_giro = 175;  // velocidad de los motores durante los giros (rotate)

};
#endif
