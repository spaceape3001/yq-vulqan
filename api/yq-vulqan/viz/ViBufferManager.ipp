////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "ViBufferManager.hpp"

#include <yq-toolbox/basic/ErrorDB.hpp>
#include <yq-vulqan/memory/Buffer.hpp>
#include <yq-vulqan/viz/ViBuffer.hpp>

namespace yq::tachyon {
    ViBufferManager::ViBufferManager(ViVisualizer& viz) : m_viz(viz)
    {
    }
    
    ViBufferManager::~ViBufferManager()
    {
        cleanup();
    }

    void                ViBufferManager::cleanup()
    {
        m_buffers.clear();
    }

    ViBufferCPtr    ViBufferManager::create(const Buffer&buf)
    {
        {
            mutex_t::scoped_lock _lock(m_mutex, false);
            auto j = m_buffers.find(buf.id());
            if(j != m_buffers.end())
                return j->second;
        }

        ViBufferCPtr    ret, p;
        
        p       = new ViBuffer(m_viz, buf);
        if(!p->valid())
            return {};
        
        {
            mutex_t::scoped_lock _lock(m_mutex, true);
            auto [j,f]  = m_buffers.try_emplace(buf.id(), p);
            if(f){
                std::swap(p, ret);
            } else
                ret = j->second;
        }

        return ret;
    }

    void                ViBufferManager::erase(const Buffer& buf)
    {
        erase(buf.id());
    }
    
    void                ViBufferManager::erase(uint64_t i)
    {
        ViBufferCPtr    vb;
        {
            mutex_t::scoped_lock _lock(m_mutex, true);
            auto j  = m_buffers.find(i);
            if(j != m_buffers.end()){
                vb      = j->second;
                m_buffers.erase(j);
            }
        }
    }
    
    ViBufferCPtr    ViBufferManager::get(uint64_t i) const
    {
        {
            mutex_t::scoped_lock _lock(m_mutex, false);
            auto j = m_buffers.find(i);
            if(j != m_buffers.end())
                return j->second;
        }

        return {};
    }
    
    bool                ViBufferManager::has(uint64_t i) const
    {
        mutex_t::scoped_lock _lock(m_mutex, false);
        return m_buffers.contains(i);
    }

}
