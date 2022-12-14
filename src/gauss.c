#include "gauss.h"
#include "math.h"

/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */
int eliminate(Matrix *mat, Matrix *b){
    /**
  	 * Tutaj należy umieścić właściwą implemntację.
		 */

		int r, c, c_max, i;
		double *temp;
		double b_temp, multiplier;

		int n = mat->r;

		for (c = 0; c < n-1; c++) {
			c_max = c;

			for (r = c + 1; r < n; r++)
				if (fabs(mat->data[r][c]) > fabs(mat->data[c_max][c]))
					c_max = r;

			if (c_max != c) {
				temp = mat->data[c];

				mat->data[c] = mat->data[c_max];
				mat->data[c_max] = temp;
				
				b_temp = b->data[c][0];

				b->data[c][0] = b->data[c_max][0];
				b->data[c_max][0] = b_temp;
			}

			for (r = c + 1; r < n; r++) {
				if (mat->data[c][c] == 0)
						return n + c;

				multiplier = mat->data[r][c] / mat->data[c][c];

				for (i = c; i < n; i++)
					mat->data[r][i] -= multiplier * mat->data[c][i];

				b->data[r][0] -= multiplier * b->data[c][0];
			}
		}

		return 0;
}

