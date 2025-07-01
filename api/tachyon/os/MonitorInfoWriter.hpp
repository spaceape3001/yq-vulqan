////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/os/Monitor.hpp>
#include <tachyon/os/MonitorData.hpp>
#include <tachyon/api/TachyonMetaWriter.hpp>

namespace yq::tachyon {
    template <typename C>
    class MonitorInfo::Writer : public TachyonMeta::Writer<C> {
    public:
        Writer(MonitorInfo* monitorInfo) : TachyonMeta::Writer<C>(monitorInfo)
        {
        }
        
        Writer(MonitorInfo& monitorInfo) : Writer(&monitorInfo)
        {
        }
    };

}
