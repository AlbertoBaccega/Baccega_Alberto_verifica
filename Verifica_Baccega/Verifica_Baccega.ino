int tempoRossoGiallo;   //input
int tempoBiancoVerde;    //input

void setup() {
  // put your setup code here, to run once:

  tempoRossoGiallo = 0;
  tempoBiancoVerde = 0;

  pinMode(12, OUTPUT);  //Rosso
  pinMode(6, OUTPUT);   //Giallo
  pinMode(8, OUTPUT);   //Bianco
  pinMode(10, OUTPUT);   //Verde

  Serial.begin(9600);

  TempoAccensioneRossoGiallo();
  TempoAccensioneBiancoVerde();

}

void loop() {
  // put your main code here, to run repeatedly:
  
  digitalWrite(12, HIGH);
  digitalWrite(6, HIGH);
  delay(tempoRossoGiallo);
  digitalWrite(12, LOW);
  digitalWrite(6, LOW);  
  digitalWrite(8, HIGH);
  digitalWrite(10, HIGH);
  delay(tempoBiancoVerde);
  digitalWrite(8, LOW);
  digitalWrite(10, LOW);

  
}


void TempoAccensioneRossoGiallo()
{
  Serial.begin(9600);
  Serial.print( "Quanto tempo vuoi che rimanga acceso il ROSSO-GIALLO?(ms)");
  while(Serial.available() == 0) {};
  tempoRossoGiallo = Serial.readString().toInt();
}



void TempoAccensioneBiancoVerde()
{
  Serial.begin(9600);
  Serial.print( "Quanto tempo vuoii che rimanga acceso il BIANCO-VERDE?(ms)");
  while(Serial.available() == 0) {};
  tempoBiancoVerde = Serial.readString().toInt();
}
