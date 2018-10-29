#include <iostream>

using namespace std;

int main(void)
{
	int hours, minutes;
	bool pastMidday;
	
	hours = 0;
	minutes = 0;
	
	pastMidday = false;
	
	cin >> hours >> minutes;
	
	if (hours == 0 || hours == 24)
		hours = 12;
	else if (hours >= 12)
	{
		pastMidday = true;
		
		if (hours > 12)
			hours -= 12;
	}
	
	if (hours < 10)
		cout << "0" << hours << ":";
	else
		cout << hours << ":";
	
	if (minutes < 10)
		cout << "0" << minutes << " ";
	else
		cout << minutes << " ";
	
	if (pastMidday)
		cout << "PM" << endl;
	else
		cout << "AM" << endl;
}