////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/os/GraphicsCard.hpp>
#include <yt/os/GraphicsCardData.hpp>
#include <yt/api/TachyonInfoWriter.hpp>

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
