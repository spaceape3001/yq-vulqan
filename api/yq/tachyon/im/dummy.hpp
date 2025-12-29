////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/MyImGui.hpp>
#include <yq/tachyon/keywords.hpp>
#include <yq/typedef/size2.hpp>

namespace yq::tachyon::im {
    void    dummy(const Size2F&);

    void    dummy(horizontal_k, float);

    //! Adds dummy space to get horizontal spacing to x value, returns the size necessary, negative means it's already
    //! Too far
    float   dummy(horizontal_k, to_k, float);
    
    void    dummy(vertical_k, float);

    //! Adds dummy space to get vertical spacing to y value, returns the size necessary, negative means it's already
    //! Too far
    float   dummy(vertical_k, to_k, float);
}
