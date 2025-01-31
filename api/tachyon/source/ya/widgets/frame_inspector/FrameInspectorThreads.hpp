////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "FrameInspectorTachyons.hpp"
#include <yt/api/Thread.hpp>
#include <yt/api/ThreadData.hpp>

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
            //const Thread*       thread  = static_cast<const Thread*>(m_tachyon);
            //const ThreadSnap*   snap    = static_cast<const ThreadSnap*>(m_snap);
            const ThreadData*   data    = static_cast<const ThreadData*>(m_data);
        
            ImGui::TableNextRow();
            if(ImGui::TableNextColumn()){
                ImGui::TextUnformatted("------");
            }
            if(ImGui::TableNextColumn()){
                ImGui::TextUnformatted(">>> THREAD PROPERTIES <<<");
            }

            ImGui::TableNextRow();
            if(ImGui::TableNextColumn()){
                ImGui::TextUnformatted("FPS");
            }
            if(ImGui::TableNextColumn()){
                ImGui::Text("%lf", 1.0 / unit::Second(data->cycleTime).value);
            }

            ImGui::TableNextRow();
            if(ImGui::TableNextColumn()){
                ImGui::TextUnformatted("Objects");
            }
            if(ImGui::TableNextColumn()){
                ImGui::Text("%ld", data->tachyons.size());
            }
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
