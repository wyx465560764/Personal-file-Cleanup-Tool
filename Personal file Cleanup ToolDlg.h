
// Personal file Cleanup ToolDlg.h : ͷ�ļ�
//

#pragma once


// CPersonalfileCleanupToolDlg �Ի���
class CPersonalfileCleanupToolDlg : public CDialogEx
{
// ����
public:
	CPersonalfileCleanupToolDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PERSONALFILECLEANUPTOOL_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
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
