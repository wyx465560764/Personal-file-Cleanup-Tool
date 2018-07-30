
// Personal file Cleanup ToolDlg.h : 头文件
//

#pragma once


// CPersonalfileCleanupToolDlg 对话框
class CPersonalfileCleanupToolDlg : public CDialogEx
{
// 构造
public:
	CPersonalfileCleanupToolDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PERSONALFILECLEANUPTOOL_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton();
	afx_msg void OnBnClickedButtonTongji();
	afx_msg void OnBnClickedButtonFindbig();
	afx_msg void OnBnClickedButtonCreatfile();
	afx_msg void OnBnClickedButtonFindsame();
	afx_msg void OnBnClickedButtonClean();
};
