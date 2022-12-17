// Aryan Dhotre 21BCY10037
// Selection Sort
// Worst Case time complexity is : O(n^2)
// Best Case time complexity is : O(n^2)
// Count is the number of swappings
#include <stdio.h>
#include <stdlib.h>

int main(){
    int i, j, temp, n;
    int arr[] = {10,9,8,7,6,5,4,3,2,1};
    int count = 0;
    printf("Given Array for worst case: ");
    for(i=0; i<10; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    // selection sort
    n = sizeof(arr)/sizeof(arr[0]);
    for(i=0; i<n-1; i++){
        int min = i;
        for(j=i+1; j<n; j++){
            if(arr[j] < arr[min]){
                min = j;
                count++;
            }
        }
        temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
        
    }
    printf("Count for worst case: %d\n", count);
    printf("Sorted array: ");
    for(i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    printf("Given Array for best case: ");
    int newarr[] = {10,20,30,40,50,60,70,80,90,100};
    for(i=0; i<10; i++){
        printf("%d ", newarr[i]);
    }
    printf("\n");
    int newcount = 0;
    for(i=0; i<n-1; i++){
        int min = i;
        for(j=i+1; j<n; j++){
            if(newarr[j] < newarr[min]){
                min = j;
                newcount++;
            }
        }
        temp = newarr[min];
        newarr[min] = newarr[i];
        newarr[i] = temp;
        
    }
    printf("Count for best case: %d\n", newcount);
    printf("Sorted array: ");
    for(i=0; i<n; i++){
        printf("%d ", newarr[i]);
    }
}