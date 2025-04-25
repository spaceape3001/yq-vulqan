////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "FrameInspectorTachyons.hpp"
#include <tachyon/os/Monitor.hpp>
#include <tachyon/os/MonitorData.hpp>

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
                ImGui::TextUnformatted("------");
            }
            if(ImGui::TableNextColumn()){
                ImGui::TextUnformatted(">>> MONITOR PROPERTIES <<<");
            }

#if 0
            ImGui::TableNextRow();
            if(ImGui::TableNextColumn()){
                ImGui::TextUnformatted("Scale");
            }
            if(ImGui::TableNextColumn()){
                ImGui::Text(snap->scale);
            }
#endif

            ImGui::TableNextRow();
            if(ImGui::TableNextColumn()){
                ImGui::TextUnformatted("Size");
            }
            if(ImGui::TableNextColumn()){
                ImGui::Text(snap->size);
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

        static void init_info()
        {
        }
    };
}
