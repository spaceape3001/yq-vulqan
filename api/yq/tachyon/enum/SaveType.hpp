////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/core/Enum.hpp>
#include <yq/meta/MetaBinder.hpp>

namespace yq::tachyon {
    YQ_ENUM(SaveType, , 
        //! General save, non-specific
        General,
        
        //! Snapshot type of save, will be very descriptive
        Snapshot,
        
        //! Template (group) type of save, so meant for reuse
        Template,
        
        //! Component type of save, again, meant for reuse
        Component
    )
}

YQ_TYPE_DECLARE(yq::tachyon::SaveType)
