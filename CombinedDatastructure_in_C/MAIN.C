//#include<sort.h>
#include<linked.h>
void main()
{
int c1,choice,n,m,pos,i,p,item,top,priority;
clrscr();
 while(1)
 {

 clrscr();
 menu:

 printf("1.single linked list\n");
 printf("2.double linked list\n");
 printf("3.circular linked list\n");
 printf("4.stack\n");
 printf("5.queue\n");
 printf("6.priority queue\n");
 printf("7.exit\n");
 printf("enter your choice:");
 scanf("%d",&c1);
 switch(c1)
 {
 case 1:
 clrscr();
 start=NULL;
 do
 {
  menu1:
  printf("1.Create list\n");
  printf("2.Add at beginning\n");
  printf("3.Addafter\n");
  printf("4.Add at last\n");
  printf("5.Delete\n");
  printf("6.Display\n");
  printf("7.Count\n");
  printf("8.Reverse \n");
  printf("9.Search\n");
  printf("10.exit\n");
  printf("enter your choice:");
  scanf("%d",&choice);
switch(choice)
{
case 1:
start=NULL;
clrscr();
printf("how many nodes you want:");
scanf("%d",&n);
for(i=0;i<n;i++)
{
printf("enter the element:");
scanf("%d",&m);
SL_create_list(m);
}
clrscr();
break;

case 2:
clrscr();
printf("enter your data you want to input atbegining:");
scanf("%d",&m);
SL_addatbeg(m);
clrscr();
break;

case 3:
clrscr();
printf("enter the position after which you want to enter:");
scanf("%d",&pos);
printf("enter the element or data:");
scanf("%d",&m);
SL_addafter(m,pos);
break;

case 4:
clrscr();
printf("enter element:");
scanf("%d",&m);
SL_Add_at_end(m);
clrscr();
break;

case 5:
clrscr();
printf("enter the data/element:");
scanf("%d",&m);
SL_del(m);
break;

case 6:
clrscr();
SL_display();
break;

case 7:
clrscr();
SL_count();
break;

case 8:
clrscr();
SL_rev();
break;

case 9:
clrscr();
printf("enter the data to be searched:");
scanf("%d",&m);
SL_search(m);
break;

case 10:
break;

default:
clrscr();
printf("invalid input\n");
goto menu1;
}
}while(choice!=10);
break;


case 2:
clrscr();
Start=NULL;
do
{
menu2:
printf("1.create list\n");
printf("2.add at begining\n");
printf("3.add after\n");
printf("4.delete \n");
printf("5.display\n");
printf("6.count\n");
printf("7.reverse\n");
printf("8.exit\n");
printf("enter your choice:");
scanf("%d",&choice);
switch(choice)
{
case 1:
Start=NULL;
clrscr();
printf("how many nodes you want:");
scanf("%d",&n);
for(i=0;i<n;i++)
{
printf("enter the element:");
scanf("%d",&m);
DL_create_list(m);
}
break;

case 2:
clrscr();
printf("enter the element:");
scanf("%d",&m);
DL_addatbeg(m);
break;

case 3:
clrscr();
printf("enter the position after which you want to enter element:");
scanf("%d",&pos);
printf("enter the element:");
scanf("%d",&m);
DL_addafter(pos,m);
break;

case 4:
clrscr();
printf("enter the element you want to delete:");
scanf("%d",&m);
DL_del(m);
break;

case 5:
clrscr();
DL_display();
break;

case 6:
clrscr();
DL_count();
break;

case 7:
clrscr();
DL_rev();
break;

case 8:
break;

default:
clrscr();
printf(" invalid input\n");
goto menu2;
}
}while(choice!=8);
break;

case 3:
clrscr();
last=NULL;
do
{
menu3:
printf("1.create_list\n");
printf("2.addatbeg\n");
printf("3.addafter\n");
printf("4.delete\n");
printf("5.display\n");
printf("6.exit\n");
printf("enter your choice:");
scanf("%d",&choice);
switch(choice)
{
case 1:
last=NULL;
clrscr();
printf("how many node you want:");
scanf("%d",&n);
for(i=0;i<n;i++)
{
printf("enter the element:");
scanf("%d",&m);
SC_create_list(m);
}
break;

case 2:
clrscr();
printf("enter the element:");
scanf("%d",&m);
SC_addatbeg(m);
break;

case 3:
clrscr();
printf("enter position of element you want to enter:");
scanf("%d",&p);
printf("enter the element:");
scanf("%d",&m);
SC_addafter(m,p);
break;

case 4:
clrscr();
if(last==NULL)
{
printf("list underflow\n");
continue;
}
printf("enter the no. or element you want to delete:");
scanf("%d",&m);
SC_del(m);
break;
case 5:
clrscr();
SC_display();
break;
case 6:
break;

default:
clrscr();
printf("invalid input\n");
goto menu3;
}
}while(choice!=6);
break;



case 4:
start1=NULL;
clrscr();
do
{
menu4:
printf("1.push\n");
printf("2.pop\n");
printf("3.display\n");
printf("4.new stack\n");
printf("5.exit\n");
printf("enter your choice:");
scanf("%d",&choice);
switch(choice)
{
case 1:
clrscr();
printf("input the new value to be pushed on stack:");
scanf("%d",&item);
push(item);
break;

case 2:
clrscr();
pop();
break;

case 3:
clrscr();
display();
break;

case 4:
clrscr();
start1=NULL;
break;

case 5:
break;
default:
clrscr();
printf("invalid choice\n");
goto menu4;
}
}while(choice!=5);
break;

case 5:
clrscr();
front=NULL,rear=NULL;
do
{
 menu5:
 printf("1.insert\n");
 printf("2.delete\n");
 printf("3.display\n");
 printf("4.new queue\n");
 printf("5.quit\n");
 printf("enter your choice:");
 scanf("%d",&choice);
 switch(choice)
 {
  case 1:
  clrscr();
  printf("input the element for adding in queue:");
  scanf("%d",&item);
  Q_insert(item);
  break;

  case 2:
  clrscr();
  Q_del();
  break;

  case 3:
  clrscr();
  Q_display();
  break;

  case 4:
  clrscr();
  front=NULL;
  break;


  case 5:
  break;
  default:
  clrscr();
  printf("invalid input\n");
  goto menu5;
  }
  }while(choice!=5);
  break;

  case 6:
  clrscr();
  do
 {
  menu6:
  printf("1.insert\n");
  printf("2.delete\n");
  printf("3.display\n");
  printf("4.new queue\n");
  printf("5.quit\n");
  printf("enter your choice:");
  scanf("%d",&choice);
  switch(choice)
  {
   case 1:
   clrscr();
   printf("Input the item value to be added in the queue:");
   scanf("%d",&item);
   printf("enter the priority:");
   scanf("%d",&priority);
   PQ_insert(item,priority);
   break;

   case 2:
   clrscr();
   PQ_del();
   break;

   case 3:
   clrscr();
   PQ_display();
   break;

   case 4:
   clrscr();
   Front=NULL;
   break;

   case 5:
   break;

   default:
   clrscr();
   printf("invalid input\n");
   goto menu6;
  }
 }while(choice!=5);
 break;

case 7:
exit();
default:
clrscr();
printf("invalid input\n");
goto menu;
}
}
}