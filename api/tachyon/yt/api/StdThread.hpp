////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/core/Enum.hpp>
#include <yq/core/Flag.hpp>
#include <yq/meta/InfoBinder.hpp>
#include <yt/typedef/thread.hpp>

namespace yq::tachyon {
    /*! \brief Standard threads
    
        These are considered "standard" controlling threads.
        
        \note This is *NOT* a restriction, simply a way to automate some
        common needed threads.
    */
    YQ_ENUM(StdThread, , 
        // Application/OS/Input
        App     = 0,
        
        // Audio thread
        Audio,
        
        // Game thread
        Game,
        
        // IO thread (ie saving)
        IO,
        
        // Network thread
        Network,
        
        // Sim thread
        Sim,
        
        // Task thread (for longer, drawn out tasking)
        Task,
        
        // Visual/UI thread
        Viewer
    )
    
    using StdThreadFlags    = Flag<StdThread>;
    using StdThreadRevMap   = std::map<ThreadID, StdThread>;
}

YQ_TYPE_DECLARE(yq::tachyon::StdThread)
YQ_TYPE_DECLARE(yq::tachyon::StdThreadFlags)
