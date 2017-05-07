#include <iostream>

using namespace std;

class Set {
	char set[100];
	Set() { for (int i = 0; i < 100; i++) set[i] = ' '; }
public:
	char* GetMembers() { return set; }
	int GetMembersCount() {
		int count = 0;
		for (int i = 0; i < 100; i++)
			if (set[i] != ' ')
				count++;
		return count;
	}
	Set Union(Set S2) {
		char* S2Members = S2.GetMembers();
	}
}S1,S2;

void main(void) {

}