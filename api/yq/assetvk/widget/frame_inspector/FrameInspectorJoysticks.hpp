////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "FrameInspectorTachyons.hpp"
#include <yq/tachyon/os/Joystick.hpp>
#include <yq/tachyon/os/JoystickData.hpp>
#include <yq/stream/Text.hpp>
#include <yq/tachyon/im/text.hpp>

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
                im::text("------");
            }
            if(ImGui::TableNextColumn()){
                im::text(">>> JOYSTICK PROPERTIES <<<");
            }

            ImGui::TableNextRow();
            if(ImGui::TableNextColumn()){
                im::text("Axes");
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
                im::text(data);
            }

            ImGui::TableNextRow();
            if(ImGui::TableNextColumn()){
                im::text("Buttons");
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
                im::text(data);
            }

            ImGui::TableNextRow();
            if(ImGui::TableNextColumn()){
                im::text("GUID");
            }
            if(ImGui::TableNextColumn()){
                im::text(snap->guid);
            }

            ImGui::TableNextRow();
            if(ImGui::TableNextColumn()){
                im::text("Name");
            }
            if(ImGui::TableNextColumn()){
                im::text(snap->name);
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

        static void init_meta()
        {
        }
    };
}
