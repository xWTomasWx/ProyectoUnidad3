# The guardians library-basics

Este proyecto busca demostrar los tiempos de ordenamiento de algunos algoritmos cuadraticos y logaritmicos, con la utilizacion de arreglos de diferentes tamaños y distintas formas.

## Indice
- [Datos del creador](#datos-del-creador)
- [Funcionamiento del programa](#funcionamiento-del-programa)
- [Funcionamiento del código](#funcionamiento-del-codigo)
## Datos del creador
- **Nombre**: José Peña.
- **Universidad**: Universidad de Talca.
- **Carrera**: Ingeniera en desarrollo de videojuegos y realidad virtual.
- **Modulo**: Algoritmos y estructura de datos.
- **Profesor**: Manuel Moscoso.

## Funcionamiento del programa
### Resumen del programa
En este programa se ordenaran arreglos de distintos tamaños para validar el tiempo que se demoran los algoritmos de ordenamiento en terminar su funcion con aquellos, los algoritmos que se utilizaran son: **Insertion sort**, **Bubble sort**, **Selection sort**, **Shell sort**, **Merge sort**, **Quick sort** y **Heap sort**.
Los arreglos que recibiran estos algoritmos de ordenamiento son:
Arreglos ordenados: 1,2,3,4,5,6.
Arreglos inversos: 6,5,4,3,2,1.
Arreglos aleatorios: 4,2,5,1,6,3.
Arreglos aleatorios con duplicados: 4,3,3,2,1,6.
(Estos es solo un ejemplo, no se reciben exactamente estos arreglos)
### Menú principal
En el menú se le dara la posibilidad de escoger entre tres tipos de carreras, las cuales son: **Colas de espera**, **Trazabilidad de objetos** y **Eventos de cada escenario**.
Cada una de estas carreras posee una cantidad de datos la primera posee entre **100000** y **110000**, la segunda posee entre **15000** y **22500**, y la tercera entre **60000** y **80000**.

## Funcionamiento del codigo
### Librerías usadas
Las librerías usadas son:
	- [iostream](https://cplusplus.com/reference/iostream/)
	- [chrono](https://cplusplus.com/reference/chrono/)
	- [cstdlib](https://cplusplus.com/reference/cstdlib/)
	- [time.h](https://cplusplus.com/reference/ctime/)
	- [algorithm](https://cplusplus.com/reference/algorithm/)
	- [windows.h](https://en.wikipedia.org/wiki/Windows.h)

### Funciones
1. **intercambiar**: Recibe dos punteros a enteros para intencambiar sus valores
2. **insertionSort**: Esta funcion recorre un arreglo y coloca cada entero en su posicion dentro de la parte que ya esta ordenada, desplazando los mayores a la derecha
3. **bubbleSort**: Esta funcion recorre todo el arreglo y va intercambiando los valores adyacentes del actual mientras recorre, recorre varias veces hasta que ya no realice intercambios.
4. **selectionSort**: Esta funcion busca el valor mas bajo para colocarlo en el primero, despues recorre de nuevo buscando el valor mas bajo para colocarlo en el segundo asi sucesivamente.
5. **shellSort**: Esta funcion divide el arreglo en espacios mas pequños para comparar los valores entre ellos, compara el primer valor del primer espacio con el primer valor del segundo espacio y si el del segundo es menor los cambia, despues vuelve a dividir y hacer lo mismo pero con más espacios.
6. **mergeSort**: Esta funcion divide el arreglo recursivamente hasta que quede solo un numero, despues de eso va uniendo las partes adyacentes de forma ordenada.
7. **merge**: Esta funcion va en conjunto con mergeSort para realizar su funcionamiento.
7. **quickSort**: En esta funcion se divide el arreglo y se crea un elemento pivote, lo valores menores quedan en la izquierda y los mayores en la derecha, esto se hace varias veces hasta que se tiene el arreglo ordenado.
8. **particion**: Esta funcion va en conjunto con quickSort para realizar su funcionamiento.
9. **heapSort**: Funciona construyendo un heap a partir de los elementos a ordenar y luego extrayendo repetidamente el elemento máximo, colocándolo al final del arreglo hasta que el heap esté vacío. Esto resulta en un arreglo completamente ordenado.
10. **heap**: Esta funcion va en conjunto con heapSort para realizar su funcionamiento.
11. **imprimirArreglo**: Imprime el arreglo en su totalidad.
12. **verificarTiempo**: En esta funcion se ejecutan los algoritmos de ordenamiento y se toman los tiempos que se demoran en ordenar el arreglo, y al final se muestran en pantalla los valores, al final se muestra el algoritmo que se demoro menos.
13. **crearArreglos**: En esta funcion se crean los cuatro arreglos que se necesitan y se llama la funcion verificarTiempo para que realice las carreras.
14. **obtenerRandom**: En esta funcion se obtiene un random que este dentro de los dos parametros que recibe
15. **menu**: En esta funcion se le da al usuario la posibilidad de escoger entre diferentes carreras.