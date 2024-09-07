////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/ui/Editor.hpp>
#include <yq-vulqan/imgui/MyImGui.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::Editor)

namespace yq::tachyon {
    EditorInfo::EditorInfo(std::string_view n, WidgetInfo& base, const std::source_location& sl) : WidgetInfo(n, base, sl)
    {
    }

    Editor::Editor()
    {
    }
    
    Editor::~Editor()
    {
    }
    
    void    Editor::imgui_(ViContext&u)
    {
        if(metaInfo().menu_bar()){
            if(ImGui::BeginMainMenuBar()){
                menubar_(u);
                ImGui::EndMainMenuBar();
            }
        }
        Widget::imgui_(u);
        content_(u);
    }
}
