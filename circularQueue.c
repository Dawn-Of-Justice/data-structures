//Circular queue with size 5
#include<stdio.h>
#define size 5 //Size of the array
int queue[size];
int front = -1;
int rear = -1;

//Inserting data
void enqueue(int x){
    if (front == -1 && rear == -1){
        front = rear = 0;
        queue[rear] = x;
    }else if(((rear+1)%size)==front){
        printf("Queue is full");
    }else{
        rear=(rear+1)%size;
        queue[rear]=x;
    }
}

void dequeue(){
    if(front == -1 && rear == -1){
        printf("Queue is empty");
    }else{
        printf("Deleted %d from front\n",queue[front]);
        if(front == rear){
            front = rear =-1;
        }else{
            front =(front+1)%size;
        }
    }
}

void display(){
    if(front ==-1 && rear == -1){
        printf("Queue Empty\n");
    }else{
        printf("Queue\n");
        int i=front;
        while(i!=rear){
            printf("%d ",queue[i]);
            i=(i+1)%size;
        }
        printf("%d",queue[rear]);
    }
}

void main(){
int loop=1;
    while(loop){
        int choice;
        printf("\nWhich operation would you like to do in Circular queue?\n");
        printf("1 : Inserte data in the rear\n");
        printf("2 : Delete data in the front\n");
        printf("3 : Display the queue\n");
        printf("4 : Exit\n");
        printf("Your choice: ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            printf("How many elements would you like to insert: ");
            int num,i=0,data; 
            scanf("%d",&num);
            if(num>size){
                printf("Insufficient space in array, Update size");
            }else{
                while(i<num){
                    printf("Enter term %d: ",i+1);
                    scanf("%d",&data);
                    enqueue(data);
                    i++;
                }
            }
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            loop=0;
            break;
        default:
            printf("Invalid Option");
            break;
        }
    }
}
