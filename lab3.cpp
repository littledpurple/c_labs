#include <stdio.h>

int main()
{
	int len = 0, i = 1;
	int bufflen = 16;
	char *s = new char [bufflen];
	char c;
	while ((c = getchar()) != '\n') {
		s[len] = c;
		len++;
		if (len >= bufflen) {
			char *temp = new char [bufflen*2];
			memcpy (temp, s, bufflen);
			delete s;
			s = temp;
			bufflen = bufflen*2;
			}
		}
	s[len++]= '\0';
	puts ("You entered:");
	puts (s);
	for (i = 0; i < len; i++) {
		if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')) {
			switch(s[i]) {
				case 'a': s[i] = 'A'; break;
				case 'b': s[i] = 'B'; break;
				case 'c': s[i] = 'C'; break;
				case 'd': s[i] = 'D'; break;
				case 'e': s[i] = 'E'; break;
				case 'f': s[i] = 'F'; break;
				case 'g': s[i] = 'G'; break;
				case 'h': s[i] = 'H'; break;
				case 'i': s[i] = 'I'; break;
				case 'j': s[i] = 'J'; break;
				case 'k': s[i] = 'K'; break;
				case 'l': s[i] = 'L'; break;
				case 'm': s[i] = 'M'; break;
				case 'n': s[i] = 'N'; break;
				case 'o': s[i] = 'O'; break;
				case 'p': s[i] = 'P'; break;
				case 'q': s[i] = 'Q'; break;
				case 'r': s[i] = 'R'; break;
				case 's': s[i] = 'S'; break;
				case 't': s[i] = 'T'; break;
				case 'u': s[i] = 'U'; break;
				case 'v': s[i] = 'V'; break;
				case 'w': s[i] = 'W'; break;
				case 'x': s[i] = 'X'; break;
				case 'y': s[i] = 'Y'; break;
				case 'z': s[i] = 'Z'; break;
				case 'A': s[i] = 'a'; break;
				case 'B': s[i] = 'b'; break;
				case 'C': s[i] = 'c'; break;
				case 'D': s[i] = 'd'; break;
				case 'E': s[i] = 'e'; break;
				case 'F': s[i] = 'f'; break;
				case 'G': s[i] = 'g'; break;
				case 'H': s[i] = 'h'; break;
				case 'I': s[i] = 'i'; break;
				case 'J': s[i] = 'j'; break;
				case 'K': s[i] = 'k'; break;
				case 'L': s[i] = 'l'; break;
				case 'M': s[i] = 'm'; break;
				case 'N': s[i] = 'n'; break;
				case 'O': s[i] = 'o'; break;
				case 'P': s[i] = 'p'; break;
				case 'Q': s[i] = 'q'; break;
				case 'R': s[i] = 'r'; break;
				case 'S': s[i] = 's'; break;
				case 'T': s[i] = 't'; break;
				case 'U': s[i] = 'u'; break;
				case 'V': s[i] = 'v'; break;
				case 'W': s[i] = 'w'; break;
				case 'X': s[i] = 'x'; break;
				case 'Y': s[i] = 'y'; break;
				case 'Z': s[i] = 'z'; break;
				default: break;
			}
		}
	}
	puts ("Output:");
	puts (s);
}