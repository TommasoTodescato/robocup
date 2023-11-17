#define trigPin 9     //definiso trigPin ed echoPin
#define echoPin 12

long durata, cm;    //dichiaro due variabili: la prima per registrare la durata dell'intensità del sensore
int led = 1;

void setup() {                    /*
                                      dichiaro i pin di input e output
                                  */
}
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(led, OUTPUT);
}
void loop()
{
  digitalWrite(trigPin, LOW);         //avvio il sensore
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delay(100);
  digitalWrite(trigPin, LOW);
  durata = pulseIn(echoPin, HIGH);
  cm = durata / 58;                 //calcolo la distanza in cm 
  if(cm<=12){                 //accendo o spengo un led in base a quanto vicino è l'oggetto individuato dal sensore
    digitalWrite(led, LOW);
  }
  else{
    digitalWrite(led, HIGH);
  }
   
}
