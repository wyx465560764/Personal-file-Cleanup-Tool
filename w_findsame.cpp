// w_findsame.cpp : 实现文件
//

#include "stdafx.h"
#include "Personal file Cleanup Tool.h"
#include "w_findsame.h"
#include "afxdialogex.h"


// w_findsame 对话框

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


// w_findsame 消息处理程序



void w_findsame::OnBnClickedButton4()
{
	CString strFilter;

	strFilter = "All Files(*.*)|*.*||";

	CFileDialog dlg(TRUE, NULL, NULL, OFN_EXPLORER | OFN_HIDEREADONLY |

		OFN_ENABLESIZING | OFN_FILEMUSTEXIST, strFilter);

	if (dlg.DoModal() == IDOK) //显示打开文件对话框

	{

		m_folder = dlg.GetPathName();
		UpdateData(false);

	}
	// TODO: 在此添加控件通知处理程序代码
}
