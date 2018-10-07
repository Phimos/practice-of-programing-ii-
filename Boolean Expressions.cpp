#include<iostream>

using namespace std;

bool expression_res();
bool factor_res();

char get_next_char()
{
	char c = ' ';
	while (c == ' ')
	{
		c = cin.get();
	}
	return c;
}

bool expression_res()
{
	bool res = factor_res();
	while (true)
	{
		char op = get_next_char();
		switch (op)
		{
		case '|':
			res |= factor_res();
			break;
		case '&':
			res &= factor_res();
			break;
		default:
			return res;
		}
	}
}

bool factor_res()
{
	char c = get_next_char();
	switch (c)
	{
	case'(':
		return expression_res();
	case '!':
		return !factor_res();
	case 'V':
		return true;
	case 'F':
		return false;
	}
}

int main()
{
	int cnt = 1;
	char c;
	while (c=cin.peek()!=EOF)
	{
		cout << "Expression " << cnt++ << ": " << (expression_res() ? 'V' : 'F') << endl;
	}
	return 0;
}