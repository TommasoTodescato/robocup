
#include <IRremote.h>
int tsop_receiver = 12; // collegamento al pin "data" dello TSOP1738
IRrecv irrecv (tsop_receiver) ; //crea un istanza di "irrecv"
decode_results results; //crea un istanza di "decode_results"
void setup ()
{
Serial.begin(9600); //imposta il baud rate a 9600
irrecv.enableIRIn (); //fa partire il ricevitore
}
void loop () {
if (irrecv.decode(&results)) {  //decodifica il segnale del tasto premuto
Serial.println(results.value,HEX);  //stampa la codifica del tasto in esadecimale
irrecv.resume();  // in attesa di ricevere il successivo
}
}