////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/thread/GameThread.hpp>

#include <tachyon/api/Thread.hpp>
#include <tachyon/api/ThreadData.hpp>
#include <tachyon/api/ThreadInfoWriter.hpp>

YQ_TACHYON_IMPLEMENT(yq::tachyon::GameThread)

namespace yq::tachyon {
    GameThread::GameThread(const Param&p) : Thread(p)
    {
        m_name  = "GAME";
    }
    
    GameThread::~GameThread()
    {
    }
    
    void GameThread::shutdown()
    {
        quit();
    }
    
    void GameThread::init_info()
    {
        auto w = writer<GameThread>();
        w.description("Game Thread");
    }
}
