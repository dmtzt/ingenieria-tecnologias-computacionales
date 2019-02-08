/* 
 * grades.cpp
 * 
 * Description
 *
 * David Alejandro Martinez Tristan
 * 24/01/2019
*/
#include <fstream>

using namespace std;

int main(void)
{
    int passed = 0;
    int failed = 0;
    int students = 0;
    double highest = 0;
    double lowest = 100;
    double average = 0;
    double p1, p2, final_exam, final_grade;
    string first_name;
    string last_name;
    ifstream infile;
    ofstream outfile;

    infile.open("grades.txt");
    outfile.open("finalGrade.txt");

    outfile << "FName" << '\t' << "LName" << '\t' << "P1" << '\t' << "P2" << 
            '\t' << "FinalExam" << '\t' << "FinalGrade" << endl;

    while (!infile.eof())
    {
        infile >> first_name >> last_name >> p1 >> p2 >> final_exam;

        final_grade = p1 * 0.25 + p2 * 0.25 + final_exam * 0.5;
        average += final_grade;

        if (final_grade < 70)
            failed++;
        else
            passed++;

        if (final_grade > highest)
            highest = final_grade;
        if (final_grade < lowest)
            lowest = final_grade;

        outfile << first_name << '\t' << last_name << '\t' << p1 << '\t' << p2 <<
                '\t' << final_exam << '\t' << final_grade << endl;

        students++;
    }

    average /= students;
    outfile << "Group Average: " << average << endl;
    outfile << "Passed Students: " << passed << endl;
    outfile << "Failed Students: " << failed << endl;
    outfile << "Highest Grade: " << highest << endl;
    outfile << "Lowest Grade: " << lowest << endl;

    infile.close();
    outfile.close();

    return 0;
}
