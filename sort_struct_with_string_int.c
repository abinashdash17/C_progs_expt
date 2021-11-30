#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Book{
    char name[20];
    int pages;
};

typedef struct Book book;
int comp(const void *a,const void* b){
    book* x = (book *) a;
    book* y = (book *) b;
    if(x->pages > y->pages) return 1;
    else if(x->pages < y->pages) return -1;
    else return 0;
}



int main(){
    book b[3];
    strcpy(b[0].name,"med");
    b[0].pages = 67;
    strcpy(b[1].name,"low");
    b[1].pages = 64;
    strcpy(b[2].name,"high");
    b[2].pages = 69;
    
    for(int i = 0;i<3;i++){
        printf("%s %d",b[i].name,b[i].pages);
        printf("\n");
    }
    printf("\n");
    book * temp = (book *) malloc(sizeof(book));
    temp = &b[1];
    printf("test %d \n",temp -> pages);
    qsort(b,3,sizeof(book),comp);
    for(int i = 0;i<3;i++){
        printf("%s %d",b[i].name,b[i].pages);
        printf("\n");
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