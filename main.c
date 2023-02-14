#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>
#define ll long long
ll SWAP, COMP;
void swap(ll *var1, ll *var2){
    SWAP++;
    ll var = *var1;
    *var1 = *var2;
    *var2 = var;
}
int comp(ll var1, ll var2){
    COMP++;
    if(var1 < 0) var1 *= -1;
    if(var2 < 0) var2 *= -1;
    //
    if(var1 < var2) return -1;
    else if(var1 > var2) return 1;
    else return 0;
}
void InsertionSort(int n, ll *arr){
    printf("Insertion sort:\n");
    COMP = 0;
    SWAP = 0;
    for(int i = 0; i < n - 1; i++){
        int ind = i;
        for(int j = i + 1; j < n; j++){
            if(comp(arr[j], arr[ind]) < 0) ind = j;
        }
        swap(&arr[i], &arr[ind]);
    }
    printf("comparisons %lld swaps %lld\n", COMP, SWAP);
}
int part(int n, ll *arr, int l, int r){
    int ind = l;
    for(int i = l; i < r; i++){
        if(comp(arr[i], arr[r]) <= 0){
            swap(&arr[i], &arr[ind++]);
        }
    }
    swap(&arr[r], &arr[ind]);
    return ind;
}
void recursive(int n, ll *arr, int l, int r){
    if(l >= r) return;
    int mid = part(n, arr, l, r);
    recursive(n, arr, l, mid - 1);
    recursive(n, arr, mid + 1, r);
}
void QuickSort(int n, ll *arr){
    printf("Quick sort:\n");
    COMP = 0;
    SWAP = 0;
    recursive(n, arr, 0, n - 1);
    printf("comparisons %lld swaps %lld\n", COMP, SWAP);
}
void build_arr(int n, ll *arr, int type){
    srand(time(NULL));
    for(int i = 0; i < n; i++){
        if(type == 1) arr[i] = i + 1;
        else if(type == 2) arr[i] = n - i;
        else arr[i] = rand() * ((rand() % 2) ? -1: 1);
    }
}
int main()
{
    int n, type;
    printf("Please enter size of array and original order of elements: ");
    scanf("%d %d", &n, &type);
    //
    ll *arr = malloc(sizeof(ll) * n);
    build_arr(n, arr, type);
    //
    ll *copy = malloc(sizeof(ll) * n);
    for(int i = 0; i < n; i++) copy[i] = arr[i];
    //
    InsertionSort(n, arr);
    QuickSort(n, copy);
    //
    free(arr);
    free(copy);
}
