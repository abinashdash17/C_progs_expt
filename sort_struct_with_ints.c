#include<stdio.h>
#include<stdlib.h>

struct Book{
    int index;
    int pages;
};

typedef struct Book book;
int comp(const void *a,const void* b){
    book* x = (book *) a;
    book* y = (book *) b;
    if(x->pages > y->pages) return -1;
    else if(x->pages < y->pages) return 1;
    else return 0;
}



int main(){
    book b[3];
    b[0].index = 0;
    b[0].pages = 67;
    b[1].index = 1;
    b[1].pages = 64;
    b[2].index = 0;
    b[2].pages = 69;
    
    for(int i = 0;i<3;i++){
        printf("%d ",b[i].pages);
    }
    printf("\n");
    book * temp = (book *) malloc(sizeof(book));
    temp = &b[1];
    printf("test %d \n",temp -> pages);
    qsort(b,3,sizeof(book),comp);
    for(int i = 0;i<3;i++){
        printf("%d ",b[i].pages);
    }
    printf("\n");
/*
    for(int i = 0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    */
    return 0;
}