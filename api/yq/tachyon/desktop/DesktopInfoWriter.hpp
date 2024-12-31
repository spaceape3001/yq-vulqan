////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/desktop/Desktop.hpp>
#include <yq/tachyon/desktop/DesktopData.hpp>
#include <yq/tachyon/api/ManagerInfoWriter.hpp>

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