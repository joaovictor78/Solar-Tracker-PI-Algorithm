//poisitvo para esquerda
//dir 1 vai pra esquerda

float y = 0;
float u = 0;
float e = 0;
float r = 1.2;
float Kp = 5.0;
float Ti = 0.5;
float Ts = 0.025;
float eold = 0;
long tempo = 0;
#define enabl  9
#define dir1  10
#define dir2  11

void setup() {
  for(int count = 9; count <= 11; count++) {
    pinMode(count, OUTPUT);
     
  }
  digitalWrite(dir1, HIGH);
  digitalWrite(dir2, LOW);
  Serial.begin(115200);
}




void loop() {
  tempo = millis();
  y=analogRead(0)*5.0/1023.0;
  r=2.0+1.0*(((millis()/3000)%2)==1);
  eold = e;
  e=r-y;
  u=u+Kp*e+(Ts*Kp/Ti -Kp)*eold;
  u=min(max(u,-5.0),5.0);
  digitalWrite(dir1,u>=0);
  digitalWrite(dir2,u<=0);
  analogWrite(enabl,abs(u)*155/5.0+100);
  Serial.print(millis()/1000.0, 4);
  Serial.print(',');  
  Serial.print(r, 4);
  Serial.print(',');
  Serial.print(y, 4);
  Serial.print(',');
  Serial.print(u, 4);
  Serial.println(';');
  /*Serial.print(',');
  Serial.print(u>=0);
  Serial.print(',');
  Serial.print(u<=0);
  Serial.println(u*100);
*/
  while(millis()-tempo<=(Ts*1000)){}


  
}