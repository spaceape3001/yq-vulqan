////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/net/Url.hpp>
#include <yq/tachyon/api/ThreadData.hpp>

namespace yq::tachyon {
    struct TEDocSnap : public ThreadSnap {  // change if edit thread changes
        Url     url;
    };
    
    struct TEDocData : public ThreadData {
    };
}
