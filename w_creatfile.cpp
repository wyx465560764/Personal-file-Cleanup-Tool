// w_creatfile.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Personal file Cleanup Tool.h"
#include "w_creatfile.h"
#include "afxdialogex.h"


// w_creatfile �Ի���

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


// w_creatfile ��Ϣ�������


void w_creatfile::OnBnClickedButtonCreat()
{
	CString m_strFolderPath = _T("C:\\path");
	if (!PathIsDirectory(m_strFolderPath))
	{
		CString strMsg;
		strMsg.Format(_T("ָ��·��\"%s\"�����ڣ��Ƿ񴴽�?"), m_strFolderPath);
		if (AfxMessageBox(strMsg, MB_YESNO) == IDYES)
		{
			if (!CreateDirectory(m_strFolderPath, NULL))
			{
				strMsg.Format(_T("����·��\"%s\"ʧ�ܣ��Ƿ����?"), m_strFolderPath);
				if (AfxMessageBox(strMsg, MB_YESNO) == IDYES)
					return;
			}
		}

	}
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}
