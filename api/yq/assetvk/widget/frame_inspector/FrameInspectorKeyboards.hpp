////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "FrameInspectorTachyons.hpp"
#include <yq/tachyon/im/text.hpp>
#include <yq/tachyon/os/Keyboard.hpp>

namespace yq::tachyon {
    class FrameInspectorKeyboards : public FrameInspectorTachyons {
        YQ_TACHYON_DECLARE(FrameInspectorKeyboards, FrameInspectorTachyons)
    public:
    
        FrameInspectorKeyboards() 
        {
        }
        
        ~FrameInspectorKeyboards()
        {
        }
        
        uint64_t    count() const override { return m_frame->count(KEYBOARD); }
        virtual const char* name() const override { return "Keyboard"; }

        using FrameInspectorTachyons::render;

        void    render(keyboard_k)
        {
            ImGui::TableNextRow();
            if(ImGui::TableNextColumn()){
                im::text("------");
            }
            if(ImGui::TableNextColumn()){
                im::text(">>> KEYBOARD PROPERTIES <<<");
            }
        }

        void    render(ViContext&ctx) override
        {
            for(KeyboardID v : m_frame->ids(KEYBOARD)){
                if(!begin(v))
                    continue;
                render(KEYBOARD);
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
