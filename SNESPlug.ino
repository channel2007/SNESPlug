#include <Arduino.h>
#include <BleGamepad.h>

#include "GameControllers.h"

// SNES PIN.
const int LATCH_PIN = 16;
const int CLOCK_PIN = 17;
const int DATA_PIN_0 = 18;  

GameControllers controllers;

BleGamepad bleGamepad;

void setup()
{  
  Serial.begin(115200);
  
  controllers.init(LATCH_PIN, CLOCK_PIN);   
  controllers.setController(0, GameControllers::SNES, DATA_PIN_0);

  Serial.println("Starting BLE work!");
  
  bleGamepad.begin();
}

void loop()
{
  //read all controllers at once
  controllers.poll(); 

  if (bleGamepad.isConnected()){
    if(controllers.down(0, GameControllers::START)){
      //Serial.println("Start");
      bleGamepad.press(BUTTON_12);
    }else{
      bleGamepad.release(BUTTON_12);
    }
    if(controllers.down(0, GameControllers::SELECT)){
      //Serial.println("SELECT");
      bleGamepad.press(BUTTON_11);
    }else{
      bleGamepad.release(BUTTON_11);
    }
    if(controllers.down(0, GameControllers::A)){
      //Serial.println("A");
      bleGamepad.press(BUTTON_2);
    }else{
      bleGamepad.release(BUTTON_2);
    }
    if(controllers.down(0, GameControllers::B)){
      //Serial.println("B");
      bleGamepad.press(BUTTON_1);
    }else{
      bleGamepad.release(BUTTON_1);
    }
    if(controllers.down(0, GameControllers::X)){
      //Serial.println("X");
      bleGamepad.press(BUTTON_5);
    }else{
      bleGamepad.release(BUTTON_5);
    }
    if(controllers.down(0, GameControllers::Y)){
      //Serial.println("Y");
      bleGamepad.press(BUTTON_4);
    }else{
      bleGamepad.release(BUTTON_4);
    }
    if(controllers.down(0, GameControllers::L)){
      //Serial.println("L");
      bleGamepad.press(BUTTON_7);
    }else{
      bleGamepad.release(BUTTON_7);
    }
    if(controllers.down(0, GameControllers::R)){        
      //Serial.println("R");
      bleGamepad.press(BUTTON_8);
    }else{
      bleGamepad.release(BUTTON_8);
    }

    /*
    // 按鈕.
    if(controllers.down(0, GameControllers::UP)){        
      //Serial.println("UP");
      bleGamepad.press(BUTTON_3);
    }else{
      bleGamepad.release(BUTTON_3);
    }
    if(controllers.down(0, GameControllers::DOWN)){        
      //Serial.println("DOWN");
      bleGamepad.press(BUTTON_6);
    }else{
      bleGamepad.release(BUTTON_6);
    }
    if(controllers.down(0, GameControllers::LEFT)){        
      //Serial.println("LEFT");
      bleGamepad.press(BUTTON_9);
    }else{
      bleGamepad.release(BUTTON_9);
    }
    if(controllers.down(0, GameControllers::RIGHT)){        
      //Serial.println("RIGHT");
      bleGamepad.press(BUTTON_10);
    }else{
      bleGamepad.release(BUTTON_10);
    }
    */

    // 數位搖桿.
    if( controllers.down(0, GameControllers::UP) && controllers.down(0, GameControllers::RIGHT)){      
      bleGamepad.setLeftThumb(32767, 0);
    }else if( controllers.down(0, GameControllers::DOWN) && controllers.down(0, GameControllers::RIGHT)){
      bleGamepad.setLeftThumb(32767, 32767);
    }else if( controllers.down(0, GameControllers::DOWN) && controllers.down(0, GameControllers::LEFT)){
      bleGamepad.setLeftThumb(0, 32767);
    }else if( controllers.down(0, GameControllers::UP) && controllers.down(0, GameControllers::LEFT)){
      bleGamepad.setLeftThumb(0, 0);
    }else if(controllers.down(0,GameControllers::UP)){
      bleGamepad.setLeftThumb(16384, 0);
    }else if(controllers.down(0, GameControllers::DOWN)){
      bleGamepad.setLeftThumb(16384, 32767);
    }else if(controllers.down(0, GameControllers::LEFT)){
      bleGamepad.setLeftThumb(0, 16384);
    }else if(controllers.down(0, GameControllers::RIGHT)){
      bleGamepad.setLeftThumb(32767, 16384);
    }else{      
      bleGamepad.setAxes(16384, 16384, 16384, 16384, 16384, 16384, 16384, 16384);    
    }
  }  
  
  delay(33);
}
