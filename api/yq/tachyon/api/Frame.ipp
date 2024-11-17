////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/units.hpp>
#include <yq/core/Ref.hpp>
#include <yq/tachyon/api/ID.hpp>
#include <yq/tachyon/typedef/post.hpp>
#include <yq/tachyon/typedef/proxy.hpp>
#include <yq/tachyon/typedef/tachyon.hpp>

#include <chrono>

namespace yq::tachyon {


    /*
        Tachyons will *belong* to a thread... either directly or indirectly 
        (ie a chain).  During some threads execution (ie, sim-thread or viz-thread), 
        these may be temporarily delegated into other threads, but will not strip 
        the owning thread of ownership.
    */


    struct TachyonData {
        TachyonPtr              tachyon = {};
        std::vector<ProxyPtr>   proxies;
        std::vector<PostCPtr>   sent, received;
        uint64_t                revision    = 0ULL;
    };

    struct ThreadData {
        unsigned                    thread_id;  //! as reported by thread::id()
        uint64_t                    tick        = 0;
        unit::Second                time        = {};   // start of 
        std::vector<TachyonData>    tachyons;
        std::set<ID>                created, arrived, left, deleted;
    };

    class ThreadFrame : public RefCount {
    public:
    

        //! Thread tick number, always monotonically increasing
        uint64_t        tick() const { return m_tick; }
        
        //! App time
        unit::Second    time() const { return m_time; }

        ThreadFrame();
        ~ThreadFrame();
        
        bool            send(TachyonID, const PostCPtr&);

        using proxy_span_t      = std::span<const ProxyPtr>;
        using post_span_t       = std::span<const PostCPtr>;

    private:
    
        using tachyon_hash_t    = std::unordered_map<uint64_t, TachyonPtr>;
        using proxy_hash_t      = std::unordered_map<uint64_t, proxy_span_t>;
        using post_hash_t       = std::unordered_map<uint64_t, post_span_t>;
    
        unit::Second            m_time      = {};
        uint64_t                m_tick      = 0;
        tachyon_hash_t          m_live, m_dead;
        proxy_hash_t            m_proxies;
        post_hash_t             m_sent, m_received;
    };
}
