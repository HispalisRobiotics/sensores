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
 *      *)    Conceptos de Programacion: Devolucion de un array desde una funcion: ( I )
 *                                    Asignacion dinámica: Uso de malloc y free
 *                                    Aritmetica de punteros
 *                      
 *  
 *  Notas:    Conceptos Avanzados de programacion
 *  
 *    C no devuelve el tipo [] directamente, aunque se puede hacer indirectamente. 
 *    Hay muchas formas de devolver un array ( indirectamente ) desde una funcion,
 *    aunque todas involucran el uso de punteros
 *      
 *      a) Asignacion dinamica -malloc - en la funcion y posterior llamada a free
 *      b) Haciendo static el array en el constructor 
 *  
 *  
 *  
 *  El sensor emplea las entradas analógicas A0 - A3
 *  
 *  
 */


//  Constantes de preprocesador 
#define PARA   delay(500)
#define FIN    for(;;)


//  Prototipos
int *CreaArray( int );
void PrintLineSensor( int [] );


//    Programa principal 



void setup() 
{
  Serial.begin( 115200 );
}

void loop() 
{
  //    Creamos el array
  int *puntero_a_array = CreaArray( 4 );
  
  
  //  Control del array. Si cambiamos el 4 anterior por 40000 se verá más claro
  if( puntero_a_array )
  {
    //  Las dos lineas siguientes verifican el vector creado
    //PrintLineSensor( puntero_a_array );
    //FIN;
    
    //    Empleamos notacion vectorial

    puntero_a_array[0] = analogRead( A0 );  
    puntero_a_array[1] = analogRead( A1 );
    puntero_a_array[2] = analogRead( A2 );
    puntero_a_array[3] = analogRead( A3 );
    
    
    //  Podemos codificar lo anterior empleando aritmetica de punteros
    //  Para probarlo, comentar las lineas anteriores, y quitar el comentario a las siguientes
    
    /*
      
    *(puntero_a_array+0) = analogRead( A0 );
    *(puntero_a_array+1) = analogRead( A1 );
    *(puntero_a_array+2) = analogRead( A2 );
    *(puntero_a_array+3) = analogRead( A3 );
    
     */

    PARA;
    PrintLineSensor( puntero_a_array );
    PARA;

    //  Liberamos la memoria
    free ( puntero_a_array );
  }
  else
  {
    //  Arduino no tiene memoria para crear un vector de ( por ejemplo )40000 enteros y malloc() falla
    Serial.println("Error de memoria");
    FIN;
  }
      
}



//    Fin del programa principal 







    
void PrintLineSensor( int a[] )
{

for( int ind =0; ind <4 ; ind++)
      Serial.print("\t"+String( a[ind] ));
    Serial.println("");
}   

  
  
int *CreaArray( int elementos )
{
  int *retorno = malloc( elementos*sizeof(int) );

  //  Control de malloc
  if( !retorno )
    return (int *) NULL;

  //  Blanqueamos el array
  memset( retorno , 0 , elementos*sizeof(int) );

  return retorno;
}

