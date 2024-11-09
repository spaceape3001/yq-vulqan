////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/units.hpp>
#include <yq/core/Ref.hpp>
#include <yq/tachyon/typedef/viewer.hpp>

namespace yq::tachyon {
    class AppFrame : public RefCount {
    public:
    
        //! App Tick number, always monotonically increasing
        uint64_t        tick() const { return m_tick; }
        
        //! Sim time
        unit::Second    time() const { return m_time; }
    
    private:
        unit::Second            m_time      = {};
        uint64_t                m_tick      = 0;
        
        std::vector<ViewerPtr>  m_viewers;
    };
}
