////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/thread/AudioThread.hpp>

#include <tachyon/api/Thread.hpp>
#include <tachyon/api/ThreadData.hpp>
#include <tachyon/api/ThreadInfoWriter.hpp>

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
    
    void AudioThread::init_info()
    {
        auto w = writer<AudioThread>();
        w.description("Audio Thread");
    }
}
