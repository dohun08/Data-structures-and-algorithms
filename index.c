#include <stdio.h>
int n = 5;
int hash(int key){
    return key%n;
}
int main(){
    int key;
    int k=-1;
    int list[5] = {1,0,3,40, 0};
    scanf("%d", &key);
    int index = hash(key);
    while(1){
        if(list[index] == 0){
            list[index] = key;
            break;
        }
        else{
            k++;
            index = (hash(key)+(k*k))%n;
        }
    }
    printf("%d", index);
    return 0;
}