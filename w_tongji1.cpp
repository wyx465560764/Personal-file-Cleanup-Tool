// w_tongji1.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Personal file Cleanup Tool.h"
#include "w_tongji1.h"
#include "afxdialogex.h"

// w_tongji1 �Ի���

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


// w_tongji1 ��Ϣ�������


void w_tongji1::OnBnClickedButtonJiancha()
{
	CString oldDir;//����ԭʼ�ĵ�ǰ·��

	UpdateData(true);//��ȡ��������

	GetCurrentDirectory(50, (LPTSTR)(LPCTSTR)oldDir);//��ȡ��ǰ·��

	if (!SetCurrentDirectory((LPCTSTR)m_folder) || m_folder.IsEmpty())//���������

	{

		m_folder = (LPCTSTR)oldDir;

		UpdateData(false);

	}

	while (m_fileList.GetCount() != 0)//����б��

	{

		int index = m_fileList.GetTopIndex();

		m_fileList.DeleteString(index);

	}

	FindFile1(CString(m_folder));//��ʼ����

	m_filenum = m_fileList.GetCount();//��ȡ�ļ���Ŀ

	UpdateData(false);//�༭����ʾ

	SetCurrentDirectory((LPCTSTR)oldDir);//�ָ���ǰĿ¼
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void w_tongji1::OnEnChangeEdit2()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void w_tongji1::OnBnClickedButtonLiulan()
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


void w_tongji1::OnEnChangeEdit1()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}




int w_tongji1::FindFile1(CString Curdir)
{
	HANDLE hfile;//�����ļ����

	WIN32_FIND_DATA wfdata;//�ļ���Ϣ�ṹ

	BOOL IsOver = false;//���ҹ��̽�����־

	CString strname;//�ļ���

	CString strfull;//ȫ·��

	hfile = FindFirstFile((LPCTSTR)("*.*"), &wfdata);//���ҵ�һ���ļ�

	if (hfile == INVALID_HANDLE_VALUE)

		IsOver = true;//���ҹ��̽���

	while (!IsOver)

	{

		strname.Format( wfdata.cFileName);//��ȡ�ҵ����ļ���

		strfull = Curdir + "\\" + strname;//ȫ·��

		if ((wfdata.dwFileAttributes&FILE_ATTRIBUTE_DIRECTORY) && (wfdata.cFileName[0] != _TEXT('.')))//

		{

			SetCurrentDirectory(wfdata.cFileName);

			FindFile1(strfull);//�ݹ����
			SetCurrentDirectory("..");//���ص�ǰĿ¼

		}

		else if (wfdata.cFileName[0] != _TEXT('.'))

			m_fileList.AddString(strfull);

		IsOver = !FindNextFile(hfile, &wfdata);//������һ���ļ�

	}

	FindClose(hfile);//�رվ��
	return 0;
}


void w_tongji1::OnLbnSelchangeList1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}
