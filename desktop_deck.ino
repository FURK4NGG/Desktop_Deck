#include <SoftwareSerial.h>
#include <Keyboard.h>
#include <Mouse.h>

#define Buton A0
#define role_d 6
int role = 7;
int roleK = 0;
int i,a = 0;
int buton_durumu;
int veri;

void setup() {
  Serial.begin(9600);
  pinMode(Buton ,INPUT);
  pinMode(role,OUTPUT);     
  digitalWrite(role,HIGH);
}
void loop() {
  int buton_durumu = analogRead(Buton);
  int roled = digitalRead(role_d);
  Serial.println(buton_durumu);  
  if (roled==1){
    int roleK = !i;
    i=!i;
    digitalWrite(role,roleK);
    }
 if(Serial.available()){  //Seri haberleşmeden veri gelmesini bekliyoruz.
    veri = Serial.read();
    Serial.println(veri);//Seri haberleşmeden gelen veriyi okuyoruz.
  }
   delay(500);
  if (buton_durumu > 900 && buton_durumu < 1030){
    printscreen();
  }
  else if(buton_durumu > 500 && buton_durumu < 600){
    kapat();
    }
}

void printscreen(){
  Keyboard.press(KEY_LEFT_GUI);
  delay(100);
  Keyboard.press(KEY_LEFT_SHIFT);
  delay(100);
  Keyboard.press('s');
  delay(100);
  Keyboard.releaseAll();
  delay(1000);
  Keyboard.write(KEY_TAB);
  delay(500);
  Keyboard.write(KEY_TAB);
  delay(500);
  Keyboard.write(KEY_DOWN_ARROW);
  delay(800);
  Keyboard.press(KEY_DOWN_ARROW);
  delay(500);
  Keyboard.releaseAll();      
  delay(500);}

void altf4s(){
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press('s');
    delay(1000);
    Keyboard.press(KEY_LEFT_ARROW);
    delay(100);
    Keyboard.press(KEY_RETURN);
    Keyboard.press(KEY_RETURN);
    Keyboard.releaseAll();
    delay(100);
    Keyboard.press(KEY_LEFT_ALT);
    Keyboard.press(KEY_F4);
    delay(100);
    Keyboard.press(KEY_RETURN);
    Keyboard.releaseAll();
    delay(1000);}

void kapat(){
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.press(KEY_DELETE);
  delay(500);
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();}

void wifi(){
    Mouse.move(600 / 5, 600 / 5, 0);
    Mouse.press(MOUSE_LEFT);
    Keyboard.press(KEY_TAB);
    delay(100);
    Keyboard.press(KEY_TAB);
    delay(100);
    Keyboard.press(KEY_TAB);
    delay(100);
    Keyboard.press(KEY_RETURN);
    delay(100);
    Keyboard.press(KEY_RETURN);
    Keyboard.releaseAll();
    delay(500);
    Keyboard.print("Wifi");
    delay(500);
    Keyboard.press(KEY_RETURN);
    Keyboard.press(KEY_TAB);
    delay(100);
    Keyboard.press(KEY_RETURN);
    delay(100);
    Mouse.press(MOUSE_LEFT);
    delay(100);
    Mouse.release(MOUSE_LEFT);
    Keyboard.releaseAll();
    delay(2000);}

//LINUX

void linux_kapat(){
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press('x');
  delay(100);
  Keyboard.releaseAll();
  delay(1000);
  Keyboard.print("sudo shutdown now");
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();}

void linux_printscreen(){
  a=!a;
  if(a==1){
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press(KEY_LEFT_SHIFT);
    Keyboard.press(KEY_PRINT_SCREEN);
    delay(100);
    Keyboard.releaseAll();}
  else{
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press(KEY_LEFT_SHIFT);
    Keyboard.press(KEY_PAUSE);
    delay(100);
    Keyboard.releaseAll();}
  }
