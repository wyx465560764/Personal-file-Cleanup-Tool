#pragma once


// w_creatfile �Ի���

class w_creatfile : public CDialogEx
{
	DECLARE_DYNAMIC(w_creatfile)

public:
	w_creatfile(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~w_creatfile();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_CREATFILE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonCreat();
};
