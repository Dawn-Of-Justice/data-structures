//Implementing stack using linked list
#include<stdio.h>
#include<stdlib.h>
int top = -1;

struct node{
    int data;
    struct node *next;
};

void display(struct node * head){

}

struct node* pop(){

}

struct node* push(struct node * head, int data){
    struct node *temp,*flag;

    if(head == NULL){
        temp = (struct node*) malloc (sizeof(struct node));
        temp->data = data;
        temp->next = NULL;
        head = temp;
    }else{
        temp = head;
        while(temp->next!=NULL){
            temp = temp->next;
        }
        flag = (struct node*) malloc (sizeof(struct node));
        flag->data = data;
        flag->next = NULL;
        temp->next = flag;
    }
    return head;
}

int main(){
    int ch,loop=1,item,noElement,data;
    struct node *head = NULL;

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
            for(int i=0;i<noElement;i++){
                printf("Enter term %d",i+1);
                scanf("%d",&data);
                push(head,data);
            }
            break;
        case 2:
            item = pop();
            break;
        case 3:
            if(top == -1)
            printf("Empty Stack");
            else
            display(head);
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
