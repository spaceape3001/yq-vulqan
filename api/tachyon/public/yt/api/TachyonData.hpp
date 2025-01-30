////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/core/Ref.hpp>
#include <yq/unit/MKS.hpp>
#include <yq/unit/SCALED.hpp>
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
        unit::Second            time        = 0.;
        TypedID                 parent;
        TypedID                 self;
        std::vector<TypedID>    children;
        bool                    started     = false;
        bool                    running     = false;
        bool                    paused      = false;
        bool                    teardown    = false;
        
        TachyonSnap();
        virtual ~TachyonSnap();
        
        constexpr uint64_t id() const { return self.id; }
    };

    struct InPost {
        enum class State {
            Accepted = 0,
            Rejected,
            Duplicate
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
        unit::Nanosecond        cycleTime   = { 0. };
        
        TachyonData();
        virtual ~TachyonData();
    };
}
