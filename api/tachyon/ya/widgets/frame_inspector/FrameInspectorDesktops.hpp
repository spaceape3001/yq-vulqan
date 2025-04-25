////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "FrameInspectorManagers.hpp"
#include <tachyon/os/Desktop.hpp>

namespace yq::tachyon {
    class FrameInspectorDesktops : public FrameInspectorManagers {
        YQ_TACHYON_DECLARE(FrameInspectorDesktops, FrameInspectorManagers)
    public:
    
        FrameInspectorDesktops() 
        {
        }
        
        ~FrameInspectorDesktops()
        {
        }

        uint64_t    count() const override { return m_frame->count(DESKTOP); }
        virtual const char* name() const override { return "Desktop"; }
        
        using FrameInspectorManagers::render;
        
        void    render(desktop_k)
        {
            ImGui::TableNextRow();
            if(ImGui::TableNextColumn()){
                ImGui::TextUnformatted("------");
            }
            if(ImGui::TableNextColumn()){
                ImGui::TextUnformatted(">>> DESKTOP PROPERTIES <<<");
            }
        }
        
        void    render(ViContext&ctx) override
        {
            for(DesktopID v : m_frame->ids(DESKTOP)){
                if(!begin(v))
                    continue;
                render(DESKTOP);
                separator();
                render(MANAGER);
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
