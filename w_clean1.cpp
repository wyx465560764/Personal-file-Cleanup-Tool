// w_clean1.cpp : 实现文件
//
#define_CRT_SECURE_NO_DEPRECATE
#include "stdafx.h"
#include "Personal file Cleanup Tool.h"
#include "w_clean1.h"
#include "afxdialogex.h"


// w_clean1 对话框

IMPLEMENT_DYNAMIC(w_clean1, CDialogEx)


w_clean1::w_clean1(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG_CLEAR, pParent)
	, m_strFolder(_T(""))
	, m_radio(0)
{

}

w_clean1::~w_clean1()
{
}

void w_clean1::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//  DDX_Control(pDX, IDC_LIST1, m_strFolder);
	DDX_Text(pDX, IDC_EDIT1, m_strFolder);
}


BEGIN_MESSAGE_MAP(w_clean1, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &w_clean1::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &w_clean1::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_RADIO_BAK, &w_clean1::OnBnClickedRadioBak)
END_MESSAGE_MAP()


// w_clean1 消息处理程序


void w_clean1::OnBnClickedButton1()
{
	//定义指向IMalloc的指针

	LPMALLOC  pMalloc;

	if (::SHGetMalloc(&pMalloc) != NOERROR)

		return; // failed to get allocator

	char szDisplayName[_MAX_PATH];

	char szBuffer[_MAX_PATH];

	BROWSEINFO browseInfo; //构造对话框结构

	browseInfo.hwndOwner = this->m_hWnd;

	browseInfo.pidlRoot = NULL; //设置根目录为桌面

	browseInfo.pszDisplayName = szDisplayName;

	browseInfo.lpszTitle = "选择删除文件的目录";   //对话框标题

	browseInfo.ulFlags = BIF_RETURNFSANCESTORS | BIF_RETURNONLYFSDIRS;

	browseInfo.lpfn = NULL;     //未用

	browseInfo.lParam = 0;       //未用

	LPITEMIDLIST lpItemIDList;

	if ((lpItemIDList = ::SHBrowseForFolder(&browseInfo)) != NULL)

	{

		//得到目录的路径

		if (::SHGetPathFromIDList(lpItemIDList, szBuffer))

		{

			if (szBuffer[0] == '\0')

			{

				return;

			}

			m_strFolder = szBuffer;

			UpdateData(false);

		}

		else

		{

			AfxMessageBox("不能得到所选的文件夹！", MB_ICONSTOP | MB_OK);

			return;

		}

		pMalloc->Free(lpItemIDList);

		pMalloc->Release();

	}

	DisplayFileList(m_strFolder);
	// TODO: 在此添加控件通知处理程序代码
}


void w_clean1::OnBnClickedButton2()
{
	UpdateData(true);

	CString m_extern;

	switch (m_radio) //获取要删除文件类型的后缀名

	{

	case 0:

		GetDlgItem(IDC_RADIO_BAK)->GetWindowText(m_extern);

		break;

	case 1:

		GetDlgItem(IDC_RADIO_TMP)->GetWindowText(m_extern);

		break;

	case 2:

		GetDlgItem(IDC_RADIO_TEMP)->GetWindowText(m_extern);

		break;


	}

	if (m_strFolder != "" && m_extern != "")//当前目录和文件类型不为空

	{

		CString str, strdel;

		//构造类似"C:\\My Documents\\*.txt"的类型

		char string[60];

		strcpy(string, m_strFolder);

		strcat(string, "\\*");

		strcat(string, m_extern);

		CFileFind filefind;

		if (filefind.FindFile(string, 0) != 0)//遍历搜索文件

		{

			while (filefind.FindNextFile() != 0)

			{

				strdel = filefind.GetFilePath();//获取文件名

				CFile::Remove(strdel);//删除文件

			}

			strdel = filefind.GetFilePath();

			CFile::Remove(strdel);

			AfxMessageBox("文件删除完成！");

			DisplayFileList(m_strFolder);//更新显示列表框

		}

		else

		{

			AfxMessageBox("当前目录下，没有这种类型的文件！");

		}

	}

	else

		AfxMessageBox("请选择目录！");
	// TODO: 在此添加控件通知处理程序代码
}

	void w_clean1::DisplayFileList(CString strdir)
	{
		TCHAR szPath[MAX_PATH];

		strcpy(szPath, strdir);

		//DlgDirList函数用于向ListBox中加入某路径下的文件

		int nReslt = DlgDirList(

			szPath,//目录

			IDC_LIST1,//ListBox的资源ID

			0,//当前选择的驱动器和路径的静态控件ID，如果不用显示这些驱动器和路径，置为0

			DDL_READWRITE | DDL_READONLY | DDL_HIDDEN | DDL_SYSTEM | DDL_ARCHIVE);
	}


	void w_clean1::OnChangeEdit1()
	{
		// TODO: Add your control notification handler code here

		UpdateData(true);

		DisplayFileList(m_strFolder);
	}


	void w_clean1::OnBnClickedRadioBak()
	{
		// TODO: 在此添加控件通知处理程序代码
	}
