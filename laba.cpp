#include <iostream>
#include <vector>
#include <Windows.h>
#include <string>
#include <fstream>
#include <conio.h>
#include <iomanip>


using namespace std;

class FootbalTeam
{
public:
	FootbalTeam(const string name, const int num)
	{
		Name = name;

		Num = num;
	}

	void print()
	{
		cout << "Название стадиона " << Name << endl;
		cout << "Количество судьей: " << Num << endl;
	}

protected:
	string Name;
	int Num = int();
};

class FirstFootbalTeam : public FootbalTeam
{
public:
	FirstFootbalTeam(const string name, const int num, const int score, const int fine) : FootbalTeam(name, num)
	{
		Name = name;
		Num = num;
		Score = score;
		Fine = fine;
	}

	void show()
	{
		cout << "Название команды: " << Name << endl;
		cout << "Количество игроков в команде: " << Num << endl;
		cout << "Количество очков команды: " << Score << endl;
		cout << "Количество штрафов команды: " << Fine << endl;
	}

private:
	int Score;
	int Fine;
};

class SecondFootbalTeam : public FootbalTeam
{
public:
	SecondFootbalTeam(const string name, const int num, const int score, const string trener) : FootbalTeam(name, num)
	{
		Name = name;
		Num = num;
		Score = score;
		Trener = trener;
	}

	void show()
	{
		cout << "Название команды: " << Num << endl;
		cout << "Количество игроков в команде: " << Name << endl;
		cout << "Количество очков команды: " << Score << endl;
		cout << "Имя тренера: " << Trener << endl;
	}

private:
	int Score;
	string Trener;
};

class ThirdFootbalTeam : public FootbalTeam
{
public:
	ThirdFootbalTeam(const string name, const int num, const int score, const int out) : FootbalTeam(name, num)
	{
		Name = name;
		Num = num;
		Score = score;
		Out = out;
	}


	void show()
	{
		cout << "Название команды: " << Num << endl;
		cout << "Количество игроков в команде: " << Name << endl;
		cout << "Количество очков команды: " << Score << endl;
		cout << "Количество аутов в команде: " << Out << endl;

	}


private:
	int Score;
	int Out;
};

string onlyWords() {
	string slovo;
	while (true) {
		int Knopka;
		char symbol;
		Knopka = _getch();
		if (Knopka == 224) {
			Knopka = _getch();
		}
		else
			if (Knopka == 8) {
				if (slovo.length() != 0) {
					cout << '\b' << " " << '\b';
					slovo.erase(slovo.length() - 1);
				}
			}
			else
				if (Knopka == 13) {
					break;
				}
				else {
					symbol = (char)Knopka;
					if ((symbol >= 'a' && symbol <= 'z') || (symbol >= 'A' && symbol <= 'Z')) {
						slovo = slovo + symbol;
						cout << symbol;
					}
				}
	}
	return slovo;
}

int inNum(int lr, int rr);
bool isNumNumeric();
bool isNumRangeCorrect(int num, int lr, int rr);

const int NUM_S = 0;
const int NUM_F = 2147483647;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << "Название стадиона  ";
	int num, score, fine, out;
	string name, trener;

	name = onlyWords();
	cout << endl;
	cout << "Введите количество судьей ";
	num = inNum(NUM_S, NUM_F);


	FootbalTeam ft(name, num);

	cout << endl;

	ft.print();

	cout << endl;

	cout << "Введите название первой команды: ";
	name = onlyWords();
	cout << endl;

	cout << "Введите количество игроков в команде: ";
	num = inNum(NUM_S, NUM_F);
	cout << endl;

	cout << "Введите количество очков команды: ";
	score = inNum(NUM_S, NUM_F);
	cout << endl;

	cout << "Введите количество штрафов команды: ";
	fine = inNum(NUM_S, NUM_F);

	cout << endl;

	FirstFootbalTeam fft(name, num, score, fine);

	cout << endl;

	fft.show();

	cout << endl;

	cout << "Введите название второй команды: ";
	name = onlyWords();
	cout << endl;

	cout << "Введите количество игроков в команде: ";
	num = inNum(NUM_S, NUM_F);
	cout << endl;


	cout << "Введите количество очков команды: ";
	score = inNum(NUM_S, NUM_F);
	cout << endl;


	cout << "Введите имя тренера: ";
	trener = onlyWords();

	SecondFootbalTeam sft(name, num, score, trener);

	cout << endl;

	sft.show();

	cout << endl;

	cout << "Введите название третьей команды: ";
	name = onlyWords();
	cout << endl;

	cout << "Введите количество игроков в команде: ";
	num = inNum(NUM_S, NUM_F);
	cout << endl;


	cout << "Введите количество очков команды: ";
	score = inNum(NUM_S, NUM_F);
	cout << endl;

	cout << "Введите количество аутов в команде: ";
	out = inNum(NUM_S, NUM_F);

	cout << endl;

	ThirdFootbalTeam tft(name, num, score, out);

	cout << endl;

	tft.show();

	return 0;
}

int inNum(int lr, int rr)
{
	int num;
	int vol = 1;

	while (true)
	{
		cin >> num;
		if (isNumNumeric() && isNumRangeCorrect(num, lr, rr)) return num;
		cout << "Некорректный ввод! Введите числа в дипазоне от " << lr << " по " << rr << ": ";
	}
}
bool isNumNumeric()
{
	if (cin.get() == '\n') return true;
	else
	{
		cin.clear();
		cin.ignore(256, '\n');
		return false;
	}
}
bool isNumRangeCorrect(int num, int lr, int rr) { return (lr <= num && num <= rr); }



