////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/ui/Editor.hpp>
#include <tachyon/ui/MyImGui.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::Editor)

namespace yq {
    namespace tachyon {
        EditorInfo::EditorInfo(std::string_view n, WidgetInfo& base, const std::source_location& sl) : WidgetInfo(n, base, sl)
        {
        }

        Editor::Editor()
        {
        }
        
        Editor::~Editor()
        {
        }

        void    Editor::draw(/*engine::UiData&ui*/ ) 
        {
            //if(ImGui::BeginMainMenuBar()){
                //draw_menubar();
                //ImGui::EndMainMenuBar();
            //}
            //draw_content();
            Widget::draw();
        }
    }
}
