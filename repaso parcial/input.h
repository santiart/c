/** \brief                  SUMA DOS OPERANDOS.
 * \param numeroX float     PRIMER OPERANDO.
 * \param numeroY float     SEGUNDO OPERANDO.
 * \return float            RESULTADO DE LA SUMA.
 */
float sumar(float numeroX, float numeroY);

/** \brief                  RESTA DOS OPERANDOS.
 * \param numeroX float     PRIMER OPERANDO.
 * \param numeroY float     SEGUNDO OPERANDO.
 * \return float            RESULTADO DE LA RESTA.
 */
float restar(float numeroX, float numeroY);

/** \brief                  DIVIDE ENTRE DOS OPERANDOS, VERIFICA SI SE INGRESA 0.
 * \param numeroX float     PRIMER OPERANDO.
 * \param numeroY float     SEGUNDO OPERANDO
 * \return float            DEVUELVE RESULTADO DE DIVISION.
 */
float dividir(float numeroX, float numeroY);

/** \brief                  MULTIPLICA DOS OPERANDOS. VERIFICA QUE EL OPERANDOS B NO SEAN 0.
 * \param numeroX float     PRIMER OPERANDO.
 * \param numeroY float     SEGUNDO OPERANDO.
 * \return float            DEVUELVE RESULTADO DE MULTIPLICACION.
 */
float multiplicar(float numeroX, float numeroY);

/** \brief                  SACA FACTORIAL DEL NUMERO A QUE PEDIMOS.
 * \param numeroX int       NUMERO QUE NOS BRINDA EL USUARIO. VERIFICA SI EL NUMERO ES 0.
 * \return unsigned long    RESULTADO FACTORIAL NUMERO X. RETORNA EL RESULTADO FACTORIAL DEL NUMERO QUE NOS MANDO EL USUARIO.
 */
unsigned long factorial(int numero);

/** \brief                  PEDIR DATOS ENTEROS ANALIZARLOS VALIDARLOS Y MOSTRARLOS.
 * \param min int           DATO MINIMO A COMPARAR.
 * \param max int           DATO MAXIMO A COMPARAR.
 * \param dato int*         PUNTERO DATO.
 * \param intentos int      INTENTOS PARA REALIZAR OPERACION.
 * \param tipoDato char*    TIPO DE DATO A INGRESAR. Ejemplo: edad, numeros, letras, etc.
 * \param mensaje char*     MENSAJE A RECIBIR.
 * \param eMensaje char*    MENSAJE EN CASO DE ERROR.
 * \return int              DEVUELVE SI LA FUNCION FUNCIONO.
 */
int getData(int min, int max, int* dato, int intentos, char* tipoDato, char* mensaje, char* eMensaje);

/** \brief                  PEDIMOS UN MENSAJE Y EL INGRESO DE UN NUMERO ENTERO.
 * \param char* int         PUNTERO A CHAR QUE VA A SER EL MENSAJE QUE VAMOS A MOSTAR.
 * \return int              DEVUELVE EL ENTERO.
 */
int getInt(char* mensaje);

/** \brief                  PIDE UN FLOAT Y LO DEVUELVE
 * \param numero float      FLOAT A PEDIR.
 * \return float            DEVUELVE FLOAT.
 */
float getFloat(char* mensaje);

/** \brief                  PIDE UN CHAR Y LO DEVUELVE
 * \param texto char        CHAR A PEDIR.
 * \return char             DEVUELVE CHAR.
 */
char getChar(char* mensaje);

/** \brief                  PEDIMOS UN NUMERO VALIDAMOS QUE NO SEA O CONTENGA LETRAS.
 * \param cadena char*      PUNTERO A CADENA DONDE NOS INGRESARA LOS DATOS A ANALIZAR.
 * \return int              DEVUELVE SI FUNCIONO LA OPERACION.
 */
int esNumerico(char cadena[]);

int esDia(int dia);
int esMes(int mes);
int esAnio(int anio);

int esSoloLetra(char letra);

/** \brief                  VALIDA QUE SOLO SEAN LETRAS LAS INGRESADAS.
 * \param cadena[] char     RECIBE UN PUNTERO A CADENA CON LA INFO DEL USUARIO.
 * \return int              DEVUELVE SI SE PUDO REALIZAR ACCION.
 */
int esSoloLetras(char cadena[]);

/** \brief                  VALIDA SI SE INGRESA ALFA NUMERICOS.
 * \param cadena[] char     RECIBE UN PUNTERO A CADENA CON LA INFO DEL USUARIO.
 * \return int              DEVUELVE SI PUDO REALIZAR ACCION.
 */
int esAlfaNumerico(char cadena[]);

/** \brief                  VALIDA SI ES TELEFONO.
 * \param cadena[] char     RECIBE UN PUNTERO A CADENA CON LA INFO DEL USUARIO.
 * \return int              DEVUELVE SI REALIZO OPERACION.
 */
int esTelefono(char cadena[]);

/** \brief                  ORDENA UN ARRAY
 * \param cadena[] char     RECIBE UNA CADENA SEA CUAL SEA.
 * \param largoCadena int   RECIBE UN LARGO DE LA CADENA.
 * \param signo char        RECIBE UN SIGNO PARA SABER DE QUE MANERA QUEREMOS ORDENARLA, EJ.: <  menor, >  mayor.
 * \return int              DEVUELVE ENTERO PARA SABER SI SE PUDO REALIZAR ACCION.
 */
int burbujeo(char cadena[],int largoCadena,char signo);

/** \brief                  RECIVE UN VECTOR DE CADENA Y LO SETEA EN SU ESTADO OCUPADO EN '0'.
 * \param vec[] eEmpleado   EL VECTOR A RECIBIR.
 * \param tam int           EL TAMAÑO DE ESE VECTOR.
 * \return void             NO RETORNA NADA.
 */
