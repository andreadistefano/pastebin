#include <stdio.h>
#include <stdlib.h>
#define N 96

int LeggiNumRic(void);
int LeggiPrimo(int i);
int LeggiUltimo(int i);

int main () {
	typedef struct {
		int primo;
		int ultimo;
	}	richiesta;
	int i = 0;
	richiesta *elenco;
	int n = 0;
	n = LeggiNumRic();
	elenco = calloc (n, sizeof (richiesta));
	for (i = 0; i < n; i++) {
		elenco[i].primo = LeggiPrimo(i);
		elenco[i].ultimo = LeggiUltimo(i);
	}
	int count;
	int j;
	for (i = 0; i < N; i++) {
		count = 0;
		j = 0;
		for (j = 0; j < n; j++) {
			if (elenco[j].primo <= i && elenco[j].ultimo >= i) {
				count++;
			}
		}
		if (count < 3) {
			return i;
		}
	}
	return -1;
}

int LeggiNumRic(void) {
	int r;
	printf("Inserisci il numero di richieste pervenute: \n");
	scanf("%d", &r);
	return r;
}

int LeggiPrimo(int i) {
	int r;
	printf("Inserisci il primo giorno per la richiesta %d: \n", i);
	scanf("%d", &r);
	if (r > N - 1 || r < 0) {
		printf("Inserire un giorno tra 0 e 95.\n");
		printf("Inserisci il primo giorno per la richiesta %d: \n", i);
		scanf("%d", &r);
	}
	return r;
}

int LeggiUltimo(int i) {
	int r;
	printf("Inserisci l'ultimo giorno per la richiesta %d: \n", i);
	scanf("%d", &r);
	if (r > N - 1 || r < 0) {
		printf("Inserire un giorno tra 0 e 95.\n");
		printf("Inserisci l'ultimo giorno per la richiesta %d: \n", i);
		scanf("%d", &r);
	}
	return r;
}