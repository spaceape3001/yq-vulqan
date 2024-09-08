////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <functional>
#include <vector>
#include <tbb/spin_mutex.h>

namespace yq::tachyon {
    using cleanup_fn               = std::function<void()>;
    
    class ViCleanupManager {
    public:
        ViCleanupManager();
        ~ViCleanupManager();
        
        void                add(cleanup_fn&&);
        ViCleanupManager&   operator<<(cleanup_fn&&);
        void                sweep();
        
    private:
        using mutex_t   = tbb::spin_mutex;
        using vector_t  = std::vector<cleanup_fn>;
    
        vector_t            m_cleanup;
        mutable mutex_t     m_mutex;
    };
}
