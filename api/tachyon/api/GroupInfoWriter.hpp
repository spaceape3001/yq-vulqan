////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/api/Group.hpp>
#include <tachyon/api/GroupData.hpp>
#include <tachyon/api/TachyonInfoWriter.hpp>

namespace yq::tachyon {
    template <typename C>
    class GroupInfo::Writer : public TachyonInfo::Writer<C> {
    public:
        Writer(GroupInfo* layerInfo) : TachyonInfo::Writer<C>(layerInfo)
        {
        }
        
        Writer(GroupInfo& layerInfo) : Writer(&layerInfo)
        {
        }
    };

}
