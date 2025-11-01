////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

/*
    Due to the irregular inheritance patterns, we need the base classes to 
    register handlers, however, it'd be burdensome to make the users do all 
    the heavy lifting.  Therefore, the base classes within the tachyon library
    can call these... outside users won't need to as the regular inheritance
    mechanisms will work.
*/

#include <yq/tachyon/api/2D.hpp>
#include <yq/tachyon/api/NWriter.hxx>

namespace yq::tachyon {
    template <typename C>
    void     ②::init_meta(TachyonMeta::Writer<C>&w)
    {
        И::init_meta(w);
    }
}

