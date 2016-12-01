#include <iostream>
using namespace std;
#include <string>
//Single Variable and max power 3


void linear(string eq)
{	
	float a, b, c,Y;
	//ax+b=c
	string x = eq.substr(0);
	a = atoi(x.c_str());
	x = eq.substr(3);
	b = atoi(x.c_str());
	x = eq.substr(5);
	c = atoi(x.c_str());
	Y = (c - b) / a;
	
	cout << "Root = " << Y<<endl;
}


void quadratic(string eq)
{	
	float a, b, c, x1, x2, determinant;

	string x = eq.substr(0);
	a = atoi(x.c_str());
	x = eq.substr(5);
	b = atoi(x.c_str());
	x = eq.substr(8);
	c = atoi(x.c_str());
	//cout << a << b<<c;

	determinant = b*b - 4 * a*c;

	if (determinant > 0) {
		x1 = (-b + sqrt(determinant)) / (2 * a);
		x2 = (-b - sqrt(determinant)) / (2 * a);
		cout << "Roots are real and different." << endl;
		cout << "x1 = " << x1 << endl;
		cout << "x2 = " << x2 << endl;
	}

	else if (determinant == 0) {
		cout << "Roots are real and same." << endl;
		x1 = (-b + sqrt(determinant)) / (2 * a);
		cout << "x1 = x2 =" << x1 << endl;
	}

	else {
		cout << "Roots are complex and different.(Not Supported)" << endl;
	}

}

void cubic()
{
	double a, b, c, d, value;
	double f, g, h;
	double i, j, k, l, m, n, p, po;
	double r, s, t, u;
	double x1, x2, x2re, x2im, x3re, x3im, x3;

	value = 1;
	for (int w = 1; w <= value; w++) {
		cout << "Enter values of a,b,c,d" << endl;
		cin >> a >> b >> c >> d;
		cout << "CUBIC EQUATION : " << a << " x^3 + " << b << " x^2 + " << c << " x + " << d << " = 0" << endl;

		f = ((3 * c / a) - ((b*b) / (a*a))) / 3;
		g = ((2 * (b*b*b) / (a*a*a)) - (9 * b*c / (a*a)) + (27 * d / a)) / 27;
		h = ((g*g) / 4) + ((f*f*f) / 27);

		if (f == 0 && g == 0 && h == 0) {     // all roots are real and equal
			x1 = pow((d / a), 0.33333333333333333333333333333333);
			x2 = pow((d / a), 0.33333333333333333333333333333333);
			x3 = pow((d / a), 0.33333333333333333333333333333333);
			cout << "x = " << x1 << endl;
			cout << "x = " << x2 << endl;
			cout << "x = " << x3 << endl;
		}
		else if (h <= 0) {         // all 3 roots are real
			i = pow((((g*g) / 4) - h), 0.5);
			j = pow(i, 0.33333333333333333333333333333333);
			k = acos((g / (2 * i))*-1);
			l = j * -1;
			m = cos(k / 3);
			n = sqrt(3) * sin(k / 3);
			p = (b / (3 * a))*-1;
			x1 = (2 * j)*m - (b / (3 * a));
			cout << "x = " << x1 << endl;
			x2 = l * (m + n) + p;
			cout << "x = " << x2 << endl;
			x3 = l * (m - n) + p;
			cout << "x = " << x3 << endl;
		}
		else if (h>0) {        // only 1 root is real
			r = ((g / 2)*-1) + pow(h, 0.5);
			s = pow(r, 0.33333333333333333333333333333333);
			t = ((g / 2)*-1) - pow(h, 0.5);
			u = pow((t), 0.33333333333333333333333333333333);
			x1 = (s + u) - (b / (3 * a));
			cout << "x = " << x1 << endl;
			x2re = (((s + u)*-1) / 2) - (b / (3 * a));
			x2im = -(s - u)*pow(3, 0.5) / 2;
			cout << "x = (" << x2re << "," << x2im << ")" << endl;
			x3re = (((s + u)*-1) / 2) - (b / (3 * a));
			x3im = (s - u)*pow(3, 0.5) / 2;
			cout << "x = (" << x3re << "," << x3im << ")" << endl;
		}
	}

}


int main()
{
	
	cout << "Select Equation Type: \n";
	cout << "(1) ax + b = c: \n";
	cout << "(2) ax^2+bx+c= 0: \n";
	cout << "(3) ax^3+bx^2+cx+d= 0: \n";

	int choice;
	cin >> choice;

	if (choice == 1)
	{
		string equation;
		cout << "Enter Equation (Form : ax+b = c) \n";
		cin >> equation;
		linear(equation);
	}
	else if (choice == 2)
	{

	cout << "Enter Equation (Form : ax^2 + bx + c = 0 ) \n";
	string equation;
	cin >> equation;
	quadratic(equation);
		
	}

	else if (choice == 3)
	{

		cout << "Enter Equation (Form : ax^3 + bx^2 + cx + d = 0 ) \n";
		cubic();

	}

	
	
}




