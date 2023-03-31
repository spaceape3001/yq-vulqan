////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <basic/ErrorDB.hpp>

namespace yq {
    namespace errors {
        using no_queue_found    = error_db::entry<"No Suitable Queue Found">;
    }
}