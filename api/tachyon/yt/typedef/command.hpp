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
    class Command;
    class CommandInfo;
    using CommandPtr           = Ref<Command>;
    using CommandCPtr          = Ref<const Command>;

    template <class C>
    concept SomeCommand        = std::derived_from<C,Command>;
}
