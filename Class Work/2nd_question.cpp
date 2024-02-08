#include <iostream>
using namespace std;

class Account{
    protected:
    string name;
    int pin;
    float ammount;
    public:
    Account(string name, int pin,float ammount) : name(name), pin(pin),ammount(ammount){}
    Account()=default;
    void set_name(string name) { this->name=name;}
   

    virtual float get_balance()=0;
    virtual void set_pin(){
        this->pin=pin;
    }
    virtual string get_name(){
        return name;
    }
  

};
class Saving_Account:public Account{
    
    float intrest_rate_per_day;
    public:

    Saving_Account(string name,int pin,float ammount,float intrest_rate_per_day):Account(name,pin,ammount),intrest_rate_per_day(intrest_rate_per_day){}
   
    void deposit(float amm){
        ammount= ammount+amm;
    }
    void withdraw(float amm){
        ammount=ammount-amm;
    }
    float get_balance() override{
        return (ammount+ammount*(intrest_rate_per_day/100));
        
    }
    
};
class Loan_Account:public Account{
    
    int intrest;
    public:
    Loan_Account(string name,int pin,float ammount,int intrest):Account(name,pin,ammount),intrest(intrest){}
    void pay_loan(int amm){
        ammount=ammount-amm;
    }
    float get_balance(){
        return (ammount+ammount*(intrest/100));
    }
    void get_loan(int amm){
        ammount=ammount+amm;}
    float calculate_intrest_ammount(){
        return (ammount*(intrest/100));
    }
};
class Current_Account: public Account{
    
    public:
    
    Current_Account(string name,int pin,float ammount):Account(name,pin,ammount){}
    
    void deposit(float amm){
        ammount= ammount+amm;
    }
    void withdraw(float amm){
        ammount=ammount-amm;
    }
    float get_balance() override{
        return ammount;
    }
    
};

int main(){
    Account* a1;
    cout<<"Enter 1 for a current account"<<endl;
    cout<<"Enter 2 for a saving account"<<endl;
    cout<<"Enter 3 for a loan account"<<endl;
    int choice;
    cin>>choice;

    if(choice ==1){
        a1=new Current_Account("Jamal",1234,20000);
    }
    else if(choice ==2){
        a1=new Saving_Account("Jamal",1234,20000,17);
    }
    else if(choice ==3){
        a1=new Loan_Account("Jamal",1234,20000,25);
    }
        a1->get_balance();
    return 0;   
}