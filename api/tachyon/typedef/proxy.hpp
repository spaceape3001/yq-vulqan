////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <concepts>
#include <functional>

namespace yq { 
    template <typename> class Ref;
}

namespace yq::tachyon {
    class Proxy;
    
    template <class P>
    concept SomeProxy        = std::derived_from<P,Proxy>;
    
    using ProxyFN           = std::function<void()>;
}
