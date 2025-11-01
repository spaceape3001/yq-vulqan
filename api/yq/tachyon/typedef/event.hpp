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
    class Event;
    class EventMeta;
    using EventPtr           = Ref<Event>;
    using EventCPtr          = Ref<const Event>;

    template <class E>
    concept SomeEvent        = std::derived_from<E,Event>;
}
