                          
int trigPin = 10;// 7;     
int echoPin = 13;// 6;    
int buzzerPin= 3;// 8      
int time;                  
int distance ;
int warningLed ;                                           
            

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);                           
  pinMode(echoPin,INPUT); 
  pinMode(buzzerPin, OUTPUT);       
}
void loop() {
  digitalWrite(trigPin, LOW);                           
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(100);
  digitalWrite(trigPin, LOW);
  time = pulseIn(echoPin, HIGH, 11600);                 
  distance= time*0.0345/2;       
  Serial.println(distance);
                          
 
 if(distance>0 && distance<=15) 
{
digitalWrite(warningLed , HIGH);
digitalWrite(buzzerPin, HIGH);
delay(150); 

digitalWrite(warningLed , LOW);
digitalWrite(buzzerPin , LOW);
delay(100);
}

 else if(distance>15 && distance<=30) 
{
digitalWrite(warningLed , HIGH);
digitalWrite(buzzerPin, HIGH);
delay(150);
digitalWrite(warningLed , LOW);
digitalWrite(buzzerPin , LOW);
delay(200);
}
else if(distance>30 && distance<=45) 
{
digitalWrite(warningLed , HIGH);
digitalWrite(buzzerPin , HIGH);
delay(150);
digitalWrite(warningLed , LOW);
digitalWrite(buzzerPin , LOW);
delay(400);
}

else if(distance>45 && distance<=60) 
{
digitalWrite(warningLed , HIGH);
digitalWrite(buzzerPin , HIGH);
delay(150);
digitalWrite(warningLed , LOW);
digitalWrite(buzzerPin , LOW);
delay(800);
}


}


