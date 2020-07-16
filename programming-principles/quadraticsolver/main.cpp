#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	double a,b,c = 0; // ax^2 + bx + c = 0

	cin >> a >> b >> c; // prompt value for each variable
	
	
	//outputting equations in the correct syntax

	if (a == 0 && b == 0 && c == 0) //invalid equation 0 = 0
	{
		cout << a << "x^2 + " << b << "x + " << c << " = 0" << endl;
		cout << "Unable to determine root(s)." << endl;

	}

	else if (a == 0 && b == 0 && c>0) //invalid equation c = 0
	{
		cout << a << "x^2 + " << b << "x + " << c << " = 0" << endl;
		cout << "Unable to determine root(s)." << endl; 	
	}
	
	else if (a == 0 && b == 0 && c < 0) //invalid equation -c = 0
	{	c = fabs(c);
		cout << a << "x^2 + " << b << "x - " << c << " = 0" << endl;
		cout << "Unable to determine root(s)." << endl; 	
	}



	else if (b > 0 && c > 0) 
	{
		cout << a << "x^2 + " << b << "x + " << c << " = 0" << endl; 
	}
		
	
	
	else if (b >= 0 && c < 0)
	{
		c = fabs(c);
		cout << a << "x^2 + " << b << "x - " << c << " = 0" << endl;
		c *=-1;
	}



	else if (b < 0 && c > 0)
	{
		b = fabs(b); 
		cout << a << "x^2 - " << b << "x + " << c << " = 0" << endl;
		b *=-1;
	}
	
	else if (b < 0 && c < 0)
	{
		b = fabs(b);
		c = fabs(c);
		cout << a << "x^2 - " << b << "x - " << c << " = 0" << endl;
		b *=-1;
		c *=-1;	
	}


	
	else //never executed since all case are handled before
	{ 
		cout << a << "invalid entry" << endl; 
	}

	
	//Equation solving begins here

	if (a == 0 && b!=0 && c!=0)  // for equation of type bx + c = 0
	{
		double x = 0;
		x = -c/b;
		cout << "x = " << x << endl; //one root
	}		


	else if (a == 0 && b == 0) //for invalid equation
	{
		//do nothing
		a = 0;
	}


	else 
	{	

		double d = 0; //initialize discriminant

		d = pow(b,2) -4*a*c; //discriminant formula

		double x1, x2, x, i = 0; //x1 = root1, x2 = root2, x = singleroot, i = imaginary root
	
			if (d >=0) //for non imaginary roots i.e positive discriminant
			{
				x1 = (-b - sqrt(d))/(2*a) ; //negative part
				x2 = (-b + sqrt(d))/(2*a) ; //positve part

				if (x1 == x2) //for one distinct root
				{
					cout << "x = " << x1 << endl;
				}

				else
				{	//for two distinct roots
					cout << "x = " << x1 << endl;
					cout << "x = " << x2 << endl;
				}
			}	

			
			else
			{ //for imaginary root when determinant is less than zero
				x = -b/(2*a); //real part
				i = sqrt(fabs(d))/(2*a); //imaginary part
				if (i >=0) //positive imaginary
				{
					cout << "x = " << x << " - " << i << "i" << endl;
					cout << "x = " << x << " + " << i << "i" << endl;
				}

				else
				{ //negative imaginary
					i = fabs(i);
					cout << "x = " << x << " + " << i << "i" << endl;
					cout << "x = " << x << " - " << i << "i" << endl;
				}


			}
	}
	
	return 0;
}