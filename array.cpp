#include<iostream>
#include<string>
using namespace std;

int main()
{
	int l, a[] = {1,2,3,4,5,6,7,8,9};
	int *p;
	p = a;
	for(int i=1;i<=9;i++)
	{
		cout<<*p;
		p++;
	}
	return 0;
}
