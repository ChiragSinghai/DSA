#include<stdio.h>
#include<malloc.h>
#define MAX 5
struct SL_Node
{
int info;
struct SL_Node *link;
}*start;
void SL_create_list(int  data)
{
struct SL_Node *q,*tmp;
tmp=malloc(sizeof(struct SL_Node));
tmp->info=data;
tmp->link=NULL;
if(start==NULL)
start=tmp;
else
{
q=start;
while(q->link!=NULL)
q=q->link;
q->link=tmp;
}
}
void SL_display()
{
struct SL_Node *q;
if(start==NULL)
{
 printf("list is empty\n");
 return;
}
q=start;
printf("list is\n");
while(q!=NULL)
{
printf("%d",q->info);
q=q->link;
printf("\n");
}
}
void SL_addatbeg(int data)
{
struct SL_Node *tmp;
tmp=malloc(sizeof(struct SL_Node));
tmp->info=data;
tmp->link=start;
start=tmp;
}

void SL_addafter(int data,int pos)
{
struct SL_Node *tmp,*q;
int i;
q=start;
for(i=0;i<pos-1;i++)
{
q=q->link;
if(q==NULL)
{
printf("there are less elements than %d elements\n ",pos);
return;
}
}
tmp=malloc(sizeof(struct SL_Node));
tmp->link=q->link;
tmp->info=data;
q->link=tmp;
}
void SL_del(int data)
{
struct SL_Node *tmp,*q;
if(start->info==data)
{
tmp=start;
start=start->link;
free(tmp);
return;
}
q=start;
while(q->link->link!=NULL)
{
if(q->link->info==data)
{
tmp=q->link;
q->link=tmp->link;
free(tmp);
return;
}
q=q->link;
}
if(q->link->info==data)
{
tmp=q->link;
free(tmp);
q->link=NULL;
return;
}
printf("element %d not found\n",data);
}
void SL_Add_at_end(int data)
{
 struct SL_Node *q=start,*tmp;
 tmp=malloc(sizeof(struct SL_Node));
 tmp->info=data;
 tmp->link=NULL;
 while(q->link!=NULL)
 q=q->link;
 q->link=tmp;
}
void SL_count()
{
struct SL_Node *q=start;
int cnt=0;
while(q!=NULL)
{
cnt++;
q=q->link;
}
printf("total element are %d\n",cnt);
}
void SL_rev()
{
struct SL_Node *p1,*p2,*p3;
if(start==NULL)
{
printf("empty\n");
return;
}
p1=start;
p2=p1->link;
p3=p2->link;
p1->link=NULL;
p2->link=p1;
while(p3!=NULL)
{
p1=p2;
p2=p3;
p3=p3->link;
p2->link=p1;
}
start=p2;
}
void SL_search(int data)
{
struct SL_Node *ptr=start;
int pos=1;
while(ptr!=NULL)
{
 if(ptr->info==data)
 {
 printf("%d found at %d position\n",data,pos);
 return;
 }
 ptr=ptr->link;
 pos++;
 }
if(ptr==NULL)
{
printf("item %d not found in list \n",data);
}
}

/*circular linked list */


struct SC_Node
{
int info;
struct SC_Node *link;
}*last;

void SC_create_list(int num)
{
struct SC_Node *q,*tmp;
tmp=malloc(sizeof(struct SC_Node));
tmp->info=num;
tmp->link=NULL;
if(last==NULL)
{
last=tmp;
tmp->link=last;
}
else
{
tmp->link=last->link;
last->link=tmp;
last=tmp;
}
}
void SC_addatbeg(int num)
{
struct SC_Node *tmp;
tmp=malloc(sizeof(struct SC_Node));
tmp->info=num;
tmp->link=last->link;
last->link=tmp;
}
void SC_addafter(int num,int pos)
{
struct SC_Node *q,*tmp;
int i;
q=last->link;
for(i=0;i<pos-1;i++)
{
q=q->link;
if(q==last->link)
{
printf("there are less than %d element\n",pos);
return;
}
}
tmp=malloc(sizeof(struct SC_Node));
tmp->info=num;
tmp->link=q->link;
q->link=tmp;
if(q==last)
last=tmp;
}
void SC_del(int num)
{
struct SC_Node *tmp,*q;
if(last->link==last&&last->info==num)
{
tmp=last;
last=NULL;
free(tmp);
return;
}
q=last->link;
if(q->info==num)
{
tmp=q;
last->link=q->link;
free(tmp);
return;
}
while(q->link!=last)
{
if(q->link->info==num)
{
tmp=q->link;
q->link=tmp->link;
free(tmp);
printf("%d deleted\n",num);
return;
}
q=q->link;
}
if(q->link->info==num)
{
tmp=q->link;
q->link=last->link;
free(tmp);
last=q;
return;
}
printf("element %d not found",num);
}
void SC_display()
{
struct SC_Node *q;
if(last==NULL)
{
printf("empty\n");
return;
}
q=last->link;
printf("list is \n");
while(q!=last)
{
printf("%d\n",q->info);
q=q->link;
}
printf("%d\n",last->info);
}

//double linked list

struct DL_Node
{
struct DL_Node *prev;
int info;
struct DL_Node *next;
}*Start;
void DL_create_list(int num)
{
struct DL_Node *q,*tmp;
tmp=malloc(sizeof(struct DL_Node));
tmp->info=num;
tmp->next=NULL;
if(Start==NULL)
{
tmp->prev=NULL;
Start=tmp;
}
else
{
q=Start;
while(q->next!=NULL)
q=q->next;
q->next=tmp;
tmp->prev=q;
}
}//end of create list

void DL_addatbeg(int num)
{
struct DL_Node *tmp;
tmp=malloc(sizeof(struct DL_Node));
tmp->prev=NULL;
tmp->info=num;
tmp->next=Start;
Start->prev=tmp;
Start=tmp;
}
//end of voidatbeg

void DL_addafter(int pos,int num)
{
struct DL_Node *q,*tmp;
int i;
q=Start;
for(i=0;i<pos-1;i++)
{
q=q->next;
if(q==NULL)
{
printf("lesser element than entered position\n");
return;
}
}
tmp=malloc(sizeof(struct DL_Node));
tmp->info=num;
q->next->prev=tmp;
tmp->next=q->next;
tmp->prev=q;
q->next=tmp;
}
//end of addafter
void DL_del(int num)
{
struct DL_Node *tmp,*q;
if(Start->info==num)
{
tmp=Start;
Start=Start->next;
Start->prev=NULL;
free(tmp);
return;
}
q=Start;
while(q->next->next!=NULL)
{
if(q->next->info==num)
{
tmp=q->next;
q->next=tmp->next;
tmp->next->prev=q;
free(tmp);
return;
}
q=q->next;
}
if(q->next->info==num)
{
tmp=q->next;
free(tmp);
q->next=NULL;
return;
}
printf("element %d not found\n",num);
}
//end of del
void DL_display()
{
struct DL_Node *q;
if(Start==NULL)
{
printf("list is empty\n");
return;
}
q=Start;
printf("list is\n");
while(q!=NULL)
{
printf("%d\n",q->info);
q=q->next;
}
}
//end of display
void DL_count()
{
struct DL_Node *q=Start;
int cnt=0;
while(q!=NULL)
{
q=q->next;
cnt++;
}
printf("no. of element are %d\n",cnt);
}
//end of count
void DL_rev()
{
struct DL_Node *p1,*p2;
p1=Start;
p2=p1->next;
p1->prev=p2;
p1->next=NULL;
while(p2!=NULL)
{
p2->prev=p2->next;
p2->next=p1;
p1=p2;
p2=p2->prev;
}
Start=p1;
}
//end of double linked list

//queue


struct Q_node
{
 int info;
 struct Q_node *link;
}*front,*rear;
void Q_insert(int data)
{
struct Q_node *tmp;
tmp=malloc(sizeof(struct Q_node));
tmp->info=data;
tmp->link=NULL;
if(front==NULL)
{
front=tmp;
}
else
{
rear->link=tmp;
}
rear=tmp;
}
void Q_del()
{
if(front==NULL)
{
printf("queue underflow\n");
}
else
{
struct Q_node *tmp;
tmp=front;
//printf("deleted element is %d\n",tmp->info);
front=front->link;
free(tmp);
}
}
void Q_display()
{
if(front==NULL)
{
printf("list is empty\n");
}
else
{
struct Q_node *q=front;
while(q!=NULL)
{
printf("%d\n",q->info);
q=q->link;
}                             //end of while
}                //end of else
}//end of display

//start of stack
struct S_Node
{
 int info;
 struct S_Node *link;
}*start1;
void push(int data)
{
struct S_Node *tmp;
tmp=malloc(sizeof(struct S_Node));
tmp->info=data;
tmp->link=start1;
start1=tmp;
}
void pop()
{
 struct S_Node *q;
 q=start1;
 start1=start1->link;
 free(q);
}
void display()
{
struct S_Node *q;
q=start1;
if(q==NULL)
{
printf("stack is empty\n");
}
else
{
while(q!=NULL)
{
printf("%d\n",q->info);
q=q->link;
}
}                             //end of while
}             //end of display
//end of stack

//priority queue
struct QP_Node
{
 int priority;
 int info;
 struct QP_Node *link;
}*Front;
void  PQ_insert(int item,int priority)
{
 struct QP_Node *tmp,*q;
 tmp=(struct QP_Node*)malloc(sizeof(struct QP_Node));
 tmp->info=item;
 tmp->priority=priority;
 if(Front==NULL||priority<Front->priority)
 {
  tmp->link=Front;
  Front=tmp;
 }
 else
 {
  q=Front;
  while(q->link!=NULL&& q->link->priority<=priority)
  {
   q=q->link;
  }
 tmp->link=q->link;
 q->link=tmp;
 }
}
//end of insert
void PQ_del()
{
 struct QP_Node *tmp;
 if(Front==NULL)
 {
  printf("queue is underflow\n");
 }
 else
 {
  tmp=Front;
  printf("deleted element is %d\n",tmp->info);
  Front=Front->link;
  free(tmp);
 }
}
//end of del in priority queue

void PQ_display()
{
 struct QP_Node *ptr;
 ptr=Front;
 if(Front==NULL)
 {
  printf("queue is empty:\n");
 }
 else
 {
  printf("queue is \n");
  printf("priority   item\n");
  while(ptr!=NULL)
  {
   printf("%5d    %5d\n",ptr->priority,ptr->info);
   ptr=ptr->link;
  }
 }
}

