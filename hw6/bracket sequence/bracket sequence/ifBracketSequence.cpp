#include "ifBracketSequence.h"

bool ifBracketSequenceIsCorrect(string const & str)
{
	Stack s;
	bool ifSequenceIsCorrect = true;
	for (int i = 0; i < str.size(); ++i)
	{
		if (isBracket(s, str[i]))
		{
			if (s.isEmpty())
			{
				ifSequenceIsCorrect = ifNotClosingBracketToEmptyStack(s, str[i]);
				if (!ifBracketSequenceIsCorrect)
				{
					return ifSequenceIsCorrect;
				}
			}
			else
			{
				if (str[i] == ')' || str[i] == ']' || str[i] == '}')
				{
					if (s.peek() == ')' || s.peek() == ']' || s.peek() == '}')
					{
						ifSequenceIsCorrect = false;
						return ifBracketSequenceIsCorrect;
					}
					// ���� �����������, �� ��������� ���� �� ���, ���� ��, �� ����� �� �����
				}
				else
				{
					// � �� ��� �� ��- �� ��, ���� ��, �� ������� �� ����� ������
				}
			}
		}
	}
}

bool isBracket(Stack const & s, char const symbol)
{
	if (symbol == '(' || symbol == ')' || symbol == '[' || symbol == ']' ||
			symbol == '{' || symbol == '}')
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool ifClosingBracket(Stack const & s, char const symbol)
{

}

bool ifNotClosingBracketToEmptyStack(Stack & s, char const symbol)
{
	if (symbol == ')' || symbol == ']' || symbol == '}')
	{
		return false;
	}
	else
	{
		s.push(symbol);
		return true;
	}
}

bool ifSameTypeOfBracket