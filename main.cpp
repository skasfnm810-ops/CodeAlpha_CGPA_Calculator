#include <iostream>
using namespace std;

// Function to convert grade to points
float getGradePoint(string grade) {
    if(grade == "A") return 4.0;
    else if(grade == "A-") return 3.7;
    else if(grade == "B+") return 3.3;
    else if(grade == "B") return 3.0;
    else if(grade == "B-") return 2.7;
    else if(grade == "C+") return 2.3;
    else if(grade == "C") return 2.0;
    else if(grade == "C-") return 1.7;
    else return 0.0;
}

int main() {
    int numCourses;
    cout << "Enter number of current semester courses: ";
    cin >> numCourses;

    float totalCredits = 0, totalGradePoints = 0;

    // Current semester input
    for(int i = 0; i < numCourses; i++) {
        string grade;
        float credit;

        cout << "\nCourse " << i + 1 << endl;
        cout << "Enter grade (A, A-, B+, B, B-, C+, C, C-): ";
        cin >> grade;

        cout << "Enter credit hours: ";
        cin >> credit;

        float gp = getGradePoint(grade);

        totalCredits += credit;
        totalGradePoints += gp * credit;
    }

    float currentGPA = totalGradePoints / totalCredits;
    cout << "\nCurrent Semester GPA: " << currentGPA << endl;

    // Previous semesters
    int prevSem;
    cout << "\nEnter number of previous semesters: ";
    cin >> prevSem;

    float prevTotalCredits = 0, prevTotalPoints = 0;

    for(int i = 0; i < prevSem; i++) {
        float gpa, credits;

        cout << "\nSemester " << i + 1 << endl;
        cout << "Enter GPA: ";
        cin >> gpa;

        cout << "Enter total credit hours: ";
        cin >> credits;

        prevTotalCredits += credits;
        prevTotalPoints += gpa * credits;
    }

    // Final CGPA calculation
    float overallCredits = totalCredits + prevTotalCredits;
    float overallPoints = totalGradePoints + prevTotalPoints;

    float finalCGPA = overallPoints / overallCredits;

    cout << "\n?? Final CGPA: " << finalCGPA << endl;

    return 0;
}
