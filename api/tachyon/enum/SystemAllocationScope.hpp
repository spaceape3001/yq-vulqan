////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/basic/Enum.hpp>
#include <yq/meta/InfoBinder.hpp>

namespace yq::tachyon {
    //! Scope of system allocation
    YQ_ENUM(SystemAllocationScope, ,
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
    )
}

YQ_TYPE_DECLARE(yq::tachyon::SystemAllocationScope)
