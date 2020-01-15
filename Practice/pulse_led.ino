// micros() 함수: millis()와 동일한 동작을 하지만 반환 값이 마이크로초 단위이다. 
// 단, 16MHz의 보드에서 (메가와 우노 모두 16MHz의 클럭 속도를 가진다) 
// micros() 함수로 반환되는 값은 항상 4로 나누어 떨어지는 값이며, 
// 따라서 최대 3.9999 마이크로초의 오차가 발생할 수 있다.

void setup() {
  // put your setup code here, to run once:
  pinMode(13, OUTPUT); //LED 출력
  pinMode(7, OUTPUT);  //trig 출력
  pinMode(6, INPUT);  // echo 입력

}

void loop() {
  // put your main code here, to run repeatedly:

  digitalWrite(7,HIGH); // 펄스 발사
  delayMicroseconds(10);  //10micros동안 발사
  digitalWrite(7,LOW); // 발사 중단

  long duration = pulseIn(6, HIGH); // echo의 전압이 감지 될 때까지 걸린 시간

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
}
