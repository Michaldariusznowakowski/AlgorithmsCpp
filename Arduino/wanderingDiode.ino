void setup()
{
for(int i=1; i<=13; i ++)
{
  pinMode(i,OUTPUT);
  if( i > 10 ) digitalWrite(i,HIGH);
}
}
void oneSec(int x, int y){
digitalWrite(x, HIGH);
digitalWrite(y, LOW);
delay(1000);
digitalWrite(x, LOW);
digitalWrite(y, HIGH);
}
void loop()
{
for(int i=11; i <=13;i++){
  for(int j=2; j <=10;j++){
  oneSec(j,i);
}
}
}
