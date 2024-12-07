#include <stdio.h>
int array[5] = {1, 3, 5, 7, 9};
int key;

int search(int start, int end){
    if(start <= end){
        int mid = (start+end) / 2;
        if(array[mid] == key) return key;
        else if(array[mid] < key) return search(mid+1, end);
        else if(array[mid] > key) return search(start, mid-1);
    }
    return -1;
}
int main(){
    int n = sizeof(array) / sizeof(int);
    scanf("%d", &key);
    int result = search(0, n-1);
    printf("%d", result);
    return 0;
}