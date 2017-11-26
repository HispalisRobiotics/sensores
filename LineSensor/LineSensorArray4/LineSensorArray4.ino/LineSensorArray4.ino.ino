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
 *                                    Tipos de almacenamiento en memoria
 *      
 *  
 *  Notas:    Conceptos Avanzados de programacion
 *  
 *  Solución al programa LineSensor3
 *  
 *  
 *  Pista: Explicar qué es el stack, y una variable LOCAL
 *  Los arrays se pasan por referencia, dando la direccion base -nombre- del array  
 *  Aunque hay dos formas diferentes de devolver un array ( no este ejemplo )
 *  
 *  
 *  El sensor emplea las entradas analógicas A0 - A3
 *  
 *  
 */


//  Constantes de preprocesador 
#define PARA delay(500)



//  Prototipos
int * ReadLineSensor( void );
void PrintLineSensor( int * );


//    Programa principal 



void setup() 
{
  Serial.begin( 115200 );
}

void loop() 
{
  int *irsensor;
  
  for(;;)
  { 
    irsensor = ReadLineSensor();
    PARA;
    PrintLineSensor( irsensor );
    PARA;
  }
}



//    Fin del programa principal 





int * ReadLineSensor( void )
{
  static int a[4];
  a[0]= analogRead( A0 );
  a[1]= analogRead( A1 );
  a[2]= analogRead( A2 );
  a[3]= analogRead( A3 );
  return a;
}


    
void PrintLineSensor( int *a )    // similar a void PrintLineSensor( int a[] )
{

for( int ind =0; ind <4 ; ind++)
      Serial.print("\t"+String( a[ind] ));
    Serial.println("");
}   

  
  

