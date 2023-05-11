<h1 align= "center">Trabajo Practico N°2 SPD 🤖</h1>
<p align="center">
   <img src= "https://user-images.githubusercontent.com/131720798/234136882-1d2f7633-e589-464f-85e3-a03955c779ee.jpg"/>
</p>

# Integrantes 👩‍🎓 
- Abril Mariel Gonzalez Bernabeu

# Proyecto: Estacion de subte :train2:
<p align="center">
   <img src= "Estacion_subte/Copy of Estacion de subte.png"/>
# Funcion principal

Recibe dos arrays, uno que contiene las variables de los pines de las luces LED y otro que contiene las variables de los pines de las luces del tablero. Utilizo un bucle 'for' para recorrer el array de las luces LED y así poder encenderlas. Luego, llamo a la función 'numero_estaciones', pasándole como parámetro la luz LED encendida y el array de las luces del tablero.
"""c++
void high_low_led(int *luces, int *letras){
  for(int i = 0; i < 4; i ++){
  	digitalWrite(luces[i], HIGH);
  	numero_estaciones(luces[i], letras);
  	digitalWrite(luces[i], LOW);
  	delay(1500);
  }
}  
"""
 
