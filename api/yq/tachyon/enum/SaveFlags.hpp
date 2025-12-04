////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/core/Flags.hpp>

namespace yq::tachyon {
    enum class SaveFlag : uint8_t {
        //! Do the threads themeselves,
        DoThreads,
        
        //! Skip the ownership information (ie, no "thread=" in the file)
        SkipOwnership,
        
        //! Skip children (if selective)
        SkipChildren,
        
        //! Want children, skip the listed
        OnlyChildren,
        
        //! Skip state saving
        SkipState
    };
    using SaveFlags = Flags<SaveFlag>;
}

