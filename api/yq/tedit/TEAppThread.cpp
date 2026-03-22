////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "TEAppThread.hpp"
#include "TEAppThreadData.hpp"
#include "TEAppThreadMetaWriter.hpp"

YQ_TACHYON_IMPLEMENT(yq::tachyon::TEAppThread)

namespace yq::tachyon {
    void    TEAppThread::init_meta()
    {
        auto w = writer<TEAppThread>();
        w.description("Tachyon Editing App Thread");
    }

    TEAppThread::TEAppThread(int&argc, char*argv[], tachyon::Application&app) : YAppThread(argc, argv, app)
    {
    }
    
    TEAppThread::~TEAppThread()
    {
    }
}

#include "moc_TEAppThread.cpp"
