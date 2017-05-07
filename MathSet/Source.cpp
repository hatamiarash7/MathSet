#include <iostream>

using namespace std;

class Set {
private:
	char set[200];
public:
	Set() {
		for (int i = 0; i < 200; i++)
			set[i] = ' ';
	}
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
	void GetMembers(char index) {
		cout << "\n Enter Set(" << index << ") : ";
		gets_s(set);
	}
	void PrintMembers() {
		cout << "\n [ ";
		for (int i = 0; i < 200; i++)
			if ((int)set[i] >= 33 && (int)set[i] <= 126)
				cout << set[i] << ' ';
		cout << ']' << endl;
	}
	void Reformat() {
		for (int i = 0; i < 200; i++)
		{
			char c = set[i];
			for (int j = i + 1; j < 200; j++)
				if (c == set[j])
					set[j] = ' ';
		}
		int sp_ind = 0;
		for (int a = 0; a < 200; a++)
		{
			if (set[a] == ' ')
				sp_ind = a;
			for (int b = a + 1; b < 200; b++)
				if (set[b] != ' ')
					std::swap(set[b], set[sp_ind]); break;
		}
	}
	int Add(char item) {
		int target = -1;
		int count = 0;
		for (int i = 0; i < 200; i++)
			if ((int)set[i] >= 33 && (int)set[i] <= 126) {
				target = i;
				count++;
			}
		if (target == -1 && count > 0)
			return 0;
		else if (target != -1 && count > 0) {
			set[target + 1] = item;
			return 1;
		}
		else if (count == 0) {
			set[0] = item;
			return 1;
		}
	}
	int Remove(char item) {
		for (int i = 0; i < 100; i++)
			if (set[i] == item) {
				for (int j = i; j < 100; j++)
					set[i] = set[i + 1];
				Reformat();
				return 1;
			}
		return 0;
	}
	void Subscription(Set S2) {
		Set Subscription;
		Set Temp;
		char* S2Members = S2.Members();
		for (int i = 0; i < 200; i++) {
			Temp.Add(set[i]);
			Temp.Add(S2Members[i]);
		}
		char* Members = Temp.Members();
		cout << "\n [ ";
		for (int i = 0; i < 200; i++)
		{
			char c = Members[i];
			for (int j = i + 1; j < 200; j++)
				if (c == Members[j] && c != ' ')
					cout << Members[i] << ' ';
		}
		cout << ']' << endl;
	}
	Set Union(Set S2) {
		Set Union;
		char* S2Members = S2.Members();
		for (int i = 0; i < 100; i++) {
			Union.Add(set[i]);
			Union.Add(S2Members[i]);
		}
		Union.Reformat();
		return Union;
	}
	Set Difference(Set Temp, Set S2) {
		char* S2Members = S2.Members();
		for (int i = 0; i < 100; i++)
			Temp.Remove(S2Members[i]);
		Temp.Reformat();
		return Temp;
	}
};

int ShowMenu();

void main(void) {
	Set S1;
	Set S2;
	while (true) {
		switch (ShowMenu())
		{
		case 0:
			exit(1);
			break;
		case 1:
			system("cls");
			S1.GetMembers('1');
			S2.GetMembers('2');
			S1.Reformat();
			S2.Reformat();
			break;
		case 2:
			system("cls");
			S1.PrintMembers();
			S2.PrintMembers();
			break;
		case 3: {
			system("cls");
			char item;
			cout << "\n Enter Item : ";
			cin >> item;
			if (S1.Add(item)) {
				cout << "\n Done !";
				S1.Reformat();
			}
			else
				cout << "\n Error ! Your Set Is Full !";
			break;
		}
		case 4: {
			system("cls");
			char item;
			cout << "\n Enter Item : ";
			cin >> item;
			if (S2.Add(item)) {
				cout << "\n Done !";
				S2.Reformat();
			}
			else
				cout << "\n Error ! Your Set Is Full !";
			break;
		}
		case 5: {
			system("cls");
			char item;
			cout << "\n Enter Item : ";
			cin >> item;
			if (S1.Remove(item))
				cout << "\n Done !";
			else
				cout << "\n Error ! Item Not Found !";
			break;
		}
		case 6: {
			system("cls");
			char item;
			cout << "\n Enter Item : ";
			cin >> item;
			if (S2.Remove(item))
				cout << "\n Done !";
			else
				cout << "\n Error ! Item Not Found !";
			break;
		}
		case 7: {
			system("cls");
			S1.Subscription(S2);
			break;
		}
		case 8: {
			system("cls");
			Set Union = S1.Union(S2);
			Union.PrintMembers();
			break;
		}
		case 9: {
			system("cls");
			Set Temp = S1;
			Set Difference = S1.Difference(Temp, S2);
			Difference.PrintMembers();
			break;
		}
		}
		cout << "\n\n ";
		system("pause");
	}
}

int ShowMenu() {
	int item;
	system("cls");
	cout << "\n\n Math Sets\n\n";
	cout << " 1- Get Sets\n";
	cout << " 2- Print Sets\n";
	cout << " 3- Add Member To First Set\n";
	cout << " 4- Add Member to Second Set\n";
	cout << " 5- Remove From First Set\n";
	cout << " 6- Remove From Second Set\n";
	cout << " 7- Subscription Of Sets\n";
	cout << " 8- Union Of Sets\n";
	cout << " 9- Difference Of Sets\n";
	cout << " 0- Exit\n\n";
	cin >> item;
	cin.ignore();
	return item;
}