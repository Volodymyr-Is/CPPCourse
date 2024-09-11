#include <iostream>

using namespace std;

int main()
{
	srand(time(0));
    // Task 26

	/*double hy = 0.3, hx = 0.2, E = 0.0001, z;
	for (double x = 0.1; x + E <= 1.3; x += hx)
	{
		for (double y = 0.1; y + E <= 1.3; y += hy) {
			if (pow(x, 2) + pow(y, 2) <= 1)
				z = pow(x, 2) + pow(y, 2);
			else if (pow(x, 2) + pow(y, 2) > 1 && y >= x)
				z = pow(x, 2) + y;
			else
				z = log10(pow(x, 2) + pow(y, 2));

			cout << "z = " << z << endl;
		}
	}*/



	// Task 1 - 7

	/*double a = 16.5, b = 3.4, x = 0.61, e = 2.72, c, S;

	c = (b * pow(x, 2) - a) / (pow(e, (a * x)) - 1);
	S = (pow(x, 3) * pow(tan(pow((x + b), 2)), 2) + a) / (sqrt(x + b)) * c;

	cout << S << endl;*/


	// Task 2 - 8
	/*double hx = 0.5, z, y;

	for (double x = 1; x < 4; x += hx)
	{
		z = fabs(x) + pow(x, 3);
		y = (sin(pow((2 + x), 2))) / (2 + x) * z;

		cout << z << "\t" << y << endl;
	}*/



	// Task 2 - 7
	/*double hx = 0.2, e = 2.72, E = 0.0001, z, y;
	int b[4] = { 2, 4, 6, 8 };

	for (double x = 1; x + E <= 2; x += hx)
		for (int i = 0; i < 4; i++)
		{
			z = (sqrt(4 * b[i] + pow(x, 2))) / 2;
			y = pow(e, (x / 2)) * pow(b[i], x) * (cos(z) + sin(z));

			cout << "b = " << b[i] << endl;
			cout << "x = " << x << endl;
			cout << "z = " << z << endl;
			cout << "y = " << y << endl;
			cout << endl;
		}*/



	int n = 5;
	int** arr = new int* [n];

	for (int i = 0; i < n; i++)
		arr[i] = new int[n];

	for (int i = 0; i < n; i++,cout << endl)
		for (int j = 0; j < n; j++)
		{
			arr[i][j] = rand() % 21 - 10;
			cout << arr[i][j] << "\t";
		}
	cout << endl;


	int dob = 1;
	for (int i = 0; i < n; i++)
		//dob = dob * arr[i][i];		// Головна діагональ
		dob = dob * arr[i][n - i - 1];	// Друга діагональ
	cout << dob << endl;



	for (int k = 0; k < n - 1; k++)
		for (int i = 0; i < n - 1 - k; i++) {
			if (arr[1][i + 1] < arr[1][i]) {
				int c = arr[1][i + 1];
				arr[1][i + 1] = arr[1][i];
				arr[1][i] = c;
			}
		}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}


	
	int count = 0, res = 0, min = arr[0][0], max = arr[0][0];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] > max)
				max = arr[i][j];
			if (arr[i][j] < min)
				min = arr[i][j];
		}
	}

	res = max / min;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i % 2 == 0) {
				if (arr[i][j] > res)
					count++;
			}
		}
	}

	cout << endl << count << endl;
}