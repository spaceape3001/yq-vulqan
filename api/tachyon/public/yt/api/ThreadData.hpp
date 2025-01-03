////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/api/TachyonData.hpp>
#include <yt/typedef/thread.hpp>
#include <set>

namespace yq::tachyon {

    enum class TachyonThreadState {
        Normal  = 0,    //!< Normal thread operating state
        Pushed,         //!< Been moved/pushed to another thread
        Delete          //!< In the deletion queue, will be dead in a short while
    };

    struct TachyonFrame {
        TachyonPtr          object;
        TachyonDataCPtr     data;
        TachyonSnapCPtr     snap;
        TachyonThreadState  state = TachyonThreadState::Normal;
    };

    struct ThreadSnap : public TachyonSnap {
        virtual ~ThreadSnap();
    };
    
    struct ThreadData : public TachyonData {
        std::vector<TachyonFrame>       tachyons;       //! Tachyons
        std::set<TachyonID>             created, arrived, left, deleted;
        unit::Second                    duration;       //! Time to process
        
        virtual ~ThreadData();
    };

    struct ThreadFrame {
        ThreadPtr           thread;
        ThreadDataCPtr      data;
        ThreadSnapCPtr      snap;
        
        operator TachyonFrame() const;
    };
}
