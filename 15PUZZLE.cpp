#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>

using namespace std;

const int arraySize = 4;
char elements[arraySize][arraySize] = { {'1','2','3','4'},
										{'5','6','7','8'},
										{'9','A','B','C'},
										{'D','E','F',' '}
};

char check[arraySize][arraySize] = { {'1','2','3','4'},
									 {'5','6','7','8'},
									 {'9','A','B','C'},
									 {'D','E','F',' '}
};

int vSP = 3; // Saquli boshlugun pozisiyasi
int hSP = 3; //ufuqi boshlugun pozisiyasi
int x[100] = {}; // Komputerin addimlarini yazir.
int index = 0;  
void menu();
void moveUp();
void moveDown();
void moveRight();
void moveLeft();
void ByComputer();
void ByPlayer();
void randomise(); // random xanalarin yerinin deyishilmesi
int winer(); // puzzle-in bitmesini yoxlayir



int main()
{
	srand(time(0));
	randomise();
	menu();
	return 0;
}
void menu()
{
	int x;
	cout << "\t\t\t15 PUZZLE" << endl;
	cout << "1.By Player." << endl;
	cout << "2.By Computer." << endl;
	cout << "3.Game rules." << endl;
	cout << "\tINPUT: ";
	cin >> x;
	if (x == 1)
	{
		system("cls");
		ByPlayer();
	}
	else if (x == 2)
	{
		system("cls");
		ByComputer();
	}

}
void ByComputer() {
	bool quite(false);
	for (int k = index - 1; k >= 0; k--)
	{

		for (int i = 0; i < arraySize; i++)
		{

			for (int j = 0; j < arraySize; j++)
			{
				cout << "  " << elements[i][j];
			}

			cout << endl << endl;
		}


		switch (x[k])
		{
		case 1:
			moveDown();
			break;

		case 2:
			moveUp();
			break;

		case 3:
			moveLeft();
			break;

		case 4:
			moveRight();
			break;
		}
		int c = winer();
		if (c == 1) {
			cout << "End.." << endl;
			Sleep(5000);
		}
		Sleep(1000);
		system("cls");

	}


}
void ByPlayer() {
	bool quite(false);
	do
	{
		for (int i = 0; i < arraySize; i++) {
			for (int j = 0; j < arraySize; j++)
				cout << "  " << elements[i][j];
			cout << endl << endl;
		}
		char a;
		cout << "w - Up, s - Down, a - Left, s - Right" << endl;
		cout << "m - avtomatic(Computer)" << endl;
		cin >> a;
		switch (a)
		{
		case 'W':
		case 'w':
			moveUp();
			x[index++] = 1;
			break;

		case 'S':
		case 's':
			moveDown();
			x[index++] = 2;
			break;

		case 'D':
		case 'd':
			moveRight();
			x[index++] = 3;
			break;

		case 'a':
		case 'A':
			moveLeft();
			x[index++] = 4;
			break;
		case 'm':
		case 'M':
			ByComputer();
			break;
		default:
			cout << "Wrong character, pleas type again!" << endl;
			break;

		}
		int c = winer();
		if (c == 1) {
			cout << "Great! You solved the puzzle!" << endl;

			quite = true;
		}
		system("cls");
	} while (quite == false);
}

void moveUp()
{
	int vP = vSP;// 3
	if (vP + 1 < 4 && vP >= 0) {

		elements[vSP][hSP] = elements[vSP + 1][hSP];
		elements[vSP + 1][hSP] = ' ';
		vSP += 1;
	}
}
void moveDown()
{
	int vP = vSP;
	if (vP + 1 <= 4 && vP > 0) {

		elements[vSP][hSP] = elements[vSP - 1][hSP];
		elements[vSP - 1][hSP] = ' ';
		vSP -= 1;
	}
}
void moveRight()
{
	int hP = hSP;
	if (hP + 1 <= 4 && hP > 0) {

		elements[vSP][hSP] = elements[vSP][hSP - 1];
		elements[vSP][hSP - 1] = ' ';
		hSP -= 1;
	}
}
void moveLeft()
{
	int hP = hSP;
	if (hP + 1 < 4 && hP >= 0) {

		elements[vSP][hSP] = elements[vSP][hSP + 1];
		elements[vSP][hSP + 1] = ' ';
		hSP += 1;
	}
}
void randomise()
{
	for (int i = 0; i < 30; i++)
	{
		int a;
		for (;;)
		{
			a = rand() % 4 + 1; // 4 teref istiqametinde ozu qarishdirir.
			if (a == 1 && (vSP + 1 < 4 && vSP >= 0))break;  // eger yuxari gede bilirse 
			else if (a == 2 && (vSP + 1 <= 4 && vSP > 0))break;
			else if (a == 3 && (hSP + 1 <= 4 && hSP > 0))break;
			else if (a == 4 && (hSP + 1 < 4 && hSP >= 0))break;
		}

		x[index++] = a;

		switch (a)
		{
		case 1:
			moveUp();
			break;

		case 2:
			moveDown();
			break;

		case 3:
			moveRight();

			break;

		case 4:
			moveLeft();
			break;
		}
	}
}
int winer()
{
	int ans;

	for (int i = 0; i < arraySize; i++) {
		for (int j = 0; j < arraySize; j++) {
			if (elements[i][j] == check[i][j])
				ans = 1;
			else
				return -1;
		}
	}
	return 1;

}