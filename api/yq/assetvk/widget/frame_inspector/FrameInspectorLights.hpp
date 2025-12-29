////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "FrameInspectorTachyons.hpp"
#include <yq/tachyon/api/Light.hpp>
#include <yq/tachyon/im/text.hpp>

namespace yq::tachyon {
    class FrameInspectorLights : public FrameInspectorTachyons {
        YQ_TACHYON_DECLARE(FrameInspectorLights, FrameInspectorTachyons)
    public:
    
        FrameInspectorLights() 
        {
        }
        
        ~FrameInspectorLights()
        {
        }
        
        uint64_t    count() const override { return m_frame->count(LIGHT); }
        virtual const char* name() const override { return "Light"; }
        
        using FrameInspectorTachyons::render;
        
        void    render(light_k)
        {
            ImGui::TableNextRow();
            if(ImGui::TableNextColumn()){
                im::text("------");
            }
            if(ImGui::TableNextColumn()){
                im::text(">>> LIGHT PROPERTIES <<<");
            }
        }

        void    render(ViContext&ctx) override
        {
            for(LightID v : m_frame->ids(LIGHT)){
                if(!begin(v))
                    continue;
                render(LIGHT);
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
