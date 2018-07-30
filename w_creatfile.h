#pragma once


// w_creatfile 对话框

class w_creatfile : public CDialogEx
{
	DECLARE_DYNAMIC(w_creatfile)

public:
	w_creatfile(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~w_creatfile();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_CREATFILE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonCreat();
};
