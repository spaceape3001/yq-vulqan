////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/units.hpp>
#include <yq/core/Ref.hpp>
#include <yq/tachyon/typedef/tachyon.hpp>

namespace yq::tachyon {

    class Proxy;

    class AppFrame : public RefCount {
    public:
    
        using clock_t  = std::chrono::high_resolution_clock;
    
        //! Our time point
        //
    
        
    
    private:
        using proxy_hash_t      = std::unordered_multimap<uint64_t, Proxy*>;
    
    
        unit::Second            m_time      = {};
        uint64_t                m_tick      = 0;
        proxy_hash_t            m_proxies;
        std::vector<TachyonPtr> m_objects;
        std::vector<TachyonPtr> m_dead;      // Will be deleted at a later frame
    };
}
