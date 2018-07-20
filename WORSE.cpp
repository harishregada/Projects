#include<iostream>
#include<stdlib.h>
#include<windows.h>
#include<cstdlib>
#include<mysql.h>
#include<string>
#include"Multi_Mains.h"
//#include<bits/stdc++.h>

using namespace std;

///std::string s = std::to_string(number);
///char const *pchar = s.c_str();  //use char const* as target type


//This Is An ATM!!!, Not A Bank. Point To Be Noted

int old_pin,new_pin1=0,new_pin2=1;    //new_pin1, new_pin2 were 0 and 1??
int pin,bal,choice;

//char PIN[4];  //PIN from DB
//char BALANCE[5];  //BALANCE from DB

char confirm;

int main()
{
    MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES* res;

    int qstate;
    char* help[2];
    string s;

    int convert[4];  ///This could change the program
    int index=0;

    ///Connecting To DB Section Starting
    conn=mysql_init(0);

    /*
    cout<<"Connecting To DB |"<<endl;
    system("ping localhost -n 2 >nul");
    system("cls");

    cout<<"Connecting To DB /"<<endl;
    system("ping localhost -n 2 >nul");
    system("cls");

    cout<<"Connecting To DB --"<<endl;
    system("ping localhost -n 2 >nul");
    system("cls");

    cout<<"Connecting To DB "<<(char)92<<endl;
    system("ping localhost -n 2 >nul");
    system("cls");

    cout<<"Connecting To DB |"<<endl;
    system("ping localhost -n 2 >nul");
    system("cls");
    */

    conn=mysql_real_connect(conn,"localhost","root","","bankdetails",0,NULL,0);

    if(conn)
    {
         cout<<"Connected To DB"<<endl;
         system("pause");

         qstate=mysql_query(conn,"select VariableValues from DETAILS");  //Passing Query

         if(!qstate)
         {
             res=mysql_store_result(conn);  //res holds address


             while(row=mysql_fetch_row(res))
             {
                 help[index]=row[0];    //First Row of 1st Column then 2nd Column

                 //system("cls");
                 cout<<"HELP : "<<help[index]<<endl;

                 //system("echo.");
                 //system("ping localhost -n 3 >nul");

                 index++;
             }
         }

         else
         {
             cout<<"Query Execution Failed"<<endl;
             system("pause");
         }
    }

    else
    {
        cout<<"Connection To DB Failed : "<<mysql_error(conn)<<endl;
        system("pause");
    }

    system("cls");

    //PIN=help[0];
    //BALANCE=help[1];

    //char pin_help[5],bal_help[5];

    pin=atoi(help[0]);
    bal=atoi(help[1]);
    cout<<"pin : "<<pin<<endl<<"bal : "<<bal<<endl;

    ///row=mysql_fetch_row(res);
    ///cout<<"\n\nROW[0] : "<<row[0]<<endl<<"ROW[1] : "<<row[1]<<endl;

    //strcpy(pin_help,help[0]);
    //strcpy(bal_help,help[1]);
    //cout<<"PIN : "<<pin_help<<endl<<"BALANCE : "<<bal_help<<endl;

    system("pause");
    system("cls");

    ///cin working to get char*
    //cout<<"Enter PIN and BALANCE : ";
    //cin>>PIN;
    //cin>>BALANCE;
    //cout<<"PIN : "<<PIN<<endl<<"BALANCE : "<<BALANCE<<endl;

    ///strcpy(pin,PIN);
    ///strcpy(bal,BALANCE);

    //pin=(int)PIN;
    //bal=(int)BALANCE;

    //cout<<"pin : "<<pin;
    //cout<<"bal : "<<bal;

    system("echo.");
    system("pause");

    ///Connection To DB Section Ending

	system("cls");

	int pin_check;    ///pin_check featured as char*
	int i;

	//Login:	//Login Label
	cout<<"-----Welcome To ATM Services!-----"<<endl;

	while(1)    //Infinite Loop
	{
		cout<<"\nEnter Your Pin : ";
		cin>>pin_check;

		if(pin_check==pin) ///pin_check==PIN or pin    ///Here we go...  Need to typecast
		break;

		else	//if(pin_check!=pin)
		{
			system("cls");

			for(i=3;i>0;i--)
			{
				if(i==3)
				{
                    cout<<"\nPin Not Found";
					system("ping localhost -n 2 >nul");
					system("cls");
				}

				//Waiting For 3 Seconds After Entering Wrong Pin
				if(i<=3)
				{
					cout<<"\nEnter Pin Again In "<<i<<" Seconds";
					system("ping localhost -n 2 >nul");
					system("cls");
				}
			}
		}
	}

	Start:	//Label Start
	system("cls");

	cout<<"\n-----Welcome To ATM Services!-----"<<endl;
	cout<<"1.Check Balance"<<endl;
	cout<<"2.Withdraw"<<endl;
	cout<<"3.Change Pin"<<endl;
	cout<<"4.Exit"<<endl;
	cout<<"Enter Your Choice : ";

	cin>>choice;

	int withdraw=0;     ///withdraw featured as char*
	char confirm;

	switch(choice)
	{
		case 1:
			cout<<"\nYour Balance Is : "<<bal;

			cout<<endl;
			system("pause");    //Press Any Key To Continue..

			goto Start;     //goto label Start


		case 2:
			Trans:	//Label Trans

				withdraw=0;

				system("cls");
				cout<<"\n\nEnter Amount To Withdraw : ";
				cin>>withdraw;

				if(withdraw>bal)
				{
					cout<<"\nLow Balance Amount :(";

					cout<<endl;
					system("pause");    //Press Any Key To Continue..

					goto Trans;     //goto label Trans
				}

				if(withdraw<bal)
				{
					//fflush(stdin);
					cout<<"\nAmount To Withdraw Rs."<<withdraw<<endl;
					cout<<"Enter Y To Confirm or N To Cancel : ";
					cin>>confirm;
				}

				if(confirm=='Y' || confirm=='y')
				{
					system("cls");
					bal=bal-withdraw;

					///std::string s = std::to_string(number);
                    ///char const *pchar = s.c_str();  //use char const* as target type

                    //
                    s = to_string(bal);
                    //help[1] = s.c_str();  //use char const* as target type
                    //atoi();

					cout<<"\n\nTransaction Completed :)";
					cout<<"\nBalance Remaining : "<<bal;

					cout<<"\n\nhelp[1](bal) = "<<help[1]<<endl;
					cout<<endl;
					system("pause");    //Press Any Key To Continue..

					goto Start;     //goto label Start
				}

				if(confirm=='N' || confirm=='n')
					goto Trans;     //goto label Trans

		case 3:
		Pin:
			system("cls");
			cout<<"\nEnter Old Pin : ";
			cin>>old_pin;
            system("ping localhost -n 1 >nul");
			system("cls");

			if(old_pin==pin)
			{
				cout<<"\nEnter New Pin : ";
				cin>>new_pin1;
				system("ping localhost -n 1 >nul");
				system("cls");

				cout<<"\nEnter New Pin Again : ";
				cin>>new_pin2;
				system("ping localhost -n 1 >nul");
				system("cls");
			}

			else
			{
				cout<<"\nPin Not Found. Please Enter The Pin Again";
				system("ping localhost -n 3 >nul");
				goto Pin;   //goto label Pin
			}

			if(new_pin1==new_pin2)
			{
				pin=new_pin2;
				cout<<"Pin Has Been Changed";
				system("ping localhost -n 2 >nul");
				goto Start;     //goto label Start
			}

			else
			{
				cout<<"\nPin Is Not Matching";
				system("ping localhost -n 3 >nul");
				goto Pin;   //goto label Pin
			}


		case 4:
			cout<<"\nThank You For Using Our ATM :)";
			Sleep(3);
			break;
	}

	return (0);
}


