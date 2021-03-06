/* Generated by re2c 0.13.5 on Tue Apr 19 21:34:51 2011 */
#include <stdio.h>
#include <stdlib.h>

enum {
  CMD, INT, FLOAT, SPACE, END
};

int scan(char** p, char** lex)
{
        char* marker;
	if (lex) *lex = *p;

	{
		unsigned char yych;

		yych = (unsigned char)**p;
		if (yych <= '9') {
			if (yych <= 0x1F) {
				if (yych == '\t') goto yy8;
				goto yy10;
			} else {
				if (yych <= ' ') goto yy8;
				if (yych <= '/') goto yy10;
				goto yy6;
			}
		} else {
			if (yych <= 'F') {
				if (yych == 'E') goto yy5;
				goto yy10;
			} else {
				if (yych <= 'G') goto yy2;
				if (yych == 'P') goto yy4;
				goto yy10;
			}
		}
yy2:
		yych = (unsigned char)*(marker = ++*p);
		if (yych == 'E') goto yy24;
yy3:
		{ return END; }
yy4:
		yych = (unsigned char)*(marker = ++*p);
		if (yych == 'U') goto yy23;
		goto yy3;
yy5:
		yych = (unsigned char)*(marker = ++*p);
		if (yych == 'X') goto yy18;
		goto yy3;
yy6:
		++*p;
		if ((yych = (unsigned char)**p) == '.') goto yy13;
		if (yych <= '/') goto yy7;
		if (yych <= '9') goto yy16;
yy7:
		{ return INT; }
yy8:
		++*p;
		yych = (unsigned char)**p;
		goto yy12;
yy9:
		{ return SPACE; }
yy10:
		yych = (unsigned char)*++*p;
		goto yy3;
yy11:
		++*p;
		yych = (unsigned char)**p;
yy12:
		if (yych == '\t') goto yy11;
		if (yych == ' ') goto yy11;
		goto yy9;
yy13:
		++*p;
		yych = (unsigned char)**p;
		if (yych <= '/') goto yy15;
		if (yych <= '9') goto yy13;
yy15:
		{ return FLOAT; }
yy16:
		++*p;
		yych = (unsigned char)**p;
		if (yych == '.') goto yy13;
		if (yych <= '/') goto yy7;
		if (yych <= '9') goto yy16;
		goto yy7;
yy18:
		yych = (unsigned char)*++*p;
		if (yych == 'I') goto yy20;
yy19:
		*p = marker;
		goto yy3;
yy20:
		yych = (unsigned char)*++*p;
		if (yych != 'T') goto yy19;
yy21:
		++*p;
		{ return CMD; }
yy23:
		yych = (unsigned char)*++*p;
		if (yych == 'T') goto yy21;
		goto yy19;
yy24:
		++*p;
		if ((yych = (unsigned char)**p) == 'T') goto yy21;
		goto yy19;
	}

}


int main(int argc, char* argv[]) {
  char *p, *last;
  int token;
  if (argc < 2) return 1;

  p = argv[1];
  while ((token = scan(&p, &last)) != END) {
    int sz = p - last;
    switch (token) {
      case CMD: printf("Command: '%.*s'\n", sz, last); break;
      case INT: printf("Number: '%.*s'\n", sz, last); break;
      case FLOAT: printf("Float: '%.*s'\n", sz, last); break;
    }
  }

  return 0;
}
