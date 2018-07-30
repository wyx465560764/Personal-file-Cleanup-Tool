#pragma once


// w_clear 对话框

class w_clear : public CDialogEx
{
	DECLARE_DYNAMIC(w_clear)

public:
	w_clear(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~w_clear();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PERSONALFILECLEANUPTOOL_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
