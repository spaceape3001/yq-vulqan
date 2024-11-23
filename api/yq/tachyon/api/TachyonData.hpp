////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/core/Ref.hpp>
#include <yq/tachyon/api/ID.hpp>
#include <yq/tachyon/api/MG.hpp>
#include <yq/tachyon/api/TypedID.hpp>
#include <yq/tachyon/typedef/post.hpp>
#include <yq/tachyon/typedef/tachyon.hpp>
#include <yq/tachyon/typedef/thread.hpp>
#include <vector>

namespace yq::tachyon {
    class Proxy;
    
    struct TachyonSnap : public RefCount {
        std::vector<Proxy*>     proxies;
        uint64_t                revision    = 0ULL;
        double                  time        = 0.;
        TypedID                 parent;
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
        PostCPtr    post;
        MGF         groups;
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
