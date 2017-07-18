#include "Writer.h"

#include "EVWork.h"

using namespace evwork;

CWriter::CWriter()
{
}
CWriter::~CWriter()
{
}

void CWriter::send(const std::string& strIp, uint16_t uPort, const char* pData, size_t uSize)
{
	IConn* pConn = CEnv::getThreadEnv()->getConnManager()->getConnByIpPort(strIp, uPort);
	pConn->sendBin(pData, uSize);
}
