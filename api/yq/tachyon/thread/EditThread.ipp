////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/thread/EditThread.hpp>

#include <yq/tachyon/api/Thread.hpp>
#include <yq/tachyon/api/ThreadData.hpp>
#include <yq/tachyon/api/ThreadMetaWriter.hpp>

YQ_TACHYON_IMPLEMENT(yq::tachyon::EditThread)

namespace yq::tachyon {
    EditThread::EditThread(const Param&p) : Thread(p)
    {
        m_name    = "EDIT";
    }
    
    EditThread::~EditThread()
    {
    }
    
    void EditThread::shutdown()
    {
        quit();
    }
    
    void EditThread::init_meta()
    {
        auto w = writer<EditThread>();
        w.description("Edit Thread");
    }
}
