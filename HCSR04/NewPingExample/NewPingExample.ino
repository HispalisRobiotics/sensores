/*
 *  Hispalis RobIOTics Arduino Trainer 
 *  
 *  Programa: NewPingExample
 *  
 *  Proposito:
 *  
 *      Test del sensor HCSR04
 *      Enciende  LED_ROJO si la distancia es menor a     20 cm
 *                LED_AMARILLO si la distancia es menor a 30 cm.
 *                LED_VERDE si la distancia es menor a    40 cm.
 *      
 *  Version: ArduinoTrainer v1.0 / Hercules v1.0
 *  Revision:Octubre 2017 
 *  Proposito:
 *  
 *      1)    Test del Sensor de Linea integrado
 *            
 *      *)    Conceptos de Programacion: Uso de biblioteca externas
 * 
 *  
 *  Notas:
 *  
 *  Para instalar una biblioteca externa ( NewPing )
 *  
 *    a) Descargar el fichero zip
 *    b) Extraerlo en la carpeta Arduino/libraries
 *    
 *    https://github.com/PaulStoffregen/NewPing
 *  
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




// ---------------------------------------------------------------------------
// Example NewPing library sketch that does a ping about 20 times per second.
// ---------------------------------------------------------------------------



#include <NewPing.h>

#define TRIGGER_PIN  2  // 3 Hercules , 2 Trainer
#define ECHO_PIN     4  // 2 Hercules , 4 Trainer
#define MAX_DISTANCE 200 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.

void setup() 
{
  Serial.begin(115200); // Open serial monitor at 115200 baud to see ping results.
}

void loop() 
{
  delay(50);                      // Wait 50ms between pings (about 20 pings/sec). 29ms should be the shortest delay between pings.
  unsigned int uS = sonar.ping(); // Send ping, get ping time in microseconds (uS).
  Serial.print("Ping: ");
  Serial.print(uS / US_ROUNDTRIP_CM); // Convert ping time to distance in cm and print result (0 = outside set distance range)
  Serial.println("cm");
}
