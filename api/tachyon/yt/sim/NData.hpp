////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/api/ID.hpp>
#include <tachyon/typedef/spatial.hpp>

namespace yq::tachyon {

    struct ИSnap {
        // Set this to have coordinates & model transform
        SpatialID   spatial;
        
        virtual ~ИSnap();
    };

    struct ИData {
        virtual ~ИData();
    };
}
