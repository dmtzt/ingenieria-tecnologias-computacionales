#include <iostream>

using namespace std;

/* Parámetros: int x, double y
 * Valor de retorno: double
 */
double func(int x, double y);

/* Parámetros: char ch, int ent
 * Valor de retorno: double
*/

double func(char ch, int ent);

/* Parámetros: char p, char q, char r
 * Valor de retorno: ninguno
*/
void func(char p, char q, char r);


void uno (int x, int n);
void uno (int v);

int main()
{
	// Ejercicio 1
	// Imprime 0 -> false
	// Imprime 1 -> true
	cout << "Ejercicio 1" << endl;
	
	// false
	cout << ((-5.0 * 4 < 5) && (11 / 3 == 2)) << endl;
	
	// false
	cout << ((5 % 3 - 6 + 5 / 2) != (7 % 4 – 17 / 3)) << endl;
	
	// true
	cout << ((-5.0 * 4 != -20) || (17 / 5 >= 2)) << endl;	
		
	// false
	cout << ((2 != 2.0) && (15 > 8)) << endl;
	
	//true
	cout << ((5 % 2 + 6 – 5 / 2 ) >= ( 8 % 5 * 2)) << endl;
	
	// true 
	cout <<  (!(5 > 8) && (3.0 >= 3)) << endl;
	
	// Ejercicio 2
	// El valor final de a es 10 y de b es 20
	cout << "Ejercicio 2" << endl;
	
	int a = 10;
	int b = 20;
	uno(a,b);
	cout << a << " " << b << endl;
	
	// El valor inicial y final de x es 5
	int x = 5;
	cout << x << " ";
	uno(x);
	cout << x << " " << endl;
	
	return 0;
	
	// Ejercicio 4
	cout << "Ejercicio 4" << endl;
	
	int c, d, n, p, r, x;
	cout << "a:";
	cin >> a;
	
	cout << "b:";
	cin >> b;
	
	cout << "c:";
	cin >> c;
	
	if (a == b || a == c)
		cout << true;
	
	cout << "x:";
	cin >> x;
	
	if (x % 2 == 1)
		cout << true;
	if (x != 9)
		cout << true;
	
	cout << "n:";
	cin >> n;
	
	if (a != 5 || a != n)
		cout << true;
	
	cout << "p:";
	cin >> p;
	
	if (p >= 100 && p <= -100 && p >= -10 && p <= 10)
		cout << true;
	
	// Ejercicio 5
	cout << "Ejercicio 5";
	a = 10;
	d = 8;
	if ((a > d) || (a / 2 == 5.0))
		a -= d
	else
		a += d;
	d = d / 3;
	cout << "a:" << a << " b:" << b << " c:" << c << endl;
	r = 0, n = 28;
	if ((n > 20) && (n % 2 == 0))
 	 	 if ( n < 10)
		    r += 5;	
		else
			r = 22;
		else
			r++;
	cout << "r:" << r << " n:" << n << endl;
}

void uno (int x, int n) {
	if (x > 15) {
		x = 30;
		n = 5;
	}
	else {
	x = 12;
	n = 3;
	}
}

void uno(int v) {
	cout << v << " ";
	v = 10;
	cout << v << " ";
}