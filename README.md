<h1 align= "center">Trabajo Practico N°2 SPD 🤖</h1>
<p align="center">
   <img src= "Img/ArduinoTinkercad.jpg"/>
</p>

# Consigna SUBTE:
La empresa  “UTN FRA Robotics” ganó la licitación de un proyecto, y deberá Implementar un sistema que permita al usuario saber a qué estación de subte está llegando, aparte  el sistema muestra las estaciones que faltan hasta llegar a destino, para ello debemos utilizar 4 LEDs y el display de 7 segmentos. Esta vez el buzzer deberá emitir un sonido diferente cada vez que se llegue a una estación.
El sistema deberá arrancar apagado, luego de presionar el botón empezará y hará lo pedido.

# Integrantes 👩‍🎓 
- Abril Mariel Gonzalez Bernabeu

# Proyecto: Estacion de subte :train2:
<p align="center">
   <img src= "Img/Copy of Estacion de subte.png"/>
</p>	

# Funcion principal

Recibe dos arrays, uno que contiene las variables de los pines de las luces LED y otro que contiene las variables de los pines de las luces del tablero. Utilizo un bucle 'for' para recorrer el array de las luces LED y así poder encenderlas. Luego, llamo a la función numero_estaciones, pasándole como parámetro la luz LED encendida y el array de las luces del tablero.

```c++
void high_low_led(int *luces, int *letras){
  for(int i = 0; i < 4; i ++){
  	digitalWrite(luces[i], HIGH);
  	numero_estaciones(luces[i], letras);
  	digitalWrite(luces[i], LOW);
  	delay(1500);
  }
}  
```
# Funciones secundarias

Recibe como parámetro el número del pin del LED encendido y el array con las luces del tablero. Se utiliza un switch para realizar acciones según el LED que esté encendido                   
```c++
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
```
Recibe por parametro las luces que tiene que prender del tablero                       
```c++
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
```
Recibe por parametro el volumen para emitir un sonido cuando llega a la estacion                       
```c++
void power_buzzer(int vol){
    tone(buzzer, vol);
    delay(500);
  	noTone(buzzer);
  }                       
```
Recibe un mensaje y lo imprime                       
```c++
void imprimir_mensaje(String mensaje){
	Serial.println(mensaje);
}                       
```
# Link al proyecto en tinkercad

- https://www.tinkercad.com/things/aP4jje5Uiw6

# Link al codigo del proyecto en GDB

- https://onlinegdb.com/WpJXpb3hO                  
