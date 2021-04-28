//#include <Keyboard.h>

#define TECLA 2

void setup() {
  pinMode(TECLA,INPUT);
  //Keyboard.begin();
  //delay(5000);
  Serial.begin(9600);
}

void loop() {
  int tecla = digitalRead(TECLA);
  //if(tecla < 1000){
    //Serial.print("presionado");
    //Keyboard.press(KEY_RIGHT_GUI);
    //delay(100);
    //Keyboard.releaseAll();
  //}
  //else{
    //Serial.print("no presionado");
  //}
  Serial.println(tecla);
  
  //Keyboard.press(KEY_RIGHT_GUI);
  //Keyboard.press('r');
  //delay(100);
  //Keyboard.releaseAll();  
  delay(500);
}
