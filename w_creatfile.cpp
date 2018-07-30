// w_creatfile.cpp : 实现文件
//

#include "stdafx.h"
#include "Personal file Cleanup Tool.h"
#include "w_creatfile.h"
#include "afxdialogex.h"


// w_creatfile 对话框

IMPLEMENT_DYNAMIC(w_creatfile, CDialogEx)

w_creatfile::w_creatfile(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG_CREATFILE, pParent)
{

}

w_creatfile::~w_creatfile()
{
}

void w_creatfile::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(w_creatfile, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_CREAT, &w_creatfile::OnBnClickedButtonCreat)
END_MESSAGE_MAP()


// w_creatfile 消息处理程序


void w_creatfile::OnBnClickedButtonCreat()
{
	CString m_strFolderPath = _T("C:\\path");
	if (!PathIsDirectory(m_strFolderPath))
	{
		CString strMsg;
		strMsg.Format(_T("指定路径\"%s\"不存在，是否创建?"), m_strFolderPath);
		if (AfxMessageBox(strMsg, MB_YESNO) == IDYES)
		{
			if (!CreateDirectory(m_strFolderPath, NULL))
			{
				strMsg.Format(_T("创建路径\"%s\"失败！是否继续?"), m_strFolderPath);
				if (AfxMessageBox(strMsg, MB_YESNO) == IDYES)
					return;
			}
		}

	}
	// TODO: 在此添加控件通知处理程序代码
}
