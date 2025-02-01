////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "FrameInspectorTachyons.hpp"
#include <yt/os/Joystick.hpp>

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
            ImGui::TableNextRow();
            if(ImGui::TableNextColumn()){
                ImGui::TextUnformatted("------");
            }
            if(ImGui::TableNextColumn()){
                ImGui::TextUnformatted(">>> JOYSTICK PROPERTIES <<<");
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
