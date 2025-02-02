////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/threads/GameThread.hpp>

#include <yt/api/Thread.hpp>
#include <yt/api/ThreadData.hpp>
#include <yt/api/ThreadInfoWriter.hpp>

YQ_TACHYON_IMPLEMENT(yq::tachyon::GameThread)

namespace yq::tachyon {
    GameThread::GameThread(const Param&p) : Thread(p)
    {
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
