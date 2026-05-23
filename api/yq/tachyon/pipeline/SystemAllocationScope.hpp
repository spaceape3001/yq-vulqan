////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/core/Flags.hpp>
#include <yq/meta/MetaBinder.hpp>

namespace yq::tachyon {
    //! Scope of system allocation
    enum class SystemAllocationScope {
        //! Command allocation scope
        Command = 0,
        
        //! Object allocation scope
        Object = 1,
        
        //! Cache allocation scope
        Cache = 2,
        
        //! Device allocation scope
        Device = 3,
        
        //! Instance allocation scope
        Instance = 4
    };
    
    using SystemAllocationScopeFlags = Flags<SystemAllocationScope, uint32_t>;
}

YQ_TYPE_DECLARE(yq::tachyon::SystemAllocationScope)
YQ_TYPE_DECLARE(yq::tachyon::SystemAllocationScopeFlags)
