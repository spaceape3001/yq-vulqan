////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <concepts>

namespace yq {
    template <typename> class Ref;
}

namespace yq::tachyon {
    class Action;
    class ActionMeta;
    
    using ActionPtr  = Ref<Action>;
    using ActionCPtr = Ref<const Action>;
    
    template <typename T>
    concept SomeAction  = std::derived_from<T,Action>;
}
