#include<iostream.h>
#include<conio.h>

int check_prime(int x)
{
	int check=1;
	for(int j=2;j<=x/2;j++)
	{
		if(x%j==0)
		{
			 check=0;
		}
	}
	return check;
}


void main()
{
	clrscr();
	int n,i,t=0;
	cout<<"Enter a positive number:";
	cin>>n;
	for(i=n/2;i>0;i--)
	{
		t = check_prime(i);
		if(t==0)
		{
			continue;
		}
		else
		{
			t = 0;
			t = check_prime(n-i);
			if(t==1)
			{
				cout<<n<<"="<<i<<"+"<<n-i<<endl;
			}
		}
	}
	getch();

}
