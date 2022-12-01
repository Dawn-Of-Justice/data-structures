#include<stdio.h>

void linearsearch(int);

int main(){
    int size;
    printf("Enter the number of elements: ");
    scanf("%d",&size);
    linearsearch(size);
}

void linearsearch(int size) { 
    int i=0,array[size],search;
    printf("Enter the elements one by one\n");
    while(i<size){
        scanf("%d",&array[i]);
        i++;
    }
    printf("Enter the element to be searched: ");
    scanf("%d",&search);
    int j=0,flag=0;
    while (j<size){
        if(array[j]==search){
            printf("Element %d found at index %d\n", search, j);
            flag=1;
        }
        j++;
    }
    if(flag==0){
        printf("Element not found in the array");
    }
}

