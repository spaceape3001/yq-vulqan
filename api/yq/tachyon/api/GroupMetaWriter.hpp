////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/api/Group.hpp>
#include <tachyon/api/GroupData.hpp>
#include <tachyon/api/TachyonMetaWriter.hpp>

namespace yq::tachyon {
    template <typename C>
    class GroupMeta::Writer : public TachyonMeta::Writer<C> {
    public:
        Writer(GroupMeta* layerInfo) : TachyonMeta::Writer<C>(layerInfo)
        {
        }
        
        Writer(GroupMeta& layerInfo) : Writer(&layerInfo)
        {
        }
    };

}
