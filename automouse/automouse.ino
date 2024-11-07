#include <Mouse.h>
#include <Keyboard.h>
#include <KeyboardLayout.h>

#define SW_PIN 7
#define KEY_SHIFT 0x81

void setup() {
  pinMode(SW_PIN, INPUT_PULLUP);
}
int buttonState = 0;
int mov_x = 0;
int mov_y = 0;

int interval = 0;
bool is_init_done = false;
void loop() {
  if(!is_init_done){
      Mouse.begin();
      Keyboard.begin();
      is_init_done = true;
  }
  
  buttonState = digitalRead(SW_PIN);
  
  mov_x = random(-101, 101);
  mov_y = random(-101, 101);
  
  interval = random(5, 5000);
  
  if (buttonState == LOW) {     // ボタンが押されていたら
    Mouse.move(mov_x, mov_y, 0);
    delay(100);

    delay(10);
    Keyboard.releaseAll();
  } 
  else {
  }
  delay(interval);
}
