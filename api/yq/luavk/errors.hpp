////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/core/ErrorDB.hpp>

namespace yq::errors {
    using luavk_cannot_extract_meta   = error_db::entry<"Cannot extract meta from table">;
    using luavk_no_frame_available     = error_db::entry<"No frame available to consult">;
    using luavk_not_valid_camera_id    = error_db::entry<"Not a valid camera ID">;
    using luavk_not_valid_light_id     = error_db::entry<"Not a valid light ID">;
    using luavk_not_valid_rendered_id  = error_db::entry<"Not a valid rendered ID">;
    using luavk_not_a_table           = error_db::entry<"Not a lua table (which is what we use)">;
}
