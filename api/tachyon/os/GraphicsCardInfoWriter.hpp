////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/os/GraphicsCard.hpp>
#include <tachyon/os/GraphicsCardData.hpp>
#include <tachyon/api/TachyonMetaWriter.hpp>

namespace yq::tachyon {
    template <typename C>
    class GraphicsCardInfo::Writer : public TachyonMeta::Writer<C> {
    public:
        Writer(GraphicsCardInfo* keyboardInfo) : TachyonMeta::Writer<C>(keyboardInfo)
        {
        }
        
        Writer(GraphicsCardInfo& keyboardInfo) : Writer(&keyboardInfo)
        {
        }
    };

}
