#include "pch.h"
#include "CClientSocket.h"
#include "..\DLLChattingServer\DLLChattingServerDlg.h"

void AFX_EXT_CLASS CClientSocket::SetListenSocket(CAsyncSocket* pSocket)
{
	m_pListenSocket = pSocket;
}



void AFX_EXT_CLASS CClientSocket::OnClose(int nErrorCode)
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	CString strTmp = _T(""), strIPAddress = _T("");
	UINT uPortNumber = 0;
	TCHAR szBuffer[1024];
	::ZeroMemory(szBuffer, sizeof(szBuffer));

	GetPeerName(strIPAddress, uPortNumber);
	if (Receive(szBuffer, sizeof(szBuffer)) > 0)
	{
		CDLLChattingServerDlg* pMain = (CDLLChattingServerDlg*)AfxGetMainWnd();
		strTmp.Format(_T("%s:%d] : %s"), strIPAddress, uPortNumber, szBuffer);
		pMain->m_List.AddString(strTmp);
		pMain->m_List.SetCurSel(pMain->m_List.GetCount() - 1);

		CListenSocket* pServerSocket = (CListenSocket*)m_pListenSocket;
		pServerSocket->SendChatDataAll(szBuffer);
	}


	CSocket::OnClose(nErrorCode);
}


void AFX_EXT_CLASS CClientSocket::OnReceive(int nErrorCode)
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	
	CString strTmp = _T(""), strIPAddress = _T("");
	UINT uPortNumber = 0;
	TCHAR szBuffer[1024];
	::ZeroMemory(szBuffer, sizeof(szBuffer));

	GetPeerName(strIPAddress, uPortNumber);
	if (Receive(szBuffer, sizeof(szBuffer)) > 0)
	{
		CDLLChattingServerDlg* pMain = (CDLLChattingServerDlg*)AfxGetMainWnd();
		strTmp.Format(_T("[%s:%d] : %s"), strIPAddress, uPortNumber, szBuffer);
		pMain->m_List.AddString(strTmp);
		pMain->m_List.SetCurSel(pMain->m_List.GetCount()-1);

		CListenSocket* pServerSocket = (CListenSocket*)m_pListenSocket;
		pServerSocket->SendChatDataAll(szBuffer);

	}


	CSocket::OnReceive(nErrorCode);
}
