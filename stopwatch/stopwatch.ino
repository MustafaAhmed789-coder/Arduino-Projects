int d1 =2;
int d2 =3;
int d3 =4;
int d4 =5;

int a = 6;
int b = 7;
int c = 8;
int d = 9;
int e = 10;
int f = 11;
int g = 12;
int point = 13;

int button = A0; 
boolean lastbutton=LOW;
boolean currentbutton=LOW;
boolean ledon=false;

long count1 = 0; 
int x = 100;

int reset;
int count2=0; 
 
void setup()
{
pinMode(button, INPUT_PULLUP); 
  
  pinMode(d1, OUTPUT);
  pinMode(d2, OUTPUT);
  pinMode(d3, OUTPUT);
  pinMode(d4, OUTPUT);
  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(e, OUTPUT);
  pinMode(f, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(point, OUTPUT);
  
  digitalWrite(d1, HIGH);
  digitalWrite(d2, HIGH);
  digitalWrite(d3, HIGH);
  digitalWrite(d4, HIGH);
  }

 boolean debounce(boolean last){
   boolean current=digitalRead(button);
  
   if(last !=current){
    delay(5);
    current=digitalRead(button);
}
   return current;
}
 
void loop()
{
  currentbutton=debounce(lastbutton);

  if(lastbutton==LOW && currentbutton==HIGH){
    ledon=!ledon;
  }
  lastbutton=currentbutton;

  
if(ledon==false){
  clearleds();
  pickDigit(1);
  pickNumber((count1/x/1000)%10);
  delayMicroseconds(65);
 
  clearleds();
  pickDigit(2);
  pickNumber((count1/x/100)%10);
  delayMicroseconds(65);
 
  clearleds();
  pickDigit(3);
  pickNumber((count1/x/10)%10);
  delayMicroseconds(65);
 
  clearleds();
  pickDigit(4);
  pickNumber(count1/x%10);
  delayMicroseconds(65);
 
  count1++; 
}

if(ledon==true){

  clearleds();
  pickDigit(1);
  pickNumber((count1/x/1000)%10);
  delayMicroseconds(65);
 
  clearleds();
  pickDigit(2);
  pickNumber((count1/x/100)%10);
  delayMicroseconds(65);
 
  clearleds();
  pickDigit(3);x
  pickNumber((count1/x/10)%10);
  delayMicroseconds(65);
 
  clearleds();
  pickDigit(4);
  pickNumber(count1/x%10);
  delayMicroseconds(65);
  
   }

  reset= digitalRead(button);
  
  
  if(reset==LOW){
    count2=count2+1;
   }
    else{
    reset=HIGH;
    count2=0;
  }
  
  if(count2==1000){
  
  digitalWrite(d1, HIGH);
  digitalWrite(d2, HIGH);
  digitalWrite(d3, HIGH);
  digitalWrite(d4, HIGH);
  
  eight();
  delay(100);

  clearleds();
  delay(100);

  eight();
  delay(100);

  clearleds();
  delay(800);
  
    count2=0;
    count1=0;
    ledon=!ledon;
  }
  
}
 
void pickDigit(int pick1)
{
  digitalWrite(d1, LOW);
  digitalWrite(d2, LOW);
  digitalWrite(d3, LOW);
  digitalWrite(d4, LOW);
 
  switch(pick1)
  {
  case 1: 
    digitalWrite(d1, HIGH); 
    break;
  case 2: 
    digitalWrite(d2, HIGH); 
    break;
  case 3: 
    digitalWrite(d3, HIGH);
    digitalWrite(point,LOW);
    break;
  default: 
    digitalWrite(d4,HIGH); 
    break;
  }
}
 
void pickNumber(int pick2) 
{
  switch(pick2)
  {
  default: 
    zero(); 
    break;
  case 1: 
    one(); 
    break;
  case 2: 
    two(); 
    break;
  case 3: 
    three(); 
    break;
  case 4: 
    four(); 
    break;
  case 5: 
    five(); 
    break;
  case 6: 
    six(); 
    break;
  case 7: 
    seven(); 
    break;
  case 8: 
    eight(); 
    break;
  case 9: 
    nine(); 
    break;
  }
}
 
void clearleds() 
{
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
  digitalWrite(point, HIGH);
}
 
void zero()
{
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, LOW);
  digitalWrite(g, HIGH);
}
 

void one(){
  digitalWrite(a,HIGH);
  digitalWrite(b,LOW);
  digitalWrite(c,LOW);
  digitalWrite(d,HIGH);
  digitalWrite(e,HIGH);
  digitalWrite(f,HIGH);
  digitalWrite(g,HIGH);
}
 

void two(){
  digitalWrite(a,LOW);
  digitalWrite(b,LOW);
  digitalWrite(c,HIGH);
  digitalWrite(d,LOW);
  digitalWrite(e,LOW);
  digitalWrite(f,HIGH);
  digitalWrite(g,LOW);
}
 
void three(){
  digitalWrite(a,LOW);
  digitalWrite(b,LOW);
  digitalWrite(c,LOW);
  digitalWrite(d,LOW);
  digitalWrite(e,HIGH);
  digitalWrite(f,HIGH);
  digitalWrite(g,LOW);
}
 
void four(){
  digitalWrite(a,HIGH);
  digitalWrite(b,LOW);
  digitalWrite(c,LOW);
  digitalWrite(d,HIGH);
  digitalWrite(e,HIGH);
  digitalWrite(f,LOW);
  digitalWrite(g,LOW);
}
 
void five(){
  digitalWrite(a,LOW);
  digitalWrite(b,HIGH);
  digitalWrite(c,LOW);
  digitalWrite(d,LOW);
  digitalWrite(e,HIGH);
  digitalWrite(f,LOW);
  digitalWrite(g,LOW);
}
 
void six(){
  digitalWrite(a,LOW);
  digitalWrite(b,HIGH);
  digitalWrite(c,LOW);
  digitalWrite(d,LOW);
  digitalWrite(e,LOW);
  digitalWrite(f,LOW);
  digitalWrite(g,LOW);
}
 
void seven(){
  digitalWrite(a,LOW);
  digitalWrite(b,LOW);
  digitalWrite(c,LOW);
  digitalWrite(d,HIGH);
  digitalWrite(e,HIGH);
  digitalWrite(f,HIGH);
  digitalWrite(g,HIGH);
}
 
void eight(){
  digitalWrite(a,LOW);
  digitalWrite(b,LOW);
  digitalWrite(c,LOW);
  digitalWrite(d,LOW);
  digitalWrite(e,LOW);
  digitalWrite(f,LOW);
  digitalWrite(g,LOW);
}
 
void nine(){
  digitalWrite(a,LOW);
  digitalWrite(b,LOW);
  digitalWrite(c,LOW);
  digitalWrite(d,LOW);
  digitalWrite(e,HIGH);
  digitalWrite(f,LOW);
  digitalWrite(g,LOW);
}
