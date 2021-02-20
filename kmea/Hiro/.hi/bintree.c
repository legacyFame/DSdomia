/**Binary Tree*/

#include<stdio.h>
#include<malloc.h>
struct node
 {
 int data;
 struct node *lc,*rc;
 };

 int  option;
 struct node *root=NULL;
 int flag,l=0,fl=0;
 void insert(struct node *);
 void in(struct node *);
 void post(struct node *);
 void pre(struct node *);
 void search(struct node *,int);
void deltree(struct node *,int);
struct node * searchparent(struct node *,int);
 
void main()
 {
 int a;
 int item;
 root=(struct node*)malloc(sizeof(struct node));
 printf("\nEnter the data=");
 scanf("%d",&root->data);
 root->lc=NULL;
 root->rc=NULL;

 printf("Do you want to enter more nodes? Press 1 for yes\n");
 scanf("%d",&option);
 if(option==1)
 {
 insert(root);
 }

 while(1)
 {
 printf("\nEnter choice\n");
 printf("  1.inorder-preorder-postorder\n 2.Search\n 3.Delete\n  0.exit\n");
 scanf("%d",&a);

 switch(a)
 {

  case 1:{
	  printf("\ninorder=");
	  in(root);
	  printf("\npreorder=");
	  pre(root);
	  printf("\npostorder=");
	  post(root);
	  break;
	  }
 case 2:{
	   printf("\nenter the data to be searched=");
	   scanf("%d",&item);
	   flag=0;
	   search(root,item);
	   if(flag==1)
		puts("\nSearch succesfull\n");
	   else
		puts("\n\tSearch unsuccesfull\n");
		   break;
	  }
 case 3:{
	    printf("\n\n Enter the data to be deleted : ");
	   scanf("%d",&item);
	   deltree(root,item);
	   break;
	  }
 // case 0: exit(0);
 default:puts("\n\nInvalid\n\n");
 }//switch
 }//while

 }//main

 void insert(struct node *ptr)
 {
 struct node *lnewn,*rnewn;
 if(ptr!=NULL)
 {
 printf("Do you want to enter a left child to %d? Enter option=1/0",ptr->data);
 scanf("%d",&option);
 if(option==1)
 {
 lnewn=(struct node*)malloc(sizeof(struct node));
 printf("\nEnter the data=");
 scanf("%d",&lnewn->data);
 ptr->lc=lnewn;
 //ptr->rc=NULL;
 lnewn->lc=NULL;
 lnewn->rc=NULL;
 insert(lnewn);
 }
 else
 {
 lnewn=NULL;
 insert(lnewn);
 }

 printf("Do you want to enter a right child to %d? Enter option=1/0",ptr->data);
 scanf("%d",&option);
 if(option==1)
 {
 rnewn=(struct node*)malloc(sizeof(struct node));
 printf("\nEnter the data=");
 scanf("%d",&rnewn->data);
 ptr->rc=rnewn;
 rnewn->lc=NULL;
 rnewn->rc=NULL;
 insert(rnewn);
 }
 else
 {
 rnewn=NULL;
 insert(rnewn);
 }
 }
 }//insert


void in(struct node *w)
 {
 if(w!=NULL)
	{
	in(w->lc);
	printf("  %d",w->data);
	in(w->rc);
	}
 }

void post(struct node *w)
 {
 if(w!=NULL)
	{
	post(w->lc);
	post(w->rc);
	printf("  %d",w->data);
	}
 }

void pre(struct node *w)
 {
 if(w!=NULL)
	{
	printf("  %d",w->data);
	pre(w->lc);
	pre(w->rc);
	}
 }

 void search(struct node *tmp,int item)
 {
 if(tmp!=NULL)
	{search(tmp->lc,item);
	if(tmp->data==item)
		flag=1;
	search(tmp->rc,item);
	}
 }

 struct node* searchparent(struct node *ptr,int item)
  {
	struct node * parent,*ptr1,*ptr2;
printf("\n\n\nptr=%d, parent=%d",ptr->data,parent->data);
   parent=ptr;
 printf("\nparent in searchparent=%d",parent->data);
   if(ptr->data!=item)
     {
     ptr1=ptr->lc;
	printf("\n ptr1=%d",ptr1->data);
     ptr2=ptr->rc;
     if(ptr1!=NULL)
	 {
	printf("\nparent in searchparent in ptr1 before recursion=%d" ,parent->data);
	parent=searchparent(ptr1,item);
	//parent=ptr;
	//searchparent(ptr1,item);
	printf("\nParent in ptr1 after recursion=%d ", parent->data);
	}
      else parent=NULL;

     if(ptr2!=NULL)
       {
	parent=searchparent(ptr2,item);
	//searchparent(ptr2,item);
	printf("\nParent in ptr2=%d",parent->data);
       }
     else
	parent=NULL;
     
     }//if
   else
      {printf("\nParent before return%d",parent->data);
	return parent; 

      }
// newly added
//return ptr;
  }//function


 void deltree(struct node *ptr,int item)
 {
 struct node *tmp,*parent,*ptr1,*ptr2;
printf("root=%d",ptr->data);
 if(ptr==NULL)
	{
	printf("Tree is Empty");
	return;
	}
else
 parent=searchparent(ptr,item);

 printf("parent in deltree=%d",parent->data);
 if(parent!=NULL)
   {
   ptr1=parent->lc;
   ptr2=parent->rc;
   if(ptr1->data==item)
     {
     if((ptr1->lc==NULL)&&(ptr1->rc==NULL))
	 parent->lc=NULL;
     else
	printf("\nNode is not a leaf node: No deletion");
     }
   else
     {
     if((ptr2->lc==NULL)&&(ptr2->rc==NULL))
	parent->rc=NULL;
     else
       printf("\nNode is not a leaf node. No deletion");

     }
   }
  else
   printf("\nNode with data %d does not exist. No deletion",item);
 }
