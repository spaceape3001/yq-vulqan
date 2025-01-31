////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "FrameInspectorSpatials.hpp"
#include <yt/3D/Spatial3.hpp>

namespace yq::tachyon {
    class FrameInspectorSpatial³s : public FrameInspectorSpatials {
        YQ_TACHYON_DECLARE(FrameInspectorSpatial³s, FrameInspectorSpatials)
    public:
    
        FrameInspectorSpatial³s() 
        {
        }
        
        ~FrameInspectorSpatial³s()
        {
        }
        
        uint64_t    count() const override { return m_frame->count(SPATIAL³); }
        virtual const char* name() const override { return "Spatial³"; }

        using FrameInspectorSpatials::render;
        
        void    render(spatial³_k)
        {
            ImGui::TableNextRow();
            if(ImGui::TableNextColumn()){
                ImGui::TextUnformatted("------");
            }
            if(ImGui::TableNextColumn()){
                ImGui::TextUnformatted(">>> SPATIAL³ PROPERTIES <<<");
            }
        }
        
        void    render(ViContext&ctx) override
        {
            for(Spatial³ID v : m_frame->ids(SPATIAL³)){
                if(!begin(v))
                    continue;
                
                render(SPATIAL³);
                separator();
                render(SPATIAL);
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
