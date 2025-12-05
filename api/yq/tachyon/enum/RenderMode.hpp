////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/core/Enum.hpp>
#include <yq/meta/MetaBinder.hpp>

namespace yq::tachyon {
    YQ_ENUM(RenderMode, ,
        //! Simple rendering (ie... whatever the fragment says)  
        Simple,
        
        //! Use lighting ... objects that can't will default to simple
        Light,
        
        //! Use ray tracing ... objects that can't will default to lights or simple
        Ray
    )
}

YQ_TYPE_DECLARE(yq::tachyon::RenderMode)
