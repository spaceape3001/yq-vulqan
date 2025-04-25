////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "FrameInspectorTachyons.hpp"
#include <yt/api/Manager.hpp>

namespace yq::tachyon {
    class FrameInspectorManagers : public FrameInspectorTachyons {
        YQ_TACHYON_DECLARE(FrameInspectorManagers, FrameInspectorTachyons)
    public:
    
        FrameInspectorManagers() 
        {
        }
        
        ~FrameInspectorManagers()
        {
        }

        uint64_t    count() const override { return m_frame->count(MANAGER); }
        virtual const char* name() const override { return "Manager"; }
        
        using FrameInspectorTachyons::render;
        
        void    render(manager_k)
        {
            ImGui::TableNextRow();
            if(ImGui::TableNextColumn()){
                ImGui::TextUnformatted("------");
            }
            if(ImGui::TableNextColumn()){
                ImGui::TextUnformatted(">>> MANAGER PROPERTIES <<<");
            }
        }

        void    render(ViContext&ctx) override
        {
            for(ManagerID v : m_frame->ids(MANAGER)){
                if(!begin(v))
                    continue;
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
