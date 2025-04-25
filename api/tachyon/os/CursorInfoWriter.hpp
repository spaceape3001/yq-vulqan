////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/os/Cursor.hpp>
#include <tachyon/os/CursorData.hpp>
#include <tachyon/api/TachyonInfoWriter.hpp>

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
