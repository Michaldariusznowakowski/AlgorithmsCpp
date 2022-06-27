#define INTERVAL 500
#define REFRESH 5
unsigned long prevMillis=0;
unsigned long prevMillisREFRESH=0;
unsigned long prevMillisREFRESH2=0;
int col=0;
int row=0;
bool reverse=false;
bool tab[3][9];
bool tick=true;
int i=0;
int j=0;
void setup()
{
for(int i=1; i<=13; i ++)
{
  pinMode(i,OUTPUT);
  digitalWrite(i,LOW);
  if( i > 10 ) digitalWrite(i,HIGH);
}

}

void loop() {

unsigned long Millis = millis();
if ((unsigned long)(Millis - prevMillisREFRESH) >=REFRESH) 
{
  if(tick==true){
      if(j>8){j=0;++i;}
      if(i>2){i=0;}
        if(tab[i][j]==true){
      digitalWrite(i+11, LOW);
      digitalWrite(j+2, HIGH);
        }
        tick=false;
  }
    prevMillisREFRESH = millis();
}
if ((unsigned long)(Millis - prevMillisREFRESH2) >=REFRESH+1) 
{
    if(tick==false){
        if(tab[i][j]==true){
      digitalWrite(i+11, HIGH);
      digitalWrite(j+2, LOW);
        }
      j++;
              tick=true;
  }

    prevMillisREFRESH2 = millis();
}

  if ((unsigned long)(Millis - prevMillis) >=INTERVAL) {
    if(reverse==false){
      tab[row][col]=true;
      col++;
      if(col>8){col=0;row++;}
      if(row>2){col=8;row=2;reverse=true;}
    }else{
      tab[row][col]=false;
      col--;
      if(col<0){col=8;row--;}
      if(row<0){col=0;row=0;reverse=false;}
    }
   prevMillis = millis();
 }
}