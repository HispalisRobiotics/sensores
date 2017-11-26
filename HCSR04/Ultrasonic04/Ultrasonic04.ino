/*Por aqui. El ultimo
 *  Hispalis RobIOTics Arduino Trainer 
 *  
 *  Programa: Ultrasonic04
 *  
 *  Proposito:
 *  
 *      Test del sensor HCSR04
 *      Enciende LED_ROJO si la distancia es menor a 20 cm,
 *         y el LED_VERDE si la distancia es menor a 30 cm.
 *      
 *  Version: ArduinoTrainer v1.0 / Hercules v1.0
 *  Revision:Octubre 2017 
 *  Proposito:
 *  
 *      1)    Test del Sensor de Linea integrado
 *            
 *      *)    Conceptos de Programacion: Decisiones: if() .. else if()
 * 
 *  
 *  Notas:
 *  
 *  ¡ Ojo con cómo se anidan las condiciones !
 *  Esta no es la mejor codificacion en este caso ... ¿ por que ?
 *  
 *  El sensor HCSR04 posee 2 pines, ECHO y TRIGGER. 
 *  Los pines pertinentes corresponden a las E/S siguientes
 *  
 *  Arduino Trainer v1.0
 *    ECHO:     Pin 4 
 *    TRIGGER:  Pin 2
 *  
 *  Hercules v1.0
 *    ECHO:     Pin 2 
 *    TRIGGER:  Pin 3
 *  
 */

//  Constantes de preprocesador
#define HCSR04_ECHO           4
#define HCSR04_TRIGGER        2

#define LED_ROJO              3
#define LED_AMARILLO          5
#define LED_VERDE             6



//   Prototipos



void setup() 
{
  pinMode(HCSR04_TRIGGER , OUTPUT);
  pinMode(HCSR04_ECHO , INPUT);

  pinMode(LED_ROJO , OUTPUT);
  pinMode(LED_AMARILLO , OUTPUT);
  pinMode(LED_VERDE , OUTPUT);
  
  Serial.begin( 115200); 
}

void loop() 
{
  int distancia;
  distancia = Distance_StandardTest();
  Serial.println( "Distancia ... "+ String(distancia) + " cm.");
  
  //  Bloque if-else
  if( distancia < 20 )
  {
    digitalWrite( LED_AMARILLO , LOW );  
    digitalWrite( LED_VERDE , LOW );
    digitalWrite( LED_ROJO , HIGH );
  }
  else if( distancia < 30 )
  {
    digitalWrite( LED_ROJO , LOW );
    digitalWrite( LED_VERDE , LOW );
    digitalWrite( LED_AMARILLO , HIGH );
  }
  
  else if( distancia < 40 )
  {
    digitalWrite( LED_ROJO , LOW );
    digitalWrite( LED_AMARILLO , LOW );  
    digitalWrite( LED_VERDE , HIGH );
  }
    
  
   
  delay( 100 );
}







/* 
    Funcion:  Distance_StandardTest()
        
      Devuelve en cm la distancia del sensor HCSR04 al objeto más cercano

      Funcionamiento:
      
        1)    Lanzamos un pulso de señal cuadrado. Para ello el pin TRIGGER 
                a) Lo ponemos a LOW, y esperamos un tiempo a que se estabilice ( por si estaba en nivel HIGH )
                b) Lo ponemos a HIGH, y esperamos un tiempo
                c) Lo ponemos a LOW again
        2)  El sensor devuelve un pulso de entrada en el pin ECHO, que es el tiempo de ida y vuelta del sonido
  
        3)  Con una formula lo convertimos a cm.
*/
int Distance_StandardTest(void) 
{
  long duracion, distancia;

  //  Pulso en TRIGGER
  digitalWrite(HCSR04_TRIGGER , LOW);
  delayMicroseconds(5);           
  digitalWrite(HCSR04_TRIGGER, HIGH);
  delayMicroseconds(10);          
  digitalWrite(HCSR04_TRIGGER, LOW);
  
  //  Pulso de ECHO
  duracion = pulseIn(HCSR04_ECHO , HIGH) ;    

  //  Conversion a int. Podemos convertir a float ...
  distancia = (int) (duracion / 59.2 ) ;   //distancia = (int) (duracion / 2 / 29.1 ) ;
  
  //Serial.println( "Distancia ... "+ String(distancia) + " cm.") ;
  
  return distancia;
}
