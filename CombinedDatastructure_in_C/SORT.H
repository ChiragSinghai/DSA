#include<stdio.h>
#include<conio.h>
#define MAX 30
void init_display(int a[],int n)
{
 int i;
 printf("unsorted list is :\n");
 for(i=0;i<n;i++)
 {
 printf("%d\t",a[i]);
 }
}

void final_display(int a[],int n)
{
 int i;
 printf("\nsorted list is :\n");
 for(i=0;i<n;i++)
 {
 printf("%d\t",a[i]);
 }
 printf("\npress any key to continue\n");
}

void bubble_sort(int arr[],int size)
{
 int i,j,temp;
 for(i=0;i<size-1;i++)
 {
  for(j=0;j<size-1-i;j++)
  {
   if(arr[j]>arr[j+1])
   {
    temp=arr[j];
    arr[j]=arr[j+1];
    arr[j+1]=temp;
   }
  }
 }
}
//quick sort



void quick(int arr[],int first,int last)
{
 int piv,temp,low,high;
 low=first;
 high=last;
 piv=arr[(first+last)/2];
 while(low<=high)
 {
 while(arr[low]<piv)
 low++;
 while(arr[high]>piv)
 high--;
 if(low<=high)
 {
 temp=arr[low];
 arr[low++]=arr[high];
 arr[high--]=temp;
 }
 }
 if(first<high)
 quick(arr,first,high);
 if(low<last)
 quick(arr,low,last);
 }

//  selection sort

void selection(int arr[],int n)
{
int i,smallest,k,tmp;
for(i=0;i<n-1;i++)
{
smallest=i;
for(k=i+1;k<n;k++)
{
if(arr[smallest]>arr[k])
smallest=k;
}
if(i!=smallest)
{
tmp=arr[i];
arr[i]=arr[smallest];
arr[smallest]=tmp;
}
}
}

//insertion sort

void insertion(int arr[],int n)
{
int j,k,i;
for(j=1;j<n;j++)
{
k=arr[j];
for(i=j-1;i>=0 && k<arr[i];i--)
{
arr[i+1]=arr[i];
}
arr[i+1]=k;
}
}

//shell sort

void shell(int arr[],int n,int incr)
{
int i,j,k;
 while(incr>=1)
 {
  for(j=incr;j<n;j++)
  {
   k=arr[j];
    for(i=j-incr;j>=0 && k<arr[i];i=i-incr)
    {
    arr[i+incr]=arr[i];
    }
    arr[i+incr]=k;
  }
    incr=incr-2;
 }
}


//merge sort
/*
void merge(int low,int mid,int high)
{
 int temp[MAX];
 int i=low;
 int j=mid+1;
 int k=low;
 while((i<=mid)&&(j<=high))
 {
  if(array[i]<=array[j])
  temp[k++]=array[i++];
  else
  temp[k++]=array[j++];
 }
 while(i<=mid)
  temp[k++]=array[i++];
  while(j<=high)
  temp[k++]=array[j++];

  for(i=low;i<=high;i++)
  {
  array[i]=temp[i];
  }
  }
  void merge_sort(int low,int high)
  {
  int  mid;
  if(low!=high)
  {
  mid=(low+high)/2;
  merge_sort(low,mid);
  merge_sort(mid+1,high);
  merge(low,mid,high);
  }
 }
*/

