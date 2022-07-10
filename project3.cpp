#include <iostream>
#include<string.h>
#include<ctime>
using namespace std;
// Class to create Commit
class Calc_Ebill
{
int cus_Id;
char cus_Name[100];
int units;
double bill_Bal;
 int bal,tax;
public:
// Gives user total balance
    int balance()
    {
        cout<<"Enter the Total balance :"<<endl;
        cin>>bal;
        return(bal);
    }

    // Takes customer info
    void get()
    {
        cout << "Please enter detail of customer below: \n" << endl;
       
        cout << "Enter customer id: " << endl;
        cin>>cus_Id;
         cout << "Enter customer Name: " << endl;
        gets(cus_Name);
       
    }
// Displays customer bill amount
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
    /*1 - 100 = 5
    101 - 200 = 6
    201 - 300 = 7
    above 300 - 8*/

    // Caluclates the  bill 
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
            tax=bill_Bal*113/100;
    }
    // Friend funcion for payment
    friend int payment(Calc_Ebill b);
};

// Returns the balance
   int payment(Calc_Ebill b)
    {
        char pay1[10];
        if(b.bal>=b.tax)
        {
            cout<<"Would you like to do payment(Y/N):";
            cin>>pay1;
            if((strcmp(pay1,"Y")==0)||(strcmp(pay1,"y")==0))
            {
               b.bal= b.bal-b.tax; 
                   time_t now =time(0);
                        char*dt =ctime(&now);
                        cout<<"THIS PAYMENT WAS SUCCESSFULL ON:"<<dt<<endl;
                        cout<<"Remaining balance :"<<b.bal  ;
                        return b.bal;
                           cin.ignore();
        cout<<"\npress enter........."<<endl;
     
             cin.get();
             system("cls");
            }
        }
        else
        {
           cout<<"\n***Insufficent Balance***"<<endl;
           return b.bal;
           cin.ignore();
           cout<<"\npress enter........."<<endl;
     
             cin.get();
             system("cls");
        }
           
        
       
    }

int main()
{ system("cls");
    Calc_Ebill b;
    int bal1;
    char pass[100],pass1[100];
    char userr[100],user1[100];
    cout<<"-----------------WELCOME TO SMART PAYMENT--------------\n";
    cout<<"\n Press enter to continue.......";
    cin.get();
    system("cls");
    cout<<"-+-+-+-+-  REGISTER  -+-+-+-+-\n"<<endl;
    cout<<"Enter the user name :"<<endl;
    gets(userr);
  
    cout<<"Enter the password:"<<endl;
    gets(pass);
  
    system("cls");
    cout<<"User ID Created Successfully.........  "<<endl;

    system("cls");
    cout<<"------  LOGIN   -----\n"<<endl;

    cout<<"Username:"<<endl;
     gets(user1);
    if(strcmp(userr,user1)==0 )
    {
        cout<<"Password :"<<endl;
        gets(pass1);
          
        bal1=b.balance();
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
            cout<<"invalid password !!!!!!!!!!!"<<endl;
        }
    }
    else
    {
        cout<<"Invalid username !!!!!!!!"<<endl;

    }
    return 0;
}

