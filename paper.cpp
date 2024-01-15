#include <iostream>
using namespace std;
class account{
    public:
    int balance;
    static int returning(account a,account b){
        account c;
        c.balance= a.balance + b.balance;
        return c.balance;
    }
};
int main() {
    account a;
    account b;
    account c;
    a.balance=10;
    b.balance=20;
    cout<<c.returning(a,b);
    return 0;
}