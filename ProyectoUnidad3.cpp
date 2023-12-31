#include<iostream>
#include<chrono>
#include<cstdlib>
#include<time.h>
#include<algorithm>
#include<windows.h>
// Utilizo esta definicion para acortar un poco a la hora de programar, ademas es mas sencillo de entender que esto cambia el color de las letras o el fondo.
#define color SetConsoleTextAttribute

using namespace std;
// Es lo mismo que un swap
void intercambiar(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}
// Todos estas funciones son algoritmos de ordenamientos, hasta el heapSort despues de este ya son otras funciones
void insertionSort(int arr[], int n){
    for(int i = 1; i < n; ++i){
        int clave = arr[i];
        int j = i-1;

        while(j >= 0 && arr[j] > clave){
            arr[j+1] = arr[j];
            j = j-1;
        }
        arr[j+1] = clave;
    }
}

void bubbleSort(int arr[], int n){
    for(int i = 0; i<n-1; ++i){
        for(int j = 0; j<n-i-1; ++j){
            if(arr[j] > arr[j+1]){
            	intercambiar(&arr[j], &arr[j+1]);
			}
        }
    }
}

void selectionSort(int arr[], int n){
    for(int i = 0; i<n-1; ++i){
        int indiceMin = i;
        for(int j = i + 1; j < n; ++j){
            if(arr[j] < arr[indiceMin]){
            	indiceMin = j;
			}
        }
        intercambiar(&arr[indiceMin], &arr[i]);
    }
}

void shellSort(int arr[], int n){
    for(int intervalo = n/2; intervalo>0; intervalo/=2){
        for(int i = intervalo; i<n; ++i){
            int temp = arr[i];
            int j;
            for(j = i; j>=intervalo && arr[j-intervalo]>temp; j-=intervalo){
                arr[j] = arr[j-intervalo];
            }
            arr[j] = temp;
        }
    }
}

void merge(int arr[], int l, int m, int r){
    int n1 = m-l+1;
    int n2 = r-m;

    int L[n1], R[n2];

    for(int i = 0; i<n1; i++){
    	L[i] = arr[l+i];
	}
    for(int j = 0; j<n2; j++){
    	R[j] = arr[m+1+j];
	}
	
    int i = 0;
    int j = 0;
    int k = l;

    while(i < n1 && j < n2){
        if(L[i] <= R[j]){
            arr[k] = L[i];
            i++;
        }else{
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while(i < n1){
        arr[k] = L[i];
        i++;
        k++;
    }

    while(j < n2){
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r){
    if(l < r){
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

int particion(int arr[], int low, int high){
    int medio = low + (high - low) / 2;
    int pivote = arr[medio];

    intercambiar(&arr[medio], &arr[high]);

    int i = low;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivote) {
            intercambiar(&arr[i], &arr[j]);
            i++;
        }
    }

    intercambiar(&arr[i], &arr[high]);
    return i;
}

void quickSort(int arr[], int low, int high){
    if(low < high){
        int p = particion(arr, low, high);

        quickSort(arr, low, p - 1);
        quickSort(arr, p + 1, high);
    }
}

void heap(int arr[], int n, int i){
    int maximo = i;
    int izquierda = 2 * i + 1;
    int derecha = 2 * i + 2;

    if(izquierda < n && arr[izquierda] > arr[maximo]){
    	maximo = izquierda;
	}
    if(derecha < n && arr[derecha] > arr[maximo]){
    	maximo = derecha;
	}
    if(maximo != i){
        intercambiar(&arr[i], &arr[maximo]);

        heap(arr, n, maximo);
    }
}

void heapSort(int arr[], int n){
    for(int i = n / 2 - 1; i >= 0; i--){
    	heap(arr, n, i);
	}
    for(int i = n - 1; i > 0; i--){
        intercambiar(&arr[0], &arr[i]);

        heap(arr, i, 0);
    }
}
// Imprime un arreglo de enteros
void imprimirArreglo(int arr[], int n){
	for(int i = 0; i<n; i++){
		cout << arr[i] << " ";
	}
	cout << endl;
}
// Toma el tiempo de cada algoritmo a la hora de ordenar un arreglo, y lo muestra en pantalla, ademas realiza una comparacion de ellos.
// El color es lo que se define mas arriba, y se utiliza para cambiar el color 4 = rojo y 7 = blanco.
// copy es una funcion de algorithm que utilice para copiar los arreglos
void verificarTiempo(int arrUtil[], int arrAuxiliar[], int maximo){
	
	copy(arrUtil, arrUtil+maximo, arrAuxiliar);
	auto tiempoInicial = chrono::high_resolution_clock::now();
	insertionSort(arrUtil, maximo);
	auto tiempoFinal = chrono::high_resolution_clock::now();
	chrono::duration<double> duracionInsertion = tiempoFinal - tiempoInicial;
	copy(arrAuxiliar, arrAuxiliar+maximo, arrUtil);

	tiempoInicial = chrono::high_resolution_clock::now();
	bubbleSort(arrUtil, maximo);
	tiempoFinal = chrono::high_resolution_clock::now();
	chrono::duration<double> duracionBubble = tiempoFinal - tiempoInicial;
	copy(arrAuxiliar, arrAuxiliar+maximo, arrUtil);

	tiempoInicial = chrono::high_resolution_clock::now();
	selectionSort(arrUtil, maximo);
	tiempoFinal = chrono::high_resolution_clock::now();
	chrono::duration<double> duracionSelection = tiempoFinal - tiempoInicial;
	copy(arrAuxiliar, arrAuxiliar+maximo, arrUtil);

	tiempoInicial = chrono::high_resolution_clock::now();
	shellSort(arrUtil, maximo);
	tiempoFinal = chrono::high_resolution_clock::now();
	chrono::duration<double> duracionShell = tiempoFinal - tiempoInicial;
	copy(arrAuxiliar, arrAuxiliar+maximo, arrUtil);

	tiempoInicial = chrono::high_resolution_clock::now();
	mergeSort(arrUtil, 0, maximo-1);
	tiempoFinal = chrono::high_resolution_clock::now();
	chrono::duration<double> duracionMerge = tiempoFinal - tiempoInicial;
	copy(arrAuxiliar, arrAuxiliar+maximo, arrUtil);

	tiempoInicial = chrono::high_resolution_clock::now();
	quickSort(arrUtil, 0, maximo-1);
	tiempoFinal = chrono::high_resolution_clock::now();
	chrono::duration<double> duracionQuick = tiempoFinal - tiempoInicial;
	copy(arrAuxiliar, arrAuxiliar+maximo, arrUtil);

	tiempoInicial = chrono::high_resolution_clock::now();
	heapSort(arrUtil, maximo);
	tiempoFinal = chrono::high_resolution_clock::now();
	chrono::duration<double> duracionHeap = tiempoFinal - tiempoInicial;
	copy(arrAuxiliar, arrAuxiliar+maximo, arrUtil);

	HANDLE hConsole = GetStdHandle( STD_OUTPUT_HANDLE );
	color(hConsole, 4);
	cout << "1. ";
	color(hConsole, 7);
	cout << "Insertion sort: " << duracionInsertion.count() << " segundos\n";
	color(hConsole, 4);
	cout << "2. ";
	color(hConsole, 7);
	cout << "Bubble sort: " << duracionBubble.count() << " segundos\n";
	color(hConsole, 4);
	cout << "3. ";
	color(hConsole, 7);
	cout << "Selection sort: " << duracionSelection.count() << " segundos\n";
	color(hConsole, 4);
	cout << "4. ";
	color(hConsole, 7);
	cout << "Shell sort: " << duracionShell.count() << " segundos\n";
	color(hConsole, 4);
	cout << "5. ";
	color(hConsole, 7);
	cout << "Merge sort: " << duracionMerge.count() << " segundos\n";
	color(hConsole, 4);
	cout << "6. ";
	color(hConsole, 7);
	cout << "Quick sort: " << duracionQuick.count() << " segundos\n";
	color(hConsole, 4);
	cout << "7. ";
	color(hConsole, 7);
	cout << "Heap sort: " << duracionHeap.count() << " segundos\n";
	
	chrono::duration<double> duracion[7]= {duracionInsertion, duracionBubble, duracionSelection, duracionShell, duracionMerge, duracionQuick, duracionHeap};
	chrono::duration<double> duracionMenor = duracionInsertion;
	string algoritmos[7] = {"Insertion sort", "Bubble sort", "Selection sort", "Shell sort", "Merge sort", "Quick sort", "Heap sort"};
	int ganador = 0;
	for(int i = 0; i<7; i++){
		if(duracion[i].count() < duracionMenor.count()){
			duracionMenor = duracion[i];
			ganador = i;
		}
	}
	cout << "\nEl ganador es: " << algoritmos[ganador] << " un tiempo de " << duracionMenor.count() << " segundos\n\n";
	
}
// Crea los cuatro arreglos necesarios para la problematica
// random_shuffle desordena un arreglo de manera aleatoria, es bastante practico para crear un arreglo aleatorio sin repeticion
// Tambien cree arreglos dinamicos porque a la hora de utilizar arreglos normales daba ciertos fallos en la memoria, desconosco el porque pero esta opcion me soluciono el problema
void crearArreglos(int maximo, string modo){

	int* arrOrdenado = new int[maximo];
	int* arrInverso = new int[maximo];
	int* arrDesordenado = new int[maximo];
	int* arrDuplicados = new int[maximo];
	int* arrAuxiliar = new int[maximo];

	for(int i = 0; i<maximo; i++){
		arrOrdenado[i] = i+1;
		arrInverso[maximo-i-1] = i+1;
		arrDuplicados[i] = rand()%maximo+1;
	}
	copy(arrOrdenado, arrOrdenado+maximo, arrDesordenado);
	random_shuffle(arrDesordenado, arrDesordenado+maximo);
	
	cout << "Carrera " << modo << ", Modo Ordenado\n";
	verificarTiempo(arrOrdenado, arrAuxiliar, maximo);
	cout << "Carrera " << modo << ", Modo Inverso\n";
	verificarTiempo(arrInverso, arrAuxiliar, maximo);
	cout << "Carrera " << modo << ", Modo Aleatorio\n";
	verificarTiempo(arrDesordenado, arrAuxiliar, maximo);
	cout << "Carrera " << modo << ", Modo Aleatorio con duplicados\n";
	verificarTiempo(arrDuplicados, arrAuxiliar, maximo);
	
	
	delete[] arrOrdenado;
    delete[] arrInverso;
    delete[] arrDesordenado;
    delete[] arrDuplicados;

}
// Obtiene un numero random dentro de un rango
int obtenerRandom(int inicio, int final){
	return rand()%(final-inicio+1)+inicio;
}
// Le da opciones al usuario para que decida que carrera quiere ejecutar
void menu(){
	int opcion = 0;
	cout << "Bienvenido a las carreras de algoritmos de ordenamiento\n";
	while(opcion != 4){
		cout << "Seleccione:\n1) Cola de espera\n2) Trazabilidad de objetos\n3) Eventos de cada escenario\n4) Salir\nIngrese una opcion: ";
		cin >> opcion;
		if(cin.fail()){
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "\nDebe ser un numero la opcion que ingresa\n";
		}
		if(opcion == 1){
			crearArreglos(obtenerRandom(100000, 110000), "Cola de espera");
		}
		if(opcion == 2){
			crearArreglos(obtenerRandom(1000*15, 1500*15), "Trazabilidad de objetos");
		}
		if(opcion == 3){
			crearArreglos(obtenerRandom(60000, 80000), "Eventos de cada escenario");
		}
		if(opcion > 4 || opcion < 1){
			cout << "Opcion invalida\n";
		}
	}
}

int main(){
	srand(time(0));
	menu();
	return 0;
}

