////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

//#include <yq/tachyon/api/dim/3DData.hpp>
#include <yq/tachyon/api/TachyonData.hpp>
#include <yq/tachyon/api/DomainData.hpp>
#include <yq/tachyon/typedef/scene3.hpp>
#include <yq/tensor/Tensor44.hpp>

namespace yq::tachyon {
    struct Domain³Snap : public DomainSnap /* , public ③Snap */ {
        Domain³Snap();
        virtual ~Domain³Snap();
    };
    
    struct Domain³Data : public DomainData /*, public ③Data */ {
        Domain³Data();
        virtual ~Domain³Data();
    };
}

