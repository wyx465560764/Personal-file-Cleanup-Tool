// w_clean1.cpp : ʵ���ļ�
//
#define_CRT_SECURE_NO_DEPRECATE
#include "stdafx.h"
#include "Personal file Cleanup Tool.h"
#include "w_clean1.h"
#include "afxdialogex.h"


// w_clean1 �Ի���

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


// w_clean1 ��Ϣ�������


void w_clean1::OnBnClickedButton1()
{
	//����ָ��IMalloc��ָ��

	LPMALLOC  pMalloc;

	if (::SHGetMalloc(&pMalloc) != NOERROR)

		return; // failed to get allocator

	char szDisplayName[_MAX_PATH];

	char szBuffer[_MAX_PATH];

	BROWSEINFO browseInfo; //����Ի���ṹ

	browseInfo.hwndOwner = this->m_hWnd;

	browseInfo.pidlRoot = NULL; //���ø�Ŀ¼Ϊ����

	browseInfo.pszDisplayName = szDisplayName;

	browseInfo.lpszTitle = "ѡ��ɾ���ļ���Ŀ¼";   //�Ի������

	browseInfo.ulFlags = BIF_RETURNFSANCESTORS | BIF_RETURNONLYFSDIRS;

	browseInfo.lpfn = NULL;     //δ��

	browseInfo.lParam = 0;       //δ��

	LPITEMIDLIST lpItemIDList;

	if ((lpItemIDList = ::SHBrowseForFolder(&browseInfo)) != NULL)

	{

		//�õ�Ŀ¼��·��

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

			AfxMessageBox("���ܵõ���ѡ���ļ��У�", MB_ICONSTOP | MB_OK);

			return;

		}

		pMalloc->Free(lpItemIDList);

		pMalloc->Release();

	}

	DisplayFileList(m_strFolder);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void w_clean1::OnBnClickedButton2()
{
	UpdateData(true);

	CString m_extern;

	switch (m_radio) //��ȡҪɾ���ļ����͵ĺ�׺��

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

	if (m_strFolder != "" && m_extern != "")//��ǰĿ¼���ļ����Ͳ�Ϊ��

	{

		CString str, strdel;

		//��������"C:\\My Documents\\*.txt"������

		char string[60];

		strcpy(string, m_strFolder);

		strcat(string, "\\*");

		strcat(string, m_extern);

		CFileFind filefind;

		if (filefind.FindFile(string, 0) != 0)//���������ļ�

		{

			while (filefind.FindNextFile() != 0)

			{

				strdel = filefind.GetFilePath();//��ȡ�ļ���

				CFile::Remove(strdel);//ɾ���ļ�

			}

			strdel = filefind.GetFilePath();

			CFile::Remove(strdel);

			AfxMessageBox("�ļ�ɾ����ɣ�");

			DisplayFileList(m_strFolder);//������ʾ�б��

		}

		else

		{

			AfxMessageBox("��ǰĿ¼�£�û���������͵��ļ���");

		}

	}

	else

		AfxMessageBox("��ѡ��Ŀ¼��");
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}

	void w_clean1::DisplayFileList(CString strdir)
	{
		TCHAR szPath[MAX_PATH];

		strcpy(szPath, strdir);

		//DlgDirList����������ListBox�м���ĳ·���µ��ļ�

		int nReslt = DlgDirList(

			szPath,//Ŀ¼

			IDC_LIST1,//ListBox����ԴID

			0,//��ǰѡ�����������·���ľ�̬�ؼ�ID�����������ʾ��Щ��������·������Ϊ0

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
		// TODO: �ڴ���ӿؼ�֪ͨ����������
	}
