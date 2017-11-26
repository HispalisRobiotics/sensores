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
 *      *)    Conceptos de Programacion: Caracteres ASCII
 *                                    Funciones de libreria: String()
 *  
 *  Notas:
 *  
 *  El sensor emplea las entradas analógicas A0 - A3
 *  
 */



//    Constantes de preprocesador
#define PARA delay(500)



void setup() 
{
  Serial.begin( 115200 );
}

void loop() 
{
  int s1 , s2 , s3 , s4;
  int ind;

  for(;;)
  { 
    s1 = analogRead( A0 );
    s2 = analogRead( A1 );
    s3 = analogRead( A2 );
    s4 = analogRead( A3 );
    PARA;

    for( ind =0; ind <4 ; ind++)
      Serial.println("LineSensor -->\tS1:"+String(s1)+"   \tS2:"+String(s2)+"   \tS3:"+String(s3)+"   \tS4:"+String(s4) );
    PARA;
  }
}

  
  

