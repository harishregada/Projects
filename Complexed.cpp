#include<iostream>
#include<windows.h>
#include<cstdlib>
#include<mysql.h>
#include<string>
//#include<bits/stdc++.h>

using namespace std;

//This Is An ATM!!!, Not A Bank. Point To Be Noted


int old_pin,new_pin1=0,new_pin2=1;
int pin,bal,choice;

char* PIN;  //PIN from DB
char* BALANCE;  //BALANCE from DB

char confirm;

int main()
{
    MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES* res;

    int qstate;
    int fetch_count=1;
    char* help[2];
    int index=0;

    //Connecting To DB Section Starting
    conn=mysql_init(0);

/*    cout<<"Connecting To DB |"<<endl;
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
                 help[index]=row[0];

                 //if(index==0)     //Value In 2nd ROW In 1st Column of Table
                 {
                     //PIN=help[index];
                     //Replacement -> PIN=row[0];
                 }


                 //if(index==1)     //Value In 2nd ROW In 2nd Column of Table
                 {
                     //BALANCE=help[index];
                     //Replacement -> BALANCE=row[0];
                 }

                 //if(fetch_count==3)
                 //    break;

                 //system("cls");
                 //cout<<"PIN = "<<PIN<<endl<<"BALANCE = "<<BALANCE<<endl;
                 //cout<<"RES : "<<res<<endl<<"ROW : "<<row<<endl;
                 //cout<<"HELP : "<<help[index]<<endl;

                 //system("echo.");
                 //system("ping localhost -n 3 >nul");

                 //fetch_count++;
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
    strcpy(PIN,help[0]);
    strcpy(BALANCE,help[1]);
    cout<<"PIN : "<<PIN<<endl<<"BALANCE : "<<BALANCE<<endl;
    system("echo.");
    system("pause");

    //pin=(int)PIN;
    //bal=(int)BALANCE;
    //cout<<"pin : "<<pin;
    //cout<<"bal : "<<bal;
    //system("pause");

    //Connection To DB Section Ending

	system("cls");
	int pin_check,i;

	//Login:	//Login Label
	cout<<"-----Welcome To ATM Services!-----"<<endl;

	while(1)    //Infinite Loop
	{
		cout<<"\nEnter Your Pin : ";
		cin>>pin_check;

		if(pin_check==pin)
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

	long withdraw=0;
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
					fflush(stdin);
					cout<<"\nAmount To Withdraw Rs."<<withdraw<<endl;
					cout<<"Enter Y To Confirm or N To Cancel : ";
					cin>>confirm;
				}

				if(confirm=='Y' || confirm=='y')
				{
					system("cls");
					bal=bal-withdraw;
					cout<<"\n\nTransaction Completed :)";
					cout<<"\nBalance Remaining : "<<bal;

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

