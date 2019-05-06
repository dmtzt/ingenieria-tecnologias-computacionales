int PUSH1=12;

int BCDA=5;
int BCDB=4;
int BCDC=3;
int BCDD=2;
int contador=0;
bool a,b,c,d;
bool fA, fB, fC, fD;
unsigned byteContador = 0x00;
   
void setup() {
  // put your setup code here, to run once:
   pinMode(PUSH1,INPUT);
   
   pinMode(BCDA,OUTPUT);
   pinMode(BCDB,OUTPUT);
   pinMode(BCDC,OUTPUT);
   pinMode(BCDD,OUTPUT);
   Serial.begin(9600);    // abre el Puerto serie configurando la velocidad en 9600 bps
   digitalWrite(BCDA,LOW); 
   digitalWrite(BCDB,LOW); 
   digitalWrite(BCDC,LOW); 
   digitalWrite(BCDD,LOW); 
delay(2000);
}

void loop() {
   delay(400);     // espera 1 segundo

   if(digitalRead(PUSH1)==HIGH){

  byteContador = (char) contador;
    if ((byteContador & 0x08) == 8) a=true; else a= false;
    if ((byteContador & 0x04) == 4) b=true; else b= false;
    if ((byteContador & 0x02) == 2) c=true; else c= false;
    if ((byteContador & 0x01) == 1) d=true; else d= false;

     
    Serial.print("a,b,c,d: ");
    if (a) Serial.print("1");else Serial.print("0");
    if (b) Serial.print("1");else Serial.print("0");
    if (c) Serial.print("1");else Serial.print("0");
    if (d) Serial.println("1");else Serial.println("0");       
    
      // ABCD son las entradas (al revés) para el 7447 Convertidor BCD a 7 segmentos
      // fA = AB'C' 
      fA = a && !b && !c;
      if (fA) digitalWrite(BCDA,HIGH); else digitalWrite(BCDA,LOW);

      //fB = A'B
      fB = !a && b;
      if (fB) digitalWrite(BCDB,HIGH); else digitalWrite(BCDB,LOW);

      //fC = A'C
      fC = !a && c;
      if (fC) digitalWrite(BCDC,HIGH); else digitalWrite(BCDC,LOW);

      //fD = A'D + B'C'D
      fD = (!a && d) || (!b && !c && d);
      if (fD) digitalWrite(BCDD,HIGH); else digitalWrite(BCDD,LOW);

      contador = contador +1;
      if (contador > 9)  contador=0;
  
  }
}
