#include <bits/stdc++.h>
using namespace std;

class calculator
{
protected:
    int r;

public:
    double calculation(int val1, int val2, int ch1)
    {
        switch (ch1)
        {
        case 1:
            r = val1 + val2;
            return r;
            break;

        case 2:
            if (val1 <= val2)
            {
                r = val2 - val1;
                return r;
                break;
            }
            else
            {
                r = val1 - val2;
                return r;
                break;
            }

        case 3:
            r = val1 * val2;
            return r;
            break;

        case 4:
            r = val1 / val2;
            return r;
            break;

        case 5:
            r = val1 % val2;
            return r;
            break;

        default:
            cout << "Enter a valid input\n";
            break;
        }
    }
    double calculate(int num, int ch2);
};

double calculator ::calculate(int number, int ch2)
{
    switch (ch2)
    {
    case 1:
        r = abs(number);
        return r;
        break;
    
    case 2:
        r = sqrt(number);
        return r;
        break;

    case 3:
        r = cbrt(number);
        return r;
        break;
    
    case 4:
        int p;
        cout<<"Enter the power number: ";
        cin>>p;
        r = pow(number, p);
        return r;
        break;

    case 5:
        r = exp(number);
        return r;
        break;

    case 6:
        r = log(number);
        return r;
        break;

    case 7:
        r = log10(number);
        return r;
        break;

    case 8:
        r = log2(number);
        return r;
        break;

    case 9:
        r = sin(number);
        return r;
        break;

    case 10:
        r = cos(number);
        return r;
        break;

    case 11:
        r = tan(number);
        return r;
        break;

    case 12:
        r = 1/sin(number);
        return r;
        break;

    case 13:
        r = 1/cos(number);
        return r;
        break;

    case 14:
        r = 1/tan(number);
        return r;
        break;

    default:
        break;
    }
}

int main()
{
    int choice1;
    cout<<"What do you want to do?\n'1' for Basic Arithmetic operations\n'2' for Special Arithmetic operations\n";
    cout << "Enter your choice: ";
    cin >> choice1;
    switch (choice1)
    {
    case 1:
        int n1, n2;
        cout << "Enter the first number: ";
        cin >> n1;
        cout << "Enter the second number: ";
        cin >> n2;
        int choice2;
        cout << "'1' for Addition\n'2' for Subtraction\n'3' for Multiplication\n'4' for Division\n'5' for Remainder\n";
        cout << "Enter your choice: ";
        cin >> choice2;
        calculator c;
        int result1;
        result1 = c.calculation(n1, n2, choice2);
        cout << "The result is: " << result1 << "\n";
        break;

    case 2:
        int n3, choice3;
        cout << "Enter a number: ";
        cin >> n3;
        cout << "'1' for Absolute Value\n'2' for Square Root\n'3' for Cube Root\n'4' for Power\n'5' for Exponential\n'6' for Natural Logarithm\n'7' for Base-10 Logarithm\n'8' for Base-2 Logarithm\n'9' for Sine\n'10' for Cosine\n'11' for Tan\n'12' for Cosec\n'13' for Sec\n'14' for Cot\n";
        cout << "Enter your choice: ";
        cin >> choice3;
        int result2;
        result2 = c.calculate(n3, choice3);
        cout << "The result is: " << result2 << "\n";
        break;

    default:
        cout<<"Enter a valid input\n";
        break;
    }
}