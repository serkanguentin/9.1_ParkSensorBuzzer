                           //LCD kütüphanemizi başlatıyoruz.
int trigPin = 10;// 7;                                        //Ultrasonik sensör trig pini değişkeni
int echoPin = 13;// 6;    
int buzzerPin= 3;// 8;                                    //Ultrasonik sensör echo pini değişkeni
int sure;                                               //Ses dalgasının gidip gelme süresi değişkeni
int uzaklik ;
int uyariLed ;                                            //Ölçülen uzaklık değeri değişkeni
            //LCD'nin pin bağlantılarını ayarlıyoruz.

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);                             //trig pinini OUTPUT olarak ayarlıyoruz.
  pinMode(echoPin,INPUT); 
  pinMode(buzzerPin, OUTPUT);                                //echo pinini INPUT olarak ayarlıyoruz.
                                  //LCD ekranımızın en-boy oranını ayarlıyoruz.                               
}
void loop() {
  digitalWrite(trigPin, LOW);                           //Ultrasonik sensör ile ölçüm sekansını başlatıyoruz.
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(100);
  digitalWrite(trigPin, LOW);
  sure = pulseIn(echoPin, HIGH, 11600);                 //Ses dalgasının gidip gelme süresini ölçüyoruz.
  uzaklik= sure*0.0345/2;       
  Serial.println(uzaklik);
                          //Ölçülen süre ile uzaklık hesabı yapıyoruz.
 
 if(uzaklik>0 && uzaklik<=15) //Mesafe 10 cm den uzun 20cm de eşit veya kısaysa aşağdaki işlemler gerçekleşir.
{
digitalWrite(uyariLed , HIGH);
digitalWrite(buzzerPin, HIGH);
delay(150); // ledin yanık kalma süresiyle buzzerin uyarı süresi standart bir süreye 150ms ye ayarlandı.
digitalWrite(uyariLed , LOW);
digitalWrite(buzzerPin , LOW);
delay(100);
}

 else if(uzaklik>15 && uzaklik<=30) //Mesafe 10 cm den uzun 20cm de eşit veya kısaysa aşağdaki işlemler gerçekleşir.
{
digitalWrite(uyariLed , HIGH);
digitalWrite(buzzerPin, HIGH);
delay(150); // ledin yanık kalma süresiyle buzzerin uyarı süresi standart bir süreye 150ms ye ayarlandı.
digitalWrite(uyariLed , LOW);
digitalWrite(buzzerPin , LOW);
delay(200);
}
else if(uzaklik>30 && uzaklik<=45) //Mesafe 20 cm den uzun 30cm de eşit veya kısaysa aşağdaki işlemler gerçekleşir.
{
digitalWrite(uyariLed , HIGH);
digitalWrite(buzzerPin , HIGH);
delay(150);
digitalWrite(uyariLed , LOW);
digitalWrite(buzzerPin , LOW);
delay(400);
}

else if(uzaklik>45 && uzaklik<=60) //Mesafe 40 cm den uzun 50cm de eşit veya kısaysa aşağdaki işlemler gerçekleşir.
{
digitalWrite(uyariLed , HIGH);
digitalWrite(buzzerPin , HIGH);
delay(150);
digitalWrite(uyariLed , LOW);
digitalWrite(buzzerPin , LOW);
delay(800);
}


}


