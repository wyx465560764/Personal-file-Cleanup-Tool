// w_findsame.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Personal file Cleanup Tool.h"
#include "w_findsame.h"
#include "afxdialogex.h"


// w_findsame �Ի���

IMPLEMENT_DYNAMIC(w_findsame, CDialogEx)

w_findsame::w_findsame(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG_, pParent)
	, m_folder(_T(""))
{

}

w_findsame::~w_findsame()
{
}

void w_findsame::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_folder);
}


BEGIN_MESSAGE_MAP(w_findsame, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON4, &w_findsame::OnBnClickedButton4)
END_MESSAGE_MAP()


// w_findsame ��Ϣ�������



void w_findsame::OnBnClickedButton4()
{
	CString strFilter;

	strFilter = "All Files(*.*)|*.*||";

	CFileDialog dlg(TRUE, NULL, NULL, OFN_EXPLORER | OFN_HIDEREADONLY |

		OFN_ENABLESIZING | OFN_FILEMUSTEXIST, strFilter);

	if (dlg.DoModal() == IDOK) //��ʾ���ļ��Ի���

	{

		m_folder = dlg.GetPathName();
		UpdateData(false);

	}
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}
