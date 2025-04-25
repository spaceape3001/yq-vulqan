////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/os/Desktop.hpp>
#include <tachyon/os/DesktopData.hpp>
#include <yt/api/ManagerInfoWriter.hpp>

namespace yq::tachyon {
    template <typename C>
    class DesktopInfo::Writer : public ManagerInfo::Writer<C> {
    public:
        Writer(DesktopInfo* lightInfo) : ManagerInfo::Writer<C>(lightInfo)
        {
        }
        
        Writer(DesktopInfo& lightInfo) : Writer(&lightInfo)
        {
        }
    };

}
