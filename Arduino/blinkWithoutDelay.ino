#define ROW1 11
#define ROW2 12
#define ROW3 13
#define INTERVAL 1000
unsigned long prevMillis=0;
int command=1;
void setup()
{

for(int i=1; i<=13; i ++)
{
  pinMode(i,OUTPUT);
  if( i > 10 ) digitalWrite(i,HIGH);
}

}
void on(int y){
  for(int i=2;i<=10;i++){
  digitalWrite(i, HIGH);
  }
  digitalWrite(y, LOW);
}
void off(int y){
for(int i=2;i<=10;i++){
digitalWrite(i, LOW);
}
digitalWrite(y, HIGH);
}
void loop() {
  unsigned long Millis = millis();
  if ((unsigned long)(Millis - prevMillis) >=INTERVAL) {
    switch (command) {
    case 1:
      on(ROW1);
      command++;
      break;
    case 2:
      off(ROW1);
      command++;
      break;
    case 3:
      on(ROW2);
      command++;
      break;
    case 4:
      off(ROW2);
      command++;
      break;
    case 5:
      on(ROW3);
      command++;
      break;
    case 6:
      off(ROW3);
      command=1;
      break;
    default:
     command=1;
      break;
    }
   prevMillis = millis();
 }
}