#include<stdio.h>
#include<stdbool.h>
#define size 5

void enq();
const char* deq();
void display();
bool isfull();
bool isempty();

char item[8];
int rear=size;
int front=-1;
int q[size];
int choice;

void main(){
while(1){
   printf("\n 1. enq 2. deq 3.Display 4. isFull 5. isEmpty");
   scanf("%d",&choice);
   switch(choice){
   case 1: enq();break;
   case 2: printf("%s",deq());break;
   case 4: if(isfull()){printf("\n Overflow");}break;
   case 3: display();break;
   case 5: if(isempty()){printf("\n Empty");} break;
   default: printf("Try Again");
   
}
}
}
bool isfull(){
  if(front>=rear-1){return true;}
  return false;
}
bool isempty(){
  if(front==-1 && rear==size)
      return true;
   return false;
}
void display(){
   if(isempty()){printf("Empty");return;}
   for(int i=front;i<=rear;i++){ printf("%d ",q[i]);}
   return;}

const char* deq(){
if(isempty()){return "Empty";}
else{
sprintf(item,"%d",q[front]);
front++;
return item;} 
}

void enq(){
   if(isfull()){printf("q overflow");return;}
   else{
   printf("Item????");
   rear++;
   scanf("%d",&q[rear]);
   printf("Item added");
   if(front==-1){front++;}
   }
   return;
}
