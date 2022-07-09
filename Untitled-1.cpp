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
        cout << "\n            Customer Details          \n" << endl;
        cout << "\nCustomer id : " <<cus_Id<<endl;
        cout<<"\nCustomer Name :" <<cus_Name<<endl;           
        cout << "\n  Unit      : " <<units<<endl;

        cout << "\n amount     : " << bill_Bal<<endl;
        cout << "\nTax amount  : " << bill_Bal*13/100<<endl;
        cout << "\ntotal amount: " << bill_Bal*113/100<<endl;
        
       
        cout<<"press enter........."<<endl;
        cin.ignore();
             cin.get();
    }
    /*1 - 100 = 5
    101 - 200 = 6
    201 - 300 = 7
    above 300 - 8*/
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
    friend void payment(Calc_Ebill b);
};
   int payment(Calc_Ebill b)
    {
        char pay1[10];
        int bal1,temp;
        if(b.bal>=b.bill_Bal)
        {
            cout<<"Would you like to do payment(Y/N):";
            cin>>pay1;
            if((strcmp(pay1,"Y")==0)||(strcmp(pay1,"y")==0))
            {
               bal1= b.bal-b.bill_Bal; 
                   time_t now =time(0);
                        char*dt =ctime(&now);
                        cout<<"THIS PAYMENT WAS SUCCESSFULL ON:"<<dt<<endl;
                        cout<<"Remaining balance :"<<bal1  ;
                        temp=b.bal;
                        b.bal=bal1;
                        bal1=temp;
                        swap(b.bal,bal1 );
                        return bal1;
            }
        }
        else
        {
           cout<<"\n***Insufficent Balance***"<<endl;
           return b.bal
        }
        
        cout<<"\npress enter........."<<endl;
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
             printf("\n Press enter to continue...");
             cin.get();
    system("cls");


    cout<<"-+-+-+-+-  REGISTER  -+-+-+-+-\n"<<endl;
    cout<<"Enter the user name :"<<endl;
    cin>>userr;
    cout<<"Enter the password:"<<endl;
    cin>>pass;
    bal1=b.balance();
    system("cls");
    cout<<"User Id Created  Successfully...........................  "<<endl;

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
            cout<<"*****Login sucessfull*****"<<endl;
             cin.ignore();
             printf("\n Press enter to continue...");
             cin.get();
            system("cls");
            int choice=1;
            while(choice!=5)
            {
            
                printf("\n ************************************  ");
                printf("\n      Electricity Bill Calculator");
                printf("\n ************************************ \n ");
                cout<<"User name:"<<user1<<"                 Total balance :";
                  cout<<bal1<<endl;
                
                printf("\n  MAIN MENU  ");
                printf("\n  1. Customer Entry  "); 	
                printf("\n  2. Generate Bill  ");
                printf("\n  3. Display bill  ");
                printf("\n  4. Payment  ");
                printf("\n  5. EXIT ");
                printf("\n Enter your choice :    ");
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
                     bal1=payment(b);
                     system("cls");

                            break;
                    case 5: break;	  	  
                    default:{
                        printf("\n\n  Invalid Choice...!");
                        printf("\n\n Please Try Again ...");
                                cin.ignore();
             printf("\n Press enter to continue...");
             cin.get();
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

