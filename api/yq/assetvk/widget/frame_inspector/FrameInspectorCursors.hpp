////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "FrameInspectorTachyons.hpp"
#include <yq/tachyon/os/Cursor.hpp>
#include <yq/tachyon/im/text.hpp>

namespace yq::tachyon {
    class FrameInspectorCursors : public FrameInspectorTachyons {
        YQ_TACHYON_DECLARE(FrameInspectorCursors, FrameInspectorTachyons)
    public:
    
        FrameInspectorCursors() 
        {
        }
        
        ~FrameInspectorCursors()
        {
        }
        
        uint64_t    count() const override { return m_frame->count(CURSOR); }
        virtual const char* name() const override { return "Cursor"; }

        using FrameInspectorTachyons::render;

        void    render(cursor_k)
        {
            ImGui::TableNextRow();
            if(ImGui::TableNextColumn()){
                im::text("------");
            }
            if(ImGui::TableNextColumn()){
                im::text(">>> CURSOR PROPERTIES <<<");
            }
        }

        void    render(ViContext&ctx) override
        {
            for(CursorID v : m_frame->ids(CURSOR)){
                if(!begin(v))
                    continue;
                    
                render(CURSOR);
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
