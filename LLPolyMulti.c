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
        (temp->coeff>0) ? printf("+%dX^%d ",temp->coeff,temp->exp) : printf("%dX^%d ",temp->coeff,temp->exp);
        temp = temp->next;
    }
}

struct node* polyMulti(struct node *head,int coeff, int exp){
    struct node *temp,*flag;

    if(head == NULL){
        temp = (struct node*) malloc (sizeof(struct node));
        temp->coeff = coeff;
        temp->exp = exp;
        temp->next = NULL;
        head = temp;
    }else{
        temp = head;
        while (temp->next!=NULL){
            if(temp->exp == exp){
                temp->coeff = temp->coeff + coeff;
                return head;
            }else{
                temp = temp->next;
            }
        }
            flag = (struct node*)malloc(sizeof(struct node));
            flag->coeff = coeff;
            flag->exp = exp;
            flag->next = NULL;
            temp->next = flag;
    }return head;
}

struct node* polyArrange(struct node*head){
    struct node *temp=head,*flag;
    while (temp->next !=NULL){
        if(temp->exp == temp->next->exp){
            temp->coeff = temp->coeff+temp->next->coeff;
            flag = temp->next;
            temp->next = temp->next->next;
            free(flag);
        }
        else{
            temp = temp->next;
        }
    }
    return head;
}

int main(){

    struct node *head1 = NULL, *head2 = NULL, *head3 = NULL;
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

    if(head1 != NULL && head2 != NULL){
        int rcoeff, rexp;
        struct node *temp1=head1, *temp2=head2;
        while(temp1 != NULL){
            temp2 = head2;
            while (temp2 != NULL){
                rcoeff = temp1->coeff * temp2->coeff;
                rexp = temp1->exp + temp2->exp;
                head3 = polyMulti(head3,rcoeff,rexp);
                temp2 = temp2->next;
            }temp1 = temp1->next;
        }
    }
    head3 = polyArrange(head3);
    if(head3 != NULL){
        printf("\nPolynomial after multiplying Polynomial 1 & Polynomial 2\n");
        display(head3);
    }
    return 0;
}