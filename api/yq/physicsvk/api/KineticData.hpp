////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/TachyonData.hpp>
#include <yq/physicsvk/typedef/kinetic.hpp>

namespace yq::tachyon {
    struct KineticSnap : public TachyonSnap {
    };
    
    struct KineticData : public TachyonData {
    };
}
