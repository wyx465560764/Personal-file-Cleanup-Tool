// w_tongji1.cpp : 实现文件
//

#include "stdafx.h"
#include "Personal file Cleanup Tool.h"
#include "w_tongji1.h"
#include "afxdialogex.h"

// w_tongji1 对话框

IMPLEMENT_DYNAMIC(w_tongji1, CDialogEx)

w_tongji1::w_tongji1(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG_TONGJIYEMIAN, pParent)
	, m_filenum(0)
	, m_folder(_T(""))
{

}

w_tongji1::~w_tongji1()
{
}

void w_tongji1::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//  DDX_Control(pDX, IDC_EDIT2, m_filenum);
	DDX_Control(pDX, IDC_LIST1, m_fileList);
	DDX_Text(pDX, IDC_EDIT2, m_filenum);
	//  DDX_Control(pDX, IDC_BUTTON_LIULAN, m_folder);
	DDX_Text(pDX, IDC_EDIT1, m_folder);
}


BEGIN_MESSAGE_MAP(w_tongji1, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_JIANCHA, &w_tongji1::OnBnClickedButtonJiancha)
	ON_EN_CHANGE(IDC_EDIT2, &w_tongji1::OnEnChangeEdit2)
	ON_BN_CLICKED(IDC_BUTTON_LIULAN, &w_tongji1::OnBnClickedButtonLiulan)
	ON_EN_CHANGE(IDC_EDIT1, &w_tongji1::OnEnChangeEdit1)
	ON_LBN_SELCHANGE(IDC_LIST1, &w_tongji1::OnLbnSelchangeList1)
END_MESSAGE_MAP()


// w_tongji1 消息处理程序


void w_tongji1::OnBnClickedButtonJiancha()
{
	CString oldDir;//保存原始的当前路径

	UpdateData(true);//获取输入数据

	GetCurrentDirectory(50, (LPTSTR)(LPCTSTR)oldDir);//获取当前路径

	if (!SetCurrentDirectory((LPCTSTR)m_folder) || m_folder.IsEmpty())//如果有输入

	{

		m_folder = (LPCTSTR)oldDir;

		UpdateData(false);

	}

	while (m_fileList.GetCount() != 0)//清空列表框

	{

		int index = m_fileList.GetTopIndex();

		m_fileList.DeleteString(index);

	}

	FindFile1(CString(m_folder));//开始查找

	m_filenum = m_fileList.GetCount();//获取文件数目

	UpdateData(false);//编辑框显示

	SetCurrentDirectory((LPCTSTR)oldDir);//恢复当前目录
	// TODO: 在此添加控件通知处理程序代码
}


void w_tongji1::OnEnChangeEdit2()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void w_tongji1::OnBnClickedButtonLiulan()
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


void w_tongji1::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}




int w_tongji1::FindFile1(CString Curdir)
{
	HANDLE hfile;//查找文件句柄

	WIN32_FIND_DATA wfdata;//文件信息结构

	BOOL IsOver = false;//查找过程结束标志

	CString strname;//文件名

	CString strfull;//全路径

	hfile = FindFirstFile((LPCTSTR)("*.*"), &wfdata);//查找第一个文件

	if (hfile == INVALID_HANDLE_VALUE)

		IsOver = true;//查找过程结束

	while (!IsOver)

	{

		strname.Format( wfdata.cFileName);//获取找到的文件名

		strfull = Curdir + "\\" + strname;//全路径

		if ((wfdata.dwFileAttributes&FILE_ATTRIBUTE_DIRECTORY) && (wfdata.cFileName[0] != _TEXT('.')))//

		{

			SetCurrentDirectory(wfdata.cFileName);

			FindFile1(strfull);//递归调用
			SetCurrentDirectory("..");//返回当前目录

		}

		else if (wfdata.cFileName[0] != _TEXT('.'))

			m_fileList.AddString(strfull);

		IsOver = !FindNextFile(hfile, &wfdata);//查找下一个文件

	}

	FindClose(hfile);//关闭句柄
	return 0;
}


void w_tongji1::OnLbnSelchangeList1()
{
	// TODO: 在此添加控件通知处理程序代码
}
