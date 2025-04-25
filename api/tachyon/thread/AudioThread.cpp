////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/thread/AudioThread.hpp>

#include <yt/api/Thread.hpp>
#include <yt/api/ThreadData.hpp>
#include <yt/api/ThreadInfoWriter.hpp>

YQ_TACHYON_IMPLEMENT(yq::tachyon::AudioThread)

namespace yq::tachyon {
    AudioThread::AudioThread(const Param&p) : Thread(p)
    {
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
