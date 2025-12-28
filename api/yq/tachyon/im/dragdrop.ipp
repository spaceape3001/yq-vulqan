////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "dragdrop.hpp"
#include <yq/net/Url.hpp>
#include <yq/text/match.hpp>

namespace yq::tachyon::im {
    const ImGuiPayload*   accept_drop(const char* type, ImGuiDragDropFlags flags)
    {
        return ImGui::AcceptDragDropPayload(type, flags);
    }

    const ImGuiPayload*   accept_drop(const string_view_vector_t& types, ImGuiDragDropFlags flags)
    {
        const ImGuiPayload* payload = get_drag_payload();
        if(!payload)
            return nullptr;
        if(is_in(payload->DataType, types))
            return accept_drop(payload->DataType, flags);
        return nullptr;
    }

    bool    begin_drag_source(ImGuiDragDropFlags flags)
    {
        return ImGui::BeginDragDropSource(flags);
    }
    
    bool    begin_drop_target()
    {
        return ImGui::BeginDragDropTarget();
    }

    void    end_drag_source()
    {
        return ImGui::EndDragDropSource();
    }
    
    void    end_drop_target()
    {
        return ImGui::EndDragDropTarget();
    }

    const ImGuiPayload* get_drag_payload()
    {
        return ImGui::GetDragDropPayload();
    }

    bool  set_drag_payload(const char* type, const void*data, size_t sz, ImGuiCond cond)
    {
        return ImGui::SetDragDropPayload(type, data, sz, cond);
    }
    
    bool  set_drag_payload(const char* type, std::string_view sv, ImGuiCond cond)
    {
        return set_drag_payload(type, sv.data(), sv.size(), cond);
    }

    bool    set_drag_payload(const char* type, uint64_t v, ImGuiCond cond)
    {
        return set_drag_payload(type, &v, sizeof(v), cond);
    }

    bool    set_drag_payload(const char* type, const Url& u, ImGuiCond cond )
    {
        return set_drag_payload(type, to_string(u), cond);
    }
}
