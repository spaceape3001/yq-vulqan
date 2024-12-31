////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/desktop/Cursor.hpp>
#include <yq/tachyon/desktop/CursorData.hpp>
#include <yq/tachyon/api/TachyonInfoWriter.hpp>

namespace yq::tachyon {
    template <typename C>
    class CursorInfo::Writer : public TachyonInfo::Writer<C> {
    public:
        Writer(CursorInfo* cursorInfo) : TachyonInfo::Writer<C>(cursorInfo)
        {
        }
        
        Writer(CursorInfo& cursorInfo) : Writer(&cursorInfo)
        {
        }
    };

}
