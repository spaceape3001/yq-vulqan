////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/os/Monitor.hpp>
#include <yt/os/MonitorData.hpp>
#include <yt/api/TachyonInfoWriter.hpp>

namespace yq::tachyon {
    template <typename C>
    class MonitorInfo::Writer : public TachyonInfo::Writer<C> {
    public:
        Writer(MonitorInfo* monitorInfo) : TachyonInfo::Writer<C>(monitorInfo)
        {
        }
        
        Writer(MonitorInfo& monitorInfo) : Writer(&monitorInfo)
        {
        }
    };

}
