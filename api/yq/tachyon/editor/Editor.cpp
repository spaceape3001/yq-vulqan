////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Editor.hpp"
#include <yq/tachyon/MyImGui.hpp>
#include <yq/tachyon/editor/EditorInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::Editor)

namespace yq::tachyon {
    EditorInfo::EditorInfo(std::string_view n, WidgetInfo& base, const std::source_location& sl) : WidgetInfo(n, base, sl)
    {
        set(Flag::EDITOR);
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
    
    void Editor::init_info()
    {
        auto w = writer<Editor>();
        w.description("Editor base");
    }
}
