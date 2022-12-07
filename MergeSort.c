#include <stdio.h>
#define max 5

void merge(int arr[], int lb, int m, int ub)
{
	int i, j, k;
	int n1 = m - lb + 1;
	int n2 = ub - m;

	int temp1[n1], temp2[n2];    //create temp arrays

	for (i = 0; i < n1; i++)     // Copy data to temp arrays
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];

	// Adding Elements back to the array 
	i = 0; // Initial index of first subarray
	j = 0; // Initial index of second subarray
	k = lb; // Initial index of merged subarray
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		}
		else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	// Adding the remaining elements
	while (i < n1) {
		arr[k] = L[i];
		i++;
		k++;
	}
	while (j < n2) {
		arr[k] = R[j];
		j++;
		k++;
	}
}

void mergeSort(int arr[], int l, int r)
{
	if (l < r) {
		int m = l + (r - l) / 2;

		// Sort first and second halves
		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);

		merge(arr, l, m, r);
	}
}

void show(int A[])
{
	for (int i = 0; i < max; i++)
		printf("%d\n", A[i]);
}

int main()
{
	int arr[max];
	for(int i=0; i<max; i++)
	        scanf("%d", &arr[i]);
	show(arr);
	mergeSort(arr, 0, max-1);
	show(arr);
	return 0;
}
