////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/os/Monitor.hpp>
#include <yq/tachyon/os/MonitorData.hpp>
#include <yq/tachyon/api/TachyonMetaWriter.hpp>

namespace yq::tachyon {
    template <typename C>
    class MonitorMeta::Writer : public TachyonMeta::Writer<C> {
    public:
        Writer(MonitorMeta* monitorInfo) : TachyonMeta::Writer<C>(monitorInfo)
        {
        }
        
        Writer(MonitorMeta& monitorInfo) : Writer(&monitorInfo)
        {
        }
    };

}
