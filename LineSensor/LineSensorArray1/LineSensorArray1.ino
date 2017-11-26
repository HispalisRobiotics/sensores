/*
 *  Hispalis RobIOTics Arduino Trainer 
 *  
 *  Programa: LineSensor
 *  
 *  Proposito:
 *  
 *      Test del sensor de Linea
 *      
 *  Version: ArduinoTrainer v1.0 / Hercules v1.0
 *  Revision:Octubre 2017 
 *  
 *  Proposito:
 *  
 *      1)    Test del Sensor de Linea integrado
 *            
 *      *)    Conceptos de Programacion: Arrays
 *      
 *  
 *  Notas:
 *  
 *  El sensor emplea las entradas analógicas A0 - A3
 *  
 */


//  Constantes de preprocesador 
#define PARA delay(250)



void setup() 
{
  Serial.begin( 115200 );
}

void loop() 
{
  int i[4];
  int ind;

  for(;;)
  { 
    i[0]= analogRead( A0 );
    i[1]= analogRead( A1 );
    i[2]= analogRead( A2 );
    i[3]= analogRead( A3 );
    PARA;

    for( ind =0; ind <4 ; ind++)
      Serial.print("\t"+String( i[ind] ));
    Serial.println("");
    PARA;
  }
}

  
  

