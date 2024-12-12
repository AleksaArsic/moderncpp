#include <iostream> 
#include <string>
#include <vector>

class Repository
{
    public:
        Repository(const std::initializer_list<const char*>& words)
        {
            wordList.insert(std::begin(wordList), std::begin(words), std::end(words));  
        }
    
        auto begin() const 
        {
            return std::begin(wordList);   
        }
        
        auto end() const
        {
            return std::end(wordList);   
        }
    
        friend std::ostream& operator<<(std::ostream& out, Repository& r);
    private:
        std::vector<std::string> wordList;
};

std::ostream& operator<<(std::ostream& out, Repository& r)
{
    for (const auto& s : r)
    {
        out << s << " ";   
    }
    
    return out;
}

int main() 
{ 
    Repository repo = { "Aleksa", "Arsic", "is", "learning", "modern", "cpp" };
    
    std::cout << repo << std::endl;
        
    return 0; 
}