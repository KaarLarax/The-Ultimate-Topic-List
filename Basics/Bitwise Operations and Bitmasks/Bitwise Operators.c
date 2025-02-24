#include <stdio.h>
// Funcion para calcular los valores maximos
void calculate_the_maximum(int n, int k) {
    int ii = 0, oo = 0, xx = 0;
    
    for (int i = 1; i < n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            if ((i & j) < k) {
                ii = (i & j) > ii ? (i & j) : ii;
            }
            if ((i | j) < k) {
                oo = (i | j) > oo ? (i | j) : oo;
            }
            if ((i ^ j) < k) {
                xx = (i ^ j) > xx ? (i ^ j) : xx;
            }
        }
    }
    printf("%d\n", ii);
    printf("%d\n", oo);
    printf("%d\n", xx);
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k); // Leer valores de entrada
    calculate_the_maximum(n, k); // Llamar a la funcion
    return 0;
}