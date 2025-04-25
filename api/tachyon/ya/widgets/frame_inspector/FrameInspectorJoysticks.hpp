////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "FrameInspectorTachyons.hpp"
#include <tachyon/os/Joystick.hpp>
#include <tachyon/os/JoystickData.hpp>
#include <yq/stream/Text.hpp>

namespace yq::tachyon {
    class FrameInspectorJoysticks : public FrameInspectorTachyons {
        YQ_TACHYON_DECLARE(FrameInspectorJoysticks, FrameInspectorTachyons)
    public:
    
        FrameInspectorJoysticks() 
        {
        }
        
        ~FrameInspectorJoysticks()
        {
        }
        
        uint64_t    count() const override { return m_frame->count(JOYSTICK); }
        virtual const char* name() const override { return "Joystick"; }

        using FrameInspectorTachyons::render;
        
        void    render(joystick_k)
        {
            const JoystickSnap*  snap    = static_cast<const JoystickSnap*>(m_snap);

            ImGui::TableNextRow();
            if(ImGui::TableNextColumn()){
                ImGui::TextUnformatted("------");
            }
            if(ImGui::TableNextColumn()){
                ImGui::TextUnformatted(">>> JOYSTICK PROPERTIES <<<");
            }

            ImGui::TableNextRow();
            if(ImGui::TableNextColumn()){
                ImGui::TextUnformatted("Axes");
            }
            if(ImGui::TableNextColumn()){
                std::string data;
                {
                    stream::Text out(data);
                    for(size_t n=0;n<snap->axes.size();++n){
                        if(n){
                            out << ", ";
                        }
                        out << snap->axes[n];
                    }
                }
                ImGui::TextUnformatted(data);
            }

            ImGui::TableNextRow();
            if(ImGui::TableNextColumn()){
                ImGui::TextUnformatted("Buttons");
            }
            if(ImGui::TableNextColumn()){
                std::string data;
                {
                    stream::Text out(data);
                    for(size_t n=0;n<snap->buttons.size();++n){
                        if(n){
                            out << ", ";
                        }
                        out << snap->buttons[n];
                    }
                }
                ImGui::TextUnformatted(data);
            }

            ImGui::TableNextRow();
            if(ImGui::TableNextColumn()){
                ImGui::TextUnformatted("GUID");
            }
            if(ImGui::TableNextColumn()){
                ImGui::TextUnformatted(snap->guid);
            }

            ImGui::TableNextRow();
            if(ImGui::TableNextColumn()){
                ImGui::TextUnformatted("Name");
            }
            if(ImGui::TableNextColumn()){
                ImGui::TextUnformatted(snap->name);
            }
        }

        void    render(ViContext&ctx) override
        {
            for(JoystickID v : m_frame->ids(JOYSTICK)){
                if(!begin(v))
                    continue;
                render(JOYSTICK);
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
