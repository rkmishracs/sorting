#include<stdio.h>
void input(int[],int);
void output(int[], int);
void merge_sort(int [], int, int);
void merge(int [], int, int,int);
int main()
{
  int a[20];
  int n;
  printf(" Enter the number of elements\n");
  scanf("%d",&n);
  printf(" Enter the Array Elements");
  input(a,n);
  printf(" Array Before Merge Sort\n");
  output(a,n);
  merge_sort(a,0,n-1);
  printf(" Array After Merge Sort\n");
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

void merge_sort(int a[], int start,int end)
{
  int mid=0;
  if(start<end)
  {
    mid=(start+end)/2;
    merge_sort(a,start,mid);
    merge_sort(a,mid+1,end);
    merge(a,start,mid,end);
  }
}

void merge(int *Arr, int start, int mid, int end)
{
	// create a temp array
	int temp[end - start + 1];

	// crawlers for both intervals and for temp
	int i = start, j = mid+1, k = 0;

	// traverse both arrays and in each iteration add smaller of both elements in temp
	while(i <= mid && j <= end) {
		if(Arr[i] <= Arr[j]) {
			temp[k] = Arr[i];
			k += 1; i += 1;
		}
		else {
			temp[k] = Arr[j];
			k += 1; j += 1;
		}
	}

	// add elements left in the first interval
	while(i <= mid) {
		temp[k] = Arr[i];
		k += 1; i += 1;
	}

	// add elements left in the second interval
	while(j <= end) {
		temp[k] = Arr[j];
		k += 1; j += 1;
	}

	// copy temp to original interval
	for(i = start; i <= end; i += 1) {
		Arr[i] = temp[i - start];
	}
}
