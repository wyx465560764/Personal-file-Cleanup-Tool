#pragma once


// w_clean �Ի���

class w_clean : public CDialogEx
{
	DECLARE_DYNAMIC(w_clean)

public:
	w_clean(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~w_clean();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PERSONALFILECLEANUPTOOL_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
