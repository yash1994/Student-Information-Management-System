#include<iostream>
#include<cstdio>
#include<cstring>
#include<fstream>
#include<ctype.h>
#include<conio.h>
using namespace std;
fstream fin , fout;
class faculty;
//Date holds the DOB of the student
struct date
{
    int dd;
    int mm;
    int yy;
};
//Student class holds the info of the students
class student
{
    protected:
       
        char category[4];
        char *roll_no;
        char branch[3];
        char *st_nm;
        date dob;
        char attend[15][5];
        char grades[6];
        char sex;
        int sem;
        char pass[10];
        char sub_cd[8][7];
        static int status[5];
    public:
        student()
        {	
            roll_no = new char [1];
            st_nm = new char [1];
	     	strcpy(category,"Not\0");
	     	strcpy(branch , "Null\0");
            strcpy(grades,"NULL\0");
            for(int i = 0 ; i <= 14 ; i++ )
                 strcpy(attend[i],"PPPP");
            dob.dd = 0;
	     	dob.mm = 0;
	     	dob.yy = 0;
	     	sex = '0';
	     	sem = 0;
	
	    }
        void sign_up();
        void modify();
        void display();
        void login_stu();
        int dob_chk();
        char* getrno()
	    {	
            return roll_no; 
        }
        char* getpass()
        {
            return pass;
        }
        char* getnm()
        {
            return st_nm;
        }
        
        friend class faculty;
};
student st;
int student :: status[5] = {0};
//For Existing student login 
void student :: login_stu( )
{
    char c;
    int j;
    char pw[10] , id[7];
    label:
     cout<<"\n\t*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*";
	 cout<<"\n\t\t\t\tLogin Window";
	 cout<<"\n\t*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*";
     cout << "\n\t\t\tEnter Your id: ";
	for( j=0;j < 79 && (c = getch()) != '\r'; j++ )
	{	if ( c == '\b')
        {
            cout << '\b';
            cout << " ";
            cout <<'\b';
            j = j-2;
        }
        else
        {
            id[j] = c;
            cout<<id[j];
        }
	}
	id[j] = '\0';
	if(!strcmpi(id,roll_no))
		cout << "\n\t\t\tID confirmed";
	else
	{	cout << "\n\t\t\tID is invalid\n";
		goto label;
	}
    label1:
    cout << "\n\t\tEnter your password (10 characters only): ";
	for( j=0;j < 79 && (c = getch()) != '\r'; j++ )
	{	if ( c == '\b')
        {
            cout << '\b';
            cout << " ";
            cout <<'\b';
            j = j-2;
        }
        else
        {
            pw[j] = c;
		    std::cout<<"*";
        }
	}
	pw[j] = '\0';
	if(!strcmpi(pw, pass))
		cout << "\n\t\tPassword confirmed";
	else
	{	cout << "\n\t\tPassword denied\n";
		goto label1;
	}
}
void student :: display()
{
   	cout<<"\n\t-------------------------------------------------------\n";
	cout<<"\n\n\t\tDetails of the student";
	cout<<"\n\tRoll no:\t"<<(roll_no);
	cout<<"\n\tName:\t"<<(st_nm);
	cout<<"\n\tBranch:\t"<<branch;
	cout<<"\n\tCategory:\t"<<category;
	cout<<"\n\tSex:\t"<<sex;
	cout<<"\n\tSemester:\t"<<sem;
	cout<<"\n\tDate of birth:\t"<<dob.dd<<"/"<<dob.mm<<"/"<<dob.yy;
	cout<<"\n\tSubject Codes you Opted for:\t";
	for(int  i = 0; i < 6; i++)
	{
        cout<<"\n\t\t"<<sub_cd[i];
    }
    cout<<"\n\t Attendence in the subjects opted by you";
    cout<<"\n\t1. Attendence in Computer Science Lecture:\t"<<attend[0];
    cout<<"\n\t2. Attendence in Computer Science Practical:\t"<<attend[1];
    cout<<"\n\t3. Attendence in Computer Science Tutorial:\t"<<attend[2];
    cout<<"\n\t4. Attendence in Engineering DrwaingII Lecture:\t"<<attend[3];
    cout<<"\n\t5. Attendence in Engineering DrwaingII Practical:\t"<<attend[4];
    cout<<"\n\t6. Attendence in MathematicsII Lecture:\t"<<attend[5];
    cout<<"\n\t7. Attendence in MathematicsII Tutorial:\t"<<attend[6];
    cout<<"\n\t8. Attendence in Engineering Physics Lecture:\t"<<attend[7];
    cout<<"\n\t9. Attendence in Engineering Physics Practical:\t"<<attend[8];
    cout<<"\n\t10.Attendence in Communication Skills Lecture:\t"<<attend[9];
    cout<<"\n\t11.Attendence in Communication Skills Practical:\t"<<attend[10];
    cout<<"\n\t12.Attendence in Elements of Electrical Engineering Lecture:\t"<<attend[11];
    cout<<"\n\t13.Attendence in Elements of Electrical Engineering Practical:\t"<<attend[12];
    cout<<"\n\t14.Attendence in Elements of Electrical Engineering Tutorial:\t"<<attend[13];
    cout<<"\n\t-------------------------------------------------------\n";
}
//For New student sign up
void student::sign_up()
{	int len;
    int flag;
    int j;
    char c;
    char nm[30];
    char rno[8];
    lb:
    cout<<"\nEnter Your rollno(No special character):\t";
    cin.get();
    gets(rno);
    roll_no = rno ;
    strcpy(roll_no,rno);
    for(int i=0;roll_no[i] !='\0';i++)
	    {	 
            if(isalnum(roll_no[i]) == 0)
		    {	  
                  cout<<"\nYour Roll No is invalid renter\a\a\a";
                  strcpy(roll_no,"0000000");
                  goto lb;
            }
        }
    cout<<"\nEnter Your name\t";
	gets(nm);
	st_nm = new char [strlen(nm)];
    strcpy(st_nm,nm);
	lb1:
	cout<<"\nEnter your Stream chosen from the given options(BCE,BME,BEC,BEE,BCL,BCH) \n";
	cin>>(branch);
	if(strcmp(branch,"BCE")!= 0 && strcmp(branch,"BCL")!=0 && strcmp(branch,"BCH")!=0 && strcmp(branch,"BEE")!=0 && strcmp(branch,"BEC") != 0 && strcmp(branch,"BIT") && strcmp(branch,"BME") != 0)
	{	cout<<"\nYou Entered a Invalid Branch";
	    strcpy(branch,"NUll");
		goto lb1;
	}
	cout<<"\nEnter your semester:\t";
    cin>>sem;
    lb2:
    cout<<"\nEnter category(GEN,OBC,SC,ST):\t";
	cin>>category;
	if(strcmp(category,"GEN") != 0 && strcmp(category,"OBC") != 0 && strcmp(category,"SC") != 0 && strcmp(category,"ST") != 0)
    {   cout<<"\nYour Entered Category is invalid\a\a\a";
        strcpy(category,"NULL");
        goto lb2;
    }
	cout<<"\nEnter sex(Enter F/M):\t";
	cin>>sex;
	lb3:
    cout<<"\nEnter your Date of  birth (dd/mm/yy):\t";
    cin>>dob.dd;
    cin>>dob.mm;
    cin>>dob.yy;
    flag = dob_chk();
    if ( flag == 1)
        goto lb3;
    cout << "\nEnter password of your choice(10 characters only): ";
	for( j=0;j < 79 && (c = getch()) != '\r'; j++ )
	{	if ( c == '\b')
        {
            cout << '\b';
            cout << " ";
            cout <<'\b';
            j = j-2;
        }
        else
        {
            pass[j] = c;
		    std::cout<<"*";
        }
	}
	pass[j] = '\0';
	lb4:
    char pw[10];
    cout<<"\nReconfirm your password:\t";
    cout << "\nEnter password: ";
	for(j=0;j < 79 && (c = getch()) != '\r'; j++ )
	{	if ( c == '\b')
        {
            cout << '\b';
            cout << " ";
            cout <<'\b';
            j = j-2;
        }
        else
        {
            pw[j] = c;
		    std::cout<<"*";
        }
	}
	pw[j] = '\0';
    if(!strcmpi(pw, pass))
		cout << "\nPassword confirmed";
	else
	{	cout << "\nDoesn't match the previous one reconfirm\n";
		goto lb4;
	}
	cout<<"\nEnter the Subject code of the subjects you are studying:\t";
	for( int  i = 0 ; i < 6 ; i++)
    {
        gets(sub_cd[i]);
    }
}
//For Modifying student data
void student::modify()
{	char nm[30];
	char nme[5];
	char rno[5];
	char ad[5];
	char cat[5];
	char brn[3];
	cout<<"\nOld details of the student";
	display();
	cout<<"\nEnter new details";
	cout<<"\nNew admission number (Enter '.' to retain old one):\t";
	gets(ad);
	cout<<"\nNew roll number (Enter '.' to retain old one):\t";
	gets(rno);
	cout<<"\nNew\t";
	cin.getline(nme,5);
	cout<<"name (Enter '.' to retain old one):\t";
	cin.getline(nm,30);
	cout<<"\nCaste(Enter '.' to retain old one):\t";
	gets(cat);
	cout<<"\nStream(Enter '.' to retain old one):\t";
	cin>>brn;
	if(strcmp(rno,".")!=0)
		strcpy(roll_no,rno);
	if(strcmp(nm,".")!=0)
		strcpy(st_nm,nm);
	if(strcmp(cat,".")!=0)
		strcpy(category,cat);
	if(strcmp(brn,".")!=0)
	    strcpy(branch,brn);
		
}
//For checking the Date of Birth of the student
int student :: dob_chk()
{
   		int flag=1;
		if(dob.mm==1||dob.mm==3||dob.mm==5||dob.mm==7||dob.mm==8||dob.mm==10||dob.mm==12)
		{	if(dob.dd<=31&& dob.dd>0)
				flag=0;
			else
				cout<<"\nThe Date entered by u is invalid";
		}
		else if(dob.mm==4||dob.mm==6||dob.mm==9||dob.mm==11)
		{	if(dob.dd<=30&&dob.dd>0)
				flag=0;
			else
				cout<<"\nThe Date entered by u is invalid";
		}
		else if(dob.mm==2)
		{	if(dob.yy%100==0 && dob.yy%400==0|| dob.yy%100==0 && dob.yy%4==0)
			{	if(dob.dd<=29&&dob.dd>0)
					flag=0;
				else
					cout<<"\nThe Date entered by u is invalid";
			}
			else
			{	if(dob.dd<=28 && dob.dd>0)
					flag=0;
				else
					cout<<"\nThe Date entered by u is invalid";
			}
		}
		if(flag==0)
			cout<<"Date enterd by u is valid";
		return flag;

}
//Faculty is a friend class of student
class faculty
{
    
    char id[7];
    char pwd[7];
    char ch;
    char typ;
    public:
        
        faculty()
        {
            strcpy(id ,"12NUBCE");
            strcpy(pwd ,"1234567");
        }
        void upd_attd();
        void upd_grades();
        void login_fac();
        
};
faculty ft;
//For Facult login
void faculty :: login_fac()
{
    char c;
    int j;
    lab:
     cout<<"\n\t*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*";
	 cout<<"\n\t\t\t\tFaculty Login Window";
     cout<<"\n\t*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*";
    cout << "\n\t\tEnter Your id: ";
	for( j=0;j < 79 && (c = getch()) != '\r'; j++ )
	{	if ( c == '\b')
        {
            cout << '\b';
            cout << " ";
            cout <<'\b';
            j = j-2;
        }
        else
        {
            id[j] = c;
            cout<<id[j];
        }
	}
	id[j] = '\0';
	if(!strcmpi(id,"12NUBE"))
		cout << "\n\t\tID confirmed";
	else
	{	cout << "\n\t\tID is invalid\n";
		goto lab;
	}
    lab1:
    cout << "\n\t\tEnter password of your choice(10 characters only): ";
	for( j=0;j < 79 && (c = getch()) != '\r'; j++ )
	{	if ( c == '\b')
        {
            cout << '\b';
            cout << " ";
            cout <<'\b';
            j = j-2;
        }
        else
        {
            pwd[j] = c;
		    std::cout<<"*";
        }
	}
	pwd[j] = '\0';
	if(!strcmpi(pwd, "1234567"))
		cout << "\nPassword confirmed";
	else
	{	cout << "\nPasswprd denied\n";
		goto lab1;
	}
}
//To upgrade Grades
void faculty :: upd_attd()
{
    student st;
    char rno[8];
    fin.open("Student.DAT",ios::in|ios::out|ios::app);
    int pos , count = 1;
    cout<<"\n\t------------------------------------------------------------------";
    cout<<"\n\tEnter the roll number of student whose attendence you want to update";
    cin>>rno;
    cout<<"\n\tEnter yout choice for the subject you teach:\t"; 
    cout<<"\n\t\t1.Computer Programing II";
    cout<<"\n\t\t2.Engineering Drawing II";
    cout<<"\n\t\t3.Mathematics II";
    cout<<"\n\t\t4.Engineering Physics";
    cout<<"\n\t\t5.Communication skills";
    cout<<"\n\t\t6.Elements of Electrical Engineering\n";
    cin>>ch;
    cout<<"\nEnter Lecture type(1.For Lecture  2.For Practical and 3.For Tutorial):\t";
    cin>>typ;
    cout<<"\n\t------------------------------------------------------------------";
    while(!fin.eof())
	{	fin.read((char *)&st,sizeof(st));
		if (fin.eof())
			break;
		if(strcmpi(st.getrno(),rno)==0)
		{	
			count=0;
		}
	}
	pos = fin.tellg();
    fin.seekp((pos-sizeof(st)));
    switch(ch)
    {
        case '1':
            
            switch(typ)
            {
                case '1':
                cout<<"\nEnter the status of student in present class (A/P):\t";
                cin>>st.attend[0][st.status[0]];
                st.status[0]++;
                break;
                case '2':
                cout<<"\nEnter the status of student in present class (A/P):\t";
                cin>>st.attend[1][st.status[1]];
                st.status[1]++;
                break;
                case '3':
                cout<<"\nEnter the status of student in present class (A/P):\t";
                cin>>st.attend[2][st.status[2]];
                st.status[2]++;
            }
            break;
            case '2':
            switch(typ)
            {
                case '1':
                cout<<"\nEnter the status of student in present class (A/P):\t";
                cin>>st.attend[3][st.status[3]];
                st.status[3]++;
                break;
                case '2':
                cout<<"\nEnter the status of student in present class (A/P):\t";
                cin>>st.attend[4][st.status[4]];
                st.status[4]++;
                break;
            }
            break;
            case '3':
            switch(typ)
            {
                case '1':
                cout<<"\nEnter the status of student in present class (A/P):\t";
                cin>>st.attend[5][st.status[5]];
                st.status[5]++;
                break;
                case '2':
                cout<<"\nNo Practical sessions for this Subject Sorry!!!!\a\a";
                break;
                case '3':
                cout<<"\nEnter the status of student in present class (A/P):\t";
                cin>>st.attend[6][st.status[6]];
                st.status[6]++;
                break;
            }
            break;
            
            case '4':
            switch(typ)
            {
                case '1':
                cout<<"\nEnter the status of student in present class (A/P):\t";
                cin>>st.attend[7][st.status[7]];
                st.status[7]++;
                break;
                case '2':
                cout<<"\nEnter the status of student in present class (A/P):\t";
                cin>>st.attend[8][st.status[8]];
                st.status[8]++;
                break;
                case '3':
                cout<<"\nNo Tutorial Sessions for this";
            }
            break;
        
            case '5':
            switch(typ)
            {
                case '1':
                cout<<"\nEnter the status of student in present class (A/P):\t";
                cin>>st.attend[9][st.status[9]];
                st.status[9]++;
                break;
                case '2':
                cout<<"\nEnter the status of student in present class (A/P):\t";
                cin>>st.attend[10][st.status[10]];
                st.status[10]++;
                break;
                case '3':
                cout<<"\nNo Tutorial Sessions for this";
            }
            break;
            
            case '6':
            switch(typ)
            {
                case '1':
                cout<<"\nEnter the status of student in present class (A/P):\t";
                cin>>st.attend[11][st.status[11]];
                st.status[11]++;
                break;
                case '2':
                cout<<"\nEnter the status of student in present class (A/P):\t";
                cin>>st.attend[12][st.status[12]];
                st.status[12]++;
                break;
                case '3':
                cout<<"\nEnter the status of student in present class (A/P):\t";
                cin>>st.attend[13][st.status[13]];
                st.status[13]++;
                break;
            }
            break;
        }
        st.display();
        fin.write((char *) &st , sizeof(st));
        fin.close();
}    
//Global function Declaration    
void reg(student &st);
void disp();
void modfy();
student srch(char rno[]);
//Main Body
int main()
{
  
    int c1 , c2 , c3 , count = 1;
    student st;
    faculty ft;
    int ch ;
    char ch1 = 'y';
    char rno[8];
    while(ch1=='y'||ch1=='Y')
	{	//clrscr();
		//main menu
        menu:
        cout<<"\n\t*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*";
		cout<<"\n\t\t\t\aWelcome to Nirma University Student Database";
		cout<<"\n\t*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*";
		cout<<"\n\n\t\t\tHello! You are in Main Menu\n";
		cout<<"\n\t-------------------------------------------------------\n";
		cout<<"\n\t\t\t\tMain Menu Options\n";
		cout<<"\n\t\t1.Student Section\n";
		cout<<"\n\t\t2.Faculty Section\n";
		cout<<"\t-------------------------------------------------------";
		cout<<"\nEnter Your choice:\t";
		cin>>ch;
		switch(ch)                                                                 //start of switch statment
		{
            //Student menu logic
            case 1:
			
			//clrscr();
			cout<<"\n\t-------------------------------------------------------\n";
			cout<<"\n\n\t\t\tHello! You are in Student Menu";
			cout<<"\n\n\t\t\tStudent Menu opton";
			cout<<"\n\t1.New Student Sign Up";
			cout<<"\n\t2.Existing Student login";
			cout<<"\n\t3.To return to Main Menu";
			cout<<"\n\t-------------------------------------------------------\n";
			cout<<"\nEnter your choice:\t";
			cin>>c1;
			switch(c1)                                                              //Start of switch statement
			{  //To search record by roll number
				case 1:
				reg(st);
				//clrscr();
				cout<<"-----------------------------------------------------------------\n";
				cout<<"\n\t\tRegistered Successfully";
				cout<<"\n-----------------------------------------------------------------\n";
				goto menu;
				break;

				//Student Login Menu
				case 2:
	            //clrscr();
                cout<<"\n\t-------------------------------------------------------\n";
			    cout<<"\n\n\t\t\tHello! You are in Profile Menu";
			    cout<<"\n\n\t\t\tProfile Menu Options";
			    cout<<"\n\t1.To Display Your Profile";
			    cout<<"\n\t2.To Modify  Your Profile";
			    cout<<"\n\t3.To Search records";
                cout<<"\n\t4.To return to main menu";
			    cout<<"\n\t-------------------------------------------------------\n";
			    cout<<"\nEnter your choice";
			    cin>>c2;
			    switch(c2)                                                              //Start of switch statement
			    {

				   //To display record of the student
				   case 1:
				   disp();
				   break;

				   //To modify an existing record of the student
				   case 2:
				   //modfy();
				   break;
                  //To search the profile of other student
				   case 3:
				   cout<<"\n\t\tEnter Your roll no";
                   st = srch(rno);
                   st.display();
				   break;
				   case 4:
                   goto menu;
                   break;
            
			   }                                                                       //End of switch statement
		       break;

				//To return to main menu
			   case 3:
			   goto menu;
			   break;

			}                                                                       //End of switch statement
			break;
            //Faculty Menu Logic
			case 2:
			    cout<<"\n\t-------------------------------------------------------\n";
			    cout<<"\n\n\t\t\tHello! Your in Faculty Menu";
			    cout<<"\n\n\t\t\tFaculty Menu Options";
			    cout<<"\n\t1.To Update the attendence of student";
			    cout<<"\n\t2.To Update the grades of student";
			    cout<<"\n\t3.To Search record of a student";
                cout<<"\n\t4.To return to main menu";
			    cout<<"\n\t-------------------------------------------------------\n";
			    cout<<"\nEnter your choice";
			    cin>>c2;
			    switch(c2)
			    {
                    case 1:
                        ft.login_fac();
                        ft.upd_attd();
                        break;
                    case 2:
                        ft.login_fac();
                        break;
                    case 3:
                        cout<<"\n\t\tEnter the roll no of the student";
                        gets(rno);
                        gets(rno);
                        st = srch(rno);
                        st.display();
                        break;
                    case 4:
                        goto menu;
                        break;
                }
                


			case 3:
			//exit(0);
			break;
		}                                                                          //End switch statment
		cout<<"\nDo You want to continue:\t";
		cin>>ch1;
	}
}
void reg(student &s)
{
    //clrscr();
    fout.open("Student.DAT",ios::out|ios::app);
    cout<<"\n**********************************************************************";
    cout<<"\n\t\tNew Student registration Forum";
    cout<<"\n**********************************************************************";
    s.sign_up();
    fout.write((char *) &s , sizeof(s) );
    fout.close();
    
}
void disp()
{
    student s;
    fin.open("Student.DAT", ios::in);
    fin.read((char *) &s , sizeof(s));
    s.display();
    fin.close();
    return;
}
student srch(char rno[8])
{
    int pos , count = 1;
    student s1;
    fin.open("Student.DAT",ios::in);
    while(!fin.eof())
	{	fin.read((char *)&s1,sizeof(s1));
		if (fin.eof())
			break;
		if(strcmp(s1.getrno(),rno)==0)
		{	
			count=0;
		}
	}
	if(count!=0)
		cout<<"\nRecord of student with\t"<<rno<<"\tdoes not exist";
	else
        s1.display();
	fin.close();
	return s1;
}
//To modify the student record
void modfy()
{	char rn[5];
	int pos;
	student s2;
	fstream fin;
	cout<<"\nEnter the roll no of the student whose details are to be modified:\t";
	cin>>rn;
	fin.open("student.dat",ios::app|ios::in);
	while(!fin.eof())
	{	fin.read((char *)&s2,sizeof(s2));
		if(fin.eof())
			break;
		pos=fin.tellg();
		if(strcmp(s2.getrno(),rn)==0)
		{	s2.modify();
			fin.seekp((pos-sizeof(s2)));
			fin.write((char *)&s2,sizeof(s2));
			break;
		}
	}
	fin.close();
}


