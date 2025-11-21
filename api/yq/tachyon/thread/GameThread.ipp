////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/thread/GameThread.hpp>

#include <yq/tachyon/api/Thread.hpp>
#include <yq/tachyon/api/ThreadData.hpp>
#include <yq/tachyon/api/ThreadMetaWriter.hpp>

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
    
    void GameThread::init_meta()
    {
        auto w = writer<GameThread>();
        w.description("Game Thread");
    }
}
