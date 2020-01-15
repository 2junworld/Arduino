#include <Servo.h>


//1초에 한번씩 서보모터의 각도가 10‘씩 증가하도록 하시오
//만약 서보모터의 현재각도가 150'에 도달하게 되는 경우 -10‘씩 감소하도록 하시오

Servo sv;
int angle=0;
boolean flag=false;

void setup()
{
  // put your setup code here, to run once:
  pinMode(13,OUTPUT);
  sv.attach(9); //9번 핀에 서보모터 설치
}

void loop()
{
  // put your main code here, to run repeatedly:
  if (angle<150)  {
    if(millis() % 1000 < 500)  {
      if (flag==true)  {
        flag=false;
        angle+=10;
        sv.write(angle);
      }
    }
     //500ms 전까지 flag가 1이면 0으로 바꾸고 각도를 10 증가
     //그 이후 500ms 전까지 flag는 0이므로 if문 실행 안함
    else  {
      flag=true;  
    }
    //500ms 이후 flag가 1로 바뀌고 1cycle 후에 다시 if문 실행. 반복.
  }
  //1초 주기로 서보모터가 10도씩 증가.

  else if (angle>=150)  {
    if(millis() % 1000 < 500)  {
      if (flag==true)  {
        flag=false;
        angle+=10;
        sv.write(angle);
      }
    }
     //500ms 전까지 flag가 1이면 0으로 바꾸고 각도를 10 증가
     //그 이후 500ms 전까지 flag는 0이므로 if문 실행 안함
    else  {
      flag=true;  
    }
    //500ms 이후 flag가 1로 바뀌고 1cycle 후에 다시 if문 실행. 반복.
  }
  //1초 주기로 서보모터가 10도씩 증가.

}

  
  
  
