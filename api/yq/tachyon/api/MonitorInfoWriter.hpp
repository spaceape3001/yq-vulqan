////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Monitor.hpp>
#include <yq/tachyon/api/MonitorData.hpp>
#include <yq/tachyon/api/TachyonInfoWriter.hpp>

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
