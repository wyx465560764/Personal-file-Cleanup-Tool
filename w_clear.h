#pragma once


// w_clear �Ի���

class w_clear : public CDialogEx
{
	DECLARE_DYNAMIC(w_clear)

public:
	w_clear(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~w_clear();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PERSONALFILECLEANUPTOOL_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
