#include <iostream>
using namespace std;

class Student
{
public:

    Student(string studentName, int numberofGrades);
    Student(const Student &original);
    void setGrades(int arrayGrades[]);
    double calculateAverageGrade();
    void displayInfo();

    Student &operator=(const Student &original2)
    {
        if (this == &original2)
            return *this;
        name = original2.name;
        length = original2.length;
        delete[] grades;

        for (int i = 0; i < length; i++)
        {
            grades[i] = original2.grades[i];
        }
        return *this;
    }
    ~Student()
    {
        cout << "Destructor called for student: " << name << endl;
        delete[] grades;
    }

private:
    string name;
    int length;
    int *grades;
};

void Student::setGrades(int arrayGrades[])
{
    for (int i = 0; i < length; i++)
        grades[i] = arrayGrades[i];
}
double Student::calculateAverageGrade()
{
    double total;
    for (int i = 0; i < length; i++)
    {
        total += grades[i];
    }
    return total / length;
}
void Student::displayInfo()
{
    cout << "Student name: " << name << endl;
    cout << "Grades: ";
    for (int i = 0; i < length; i++)
    {
        cout << grades[i] << " ";
    }
    cout << endl;
    cout << "Average: " << calculateAverageGrade() << endl;
}

Student::Student(string studentName, int numberofGrades)
{
    name = studentName;
    length = numberofGrades;
    grades = new int[length];
}

Student::Student(const Student &original)
{
    length = original.length;
    name = original.name;
    grades = new int[length];
    for (int i = 0; i < length; i++)
    {
        grades[i] = original.grades[i];
    }
}
int main()
{
    Student Alex("Alex", 5);
    int AlexGrades[] = {13, 10, 10, 10, 10};
    Alex.setGrades(AlexGrades);
    cout << "Student 1" << endl;
    Alex.displayInfo();

    Student Sasha("Sasha", 5);
    int sashaGrades[] = {67, 70, 98, 50, 45};
    Sasha.setGrades(sashaGrades);
    cout << "Student 2" << endl;
    Sasha.displayInfo();

    cout << "Student 3 (Copy Constructor)" << endl;
    Student copyofAlex(Alex);
    copyofAlex.displayInfo();

    cout << "Student 4 (Assign Operator)" << endl;
    Student assign("Default", 5);
    assign = Sasha;
    assign.displayInfo();
    return 0;
}
