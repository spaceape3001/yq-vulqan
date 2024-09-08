////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "ViCleanupManager.hpp"
#include <utility>

namespace yq::tachyon {
    ViCleanupManager::ViCleanupManager()
    {
    }
    
    ViCleanupManager::~ViCleanupManager()
    {
        sweep();
    }
    
    void                ViCleanupManager::add(cleanup_fn&& fn)
    {
        mutex_t::scoped_lock _lock(m_mutex);
        m_cleanup.push_back(std::move(fn));
    }
    
    ViCleanupManager&   ViCleanupManager::operator<<(cleanup_fn&& fn)
    {
        add(std::move(fn));
        return *this;
    }
    
    void                ViCleanupManager::sweep()
    {
        vector_t    what;
        {
            mutex_t::scoped_lock _lock(m_mutex);
            std::swap(what, m_cleanup);
        }
        for(cleanup_fn& fn : what){
            fn();
        }
    }
}
