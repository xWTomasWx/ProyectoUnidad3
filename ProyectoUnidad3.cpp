#include<iostream>
#include<chrono>
#include<cstdlib>
#include<time.h>
#include<algorithm>

using namespace std;

void intercambiar(int &a, int &b){
	int temp = a;
	a = b;
	b = temp;
}

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
            	intercambiar(arr[j], arr[j+1]);
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
        intercambiar(arr[indiceMin], arr[i]);
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
    int pivote = arr[high];
    int i = (low - 1);

    for(int j = low; j <= high - 1; j++){
        if(arr[j] < pivote){
            i++;
            intercambiar(arr[i], arr[j]);
        }
    }
    intercambiar(arr[i + 1], arr[high]);
    return (i + 1);
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
        intercambiar(arr[i], arr[maximo]);

        heap(arr, n, maximo);
    }
}

void heapSort(int arr[], int n){
    for(int i = n / 2 - 1; i >= 0; i--){
    	heap(arr, n, i);
	}
    for(int i = n - 1; i > 0; i--){
        intercambiar(arr[0], arr[i]);

        heap(arr, i, 0);
    }
}

void imprimirArreglo(int arr[], int n){
	for(int i = 0; i<n; i++){
		cout << arr[i] << " ";
	}
	cout << endl;
}



void crearArreglos(int maximo){

	int* arrOrdenado = new int[maximo];
	int* arrInverso = new int[maximo];
	int* arrDesordenado = new int[maximo];
	int* arrDuplicados = new int[maximo];
	int* arrAuxiliar = new int[maximo];

	for(int i = 0; i<maximo; ++i){
		arrOrdenado[i] = i+1;
		arrInverso[maximo-i] = i+1;
		arrDuplicados[i] = rand()%maximo+1;
	}
	copy(arrOrdenado, arrOrdenado+maximo, arrDesordenado);
	random_shuffle(arrDesordenado, arrDesordenado+maximo);
	
	
	delete[] arrOrdenado;
    delete[] arrInverso;
    delete[] arrDesordenado;
    delete[] arrDuplicados;
    delete[] arrAuxiliar;
}

int obtenerRandom(int inicio, int final){
	return rand()%(final-inicio+1)+inicio;
}

void menu(){
	int opcion = 0;
	cout << "Bienvenido a las carreras de algoritmos de ordenamiento\n";
	while(opcion != 4){
		cout << "Seleccione:\n1) Cola de espera\n2) Trazabilidad de objetos\n3) Eventos de cada escenario\n4) Salir\nIngrese una opcion: ";
		cin >> opcion;
		
		if(opcion == 1){
			
			crearArreglos(obtenerRandom(100000, 110000));
		}
		if(opcion == 2){
			crearArreglos(obtenerRandom(1000*15, 1500*15));
		}
		if(opcion == 3){
			crearArreglos(obtenerRandom(60000, 80000));
		}
		if(opcion > 4 || opcion < 1){
			cout << "Opcion invalida\n";
		}
	}
}

int main(){
	srand(time(0));
	menu();
	//imprimirArreglo(arr, n);
	/*auto t0 = chrono::high_resolution_clock::now();
	insertionSort(arr, n);
	auto t1 = chrono::high_resolution_clock::now();
	chrono::duration<double> duracion = t1 - t0;
	cout << "La funcion duro: " << duracion.count() << " segundos\n";*/
	//bubbleSort(arr, n);
	//selectionSort(arr, n);
	//shellSort(arr, n);
	//mergeSort(arr, 0, n-1);
	//quickSort(arr, 0, n-1);
	//heapSort(arr, n);
	//imprimirArreglo(arr, n);
	return 0;
}

