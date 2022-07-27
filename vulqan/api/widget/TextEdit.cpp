////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "TextEdit.hpp"
#include <MyImGui.hpp>

YQ_OBJECT_IMPLEMENT(yq::widget::TextEdit)

namespace yq {
    namespace widget {
        TextEdit::TextEdit()
        {
        }
        
        TextEdit::~TextEdit()
        {
        }

        void    TextEdit::draw() 
        {
            auto drawList = ImGui::GetWindowDrawList();
            ImU32 red  = ImGui::GetColorU32(ImVec4(1., 0., 0., 1.));
            ImVec2  vstart  = ImGui::GetWindowContentRegionMin();
            ImVec2  vend    = ImGui::GetWindowContentRegionMax();
            drawList->AddRectFilled(vstart, vend, red);
        }
    }
}
