////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "dummy.hpp"

namespace yq::tachyon::im {
    void    dummy(const Size2F&v)
    {
        ImGui::Dummy({v.x, v.y});
    }

    void    dummy(horizontal_k, float v)
    {
        ImGui::Dummy({v, 1});
    }
    
    float   dummy(horizontal_k, to_k, float v)
    {
        float   dx  = v - ImGui::GetCursorPos().x;
        if(dx > 0.)
            ImGui::Dummy({dx, 1.});
        return dx;
    }
    
    void    dummy(vertical_k, float v)
    {
        ImGui::Dummy({1, v});
    }
    
    float   dummy(vertical_k, to_k, float v)
    {
        float dy  = v - ImGui::GetCursorPos().y;
        if(dy > 0.)
            ImGui::Dummy({1.,dy});
        return dy;
    }
}

