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
    class Trigger;
    class TriggerInfo;
    using TriggerPtr           = Ref<Trigger>;
    using TriggerCPtr          = Ref<const Trigger>;

    template <class T>
    concept SomeTrigger        = std::derived_from<T,Trigger>;
}
