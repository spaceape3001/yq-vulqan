////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/basic/Enum.hpp>
#include <yq/meta/InfoBinder.hpp>

namespace yq::tachyon {

    //! Subpass contents
    YQ_ENUM(SubpassContents, ,
    
        //! Inline
        Inline = 0,
        
        //! Using secondary command buffers
        SecondaryCommandBuffers = 1
    )
}

YQ_TYPE_DECLARE(yq::tachyon::SubpassContents)
