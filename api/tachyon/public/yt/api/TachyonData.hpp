////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/core/Ref.hpp>
#include <yt/api/ID.hpp>
#include <yt/msg/MG.hpp>
#include <yt/api/TypedID.hpp>
#include <yt/typedef/post.hpp>
#include <yt/typedef/tachyon.hpp>
#include <yt/typedef/thread.hpp>
#include <vector>

namespace yq::tachyon {
    class Proxy;
    
    struct TachyonSnap : public RefCount {
        std::vector<Proxy*>     proxies;
        uint64_t                revision    = 0ULL;
        double                  time        = 0.;
        TypedID                 parent;
        TypedID                 self;
        std::vector<TypedID>    children;
        
        TachyonSnap();
        virtual ~TachyonSnap();
    };

    struct InPost {
        enum class State {
            Rejected = 0,
            Accepted
        };
        PostCPtr    post;
        State       state   = State::Rejected;
    };
    

    struct OutPost {
        PostTarget  to;
        PostCPtr    post;
    };

    struct TachyonData : public RefCount {
        std::vector<InPost>     inbound;
        std::vector<OutPost>    outbound;
        uint64_t                tick        = 0ULL;
        ThreadID                owner;
        
        TachyonData();
        virtual ~TachyonData();
    };
}