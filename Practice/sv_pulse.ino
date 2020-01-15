#include <Servo.h>
Servo sv;
int trig = 7;
int echo = 6;
int ratio = 10;
double duration;
double distance;
long distance_max=2000;
 int potential;
 int DIRECT_FACTOR, angle_FACTOR;
 int angle;
 
void setup() 
{
    pinMode(trig,OUTPUT);//trig 핀을 출력핀으로
    pinMode(echo,INPUT);//echo 핀을 입력핀으로
    sv.attach(9);
    pinMode(A0,INPUT);

}
void loop() 
{
    digitalWrite(trig,HIGH);
    delay(10);
    digitalWrite(trig,LOW);
    duration = pulseIn(echo,HIGH,20000);//pulseIn함수의 단위는 us(마이크로 세컨드)
    distance = (34*((double)1/1000)*duration)/2;
    distance = (int)distance; // 거리 감지 및 출력 시작
    angle_FACTOR = distance/ ratio;
    potential = analogRead(A0); // analogRead 를 통해 A0에 인가된 전압 읽어들임
    int angle_limit = map(potential,0,1023,0,90); 
    angle_limit = angle_limit +90;
    long angle_FACTOR_max = distance_max/ ratio;

    int angle = map(angle_FACTOR,0,angle_limit,0,angle_FACTOR_max);
    
    sv.write(angle);
}
