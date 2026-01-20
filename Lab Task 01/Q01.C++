#include<iostream>//header file
using namespace std;//standard namespace
class BankAccount{  //class definition
    int balance;    //initially private member
    public://making public members
    //default constructor
    BankAccount(){  
        balance=100; //initializing balance to 100
    }
    //parameterized constructor
    BankAccount(int b){ 
        balance=b;
    }   
    //copy constructor
    BankAccount(BankAccount &obj){
        balance=obj.balance;
    }
    //Withdraw function
    void withdraw(int amount){
        balance-=amount;
    }
    //Display function
    void displayBalance(){
        cout<<"Balance: "<<balance<<endl;
    }
    
};
int main(){ //main function
    BankAccount account1; //calling default constructor
    account1.displayBalance(); //displaying balance for account1
    BankAccount account2(1000); //calling parameterized constructor
    account2.displayBalance();//displaying balance for account2
    BankAccount account3(account2);//calling copy constructor
    account3.withdraw(200);//withdrawing 200 from account3
    account3.displayBalance();//displaying balance for account3
    account2.displayBalance();//displaying balance for account2 to show it's unchanged
    return 0;//returning 0
}