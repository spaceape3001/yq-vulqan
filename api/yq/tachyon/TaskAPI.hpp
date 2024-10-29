////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/Task.hpp>

namespace yq {}

namespace yq::tachyon {
    class TaskEngine;
    class Application;

    class TaskAPI {
        friend class TaskEngine;
        friend class Application;
    public:
    
    
        //! Desired overclock
        double  overclock() const { return m_overclock; }
        
    private:
        double          m_overclock   = 1.0;
    };
}
