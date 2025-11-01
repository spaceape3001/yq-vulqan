////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/os/GraphicsCard.hpp>
#include <yq/tachyon/os/GraphicsCardData.hpp>
#include <yq/tachyon/api/TachyonMetaWriter.hpp>

namespace yq::tachyon {
    template <typename C>
    class GraphicsCardMeta::Writer : public TachyonMeta::Writer<C> {
    public:
        Writer(GraphicsCardMeta* keyboardInfo) : TachyonMeta::Writer<C>(keyboardInfo)
        {
        }
        
        Writer(GraphicsCardMeta& keyboardInfo) : Writer(&keyboardInfo)
        {
        }
    };

}
