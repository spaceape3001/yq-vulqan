////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/net/Url.hpp>
#include <yq/tachyon/api/ThreadData.hpp>

namespace yq::tachyon {
    struct TEDocumentSnap : public ThreadSnap {  // change if edit thread changes
        Url     url;
    };
    
    struct TEDocumentData : public ThreadData {
    };
}
