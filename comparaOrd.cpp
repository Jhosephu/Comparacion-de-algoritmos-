#include <iostream>
#include <ctime>
#include <cstdlib>
#include <chrono>

using namespace std;

const int MAXIMONUMERO = 10000;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int particion(int arreglo[], int bajo, int alto) {
    int pivote = arreglo[alto]; 
    int i = bajo - 1;           

    for (int j = bajo; j < alto; j++) {
        if (arreglo[j] < pivote) {
            i++;
            swap(arreglo[i], arreglo[j]); 
        }
    }
    swap(arreglo[i + 1], arreglo[alto]);
    return i + 1;                                
}

void quickSortR(int arreglo[], int bajo, int alto) {
    if (bajo < alto) {
        int indicePivote = particion(arreglo, bajo, alto); 
        quickSortR(arreglo, bajo, indicePivote - 1);        
        quickSortR(arreglo, indicePivote + 1, alto);       
    }
}

void quickSort(int arreglo[], int n) {
    quickSortR(arreglo, 0, n - 1);
}

void insercionDirecta(int arreglo[],int n){
	int aux, k;
	for(int i = 1; i < n; i++){
		aux = arreglo[i];
		k = i-1;
		while(k>=0 && aux < arreglo[k]){
			arreglo[k+1] = arreglo[k];
			k--;
		}
		arreglo[k+1]=aux;
	} 
}

void generarArregloAleatorio(int arreglo1[], int arreglo2[], int n){
	for (int i = 0; i < n; i++){
		arreglo1[i] = arreglo2[i] = rand() % MAXIMONUMERO + 1;
	}
}

void mostrarArreglo(int arreglo[], int n){
	for (int i = 0; i < n; i++){
		cout << arreglo[i] << " ";
	}
}

void ejecutarInsercionDirecta(int arreglo1[], int n){
	auto inicio = chrono::high_resolution_clock::now();
	insercionDirecta(arreglo1, n);
	auto final = chrono::high_resolution_clock::now();
	chrono::duration<double> duration = final - inicio;
	cout << "Tiempo de ejecucion del algoritmo: " << duration.count() << endl;
	//mostrarArreglo(arreglo1, n);
}

void ejecutarQuickSort(int arreglo2[], int n){
	auto inicio = chrono::high_resolution_clock::now();
	quickSort(arreglo2, n);
	auto final = chrono::high_resolution_clock::now();
	chrono::duration<double> duration = final - inicio;
	cout << "Tiempo de ejecucion del algoritmo: " << duration.count() << endl;
	//mostrarArreglo(arreglo2, n);
}

void menu(int arreglo1[], int arreglo2[], int n){
	int option;
	do {
		cout << "\nOpciones del programa" << endl;
		cout << "1. Ordenar por algoritmo de insercion directa" << endl;
		cout << "2. Ordenar por algoritmo QuickSort" << endl;
		cout << "3. Generar nuevamente el arreglo aleatoriamente" << endl;
		cout << "0. Salir" << endl;
		cout << "Opcion: ", cin >> option;
		cout << endl;
		
		switch(option){
			case 1:
				ejecutarInsercionDirecta(arreglo1, n);
				break;
			case 2:
				ejecutarQuickSort(arreglo2, n);
				break;
			case 3:
				generarArregloAleatorio(arreglo1, arreglo2, n);
				cout << "Arreglos correctamente generados aleatoriamente" << endl;
				break;
			case 0:
				cout << "Saliendo..." << endl;
				break;
			default:
				cout << "Opcion invalida" << endl;
		} 	
	} while(option != 0);

}

int main(){
	srand(time(NULL));
	
	int n;
	cout << "Ingrese la cantidad de elementos de su arreglo: ", cin >> n;
	
	int* arreglo1 = new (nothrow) int[n];
    int* arreglo2 = new (nothrow) int[n];
    

    if (arreglo1 == nullptr || arreglo2 == nullptr) {
        cout << "Error: No hay suficiente memoria para crear los arreglos" << endl;
        delete[] arreglo1;
        delete[] arreglo2;
        return 1;
    }
    
    generarArregloAleatorio(arreglo1, arreglo2, n);
    menu(arreglo1, arreglo2, n);
    
    delete[] arreglo1;
    delete[] arreglo2;
	
	return 0;
}
