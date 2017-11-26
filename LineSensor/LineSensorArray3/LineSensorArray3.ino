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
 *      *)    Conceptos de Programacion: Funcion que devuelve un array
 *      
 *  
 *  Notas:
 *  
 *  Este programa es incorrecto ¿ por qué ?
 *  Y solo devuelve un valor correcto de sensor ¿ Cual ?
 *  
 *  
 *  
 *  El sensor emplea las entradas analógicas A0 - A3
 *  
 *  
 */


//  Constantes de preprocesador 
#define PARA delay(500)



//  Prototipos
int ReadLineSensor( void );
void PrintLineSensor( int [] );


//    Programa principal 



void setup() 
{
  Serial.begin( 115200 );
}

void loop() 
{
  int irsensor[4];
  
  for(;;)
  { 
    *irsensor = ReadLineSensor();
    PARA;
    PrintLineSensor( irsensor );
    PARA;
  }
}



//    Fin del programa principal 





int ReadLineSensor( void )
{
  int a[4];
  a[0]= analogRead( A0 );
  a[1]= analogRead( A1 );
  a[2]= analogRead( A2 );
  a[3]= analogRead( A3 );
  return *a;
}


    
void PrintLineSensor( int a[] )
{

for( int ind =0; ind <4 ; ind++)
      Serial.print("\t"+String( a[ind] ));
    Serial.println("");
}   

  
  

