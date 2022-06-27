void setup()
{
#define COL1 2
#define COL2 3
#define COL3 4
#define ROW1 11
#define ROW2 12
#define ROW3 13
for(int i=1; i<=13; i ++)
{
  pinMode(i,OUTPUT);
  if( i > 10 ) digitalWrite(i,LOW);
}
}
void oneSec(int x, int y){
digitalWrite(x, HIGH);
digitalWrite(y, LOW);
delay(1000);
digitalWrite(x, LOW);
digitalWrite(y, LOW);
}
void loop()
{
oneSec(COL1,ROW1);
oneSec(COL2,ROW2);
oneSec(COL3,ROW3);
}
