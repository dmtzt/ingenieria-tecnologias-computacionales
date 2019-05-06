// Puertos de salida
int ledPin0=6;
int ledPin1=7;
int ledPin2 = 8;
int ledPin3=9;
int ledPin4=10;
int ledPin5 = 11;
int ledPin6 = 12;
int ledPin7=13;

//Puertos de entrada
int inPinA=2;
int inPinB = 3;
int inPinC=4;

//variables
int swa,swb,swc;
bool s0,s1,s2,s3,s4,s5,s6,s7;
bool a,b,c;

void setup () {
  pinMode(ledPin0,OUTPUT);
  pinMode(ledPin1,OUTPUT);
  pinMode(ledPin2,OUTPUT);
  pinMode(ledPin3,OUTPUT);
  pinMode(ledPin4,OUTPUT);
  pinMode(ledPin5,OUTPUT);
  pinMode(ledPin6,OUTPUT);
  pinMode(ledPin7,OUTPUT);
  
  pinMode(inPinA,INPUT);
  pinMode(inPinB,INPUT);
  pinMode(inPinC,INPUT);
}

void loop () {
  //leer botón A
  swa = digitalRead(inPinA);
  if (swa==HIGH) 
     a=true;
   else
     a=false;

  //leer botón B
  swb = digitalRead(inPinB);
  if (swb == HIGH)
    b = true;  
  else
    b = false;

  //leer botón C
  swc = digitalRead(inPinC);
  if (swc==HIGH) 
     c=true;
   else
     c=false;


  //evaluar función booleana

// contar del 0 al 7 
s7 = a && b && c;
s6 = a && b && !c;
s5 = a && !b && c;
s4 = a && !b && !c;
s3 = !a && b && c;
s2 = !a && b && !c;
s1 = !a && !b && c;
s0 = !a && !b && !c;

  // Enciende LED Si es verdadera
  if (s0)  
     digitalWrite(ledPin0,HIGH);
  else
     digitalWrite(ledPin0,LOW);
  
  // Enciende LED Si es verdadera

  if (s1)  
     digitalWrite(ledPin1,HIGH);
  else
     digitalWrite(ledPin1,LOW);
     
  // Enciende LED Si es verdadera
  if (s2)  
     digitalWrite(ledPin2,HIGH);
  else
     digitalWrite(ledPin2,LOW);
  
  // Enciende LED Si es verdadera
  if (s3)  
     digitalWrite(ledPin3,HIGH);
  else
     digitalWrite(ledPin3,LOW);

  // Enciende LED Si es verdadera
  if (s4)  
     digitalWrite(ledPin4,HIGH);
  else
     digitalWrite(ledPin4,LOW);

  
  // Enciende LED Si es verdadera
  if (s5)  
     digitalWrite(ledPin5,HIGH);
  else
     digitalWrite(ledPin5,LOW);

  
  // Enciende LED Si es verdadera
  if (s6)  
     digitalWrite(ledPin6,HIGH);
  else
     digitalWrite(ledPin6,LOW);
  
  // Enciende LED Si es verdadera
  if (s7)  
     digitalWrite(ledPin7,HIGH);
  else
     digitalWrite(ledPin7,LOW);

}
