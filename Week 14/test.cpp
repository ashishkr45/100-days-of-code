#include <iostream>
#include <string>
#include <vector>

using namespace std;

class stud
{
public:
    string name;
    double average;

    void setName(const string name)
    {
        this->name = name;
    }

    void avg(const vector<double> &marks)
    {
        double sum = 0.0;
        for (int i = 0; i < marks.size(); i++)
        {
            sum += marks[i];
        }
        average = sum / (int)marks.size();
    }

    void print() const
    {
        cout << "Student Details:" << endl;
        cout << "Name: " << name << endl;
        cout << "Average marks: " << average << endl;
    }
};

int main()
{
    int num;
    cin >> num;
    cin.ignore();
    cout << "Strudent Details:" << endl;

    while (num > 0)
    {
        string name;
        getline(cin, name);
        cin.ignore();

        int n;
        cin >> n;
        vector<double> marks(n);
        for (int i = 0; i < n; i++)
        {
            cin >> marks[i];
        }
        stud s;
        s.setName(name);
        s.avg(marks);
        s.print();
    }
    return 0;
}