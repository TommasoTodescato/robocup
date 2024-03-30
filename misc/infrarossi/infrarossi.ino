#define led A9      //definisco il pin digitale con un nome

void setup ()
{
  Serial.begin(9600);   //inizializzo il monitor seriale per poter leggere i valori del sensore
}

void loop () {
int valore = analogRead(led);   //inserisco in una variabile il valore letto dal sensore 
Serial.println(valore);         //stampo a monitor il valore del sensore
}
