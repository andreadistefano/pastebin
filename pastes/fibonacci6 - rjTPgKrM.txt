#include <stdio.h>
#include <stdlib.h>

unsigned long long int ** prodotto (unsigned long long int **, unsigned long long int **);
unsigned long long int ** potenza (unsigned long long int **, unsigned long long int);
unsigned long long int rigaxcolonna (unsigned long long int **, unsigned long long int **, unsigned long long int, unsigned long long int, unsigned long long int);

unsigned long long int main () {
	unsigned long long int **a = calloc(2, sizeof(unsigned long long int *));
	unsigned long long int i = 0;
	for (i = 0; i < 2; i++) {
		a[i] = calloc(2, sizeof(unsigned long long int));
	}
	unsigned long long int n = 0;
	printf("Questo programma calcola l'n-esimo numero di Fibonacci. Inserisci n: ");
	scanf("%lld", &n);
	if (n == 0) {
		printf("Fibonacci(0) non definito, errore. \n");
		return 1;
	}
	a[0][0] = 1;
	a[0][1] = 1;
	a[1][0] = 1;
	a[1][1] = 0;
	unsigned long long int **m = calloc(2, sizeof(unsigned long long int *));
	for (i = 0; i < 2; i++) {
		m[i] = calloc(2, sizeof(unsigned long long int));
	}
	m = potenza(a, n - 1);
	printf("Fibonacci(%lld) = %lld.\n", n, m[0][0]);
	return 0;
}

unsigned long long int ** potenza (unsigned long long int **a, unsigned long long int k) {
	unsigned long long int **res = calloc(2, sizeof(unsigned long long int *));
	unsigned long long int i = 0;
	unsigned long long int j = 0;
	for (i = 0; i < 2; i++) {
		res[i] = calloc(2, sizeof(unsigned long long int));
	}
	if (k <= 1) {
		res[0][0] = 1;
		res[0][1] = 0;
		res[1][0] = 0;
		res[1][1] = 1;
	}
	else {
		for (i = 0; i < 2; i++) {
			for (j = 0; j < 2; j++) {
				res[i][j] = a[i][j];
			}
		}
		res = potenza(res, k/2);
		res = prodotto(res, res);
	}
	if ((k%2) != 0) {
		res = prodotto(res, a);
	}
	return res;
}

unsigned long long int ** prodotto (unsigned long long int **m1, unsigned long long int **m2) {
	unsigned long long int **res = calloc(2, sizeof(unsigned long long int *));
	unsigned long long int i = 0;
	unsigned long long int j = 0;
	for (i = 0; i < 2; i++) {
		res[i] = calloc(2, sizeof(unsigned long long int));
	}
	for (i = 0; i < 2; i++) {
		for (j = 0; j < 2; j++) {
			res[i][j] = rigaxcolonna(m1, m2, i, j, 2); 
		}
	}
	return res;
}

unsigned long long int rigaxcolonna (unsigned long long int **m1, unsigned long long int **m2, unsigned long long int i, unsigned long long int j, unsigned long long int rank) {
	unsigned long long int r = 0;
	unsigned long long int k = 0;
	for (k = 0; k < rank; k++) {
		r += m1[i][k] * m2[k][j];
	}
	return r;
}