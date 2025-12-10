////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "ASpatial3.hpp"
#include "AOrientation3Writer.hxx"
#include "APosition3Writer.hxx"
#include "AScale3Writer.hxx"

namespace yq::tachyon {
    template <typename C>
    void ASpatial³::init_meta(TachyonMeta::Writer<C>&w)
    {
        APosition³::init_meta(w);
        AOrientation³::init_meta(w);
        AScale³::init_meta(w);
    }
}
