#include <iostream>
using namespace std;

const int MAX = 65;

class password
{
    char signs[MAX] = {'A', 'a', 'B', 'b', 'C', '1', 'c', 'D', 'd', 'E', 'e', '2', 'F', 'f', 'G', 'g', 'H', '3', 'h', 'I', '-', 'i', 'J', 'j', '4', 'K', 'k', 'L', 'l', 'M', '5', 'm', 'N', 'n', 'O', 'o', '6', 'P', 'p', 'Q', 'q', '.', 'R', '7', 'r', 'S', 's', 'T', 't', '8', 'U', 'u', 'V', 'v', 'W', '9', 'w', 'X', 'x', 'Y', 'y', '0', '@', 'Z', 'z'};
    string res = "";

public:
    string create_password(int len)
    {
        for (int i = 0; i < len; i++)
        {
            res = res + signs[rand() % MAX];
        }
        return res;
    }
};

int main()
{
    int l;
    cout << "Enter the length of the password: ";
    cin >> l;
    password pwd;
    string pass = pwd.create_password(l);
    cout << "Your password is: " << pass << endl;
    return 0;
}