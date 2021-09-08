//****************************************************************
//                   HEADER FILE USED IN PROJECT
//****************************************************************
#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<process.h>
#include<string.h>
#include<iomanip.h>
//****************************************************************
//                   CLASS USED IN PROJECT
//****************************************************************
void box();
void intro();
class book
{
	char bno[6];
	char aname[50];
  protected:
	char bname[50];
  public:
    void create_book()
    {

	box();
	gotoxy(30,3);
	cout<<"...NEW BOOK ENTRY...";
	gotoxy(3,4);
	cout<<"Enter The book number(10**): ";
	cin>>bno;
	gotoxy(3,5);
	cout<<"Enter The Name of The Book: ";
	gets(bname);
	gotoxy(3,6);
	cout<<"Enter The Author's Name: ";
	gets(aname);
	gotoxy(3,7);
	cout<<"Book Created...";
    }

    void show_book(int n)
    {
	gotoxy(3,n);
	n++;
	cout<<"Book Number(10**) : "<<bno;
	gotoxy(3,n);
	n++;
	cout<<"Book Name : ";
	puts(bname);
	gotoxy(3,n);
	cout<<"Author Name : ";
	puts(aname);
    }

    void modify_book(int i)
    {
	gotoxy(3,i);
	i++;
	cout<<"Book Number(10**) : "<<bno;
	gotoxy(3,i);
	i++;
	cout<<"Modify Book Name : ";
	gets(bname);
	gotoxy(3,i);
	cout<<"Modify Author's Name of Book : ";
	gets(aname);
    }

    char* retbno()
    {
	return bno;
    }

/*    void report()
    {
	cout<<bno<<setw(30)<<bname<<setw(30)<<aname<<endl;
    }*/
    void report(int y)
    {
	gotoxy(3,y);
	cout<<setw(6)<<bno<<setw(35)<<bname<<setw(30)<<aname<<endl;
    }



}bk;         //class book ends here
class student
{
	int admno;
	char name[20];
	char stbno[6];
	int token;

	public:

	void create_student(int ano)
	{
		clrscr();
		box();
		admno=ano;
		gotoxy(29,3);
		cout<<"...NEW STUDENT ENTRY...";
		gotoxy(3,4);
		cout<<"Enter The Admission number(50**): "<<admno;
		gotoxy(3,5);
		cout<<"Enter The Name of The Student: ";
		gets(name);
		token=0;
		stbno[0]='\0';
		gotoxy(3,7);
		cout<<"Student Record Created..";
	}
	void show_student(int j)
	{
		gotoxy(3,j);
		j++;
		cout<<"Admission Number(50**): "<<admno;
		gotoxy(3,j);
		j++;
		cout<<"Student Name: ";
		puts(name);
		gotoxy(3,j);
		j++;
		cout<<"Number of Book issue: "<<token;
		if(token==1)
		{
			gotoxy(3,j);
			cout<<"Book Number(10**): "<<stbno;
		}
	}
	void modify_student(int k)
	{
		gotoxy(3,k);
		k++;
		cout<<"Admission number(50**) : "<<admno;
		gotoxy(3,k);
		cout<<"Modify Student Name : ";
		gets(name);
	}

	int retadmno()
	{
		return admno;
	}
	char* retstbno()
	{
		return stbno;
	}
	int rettoken()
	{
		return token;
	}

	void addtoken()
	{
		token=1;
	}

	void resettoken()
	{
		token=0;
	}

	void getstbno(char t[])
	{
		strcpy(stbno,t);
	}

	void report()
	{
		cout<<setw(8)<<admno<<setw(20)<<name<<setw(10)<<token<<endl;
	}
	void rep()
	{
		cout<<setw(8)<<admno<<setw(35)<<name<<setw(27)<<token<<endl;
	}
}st;         //class Student ends here
//****************************************************************
//        global declaration for stream objects
//****************************************************************
fstream fp,fp1;
//****************************************************************
//        functions to write in file
//****************************************************************

void write_book()
{
	box();
	char ch;
	fp.open("book.dat",ios::out|ios::app|ios::binary);
	do
	{
		clrscr();
		bk.create_book();
		fp.write((char*)&bk,sizeof(book));
		gotoxy(3,22);
		cout<<"Do you want to add more record...(y/n?)";
		cin>>ch;
	}while(ch=='y'||ch=='Y');
	fp.close();
}
void write_student()
{
	clrscr();
	box();
	char ch;
	int an;
	ifstream f;
	f.open("student.dat",ios::in|ios::binary);
	if(f.good())
	{
		while(!f.eof())
		{
			f.read((char*)&st,sizeof(student));
			st.retadmno();
		}
		an=st.retadmno();
		an++;
		f.close();
		fp.open("student.dat",ios::out|ios::app|ios::binary);
		st.create_student(an);
		fp.write((char*)&st,sizeof(student));
		fp.close();
	}
	else
	{
		fp.open("student.dat",ios::out|ios::app|ios::binary);
		st.create_student(5000);
		fp.write((char*)&st,sizeof(student));
		fp.close();
	}
	fp.close();
}
//***************************************************************
//        FUNCTION TO READ SPECIFIC RECORD FROM FILE
//****************************************************************
void display_spb()
{
	char n[10];
	clrscr();
	box();
	gotoxy(30,3);
	cout<<"... BOOK DETAILS ...";
	gotoxy(3,5);
	cout<<"Enter The book Number(10**): ";
	cin>>n;
	int flag=0;
	fp.open("book.dat",ios::in);
	while(fp.read((char*)&bk,sizeof(book)))
	{
		if(strcmpi(bk.retbno(),n)==0)
		{
			bk.show_book(6);
			flag=1;
		}
	}

	fp.close();
	if(flag==0)
	{
		gotoxy(3,23);
		cout<<"Book does not exist!!!";
	}
	getch();
}

void display_sps()
{
	int n;
	clrscr();
	box();
	gotoxy(3,5);
	cout<<"Enter The Admission Number(50**): ";
	cin>>n;
	gotoxy(30,3);
	cout<<"...STUDENT DETAILS...";
	int flag=0;
	fp.open("student.dat",ios::in);
	while(fp.read((char*)&st,sizeof(student)))
	{
		if(st.retadmno()==n)
		{
			st.show_student(6);
			flag=1;
		}
	}

	fp.close();
	if(flag==0)
	{
		gotoxy(3,23);
		cout<<"Student does not exist!!!";
	}
	getch();
}
//****************************************************************
//		 FUNCTION TO DELETE RECORD FILE
//****************************************************************
void modify_book()
{
	clrscr();
	box();
	char n[6];
	int found=0;
	gotoxy(28,3);
	cout<<"... MODIFY BOOK RECORD ...";
	gotoxy(3,5);
	cout<<"Enter The book number of The book(10**):";
	cin>>n;
	fp.open("book.dat",ios::in|ios::out);
	while(fp.read((char*)&bk,sizeof(book)) && found==0)
	{
		if(strcmpi(bk.retbno(),n)==0)
		{
			bk.show_book(6);
			gotoxy(3,10);
			cout<<"Enter The New Details of book:";
			bk.modify_book(11);
			int pos=-1*sizeof(bk);
			fp.seekp(pos,ios::cur);
			fp.write((char*)&bk,sizeof(book));
			gotoxy(3,23);
			cout<<"Record Updated";
			found=1;
		}
	}

	fp.close();
	if(found==0)
	{
		gotoxy(3,23);
		cout<<"Record Not Found!!! ";
	}
	getch();
}
void modify_student()
{
	clrscr();
	box();
	int n;
	int found=0;
	gotoxy(26,3);
	cout<<"... MODIFY STUDENT RECORD ...";
	gotoxy(3,5);
	cout<<"Enter The admission number of The student(50**):";
	cin>>n;
	fp.open("student.dat",ios::in|ios::out);
	while(fp.read((char*)&st,sizeof(student)) && found==0)
	{
		if(st.retadmno()==n)
		{
			st.show_student(7);
			getch();
			gotoxy(3,11);
			st.modify_student(12);
			int pos=-1*sizeof(st);
			fp.seekp(pos,ios::cur);
			fp.write((char*)&st,sizeof(student));
			gotoxy(3,23);
			cout<<"Record Updated!!!";
			found=1;
		}
	}

	fp.close();
	if(found==0)
	{
		gotoxy(3,23);
		cout<<"Record Not Found!!! ";
	}
	getch();
}
//***************************************************************
//        FUNCTION TO DELETE RECORD FILE
//****************************************************************
void delete_student()
{
	clrscr();
	box();
	int n;
	int flag=0;
	gotoxy(30,3);
	cout<<"... DELETE STUDENT ...";
	gotoxy(3,5);
	cout<<"Enter The Admission number of the Student You Want To Delete(50**): ";
	cin>>n;
	fp.open("student.dat",ios::in|ios::out);
	fstream fp2;
	fp2.open("Temp.dat",ios::out);
	fp.seekg(0,ios::beg);
	while(fp.read((char*)&st,sizeof(student)))
	{
		if(st.retadmno()!=n)
		{
			fp2.write((char*)&st,sizeof(student));
		}
		else
		{
			st.show_student(7);
			flag=1;
		}
	}
	fp2.close();
	fp.close();
	remove("student.dat");
	rename("Temp.dat","student.dat");
	if(flag==1)
	{
		gotoxy(3,23);
		cout<<"Record Deleted ...";
	}
	else
	{
		gotoxy(3,23);
		cout<<"Record not found!!!";
	}
	getch();
}
void delete_book()
{
	clrscr();
	box();
	char n[6];
	gotoxy(33,3);
	cout<<"... DELETE BOOK ...";
	gotoxy(3,5);
	cout<<"Enter The Book number of the Book You Want To Delete(10**): ";
	cin>>n;
	fp.open("book.dat",ios::in|ios::out);
	fstream fp2;
	fp2.open("Temp.dat",ios::out);
	fp.seekg(0,ios::beg);
	while(fp.read((char*)&bk,sizeof(book)))
	{
		if(strcmpi(bk.retbno(),n)!=0)
		{
			fp2.write((char*)&bk,sizeof(book));
		}
		else
		{
			bk.show_book(7);
		}
	}

	fp2.close();
	fp.close();
	remove("book.dat");
	rename("Temp.dat","book.dat");
	gotoxy(3,23);
	cout<<"Record Deleted ...";
	getch();
}
//****************************************************************
//        	FUNCTION TO DISPLAY STUDENT LIST
//****************************************************************

void display_alls()
{

	clrscr();
	box();
	int cnt=7;
	fp.open("student.dat",ios::in);
	if(!fp)
	{
	       cout<<"ERROR!!! FILE COULD NOT BE OPEN ";
	       getch();
	       return;
	}
	gotoxy(30,3);
	cout<<"... STUDENT LIST ...";
	gotoxy(2,4);
	cout<<"==============================================================================";
	gotoxy(3,5);
	cout<<"Admission Number"<<setw(30)<<"Student's Name"<<setw(27)<<"Book Issued";
	gotoxy(2,6);
	cout<<"==============================================================================";
	while(fp.read((char*)&st,sizeof(student)))
	{
		gotoxy(3,cnt);
		st.rep();
		cnt++;
	}

	fp.close();
	getch();
}
//****************************************************************
//        	FUNCTION TO DISPLAY BOOK LIST
//****************************************************************

void display_allb()
{
	clrscr();
	box();
	fp.open("book.dat",ios::in|ios::binary);
	if(!fp)
	{
		gotoxy(3,22);
		cout<<"ERROR!!! FILE COULD NOT BE OPEN ";
		getch();
		return;
	}
	int y=7;
	gotoxy(32,3);
	cout<<"... BOOK LIST ...";
	gotoxy(2,4);
	cout<<"==============================================================================";
	gotoxy(2,5);
	cout<<setw(8)<<" Book Number"<<setw(30)<<"Book Name"<<setw(27)<<"Author";
	gotoxy(2,6);
	cout<<"==============================================================================\n";
	while(fp.read((char*)&bk,sizeof(book)))
	{
		bk.report(y);
		y++;
	}
	fp.close();
	getch();
}
//****************************************************************
//        	    FUNCTION TO ISSUE BOOK
//****************************************************************

void book_issue()
{
	clrscr();
	box();
	char bn[6];
	int sn;
	int found=0,flag=0;
	gotoxy(31,3);
	cout<<"... BOOK ISSUE ...";
	gotoxy(3,5);
	cout<<"Enter The student's admission number(50**):";
	cin>>sn;
	fp.open("student.dat",ios::in|ios::out);
	fp1.open("book.dat",ios::in|ios::out);
	while(fp.read((char*)&st,sizeof(student)) && found==0)
	{
		if(st.retadmno()==sn)
		{
			found=1;
			if(st.rettoken()==0)
			{
				gotoxy(3,6);
				cout<<"Enter the book number(10**): ";
				cin>>bn;
				while(fp1.read((char*)&bk,sizeof(book))&& flag==0)
			    {
				if(strcmpi(bk.retbno(),bn)==0)
				{
					bk.show_book(7);
					flag=1;
					st.addtoken();
					st.getstbno(bk.retbno());
					int pos=-1*sizeof(st);
					fp.seekp(pos,ios::cur);
					fp.write((char*)&st,sizeof(student));
					gotoxy(3,21);
					cout<<"Book issued successfully!!!";
					gotoxy(3,22);
					cout<<"Note: Write current date in backside of book and submit within 15 days";
					gotoxy(3,23);
					cout<<"(Fine Rs. 1 for each day after 15 days period)";
					getch();
				}
			     }
				if(flag==0)
				{
					gotoxy(3,19);
					cout<<"Book no does not exist!!!";
				}
			}
		else
		  cout<<"You have not returned the last book... ";

		}
	}
	if(found==0)
	{
		gotoxy(3,23);
		cout<<"Student record not exist...";
	}
	getch();
	fp.close();
	fp1.close();
}
//***************************************************************
//        	FUNCTION TO DEPOSIT BOOK
//***************************************************************
void book_deposit()
{
	clrscr();
	box();
	char bn[6];
	int sn;
	int found=0,flag=0,day,fine;
	gotoxy(30,3);
	cout<<"... BOOK DEPOSIT ...";
	gotoxy(3,5);
	cout<<"Enter the student admission number(50**):";
	cin>>sn;
	fp.open("student.dat",ios::in|ios::out);
	fp1.open("book.dat",ios::in|ios::out);
	while(fp.read((char*)&st,sizeof(student)) && found==0)
	{
		if(st.retadmno()==sn)
		{
			found=1;
			if(st.rettoken()==1)
			{
				while(fp1.read((char*)&bk,sizeof(book))&& flag==0)
				{
					if(strcmpi(bk.retbno(),st.retstbno())==0)
					{
						st.show_student(6);
						bk.show_book(9);
						flag=1;
						gotoxy(3,13);
						cout<<"Book deposited in number of days:";
						cin>>day;
						if(day>15)
						{
							fine=(day-15)*1;
							gotoxy(3,15);
							cout<<"Fine has to deposited Rs.: "<<fine;
						}
						st.resettoken();
						int pos=-1*sizeof(st);
						fp.seekp(pos,ios::cur);
						fp.write((char*)&st,sizeof(student));
						gotoxy(3,22);
						cout<<" Book deposited successfully!!!";
					}
				}
				if(flag==0)
				{
					gotoxy(3,22);
					cout<<"Book number does not exist...";
				}
			}
				else
				{
					gotoxy(3,22);
					cout<<"No book is issued..please check!!!";
				}
		}
       }
	if(found==0)
	{
		gotoxy(3,22);
		cout<<"Student record not exist...";
	}
	fp.close();
	fp1.close();
	getch();
}
//****************************************************************
//        	     FUNCTION TO MAKE BOX
//****************************************************************
void box()
{
	int x,y;

	cout<<(char)201;
	for(int i=1;i<=78;i++)
	{
		cout<<(char)205;
	}
	cout<<(char)187;
	y=2;
	for(i=1;i<23;i++)
	{
		gotoxy(1,y);
		cout<<(char)186;
		gotoxy(80,y);
		cout<<(char)186;
		y++;
	}
	cout<<(char)200;
	for(i=1;i<=78;i++)
	{
		cout<<(char)205;
	}
	cout<<(char)188;


}
//****************************************************************
//        	  INTRODUCTION PAGE FUNCTION
//****************************************************************
void intro()
{
	gotoxy(24,11);
	cout<<" L I B R A R Y     M A N A G E M E N T";
	gotoxy(35,13);
	cout<<" S Y S T E M";
	getch();
	clrscr();
	box();
	gotoxy(28,7);
	cout<<"D E V E L O P E D   B Y :";
	gotoxy(27,9);
	cout<<"V A N S H   S O N A V A N E";
	gotoxy(31,11);
	cout<<"C L A S S  XII - B";
	gotoxy(33,14);
	cout<<"( 2019 - 2020 )";
	getch();
}
//****************************************************************
//        	  ADMINISTRATOR MENU FUNCTION
//****************************************************************
void admin_menu()
{
	clrscr();
	box();
	int ch2;
	gotoxy(28,2);
	cout<<"... ADMINISTRATOR MENU ...";
	gotoxy(3,5);
	cout<<"1.CREATE STUDENT RECORD";
	gotoxy(3,6);
	cout<<"2.DISPLAY ALL STUDENTS RECORD";
	gotoxy(3,7);
	cout<<"3.DISPLAY SPECIFIC STUDENT RECORD ";
	gotoxy(3,8);
	cout<<"4.MODIFY STUDENT RECORD";
	gotoxy(3,9);
	cout<<"5.DELETE STUDENT RECORD";
	gotoxy(3,10);
	cout<<"6.CREATE BOOK ";
	gotoxy(3,11);
	cout<<"7.DISPLAY ALL BOOKS ";
	gotoxy(3,12);
	cout<<"8.DISPLAY SPECIFIC BOOK ";
	gotoxy(3,13);
	cout<<"9.MODIFY BOOK ";
	gotoxy(3,14);
	cout<<"10.DELETE BOOK ";
	gotoxy(3,15);
	cout<<"11.BACK TO MAIN MENU";
	gotoxy(3,17);
	cout<<"Please Enter Your Choice (1-11):";
	cin>>ch2;
	switch(ch2)
	{
		case 1:
			clrscr();
			write_student();
			break;
		case 2:
			display_alls();
			break;
		case 3:
			display_sps();
			break;
		case 4:
			modify_student();
			break;
		case 5:
			delete_student();
			break;
		case 6:
			clrscr();
			write_book();
			break;
		case 7:
			display_allb();
			break;
		case 8:
			display_spb();
			break;

		case 9:
			modify_book();
			break;
		case 10:
			delete_book();
			break;
		case 11:
			return;
		default:
			exit(0);
	}
	admin_menu();
}
//****************************************************************
//          	     THE MAIN FUNCTION OF PROGRAM
//****************************************************************
void main()
{
	char ch;
	clrscr();
	intro();
	do
	{
		clrscr();
		box();
		gotoxy(32,3);
		cout<<"*** MAIN MENU ***";
		gotoxy(3,4);
		cout<<"01. BOOK ISSUE";
		gotoxy(3,5);
		cout<<"02. BOOK DEPOSIT";
		gotoxy(3,6);
		cout<<"03. ADMINISTRATOR MENU";
		gotoxy(3,7);
		cout<<"04. EXIT";
		gotoxy(3,9);
		cout<<"Please Select Your Option (1-4): ";
		ch=getche();
		switch(ch)
		{
			case '1':
				getch();
				book_issue();
				break;
			case '2':
				getch();
				book_deposit();
				break;
			case '3':
				getch();
				admin_menu();
				break;
			case '4':
				getch();
				exit(0);
			default :
				exit(1);
		}
	}while(ch!='4');
}
//***************************************************************
//                 	END OF PROJECT
//***************************************************************
