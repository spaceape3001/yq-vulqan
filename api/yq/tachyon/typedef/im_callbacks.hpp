////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <concepts>
#include <functional>
#include <vector>

namespace yq::tachyon::im {
    template <typename K>
    using TreeDetectorFN        = std::function<bool(K)>;

    template <typename K>
    using FilterFN              = std::function<bool(K)>;
    
    template <typename K>
    using ProviderFN            = std::function<std::vector<K>()>;

    template <typename K>
    using ProviderGeneratorFN   = std::function<ProviderFN<K>>;
}
