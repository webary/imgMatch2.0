#pragma once
#ifndef __DB_TABLE_H__
#define __DB_TABLE_H__

/*
 ��Ҫ��stdafx.h����ӣ�
 #import "C:\Program Files\Common Files\system\ado\msadox.dll"
 #import "C:\Program Files\Common Files\system\ado\msado15.dll" rename("EOF","adoEOF")
*/

struct TABLE
{
	CString tableName;
	CString tvalueName[20];
};

class DB_table : public CDialog
{
	DECLARE_DYNAMIC(DB_table)
public:
	const CString m_dbName;
	const _bstr_t DBName;
	static const int tableNum = 1;
	TABLE table[tableNum];

	DB_table(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~DB_table();

	CString findData(const char* s1, int re_i = 1);
	void addRow(const char* s1, CString s2 = "", CString s3 = "");

// �Ի�������
	//enum { IDD = IDD_DB1_FORM };
	static const int TValueNums = 3;	//��ǰ�������
	char source[31];

private:
	int dataLen[tableNum];	//��ǰÿ���������ݸ���
	const CString LogDir;
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};

#endif // !__DB_TABLE_H__