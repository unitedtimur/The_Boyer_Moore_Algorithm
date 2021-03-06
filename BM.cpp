#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

/*
*
*Created by UnitedTimur
*
*/


int SearchBM(char *String, char *Subject);

int main(void) {

	char String[255];
	char Subject[255];

	printf("Enter the String, please: ");
	gets_s(String);

	printf("Enter the Subject, please: ");
	gets_s(Subject);

	if (SearchBM(String, Subject) != -1) {
		printf("match index = %d\n", SearchBM(String, Subject));
	}
	else {
		printf("Error #1. Try again ;( \n");
	}

	unsigned int Time = clock() / 1000;
	printf("Time work this program equally %d's\n", Time);


	system("PAUSE");
}

int SearchBM(char *String, char *Subject) {

	unsigned int SizeString = strlen(String);
	unsigned int SizeSubject = strlen(Subject);

	int Table[256];

	for (int i = 0; i < 256; i++) {
		Table[i] = SizeSubject;
	}

	for (int i = 0; i < SizeSubject - 1; i++) {
		Table[Subject[i]] = SizeSubject - 1 - i;
	}

	int key = 0,
		j = SizeSubject - 1,
		i = SizeSubject - 1;

	while (i < SizeString) {

		key = i;
		j = SizeSubject - 1;

		while (String[key] == Subject[j]) {
			key--;
			j--;
		}

		if (j < 0) {
			return i - SizeSubject + 1;
		}

		i += Table[String[key]];

	}

	return -1;

}
