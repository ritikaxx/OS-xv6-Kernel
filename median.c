#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"
void swap(int* xp, int* yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 

void selectionSort(int arr[], int n) 
{ 
    int i, j, min_idx; 
 
    for (i = 0; i < n - 1; i++) { 

        min_idx = i; 
        for (j = i + 1; j < n; j++) 
            if (arr[j] < arr[min_idx]) 
                min_idx = j; 

        swap(&arr[min_idx], &arr[i]); 
    } 
}
int main(int argc, char *argv[])
{
    int size = argc-1;
    int data[size];
    int i;
    int m = 0;
    for (i=0;i<size;i++)
    {
        data[i]=atoi(argv[i+1]);
    }
    selectionSort(data, size);
    if(size % 2 == 0) {
        m = (data[size/2] + data[(size/2)-1]) / 2;
    }
    else {
        m = data[size/2];
    }
    printf(1,"\n median value is: %d \n",median(m));
    exit();
}
