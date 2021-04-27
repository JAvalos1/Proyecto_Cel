//#include <Keyboard.h>

void setup() {
  pinMode(A0,INPUT);
  //Keyboard.begin();
  //delay(5000);
  Serial.begin(9600);
}

void loop() {
  int tecla = analogRead(A0);
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
  //delay(1000);
}
