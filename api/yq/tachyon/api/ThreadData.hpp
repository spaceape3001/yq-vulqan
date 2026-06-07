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

    class ThreadSnap : public TachyonSnap {
        YQ_OBJECT_DECLARE(ThreadSnap, TachyonSnap)
    public:
        bool        paused      = false;
        double      overclock   = 0.;
        
        ThreadSnap();
        virtual ~ThreadSnap();
        static void init_meta();
    };
    
    class ThreadData : public TachyonData {
        YQ_OBJECT_DECLARE(ThreadData, TachyonData)
    public:
        std::vector<TachyonFrame>       tachyons;       //! Tachyons
        std::set<TachyonID>             created, arrived, left, deleted;
        //unit::Second                    duration;       //! Time to process
        unit::Second                    time;
        
        ThreadData();
        virtual ~ThreadData();
        static void init_meta();
    };

    struct ThreadFrame {
        ThreadPtr           thread;
        ThreadDataCPtr      data;
        ThreadSnapCPtr      snap;
        
        operator TachyonFrame() const;
    };
}
