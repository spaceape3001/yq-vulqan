////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "FrameInspectorSpatials.hpp"
#include <yq/tachyon/api/Spatial3.hpp>
#include <yq/tachyon/api/Spatial3Data.hpp>
#include <yq/tachyon/im/text.hpp>

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
            const Spatial³Snap* snap = static_cast<const Spatial³Snap*>(m_snap);
            
            ImGui::TableNextRow();
            if(ImGui::TableNextColumn()){
                im::text("------");
            }
            if(ImGui::TableNextColumn()){
                im::text(">>> SPATIAL³ PROPERTIES <<<");
            }

            ImGui::TableNextRow();
            if(ImGui::TableNextColumn()){
                im::text("Domain to Local");
            }
            if(ImGui::TableNextColumn()){
                im::text(snap->domain2local);
            }

            ImGui::TableNextRow();
            if(ImGui::TableNextColumn()){
                im::text("Local to Domain");
            }
            if(ImGui::TableNextColumn()){
                im::text(snap->local2domain);
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

        static void init_meta()
        {
        }
    };
}
