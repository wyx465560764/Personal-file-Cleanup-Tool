#pragma once


// w_findsame 对话框

class w_findsame : public CDialogEx
{
	DECLARE_DYNAMIC(w_findsame)

public:
	w_findsame(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~w_findsame();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_ };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
//	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton4();
	CString m_folder;
};
