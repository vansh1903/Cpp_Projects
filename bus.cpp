#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>

static int p = 1;

class BusRes
{
	private:
		char busn[5], driver[20], arrival[20], depart[20], from[20], to[20], seat[8][4][10];
	public:
		void install();
		void allotment();
		void empty();
		void show();
		void avail();
		void position();
}b[10];

void BusRes ::install()
{
	cout<<"Enter bus number:";
	gets(b[p].busn);
	cout<<"Enter driver's name:";
	gets(b[p].driver);
	cout<<"Enter arrival time:";
	gets(b[p].arrival);
	cout<<"Enter depart time:";
	gets(b[p].depart);
	cout<<"Enter from place:";
	gets(b[p].from);
	cout<<"Enter destination:";
	gets(b[p].to);
	b[p].empty();
	p++;
}

void BusRes ::allotment()
{
	int sno,n;
	char number[5];
	top:
	cout<<"Enter bus number:";
	gets(number);
	for(n=0;n<=p;n++)
	{
		if(strcmp(b[n].busn,number) == 0)
		{
			break;
		}
	}
	while(n<=9)
	{
		cout<<"Enter seat number:";
		cin>>sno;
		sno += 1;
		if(sno>=32)
		{
			cout<<"The bus has 32 seats";
		}
		else
		{

			if(strcmp(b[n].seat[sno/4][sno%4],"Empty")==0)
			{
				cout<<"Enter passenger's name:";
				cin>>b[n].seat[sno/4][sno%4];
			}
		}
	}
	if(n>p)
	{
		cout<<"Enter correct bus number";
		goto top;
	}
}

void BusRes :: empty()
{
	for(int i=0;i<8;i++)
	{
		for(int j=0;j<4;j++)
		{
			strcpy(b[p].seat[i][j],"Empty");
		}
	}
}

void BusRes :: show()
{
	char number[5];
	cout<<"Enter bus number:";
	gets(number);
	for(int n=0;n<=p;n++)
	{
		if(strcmp(b[n].busn,number)==0)
		{
			break;
		}
	}
	cout<<"Bus number:"<<b[n].busn;
	cout<<"\nDriver's name:"<<b[n].driver;
	cout<<"\nArrival time:"<<b[n].arrival;
	cout<<"\nDepart time:"<<b[n].depart;
	cout<<"\nFrom :"<<b[n].from;
	cout<<"\nDestination:"<<b[n].to;
	int count;
	for(int i=0;i<8;i++)
	{
		for(int j=0;j<4;j++)
		{
			if(strcmp(b[n].seat[i][j],"Empty")==0)
			{
				count++;
			}
		}
	}
	cout<<count<<"seats are vacant in the bus"<<b[n].busn;
}

void BusRes :: avail()
{
	for(int n=0;n<=p;n++)
	{
		cout<<"\tBus number:"<<b[n].busn;
		cout<<"\n\tDriver's name:"<<b[n].driver;
		cout<<"\n\tArrival time:"<<b[n].arrival;
		cout<<"\n\tDepart time:"<<b[n].depart;
		cout<<"\n\tFrom :"<<b[n].from;
		cout<<"\n\tDestination:"<<b[n].to;
		cout<<"---------------------------------------------------";

	}
}

int main()
{
	int c;
	do{
		clrscr();
		cout<<"\t---BUS RESERVATION SYSTEM---";
		cout<<"1.Insert\n2.Allotment\n3.Show\n4.Bus Available\n5.Exit";
		cout<<"Enter your choice:";
		cin>>c;
		switch(c)
		{
			case 1:b[p].install();
				break;

			case 2:b[p].allotment();
				break;

			case 3:b[p].show();
				break;

			case 4:b[p].avail();
				break;

			case 5:exit(0);

			default:cout<<"Enter correct choice";
		}
	}while(c<6);
	getch();
	return 0;
}
