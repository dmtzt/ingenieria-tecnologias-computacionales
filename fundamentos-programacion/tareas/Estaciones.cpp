#include <iostream>

#define JANUARY 1
#define FEBRUARY 2
#define MARCH 3
#define APRIL 4
#define MAY 5
#define JUNE 6
#define JULY 7
#define AUGUST 8
#define SEPTEMBER 9
#define OCTOBER 10
#define NOVEMBER 11
#define DECEMBER 12

using namespace std;

int main(void)
{
	int day, month;
	
	day = 0;
	month = 0;
	
	cin >> day >> month;
	
	switch(month)
	{
		case JANUARY:
		case FEBRUARY:
			cout << "INVIERNO";
			break;
		case MARCH:
			(day < 21) 
			? cout << "INVIERNO" << endl 
			: cout << "PRIMAVERA" << endl;
			break;
		case APRIL:
		case MAY:
			cout << "PRIMAVERA";	
			break;
		case JUNE:
			(day < 22) 
			? cout << "PRIMAVERA" << endl 
			: cout << "VERANO" << endl;
			break;
		case JULY:
		case AUGUST:
			cout << "VERANO";	
			break;
		case SEPTEMBER:
			(day < 22) 
			? cout << "VERANO" << endl
			: cout << "OTOÑO" << endl;
			break;
		case OCTOBER:
		case NOVEMBER:
			cout << "OTOÑO";	
			break;
		case DECEMBER:
			(day < 22) 
			? cout << "OTOÑO" << endl
			: cout << "INVIERNO" << endl;
			break;
	}
	return 0;
}