#include<stdio.h>
#include<stdlib.h>
struct node{
int data;
struct node *next;
};
int main(){
    int choice=1,todo,i=1,loop;
    char option[1];
    struct node *HEAD,*NEWNODE,*TEMP,*PREVNODE,*NEXTNODE;
    HEAD = 0;
    printf("Linked List Implementation\n\n");
    while(choice){
        printf("How many elements would you like to enter: ");
        scanf("%d",&loop);
        while(i<=loop){
        NEWNODE = (struct node*)malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d",&NEWNODE->data);
        NEWNODE->next=0;

        if(HEAD == 0){
            HEAD=TEMP=NEWNODE;
        }else{
            TEMP->next=NEWNODE;
            TEMP=NEWNODE;
        }i++;
        }
    }
    Select:
    printf("\n\nChoice an operation to perform\n");
    printf("1: Display\n");
    printf("2: Insert at Beginning\n");
    printf("3: Insert at End\n");
    printf("4: Insert at a specified Position\n");
    printf("5: Delete from Beginning\n");
    printf("6: Delete form End\n");
    printf("7: Delete form a specified Position\n");
    printf("8: Exit\n");
    scanf("%d",&todo);

    if(todo==1){
//Displaying Linked List

        TEMP = HEAD;
        printf("\nLinked List\n");
        while(TEMP!=0){
            printf("%d\t",TEMP->data);
            TEMP=TEMP->next;
        }goto Select;

    }else if(todo==2){
//Insert at Beginning

     NEWNODE =(struct node*)malloc(sizeof(struct node));
     printf("Enter data you want to insert in the beginning: ");
     scanf("%d",&NEWNODE->data);
     NEWNODE->next = HEAD;
     HEAD = NEWNODE;
     goto Select;

    }else if(todo==3){
//Insert at End

     NEWNODE =(struct node*)malloc(sizeof(struct node));
     printf("Enter data you want to insert in the end: ");
     scanf("%d",&NEWNODE->data);
     NEWNODE->next = 0;
     TEMP = HEAD;
     while(TEMP->next != 0){
        TEMP=TEMP->next;
     }
     TEMP->next=NEWNODE;
     goto Select;

    }else if(todo==4){
//Insert at specified Position

     NEWNODE =(struct node*)malloc(sizeof(struct node));
     int pos,count=0,i;
     TEMP=HEAD;
     while(TEMP!=0){
        count++;
        TEMP=TEMP->next;
     }count++;
     Position:
     printf("Enter the position you want to enter the data: ");
     scanf("%d",&pos);
     if(pos>count){
        printf("Invalid Position");
        goto Position;
     }else{
        TEMP=HEAD;
        while(i<pos){
            TEMP=TEMP->next;
            i++;
        }printf("Enter data you want to insert in the position %d: ",pos);
        scanf("%d",&NEWNODE->data);
        NEWNODE->next=TEMP->next;
        TEMP->next=NEWNODE;
     }goto Select;

    }else if(todo==5){
//Delete from Beginning

    TEMP=HEAD;
    HEAD = HEAD->next;
    free(TEMP);
    goto Select;

    }else if(todo==6){
//Delete from End

    TEMP=HEAD;
    while(TEMP->next!=0){
        PREVNODE=TEMP;
        TEMP=TEMP->next;
    }if(TEMP==HEAD)
        HEAD=0;
    else
        PREVNODE->next=0;
    free(TEMP);
    goto Select;

    }else if(todo==7){
//Delete from a specified Position

    int pos,i=1;
    TEMP=HEAD;
    printf("Enter the position of the element you would like to delete");
    scanf("%d",&pos);
    while(i<pos-1){
        TEMP=TEMP->next;
        i++;
    }NEXTNODE=TEMP->next;
    TEMP->next=NEXTNODE->next;
    free(NEXTNODE);
    goto Select;

    }else if(todo==8){
//Exit
    }else{
    printf("Invalid Option");
    goto Select;
    }
}
