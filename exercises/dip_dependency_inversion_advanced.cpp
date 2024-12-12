#include <iostream>
#include <string>

class OwnerInterface
{
    public:
        virtual ~OwnerInterface() = default;
        virtual std::string getName() const = 0;
};

class AccountInterface
{
    public:
        virtual ~AccountInterface() = default;
        virtual std::string getName() const = 0;
};

class Customer : public OwnerInterface
{
    public:
        void setAccount(AccountInterface* acc)
        {
            account = acc;
        }
        
        virtual std::string getName() const final 
        {
            return "Customer";
        }
    private:
        AccountInterface* account;
};

class Account : public AccountInterface
{
    public:
        void setCustomer(OwnerInterface* own)
        {
            owner = own;   
        }
        
        virtual std::string getName() const final
        {
            return "Account";   
        }
    private:
        OwnerInterface* owner;
};

int main() 
{ 
    Customer* customer = new Customer {};
    Account* account = new Account {};
    
    customer->setAccount(account);
    account->setCustomer(customer);
    
    std::cout << customer->getName() << std::endl;
    std::cout << account->getName() << std::endl;

    return 0; 
}