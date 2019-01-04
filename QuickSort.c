#include<stdio.h>
void input(int[],int);
void output(int[], int);
void quick_sort(int [], int, int);
int main()
{
  int a[20];
  int n;
  printf(" Enter the number of elements\n");
  scanf("%d",&n);
  printf(" Enter the Array Elements");
  input(a,n);
  printf(" Array Before Quick Sort\n");
  output(a,n);
  quick_sort(a,0,n-1);
  printf(" Array After Quick Sort\n");
  output(a,n);
}
void input(int a[],int n)
{
  for(int i=0;i<n;i++)
  scanf("%d",&a[i]);
}

void output(int a[],int n)
{
  for(int i=0;i<n;i++)
  printf("%d\n",a[i]);
}

void quick_sort(int a[], int beg,int end)
{
  int i,j,pivot, temp;
  int left, right;
  left=beg;
  right=end;
  pivot=a[(beg+end)/2];

  do {

      while(a[left]<pivot)
      {
        left++;
      }
      while(a[right]>pivot)
      {
        right--;
      }
if(left<=right)
{
  temp=a[left];
  a[left++]=a[right];
  a[right--]=temp;
}


  } while(left<=right);

  if(beg<right)
   quick_sort(a,beg,right);
   if(left<=end)
   quick_sort(a,left,end);
}
