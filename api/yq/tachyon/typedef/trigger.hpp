////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <concepts>
#include <memory>

//namespace yq { 
    //template <typename> class Ref;
//}

namespace yq::tachyon {
    class Trigger;
    class TriggerInfo;
    using TriggerCPtr           = std::unique_ptr<const Trigger>;
    using TriggerPtr            = std::unique_ptr<Trigger>;
    //using TriggerCPtr          = Ref<const Trigger>;

    template <class T>
    concept SomeTrigger        = std::derived_from<T,Trigger>;
}
