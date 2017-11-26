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
 *      *)    Conceptos de Programacion: Arrays, funciones
 *                                    Paso de un array como argumento 
 *  
 *  Notas:
 *  
 *  El sensor emplea las entradas analógicas A0 - A3
 *  
 */


//  Constantes de preprocesador
#define PARA delay(250)

//  Prototipos
void PrintLineSensor( int [] );
void LeeLineSensor( int [] );



//    Programa principal 



void setup() 
{
  Serial.begin( 115200 );
}



void loop() 
{
  int irsensor[4];
  int ind;

  for(;;)
  { 
    LeeLineSensor( irsensor );
    PARA;

    PrintLineSensor( irsensor );
    PARA;
  }
}



//    Fin del programa principal 





void LeeLineSensor( int a[] )
{
    a[0]= analogRead( A0 );
    a[1]= analogRead( A1 );
    a[2]= analogRead( A2 );
    a[3]= analogRead( A3 );
}



void PrintLineSensor( int a[] )
{

  for( int ind =0; ind <4 ; ind++)
    Serial.print("\t"+String( a[ind] ));
  Serial.println("");
  delay(250);  
}   

  
  

