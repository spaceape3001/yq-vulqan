////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "FrameInspectorTachyons.hpp"
#include <yq/tachyon/os/Monitor.hpp>
#include <yq/tachyon/os/MonitorData.hpp>
#include <yq/tachyon/im/text.hpp>

namespace yq::tachyon {
    class FrameInspectorMonitors : public FrameInspectorTachyons {
        YQ_TACHYON_DECLARE(FrameInspectorMonitors, FrameInspectorTachyons)
    public:
    
        FrameInspectorMonitors() 
        {
        }
        
        ~FrameInspectorMonitors()
        {
        }

        uint64_t    count() const override { return m_frame->count(MONITOR); }
        virtual const char* name() const override { return "Monitor"; }
        
        using FrameInspectorTachyons::render;

        void    render(monitor_k)
        {
            const MonitorSnap*  snap    = static_cast<const MonitorSnap*>(m_snap);

            ImGui::TableNextRow();
            if(ImGui::TableNextColumn()){
                im::text("------");
            }
            if(ImGui::TableNextColumn()){
                im::text(">>> MONITOR PROPERTIES <<<");
            }

#if 0
            ImGui::TableNextRow();
            if(ImGui::TableNextColumn()){
                im::text("Scale");
            }
            if(ImGui::TableNextColumn()){
                im::text(snap->scale);
            }
#endif

            ImGui::TableNextRow();
            if(ImGui::TableNextColumn()){
                im::text("Size");
            }
            if(ImGui::TableNextColumn()){
                im::text(snap->size);
            }

        }

        void   render(ViContext&ctx) override
        {
            for(MonitorID v : m_frame->ids(MONITOR)){
                if(!begin(v))
                    continue;
                render(MONITOR);
                separator();
                render(TACHYON);
                end();
            }
        }

        static void init_meta()
        {
        }
    };
}
