#include <iostream>

using namespace std;

class Set {
	char set[200];
	Set() {
		for (int i = 0; i < 200; i++)
			set[i] = ' ';
	}
public:
	char* Members() {
		return set;
	}
	int MembersCount() {
		int count = 0;
		for (int i = 0; i < 100; i++)
			if (set[i] != ' ')
				count++;
		return count;
	}
	void GetMembers() {
		gets_s(set);
	}
	void PrintMembers() {
		cout << '[';
		for (int i = 0; i < 100; i++)
			if (set[i] != ' ')
				cout << set[i]<<',';
		cout << ']';
	}
	void PrintMembers2() {
		cout << '[';
		for (int i = 0; i < 200; i++)
			if (set[i] != ' ')
				cout << set[i] << ',';
		cout << ']';
	}
	void Reformat() {
		for (int i = 0; i < 100; i++)
			for (int j = i + 1; j < 100; j++)
				if (set[i] == set[j])
					set[i - 1] = set[i];
	}
	int Add(char item) {
		for (int i = 0; i < 100; i++)
			if (set[i] == ' ') {
				set[i] = item;
				return 1;
			}
		return 0;
	}
	int Add2(char item) {
		for (int i = 0; i < 200; i++)
			if (set[i] == ' ') {
				set[i] = item;
				return 1;
			}
		return 0;
	}
	int Remove(char item) {
		for (int i = 0; i < 100; i++)
			if (set[i] == item) {
				for (int j = i; j < 100; j++)
					set[i] = set[i + 1];
				return 1;
			}
		return 0;
	}
	Set Subscription(Set S2) {
		Set Subscription;
		char* S2Members = S2.Members();
		for (int i = 0; i < 100; i++)
			if (set[i] == S2Members[i])
				Subscription.Add(set[i]);
		Subscription.Reformat();
		return Subscription;
	}
	Set Union(Set S2) {
		Set Union;
		char* S2Members = S2.Members();
		for (int i = 0; i < 100; i++) {
			Union.Add2(set[i]);
			Union.Add2(S2Members[i]);
		}
		Union.Reformat();
		return Union;
	}
	Set Difference(Set S2) {
		Set Difference;
		char* S2Members = S2.Members();
		for (int i = 0; i < 100; i++)
			for (int j = i; j < 100; j++)
				if (set[i] != S2Members[j])
					Difference.Add(set[i]);
		Difference.Reformat();
		return Difference;
	}
}S1, S2;

void main(void) {
	while (true) {
		switch (ShowMenu())
		{
		case 0:
			exit(1);
			break;
		case 1:
			system("cls");
			S1.GetMembers();
			S2.GetMembers();
			S1.Reformat();
			S2.Reformat();
			break;
		case 2:
			system("cls");
			S1.PrintMembers();
			S2.PrintMembers();
			break;
		case 3:
			system("cls");
			char item;
			cout << "\n Enter Item : ";
			cin >> item;
			if (S1.Add(item))
				cout << "\n Done !";
			else
				cout << "\n Error ! Your Set Is Full !";
			break;
		case 4:
			system("cls");
			char item;
			cout << "\n Enter Item : ";
			cin >> item;
			if (S2.Add(item))
				cout << "\n Done !";
			else
				cout << "\n Error ! Your Set Is Full !";
			break;
		case 5:
			system("cls");
			char item;
			cout << "\n Enter Item : ";
			cin >> item;
			if (S1.Remove(item))
				cout << "\n Done !";
			else
				cout << "\n Error ! Item Not Found !";
			break;
		case 6:
			system("cls");
			char item;
			cout << "\n Enter Item : ";
			cin >> item;
			if (S2.Remove(item))
				cout << "\n Done !";
			else
				cout << "\n Error ! Item Not Found !";
			break;
		case 7:
			system("cls");
			Set Subscription = S1.Subscription(S2);
			Subscription.PrintMembers();
			break;
		case 8:
			system("cls");
			Set Union = S1.Union(S2);
			Union.PrintMembers2();
			break;
		case 9:
			system("cls");
			Set Difference = S1.Difference(S2);
			Difference.PrintMembers2();
			break;
		}
		cout << endl;
		system("pause");
	}
}

int ShowMenu() {
	int item;
	cout << "\n\nMath Sets\n\n";
	cout << "1- Get Sets\n";
	cout << "2- Print Sets\n";
	cout << "3- Add Member To First Set\n";
	cout << "4- Add Member to Second Set\n";
	cout << "5- Remove From First Set\n";
	cout << "6- Remove From Second Set\n";
	cout << "7- Subscription Of Sets\n";
	cout << "8- Union Of Sets\n";
	cout << "9- Difference Of Sets\n";
	cout << "0- Exit\n\n";
	cin >> item;
	return;
}