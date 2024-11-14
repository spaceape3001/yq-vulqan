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
    class Plugin;
    class PluginInfo;
    using PluginPtr           = Ref<Plugin>;
    using PluginCPtr          = Ref<const Plugin>;

    template <class E>
    concept SomePlugin        = std::derived_from<E,Plugin>;
}
