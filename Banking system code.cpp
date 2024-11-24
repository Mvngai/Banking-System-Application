#include <iostream>
#include <string>

using namespace std;


class myBankAccount{
public:

    int operation;
    float balance=10000.00;      //Initializes a customer's balance as 10,000.
    float totalLoan=0.00;        //Initializes a customer's total loan borrowed as zero.
    float deposit;
    float withdraw;
    float amount;
    float loan;
    string accountNumber;


//Function for managing deposit operations
    void makeDeposit(){
        cout<< "How much would you like to deposit?  ";
        cin>> deposit;
        this->balance=this->balance+deposit;         //Updates balance by adding deposit
        cout<< "Deposit successful. Your new balance is: Shs." << this->balance<<endl;
    }

//Function for managing withdrawals
    void makeWithdrawal(){
        cout<< "How much would you like to withdraw?";
        cin>> withdraw;

            if(withdraw>balance){
                cout<< "You have insufficient balance to make this withdraw.";
            }else{
                this->balance=this->balance-withdraw;          //Updates balance by subtracting withdrawal
                cout<< "Withdrawal successful! Your new balance is: Shs." <<this->balance;
            }
    }

//Function for managing money transfer to another account
    void sendMoney(){
        cout<< "Enter a 15 character account number that you wish to send money to.\n";
        cin>> accountNumber;

            if(accountNumber.length() == 15){        //Checks if recipient account is 15 characters
                cout<< "How much would you like to send?\n";
                cin>>amount;

                    if(amount<= this->balance){        //Checks if balance is enough for making transfers
                cout<< "\nKsh." <<amount <<" has successfully been sent to account number " <<accountNumber <<endl;
                this->balance =this->balance-amount;        //Updates balance after making cash transfer
                cout<< "Your new account balance is Ksh." <<this->balance <<endl;
                    }else{
                cout <<"\nInsufficient Funds";
                    }
            }else{
                cout<< "Account Number entered is invalid!";
                }
    }

//Function that allows loan borrowing
    void getLoan(){
        cout<< "You are liable to borrow a loan not exceeding 30% of your account balance.\n";
        cout<< "Current loan limit: Ksh." <<balance*0.3;       //Displays the customer's loan limit
        cout<< "\n\nEnter loan amount you wish to get: ";
        cin>>loan;

            if(loan <= 0.3*balance){        //Checks whether loan limit is reached or not
                this->balance =balance+loan;       //Updates balance after loan is applied
                cout<< "\n\nLoan application successful!\nYour new account balance is: Shs" <<balance;
                this->totalLoan= totalLoan +loan;        //Displays the customers total loan borrowed
                cout<<"\nYou have borrowed a total of Ksh. " <<totalLoan <<" of loan";
            }else{
                cout<< "Loan application denied!\n";
                }
    }

//Function to check a customer's account balance
    void checkBalance(){
        cout<< "Your account balance is: Shs" <<balance;
    }
};


int main(){
    myBankAccount myOperations;

    bool run=true;

//Do-while loop to loop main function indefinitely until the user terminates it.
    do{

    cout<< "\n\n\n*** Welcome to your Bank Account.***\n";
    cout<< "Your Account Number is: A/\c 12903.\n";
    cout<< "Your Account balance is Shs." <<myOperations.balance <<endl <<endl;
    cout<< "        *****MENU*****\n\n";
    cout<< "1. Make a Deposit.\n";
    cout<< "2. Make a Withdrawal.\n";
    cout<< "3. Apply for a loan.\n";
    cout<< "4. Send Money to Another Account.\n";
    cout<< "5. Check your Account Balance.\n";
    cout<< "6. Exit.\n\n";

    cout<< "Select an operation: ";
    cin>>myOperations.operation;


    //Switch statements to call required functions to handle main operation.
            switch(myOperations.operation){
            case 1:
                myOperations.makeDeposit();
            break;
            case 2:
                myOperations.makeWithdrawal();
            break;
            case 3:
                myOperations.getLoan();
            break;
            case 4:
                myOperations.sendMoney();
            break;
            case 5:
                myOperations.checkBalance();
            break;
            case 6:     //To terminate the program and stop the do-while loop.
                cout<<"\n***Come back again.***\n\n\n";
                exit (0);
            default:
                cout<<"Invalid operation selected!";
            }
        }while(1);
return 0;
}
