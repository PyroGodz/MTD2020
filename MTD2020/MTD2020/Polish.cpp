#include "stdafx.h"
#include "LT.h"
#include <stack>
#include <queue>

using namespace std;

int search(int index, LEX::LexTable& ltable) //����� ���������
{
	for (int i = index; i < (unsigned int)ltable.size; i++) //������� ������
	{
		if (ltable.table[i].lexema == LEX_PLUS || ltable.table[i].lexema == LEX_MINUS
			|| ltable.table[i].lexema == LEX_STAR || ltable.table[i].lexema == LEX_DIRSLASH
			|| ltable.table[i].lexema == LEX_AND || ltable.table[i].lexema == LEX_OR
			|| ltable.table[i].lexema == LEX_NOT) //������� ��������
		{
			for (; ; i--) //���������� ������� �������
			{
				if (ltable.table[i].lexema == LEX_COMPARE || ltable.table[i].lexema == LEX_RIGHTHESIS)
					return i + 1;
			}
		}
	}
	return -1; //���� �� ����� ���������� ����� 1
}



bool PolishNotation(LEX::LexTable& ltable, ID::IdTable& itable)
{
	stack<LEX::Entry> stack;	  	// ���� ��� ��������
	queue<LEX::Entry> queue;	 	// ������� ��� ���������
	LEX::Entry temp;				//  ��� ������ �������� ����� ���������� �� ��� �������
	temp.indxTI = -1;               // ������ � ������� id
	temp.lexema = '$';
	int i = 0;						// ���������� ��������������� ������
	int posLex;						// ���������� ����� ������� ����� ���������������
	while (search(i, ltable) != -1) {

		i = search(i, ltable);
		int countLex = 0;
		posLex = i;
		while (ltable.table[i].lexema != LEX_POINT) {
			if (ltable.table[i].lexema == LEX_ID)			// ���� �������������
			{
				queue.push(ltable.table[i]);
			}
			if (ltable.table[i].lexema == LEX_LITERAL)		// ���� �������
			{
				queue.push(ltable.table[i]);				// �������� � �������
			}
			if (ltable.table[i].lexema == LEX_LEFTHESIS)	// ���� (
			{
				stack.push(ltable.table[i]);				// �������� �� � ����
			}
			if (ltable.table[i].lexema == LEX_RIGHTHESIS)	// ���� )
			{
				while (stack.top().lexema != LEX_LEFTHESIS)	// ���� �� �������� (
				{
					queue.push(stack.top());				// ����������� �� ����� � �������
					stack.pop();

					if (stack.empty())
						return false;
				}
				stack.pop();	// ���������� (
			}
			if (ltable.table[i].lexema == LEX_PLUS ||
				ltable.table[i].lexema == LEX_MINUS ||
				ltable.table[i].lexema == LEX_STAR ||
				ltable.table[i].lexema == LEX_DIRSLASH ||
				ltable.table[i].lexema == LEX_AND ||
				ltable.table[i].lexema == LEX_OR ||
				ltable.table[i].lexema == LEX_NOT)	// ���� ���� ���������
			{
				while (!stack.empty() && ltable.table[i].priority <= stack.top().priority)	// ���� ��������� �������� ��������� 
																									//������ ��� ����� ���������� ��������� � ������� �����
				{
					queue.push(stack.top());	// ����������� �� ����� � �������� ������
					stack.pop();
				}
				stack.push(ltable.table[i]);
			}
			i++; countLex++;
		}
		while (!stack.empty())	// ���� ���� �� ������
		{
			if (stack.top().lexema == LEX_LEFTHESIS || stack.top().lexema == LEX_RIGHTHESIS)
				return false;
			queue.push(stack.top());	// ����������� ��� � �������
			stack.pop();
		}
		while (countLex != 0)		// ������ �������� ��������� � ������� ������ �� ��������� � �����
		{
			if (!queue.empty()) {
				ltable.table[posLex++] = queue.front();
				queue.pop();
			}
			else
			{
				temp.sn = ltable.table[i].sn;
				ltable.table[posLex++] = temp;			// ����������� �������
			}
			countLex--;
		}
		for (int i = 0; i < posLex; i++)		// �������������� �������� ������� ��������� � ������� ������ � ���������� �� ������� ���������������
		{
			if (ltable.table[i].lexema == LEX_PLUS || ltable.table[i].lexema == LEX_MINUS || ltable.table[i].lexema == LEX_STAR || ltable.table[i].lexema == LEX_DIRSLASH || ltable.table[i].lexema == LEX_LITERAL || ltable.table[i].lexema == LEX_AND || ltable.table[i].lexema == LEX_OR || ltable.table[i].lexema == LEX_NOT)
				itable.table[ltable.table[i].indxTI].idxfirstLE = i;
		}
	}
	return true;
}