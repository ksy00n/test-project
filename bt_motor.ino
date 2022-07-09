#include <SoftwareSerial.h>

SoftwareSerial mySerial(2,4);//블루투스 객체 선언(TX, RX)

int IN1Pin = 6;
int IN2Pin = 5;
int IN3Pin = 10;
int IN4Pin = 11;

int IN5Pin = A0;
int IN6Pin = A1;
int IN7Pin = A2;
int IN8Pin = A3;

byte ENPin1 = 3;
byte ENPin2 = 9;
byte ENPin3 = A5;
byte ENPin4 = A4;
byte value;

void setup(){
  Serial.begin(9600);//시리얼 통신 설정
  mySerial.begin(9600);// 소프트웨어 시리얼 통신 설정
  pinMode(IN1Pin, OUTPUT);
  pinMode(IN2Pin, OUTPUT);
  pinMode(IN3Pin, OUTPUT);
  pinMode(IN4Pin, OUTPUT);
  pinMode(IN5Pin, OUTPUT);
  pinMode(IN6Pin, OUTPUT);
  pinMode(IN7Pin, OUTPUT);
  pinMode(IN8Pin, OUTPUT);
}

 void forward(){//전진
      digitalWrite(IN1Pin, LOW);
      digitalWrite(IN2Pin, HIGH);
      digitalWrite(IN3Pin, LOW);
      digitalWrite(IN4Pin, HIGH);
     
      digitalWrite(IN5Pin, HIGH); 
      digitalWrite(IN6Pin, LOW);
      digitalWrite(IN7Pin, HIGH); 
      digitalWrite(IN8Pin, LOW);

    }
  void backward(){//후진
      digitalWrite(IN1Pin, HIGH); 
      digitalWrite(IN2Pin, LOW);
      digitalWrite(IN3Pin, HIGH); 
      digitalWrite(IN4Pin, LOW);
      
      digitalWrite(IN5Pin, LOW);
      digitalWrite(IN6Pin, HIGH);
      digitalWrite(IN7Pin, LOW);
      digitalWrite(IN8Pin, HIGH); 
    }
  void stopall(){//정지
      digitalWrite(IN1Pin, HIGH);
      digitalWrite(IN2Pin, HIGH);
      digitalWrite(IN3Pin, HIGH);
      digitalWrite(IN4Pin, HIGH);
      digitalWrite(IN5Pin, HIGH);
      digitalWrite(IN6Pin, HIGH);
      digitalWrite(IN7Pin, HIGH);
      digitalWrite(IN8Pin, HIGH);    
    }
  void right(){
      digitalWrite(IN1Pin, HIGH);
      digitalWrite(IN2Pin, HIGH);
      digitalWrite(IN3Pin, LOW);
      digitalWrite(IN4Pin, HIGH);
      
      digitalWrite(IN5Pin, HIGH);
      digitalWrite(IN6Pin, LOW);
      
      digitalWrite(IN7Pin, HIGH);
      digitalWrite(IN8Pin, HIGH);       
    }
  void left(){
      digitalWrite(IN1Pin, LOW);
      digitalWrite(IN2Pin, HIGH);
      digitalWrite(IN3Pin, HIGH);
      digitalWrite(IN4Pin, HIGH);
      
      digitalWrite(IN5Pin, HIGH);
      digitalWrite(IN6Pin, HIGH);
      
      digitalWrite(IN7Pin, HIGH);
      digitalWrite(IN8Pin, LOW); 
    }

 void loop(){
    analogWrite(ENPin1, 200); //Max Speed
    analogWrite(ENPin2, 200); //Max Speed
    analogWrite(ENPin3, 200); //Max Speed
    analogWrite(ENPin4, 200); //Max Speed
    
  if(mySerial.available()){
    value=mySerial.read();
    if(value=='f')forward();
    if(value=='b')backward();
    if(value=='l')left();
    if(value=='r')right();
    if(value=='s')stopall();
  }
  
}
