////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/thread/AudioThread.hpp>

#include <yq/tachyon/api/Thread.hpp>
#include <yq/tachyon/api/ThreadData.hpp>
#include <yq/tachyon/api/ThreadMetaWriter.hpp>

YQ_TACHYON_IMPLEMENT(yq::tachyon::AudioThread)

namespace yq::tachyon {
    AudioThread::AudioThread(const Param&p) : Thread(p)
    {
        m_name  = "AUDIO";
    }
    
    AudioThread::~AudioThread()
    {
    }
    
    void AudioThread::shutdown()
    {
        quit();
    }
    
    void AudioThread::init_meta()
    {
        auto w = writer<AudioThread>();
        w.description("Audio Thread");
    }
}
