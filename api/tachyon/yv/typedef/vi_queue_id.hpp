////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <cstdint>

namespace yq::tachyon {
    struct ViQueueFamilyID {
        uint32_t    index      = UINT32_MAX;
        auto    operator<=>(const ViQueueFamilyID&) const = default;
        bool    valid() const { return index != UINT32_MAX; }
        bool    invalid() const { return index == UINT32_MAX; }
    };

    struct ViQueueID {  // TBH... 16 or even 8-bits might be enough here... spec is 32-bits though
        ViQueueFamilyID     family;
        uint32_t            sub     = UINT32_MAX;
        
        auto    operator<=>(const ViQueueID&) const = default;
        bool    valid() const { return family.valid() && (sub != UINT32_MAX); }
        bool    invalid() const { return family.invalid() || (sub == UINT32_MAX); }
    };
}
