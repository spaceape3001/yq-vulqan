////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/meta/MetaBinder.hpp>

namespace yq::tachyon {
    enum class SaveType : uint8_t {
        //! General save, non-specific
        General,
        
        //! Snapshot type of save, will be very descriptive
        Snapshot,
        
        //! Template (group) type of save, so meant for reuse
        Template,
        
        //! Component type of save, again, meant for reuse
        Component
    };
}

YQ_TYPE_DECLARE(yq::tachyon::SaveType)
