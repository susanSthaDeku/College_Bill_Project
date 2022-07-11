#include<iostream>
#include <fstream> 
#include <iomanip> 
using namespace std;
int main()
{
       string Name;
       string surname;
       int account_no;
       string Location;
       int OpeningMReading,x;
       int ClosingMReading,;
       double outStandingBalance,i,j,m,l,std_charge,total,monthlyBill,OutStandingPeecent,VAT,amoutDue,bm,mw;
     ofstream outClientFile( "MASERU.doc", ios::out );
     ofstream outClientFiles( "MAFETENG.doc", ios::out );
     ofstream outClientFile1( "BILLS.txt", ios::out );
     ofstream outClientFile2( "DEFAULERS.txt", ios::out );
    if ( !outClientFile )
    {
    cerr << "File could not be opened" << endl;
       exit( 1 );
    }
    else if(!outClientFiles)
    {
         cerr<<"File could not be opened"<<endl;
         }
   else if(!outClientFile1)
    {
         cerr<<"File could not be opened"<<endl;
         }
         else if(!outClientFile2)
    {
         cerr<<"File could not be opened"<<endl;
        }
cout<<"Enter\n    Account no\n    Name\n    Surname\n    Location\n    Opening meter readings\n    Closing meter readings and\n    Outstatnig balance\n";
outClientFile2<<left<<setw(13)<<"Name"<<setw(13)<<"Surname"<<setw(13)<<"Acount_No"<<setw(13)<<"Location"<<setw(13)<<"Open-M-read"<<setw(13)<<"Close-M-read"<<setw(13)<< right<<"OutstandingBalance\n\n";
outClientFile1<<left<<setw(13)<<"Name"<<setw(13)<<"Surname"<<setw(13)<<"Acount_No"<<setw(13)<<"Location"<<setw(13)<<"Open-M-read"<<setw(13)<<"Close-M-read"<<setw(13)<< right<<"OutstandingBalance\n\n";
while(cin>>account_no>>Name>>surname>>Location>>OpeningMReading>>ClosingMReading>>outStandingBalance)
 {                                                                                                        x = ClosingMReading - OpeningMReading;
    if(Location=="Maseru")
     {
          std_charge=10.00 ;                
      i =0.25*90;
      j=(x-90)*0.35;
      bm=i+j;
     monthlyBill=bm+std_charge;
     }
     else if(Location=="Mafeteng")
      {
           std_charge=10.00 ;
      m =0.20*100;
      l=(x-100)*0.25;
      mw=m+l;
     monthlyBill=mw+std_charge;
    }


  OutStandingPeecent=(10/100.00)*outStandingBalance;
total=  monthlyBill+ outStandingBalance+ OutStandingPeecent;
VAT=(10/100.00)*total;
amoutDue=VAT+total;

if((Location=="Maseru")&&(outStandingBalance>=150.00))
{
   outClientFile<<"===================================================\n";
   outClientFile<<"WELCOME YOUR COMPANY WATER AND SAWAGE AUTHORITY";
   outClientFile<<"\n===================================================";
   outClientFile<<"\n\nACCOUNT NO:          \t\t"<<account_no<<"\n\nCLIENT'S NAME:        \t\t"<<Name<<" "
   <<surname<<"\n\nLOCATION:            \t\t"<<Location<<"\n\nUNIT USED:           \t\t"
   <<setprecision( 2 ) << fixed <<x<<"\n\nUSAGE:              \t\tM"<<i+j<<"\nSTANDARD CHARGE:      \t\tM"<< setprecision( 2 ) << fixed <<std_charge<<"\nMONTLY BILL:           \tM"
   <<monthlyBill<<"\n\nOUTSTANDING BALANCE:    \tM"<< setprecision( 2 ) << fixed <<outStandingBalance<<"\n10%OUTSTANDING BALANCE:\tM"
   << setprecision( 2 ) << fixed <<OutStandingPeecent<<"\n\nTOTAL:            \t\tM"<< setprecision( 2 ) << fixed <<total<<"\n10% VAT:              \t\tM"
   << setprecision( 2 ) << fixed <<VAT<<"\n\nAMOUNT DUE:       \t\tM"<< setprecision( 2 ) << fixed <<amoutDue<<"\n\n"
    <<"\n\n\nFailure to Pay "<<setprecision( 2 )<<fixed<<outStandingBalance
   <<" within 30 days will result in water disconnection\n"
   <<"===================================================\n\n\n";
  }
else if((Location=="Mafeteng")&&(outStandingBalance>=150.00))
{
   outClientFiles<<"===================================================\n";
   outClientFiles<<"WELCOME YOUR COMPANY WATER AND SAWAGE AUTHORITY";
   outClientFiles<<"\n===================================================";
   outClientFiles<<"\n\nACCOUNT NO:        \t\t"<<account_no<<"\n\nCLIENT'S NAME:      \t\t"<<Name<<" "<<surname
   <<"\n\nLOCATION:         \t\t"<<Location<<"\n\nUNIT USED:         \t\t"<<setprecision( 2 ) << fixed <<x<<"\n\nUSAGE:            \t\tM"<<m+l
   <<"\nSTANDARD CHARGE:  \t\tM"<<std_charge<<"\nMONTLY BILL:           \tM"<<monthlyBill<<"\n\nOUTSTANDING BALANCE:    \tM"
   <<outStandingBalance<<"\n10%OUTSTANDING BALANCE:\tM"<<OutStandingPeecent<<"\n\nTOTAL:            \t\tM"<<total<<"\n10% VAT:             \t\tM"
   <<VAT<<"\n\nAMOUNT DUE:       \t\tM"<<amoutDue<<"n"
   <<"\n\n\nFailure to Pay "<<setprecision( 2 )<<fixed<<outStandingBalance
   <<" within 30 days will result in water disconnection\n"
   <<"===================================================\n\n\n";
} 
else if((Location=="Maseru")&&(outStandingBalance<150.00))
{
   outClientFile<<"===================================================\n";
   outClientFile<<"WELCOME YOUR COMPANY WATER AND SAWAGE AUTHORITY";
   outClientFile<<"\n===================================================";
   outClientFile<<"\n\nACCOUNT NO:          \t\t"<<account_no<<"\n\nCLIENT'S NAME:        \t\t"<<Name<<" "
   <<surname<<"\n\nLOCATION:            \t\t"<<Location<<"\n\nUNIT USED:           \t\t"
  <<setprecision( 2 ) << fixed<<x<<"\n\nUSAGE:              \t\tM"<<setprecision( 2 )<<fixed<<bm<<"\nSTANDARD CHARGE:      \t\tM"<<setprecision( 2 )<<fixed<<std_charge<<"\nMONTLY BILL:           \tM"
   <<setprecision( 2 )<<fixed<<monthlyBill<<"\n\nOUTSTANDING BALANCE:    \tM"<<setprecision( 2 )<<fixed<<outStandingBalance<<"\n10%OUTSTANDING BALANCE:\tM"
   <<setprecision( 2 )<<fixed<<OutStandingPeecent<<"\n\nTOTAL:            \t\tM"<<setprecision( 2 )<<fixed<<total<<"\n10% VAT:              \t\tM"
   <<setprecision( 2 )<<fixed<<VAT<<"\n\nAMOUNT DUE:       \t\tM"<<setprecision( 2 )<<fixed<<amoutDue<<"\n\n"
   <<"===================================================\n\n\n";
  }
else if((Location=="Mafeteng")&&(outStandingBalance<150.00))
{
   outClientFiles<<"===================================================\n";
   outClientFiles<<"WELCOME YOUR COMPANY WATER AND SAWAGE AUTHORITY";
   outClientFiles<<"\n===================================================";
   outClientFiles<<"\n\nACCOUNT NO:        \t\t"<<account_no<<"\n\nCLIENT'S NAME:      \t\t"<<Name<<" "<<surname
   <<"\n\nLOCATION:         \t\t"<<Location<<"\n\nUNIT USED:         \t\t"<<setprecision( 2 ) << fixed <<x<<"\n\nUSAGE:            \t\tM"<<setprecision( 2 )<<fixed<<mw
   <<"\nSTANDARD CHARGE:  \t\tM"<<setprecision( 2 )<<fixed<<std_charge<<"\nMONTLY BILL:           \tM"<<setprecision( 2 )<<fixed<<monthlyBill<<"\n\nOUTSTANDING BALANCE:    \tM"
   <<setprecision( 2 )<<fixed<<outStandingBalance<<"\n10%OUTSTANDING BALANCE:\tM"<<setprecision( 2 )<<fixed<<OutStandingPeecent<<"\n\nTOTAL:            \t\tM"<<setprecision( 2 )<<fixed<<total<<"\n10% VAT:             \t\tM"
   <<setprecision( 2 )<<fixed<<VAT<<"\n\nAMOUNT DUE:       \t\tM"<<setprecision( 2 )<<fixed<<amoutDue<<"\n\n"
   <<"===================================================\n\n\n";
} 
else
cout<<"unknown Location\n";
if((Location=="Maseru")||(Location=="Mafeteng"))
{
outClientFile1<<left<<setw(13)<<Name<<setw(13)<<surname<<setw(13)<<account_no<<setw(13)<<Location<<setw(13)<<OpeningMReading<<setw(13)<<ClosingMReading<<setw(13)<< setprecision( 2 ) << fixed<<outStandingBalance<<endl;
}
if(outStandingBalance>=150.00)
{
outClientFile2<<left<<setw(13)<<Name<<setw(13)<<surname<<setw(13)<<account_no<<setw(13)<<Location<<setw(13)<<OpeningMReading<<setw(13)<<ClosingMReading<<setw(13)<< setprecision( 2 ) << fixed<<outStandingBalance<<endl;
}
}
system("Pause");
return 0;
}
