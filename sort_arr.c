#include<stdio.h>
#include<stdlib.h>

int comp(const void *a,const void* b){
    int x = *(const int *) a;
    int y = *(const int *) b;
    if(x>y) return 1;
    else if(x<y) return -1;
    else return 0;
}

int main(){
    int n=7;
    //printf("enter a num: ");
    //scanf("%d",&n);
    int* arr = (int *) malloc(n*sizeof(*arr));
    int arr2[]= {1,2,3,4,5,6,7};
    for(int i = 0;i<n;i++){
        arr[i] = n-i;
    }
    for(int i = 0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    int l1= sizeof arr / sizeof *arr;
    int l2= sizeof arr2 / sizeof *arr2;
    printf("%d %d\n",l1,l2);
    qsort(arr,l1,sizeof(int),comp);
    for(int i = 0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    return 0;
}