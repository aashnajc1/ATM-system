#include <iostream>
#include<conio.h> // c programming header
#include<string>
using namespace std;

class atm{
    
private:
    long int accountno;
    string name;
    int PIN;
    double balance;
    string mobileno;
public:
   void setdata(long int Accountno, string Name, int pin, double Balance, string MobileNo)
   {
       accountno = Accountno;
       name = Name;
       PIN = pin;
       balance = Balance;
       mobileno = MobileNo;
   }
   long int getaccountno()
   {
       return accountno;
   }
   string getName()
   {
       return name;
   }
   int getPin()
   {
       return PIN;
   }
   double getBalance()
   {
       return balance;
   }
   string getMobileno()
   {
       return mobileno;
   }
   void setnewnumber(string prevnum, string newnum)
   {
        if(prevnum==mobileno){
            mobileno = newnum;
            cout<< "Mobile number updated succesfully to " << mobileno << endl;
            getch();
        }
   }
   void cashwithdrawal(int amount){
      
       if(amount > 0 && amount < balance)
       {
           balance -= amount;
           cout << "Please collect your cash" << endl;
           cout << "Available balance : " << balance << endl;
           getch();
       }
       else{
           cout << endl << "Invalid input or insufficeint balance ";
       }
   }
    
};

int main()
{
    int choice = 0, enterpin, number;
    long int enteraccno;
    
    atm user1;
    user1.setdata(1234, "Aashna", 4576, 14598.00, "9661358965");
    
        cout<< "Enter your account no"<<endl;
        cin>> enteraccno;
        cout<<"Enter PIN" << endl;
        cin>> enterpin;
        if((enteraccno==user1.getaccountno()) && (enterpin==user1.getPin()))
        {
            int amount = 0;
            string oldno, newno;
            cout << "Select options" << endl;
            cout << "1.Check Balance"<< endl;
            cout << "2.Cash Withdraw" << endl;
            cout << "3.Show User Details" << endl;
            cout << "4.Update Mobile No." << endl;
            cout << "5. Exit" << endl;
            cin >> choice;
            
            switch(choice)
            {
                case 1 :
                   cout << "Your bank balance is " << user1.getBalance() << endl;
                   break;
                case 2:
                   cout << "Enter the amount you want to withdraw :" << endl;
                   cin >> amount;
                   user1.cashwithdrawal(amount);
                   break;
                case 3:
                   cout << "Account number : " << user1.getaccountno() << endl;
                   cout << "Name : " << user1.getName() <<endl;
                   cout << "Balance : " << user1.getBalance() <<endl;
                   cout << "Mobile Number : " << user1.getMobileno() << endl;
                   break;
                case 4:
                   cout << "Enter old Mobile Number : " << endl;
                   cin >> oldno;
                   cout << "Enter new Mobile Number : " << endl;
                   cin >> newno;
                   user1.setnewnumber(oldno, newno);
                   break;
                case 5:
                   exit(0);
                default:
                   cout << endl << "Enter valid input "<< endl;
            }
            
        }


    return 0;
}
