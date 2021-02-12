// compile: g++ -std=c++11 -o pointers pointers.cpp
#include <iostream>
#include <string>
#include <cmath>

typedef struct Student {
    int id;
    char *f_name;
    char *l_name;
    int n_assignments;
    double *grades;
} Student;

int promptInt(std::string message, int min, int max);
double promptDouble(std::string message, double min, double max);
void calculateStudentAverage(void *object, double *avg);

using namespace std;
int main(int argc, char **argv)
{
    Student student;
    double average;
    student.f_name = new char[128];
    student.l_name = new char[128];

    // Sequence of user input -> store in fields of `student`
    student.id = promptInt("PLEASE ENTER THE STUDENT'S ID: ",0,999999999);

    //get students name
    std::cout << "PLEASE ENTER THE STUDENT'S FIRST NAME: ";
    cin >> student.f_name;
    
    std::cout << "PLEASE ENTER THE STUDENTS LAST NAME: ";
    cin >> student.l_name;

    //get number of assignments
    student.n_assignments = promptInt("PLEASE ENTER THE NUMBER OF ASSIGNMENTS: ", 1, 999999999);

    student.grades = new double[student.n_assignments];
    int i;
    average = 0.0;

    //adding 
    for(i = 0; i < student.n_assignments; i++){
        std::cout << "PLEASE ENTER GRADE FOR ASSIGNMENT " << i + 1 << ": ";
        student.grades[i] = promptDouble("", 0, 100.00);
        average = average + student.grades[i];

    }

    // Call `CalculateStudentAverage(???, ???)`sss
    // Output `average`
    calculateStudentAverage(&student.n_assignments, &average);
    
    std::cout << "STUDENT: " << student.f_name << " " << student.l_name << " [" << student.id << "]" << std::endl;
    std::cout << "AVERAGE GRADE: " << average;

    return 0;
}

/*
   message: text to output as the prompt
   min: minimum value to accept as a valid int
   max: maximum value to accept as a valid int
*/
int promptInt(std::string message, int min, int max)
{
    // Code to prompt user for an int

    int outputINT;

    cout << message;
    cin >> outputINT;

    return outputINT;
}

/*
   message: text to output as the prompt
   min: minimum value to accept as a valid double
   max: maximum value to accept as a valid double
*/
double promptDouble(std::string message, double min, double max)
{
    // Code to prompt user for a double
    double outputDouble;

    cout << message;
    cin >> outputDouble;

    return outputDouble;
}

/*
   object: pointer to anything - your choice! (but choose something that will be helpful)
   avg: pointer to a double (can store a value here)
*/
void calculateStudentAverage(void *object, double *avg)
{
    // Code to calculate and store average grade
    int denominator = *(int *)object;

    *avg = *avg / denominator;
    *avg = round(*avg * 10)/10;
}
