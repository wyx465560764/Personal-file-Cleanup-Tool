// w_FINDBIG.cpp : 实现文件
//

#include "stdafx.h"
#include "Personal file Cleanup Tool.h"
#include "w_FINDBIG.h"
#include "afxdialogex.h"


// w_FINDBIG 对话框

IMPLEMENT_DYNAMIC(w_FINDBIG, CDialogEx)

w_FINDBIG::w_FINDBIG(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG_FINDBIG, pParent)
	, m_folder(_T(""))
{

}

w_FINDBIG::~w_FINDBIG()
{
}

void w_FINDBIG::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//  DDX_Control(pDX, IDC_EDIT1, m_folder);
	DDX_Text(pDX, IDC_EDIT1, m_folder);
}


BEGIN_MESSAGE_MAP(w_FINDBIG, CDialogEx)
	ON_BN_CLICKED(IDOK, &w_FINDBIG::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON_FIND, &w_FINDBIG::OnBnClickedButtonFind)
	ON_BN_CLICKED(IDC_BUTTON_LIULAN, &w_FINDBIG::OnBnClickedButtonLiulan)
END_MESSAGE_MAP()


// w_FINDBIG 消息处理程序


void w_FINDBIG::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
}


void w_FINDBIG::OnBnClickedButtonFind()
{
	
	// TODO: 在此添加控件通知处理程序代码
}


void w_FINDBIG::Find(LPCTSTR lpszFileName)
{
	{
		CString strWildcard = lpszFileName;
		strWildcard += _T("\\*.*");

		CFileFind finder;
		BOOL bFind = FALSE;

		//查找文件
		bFind = finder.FindFile(strWildcard);
		while (bFind)
		{
			//查找下一个文件
			bFind = finder.FindNextFile();

			//判断找到文件的是否包含"."或".."
			if (finder.IsDots())
			{
				continue;
			}

			//获得找到文件的名称
			if (finder.IsDirectory())
			{
				//找到文件的路径
				CString strFilePath = finder.GetFilePath();
				//递归查找文件
				Find(strFilePath);
			}

			//获得找到文件的名称
			CString strFileName = finder.GetFileName();

			CListBox* pListBox = (CListBox*)GetDlgItem(IDC_FILELIST);
			pListBox->AddString(strFileName);
		}

		//结束查找
		finder.Close();
	}
}


void w_FINDBIG::OnBnClickedButtonLiulan()
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
