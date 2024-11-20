////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/core/Ref.hpp>
#include <yq/tachyon/api/ID.hpp>
#include <yq/tachyon/typedef/post.hpp>
#include <yq/tachyon/typedef/tachyon.hpp>
#include <yq/tachyon/typedef/thread.hpp>
#include <vector>

namespace yq::tachyon {
    class Proxy;
    
    struct TachyonSnap : public RefCount {
        double                  time        = 0.;
        std::vector<Proxy*>     proxies;
        uint64_t                revision    = 0ULL;
        
        TachyonSnap();
        virtual ~TachyonSnap();
    };

    struct TachyonData : public RefCount {
        uint64_t                tick        = 0ULL;
        std::vector<PostCPtr>   sent, received;
        ThreadID                owner;
        unsigned                thread_id   = ~0;      //! thread::id() that corresponded to tick()
        
        TachyonData();
        virtual ~TachyonData();
    };
}
