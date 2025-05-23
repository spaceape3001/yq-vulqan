////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/api/Editor.hpp>
#include <tachyon/api/EditorInfoWriter.hpp>
#include <tachyon/MyImGui.hpp>
#include <yq/meta/Init.hpp>

YQ_TACHYON_IMPLEMENT(yq::tachyon::Editor)
YQ_TYPE_IMPLEMENT(yq::tachyon::EditorID)

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
    
    void    Editor::imgui(ViContext&u)
    {
        if(metaInfo().menu_bar()){
            if(ImGui::BeginMainMenuBar()){
                menubar_(u);
                ImGui::EndMainMenuBar();
            }
        }
        Widget::imgui(u);
        content_(u);
    }
    
    void Editor::init_info()
    {
        auto w = writer<Editor>();
        w.description("Editor base");

        auto wt = writer<EditorID>();
        wt.description("Editor Identifier");
        wt.set(Meta::Flag::ID);
    }
}
