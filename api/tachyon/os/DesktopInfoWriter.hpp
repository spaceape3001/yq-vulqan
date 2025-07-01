////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/os/Desktop.hpp>
#include <tachyon/os/DesktopData.hpp>
#include <tachyon/api/ManagerMetaWriter.hpp>

namespace yq::tachyon {
    template <typename C>
    class DesktopInfo::Writer : public ManagerMeta::Writer<C> {
    public:
        Writer(DesktopInfo* lightInfo) : ManagerMeta::Writer<C>(lightInfo)
        {
        }
        
        Writer(DesktopInfo& lightInfo) : Writer(&lightInfo)
        {
        }
    };

}
