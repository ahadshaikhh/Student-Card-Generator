#include<iostream>
#include<iomanip> 
#include<fstream>
#include<conio.h>
#include<string.h>
#include<windows.h>

using namespace std;

int flag =0;

class person{
	protected:
		char name[20];
		char id[20];
		long long int NIC;
		char expdate[20];
		int age;
		char email[40];
		char gender[20];
	public:
		person(){}
		virtual void displaycard()=0;
};

class staff{
	protected:
		char joindate[20];
		int expyrs;
	
	public:
		staff(){}

};

class student:public person{
	private:
		int batch;
		static int scount;
		char section[20];
		char program[20];
	public:
		student(){}
		void getdata()
		{
			char ext[20] = "@nu.edu.pk";
			cout << "-STUDENT INFORMATION-" << endl << endl;
			fflush(stdin);
			cout << "ENTER STUDENT'S NAME: ";
			cin.getline(name, 28);
			fflush(stdin);
			cout << "ENTER STUDENT'S ID: ";
			fflush(stdin);
			cin.getline(id, 20);
			cout << "ENTER STUDENT'S NIC (Without dashes): ";
			cin >> NIC;
			cout<<"ENTER CARD EXPIRY DATE: ";
			fflush(stdin);
			cin.getline(expdate, 20);
			cout << "ENTER STUDENT'S AGE : ";
			cin >> age;
			strcpy(email, id);
			strcat(email, ext);
			cout << "ENTER STUDENT'S GENDER: ";
			fflush(stdin);
			cin.getline(gender, 20);
			cout << "ENTER STUDENT'S BATCH: ";
			cin >> batch;
			cout << "ENTER STUDENT'S SECTION: ";
			fflush(stdin);
			cin.getline(section, 20);
			cout<<"ENTER STUDENT'S PROGRAM: ";
			fflush(stdin);
			cin.getline(program,20);
			scount++;
		}
		int storeRecord()
		{
			student s;
			ofstream out;
			out.open("STUDENTS_DATA.dat",ios::app|ios::out);
			if(out.fail())
			{
				cout << endl << "Error opening file!";
				return(0);
			}
			s.getdata();
			out.write((char*)&s,sizeof(s));
			out.close();
			return(1);
		}
		student searchRecord()
		{
			int x=0;
			char i[20];
			cout << "Enter STUDENT's ID to search for : ";
			fflush(stdin);
			cin.getline(i,20);
			student stud;
			ifstream in;
			in.open("STUDENTS_DATA.dat",ios::in);
			if(in.fail())
			{
				cout <<endl << "Error opening file!";
				exit(0);
			}
			cout << endl << "File opened!";
			in.seekg(0,ios::beg);
			while(in.read((char *)&stud,sizeof(stud)))
			{	
				if(strcmp(i,stud.id)==0)
				{
					flag = 1;
					x=1;
					cout << endl << "Data found";
				}
			}	
			if(x==0)
			{
				cout << endl << "Data not found!";
			}
			return stud;		
			in.close();
		}
		void displaycard()
		{
			int i;
		    system("cls");
	   	    for(i=0;i<55;i++)
	   	    {
	   	       cout<<"_";
		        if(i>1)
		        {
		        Sleep(50);	
		        }	
		    }
		   	cout << endl << "NATIONAL UNIVERSITY OF COMPUTER AND EMERGING SCIENCES";
			cout << endl << "NAME : " << name;
			cout << endl << "ID : " << id;
			cout << endl << "Gender: " << gender;
			cout << endl << "PROGRAM : " << program;
			cout << endl << "SECTION : " << section;
			cout << endl << "EMAIL : " << email;
			cout << endl << "NIC : " << NIC;
			cout << endl << "EXPIRY DATE : " << expdate <<endl;
	   	    for(i=0;i<55;i++)
	   	    {
	   	    cout<<"_";
		        if(i>1)
		        {
		         Sleep(50);	
		        }	
		    }
		}
		static void totalstudents()
		{
			cout<<"NUMBER OF STUDENTS ADDED RECENTLY: "<<scount;
		}
		
};

int student :: scount=0;

class teacher :public person,public staff{
	private:
		char course[20];
		static int tcount;
	public:
		teacher(){}
		void getdata()
		{
			char ext[20] = "@nu.edu.pk";
			cout<<"-TEACHER INFORMATION-"<<endl<<endl;
			cout<<"ENTER TEACHER'S NAME: ";
			fflush(stdin);
			cin.getline(name,20);
			cout<<"ENTER TEACHER'S ID: ";
			fflush(stdin);
			cin.getline(id,20);
			cout<<"ENTER TEACHER'S NIC (Without dashes): ";
			cin>>NIC;
			cout<<"ENTER CARD EXPIRY DATE: ";
			fflush(stdin);
			cin.getline(expdate,20);
			strcpy(email,id);
			strcat(email,ext);
			cout<<"ENTER  TEACHER'S GENDER: ";
			fflush(stdin);
			cin.getline(gender,20);
			cout<<"ENTER TEACHER'S JOINING DATE : ";
			fflush(stdin);
			cin.getline(joindate,20);
			cout<<"ENTER COURSE TEACHER WILL TEACH : ";
			fflush(stdin);
			cin.getline(course,20);
			cout<<"ENTER TEACHER'S YEARS OF EXPERIENCE : ";
			cin>>expyrs;
			tcount++;
		}
	
		int storeRecord()
		{
			teacher t;
			ofstream out;
			out.open("TEACHERS_DATA.dat",ios::app|ios::out);
			if(out.fail())
			{
				cout <<endl << "Error opening file!";
				return(0);
			}
			t.getdata();
			out.write((char*)&t,sizeof(t));
			out.close();
			return(1);
		}
		
		teacher searchRecord()
		{
			int x=0;
			char i[20];
			cout << "Enter TEACHER's ID to search for : ";
			fflush(stdin);
			cin.getline(i,20);
			teacher tea;
			ifstream in;
			in.open("TEACHERS_DATA.dat",ios::in);
			if(in.fail())
			{
				cout <<endl << "Error opening file!";
				exit(0);
			}
			
			cout << endl << "File opened!";
			in.seekg(0,ios::beg);
			
			while(in.read((char *)&tea,sizeof(tea)))
			{	
				if(strcmp(i,tea.id)==0)
				{
					flag =1;
					x=1;
					cout << endl << "Data found";
				}
			}		
			if(x==0)
			{
				cout << endl << "Data not found!";
			}	
			return tea;
			in.close();
		}
		
		void displaycard()
		{
			int i;
			system("cls");
			for(i=0;i<55;i++)
				{
				cout<<"_";
					if(i>1)
					{
					Sleep(50);	
					}	
				}
			cout << endl << "NATIONAL UNIVERSITY OF COMPUTER AND EMERGING SCIENCES";
			cout << endl << "NAME : " << name;
			cout << endl << "ID : " << id;
			cout << endl << "COURSE : " << course;
			cout << endl << "EMAIL : " << email;
			cout << endl << "NIC : " << NIC;
			cout << endl << "EXPIRY DATE : " << expdate<<endl;;
			
			for(i=0;i<55;i++)
				{
				cout<<"_";
					if(i>1)
					{
					Sleep(50);	
					}	
				}
		}
		static void totalteachers()
		{
			cout<<"NUMBER OF TEACHERS ADDED RECENTLY: "<<tcount;
		}
};

int teacher::tcount=0;

class admin : public person,public staff{
	static int acount;
	public:
		admin(){}
		void getdata()
		{
			char ext[20] = "@nu.edu.pk";
			cout<<"-ADMIN INFORMATION-"<<endl<<endl;
			cout<<"ENTER ADMIN OFFICER'S NAME: ";
			fflush(stdin);
			cin.getline(name,20);
			cout<<"ENTER ADMIN OFFICER'S ID: ";
			fflush(stdin);
			cin.getline(id,20);
			cout<<"ENTER ADMIN OFFICER'S NIC (Without dashes): ";
			cin>>NIC;
			cout<<"ENTER CARD EXPIRY DATE: ";
			fflush(stdin);
			cin.getline(expdate,20);
			strcpy(email,id);
			strcat(email,ext);
			cout<<"ENTER  ADMIN OFFICER'S GENDER: ";
			fflush(stdin);
			cin.getline(gender,20);
			cout<<"ENTER ADMIN OFFICER'S JOINING DATE : ";
			fflush(stdin);
			cin.getline(joindate,20);
			cout<<"ENTER ADMIN OFFICER'S YEARS OF EXPERIENCE : ";
			cin>>expyrs;
			acount++;
		}
		int storeRecord()
		{
			admin ad;
			ofstream out;
			out.open("ADMINS_DATA.dat",ios::app|ios::out);
			if(out.fail())
			{
				cout <<endl << "Error opening file!";
				return(0);
			}
			ad.getdata();
			out.write((char*)&ad,sizeof(ad));
			out.close();
			return(1);
		}
		
		admin searchRecord()
		{
			int x=0;
			char i[20];
			cout << "Enter ADMIN's ID to search for : ";
			fflush(stdin);
			cin.getline(i,20);
			admin ad;
			ifstream in;
			in.open("ADMINS_DATA.dat",ios::in);
			if(in.fail())
			{
				cout <<endl << "Error opening file!";
			}
			cout << endl << "File opened!";
			in.seekg(0,ios::beg);
			
			while(in.read((char *)&ad,sizeof(ad)))
			{	
				if(strcmp(i,ad.id)==0)
				{
					flag = 1;
					x=1;
					cout << endl << "Data found";
				}
			}			
			if(x==0)
			{
				cout << endl << "Data not found!";
			}
			return ad;
			in.close();
		}
		
		void displaycard()
		{
			system("cls");
		   	int i;
		    system("cls");
	   	    for(i=0;i<55;i++)
	   	    {
	   	    cout<<"_";
		        if(i>1)
		        {
		         Sleep(50);	
		        }	
		    }
		   	cout << endl << "NATIONAL UNIVERSITY OF COMPUTER AND EMERGING SCIENCES";
			cout << endl << "NAME : " << name;
			cout << endl << "ID  : " << id;
			cout << endl << "JOINING DATE : " << joindate;
			cout << endl << "NIC : " << NIC;
			cout << endl << "EXPIRY DATE : " << expdate<<endl;
			
		    
	   	    for(i=0;i<55;i++)
	   	    {
	   	    cout<<"_";
		        if(i>1)
		        {
		         Sleep(50);	
		        }	
		    }
		}
		static void totaladmin()
		{
			cout<<"NUMBER OF ADMINS ADDED RECENTLY: "<<acount;
		} 
}; 
int admin::acount=0;

void loading()
{
	system("Color 0A");
	char x=219;
	int i;
	cout<<"\n\n\n\n\n\n\n\n\n";
	cout<<"\t\t\t\t\tLOADING: ";
	
	for(i=0;i<=28;i++)
	{
		cout<<x;
		if(i>=1)
		{
			Sleep(50);
		}
	}
}

void showheading()
{
	int x;
	cout<<"\t\t\t\t\t |~~~~~~~~~~~~~~~~~~~~~~~~~~~~|"<<endl;
    cout<<"\t\t\t\t\t |       CARD GENERATOR       |"<< endl;
	cout<<"\t\t\t\t\t |       FAST UNIVERSITY      |"<<endl;
    cout<<"\t\t\t\t\t |        MAIN CAMPUS         |"<<endl;
    cout<<"\t\t\t\t\t |          KARACHI           |"<<endl;
    cout<<"\t\t\t\t\t |~~~~~~~~~~~~~~~~~~~~~~~~~~~~|"<<endl;
}

int login()
{

	string real_pass = "fast",Password;
	char ch;
	cout << endl << "ENTER PASSWORD TO LOGIN: ";
	ch=getch();
	while (ch!=13)
	{
		Password.push_back(ch);
		cout << "*";
		ch = getch();
	}
	if(Password==real_pass)
	{
		return 1;
	}
	else
	{
		return 0;
	}


}
 
void goodbye()
{
	char y=220;
		    int i;
		    
		    system("cls");
		    
		    cout<<"\n\n\t\t";
		    
		    for(i=0;i<50;i++)
				{
				cout<<y;
					if(i>1)
					{
					Sleep(50);	
					}	
				}
				cout<<endl<<endl<<"\t\t\tGOOD BYE. HAVE A GREAT DAY AHEAD!" <<endl<<endl;
				cout<<"\t\t";
				for(i=0;i<50;i++)
				{
				cout<<y;
					if(i>1)
					{
					Sleep(100);	
					}	
				}
				system("CLS");
}
 
void welcome()
{
	system("CLS");
		    
		    char y=220;
		    int i;
		    cout<<"\n\n\t\t";
		    
		    for(i=0;i<66;i++)
				{
				cout<<y;
					if(i>1)
					{
					Sleep(50);	
					}	
				}
				cout<<endl<<endl<<"\t\tWELCOME TO OUR DATA BASE. SPECIAL WELCOME FROM AHAD, BASIL and ALI"<<endl<<endl;
				cout<<"\t\t";
				for(i=0;i<66;i++)
				{
				cout<<y;
					if(i>1)
					{
					Sleep(100);	
					}	
				}
				system("CLS");
}
 
 
int main()
{
	int c;
	cout << "1 - LOGIN TO DATABASE "<<endl;
	cout << "2 - EXIT THIS PROGRAM "<<endl<<endl;
	cout << "ENTER YOUR CHOICE: "<<endl;
	cin>>c;
	switch(c)
	{
	case 1: 
	{
	int attempts=0;
	person *ptr;
	loading();
    system("color 0F");
    system("cls");
	int choice;
	
	Login:
		system("cls");
		showheading();
		int x = login();
		if (x==1 && attempts<3)
		{
			cout << endl << "Correct Password!" << endl;
		    welcome();
				
			goto Main;
		}
		else
		{
			cout << endl << "Incorrect Password!" << endl;
			cout<<"ATTEMPTS REMAINING: "<<2-attempts<<endl;
			attempts++;
			if(attempts>=3)
		    {
		    system("CLS");
		    showheading();
		    cout<<"TRY AGAIN LATER. YOU ARE OUT OF ATTEMPTS TO LOGIN. ";
		    exit(1);
		    }
			else{
			cout << "Press Enter To Enter Password Again..." << endl;
			getch();
			goto Login;
	    }
	    }
		
			
		
	
	Main:
		loading();
        system("color 0F");
        
		system("cls");
		showheading();
		cout << "1 - ADD NEW STUDENT RECORD" << endl;
    	cout << "2 - ADD NEW TEACHER RECORD" << endl;
    	cout << "3 - ADD NEW ADMIN RECORD" << endl;
    	cout << "4 - GENERATE CARD FOR EXISTING STUDENT  "<<endl;
    	cout << "5 - GENERATE CARD FOR EXISTING TEACHER"<<endl;
    	cout << "6 - GENERATE CARD FOR EXISTING ADMIN"<<endl;
    	cout << "7 - CHECK NUMBER OF CHANGES DONE CURRENTLY"<<endl;
		cout << "8 - LOGOUT" << endl;
		cout << "9 - EXIT THIS PROGRAM"<<endl<<endl;
    	cout << "Enter Your Choice: " << endl;
    	cin>>choice;
		switch(choice)
		{
			case 1:
				{
					loading();
                    system("color 0F");
					system("cls");
					showheading();
					student s;
					if(s.storeRecord()==1)
					{
						cout <<endl<< "Record succesfully saved!";
					}
					
					cout<<endl<<"PRESS ENTER TO RETURN BACK TO MAIN MENU"<<endl;
					getch();
					system("cls");
					goto Main;
					break;
			    }
			case 2:
			   {
					loading();
					system("color 0F");
					system("cls");
					showheading();
					teacher t;
					if(t.storeRecord()==1)
					{
						cout <<endl<< "Record succesfully saved!";
					}
					cout<<endl<<"PRESS ENTER TO RETURN BACK TO MAIN MENU"<<endl;
					getch();
					system("cls");
					goto Main;
					break;
			 }
			case 3:
				{
					loading();
                    system("color 0F");
                    system("cls");
                    showheading();
					admin ad;
			
					if(ad.storeRecord()==1)
					{
						cout <<endl<< "Record succesfully saved!";
					}
					
					cout<<endl<<"PRESS ENTER TO RETURN BACK TO MAIN MENU"<<endl;
					getch();
					system("CLS");
					goto Main;
					break;
			   }
			case 4:
			   {
			   	    loading();
                    system("color 0F");
                    system("cls");
					showheading();
				   	student s1, s2;
				   	s2 = s1.searchRecord();
					if(flag == 1)
					{
						flag = 0;
						ptr=&s2;
						ptr->displaycard();
					}
				   	cout<<endl<<"PRESS ENTER TO RETURN BACK TO MAIN MENU"<<endl;
					getch();
					system("cls");
					goto Main;
					break;
			   }
			case 5:
				{
					loading();
                    system("color 0F");
					system("cls");
					showheading();
					teacher t1, t2;
				   	t2 = t1.searchRecord();
					if(flag==1)
					{
						flag = 0;
						ptr = &t2;
						ptr->displaycard();
					}
				   	cout<<endl<<"PRESS ENTER TO RETURN BACK TO MAIN MENU"<<endl;
					getch();
					system("cls");
					goto Main;
					break;					
				}
			case 6:
				{
					loading();
                    system("color 0F");
                    system("cls");
					showheading();
					admin ad1, ad2;
					ad2 = ad1.searchRecord();
					if(flag == 1)
					{
						flag = 0;
						ptr = &ad2;
					    ptr->displaycard();
					}
					cout<<endl<<"PRESS ENTER TO RETURN BACK TO MAIN MENU"<<endl;
					getch();
					system("cls");
					goto Main;
					break;
				}
			case 7:
				{
			    loading();
                system("color 0F");
                system("cls");
                student s;
                s.totalstudents();
                cout<<endl;
                teacher t;
                t.totalteachers();
                cout<<endl;
                admin a;
                a.totaladmin();
                cout<<endl;
                cout<<endl<<"PRESS ENTER TO RETURN BACK TO MAIN MENU"<<endl;
				getch();
				system("cls");
				goto Main;
				break;
                    
				}
			
			case 8:
			{
				loading();
                system("color 0F");
                system("cls");
				showheading();
				goto Login;
				break;
			}
			case 9:
			{
			    goodbye();
				exit(1);
			}
			default:
				cout << "Wrong choice";
				getch();
				goto Main;
		} 
		break;
	}

        case 2:
        	goodbye();
        	exit(1);
        	
        	break;
    }
}
