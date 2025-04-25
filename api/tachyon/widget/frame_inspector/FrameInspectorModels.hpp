////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "FrameInspectorTachyons.hpp"
#include <yt/sim/Model.hpp>

namespace yq::tachyon {
    class FrameInspectorModels : public FrameInspectorTachyons {
        YQ_TACHYON_DECLARE(FrameInspectorModels, FrameInspectorTachyons)
    public:
    
        FrameInspectorModels() 
        {
        }
        
        ~FrameInspectorModels()
        {
        }

        uint64_t    count() const override { return m_frame->count(MODEL); }
        virtual const char* name() const override { return "Model"; }
        
        using FrameInspectorTachyons::render;

        void    render(model_k)
        {
            ImGui::TableNextRow();
            if(ImGui::TableNextColumn()){
                ImGui::TextUnformatted("------");
            }
            if(ImGui::TableNextColumn()){
                ImGui::TextUnformatted(">>> MODEL PROPERTIES <<<");
            }
        }

        void    render(ViContext&ctx) override
        {
            for(ModelID v : m_frame->ids(MODEL)){
                if(!begin(v))
                    continue;
                render(MODEL);
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
