#include <bits/stdc++.h>
#include <chrono>

using namespace std;

long SecuencialOrd(long[], long, long);
long binaria(long[], long, long);
void shellSort(long[], long);

int main() {
    long n = 50000; // Tamaño del array
    long x[n], dato;
    double proms = 0, promb = 0;
    
    srand(time(0));
    // Generar arreglo
    for (long i = 0; i < n; i++) {
        x[i] = rand() % (10000000); //numeros grande para evitar repeticion de valores
    }

    // Generar un dato que seguramente no está en el arreglo'
    dato = 10000001; // Un valor fuera del rango

    int c = -1;
    do {
        cout << "Elija una opción (1: Secuencial, 2: Binaria, 0: Salir): ";
        cin >> c; // Capturamos la opción del usuario

        switch (c) {
            case 1:
                shellSort(x, n);
                for (long i = 0; i < 30; i++) {
                    auto start = chrono::high_resolution_clock::now(); // Inicia el cronómetro aquí

                    for (long j = 0; j < 10000; j++) { // Ejecutar 1000 veces
                        SecuencialOrd(x, n, dato);
                    }

                    auto end = chrono::high_resolution_clock::now(); // Termina el cronómetro aquí
                    chrono::duration<double> duration = end - start;
                    proms += duration.count() / 10000;
                    cout<< duration.count() / 10000<<endl;
                }
                proms = proms / 30; // calcular promedio
                cout << "Tiempo promedio de ejecución de SecuencialOrd: " << proms << " s" << endl; // Promediar
                break;

            case 2:
                shellSort(x, n);
                for (long i = 0; i < 30; i++) {
                    auto start = chrono::high_resolution_clock::now(); // Inicia el cronómetro aquí

                    for (long j = 0; j < 1000000; j++) { // Aumentar a 10000 veces
                        binaria(x, n, dato);
                    }

                    auto end = chrono::high_resolution_clock::now(); // Termina el cronómetro aquí
                    chrono::duration<double> duration = end - start;
                    promb += duration.count() / 1000000;
                    cout << duration.count() / 1000000<<endl;
                }
                promb = promb / 30; // calcular promedio
                cout << "Tiempo promedio de ejecución de binaria: " << promb << " s" << endl; // Promediar
                break;

            case 0:
                cout << "Saliendo..." << endl;
                break;

            default:
                cout << "Opción no válida, intente de nuevo." << endl;
                break;
        }
    } while (c != 0);

    return 0;
}

void shellSort(long x[], long n) {
    int k, cen, i, aux;
    k = n / 2; // Comenzar con un gap inicial
    while (k > 0) {
        cen = 1;
        while (cen == 1) {
            cen = 0;
            for (i = 0; i + k < n; i++) {
                if (x[i + k] < x[i]) {
                    // Intercambiar los elementos
                    aux = x[i];
                    x[i] = x[i + k];
                    x[i + k] = aux;
                    cen = 1; // Se hizo un intercambio
                }
            }
        }
        k = k / 2; // Reducir el gap
    }
}

long SecuencialOrd(long a[], long n, long dato) {
    long i = 0;
    while (i < n && a[i] < dato) {
        i++;
    }
    return (i < n && a[i] == dato) ? i : -1; // Retornar el índice o -1 si no se encuentra
}

long binaria(long a[], long n, long dato) {
    long izq = 0, der = n - 1;
    while (izq <= der) {
        long m = (izq + der) / 2;
        if (a[m] == dato) {
            return m; // Valor encontrado
        } else if (dato > a[m]) {
            izq = m + 1;
        } else {
            der = m - 1;
        }
    }
    return -1; // Valor no encontrado
}

