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
