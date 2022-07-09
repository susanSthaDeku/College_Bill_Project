#include <iostream>
#include<string.h>
#include<ctime>
using namespace std;
class Calc_Ebill
{
int cus_Id;
char cus_Name[50];
int units;
double bill_Bal;
 int bal;
public:
    int balance()
    {
        cout<<"Enter the Total balance :"<<endl;
        cin>>bal;
        return(bal);
    }
    void get()
    {
        cout << "Please enter detail of customer below: \n" << endl;
        cout << "Enter customer id: " << endl;
        cin>>cus_Id;
        cout << "Enter customer Name: " << endl;
        cin>>cus_Name;
    }
    void put()
    {
        cout << "            Customer Details         " << endl;
        cout << "       -+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+       \n       " << endl;
        cout << "Customer id     : " <<cus_Id<<endl;
        cout << "----------------------------------" << endl;
        cout << "Customer Name   : " <<cus_Name<<endl;
        cout << "----------------------------------" << endl;           
        cout << "Unit            : " <<units<<endl;
        cout << "----------------------------------" << endl;
        cout << "Amount          : " << bill_Bal<<endl;
        cout << "----------------------------------" << endl;
        cout << "Tax amount      : " << bill_Bal*13/100<<endl;
        cout << "----------------------------------" << endl;
        cout << "Total amount    : " << bill_Bal*113/100<<endl;
        cout<<"\nPress enter to continue........."<<endl;
        cin.ignore();
             cin.get();
    }
    /*1 - 100 = Rs 5
    101 - 200 = Rs 6
    201 - 300 = Rs 7
    above 300 - Rs 8*/
    void calc_Amt()
    {
        cout << "Enter the number of units consumed: " << endl;
        cin>>units; 
        if(units<=100)
            bill_Bal=units*5;
        else if(units<=200)
            bill_Bal=100*1+(units-100)*6;
        else if(units<=300)
            bill_Bal=100*1+100*2+(units-200)*7;
        else if(units>300)
            bill_Bal=100*1+100*2+100*3+(units-300)*8;
    }
    friend int payment(Calc_Ebill b);
};
   int payment(Calc_Ebill b)
    {
        char pay1[10];
        if(b.bal>=b.bill_Bal)
        {
            cout<<"Would you like to do payment(Y/N):";
            cin>>pay1;
            if((strcmp(pay1,"Y")==0)||(strcmp(pay1,"y")==0))
            {
                b.bal= b.bal-b.bill_Bal; 
                time_t now =time(0);
                char*dt =ctime(&now);
                cout<<"\nPayment was issued on :"<<endl<<dt;
                cout<<"\nRemaining balance :"<<b.bal<<endl;  ;
            }
        }
        else
        {
           cout<<"\n***Insufficent Balance***"<<endl;
        }
        cout<<"\npress enter to continue........."<<endl;
        cin.ignore();
        cin.get();
       
    }

int main()
{
    system("cls");
    Calc_Ebill b;
    int bal1;
    char pass[10],pass1[10];
    char userr[15],user1[15];
    cout<<"-----------------WELCOME TO SMART PAYMENT--------------\n";
    cout<<"\n Press enter to continue.......";
    cin.get();
    system("cls");


    cout<<"-+-+-+-+-  REGISTER  -+-+-+-+-\n"<<endl;
    cout<<"Enter the user name :"<<endl;
    cin>>userr;
    cout<<"Enter the password:"<<endl;
    cin>>pass;
    bal1=b.balance();
    system("cls");
    cout<<"User ID Created Successfully.........  "<<endl;

    system("cls");
    cout<<"------  LOGIN   -----\n"<<endl;

    cout<<"Username:"<<endl;
    cin>>user1;
    if(strcmp(userr,user1)==0 )
    {
        cout<<"Password :"<<endl;
        cin>>pass1;
        system("cls");
        if(strcmp(pass,pass1)==0 )
        {
            cout<<"        * * * * * * Login sucessfull * * * * *"<<endl;
             cin.ignore();
             cout<<"\n Press enter to continue...";
             cin.get();
            system("cls");
            int choice=1;
            while(choice!=5)
            {
            
                cout<<"\n **********************************  ";
                cout<<"\n      Electricity Bill Generator ";
                cout<<"\n ********************************** \n ";
                cout<<"User name:"<<user1<<"                 Total balance :";
                  cout<<bal1<<endl;
                
                cout<<"\n  MAIN MENU  ";;
                cout<<"\n  1. Customer Entry  "; 	
                cout<<"\n  2. Generate Bill  ";
                cout<<"\n  3. Display bill  ";
                cout<<"\n  4. Payment  ";
                cout<<"\n  5. EXIT ";
                cout<<"\n Enter your choice :    ";
                scanf("%d",&choice);
                system("cls");
                switch(choice)
            {
                    case 1: b.get();
                    cout<<        "successfull"<<endl;
                     system("cls");
                            break;
                    case 2: b.calc_Amt();
                     system("cls");

                            break;        
                    case 3: b.put();
                     system("cls");

                            break;
                    case 4:
                    payment(b);
                     system("cls");

                            break;
                    case 5: cout<<"\nThank you....!!!\n";
                            break;	  	  
                    default:{
                        cout<<"\n\n  Invalid Choice...!";
                        cout<<"\n\n Please Try Again ...";
                                cin.ignore();
             cout<<"\n Press enter to continue...";
             cin.get();
                     system("cls");
             system("cls");
                    } 
                }
            }
        }
        else
        {
            cout<<"invalid password 🙁"<<endl;
        }
    }
    else
    {
        cout<<"Invalid username 🙁"<<endl;
    }
    return 0;
}