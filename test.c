#include <stdio.h>
#include <stdlib.h>

int rec_bsearch(int *array, int l, int r, int x) {
	if(r - 1 == l) return l;
	int m = (l + r)/2;
	if (x >= array[m - 1]) return rec_bsearch(array, m, r, x);
	else return rec_bsearch(array, l, m, x);
}

int bsearch1(int *array, int size, int x) {
	if (size == 0) return -1;
	if (x >= array[size - 1]) return -1;
	if (x < array[0]) return 0;
	return rec_bsearch(array, 0, size, x);
}

int main() {
	FILE *f = fopen("./input.txt", "r");
	int *a;
	int x, n, i;
	if (f == NULL) {
		printf("Error while opening file");
	}
	fscanf(f, "%d", &n);
	a = (int *) malloc(sizeof(int) * n);
	for (i = 0; i < n; ++i) {
		fscanf(f, "%d", &a[i]);
  }
	fscanf(f, "%d", &x);
	int res = bsearch1(a, n, x);
	if (res >= 0) {
		printf("First element of array, which is more then %d is "  
				    "element number %d (%d).\n", x, res + 1, a[res]);
	}
	else
	{
		 printf("There are no elements in array which is more then %d.\n", x);
	}
	free(a);
	fclose(f);
	return 0;
}



