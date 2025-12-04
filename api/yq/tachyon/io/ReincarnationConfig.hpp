////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/core/Any.hpp>
#include <yq/tachyon/api/ID.hpp>
#include <yq/tachyon/io/SaveTypes.hpp>
#include <yq/tachyon/typedef/tachyon.hpp>
#include <yq/tachyon/typedef/thread.hpp>

namespace yq::tachyon {

    struct ReincarnationConfig {
        ThreadSpec              owner;      //!< Set to override threads (if scheduling)
        TachyonID               parent;     //!< Used to force a parent (owner check auto-disabled)
        save_str_value_map_t    variables;  //!< Used to override anything in the save
    };
}
