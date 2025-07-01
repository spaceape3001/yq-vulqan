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
    class GroupInfo::Writer : public TachyonMeta::Writer<C> {
    public:
        Writer(GroupInfo* layerInfo) : TachyonMeta::Writer<C>(layerInfo)
        {
        }
        
        Writer(GroupInfo& layerInfo) : Writer(&layerInfo)
        {
        }
    };

}
