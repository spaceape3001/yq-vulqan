////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/units.hpp>
#include <yq/core/Ref.hpp>
#include <yq/tachyon/typedef/clock.hpp>

namespace yq::tachyon {
    struct At {
        uint64_t        tick        = 0ULL;
        unit::Second    time        = {};
        time_point_t    clock;
    };

    struct TachyonData : public RefCount {
        At                      at;
        TachyonPtr              object = {};
        std::vector<Proxy*>     proxies;
        std::vector<PostCPtr>   sent, received;
        ThreadID                owner;
        uint64_t                revision    = 0ULL;
        unsigned                thread_id;      //! thread::id() that corresponded to tick()
        
        TachyonData();
        virtual ~TachyonData();
        
        TachyonData(const TachyonData&) = delete;
        TachyonData(TachyonData&&) = delete;
        TachyonData& operator=(const TachyonData&) = delete;
        TachyonData& operator=(TachyonData&&) = delete;
    };

    using TachyonDataPtr    = Ref<TachyonData>;

    struct ThreadData : public TachyonData {
        std::vector<TachyonDataPtr>     tachyons;       //! Tachyons (excluding the thread)
        std::set<ID>                    created, arrived, left, deleted;
    };

}
