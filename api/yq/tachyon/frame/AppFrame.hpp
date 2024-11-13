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

    class Proxy;

    class AppFrame : public RefCount {
    public:
    
        using clock_t  = std::chrono::high_resolution_clock;
    
        //! Our time point
        //using time_point_t  = clock_t::time_point;
    
        //! App Tick number, always monotonically increasing
        uint64_t        tick() const { return m_tick; }
        
        //! App time
        unit::Second    time() const { return m_time; }
        
    
    private:
        unit::Second                            m_time      = {};
        uint64_t                                m_tick      = 0;
        std::unordered_map<uint64_t, Proxy*>    m_proxies;
    };
}
