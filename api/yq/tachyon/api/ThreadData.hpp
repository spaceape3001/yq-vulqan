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
    
    struct TachyonFrame {
        TachyonPtr      object;
        TachyonID       id;
        Types           types;
        TachyonDataCPtr data;
        TachyonSnapCPtr snap;
    };

    struct ThreadData : public TachyonData {
        std::vector<TachyonFrame>       tachyons;       //! Tachyons
        std::set<TachyonID>             created, arrived, left, deleted;
        
        virtual ~ThreadData();
    };

}
