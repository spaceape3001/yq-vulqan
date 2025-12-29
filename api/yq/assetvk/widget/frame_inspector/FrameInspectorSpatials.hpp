////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "FrameInspectorTachyons.hpp"
#include <yq/tachyon/api/Spatial.hpp>
#include <yq/tachyon/api/SpatialData.hpp>
#include <yq/tachyon/im/text.hpp>

namespace yq::tachyon {
    class FrameInspectorSpatials : public FrameInspectorTachyons {
        YQ_TACHYON_DECLARE(FrameInspectorSpatials, FrameInspectorTachyons)
    public:
    
        FrameInspectorSpatials() 
        {
        }
        
        ~FrameInspectorSpatials()
        {
        }
        
        uint64_t    count() const override { return m_frame->count(SPATIAL); }
        virtual const char* name() const override { return "Spatial"; }

        using FrameInspectorTachyons::render;
        
        void    render(spatial_k)
        {
            const SpatialSnap* snap = static_cast<const SpatialSnap*>(m_snap);
            
            ImGui::TableNextRow();
            if(ImGui::TableNextColumn()){
                im::text("------");
            }
            if(ImGui::TableNextColumn()){
                im::text(">>> SPATIAL PROPERTIES <<<");
            }

            ImGui::TableNextRow();
            if(ImGui::TableNextColumn()){
                im::text("Domain");
            }
            if(ImGui::TableNextColumn()){
                meta_id(snap->domain);
            }
        }

        void    render(ViContext&ctx) override
        {
            for(SpatialID v : m_frame->ids(SPATIAL)){
                if(!begin(v))
                    continue;
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
