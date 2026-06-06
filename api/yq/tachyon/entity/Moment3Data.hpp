////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/ModelData.hpp>
#include <yq/tachyon/typedef/moment3.hpp>

namespace yq::tachyon {
    struct Moment³Snap : public ModelSnap {
        Moment³Snap();
        ~Moment³Snap();
    };
    
    struct Moment³Data : public ModelData {
        Moment³Data();
        ~Moment³Data();
    };
}
