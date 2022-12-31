#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define size 40
char array[size];
char stack[size];
char evaluate[size];
int number[size];
int TOS = -1,i=0,j=0;

void Push(char X){
  if (TOS < size - 1) {
    TOS++;
    stack[TOS] = X;
  }
}

char Pop(){
  if(TOS != -1){
      return stack[TOS--];
  }
  return '\0';
}

char ReadSymbol(char array[]){
  if(array[i]){
    char symbol = array[i];
    i++;
    return symbol;
  }
  return '\0';
}

void Output(char x){
  if (j > 0 && isdigit(evaluate[j - 1])) {
    printf("");
  }
  printf(" %c", x);
}

int isoperand(char x){
  if(isalnum(x)){
    return 1;
  }else {
    return 0;
  }
}

int ISP(char x){
  switch(x){
    case '+' :
      return 2;
    case '-' :
      return 2;
    case '*' :
      return 4;
    case '/':
      return 4;
    case '^':
      return 5;
    case '(':
      return 0;
    case ')':
      return 0;
    default :
      return 8;
  }
}

int ICP(char x){
  switch(x){
    case '+' :
      return 1;
    case '-' :
      return 1;
    case '*' :
      return 3;
    case '/':
      return 3;
    case '^':
      return 6;
    case '(':
      return 9;
    case ')':
      return 0;
    default :
      return 7;
  }
}

int Result(int y, int x, char op){
  switch (op)
  {
  case '+':
    return y + x;
  case '-':
    return y - x;
  case '*':
    return y * x;
  case '/':
    return (int) y / x;
  case '^':
    return pow(y,x);
  default:
    break;
  }
}

void main(){
  printf("Enter an expression to evaluate: ");
  scanf("%s",array);
  TOS = 1;
  printf("Postfix Expression: ");
  if(isoperand(array[i])){
    Push('(');
  }else{
    Push(array[i]);
  }
  while(TOS>=0){
    char item = ReadSymbol(array);
    if (item == '\0') { 
      break;
    }
    char x = Pop();
    int operand = isoperand(item); //returns true or false, used to check if the item is an operand or not
    if(operand){
      Push(x);
      Output(item);
      evaluate[j] = item;
      j++;
    }else if(item == ')'){
      while(x != '('){
        Output(x);
        evaluate[j] = x;
        j++;
        x = Pop();
      }
    }else if(!isoperand(x) && ISP(x) >= ICP(item)){
      while (ISP(x) >= ICP(item)){
        Output(x);
        evaluate[j] = x;
        j++;
        x = Pop();
      }
      Push(x);
      Push(item);
    }
    else if(ISP(x) < ICP(item)){
      Push(x);
      Push(item);
    }else{
      printf("Invalid expression");
    }
  }
  while(TOS > 0){
    char x = Pop();
    if(x != '('){
      Output(x);
      evaluate[j] = x;
      j++;
    }
  }
  printf("\n");


  //Computing the value of the expression
  char endchar = '#';
  strncat(evaluate , &endchar, 1); //used to determine the end of the array while computing the value
  i = 0; //used to reuse ReadSymbol();
  TOS = -1; //used to resue stack
  char item = ReadSymbol(evaluate);
  while (item != '#'){
    int operand = isoperand(item);
    if(operand){
      item = item - '0'; //used to convert from string to int
      Push(item);
    }else{
      char op = item;
      int y = Pop();
      int x = Pop();
      int t = Result(x,y,op);
      Push(t);
    }
    item = ReadSymbol(evaluate);
  }
  int value = Pop();
  printf("Evaluating the expression, we get %d", value);

}

