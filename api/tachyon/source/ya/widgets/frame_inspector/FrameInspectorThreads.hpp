////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "FrameInspectorTachyons.hpp"
#include <yt/api/Thread.hpp>

namespace yq::tachyon {
    class FrameInspectorThreads : public FrameInspectorTachyons {
        YQ_TACHYON_DECLARE(FrameInspectorThreads, FrameInspectorTachyons)
    public:
    
        FrameInspectorThreads() 
        {
        }
        
        ~FrameInspectorThreads()
        {
        }
        
        uint64_t    count() const override { return m_frame->count(THREAD); }
        virtual const char* name() const override { return "Thread"; }

        using FrameInspectorTachyons::render;
        
        void    render(thread_k)
        {
        }
        
        void    render(ViContext&ctx) override
        {
            for(ThreadID v : m_frame->ids(THREAD)){
                if(!begin(v))
                    continue;
                    
                render(THREAD);
                separator();
                render(TACHYON);
                end();
            }
        }

        static void init_info()
        {
        }
    };
}
