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
  pinMode(2, OUTPUT);  //trig 출력
  pinMode(3, INPUT);  // echo 입력

}

void loop() {
  // put your main code here, to run repeatedly:

  digitalWrite(2,HIGH); // 펄스 발사
  delayMicroseconds(10);  //10micros동안 발사
  digitalWrite(2,LOW); // 발사 중단

  long duration = pulseIn(3, HIGH); // echo의 전압이 감지 될 때까지 걸린 시간

  if (duration==0)  {
    return;
  }// 측정이 안되면 리턴

  long distance= duration/58.2; // 반사된 물체까지의 거리 계산(cm)

  if  (distance<=10)  {
    digitalWrite(13,HIGH);
  } 
  else if  (distance<25 && distance>10)  {
    if  (millis()%500<250)  {
      digitalWrite(13,HIGH);
    }
    else  {
      digitalWrite(13,LOW);
    }
  }
  else  {
    digitalWrite(13,LOW);
  }

  lcd.clear(); // lcd 화면 초기화
  lcd.print("Distance :"); //10글자 입력-6글자 입력 가능
  if  (distance>=10 && distance<100)  {
    lcd.print(distance); //2글자 입력-4글자 입력 가능
    lcd.print(" cm"); //3글자 입력-1글자 입력 가능
  }
  else if  (distance<10)  {
    lcd.print(" "); //1글자 입력-5글자 입력 가능
    lcd.print(distance); //1글자 입력-4글자 입력 가능
    lcd.print(" cm"); //3글자 입력-1글자 입력 가능
  }
  else  {
    lcd.print("so far"); //6글자 입력
  }
  delay(50);
}
