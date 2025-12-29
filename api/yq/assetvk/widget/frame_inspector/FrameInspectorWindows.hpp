////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "FrameInspectorTachyons.hpp"
#include <yq/tachyon/os/Window.hpp>
#include <yq/tachyon/os/WindowData.hpp>
#include <yq/tachyon/im/text.hpp>

namespace yq::tachyon {
    class FrameInspectorWindows : public FrameInspectorTachyons {
        YQ_TACHYON_DECLARE(FrameInspectorWindows, FrameInspectorTachyons)
    public:
    
        FrameInspectorWindows() 
        {
        }
        
        ~FrameInspectorWindows()
        {
        }
        
        uint64_t    count() const override { return m_frame->count(WINDOW); }
        virtual const char* name() const override { return "Window"; }

        using FrameInspectorTachyons::render;
        
        void    render(window_k)
        {
            const WindowSnap *snap  = static_cast<const WindowSnap*>(m_snap);
            
            ImGui::TableNextRow();
            if(ImGui::TableNextColumn()){
                im::text("------");
            }
            if(ImGui::TableNextColumn()){
                im::text(">>> WINDOW PROPERTIES <<<");
            }

            ImGui::TableNextRow();
            if(ImGui::TableNextColumn()){
                im::text("Aspect");
            }
            if(ImGui::TableNextColumn()){
                ImGui::Text("%d:%d", snap->window.aspect.x, snap->window.aspect.y);
            }

            ImGui::TableNextRow();
            if(ImGui::TableNextColumn()){
                im::text("Area");
            }
            if(ImGui::TableNextColumn()){
                im::text(snap->window.area);
            }

            ImGui::TableNextRow();
            if(ImGui::TableNextColumn()){
                im::text("Flags");
            }
            if(ImGui::TableNextColumn() && snap->window.flags){
                std::string     create;
                if(snap->window.flags(WindowFlag::AutoIconify))
                    create += ", Auto Iconify";
                if(snap->window.flags(WindowFlag::Closed))
                    create += ", Closed";
                if(snap->window.flags(WindowFlag::Decorated))
                    create += ", Decorated";
                if(snap->window.flags(WindowFlag::FixedAspect))
                    create += ", Fixed Aspect";
                if(snap->window.flags(WindowFlag::Floating))
                    create += ", Floating (Top)";
                if(snap->window.flags(WindowFlag::Focused))
                    create += ", Focused";
                if(snap->window.flags(WindowFlag::FocusOnShow))
                    create += ", Focus on Show";
                if(snap->window.flags(WindowFlag::Hovered))
                    create += ", Hovered";
                if(snap->window.flags(WindowFlag::Iconified))
                    create += ", Iconified";
                if(snap->window.flags(WindowFlag::Maximized))
                    create += ", Maximized";
                if(snap->window.flags(WindowFlag::MousePassThrough))
                    create += ", Mouse Pass Through";
                if(snap->window.flags(WindowFlag::RawMouseMotion))
                    create += ", Raw Mouse Motion";
                if(snap->window.flags(WindowFlag::Resizable))
                    create += ", Resizable";
                if(snap->window.flags(WindowFlag::Transparent))
                    create += ", Transparent";
                if(snap->window.flags(WindowFlag::Visible))
                    create += ", Visible";
                std::string_view    f   = create;
                im::text(f.substr(2));
            }

            ImGui::TableNextRow();
            if(ImGui::TableNextColumn()){
                im::text("Max");
            }
            if(ImGui::TableNextColumn()){
                im::text(snap->window.max);
            }

            ImGui::TableNextRow();
            if(ImGui::TableNextColumn()){
                im::text("Min");
            }
            if(ImGui::TableNextColumn()){
                im::text(snap->window.min);
            }

            ImGui::TableNextRow();
            if(ImGui::TableNextColumn()){
                im::text("Monitor");
            }
            if(ImGui::TableNextColumn()){
                meta_id(snap->window.monitor);
            }

            ImGui::TableNextRow();
            if(ImGui::TableNextColumn()){
                im::text("Opacity");
            }
            if(ImGui::TableNextColumn()){
                im::text(snap->window.opacity);
            }

            ImGui::TableNextRow();
            if(ImGui::TableNextColumn()){
                im::text("Pixels");
            }
            if(ImGui::TableNextColumn()){
                im::text(snap->window.pixels);
            }

            ImGui::TableNextRow();
            if(ImGui::TableNextColumn()){
                im::text("Position");
            }
            if(ImGui::TableNextColumn()){
                im::text(snap->window.position );
            }

            ImGui::TableNextRow();
            if(ImGui::TableNextColumn()){
                im::text("Scale");
            }
            if(ImGui::TableNextColumn()){
                im::text(snap->window.scale);
            }

            ImGui::TableNextRow();
            if(ImGui::TableNextColumn()){
                im::text("Title");
            }
            if(ImGui::TableNextColumn()){
                im::text(snap->window.title.c_str());
            }
        }
        
        void    render(ViContext&ctx) override
        {
            for(WindowID v : m_frame->ids(WINDOW)){
                if(!begin(v))
                    continue;
                render(WINDOW);
                render(TACHYON);
                end();
            }
        }

        static void init_meta()
        {
        }
    };
}
