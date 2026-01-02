////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/container/reverse.hpp>
#include <type_traits>
#include <vector>
#include <imgui_internal.h>

namespace yq::tachyon::im {
    template <typename Pred>
    void    stackback(Pred&& pred)
    {
        auto &idStack = ImGui::GetCurrentWindow()->IDStack;
        const auto oldID  = idStack.back();
        idStack.pop_back();
        pred();
        idStack.push_back(oldID);
    }

    template <typename Pred>
    void    stackback(unsigned cnt, Pred&& pred)
    {
        auto &idStack = ImGui::GetCurrentWindow()->IDStack;
        using id_type   = std::remove_cvref_t<decltype(idStack.back())>;
        std::vector<id_type>    ids;
        ids.reserve(cnt);
        for(unsigned int n=0;(n<cnt) && !idStack.empty(); ++cnt){
            ids.push_back(idStack.back());
            idStack.pop_back();
        }
        
        pred();
        
        for(id_type i2 : reverse(ids))
            idStack.push_back(i2);
    }
}
