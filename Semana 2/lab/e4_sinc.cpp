#include <iostream>
using namespace std;

bool mayor(int a, int b) {
    return a > b;
}

bool menor(int a, int b) {
    return a < b;
}

bool mayorValorAbsoluto(int a, int b) {
    int absA = (a < 0) ? -a : a;
    int absB = (b < 0) ? -b : b;
    return absA > absB;
}

bool parAntesQueImpar(int a, int b) {
    bool aEsPar = (a % 2 == 0);
    bool bEsPar = (b % 2 == 0);
    
    if (aEsPar && !bEsPar) return true;
    if (!aEsPar && bEsPar) return false;
    
    return false;
}

void ordenar(int* inicio, int* fin, bool (*criterio)(int, int)) {
    int n = fin - inicio;
    
    for (int i = 0; i < n - 1; i++) {
        bool huboIntercambio = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (criterio(inicio[j + 1], inicio[j])) {
                swap(inicio[j + 1], inicio[j]);
                huboIntercambio = true;
            }
        }
        if (!huboIntercambio) break;
    }
}

bool igual(int a, int b) {
    return a == b;
}

bool mismoValorAbsoluto(int a, int b) {
    int absA = (a < 0) ? -a : a;
    int absB = (b < 0) ? -b : b;
    return absA == absB;
}

bool mismaParidad(int a, int b) {
    return (a % 2) == (b % 2);
}

int* buscar(int* inicio, int* fin, bool (*equivale)(int, int), int clave) {
    for (int* p = inicio; p != fin; p++) {
        if (equivale(*p, clave)) {
            return p;
        }
    }
    return nullptr;
}

int* maximoSegun(int* inicio, int* fin, bool (*mejor)(int, int)) {
    if (fin - inicio == 1) {
        return inicio;
    }
    
    int* mejorDelResto = maximoSegun(inicio + 1, fin, mejor);
    
    if (mejor(*inicio, *mejorDelResto)) {
        return inicio;
    } else {
        return mejorDelResto;
    }
}

int main() {
    int A[] = {7, -2, 5, 0, -9, 4};
    int n = 6;
    
    cout << "=== ARREGLO ORIGINAL ===\n";
    for (int i = 0; i < n; i++) cout << A[i] << " ";
    cout << "\n\n";
    
    int B1[] = {7, -2, 5, 0, -9, 4};
    ordenar(B1, B1 + n, mayor);
    cout << "ORDENAR MAYOR: ";
    for (int i = 0; i < n; i++) cout << B1[i] << " ";
    cout << "\n";
    
    int B2[] = {7, -2, 5, 0, -9, 4};
    ordenar(B2, B2 + n, menor);
    cout << "ORDENAR MENOR: ";
    for (int i = 0; i < n; i++) cout << B2[i] << " ";
    cout << "\n";
    
    int* resBusqueda = buscar(A, A + n, mismoValorAbsoluto, 9);
    if (resBusqueda) cout << "BUSCAR ABS 9: " << *resBusqueda << "\n";
    
    int* resMax = maximoSegun(A, A + n, mayorValorAbsoluto);
    cout << "MAX ABSOLUTO: " << *resMax << "\n";
    
    return 0;
}