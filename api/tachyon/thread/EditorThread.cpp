////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/thread/EditorThread.hpp>

#include <tachyon/api/Thread.hpp>
#include <tachyon/api/ThreadData.hpp>
#include <tachyon/api/ThreadInfoWriter.hpp>

YQ_TACHYON_IMPLEMENT(yq::tachyon::EditorThread)

namespace yq::tachyon {
    EditorThread::EditorThread(const Param&p) : Thread(p)
    {
    }
    
    EditorThread::~EditorThread()
    {
    }
    
    void EditorThread::shutdown()
    {
        quit();
    }
    
    void EditorThread::init_info()
    {
        auto w = writer<EditorThread>();
        w.description("Editor Thread");
    }
}
