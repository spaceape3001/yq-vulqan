////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/os/Desktop.hpp>
#include <yq/tachyon/os/DesktopData.hpp>
#include <yq/tachyon/api/ManagerMetaWriter.hpp>

namespace yq::tachyon {
    template <typename C>
    class DesktopMeta::Writer : public ManagerMeta::Writer<C> {
    public:
        Writer(DesktopMeta* lightInfo) : ManagerMeta::Writer<C>(lightInfo)
        {
        }
        
        Writer(DesktopMeta& lightInfo) : Writer(&lightInfo)
        {
        }
    };

}
