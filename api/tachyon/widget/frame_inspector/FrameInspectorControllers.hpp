////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "FrameInspectorTachyons.hpp"
#include <tachyon/api/Controller.hpp>
#include <tachyon/api/ControllerData.hpp>
#include <tachyon/command/controller/DisableCommand.hpp>
#include <tachyon/command/controller/EnableCommand.hpp>

namespace yq::tachyon {
    class FrameInspectorControllers : public FrameInspectorTachyons {
        YQ_TACHYON_DECLARE(FrameInspectorControllers, FrameInspectorTachyons)
    public:
    
        FrameInspectorControllers() 
        {
        }
        
        ~FrameInspectorControllers()
        {
        }
        
        uint64_t    count() const override { return m_frame->count(CONTROLLER); }
        virtual const char* name() const override { return "Controller"; }

        using FrameInspectorTachyons::render;
        
        void    render(controller_k)
        {
            const ControllerSnap*   snap    = static_cast<const ControllerSnap*>(m_snap);
            ImGui::TableNextRow();
            if(ImGui::TableNextColumn()){
                ImGui::TextUnformatted("------");
            }
            if(ImGui::TableNextColumn()){
                ImGui::TextUnformatted(">>> CONTROLLER PROPERTIES <<<");
            }

            ImGui::TableNextRow();
            if(ImGui::TableNextColumn()){
                ImGui::TextUnformatted("Enable");
            }
            if(ImGui::TableNextColumn()){
                bool    f   = snap->enabled;
                std::string id  = "Enable";
                id += to_string_view(m_tachyon->id().id);
                ImGui::ToggleButton(id.c_str(), &f);
                if(f != snap->enabled){
                    if(f){
                        send(new EnableCommand({.target=*m_tachyon}));
                    } else {
                        send(new DisableCommand({.target=*m_tachyon}));
                    }
                }
            }
            
            //  TODO add listening/controlling later
        }

        void    render(ViContext&ctx) override
        {
            for(ControllerID v : m_frame->ids(CONTROLLER)){
                if(!begin(v))
                    continue;
                    
                render(CONTROLLER);
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
