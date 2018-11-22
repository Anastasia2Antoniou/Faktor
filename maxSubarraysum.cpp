#include<iostream>
using namespace std;

void max_subarray1(int a[], int n)
{
    int max_f=0;
    int max_h=0;
    int start=0;
    int end=0;
    int beg=0;

    for(int i=0;i<n;i++)
    {
        max_h=max_h + a[i];
        if(max_h <0)
        {
            max_h=0;
            beg=i+1;
        }
        if(max_f < max_h)
        {
            max_f=max_h;
            start=beg;
            end=i;
        }
           
    }
    cout<<"The sum of continuous subarray with the largest sum is"<<max_f<<endl;
    cout<<"The continuous subarray with the largest sum is";
    for(int i=start;i<=end;i++)
    cout<<a[i]<<"";
}
int max(int a, int b) { return (a > b)? a : b; } 
int max(int a, int b, int c) { return max(max(a, b), c); } 

int maxCrossingSum(int arr[], int l, int m, int h) 
{ 
    int sum = 0; 
    int left_sum = INT_MIN; 
    for (int i = m; i >= l; i--) 
    { 
        sum = sum + arr[i]; 
        if (sum > left_sum) 
          left_sum = sum; 
    } 
   
    sum = 0; 
    int right_sum = INT_MIN; 
    for (int i = m+1; i <= h; i++) 
    { 
        sum = sum + arr[i]; 
        if (sum > right_sum) 
          right_sum = sum; 
    } 
  
    return left_sum + right_sum; 
} 
  
int max_subarray2(int a[], int l, int h)
{
    if(l == h)
    return a[l];
    int m = (l + h)/2;
    return max(max_subarray2(a, l, m),
           max_subarray2(a, m+1, h),
           maxCrossingSum(a, l, m, h));
}
void max_subarray3(int a[], int n)
{
    cin>>n;
    for(int i=0;i<n;i++)
    cin>>a[i];
    long long max_ans;
    max_ans=a[0];
    for(int i=0;i<n;i++)
    {
        long long result=0;
        for(int j=0;j<n;j++)
        {
            result +=a[i];
            max_ans=max(max_ans, result);
        }
    }
    cout<<max_ans;
}
int main()
{
    int a[]={2,6,-3,5,1,2,1,-2,6};
    int n = sizeof(a)/sizeof(a[0]);
    int max_sum = max_subarray2(a, 0, n-1); 
    cout<<"Maximum contiguous sum is %dn"<<max_sum<<endl;
    max_subarray1(a, n);
    return 0;
}