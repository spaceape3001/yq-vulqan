////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Editor.hpp"
#include <imgui.h>

YQ_OBJECT_IMPLEMENT(yq::engine::Editor)

namespace yq {
    namespace engine {
        EditorInfo::EditorInfo(std::string_view n, engine::WidgetInfo& base, const std::source_location& sl) : WidgetInfo(n, base, sl)
        {
        }

        Editor::Editor()
        {
        }
        
        Editor::~Editor()
        {
        }

        void    Editor::draw(engine::UiData&ui) 
        {
            if(ImGui::BeginMainMenuBar()){
                draw_menubar();
                ImGui::EndMainMenuBar();
            }
            draw_content();
        }
    }
}
