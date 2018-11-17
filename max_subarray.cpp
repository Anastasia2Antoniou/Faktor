#include <iostream>
#include<climits>
using namespace std;

int max_subarray1(int a[], int n) {
	int max_f1 = INT_MIN;
	int max_h = 0;
	for(int i = 0;i<n;i++) {
		max_h = max_h+a[i];
		if(max_f1<max_h)
		max_f1 = max_h;
		if(max_h<0)
		max_h = 0;
	}
	return max_f1;
}
int max_subarray2(int a[], int n) {
	int max_f1 = a[0];
	int cur_max = a[0];
	for(int i=1;i<n;i++)
	{
		cur_max = max(a[i], cur_max+a[i]);
		max_f1 = max(max_f1, cur_max);
	}
	return max_f1;
}
int max_subarray3(int a[], int n) {
	int max_f1 = INT_MIN, max_h = 0, start = 0, end = 0, t = 0;
	for(int i=0; i<n; i++)
	{
		max_h += a[i];
		if(max_f1 < max_h)
		{
			max_f1 = max_h;
			start = t;
			end = i;
		}
		if(max_h <0)
		{
			max_h = 0;
			t = i+1;
		}
	}
	cout<<"Maximum contiguous sum is"<<max_f1<<endl;
	cout<<"Starting index"<<end<<endl;
}
int main() {
	int a[] = {2,6,-3,5,1,2,1,-2,6};
	int n = sizeof(a)/sizeof(a[0]);
	int max_sum = max_subarray1(a, n);
	cout<<"The sum of continuous subarray with thw maximum sum is:"<< max_sum;
	return 0;
   
}
