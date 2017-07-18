#include "EVWork.h"

#include "TimerHandler.h"

using namespace evwork;

class CTest
{
public:
	CTest()
	{
		m_timerTest.init(this);
		m_timerTest.start(1000);
	}
	~CTest()
	{
		m_timerTest.stop();
	}

private:
	bool __testFunc()
	{
		CEnv::getThreadEnv()->getWriter()->send("127.0.0.1", 1982, "hello", 5);
		CEnv::getThreadEnv()->getWriter()->flush();

		return true;
	}

	TimerHandler<CTest, &CTest::__testFunc> m_timerTest;
};

int main(int argc, char* argv[])
{
	//-------------------------------------------------------------------------
	// libevwork初使化

	signal(SIGPIPE, SIG_IGN);

	CSyslogReport LG;
	CEVLoop LP;
	CConnManager CM;
	CWriter WR;

	CEnv::getThreadEnv()->setLogger(&LG);
	CEnv::getThreadEnv()->setEVLoop(&LP);
	CEnv::getThreadEnv()->setLinkEvent(&CM);
	CEnv::getThreadEnv()->setConnManager(&CM);
	CEnv::getThreadEnv()->setWriter(&WR);

	CEnv::getThreadEnv()->getEVParam().uConnTimeout = 300;

	LP.init();

	//-------------------------------------------------------------------------
	// 应用程序初使化

	CTest obj;

	//-------------------------------------------------------------------------
	// 启动事件循环

	LP.runLoop();

	return 0;
}
