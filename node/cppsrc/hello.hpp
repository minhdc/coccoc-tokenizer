#include <string>
using namespace std;

class Hello{
    public:
        Hello(string userName);
        string getUserName();
    private:
        string userName;
};