#pragma once


// w_findsame �Ի���

class w_findsame : public CDialogEx
{
	DECLARE_DYNAMIC(w_findsame)

public:
	w_findsame(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~w_findsame();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_ };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
//	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton4();
	CString m_folder;
};
