// w_clean.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Personal file Cleanup Tool.h"
#include "w_clean.h"
#include "afxdialogex.h"


// w_clean �Ի���

IMPLEMENT_DYNAMIC(w_clean, CDialogEx)

w_clean::w_clean(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_PERSONALFILECLEANUPTOOL_DIALOG, pParent)
{

}

w_clean::~w_clean()
{
}

void w_clean::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(w_clean, CDialogEx)
END_MESSAGE_MAP()


// w_clean ��Ϣ�������
