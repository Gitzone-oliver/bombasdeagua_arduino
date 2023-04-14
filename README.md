## bombasdeagua_arduino
Programa que activa de manera alterna bombas de agua cada hora o cada 2 horas. Cuando se le indica que funcione de manera automática de lo contrario (en manual) se podrá activar una bomba en periodos de 1 o 2 horas.

Se cuenta con dos señales sensores que chekan cuando se alcanza un umbral minimo en la cisterna o un umbral máximo.Tambien se tiene un sensor de presión el cual presenta un corte la bomba en caso de que no haya presión (Es decir, no hay agua).

Un arduino fue utilizado para las entradas de sensores y salidas de actuadores.

- Switch apagado - 13
- Switch Manual/Auto - 12
- Switch Bomba1 - 8
- Switch Bomba2 - 7
- Switch presion - 4
- Switch altura alta 3
- Switch altura baja 2

Llena si el sensor de presión esta en bajo y si señal de cisterna esta en bajo.
Manual se elige solo una bomba. Nunca las dos bombas.

![imagen](https://user-images.githubusercontent.com/38991693/232140566-1995a651-7561-4320-8c10-f97881063fd0.png)

![imagen](https://user-images.githubusercontent.com/38991693/232140520-167a624e-2c96-4bcb-b2be-e344bbad5537.png)

