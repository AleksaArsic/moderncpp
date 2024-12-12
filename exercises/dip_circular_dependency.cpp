// Bad design decisions
// Two classes that have circular dependency.
#include <iostream>

class Account;

class Customer
{
    public:
        void setAccount(Account* acc)
        {
            account = acc;
        }
        
    private:
        Account* account;
};

class Account
{
    public:
        void setCustomer(Customer* cus)
        {
            customer = cus;   
        }
        
    private:
        Customer* customer;
};

int main() 
{ 
    Customer* customer = new Customer {};
    Account* account = new Account {};
    
    customer->setAccount(account);
    account->setCustomer(customer);

    return 0; 
}