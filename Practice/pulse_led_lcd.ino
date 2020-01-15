#include <LiquidCrystal.h>

//LiquidCrystal(RS, E, D4, D5, D6, D7): LCD 라이브러리 초기화 함수
//RS: LCD의 저장 공간에 값을 넣을 때 사용
//E: LCD에 값을 쓸 수 있도록 할지 설정
//Dn: LCD와 아두이노 사이의 입출력 핀

LiquidCrystal lcd(12, 11, 4, 5, 6, 7);

void setup() {
  // put your setup code here, to run once:
  //lcd.begin(한 줄당 들어가는 글자 개수, 줄의 개수): LCD 사용 준비
  lcd.begin(16, 2);
  pinMode(13, OUTPUT); //LED 출력
  pinMode(8, OUTPUT);  //trig 출력
  pinMode(9, INPUT);  // echo 입력

}

void loop() {
  digitalWrite(2,HIGH); // 펄스 발사
  delayMicroseconds(10);  //10micros동안 발사
  digitalWrite(2,LOW); // 발사 중단
  long duration = pulseIn(3, HIGH); // echo의 전압이 감지 될 때까지 걸린 시간
  if (duration==0)  {
    return;
  }// 측정이 안되면 리턴
  long distance= duration/58.2; // 반사된 물체까지의 거리 계산(cm)

  lcd.clear(); // lcd 화면 초기화
  lcd.print("Distance : "); //10글자 입력-6글자 입력 가능
  lcd.print(distance); //2글자 입력-4글자 입력 가능
  lcd.print(" cm "); //3글자 입력-1글자 입력 가능
  lcd.setCursor(0,1);
  if(distance > 20)
    lcd.print(" FAR  ");
  if(distance > 4 && distance < 20 )
    lcd.print(" NEAR ");

  if(distance > 40)
  {
    lcd.print(" VERY FAR       ");
    if(millis() % 2000 < 1000)
      digitalWrite(13,HIGH);
    else
      digitalWrite(13,LOW);
  }
  if(distance > 20 && distance < 40)
  {
    lcd.print(" FAR            ");
    if(millis() % 1000 < 500)
      digitalWrite(13,HIGH);
    else
      digitalWrite(13,LOW);
  }
  if(distance > 4 && distance < 20 )
  {
    lcd.print(" NEAR            ");
    if(millis() % 200 < 100)
      digitalWrite(13,HIGH);
    else
      digitalWrite(13,LOW);
  }
  delay(50);
}
  
