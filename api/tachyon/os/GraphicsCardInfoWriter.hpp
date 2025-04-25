////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/os/GraphicsCard.hpp>
#include <tachyon/os/GraphicsCardData.hpp>
#include <tachyon/api/TachyonInfoWriter.hpp>

namespace yq::tachyon {
    template <typename C>
    class GraphicsCardInfo::Writer : public TachyonInfo::Writer<C> {
    public:
        Writer(GraphicsCardInfo* keyboardInfo) : TachyonInfo::Writer<C>(keyboardInfo)
        {
        }
        
        Writer(GraphicsCardInfo& keyboardInfo) : Writer(&keyboardInfo)
        {
        }
    };

}
