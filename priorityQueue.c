//Program to implement priority queue, which adds elements from the rear according to priority and deletes element from the front of the queue.
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    int priority;
    struct node *rlink, *llink;
};

struct node *front = NULL, *rear = NULL;//Declaring front and rear globally

struct node* insertion(int data, int priority){
    struct node *temp, *flag, *prev;

    temp = (struct node*) malloc (sizeof(struct node));
    temp->data = data;
    temp->priority = priority;
    temp->rlink = NULL;
    temp->llink = NULL;

    //first element in the queue
    if(front == NULL && rear == NULL){
        front = rear = temp;
    }else{
        flag = front;
        prev = NULL;
        while (flag != NULL && flag->priority >= priority){
            prev = flag;
            flag=flag->rlink;
        }
        if (prev == NULL){
            // insert at front
            temp->rlink = front;
            front->llink = temp;
            front = temp;
        }else if(flag == NULL){
            // insert at rear
            rear->rlink = temp;
            temp->llink = rear;
            rear = temp;
        }else{
            // insert in the middle
            prev->rlink = temp;
            temp->llink = prev;
            temp->rlink = flag;
            flag->llink = temp;
        }
    }
    return temp;
}


void deletion(){
    struct node* temp;
    temp = front;
    printf("Deleted %d with priority %d",temp->data,temp->priority);
    if(front->rlink){
        front=front->rlink;
    }else{
        front = NULL;
    }
    
    free(temp);
}

void display(){
    struct node* temp;
    temp = front;
    printf("Item :     ");
    //To print the value
    while(temp!= NULL){
        printf("%d\t",temp->data);
        temp = temp->rlink;
    }
    printf("\n");
    //To print the priority
    printf("Priority : ");
    temp = front;
    while (temp!= NULL)
    {
        printf("%d\t",temp->priority);
        temp = temp->rlink;
    }
    
}

void main(){

    int loop,data,priority,choice,repeat=1;

    while(repeat){
        printf("\nWhich operation would you like to perform?");
        printf("\n1: Insertion");
        printf("\n2: Deletion");
        printf("\n3: Display");
        printf("\n4: Exit");
        printf("\nYour Choice : ");
        if (scanf("%d",&choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            // used to continue till a valid input is read
            while (getchar() != '\n');
            continue;
        }

        if(choice == 1){
            //Insertion of a node
            int i=0;
            printf("How many terms would you like to enter?\nYour choice: ");
            scanf("%d",&loop);
            while (i<loop){
                printf("Enter the data: ");
                scanf("%d",&data);
                printf("Enter the priority: ");
                scanf("%d",&priority);
                insertion(data,priority);
                i++;
            }
        }else if(choice == 2){
            //Deletion of a node
            if(front != NULL && rear != NULL){
                deletion();
            }else{
                printf("Queue is empty");
            }
        }else if(choice == 3){
            //Displaying the present queue
            if(front != NULL && rear != NULL){
                display();
            }else{
                printf("Queue is empty");
            }
        }else if(choice == 4){
            //Exiting
            struct node* temp = front;
            while(front){
                front = front->rlink;
                free(temp);
                temp = front;
            }
            repeat = 0;

        }else{
            printf("\nInvalid Input");
        }

    }
    

}
