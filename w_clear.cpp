// w_clear.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Personal file Cleanup Tool.h"
#include "w_clear.h"
#include "afxdialogex.h"


// w_clear �Ի���

IMPLEMENT_DYNAMIC(w_clear, CDialogEx)

w_clear::w_clear(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_PERSONALFILECLEANUPTOOL_DIALOG, pParent)
{

}

w_clear::~w_clear()
{
}

void w_clear::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(w_clear, CDialogEx)
END_MESSAGE_MAP()


// w_clear ��Ϣ�������
