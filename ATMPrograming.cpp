#include<iostream>
#include<fstream>
#include<time.h>

using namespace std;

void Menu();
void Register(string &username, string &password);
void Log_in(string &username, string &password);
bool Bool_log_in(string &username, string &password);
void Exit();
void Start_accountbalance(string &username, int &accountbalance);
void Main_menu();
void Deposit(string &username, int &accountbalance);
void Withdraw(string &username, int &accountbalance);
void History(string &username);
void Log_out(string username, int accountbalance);

int main()
{
    int choice;
    Menu();
    cin>>choice;
    int accountbalance;
    string username,password;
    if(choice==1)
    {
        system("cls");
        Register(username,password);
    }
    else if(choice==2)
    {
        system("cls");
        Log_in(username,password);
    }
    else if(choice==3)
    {
        system("cls");
        Exit();
    }
    else
    {
        cout<<"Your input is not available. Press 0 to try again!!!\n";
        do
        {
            cin>>choice;
            cout<<"Your input is not available. Press 0 to try again!!!\n";
        }
        while(choice!=0);
        system("cls");
        main();
    }
    //cout<<username<<'\n';

    //cout<<accountbalance;
    Start_accountbalance(username, accountbalance);
    Main_menu();
    int option;
    do
    {
        cin>>option;
        switch(option)
        {
        case 1:
            system("cls");
            Deposit(username, accountbalance);
            break;
        case 2:
            system("cls");
            Withdraw(username, accountbalance);
            break;
        case 3:
            system("cls");
            History(username);
            break;
        case 0:
            system("cls");
            Log_out(username, accountbalance);
            break;
        default:
            cout<<"Please Enter the Correct Number Choice"<<endl;
        }
    }
    while(option!=0);
    return 0;
}

void Menu()
{
    cout << endl << "\n\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb WELCOME TO ATM Banking \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n" << endl << endl;
    cout << "\t\tEnter[1]"<<' '<<"Register\n";
    cout << "\t\tEnter[2]"<<' '<<"Log in\n";
    cout << "\t\tEnter[3]"<<' '<<"Exit ATM\n\n";
    cout<<"\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n\n";
    cout << "\tPLEASE ENTER A SELECTION AND PRESS RETURN KEY: \n\n";
}

void Register(string &username, string &password)
{
    string un;
    int choice;
    cout<< "select a username: ";
    cin>>username;
    ifstream read("E:\\1Account\\"+username+".txt");
    getline(read, un);
    if(username==un)
    {
        cout<<"The username is available. Select another username!\nPress 0 to try again.\n";
        cin>>choice;
        if(choice==0)
        {
            system("cls");
            Register(username, password);
        }
    }
    cout<< "select a password: ";
    cin>>password;
    ofstream file("E:\\1Account\\"+username+".txt");
    file <<username <<endl << password;
    file.close();

    cout<<"Successfully register! Now you can sign in to BIDV.\nPress 1 to back to menu.\n";
    cin>>choice;
    if(choice==1)
    {
        system("cls");
        //Log_in(username,password);
        main();
    }
}

void Log_in(string &username, string &password)
{
    int choice,cnt=0;
    while(cnt<5)
    {
        bool status=Bool_log_in(username, password);
        if(!status)
        {
            if(cnt==4)
            {
                system("cls");
                break;
            }

            cout<<"Your password is wrong or your account is not available!" <<endl;
            cout<<"Try again or If you don't have account, let's regiser!\nPress 1 to try again or Press any keys to back to menu to register!\nYour choice: ";
            cin>>choice;
            if(choice==1)
            {
                cnt++;
                system("cls");
            }
            else
            {
                system("cls");
                main();
            }
        }
        else
            break;
    }
    if(cnt==4)
    {
        cout<<"Your account is locked!!!\n";
        cout<<"Try another account or Register!\nPress 1 to try another account or Press any keys to back to menu to register!\nYour choice: ";
        cin>>choice;
        if(choice==1)
            Log_in(username,password);
        else
        {
            system("cls");
            main();
        }
    }
}

bool Bool_log_in(string &username, string &password)
{
    string un, pw;
    cout<< "Enter username: ";
    cin>> username;
    cout<< "Enter password: ";
    cin>> password;
    ifstream read("E:\\1Account\\"+username+".txt");
    getline(read, un);
    getline(read, pw);
    if(un==username && pw==password)
        return 1;
    else
        return 0;
}

void Exit()
{
    cout<<"\n\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\ ATM ACCOUNT EXIT \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n";
    cout<<"\n\n\t\t\tGOODBYE. SEE YOU LATER! \n\n";
    cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n";
    system("PAUSE");
    exit(1);
}

void Start_accountbalance(string &username, int &accountbalance)
{
    string line_;
    ifstream file_("E:\\3Account Balance\\"+username+".txt");
    if(file_.is_open())
    {
        while(getline(file_,line_))
        {
            accountbalance=stoi(line_);
        }
        file_.close();
    }
    else
        accountbalance = 1000000;
}

void Main_menu()
{
    system("cls");
    cout << endl << "\n\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb WELCOME TO BIDV \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n" << endl << endl;
    cout << "\t\tEnter [1] To Deposit Cash" << endl;
    cout << "\t\tEnter [2] To Withdraw Cash" << endl;
    cout << "\t\tEnter [3] To History Transaction" << endl;
    cout << "\t\tEnter [0] to Sign Out" << endl << endl;
    cout << "\tPLEASE ENTER A SELECTION AND PRESS RETURN KEY: \n\n";
    cout<<"\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n\n";
}

void Deposit(string &username, int &accountbalance)
{
    int choice;
    int index,i;
    cout<<"YOUR PRESENT ACCOUNT BALANCE: "<<accountbalance<<'\n';
    cout<<"THE DENOMINATION OF MONEY YOU CAN DEPOSIT:\n--> 10000\n--> 20000\n--> 50000\n--> 100000\n--> 200000\n--> 500000\n";
    cout<<"THE MONEY YOU WANT TO DEPOSIT:\n(+) Currency Denomination: ";
    cin>>i;
    cout<<"(+) Amount: ";
    cin>>index;
    switch(i)
    {
    case(10000):
        accountbalance+=i*index;
        break;
    case(20000):
        accountbalance+=i*index;
        break;
    case(50000):
        accountbalance+=i*index;
        break;
    case(100000):
        accountbalance+=i*index;
        break;
    case(200000):
        accountbalance+=i*index;
        break;
    case(500000):
        accountbalance+=i*index;
        break;
    default:
        system("cls");
        cout<<"Wrong Input!!!\n";
        cout<<"Let's try again or back to menu!\n";
        cout<<"Press 1 to Try again!\nPress 2 to Back to menu!\nYour choice: ";
        cin>>choice;
        if(choice==1){
            system("cls");
            Deposit(username, accountbalance);
        }
        else if(choice==2)
            Main_menu();
    }
    if(choice==0)
    {
        /// sau khi nạp tiền
        cout<<"AFTER DEPOSIT: "<<accountbalance<<'\n';
        cout<<"===================================================\n";
        ofstream file("E:\\2History Transaction\\"+username+".txt",ios::out | ios::app);
        time_t now;
        time(&now);
        file << ctime(&now)<<'\n'<<"Transaction: "<<'+'<<i*index<<'\n'<<"Account Balance: "<<accountbalance <<'\n';
        file << "===================================================\n";
        file.close();
        cout<<"WOULD U WANT MORE TRANSACTION???\n";
        cout<<"Press 1 to transact or Press any keys to Back to menu!\nYour choice: ";
        cin>>choice;
        if(choice==1){
                system("cls");
            Deposit(username, accountbalance);
        }
        else
            Main_menu();
    }
}

void Withdraw(string &username, int &accountbalance)
{
    int i,choice;
    cout<<"THE MINIMUM THAT YOU CAN WITHDRAW: 100000\n";
    cout<<"YOUR ACCOUNT BALANCE: "<<accountbalance<<'\n';
    cout<<"THE MONEY YOU WANT TO WITHDRAW: ";
    cin>>i;
    /// kiểm tra số tiền rút ra
    if(i<100000||i>accountbalance)
    {
        system("cls");
        cout<<"Wrong Input!!!\n";
        cout<<"Let's try again or back to menu!\n";
        cout<<"Press 1 to Try again!\nPress any keys to Back to menu!\nYour choice: ";
        cin>>choice;
        if(choice==1){
            system("cls");
            Withdraw(username,accountbalance);
        }
        else
        {
            Main_menu();
        }
    }
    if(i>100000&&i<=accountbalance)
    {
        /// sau khi rút
        accountbalance-=i;
        cout<<"AFTER WITHDRAW: "<<accountbalance<<'\n';
        cout<<"===================================================\n";
        ofstream file("E:\\2History Transaction\\"+username+".txt",ios::out | ios::app);
        time_t now;
        time(&now);
        file << ctime(&now)<<'\n'<<"Transaction: "<<'-'<<i<<'\n'<<"Account Balance: "<<accountbalance <<'\n';
        file << "===================================================\n";
        file.close();
        /// khi hết tiền
        if(accountbalance==0)
        {
            cout<<"Your money is cleaned out of!!!\nPlease deposit money to withdraw!";
            cout<<"Press any keys to back to menu: ";
            cin>>choice;
            Main_menu();
        }
        /// vẫn còn dư
        else if(accountbalance!=0)
        {
            cout<<"WOULD U WANT MORE TRANSACTION???\n";
            cout<<"Press 1 to transact or Press any keys to Back to menu!\nYour choice: ";
            cin>>choice;
            if(choice==1)
                Withdraw(username,accountbalance);
            else
                Main_menu();
        }
    }
}

void History(string &username)
{
    string line_;
    ifstream file_("E:\\2History Transaction\\"+username+".txt");
    if(file_.is_open())
    {
        while(getline(file_,line_))
        {
            cout<<line_<<'\n';
        }
        file_.close();
    }
    cout<<"Press 1 to back to menu.\n";
    int choice;
    cin>>choice;
    if(choice==1)
    {
        system("cls");
        Main_menu();
    }
}

void Log_out(string username, int accountbalance)
{
    ofstream file("E:\\3Account Balance\\"+username+".txt");
    file <<accountbalance <<'\n';
    file.close();
    main();
}
