////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/keywords.hpp>
#include <yt/os/StdCursor.hpp>
#include <variant>

namespace yq {
    template <typename> class Ref;
}

namespace yq::tachyon {

    class Cursor;
    using CursorPtr      = Ref<Cursor>;
    using CursorCPtr     = Ref<const Cursor>;

    struct CursorSnap;
    using CursorSnapPtr  = Ref<CursorSnap>;
    using CursorSnapCPtr = Ref<const CursorSnap>;
    
    struct CursorData;
    using CursorDataPtr  = Ref<CursorData>;
    using CursorDataCPtr = Ref<const CursorData>;

    template <class> class ID;
    using CursorID = ID<Cursor>;

    using cursor_spec       = std::variant<std::monostate, disabled_k, StdCursor, CursorID>; // TODO... raster image
}
