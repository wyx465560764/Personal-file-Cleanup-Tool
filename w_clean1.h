#pragma once
#include "afxwin.h"


// w_clean1 �Ի���

class w_clean1 : public CDialogEx
{
	DECLARE_DYNAMIC(w_clean1)

public:
	w_clean1(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~w_clean1();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_CLEAR };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
//	void DisplayFileList();
	void DisplayFileList(CString strdir);
	void OnChangeEdit1();
//	CListBox m_strFolder;
	CString m_strFolder;
//	int m_radio;
	int m_radio;
	afx_msg void OnBnClickedRadioBak();
};
