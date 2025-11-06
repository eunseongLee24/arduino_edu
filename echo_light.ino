int trig = 2;  //디지털 2번 핀을 변수 trig에 대입
int echo = 3;  //디지털 3번 핀을 변수 echo에 대입
int RED = 8;
int YELLOW = 9;
int GREEN = 10;

void setup() {
  Serial.begin(9600);  //시리얼 통신시작 통신속도는 9600
  pinMode(trig, OUTPUT); // trig 핀은 출력모드로
  pinMode(echo, INPUT);
  pinMode(RED, OUTPUT);  
  pinMode(YELLOW, OUTPUT);
  pinMode(GREEN, OUTPUT);    // echo 핀을 입력모드로
 // put your setup code here, to run once:

}

void loop() {
  digitalWrite(trig, HIGH); //trig핀에 HIGH신호를 보냄
  delayMicroseconds(10);    //10마이크로초 동안 
  digitalWrite(trig, LOW);  //trig핀에 LOW(OV)신호를 보낸다
  int distance = pulseIn(echo, HIGH)*17/1000; 
  Serial.print(distance);   //거리를 확인하고 distance를 시리얼 모니터에 출력
  Serial.println("cm");     //문자열 cm를 출력
  delay(1000);              //1초 지연

  if(distance>20) // distance가 20보다 크면 초록색
    {digitalWrite(GREEN, HIGH);
    digitalWrite(YELLOW, LOW);
    digitalWrite(RED, LOW);
    }
  if(distance>10 & distance <=20) // distance가 10초과~20이하면 노란색
    {digitalWrite(GREEN, LOW);
    digitalWrite(YELLOW, HIGH);
    digitalWrite(RED, LOW);
    }
  if(distance>0 & distance<=10) // distance가 10이하면 빨간색
    {digitalWrite(GREEN, LOW);
    digitalWrite(YELLOW, LOW);
    digitalWrite(RED, HIGH);
    }
  // put your main code here, to run repeatedly:
}
