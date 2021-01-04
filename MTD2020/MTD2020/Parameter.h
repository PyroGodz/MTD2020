#pragma once
#include "stdafx.h"
#define PARAMETER_IN L"-in:"						//���� ��� �������� �����
#define PARAMETER_LOG L"-log:"					//��� ����� ���������
#define PARAMETER_ID L"-id:"	
#define PARAMETER_LEX L"-lx:"
#define PARAMETER_RULE L"-rl"
#define PARAMETER_JSFILE L"-js"
#define PARAMETER_MAX_SIZE 300					//������������ ����� ������ ���������
#define PARAMETER_LOG_FILE_EXTENSION L".log"		//���������� ����� ��������� �� ���������
#define PARAMETER_ID_FILE_EXTENSION L".id"
#define PARAMETER_LEX_FILE_EXTENSION L".lx"
#define PARAMETER_RULE_FILE_EXTENSION L".rl"
#define PARAMETER_JS_FILE_EXTENSION L".js"

namespace Parameter
{
	struct PARAMETER
	{
		wchar_t in[PARAMETER_MAX_SIZE];			//����� ������
		wchar_t log[PARAMETER_MAX_SIZE];
		wchar_t id[PARAMETER_MAX_SIZE];
		wchar_t lx[PARAMETER_MAX_SIZE];
		wchar_t rl[PARAMETER_MAX_SIZE];
		wchar_t js[PARAMETER_MAX_SIZE];
	};
	PARAMETER getparametr(int argc, _TCHAR* argv[]);			//������������ ��������� PARM �� ������ ���������� main
};