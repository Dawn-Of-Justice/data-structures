#include<stdio.h>
#include<stdlib.h>

struct node {
    int coeff;
    int expx;
    int expy;
    struct node *next;
};

void display(struct node* head){
    struct node *temp=head;
    while(temp!=NULL){
        (temp->coeff>0) ? printf("+ %dX^%dY^%d",temp->coeff,temp->expx,temp->expy) : printf("%dX^%d ",temp->coeff,temp->expx,temp->expy);
        temp = temp->next;
    }
}

struct node* PolyCreate(struct node* head, int coeff, int expx, int expy){
    struct node *temp, *flag;

    if(head == NULL){
        temp = (struct node*) malloc (sizeof(struct node));
        temp->coeff = coeff;
        temp->expx = expx;
        temp->expy = expy;
        temp->next = NULL;
        head = temp;
    }else {
        temp = head;
        while(temp->next!=NULL){
            temp = temp->next;
        }
        flag = (struct node*) malloc (sizeof(struct node));
        flag->coeff = coeff;
        flag->expx = expx;
        flag->expy = expy;
        flag->next = NULL;
        temp->next = flag;
    }
    return head;
}

struct node* PolyAdd(struct node* head1,struct node* head2,struct node* head3){
    struct node *temp1=head1, *temp2=head2, *temp3, *flag;
    head3 = NULL;
    while(temp1 && temp2){
        flag = (struct node*)malloc(sizeof(struct node));
        if(temp1->expx == temp2->expx){
            if(temp1->expy == temp2->expy){
                flag->coeff = temp1->coeff + temp2->coeff;
                flag->expx = temp1->expx;
                flag->expy = temp1->expy;
                temp1 = temp1->next, temp2 = temp2->next;
            }else{
                if(temp1->expy<temp2->expy){
                    flag->coeff = temp2->coeff;
                    flag->expx = temp2->expx;
                    flag->expy = temp2->expy;
                    temp2 = temp2->next;
                }else{
                    flag->coeff = temp1->coeff;
                    flag->expx = temp1->expx;
                    flag->expy = temp1->expy;
                    temp1 = temp1->next;
                }
            }
        }
        else{
            if(temp1->expx>temp2->expx){
                flag->coeff=temp1->coeff;
                flag->expx=temp1->expx;
                flag->expy=temp1->expy;
                temp1=temp1->next;
            }
            else{
                flag->coeff=temp2->coeff;
                flag->expx=temp2->expx;
                flag->expy=temp2->expy;
                temp2=temp2->next;
            }
        }
        flag->next = NULL;
        if(head3==NULL){
            head3=temp3=flag;
        }else{
            temp3->next = flag;
            temp3=flag;
        }
    }
    if(temp1 != NULL)
        flag = temp1;
    if(temp2 != NULL)
        flag = temp2;
        while(flag){
            temp3->coeff = flag->coeff;
            temp3->expx = flag->expx;
            temp3->expy = flag->expy;
            if(flag->next != NULL){
                temp3->next = (struct node*)malloc(sizeof(struct node));
                temp3 = temp3->next;
            }
            flag = flag->next;
        }
    return head3;
}

int main(){
    struct node *head1 = NULL, *head2 = NULL, *head3;
    int i=0,j=0,loop,coeff,expx,expy;
    printf("\nHow many terms are there in the First Polynomial: ");
    scanf("%d", &loop);
    while(i<loop){
        printf("Enter the coeffeicient of term %d of Polynomial 1: ",i+1);
        scanf("%d",&coeff);
        printf("Enter the exponent of x-term %d of Polynomial 1: ",i+1);
        scanf("%d",&expx);
        printf("Enter the exponent of y-term %d of Polynomial 1: ",i+1);
        scanf("%d",&expy);
        head1 = PolyCreate(head1,coeff,expx,expy);
        i++;
    }

    printf("\nHow many terms are there in the Second Polynomial: ");
    scanf("%d", &loop);
    while(j<loop){
        printf("Enter the coeffeicient of term %d of Polynomial 1: ",j+1);
        scanf("%d",&coeff);
        printf("Enter the exponent of x-term %d of Polynomial 1: ",j+1);
        scanf("%d",&expx);
        printf("Enter the exponent of y-term %d of Polynomial 1: ",j+1);
        scanf("%d",&expy);
        head2 = PolyCreate(head2,coeff,expx,expy);
        j++;
    }
    
    if(head1!=NULL){
        printf("\nPolynomial-1\n");
        display(head1);
    }
    if(head2!=NULL)
    {
        printf("\nPolynomial-2\n");
        display(head2);
    }
    head3 = PolyAdd(head1,head2,head3);
    if(head1!=NULL && head2!=NULL){
        printf("\nPolynomial After addition\n");
        display(head3);
    }
}