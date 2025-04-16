#include <bits/stdc++.h>
using namespace std;

class contributor
{
public:
    void addMore()
    {
        ofstream fout("question.txt", ios::app);
        if (!fout)
        {
            cerr << "No such file found!\n";
            exit(1);
        }
        else
        {
            string str;
            cout << "Enter your question below\n";
            cin.ignore();
            getline(cin, str);
            fout << endl << str;
            fout.close();
            cout << "Your question added successfully\n";
        }
    }
};

class gainer
{
    int point = 0;

public:
    void answer()
    {
        ifstream fin("question.txt");
        int i = 1;
        while (fin.eof() == 0)
        {
            string question;
            getline(fin, question);
            cout << question << endl;
            string answer;
            cout << "Write your answer: ";
            cin >> answer;
            transform(answer.begin(), answer.end(), answer.begin(), ::tolower);
            if (i == 1 && answer == "camel")
            {
                cout << "Correct Answer\n";
                point += 5;
                cout << "You earn " << point << " points\n";
            }
            else if (i == 2 && answer == "7")
            {
                cout << "Correct Answer\n";
                point += 5;
                cout << "You earn " << point << " points\n";
            }
            else if (i == 3 && answer == "24")
            {
                cout << "Correct Answer\n";
                point += 5;
                cout << "You earn " << point << " points\n";
            }
            else if (i == 4 && answer == "26")
            {
                cout << "Correct Answer\n";
                point += 5;
                cout << "You earn " << point << " points\n";
            }
            else if (i == 5 && answer == "7")
            {
                cout << "Correct Answer\n";
                point += 5;
                cout << "You earn " << point << " points\n";
            }
            else
            {
                cout << "Wrong Answer!!!\n";
                point -= 2;
                cout << "You earn " << point << " points\n";
            }
            ++i;
        }
        fin.close();
    }
};

int main()
{
    cout << "Are you a contributor or learner?\nType '1' if you are contributor\nType '2' if you are learner\nIf you are a contributor then you can contribute questions\n";
    int choice;
    cout << "Enter your choice: ";
    cin >> choice;
    contributor c;
    gainer g;
    switch (choice)
    {
    case 1:
        int qno;
        cout << "How many questions do you want to add? ";
        cin >> qno;
        for (int i = 0; i < qno; i++)
        {
            c.addMore();
        }
        break;

    case 2:
        g.answer();
        break;

    default:
        cout<<"Enter valid input\n";
        break;
    }
    return 0;
}