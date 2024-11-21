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
        std::vector<Proxy*>     proxies;
        uint64_t                revision    = 0ULL;
        double                  time        = 0.;
        
        TachyonSnap();
        virtual ~TachyonSnap();
    };

    struct TachyonData : public RefCount {
        struct {
            std::vector<PostCPtr>   sent;
            std::vector<PostCPtr>   received;
            std::vector<PostCPtr>   accepted;
            std::vector<PostCPtr>   forward;
            std::vector<PostCPtr>   children;
            std::vector<PostCPtr>   parent;
        }                       post;

        uint64_t                tick        = 0ULL;
        
        ThreadID                owner;
        
        TachyonData();
        virtual ~TachyonData();
    };
}
