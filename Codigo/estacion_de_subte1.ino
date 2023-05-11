#define a 12
#define b 13
#define c A1
#define d A2
#define e A3
#define f 11
#define g 10
#define led1 7
#define led2 6
#define led3 5
#define led4 4
#define boton 9
#define buzzer A4

int tablero[7] = {a, b, c, d, e, f, g};
int led[4] = {led4, led3, led2, led1};

void setup(){
  for(int i = 0; i < 7; i++){
  	pinMode(tablero[i], OUTPUT);
    if(i < 4){
    	pinMode(led[i], OUTPUT);
    }
  }
  pinMode(boton, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(boton, INPUT);
}

void high_low_led(int *luces, int *letras);
void numero_estaciones(int led, int *letras);
void luces_tablero(int A, int B, int C, int D, int E, int F, int G, int volumen);
void power_buzzer();
void imprimir_mensaje(String mensaje);


void loop(){
  bool bandera;
  int presiono = digitalRead(boton);
  Serial.begin(9600);
  delay(250);
  if(presiono == HIGH || bandera == false){
  	high_low_led(led, tablero);
    bandera = false;
  }
 }

void high_low_led(int *luces, int *letras){
  for(int i = 0; i < 4; i ++){
  	digitalWrite(luces[i], HIGH);
  	numero_estaciones(luces[i], letras);
  	digitalWrite(luces[i], LOW);
  	delay(1500);
  }
}

void numero_estaciones(int led, int *letras){
  switch(led){
    case 4:
    	imprimir_mensaje("Estas en Constitucion");
    	luces_tablero(letras[0], letras[1], letras[6], letras[2], letras[3], 0, 0, 1000);
    	break;
    case 5:
    	imprimir_mensaje("Estas en San juan");
    	luces_tablero(letras[0], letras[1], letras[6], letras[4], letras[3], 0, 0, 750);
    	break;
    case 6:
    	imprimir_mensaje("Estas en Independencia");
        luces_tablero(letras[1], letras[2], 0, 0, 0, 0, 0, 500);
    	break;
    case 7:
    	imprimir_mensaje("Estas en Moreno");
      	luces_tablero(letras[1], letras[2], letras[3], letras[4], letras[5], letras[0], 0, 250);
      	break;
  }
}

void luces_tablero(int A, int B, int C, int D, int E, int F, int G, int volumen){
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
  power_buzzer(volumen);
  delay(2500);
  digitalWrite(A, LOW);
  digitalWrite(B, LOW);
  digitalWrite(C, LOW);
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  digitalWrite(F, LOW);
  digitalWrite(G, LOW);
}

void power_buzzer(int vol){
  //Emite sonido para ayudar a los no videntes saber en que color esta el semaforo
    tone(buzzer, vol);
    delay(500);
  	noTone(buzzer);
  }

void imprimir_mensaje(String mensaje){
	Serial.println(mensaje);
}