#include <stdio.h>


int main() {
	char ch;

	ch = 'a';

	printf("sizeof(ch) is %d\n", sizeof(ch));
	printf("sizeof('a') is %d\n", sizeof('a'));

	printf("\'a\' in character format is %c.\n", ch);
	printf("\'a\' in decimal format is %d.\n", ch);

	ch = 'a' + 1;
	printf("\'a\' + 1 in character format is %c.\n", ch);

	ch = 97;
	printf("97 in character format is %c.\n", ch);
	return 0;
}