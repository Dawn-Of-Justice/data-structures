//Implementing stack using array
#include<stdio.h>
#define size 50 
int stack[size];
int top=-1;

void push(int noElement){
    int data,i=0;
    while(i<noElement){
    printf("Enter the data to input: ");
    scanf("%d",&data);
    if(top == size-1){
        printf("Stack Overflow");
    }else {
        top++;
        stack[top] = data;
    }
    i++;
    }
    }

int pop(){
    int item;
    if(top == -1){
        printf("Stack Underflow");
    }else {
        item = stack[top];
        top--;
        printf("The poped data is %d",item);
        return item;
    }
}

void display(){
    printf("The stack: ");
    for (int i=top;i>=0;i--){
        printf("%d ",stack[i]);
    }
}

int main(){
    int ch,loop=1,item,noElement;
    while(loop){
        printf("\n1 : Push Operation");
        printf("\n2 : Pop Operation");
        printf("\n3 : Display Operation");
        printf("\n4 : Exit");
        printf("\nYour Choice: ");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            printf("How many elements would you like to push: ");
            scanf("%d",&noElement);
            push(noElement);
            break;
        case 2:
            item = pop();
            break;
        case 3:
            if(top == -1)
            printf("Empty Stack");
            else
            display();
            break;
        case 4:
            loop=0;
            break;
        default:
            printf("Invalid input");
            break;
        }
    }
    
}
