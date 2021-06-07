#include<iostream.h>
#include<stdio.h>

int main()
{
	int age;
	char name[50];
	cout<<"Enter name:";
	gets(name);
	cout<<"Enter age:";
	cin>>age;
	
	if(age>=18)
	{
		cout<<name<<" is eligible to vote";
	}
	else
	{
		cout<<name<<" is not elibile to vote";
	}
	return 0;
}
