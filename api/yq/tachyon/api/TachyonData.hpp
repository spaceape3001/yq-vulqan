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
        TachyonPtr const        object;
        double                  time        = 0.;
        std::vector<Proxy*>     proxies;
        uint64_t                revision    = 0ULL;

        TachyonSnap(Tachyon*);
        virtual ~TachyonSnap();
        
        TachyonSnap(const TachyonSnap&) = delete;
        TachyonSnap(TachyonSnap&&) = delete;
        TachyonSnap& operator=(const TachyonSnap&) = delete;
        TachyonSnap& operator=(TachyonSnap&&) = delete;
    };

    struct TachyonData : public RefCount {
        uint64_t                tick        = 0ULL;
        Ref<const TachyonSnap>  snap;
        std::vector<PostCPtr>   sent, received;
        ThreadID                owner;
        unsigned                thread_id;      //! thread::id() that corresponded to tick()
        
        TachyonData();
        virtual ~TachyonData();
        
        TachyonData(const TachyonData&) = delete;
        TachyonData(TachyonData&&) = delete;
        TachyonData& operator=(const TachyonData&) = delete;
        TachyonData& operator=(TachyonData&&) = delete;
    };
}
