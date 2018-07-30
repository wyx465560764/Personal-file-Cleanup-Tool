#pragma once
#include "afxwin.h"


// w_FINDBIG 对话框

class w_FINDBIG : public CDialogEx
{
	DECLARE_DYNAMIC(w_FINDBIG)

public:
	w_FINDBIG(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~w_FINDBIG();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_FINDBIG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedButtonFind();
//	int Find(LPCTSTR lpszFileName);
	void Find(LPCTSTR lpszFileName);
	afx_msg void OnBnClickedButtonLiulan();
//	CEdit m_folder;
	CString m_folder;
};
