#include <stdio.h>
int list[100000];
int sorted[100000];
void merge(int left,int mid, int right){
    int i = left, j = mid + 1, k = left, l;

    while (i <= mid && j <= right){
        if (list[i] <= list[j]) sorted[k++] = list[i++];
        else sorted[k++] = list[j++];
    }

    if (i > mid) for (l = j ; l <= right ; l++) sorted[k++] = list[l];
    else for (l = i ; l <= mid ; l++) sorted[k++] = list[l];

    for (l = left ; l <= right ; l++) list[l] = sorted[l];
}
void mergesort(int left, int right){
    if(left < right){
        int mid = (left+right)/2;
        mergesort(left, mid);
        mergesort(mid+1, right);
        merge(left, mid, right);
    }
}
int main(){
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d", &list[i]);
    }
    mergesort(0, n-1);
    for(int i=0; i<n; i++){
        printf("%d ", list[i]);
    }
    return 0;
}