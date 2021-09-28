#pragma once
#include <afxsock.h>
class CClientSocket :
    public CSocket
{
public:
    CClientSocket();
    virtual ~CClientSocket();

    CAsyncSocket* m_pListenSocket;
    void SetListenSocket(CAsyncSocket* pClient);
    virtual void OnClose(int nErrorCode);
    virtual void OnReceive(int nErrorCode);
};

