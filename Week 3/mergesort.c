#include<stdio.h>
#include<time.h>
int a[20],n;
void merge(int[],int,int,int);
void mergesort(int[],int,int);

int main() {

clock_t start,end;
double time_taken;
printf("Enter the no of elements:");
scanf("%d",&n);
printf("Enter the array elements:");
for(int i = 0;i < n;i++) {
    scanf("%d",&a[i]);
}
start = clock();
mergesort(a,0,n-1);
end = clock();
time_taken = (double)(end-start)/CLOCKS_PER_SEC;
printf("\nSorted elements:");
for(int i=0;i<n;i++) {
    printf("%d\t",a[i]);
}
printf("\nTime taken to sort:%f",time_taken);
return 0;
}

void mergesort(int a[],int low,int high) {
    if(low<high) {
    int mid = (low+high)/2;
    mergesort(a,low,mid);
    mergesort(a,mid+1,high);
    merge(a,low,mid,high);
}
}

void merge(int a[],int low,int mid ,int high) {
int i=low,j=mid+1,k=0;
int c[high-low+1];
while(i<=mid && j<=high) {
    if(a[i] < a[j]) {
        c[k++] = a[i++];
    } else {
    c[k++] = a[j++];
    }
 }   while(i <= mid){
        c[k++] = a[i++];
    }
    while(j <= high) {
        c[k++] = a[j++];
    }
    for(i=low,k=0;i<=high;i++,k++) {
        a[i]=c[k];
    }
}





