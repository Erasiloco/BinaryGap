#define _CRT_SECURE_NO_WARNINGS


#include <stdio.h>
#include <string.h>

typedef enum { false, true } bool;

struct gap
{
	int number;
	char* binRep;
	int maxGapLength;
};

int bin(int, char*);
int solution(int);

int main() {
	if (solution(7) != 0) printf("failed for 7.");
	if (solution(9) != 2) printf("failed for 9.");
	if (solution(15) != 0) printf("failed, because 15 has binary representation 1111.");
	if (solution(20) != 1) printf("failed, because 20 has binary representation 10100.");
	if (solution(32) != 0) printf("failed, because 32 has binary representation 100000.");
	if (solution(529) != 4) printf("failed for 529.");
	if (solution(1041) != 5) printf("failed, because 1041 has binary representation 10000010001.");
	system("pause");
	return 0;
}


int bin(int N, char* binRep) {
	if (N == 1) {
		return 1;
	}
	else if (N % 2 == 0){
		int index = bin(N / 2, binRep);
		binRep[index] = '0';
		return ++index;
	}
	else {
		int index = bin(N / 2, binRep);
		binRep[index] = '1';
		return ++index;
	}
		
}

int solution(int N)
{
	char binRep[32];
	binRep[0] = (N > 0) ? '1' : '0';
	int nn = 0;
	if(N > 0) nn = bin(N, binRep);
	
	int maxGapLength = 0, gapLength = 0;
	bool started = false;
	for (int t = 0; t < nn; t++) {
		if (binRep[t] == '1' && started == false) {
			started = true;
			continue;
		}
		else if (binRep[t] == '1' && started == true) {
			started = false;
			maxGapLength = (maxGapLength < gapLength) ? gapLength : maxGapLength;
		}
		else if (binRep[t] == '0' && started == true) {
			gapLength++;
		}
	}
	return maxGapLength;
}