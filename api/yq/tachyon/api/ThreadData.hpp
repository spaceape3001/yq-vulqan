////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/TachyonData.hpp>
#include <yq/tachyon/typedef/thread.hpp>
#include <set>

namespace yq::tachyon {
    struct ThreadSnap : public TachyonSnap {
    };

    struct ThreadData : public TachyonData {
        std::vector<TachyonDataCPtr>    tachyons;       //! Tachyons (excluding the thread)
        std::set<TachyonID>             created, arrived, left, deleted;
        
        virtual ~ThreadData();
    };

}
