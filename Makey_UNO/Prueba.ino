/*Prueba para emular un teclado USB con arduino*/
//Buffer estandar de comunicacion USB
uint8_t buf[8]={0};
//Se definen los pines y las teclas que se implementaran
#define PIN_TECLA_DER 5
#define PIN_TECLA_IZQ 6
#define PIN_TECLA_SPC 7

/*Se definen los codigos que corresponden a cada tecla
dentro de este protocolo*/
#define COD_TECLA_DER 0X4F  //Flecha derecha
#define COD_TECLA_IZQ 0X50  //Flecha izquierda
#define COD_TECLA_SPC 0X2C  //espacio

/*Se emplea una maquina de estados para controlar si
se pulsan las teclas*/
int state = 1;

void setup()
{
  Serial.begin(9600);
  pinMode(PIN_TECLA_DER, INPUT);
  pinMode(PIN_TECLA_IZQ, INPUT);
  pinMode(PIN_TECLA_SPC, INPUT);
  //Se habilitan los pull up internos
  digitalWrite(PIN_TECLA_DER, 1);
  digitalWrite(PIN_TECLA_IZQ, 1);
  digitalWrite(PIN_TECLA_SPC, 1);

  delay(200);
}

void loop()
{
  state = digitalRead(PIN_TECLA_DER);
  if(state!=1){
    buf[2] = COD_TECLA_DER;
    Serial.write(buf,8);  //se envia la tecla por el Buffer
    releaseKey();  //se deja de presionar la tecla
  }

  state = digitalRead(PIN_TECLA_IZQ);
  if(state!=1){
    buf[2] = COD_TECLA_IZQ;
    Serial.write(buf,8);  //se envia la tecla por el Buffer
    releaseKey();  //se deja de presionar la tecla
  }

  state = digitalRead(PIN_TECLA_DER);
  if(state!=1){
    buf[2] = COD_TECLA_SPC;
    Serial.write(buf,8);  //se envia la tecla por el Buffer
    releaseKey();  //se deja de presionar la tecla
  }
}

void releaseKey()
{
  buf[0] = 0;
  buf[2] = 0;
  Serial.write(buf,8);  //Se suelta la tecla
  delay(300);
}
