#include <RobotMovil_.h>

RobotMovil robot;

void setup()
{
  pinMode (3, OUTPUT);
  digitalWrite (3, HIGH);
}

void loop()
{
  robot.forward(175,175,1000); // avance con velocidad rueda derecha, rueda izquierda y tiempo en ms
  robot.reverse(120,120,2000); // idem pero retroceso
  robot.rotate(1000); // giro durante un tiempo en ms, valores negativo o positivos indican sentido de giro
  robot.rotate(-1000); // giro durante un tiempo en ms, valores negativo o positivos indican sentido de giro
  robot.brake(1000); // detiene el robot un tiempo
}
