#pragma once
#include <afxsock.h>
class CListenSocket :
    public CAsyncSocket
{
public:

    CPtrList m_ptrClientSocketList;
    virtual void OnAccept(int nErrorCode);
    void CloseClientSocket(CSocket* pClient);
    void SendChatDataAll(TCHAR* pszMessage);
};

