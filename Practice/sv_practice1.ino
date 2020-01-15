#include <Servo.h>


//1초에 한번씩 서보모터의 각도가 10‘씩 증가하도록 하시오
//만약 서보모터의 현재각도가 150'에 도달하게 되는 경우 -10‘씩 감소하도록 하시오

Servo sv;
int angle;
boolean flag=false;
boolean angle_direction=false;
int factor;

void setup()
{
  // put your setup code here, to run once:
  pinMode(13,OUTPUT);
  sv.attach(9); //9번 핀에 서보모터 설치
  sv.write(0);
}

void loop()
{
  // put your main code here, to run repeatedly:
  if (angle<=0)  {
    angle_direction=true;
  }
  if (angle>=150)  {
    angle_direction=false;
  }
  if (angle_direction==true)  {
    factor=1;
  }
  if (angle_direction==false)  {
    factor=-1;
  }
  if(millis() % 1000 < 500)  {
    if (flag==true)  {
      flag=false;
      angle+=10*factor;
      sv.write(angle);
    }
  }
     //500ms 전까지 flag가 1이면 0으로 바꾸고 각도를 10 증가
     //그 이후 500ms 전까지 flag는 0이므로 if문 실행 안함
   else  {
    flag=true;
    }
}

  
  
  
