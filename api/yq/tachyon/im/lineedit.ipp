////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "lineedit.hpp"
#include "button.hpp"
#include "dragdrop.hpp"
#include <yq/tachyon/logging.hpp>
#include "misc/cpp/imgui_stdlib.h"

namespace yq::tachyon::im {
    bool            lineedit(const char* label, std::string&v, const lineedit_t& opts)
    {
        if(opts.labelless)
            ImGui::SetNextItemWidth(-1);
            
        bool ret = ImGui::InputText(label, &v, opts.flags);
        if(opts.drag && begin_drag_source(opts.drag_flags)){
            if(!v.empty()){
                set_drag_payload(opts.drag, v.data(), v.size());
                ImGui::TextUnformatted(v);
            }
            end_drag_source();
        }
        if(!opts.drop.empty() && begin_drop_target()){
            const ImGuiPayload* pay = accept_drop(opts.drop, opts.drop_flags);
            if(pay && pay->DataSize){
                // won't copy emptiness
                v   = std::string((const char*) pay->Data, pay->DataSize);
                ret = true;
            }
            end_drop_target();
        }
        return ret;
    }
    
    BrowseResult    lineedit(browse_k, const char* label, std::string&v, const lineedit_t& opts)
    {
        BrowseResult    ret = BrowseResult::None;
        ImGui::PushID(label);
        if(button("..."))
            ret = BrowseResult::Browse;
        ImGui::SameLine();
        if(lineedit("##text", v, opts))
            ret = BrowseResult::Changed;
        ImGui::PopID();
        return ret;
    }

}
