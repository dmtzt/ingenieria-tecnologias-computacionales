/* 
 * clock.cpp
 * 
 * Description
 *
 * David Alejandro Martinez Tristan
 * 31/01/2019
*/

#include <iostream>
#include "Clock.h"

using namespace std;

int main(void)
{
    int hours, minutes, seconds;
    string format;

    Clock clock1;

    cout << "Please enter desired time in HH MM SS FORMAT: ";
    cin >> hours >> minutes >> seconds >> format;

    Clock clock2(hours, minutes, seconds, format);

    clock1.toString();
    clock2.toString();

    while(true)
    {
        cout << "Please enter hours and minutes to add in HH MM: ";
        cin >> hours >> minutes;

        clock2.addHours(hours);
        clock2.addMinutes(minutes);

        cout << "The current time is: ";
        clock2.toString();
    }
    return 0;
}
