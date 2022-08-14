/****************PROJECT ON BANKING SYSTEM***********************/


#include<iostream>
#include<time.h>
#include<fstream>
#include<stdio.h>
#include<ctype.h>
#include<string.h>
using namespace std;
//function for date & time
const std::string currentDateTime() 
{
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);

    return buf;
}

//class define
class BankingSystem
{
		private:
			long int account_number,mob_number,balance,newbalance,amount;
			string name,address,email,type;
			char choice,ch;
		public:
			void open_new_account(int n,BankingSystem *ob);
			void account_info();
			int withdraw();
			int deposit();
			void balance_info();
			int check(long int account_number,BankingSystem *ob,int n);
			int  ret();
			ofstream fp;
			char c,u;
			char filename[20];
};

//function for new account opening

void BankingSystem::open_new_account(int n,BankingSystem *ob)
{
		newbalance=0,balance=0;
		int f=0;
		cout<<"HEY YOU ARE OUR "<<(n+1)<<" CUSTOMER"<<endl<<endl;
		cout<<"ENTER THE DESIRED ACCOUNT NUMBER"<<endl;
		do{
			cin>>account_number;
			if(account_number==check(account_number,ob,n))
			{
				cout<<"ACCOUNT NUMBER ALREADY EXISTS ENTER UNIQUE ONE"<<endl;
				f=1;
			}
			else
				f=0;
		}while(f==1);
		cout<<"TYPE OF ACCOUNT"<<endl;
		cin>>type;
		cout<<"YOUR NAME PLEASE"<<endl;
		cin>>name;
		cout<<"YOUR ADDRESS"<<endl;
		cin>>address;
		cout<<"YOUR MOBILE NUMBER"<<endl;
		cin>>mob_number;
		cout<<"ENTER YOUR VALID EMAIL ID"<<endl;
		cin>>email;
		cout<<"DO YOU WANT DEPOSIT AMOUNT Y/N"<<endl;
		
			cin>>choice;
		do{
			if(toupper(choice)=='Y')
			{
				cout<<"ENTER THE AMOUNT"<<endl;
				cin>>newbalance;
				fp.open("my_text.txt",fstream::app);
				fp << "deposite="<<newbalance<<" "<<currentDateTime()<<endl;
				fp.close();
				balance=balance+newbalance;
			}
			else if(toupper(choice)=='N')
			{
				cout<<"NO WORRIES, YOU CAN ALSO HAVE ZERO BALANCE ACCOUNT"<<endl;
				break;
			}
			else
				cout<<"ENTER VALID CHOICE PLEASE"<<endl;
			cout<<"WANT TO ADD MORE DEPOSIT ? Y/N"<<endl;
			cin>>ch;
		}while(toupper(ch)=='Y');
		cout<<endl;
		cout<<"HELLO "<<name<<" YOUR ACCOUNT NUMBER "<<account_number<<" HAS BALANCE->"<<balance<<endl<<endl;
}

//FUNCTION FOR CHECKING THE ACCOUNT EXISTANCE

int BankingSystem::check(long int x,BankingSystem *ob,int n)
{
	for(int i=0;i<n;i++)
	{
		if(ob[i].ret()==x)
			return x;
	}
	return 0;

}

//FUNCTION FOR GETTING ACCOUNT NUMBER OF A PARTICULAR RECORD

int  BankingSystem::ret()
{
	return account_number;
}

//FUNCTION FOR CHECKING THE ACCOUNT INFO

void BankingSystem::account_info()
{
		cout<<"HELLO "<<name<<endl<<"YOUR ACCOUNT NUMBER="<<account_number<<endl<<"TYPE OF ACCOUNT="<<type<<endl<<"HAS BALANCE="<<balance<<endl;
}

//FUNCTION FOR WITHDRAWING THE AMOUNT

int BankingSystem::withdraw()
{
			cout<<"HELLO "<<name<<" HAS BALANCE-> "<<balance<<endl<<" ENTER THE AMOUNT TO BE WITHDRAWN"<<endl;
			do{
				cin>>amount;
				try{
					if( amount == 0 )
           			 throw 0;
       			 }
        	catch(const int n)
				{
					cout << "\nWITHDRAW OF " << n << " is not allowed\n";
				}
			
				if(balance<amount)
					cout<<"INSUFFICIENT BALANCE"<<endl;
				else
					balance-=amount;
				cout<<"DO YOU WANT TO CONTINUE WITHDRAWING -Y/N"<<endl;
				cin>>ch;
			}while(toupper(ch)=='Y');
		cout<<"NEW BALANCE IS "<<balance<<endl;
		return amount;
}

//FUNCTION FOR DEPOSITING THE AMOUNT

int BankingSystem::deposit()
{
			cout<<"HELLO "<<name<<" HAS BALANCE-> "<<balance<<endl<<" ENTER THE AMOUNT TO DEPOSIT"<<endl;
			do{
				cin>>amount;
				balance+=amount;
				cout<<"DO YOU WANT TO CONTINUE DEPOSITING -Y/N"<<endl;
				cin>>ch;
			}while(toupper(ch)=='Y');
			
	cout<<"NEW BALANCE IS "<<balance<<endl;
	return amount;
}

//FUNCTION FOR CHECKING THE BALANCE INFO

void BankingSystem::balance_info()
{
			cout<<"HELLO "<<name<<" YOU HAS BALANCE-> "<<balance<<endl;
}

//MAIN FUNCTION DEFINED

int main(void)
{
		int wish,i=0,n=0,f=0;;
		char demand;
		ofstream fp;
		ifstream fp1;
			char c,u;
			 char filename[20];
		int amount;
		BankingSystem ob[100];
		long int tmp=ob[0].ret();
		do{
		    f=0;
			cout<<"\t\t\t"<<"WELCOME TO SECTION BANK OF SPAIN "<<endl<<endl;
			cout<<"PRESS 1 TO OPEN NEW ACCOUNT"<<endl;
			cout<<"PRESS 2 TO CHECK YOUR ACCOUNT INFO"<<endl;
			cout<<"PRESS 3 TO WITHDRAW AMOUNT"<<endl;
			cout<<"PRESS 4 TO DEPOSIT AMOUNT"<<endl;
			cout<<"PRESS 5 TO CHECK YOUR BALANCE INFO"<<endl;
			cout<<"PRESS 6 TO SEE YOUR LAST TRANSACTION"<<endl;
			cout<<"press 7 TO EXIT"<<endl;
			cout<<"ENTER YOUR WISH"<<endl;
			cin>>wish;
			switch(wish)
			{
				case 1:
					ob[i].open_new_account(n,ob);
					n=n+1;
					i=i+1;
					break;
				case 2:
				do{
					cout<<"ENTER YOUR ACCOUNT NUMBER"<<endl;
					cin>>tmp;
					for(int j=0;j<=n-1;j++){
						if(tmp==ob[j].ret()){
							ob[j].account_info();
							f=1;
							break;
					    }
					}
					if(f==0)
						cout<<"INVALID ACCOUNT NUMBER"<<endl;
					cout<<"DO YOU WANT TO CHECK OTHER ACCOUNT DETAILS -Y/N"<<endl;
			        cin>>demand;
			        }while(toupper(demand)=='Y');
						break;
				case 3:
						cout<<"ENTER YOUR ACCOUNT NUMBER"<<endl;
						cin>>tmp;
						for(int j=0;j<=n-1;j++)
						{
							if(tmp==ob[j].ret())
							{
								amount=ob[j].withdraw();
								
								f=1;
								fp.open("my_text.txt",fstream::app);
								fp << "withdraw="<<amount<<" "<<currentDateTime()<<endl;
								fp.close();
								f=1;
								break;
							}
						}
						if(f==0)
							cout<<"INVALID ACCOUNT NUMBER"<<endl;
						break;
				case 4:
						cout<<"ENTER YOUR ACCOUNT NUMBER"<<endl;
						cin>>tmp;
						for(int j=0;j<=n-1;j++){
							if(tmp==ob[j].ret())
							{
								amount=ob[j].deposit();
								f=1;
								fp.open("my_text.txt",fstream::app);
								fp << "deposite="<<amount<<" "<<currentDateTime()<<endl;
								fp.close();
							    break;
							}
						}
						if(f==0)
						cout<<"INVALID ACCOUNT NUMBER"<<endl;
						break;
				case 5:
				        do{
				    		cout<<"ENTER YOUR ACCOUNT NUMBER"<<endl;
						    cin>>tmp;
						    for(int j=0;j<=n-1;j++){
							    if(tmp==ob[j].ret()){
							    	ob[j].balance_info();
						    		f=1;
						    		break;
							    }
					    	}
				    		if(f==0)
					    		cout<<"INVALID ACCOUNT NUMBER"<<endl;
							cout<<"DO YOU WANT TO CHECK OTHER ACCOUNT DETAILS -Y/N"<<endl;
			            cin>>demand;
			            }while(toupper(demand)=='Y');
						break;
				

				case 6:
						cout<<"TRANSACTION"<<endl;
						cout<<"YOUR LAST TRANSACTION"<<endl;
						fp1.open("my_text.txt");
							while(fp1.good())
							{
								string line;
								getline(fp1,line);
								cout<<line<<endl;
							
							}
							break;
				case 7:
						cout<<"THANK YOU"<<endl;
						demand='N';
						break;
				default:
						cout<<"INVALID CHOICE";
						break;
			}
			cout<<"DO YOU WANT TO CONTINUE BANKING-Y/N"<<endl;
			cin>>demand;
		}while(toupper(demand)=='Y');
}
