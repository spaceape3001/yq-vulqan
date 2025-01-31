////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "FrameInspectorTachyons.hpp"
#include <yt/app/Viewer.hpp>
#include <yq/text/format.hpp>

namespace yq::tachyon {
    class FrameInspectorViewers : public FrameInspectorTachyons {
        YQ_TACHYON_DECLARE(FrameInspectorViewers, FrameInspectorTachyons)
    public:
    
        FrameInspectorViewers() 
        {
        }
        
        ~FrameInspectorViewers()
        {
        }
        
        uint64_t    count() const override { return m_frame->count(VIEWER); }
        virtual const char* name() const override { return "Viewer"; }

        using FrameInspectorTachyons::render;

        void    render(ViContext&ctx) override
        {
            for(ViewerID v : m_frame->ids(VIEWER)){
                if(!begin(v))
                    continue;
                
                std::string vid = to_string(v.id);
                if(ImGui::BeginTable(vid.c_str(), 2)){
                
                    //ImGui::TableNextRow();
                    //ImGui::Separator();
                
                    render(TACHYON);
                    ImGui::EndTable();
                }
                end();
            }
        }

        static void init_info()
        {
        }
    };
}
