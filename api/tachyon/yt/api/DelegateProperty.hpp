////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/meta/Meta.hpp>
#include <yq/meta/InfoBinder.hpp>

namespace yq::tachyon {
    class DelegateGetter;
    class DelegateSetter;
    
    class DelegateProperty : public Meta {
        friend class DelegateGetter;
        friend class DelegateSetter;
    public:
    
    
    };
}
