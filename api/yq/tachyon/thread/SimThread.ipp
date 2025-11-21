////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/thread/SimThread.hpp>

#include <yq/tachyon/api/Thread.hpp>
#include <yq/tachyon/api/ThreadData.hpp>
#include <yq/tachyon/api/ThreadMetaWriter.hpp>

YQ_TACHYON_IMPLEMENT(yq::tachyon::SimThread)

namespace yq::tachyon {
    SimThread::SimThread(const Param&p) : Thread(p)
    {
        m_name  = "SIM";
    }
    
    SimThread::~SimThread()
    {
    }
    
    void SimThread::shutdown()
    {
        quit();
    }
    
    void SimThread::init_meta()
    {
        auto w = writer<SimThread>();
        w.description("Sim Thread");
    }
}
