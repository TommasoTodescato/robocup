// driver A (destra)
const int A_PWMA = 7;
const int A_AIN1 = 8;   // motore 1
const int A_AIN2 = 9;   // --------
const int A_STBY = 10;
const int A_BIN1 = 11;  // motore 2
const int A_BIN2 = 12;  // --------
const int A_PWMB = 13;

// driver B (sinistra)
const int B_PWMA = 2;
const int B_STBY = 3;
const int B_BIN1 = 4;   // motore 3
const int B_BIN2 = 5;   // --------
const int B_PWMB = 6;

// id motori:
//  driver A motore A -> 1
//  driver A motore B -> 2
//  driver B motore B -> 3

bool gira(int id, bool senso, int potenza, int millis)
{
  switch(id)
  {
    case 1:
      digitalWrite(A_STBY, HIGH);
      digitalWrite(A_AIN1, senso);
      digitalWrite(A_AIN2, !senso);
      analogWrite(A_PWMA, potenza);
      delay(millis);
      digitalWrite(A_STBY, LOW);
      break;

    case 2:
      digitalWrite(A_STBY, HIGH);
      digitalWrite(A_BIN1, senso);
      digitalWrite(A_BIN2, !senso);
      analogWrite(A_PWMB, potenza);
      delay(millis);
      digitalWrite(A_STBY, LOW);
      break;

    case 3:
      digitalWrite(B_STBY, HIGH);
      digitalWrite(B_BIN1, senso);
      digitalWrite(B_BIN2, !senso);
      analogWrite(B_PWMB, potenza);
      delay(millis);
      digitalWrite(B_STBY, LOW);
      break;

    default:
      return false;
  }

  return true;
}

void setup()
{
  for (int i = 2; i < 14; i++)
    pinMode(i, OUTPUT);
}
void loop()
{
  gira(3, true, 255, 3000);

  delay(5000);
}