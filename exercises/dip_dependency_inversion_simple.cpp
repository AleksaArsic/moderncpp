#include <iostream>
#include <string>

class Owner
{
    public:
        virtual ~Owner() = default;
        virtual std::string getName() const = 0;
};

class Account;

class Customer : public Owner
{
    public:
        void setAccount(Account* acc)
        {
            account = acc;
        }
        
        std::string getName() const final 
        {
            return "Customer";
        }
    private:
        Account* account;
};

class Account
{
    public:
        void setCustomer(Owner* own)
        {
            owner = own;   
        }
        
    private:
        Owner* owner;
};

int main() 
{ 
    Customer* customer = new Customer {};
    Account* account = new Account {};
    
    customer->setAccount(account);
    account->setCustomer(customer);

    return 0; 
}