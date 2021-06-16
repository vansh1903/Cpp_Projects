#include<iostream.h>
#include<conio.h>

class time
{
	private:
	    float hour,min,sec;

	public:
	     void insert();
	     void display();
	     int seconds();
};
void time :: insert()
{
	cout<<"Enter \nhours:";
	cin>>hour;
	cout<<"Minutes:";
	cin>>min;
	cout<<"Seconds:";
	cin>>sec;
}
void time :: display()
{
	if(hour<10 && min<10 && sec<10)
	{
		cout<<"0"<<hour<<":0"<<min<<":0"<<sec;
	}
	else if(hour<10 && min<=60 && sec<10)
	{
		cout<<"0"<<hour<<":"<<min<<":0"<<sec;
	}
	else if(hour<10 && min<10 && sec<=60)
	{
		cout<<"0"<<hour<<":0"<<min<<":"<<sec;
	}
	else if(hour<10 && min<=60 && sec<=60)
	{
		cout<<"0"<<hour<<":"<<min<<":"<<sec;
	}
	else if(hour<=12 && min<10 && sec<10)
	{
		cout<<hour<<":0"<<min<<":0"<<sec;
	}
	else if(hour<=12 && min<10 && sec<=60)
	{
		cout<<hour<<":0"<<min<<":"<<sec;
	}
	else if(hour<=12 && min<=60 && sec<10)
	{
		cout<<hour<<":"<<min<<":0"<<sec;
	}
	else if(hour<=12 && min<=60 && sec<=60)
	{
		cout<<hour<<":"<<min<<":"<<sec;
	}
	else
	{
		cout<<"Entered time is wrong";
	}
}
int time :: seconds()
{
	if(hour<=12 && min<=60 && sec<=60)
	{
		float h,m,t;
		t = sec+(hour*3600)+min*60;
		cout<<"\nTotal seconds are "<<t;
	}
	else
	{
		cout<<"\nEntered time is wrong";
	}
	return 0;
}

void main()
{
	clrscr();

	time t1;

	t1.insert();
	t1.display();
	t1.seconds();

	getch();
}


