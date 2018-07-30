// w_FINDBIG.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Personal file Cleanup Tool.h"
#include "w_FINDBIG.h"
#include "afxdialogex.h"


// w_FINDBIG �Ի���

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


// w_FINDBIG ��Ϣ�������


void w_FINDBIG::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnOK();
}


void w_FINDBIG::OnBnClickedButtonFind()
{
	
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void w_FINDBIG::Find(LPCTSTR lpszFileName)
{
	{
		CString strWildcard = lpszFileName;
		strWildcard += _T("\\*.*");

		CFileFind finder;
		BOOL bFind = FALSE;

		//�����ļ�
		bFind = finder.FindFile(strWildcard);
		while (bFind)
		{
			//������һ���ļ�
			bFind = finder.FindNextFile();

			//�ж��ҵ��ļ����Ƿ����"."��".."
			if (finder.IsDots())
			{
				continue;
			}

			//����ҵ��ļ�������
			if (finder.IsDirectory())
			{
				//�ҵ��ļ���·��
				CString strFilePath = finder.GetFilePath();
				//�ݹ�����ļ�
				Find(strFilePath);
			}

			//����ҵ��ļ�������
			CString strFileName = finder.GetFileName();

			CListBox* pListBox = (CListBox*)GetDlgItem(IDC_FILELIST);
			pListBox->AddString(strFileName);
		}

		//��������
		finder.Close();
	}
}


void w_FINDBIG::OnBnClickedButtonLiulan()
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
