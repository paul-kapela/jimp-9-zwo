#include "backsubst.h"
/**
 * Zwraca 0 - wsteczne podstawienie zakonczone sukcesem
 * Zwraca 1 - błąd dzielenia przez 0 (element na diagonali = 0)
 * Zwraca 2 - błąd nieprawidłowych rozmiarów macierzy
 */
int  backsubst(Matrix *x, Matrix *mat, Matrix *b) {
				/**
				 * Tutaj należy umieścić właściwą implemntację.
				 */
				
				int r, c;

				int n = mat->r;
				double s = 0;

				for (r = n - 1; r >= 0; r--) {	
					for (c = r + 1; c < n; c++)
						s += mat->data[r][c] * x->data[c][0];

					if (mat->data[r][r] == 0)
						return 1;

					x->data[r][0] = (b->data[r][0] - s) / mat->data[r][r];
				}

				return 0;
}


