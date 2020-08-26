#include <stdio.h>
int main(void) {
	int i, j, x, y, k=5, h = 6, count = 0, no = 0, sum = 0, l, a, b,c;
	char hanoi[6][33] = { 0 };
	for (x = 0; x < 5; x++) {
		for (y = 0; y < 33; y++) {
			hanoi[x][y] = ' ';
		}
	}
	for (x = 0; x < 5; x++) {
		for (y = k; y < h; y++) {
			hanoi[x][y] = '-';
		}
		k--;
		h++;
		hanoi[x][16] = '|';
		hanoi[x][27] = '|';
	}
	for (y = 0; y < 33; y++) {
		hanoi[5][y] = '=';
	}
	
	do {
		l = a = b = 0;
		// Source code for showing tower of Hanoi here....
		for (x = 0; x < 5; x++) {
			for (y = 0; y < 10; y++) {
				if (hanoi[x][y] == '-')	l += 1;
			}
			if (l > 0)	break;
		}
		for (x = 0; x < 5; x++) {
			for (y = 12; y < 21; y++) {
				if (hanoi[x][y] == '-')	a += 1;
			}
			if (a > 0)	break;
		}
		for (x = 0; x < 5; x++) {
			for (y = 23; y < 32; y++) {
				if (hanoi[x][y] == '-')	b += 1;
			}
			if (b > 0)	break;
		}
		for (x = 0; x < 6; x++) {
			for (y = 0; y < 33; y++) {
				printf("%c", hanoi[x][y]);
			}
			printf("\n");
		}

		printf("Move a disc: ");
		scanf_s("%d %d", &i, &j);
	
		if (i == j) {
			printf("Two numbers should be different!\n");
			continue;
		}
		else if (i <= 0 || i > 3 || j <= 0 || j > 3) {
			printf("Wrong number!\n");
			continue;
		}
		else if (i == 1) {
			if (hanoi[4][5] == '|') {
				printf("No disc in peg %d\n", i);
				continue;
			}
			if (a!=0 || b!=0) {
				if (j == 2 && l > a && a != 0) {
					printf("Disc cannot move!\n");	continue;
				}
				if (j == 3 && l > b && b != 0) {
					printf("Disc cannot move!\n");	continue;
				}
			}
		}
		
		else if (i == 2) {
			if (hanoi[4][16] == '|') {
				printf("No disc in peg %d\n", i);
				continue;
			}
			if (l!=0 || b!=0) {
				if (j == 1 && a > l && l != 0) {
					printf("Disc cannot move!\n");	continue;
				}
				if (j == 3 && a > b && b != 0) {
					printf("Disc cannot move!\n");	continue;
				}
			}
		}
		else if (i == 3) {
			if (hanoi[4][27] == '|') {
				printf("No disc in peg %d\n", i);
				continue;
			}
			if (l!=0 || a!=0) {
				if (j == 2 && b > a && a != 0) {
					printf("Disc cannot move!\n");	continue;
				}
				if (j == 1 && b > l && l != 0) {
					printf("Disc cannot move!\n");	continue;
				}
			}
		}
		sum = count = no = 0;
			// Source code for changing status of discs here...
		switch (i) {
			case 1:
				for (x = 0; x < 5; x++) {
					for (y = 0; y < 10; y++) {
						if (hanoi[x][y] == '-') {
							if (y != 5)	hanoi[x][y] = ' ';
							else	hanoi[x][y] = '|';
							count += 1;
						}
					}
					if (count > 0)	break;
				}	break;
			case 2:
				for (x = 0; x < 5; x++) {
					for (y = 12; y < 21; y++) {
						if (hanoi[x][y] == '-') {
							if (y != 16)	hanoi[x][y] = ' ';
							else	hanoi[x][y] = '|';
							count += 1; 
						}
					}
					if (count > 0)	break;
				}	break;
			case 3:
				for (x = 0; x < 5; x++) {
					for (y = 23; y < 32; y++) {
						if (hanoi[x][y] == '-') {
							if (y != 27)	hanoi[x][y] = ' ';
							else	hanoi[x][y] = '|';
							count += 1;
						}
					}
					if (count > 0)	break;
				}	break;
		}

			if (j == 1) {
				switch (count) {
				case 1:		h = 5;	break;
				case 3:		h = 4;	break;
				case 5:		h = 3;	break;
				case 7:		h = 2;	break;
				case 9:		h = 1;	break;
				}
			}
			else if (j == 2) {
				switch (count) {
				case 1:		h = 16;		break;
				case 3:		h = 15;		break;
				case 5:		h = 14;		break;
				case 7:		h = 13;		break;
				case 9:		h = 12;		break;
				}
			}
			else if (j == 3) {
				switch (count) {
				case 1:		h = 27;		break;
				case 3:		h = 26;		break;
				case 5:		h = 25;		break;
				case 7:		h = 24;		break;
				case 9:		h = 23;		break;
				}
			}
			switch (j) {
			case 1:
				for (x = 4; x >= 0; x--) {
					for (y = 1; y < 10; y++) {
						if (hanoi[x][y] == '-')	continue;
						else if (hanoi[x][y] != ' '&& hanoi[x][y] == '|') {
							for (k = h; k < h + count; k++) {
								hanoi[x][k] = '-';
								no += 1;
							}
						}
						if (no > 0)	break;
					}
					if (no > 0)	break;
				}
				for (x = 4; x >= 0; x--) {
					for (y = 1; y < 10; y++) {
						if (hanoi[x][y] == '-')	sum += 1;
					}
				}
				c = 1;
				break;
			case 2:
				for (x = 4; x >= 0; x--) {
					for (y = 12; y < 21; y++) {
						if (hanoi[x][y] == '-')	continue;
						else if (hanoi[x][y] != ' '&& hanoi[x][y] == '|') {
							for (k = h; k < h + count; k++) {
								hanoi[x][k] = '-';
								no += 1;
							}
						}
						if (no > 0)	break;
					}
					if (no > 0)	break;
				}	
				for (x = 4; x >= 0; x--) {
					for (y = 12; y < 21; y++) {
						if (hanoi[x][y] == '-')	sum += 1;
					}
				}
				c = 0;
				break;
			case 3:
				for (x = 4; x >= 0; x--) {
					for (y = 23; y < 32; y++) {
						if (hanoi[x][y] == '-')	continue;
						else if (hanoi[x][y] != ' '&& hanoi[x][y] == '|') {
							for (k = h; k < h + count; k++) {
								hanoi[x][k] = '-';
								no += 1;
							}
						}
						if (no > 0)	break;
					}
					if (no > 0)	break;
				}	
				for (x = 4; x >= 0; x--) {
					for (y = 23; y < 32; y++) {
						if (hanoi[x][y] == '-')	sum += 1;
					}
				}
				c = 0;
				break;
			}
		if (sum == 25 && c == 1)		sum = 0;
		
	} while (sum != 25);	//Remove 1 and put your own loop condition...
	for (x = 0; x < 6; x++) {
		for (y = 0; y < 33; y++) {
			printf("%c", hanoi[x][y]);
		}
		printf("\n");
	}
	printf("\n");
	printf("Congratulations! But don\'t worry. The world will not end!\n");
	return 0;
}
