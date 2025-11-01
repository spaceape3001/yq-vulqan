////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "FrameInspectorLights.hpp"
#include <yq/tachyon/api/Light3.hpp>

namespace yq::tachyon {
    class FrameInspectorLight³s : public FrameInspectorLights  {
        YQ_TACHYON_DECLARE(FrameInspectorLight³s, FrameInspectorLights)
    public:
    
        FrameInspectorLight³s() 
        {
        }
        
        ~FrameInspectorLight³s()
        {
        }
        
        uint64_t    count() const override { return m_frame->count(LIGHT³); }
        virtual const char* name() const override { return "Light³"; }

        using FrameInspectorLights::render;
        
        void    render(light³_k)
        {
            ImGui::TableNextRow();
            if(ImGui::TableNextColumn()){
                ImGui::TextUnformatted("------");
            }
            if(ImGui::TableNextColumn()){
                ImGui::TextUnformatted(">>> LIGHT³ PROPERTIES <<<");
            }
        }
        
        void    render(ViContext&ctx) override
        {
            for(Light³ID v : m_frame->ids(LIGHT³)){
                if(!begin(v))
                    continue;
                render(LIGHT³);
                separator();
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
