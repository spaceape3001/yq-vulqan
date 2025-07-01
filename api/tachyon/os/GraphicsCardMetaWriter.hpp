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
