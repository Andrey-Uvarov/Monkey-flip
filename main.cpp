#include <iostream>

using namespace std;

int myMin(int r, int g, int b);
int win(int A, int C, int r, int g, int b);
int myMax(int winR, int winG, int winB);
int main() {
	int t, A, C, r, g, b;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> A >> C;
		cin >> r >> g >> b;
		int winR = win(A, C, r + 1, g, b);
		int winG = win(A, C, r, g + 1, b);
		int winB = win(A, C, r, g, b + 1);
		int Max = myMax(winR, winG, winB);
		if (winR == Max) {
			cout << "RED" << endl;
		}
		else if (winG == Max) {
			cout << "GREEN" << endl;
		}
		else {
			cout << "BLUE" << endl;
		}
 	}
}

int myMin(int r, int g, int b) {
	int min;
	if (r <= b && r <= g)
		min = r;
	else if (g <= b && g <= r)
		min = g;
	else
		min = b;
	return min;
}

int win(int A, int C, int r, int g, int b)
{
	//int res = A * (r * r + g * g + b * b) + C * myMin(r, g, b);
	return A * (r * r + g * g + b * b) + C * myMin(r, g, b);;
}

int myMax(int winR, int winG, int winB)
{
	int Max;
	if (winR > winB && winR > winG) 
		Max = winR;
	else if (winG > winB && winG > winR) 
		Max = winG;
	else 
		Max = winB;
	return Max;
}

