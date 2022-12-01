#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node {
    int rollno;
    char name[20];
    int totalmark;
    struct node *next;
};

struct node* insert(struct node* head,int rollno, char name[],int totalmark){
    struct node *temp,*flag;

    if(head == NULL){
        temp = (struct node*) malloc (sizeof(struct node));
        temp ->rollno = rollno;
        strcpy(temp->name,name);
        temp ->totalmark = totalmark;
        temp ->next = NULL;
        head = temp;
    }else{
        temp = head;
        while(temp->next!=NULL){
            temp = temp->next;
        }
        flag = (struct node*) malloc(sizeof(struct node));
        flag ->rollno = rollno;
        strcpy(flag ->name,name);
        flag ->totalmark = totalmark;
        flag ->next = NULL;
        temp->next = flag;
    }
    return head;
}

struct node* delete(struct node* head,int rollno){
    struct node* temp=head, *flag;
    int result=0;
    while (temp!=NULL){
        if(temp->rollno == rollno){
            result = 1;
            if(temp == head){
                flag = temp->next;
                free(temp);
                head = flag;
            }else if(temp->next == NULL){
                free(temp);
                flag-> next = NULL;
            }else{
                flag->next = temp->next;
                free(temp);
            }
        }else{
            flag = temp;
            temp = temp->next;
        }
    }
    if(result==0)
    printf("Roll number not found!");
    return head;
}

struct node* search(struct node* head,int searchNo){
    struct node *temp=head;
    int result = 0;
    while(temp!=NULL){
        if(temp->rollno == searchNo){
            result = 1;
            printf("Roll Number : %d\n", temp->rollno);
            printf("Name : %s\n", temp->name);
            printf("Total Mark : %d\n", temp->totalmark);
            return temp;
        }else{
            temp = temp->next;
        }
    }
    if(result==0)
    printf("Roll number not found!");

}

void BubbleSort(int rollNo[], int n){
    for(int i=0;i<n-1;++i){
        for(int j=0;j<n-i-1;++j){
            if(rollNo[j]>rollNo[j+1]){
                int temp = rollNo[j];
                rollNo[j] = rollNo[j+1];
                rollNo[j+1] = temp;
            }
        }
    }
}

struct node* swap(struct node* head,int rollNo[], int count){
    struct node *temp, *result, *flag=head;
    int i=0;
    temp = (struct node*) malloc(sizeof(struct node));
    result = temp;
    while(i < count){
        while(flag->rollno!=rollNo[i] && flag!= NULL){
            flag= flag->next;
        }
        temp->rollno=flag->rollno;
        strcpy(temp->name,flag->name);
        temp->totalmark=flag->totalmark;
        flag=head;
        i++;
        if(i>count-1){
            temp->next = NULL;
        }
        else{
        temp->next = (struct node*) malloc(sizeof(struct node));
        temp = temp->next;
        }
    }
    printf("Sorted Successfully");
    return result;
}

struct node* sort(struct node* head,int count){
    struct node *temp=head,*result;
    int rollNo[count],i=0,*sortRollNo;
    //Storing Roll number to array for sorting
    while(temp!=NULL){
        rollNo[i]=temp->rollno;
        temp=temp->next;
        i++;
    }
    BubbleSort(rollNo,count);
    result = swap(head,rollNo,count);
    return result;
}

void Display(struct node* head){

    struct node *temp = head;
    printf("\nStudent Details\n");
    while(temp!=NULL){
        printf("Roll Number : %d\n", temp->rollno);
        printf("Name : %s\n", temp->name);
        printf("Total Mark : %d\n", temp->totalmark);
        temp = temp->next;
    }

}

int main(){
    struct node *head = NULL;
    int ch=1,option,dRollNo;
    
    while(ch){
    printf("\n1 : Insert Student Details\n");
    printf("2 : Delete a Student baised on Roll number\n");
    printf("3 : Search a student baised on Roll number\n");
    printf("4 : Sort\n");
    printf("5 : Display the current List\n");
    printf("6 : Exit\n");
    scanf("%d",&option);

    switch(option){
        case 1://Insert 
            if(head!=NULL){
                int overRide=1;
                printf("List not empty\n Overriding May occure \nPress 1 to continue\n Press 0 to Cancel\n");
                scanf("%d",&overRide);
                if(overRide==0)
                break;
            }
            int loop,i=0;
            printf("Number of student details you would like to add: ");
            scanf("%d",&loop);
            while(i<loop){
                int rollno,totalmark;
                char name[20];
                printf("Roll no: ");
                scanf("%d",&rollno);
                printf("Enter the name of the student: ");
                scanf("%s",name);
                printf("Enter the total mark of %s: ", name);
                scanf("%d",&totalmark);
                head = insert(head,rollno,name,totalmark);
                i++;
            }break;

        case 2://Delete
            if(head!=NULL){
            printf("Enter the Student roll Number you would like to delete: ");
            scanf("%d",&dRollNo);
            delete(head,dRollNo);
            }else
            printf("Empty List");
            break;

        case 3://Search
            printf("Enter the Roll Number to search: ");
            int searchNo;
            scanf("%d",&searchNo);
            if(head!=NULL)
            search(head,searchNo);
            else
            printf("List Empty");
            break;

        case 4://Sort
            if(head!=NULL){
                struct node *temp=head;
                int count = 0;
                while(temp!=NULL){
                    count++;
                    temp=temp->next;
                }
                head = sort(head,count);
            }else
            printf("List Empty");
            break;

        case 5://Display
            Display(head);
            break;

        case 6:
            ch = 0;
            free(head);
            break;

        default:
            printf("Invalid Option");
            ch = 1;
            break;
    }
    }

    return 0;

}