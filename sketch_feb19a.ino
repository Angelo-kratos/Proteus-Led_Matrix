#define SH_CP 13
#define ST_CP 9
#define DS 10
#define ROW1 0
#define ROW2 1
#define ROW3 2
#define ROW4 3
#define ROW5 4
#define ROW6 5
#define ROW7 6
#define ROW8 7
byte grille[8];
int compteur=0;
void setup()
{
  boolean data = true;
  pinMode(SH_CP,OUTPUT);
  pinMode(ST_CP,OUTPUT) ;
  pinMode(DS,OUTPUT);
  pinMode(ROW1,OUTPUT);
  pinMode(ROW2,OUTPUT);
  pinMode(ROW3,OUTPUT);
  pinMode(ROW4,OUTPUT);
  pinMode(ROW5,OUTPUT);
  pinMode(ROW6,OUTPUT);
  pinMode(ROW7,OUTPUT);
  pinMode(ROW8,OUTPUT);
  
  digitalWrite(SH_CP,LOW);
  digitalWrite(ST_CP,LOW);
  digitalWrite(ROW1,HIGH);
  digitalWrite(ROW7,HIGH);
  digitalWrite(ROW2,HIGH);
  digitalWrite(ROW3,HIGH);
  digitalWrite(ROW4,HIGH);
  digitalWrite(ROW5,HIGH);
  digitalWrite(ROW6,HIGH);
  digitalWrite(ROW8,HIGH);

 for(int i=0; i<40;i=i+1)
  {
  digitalWrite(DS,data);
  digitalWrite(SH_CP,HIGH);
  delay(2);
  digitalWrite(SH_CP,LOW);
  data = !data;
  }
  digitalWrite(ST_CP,HIGH);
  delay(4);
  digitalWrite(ST_CP,LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  switch (compteur) {
    
  case 0: // A
    grille[0]=B00000000;
    grille[1]=B00111000;
    grille[2]=B01000100;
    grille[3]=B01000100;
    grille[4]=B01111100;
    grille[5]=B01000100;
    grille[6]=B01000100;
    grille[7]=B01000100;
    break;
  }
  // on allume les LEDs qui doivent l'etre

  for (int ligne=0; ligne<8; ligne++)
  {
    for (int col=0; col<8; col++)
    {
      for (byte masque = 00000001; masque>0; masque <<= 1)
        lc.setLed(0,ligne,col,(B10000000 >> col & grille[ligne]));   
    }
  }
}

}
