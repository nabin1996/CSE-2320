// Nabin Shrestha
/* C program for Merge Sort */
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h>
// Merges two subarrays of arr[]. 
// First subarray is arr[l..m] 
// Second subarray is arr[m+1..r] 
void merge(int arr[], int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 = r - m; 
  
    /* create temp arrays */
    int L[n1], R[n2]; 
  
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1 + j]; 
  
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray 
    j = 0; // Initial index of second subarray 
    k = l; // Initial index of merged subarray 
    while (i < n1 && j < n2) 
	{ 
        if (L[i] <= R[j]) 
		{ 
            arr[k] = L[i]; 
            i++; 
        } 
        else 
		{ 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    /* Copy the remaining elements of L[], if there 
       are any */
    while (i < n1) 
	{ 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    /* Copy the remaining elements of R[], if there 
       are any */
    while (j < n2) 
	{ 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 
  
/* l is for left index and r is right index of the 
   sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r) 
{ 
    if (l < r) 
	{ 
        // Same as (l+r)/2, but avoids overflow for 
        // large l and h 
        int m = l + (r - l) / 2; 
  
        // Sort first and second halves 
        mergeSort(arr, l, m); 
        mergeSort(arr, m + 1, r); 
  
        merge(arr, l, m, r); 
    } 
} 
  
/* UTILITY FUNCTIONS */
/* Function to print an array */
void PRINTARRAY(int A[], int size) 
{ 
    int i; 
    for (i = 0; i < size; i++) 
        printf("%d ", A[i]); 
    printf("\n"); 
} 
void insertionSort(int arr[], int n)  
{  
    int i, key, j;  
    for (i = 1; i < n; i++) 
    {  
        key = arr[i];  
        j = i - 1;  
  
        /* Move elements of arr[0..i-1], that are  
        greater than key, to one position ahead  
        of their current position */
        while (j >= 0 && arr[j] > key) 
        {  
            arr[j + 1] = arr[j];  
            j = j - 1;  
        }  
        arr[j + 1] = key;  
    }  
}
/* Driver program to test above functions */
int main(int argc, char *argv[]) 	
{ 
	int num =0;
	char filename[100];
    FILE *fp;
	int count=0;
   fp = fopen(argv[1], "r");
   while (fp == NULL)
   {
	  //if file = NULL ask user file name 
	  if (filename == NULL)
	  {
		  printf("file cannot be opened: \n");
		  scanf("%s",filename);
		  fp = fopen(filename,"r");
	  }
		  
   } 
   while (fgets(filename , 99, fp ) != NULL)
   {
	   count++;
	   // count number of line
   }
   int *arr = malloc(sizeof(int)*count);
   // use malloc to allocate memory in the heap
   fseek(fp,0,0);
   
   // use fseek to go to the begining of file
   
   while(fgets(filename, sizeof(filename)-1, fp) != NULL )
   {
	   arr[num] = atoi(filename);
	   num++;
   }
   // use while loop to go through the file again and inside while loop change the read input into integer and add that integer to the array 
	//use code clock 
	clock_t start, end; 
	start = clock(); 
    mergeSort(arr, 0, count - 1);
	//Call Merge Sort 
    end = clock();
	printf("mergeSort total tics= %ld.\n", end-start);
    //free memory 
	
	#ifdef PRINTARRAY
    printf("\nSorted array is \n"); 
    PRINTARRAY(arr, count); 
	#endif
	free(arr);
	arr = malloc(sizeof(int)*count);
	num = 0;
	fseek(fp,0,0);
   
   // use fseek to go to the begining of file
   
   while(fgets(filename, sizeof(filename)-1, fp) != NULL )
   {
	   arr[num] = atoi(filename);
	   num++;
   }
   // use while loop to go through the file again and inside while loop change the read input into integer and add that integer to the array 	
	start = clock(); 
    insertionSort(arr, count - 1);
	//Call Merge Sort 
    end = clock();
    //mergeSort(arr, 0, arr_size - 1); 
	printf("insertionSort total tics= %ld.\n", end-start);
    //free memory
	#ifdef PRINTARRAY
    printf("\nSorted array is \n"); 
    PRINTARRAY(arr, count); 
	#endif
	free(arr);
	
    return 0; 
} 


