#pragma once


// w_clean 对话框

class w_clean : public CDialogEx
{
	DECLARE_DYNAMIC(w_clean)

public:
	w_clean(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~w_clean();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PERSONALFILECLEANUPTOOL_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
