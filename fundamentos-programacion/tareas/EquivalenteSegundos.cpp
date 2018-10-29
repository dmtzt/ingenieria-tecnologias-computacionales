#include <iostream>

using namespace std;

int toSeconds(int hours, int minutes, int seconds);

int main(void)
{
	int hours, minutes, seconds;
	hours = 0;
	minutes = 0;
	seconds = 0;
	
	cin >> hours >> minutes >> seconds;
	
	seconds = toSeconds(hours, minutes, seconds);
	
	cout << seconds << endl;
	
	return 0;
}

int toSeconds(int hours, int minutes, int seconds)
{
	double result;
	result = 0;
	
	result += hours / 3600;
	result += minutes / 60;
	result += seconds;
	
	return result;
}

