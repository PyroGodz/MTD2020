#pragma once
#define LT_TABLE_SIZE 300
#define LT_MAXSIZE 4096					//������������ ���-�� ����� � ������� ������
#define LT_TI_NULLIDX 0xffffffff		//��� ��-�� ������� ����������������
#define LEX_UWHOLE 't'
#define LEX_STRING 't'
#define LEX_LOGIC 't'
#define LEX_ID 'i'
#define LEX_LITERAL 'l'
#define LEX_PROGRAM 'm'
#define LEX_IF 'w'
#define LEX_ELSE 'e'
#define LEX_MEOUT 'p'
#define LEX_FUNCTION 'f'
#define LEX_LIBFUNC 's'
#define LEX_REPAY 'r'
#define LEX_POINT '.'
#define LEX_COMMA ','
#define LEX_LEFTBRACE '['
#define LEX_RIGHTBRACE ']'
#define LEX_LEFTHESIS '('
#define LEX_RIGHTHESIS ')'
#define LEX_MORE '>'
#define LEX_LESS '<'
#define LEX_COMPARE ':'
#define LEX_EQUALLY '='
#define LEX_AND '&'
#define LEX_OR '|'
#define LEX_NOT '~'
#define LEX_PLUS '+'
#define LEX_MINUS '-'
#define LEX_STAR '*'
#define LEX_DIRSLASH '/'
#define LEX_END '\0'
#define LEX_ENDL '\n'
#define LEX_APOS '\''
#define LEX_SPACE ' '


namespace LEX
{
	struct Entry//������ ������� ������
	{
		char lexema;//�������
		int sn;//����� ������ � ������
		int indxTI;//������ � ������� ��������������� ��� LT_TI_NULLIDX
		int parm; // ���������� ���������� � �������
		char buf[LT_MAXSIZE * 2]; // ������ ��� ����� � �������� ������
		int znak;
		int priority;//��������� ��������
		int system;//������� ���������
	};
	struct LexTable//�������� ������� ������
	{
		int maxsize;//������� ������� ������( < LT_MAXSIZE)
		int size;//������� ������ ������� ������ ( < maxsize)
		Entry* table;//������ ����� ������� ������
	};

	struct Lex
	{
		wchar_t lexfile[PARAMETER_MAX_SIZE];
		std::ofstream* stream;
	};

	static const Lex FIRSTINIT = { L"", NULL };	//��� ��������� ������������� Lex
	LexTable Create(int);//������� ������� ������(������� ������� ������ < LT_MAXSIZE)
	void Add(LexTable&, Entry&);//�������� ������ � ������� ������(lextable, entry)
	Entry GetEntry(LexTable&, int);	//�������� ������ ������� ������(lextable, '����� ���������� ������')
	void Delete(LexTable&);//������� ������� ������
	Lex getlex(wchar_t lexfile[]);
	void Close(Lex lx);
	void WriteLex(Lex lx, LEX::LexTable& ltable); //�������� ������� � ����
	void WriteLexem(Lex lx, LEX::LexTable& ltable); //�������� ������� � ����
	void WriteData(Lex lx); //����� ��������
}
