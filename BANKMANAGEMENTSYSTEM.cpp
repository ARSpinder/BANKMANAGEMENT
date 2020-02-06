#include<iostream>
#include<iomanip>
#include<fstream>
using namespace std;
fstream myfile;
struct node
{

string name;
int Account;
int Address;
int Deposit;
node*next;
 node()
 {
 next=NULL;
 }
};
class bank_Management
{
//pointers to handle the linklist
node *head,*tail,*temp;
public:

bank_Management()
{
 head=NULL;
}
//function to create nodes
void account (string n,int a,int ad, int de)
{
 //create 1st node...
 if(head==NULL)
 {
 head=new node;
 head->next=NULL;
 head->name=n;
 head->Account=a;
 head->Address=ad;
 head->Deposit=de;

myfile.open ("bank_Management.txt",ios::out | ios::app);
myfile<<"Name_:_"<<head->name<<"__|__ACCOUNT:_"<<head->Account<<"__|__ADDRESS_:_"<<head->Address<<"__|__DEPOSIT_:_"
<<head->Deposit;
myfile.close();
 }
 //to create new node..
 else
 {
 tail=head;
 while(tail->next!=NULL)
 {
 tail=tail->next;
 }
 temp=new node;
 temp->name=n;
 temp->Account=a;
 temp->Address=ad;
 temp->Deposit=de;
temp->next=NULL;
 tail->next=temp;
 myfile.open ("bank_Management.txt",ios::out | ios::app);

myfile<<"Name_:_"<<temp->name<<"__|__ACCOUNT:_"<<temp->Account<<"__|__ADDRESS_:_"<<temp->Address<<"__|__DEPOSIT_:_"
<<temp->Deposit;
myfile.close();
 }
 }
void Delete_account(string n)
 {
 tail=head;
 if(head->name==n)
 {
 temp=head;
 head=head->next;
 delete temp;
 }
 else
 {
 while(tail->name!=n)
 {
 if(tail->next==NULL)
 {

 cout<<"Any case of"<<n<<" does not exist"<<endl;
 return ;
 }
 temp=tail;
 tail=tail->next;
 }
 temp->next=tail->next;
 delete tail;
 }

}
void print_now()
{
tail=head;
int c;
cout<<"Name "<<" ---> ACCOUNT \tADDRESS \tDeposit"<<endl;
for(c=1;tail->next!=NULL;c++)
{
cout<<"NAME "<<c<<" ---> "<<tail->name<<"\t"<<tail->Account<<"\t"<<tail->Address<<"\t"<<tail->Deposit<<endl;
tail=tail->next;
}
cout<<"NAME "<<c<<" ---> "<<tail->name<<"\t"<<tail->Account<<"\t"<<tail->Address<<"\t"<<tail->Deposit<<endl;
}

void search(string n)
{
tail=head;
while(tail!=NULL)
{
if(tail->name==n)
{
char mod;
cout<<"\n\t_________DATA FOUND__________\n\n";
cout<<"Name : "<<tail->name<<endl;
cout<<"ACCOUNT : "<<tail->Account<<endl;
cout<<"ADDRESS : "<<tail->Address<<endl;
cout<<"\nDo You want to modify Phone Number (y/n) : ";
cin>>mod;
if(mod=='y' || mod=='Y')

{
cout<<"Enter YOUR NAME ";
cin>>tail->name;
cout<<"Enter YOUR ADDRESS ";
cin>>tail->Address;
cout<<"Enter YOUR MONEY ";
cin>>tail->Deposit;
cout<<"\n\t_________Data Updated________"<<endl;
}
break;
}
tail=tail->next;
}
if(tail==NULL)
cout<<"\n\t_______DATA NOT FOUND_________\n\n";
}
void print()
{
//this function reads the data from file
string s;
myfile.open("bank_Management.txt",ios::in);
while(!myfile.eof())
{
myfile>>s;

cout<<s<<endl;
}
myfile.close();
}



};


// ATCM Class
/*class stack
{
             int arry[100];
             int top;
      public:
             stack()
              {
                top=-1;
               }
             int push(int x)
              {
                 if(top >  100)
                       {
                           cout <<"stack over flow";
                           return x;
                       }
                 arry[++top]=x;
                 cout <<"inserted" <<x;
               }

             void pop()
               {
                  if(top <0)
                   {
                         cout <<"stack under flow";
                         return;
                    }
                    cout <<"deleted" <<arry[top--];
                }
             void display()
               {
                   if(top<0)
                    {
                            cout <<" stack empty";
                            return;
                    }
                    for(int i=top;i>=0;i--)
                    cout <<arry[i] <<" ";
                }

};
*/

// MAin FUNCTION
int main()
{
 bank_Management obj;
// stack obj1;
int i,p,ch;
string n;
int a,ad,de;
int Na;
char user;

cout<<setw (50)<<"BANK MANAGEMENT SYSTEM 2020 "<<endl;
cout<<endl;
cout<<endl;
cout<<"[A] TO BANK MANAGEMENT SYSTEM "<<endl;
cout<<"[B] TO GO TO ATM MANAGEMENT SYSTEM"<<endl;
cout<<endl;

cin>>user;

if (user=='a' || user=='A')

{

  do
  {
    cout<<setw (50)<<"BANK MANAGEMENT SYSTEM 2020 "<<endl;
    cout<<endl;
    cout<<endl;
    cout<< setw (20)<<"[1] Create A NEW ACCOUNT"<<endl;
    cout<<setw (20)<< "[2] DELETE OR CLOSE YOUR ACCOUNT "<<endl;
    cout<<setw (20)<< "[3] SEARCH AND MODIFY YOUR ACCOUNT "<<endl;
    cout<<setw (10)<< "[4] SELL ALL ACCOUNT LIST "<<endl;
    cout<<setw (5)<< "[5] EXIT"<<endl;
    cout<< setw (20)<< "Select Your Option (1-4): "<<endl;
  cin>>ch;
  switch(ch)
  {
   case 1:
  cout<<"\n\t============CREATING A NEW  ACCOUNT============================\n\n";
   cout<<"Enter DATA To OPEN A NEW ACCOUNT'"<<endl;
   cout<<"\nPlease Enter Your Full Name \t";
   cin>>n;
   cout<<"\nEnter Your Account Number \t";
   cin>>a;
   cout<<"Please Enter Full Address \t";
   cin>>ad;
   cout<<"Please Enter Money to  Deposit \t";
   cin>>de;
   obj.account(n,a,ad,de);
   cout<<"Your Account "<<n<<" has been Created "<<endl;
   break;
   case 2:
  cout<<"\n\t============DELETE YOUR ACCOUNT============================\n\n";
   cout<<"\nEnter name of person whose ACCOUNT you want to delete\n"<<endl;
   cin>>n;
   obj.Delete_account(n);
   cout<<"YOUR ACCOUNT "<<n<<" Has been removed from OUR list"<<endl;
   break;
   case 3:
  cout<<"\n\t============-> SEARCH AND MODIFY YOUR ACCOUNT <-=========================\n\n";
   cout<<"Enter NAME of Person to search it from list\t";

   cin>>n;
   obj.search(n);
   break;
  case 4:
  cout<<"\n\t============-> SEE ALL LIST <-=========================\n\n";
   obj.print();
    break;


   default:
   cout<<"\t----------Invalid----------"<<endl;
  }
  }
  while(ch!=5);
  cout<<"\nTHANK YOU"<<endl;
}
/*

else if (user=='b' || user=='B')
{

  int atmm;
  int s;

          cout <<"\n1.TO ENTER ATM ADDRESS"<<endl;
          cout<<" 2.WIDHDRWL MONEY"<<endl;
          cout<<" 3.CHANGE PIN "<<endl;
          cout<<" 4.DISPLAY YOUR ACCOUNT DETAIL"<<endl;

          cout<<"Enter ur choice"<<endl;
          cin >> atmm;

          obj1.push(1548);
          obj1.push(1547);
          switch(atmm)
           {
            case 1:  cout <<"Enter ACCOUNT ADDRESS"<<endl;
                     cin >> s;
                    // obj1.search();
                     cout<<"s";






                     break;

            //case 2:  st.pop();  break;
            //case 3:  st.display();break;
            case 4:  exit(0);
            }


}
*/
}
