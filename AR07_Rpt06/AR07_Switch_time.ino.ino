/*
 예제 3.2
 I2C를 이용한 LCD 출력
*/
int blinkNumber = 0;
// I2C 통신 라이브러리 설정
#include <Wire.h>
// I2C LCD 라리브러리 설정
#include <LiquidCrystal_I2C.h>

// LCD I2C address 설정 PCF8574:0x27, PCF8574A:0x3F
LiquidCrystal_I2C lcd(0x27,16,2);  // LCD address:0x27, 16X2 LCD, 0x3F
const int inputPin = 2;
long startTime = 0;
long swCountTimer = 0;
void setup()
{
   pinMode(inputPin, INPUT_PULLUP);
  // 9600 bps로 시리얼 통신 설정
  Serial.begin(9600);
  lcd.init(); // LCD 설정
  lcd.clear();      // LCD를 모두 지운다.
  lcd.backlight();  // 백라이트를 켠다.  
 
  // LCD 백라이트를 두 번 점멸  
  // Open Serial Monitor, Type to display 표시
  
}

void loop()
{
  // 시리얼 통신 수신 값이 있을 때
 

  if(digitalRead(inputPin) == LOW){ 
    // 현재의 시간을 startTime 변수에 넣는다.    
    startTime = millis();
    // 스위치가 입력되는 동안 지연시킨다.
    while(digitalRead(inputPin) == LOW);
    // swCountTimer 변수에 스위치가 눌려진 시간을 넣는다.
    // 여기까지 측정된 시간에서 앞서 저장한 시간이 스위치가 눌려진 시간이 된다
    swCountTimer = millis() - startTime;

    // 모두 삭제
    lcd.clear();
     // 커서를 좌측 상단으로
    lcd.setCursor(0,0);
    lcd.print("AR07 time check");
    lcd.setCursor(1,1);
     lcd.print(swCountTimer);
     lcd.print(" ms");
   
  }
}
