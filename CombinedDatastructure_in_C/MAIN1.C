#include<sort.h>
void main()
{
int choice,i,n,incr,j,arr[MAX];
clrscr();
do
{
clrscr();
label:
printf("1.insert in array\n");
printf("2.bubble sort\n");
printf("3.selection sort\n");
printf("4.insertion sort\n");
printf("5.shell sort\n");
printf("6.quick sort\n");
printf("7merge sort\n");
printf("8.exit\n");
printf("enter your choice:");
scanf("%d",&choice);
switch(choice)
{
case 1:
printf("enter the no. of element");
scanf("%d",&n);
for(i=0;i<n;i++)
{
printf("enter element %d : ",i+1);
scanf("%d",&arr[i]);
}
break;

case 2:
clrscr();
init_display(arr,n);
bubble_sort(arr,n);
final_display(arr,n);
getch();
break;

case 3:
clrscr();
init_display(arr,n);
selection(arr,n);
final_display(arr,n);
getch();
break;

case 4:
clrscr();
init_display(arr,n);
insertion(arr,n);
final_display(arr,n);
getch();
break;


case 5:
clrscr();
init_display(arr,n);
shell(arr,n,n/2);
final_display(arr,n);
getch();
break;

case 6:
clrscr();
init_display(arr,n);
quick(arr,0,n-1);
final_display(arr,n);
getch();
break;

/*case 7:
merge_sort(0,n-1);
break;
*/
case 8:
break;

default:
clrscr();
printf("invalid input\n");
goto label;
}
}while(choice!=8);
}
