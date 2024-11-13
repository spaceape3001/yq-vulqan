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
    class Message;
    class MessageInfo;
    using MessagePtr           = Ref<Message>;
    using MessageCPtr          = Ref<const Message>;

    template <class M>
    concept SomeMessage        = std::derived_from<M,Message>;
}
