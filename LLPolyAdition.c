//Program which implements single variable polynomial additon using linked list
#include<stdio.h>
#include<stdlib.h>

struct node {
int coeff;
int exp;
struct node *next;
};

struct node* createPoly(struct node* head, int coeff, int exp){
    struct node *temp, *flag;

    if(head == NULL){
        temp = (struct node*) malloc (sizeof(struct node));
        temp->coeff = coeff;
        temp->exp = exp;
        temp->next = NULL;
        head = temp;
    }else{
        temp = head;
        while(temp->next!=NULL){
            temp = temp->next;
        }
        flag = (struct node*)malloc(sizeof(struct node));
        flag->coeff = coeff;
        flag->exp = exp;
        flag->next = NULL;
        temp->next = flag;
    }
    return head;
}

void display(struct node* head){
    struct node *temp=head;
    while(temp!=NULL){
        (temp->coeff>0) ? printf("+ %dX^%d ",temp->coeff,temp->exp) : printf("%dX^%d ",temp->coeff,temp->exp);
        temp = temp->next;
    }
}

struct node* PolyAdd(struct node* head1,struct node* head2,struct node* head3){
    struct node *temp1=head1, *temp2=head2, *temp3, *flag;
    temp3 = (struct node*)malloc(sizeof(struct node));
    head3 = temp3;
    while(temp1 && temp2){
        if(temp1->exp>temp2->exp){
            temp3->coeff = temp1->coeff;
            temp3->exp = temp1->exp;
            temp1 = temp1 ->next;
        }else if(temp1->exp<temp2->exp){
            temp3->coeff = temp2->coeff;
            temp3->exp = temp2->exp;
            temp2 = temp2 ->next;
        }else{
            temp3 ->coeff = temp1->coeff + temp2->coeff;
            temp3 ->exp = temp1->exp;
            temp1 = temp1->next,temp2 = temp2->next;
        }
        if(temp1 == NULL && temp2 ==NULL){

        }else{
        temp3->next = (struct node*)malloc(sizeof(struct node));
        temp3 = temp3->next;
        }
    }
    if(temp1 != NULL) 
        flag = temp1;
    if(temp2 != NULL)
        flag = temp2;
        while(flag){
            temp3 ->coeff = flag->coeff;
            temp3 ->exp = flag->exp;
            if(flag->next != NULL){
                temp3 ->next = (struct node*)malloc(sizeof(struct node));
                temp3 = temp3->next;
            }
            flag = flag->next;
        }
    temp3=NULL;
    return head3;
}

int main(){

    struct node *head1 = NULL, *head2 = NULL, *head3;
    int loop,i=0,j=0,coeff,exp;

    printf("How many terms are there in the first Polynomial: ");
    scanf("%d",&loop);
    while(i<loop){
        printf("Enter the coeffeicient of term %d: ",i+1);
        scanf("%d",&coeff);
        printf("Enter the exponent of term %d: ",i+1);
        scanf("%d",&exp);
        head1 = createPoly(head1,coeff,exp);
        i++;
    }

    printf("How many terms are there in the second Polynomial: ");
    scanf("%d",&loop);
    while(j<loop){
        printf("Enter the coeffeicient of term %d: ",j+1);
        scanf("%d",&coeff);
        printf("Enter the exponent of term %d: ",j+1);
        scanf("%d",&exp);
        head2 = createPoly(head2,coeff,exp);
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
