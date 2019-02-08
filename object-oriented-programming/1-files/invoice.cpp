/* 
 * invoice.cpp
 * 
 * Reads from an invoice file and generates a report with
 * the total amount to pay for every single employee
 * as well as the cumulated total.
 *
 * David Alejandro Martinez Tristan
 * 21/01/2019
*/

#include <fstream>

using namespace std;

int main(void)
{
    int id;
    double hours, billing_rate, single_amount;
    double total_amount = 0;

    ifstream invoice;
    ofstream report;

    // Open invoice and report files
    invoice.open("invoice.txt");
    report.open("report.txt");

    report << "ID Employee" << '\t' << "Amount to pay" << endl;

    while (!invoice.eof())
    {
        // Read employe id, hours worked and billing rate
        invoice >> id >> hours >> billing_rate;
        
        // Calculate single amount to pay
        single_amount = hours * billing_rate;
        // Add to total amount
        total_amount += single_amount;

        // Write data to report
        report << id << '\t' << '\t' << single_amount << endl;
    }

    // When all employees are done, write total amount
    report << "Total: " << total_amount;

    // Close corresponding files
    invoice.close();
    report.close();

    return 0;
}
