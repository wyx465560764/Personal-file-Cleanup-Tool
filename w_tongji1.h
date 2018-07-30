#pragma once
#include "afxwin.h"


// w_tongji1 对话框

class w_tongji1 : public CDialogEx
{
	DECLARE_DYNAMIC(w_tongji1)

public:
	w_tongji1(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~w_tongji1();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_TONGJIYEMIAN };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonJiancha();
	afx_msg void OnEnChangeEdit2();
	afx_msg void OnBnClickedButtonLiulan();
//	CEdit m_filenum;
	afx_msg void OnEnChangeEdit1();
	CListBox m_fileList;
//	void FindFile();
//	int FindFile(int Curdir);
	int FindFile1(CString Curdir);
	int m_filenum;
//	CButton m_folder;
	CString m_folder;
	afx_msg void OnLbnSelchangeList1();
};
