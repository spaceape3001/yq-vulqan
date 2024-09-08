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
        for(auto& b : m_buffers)
            b.second.destroy(m_viz);
        m_buffers.clear();
    }

    Expect<ViBuffer>    ViBufferManager::create(const Buffer&buf)
    {
        {
            mutex_t::scoped_lock _lock(m_mutex, false);
            auto j = m_buffers.find(buf.id());
            if(j != m_buffers.end())
                return j->second;
        }

        ViBuffer p, ret;
        auto ec = p.create(m_viz, buf);
        if(ec)
            return unexpected(ec);
        
        {
            mutex_t::scoped_lock _lock(m_mutex, true);
            auto [j,f]  = m_buffers.try_emplace(buf.id(), p);
            if(f){
                std::swap(p, ret);
            } else
                ret = j->second;
        }

        if(p.buffer)
            p.destroy(m_viz);
        return ret;
    }

    void                ViBufferManager::erase(const Buffer& buf)
    {
        erase(buf.id());
    }
    
    void                ViBufferManager::erase(uint64_t i)
    {
        ViBuffer    vb;
        {
            mutex_t::scoped_lock _lock(m_mutex, true);
            auto j  = m_buffers.find(i);
            if(j != m_buffers.end()){
                vb      = j->second;
                m_buffers.erase(j);
            }
        }
        
        if(vb.buffer)
            vb.destroy(m_viz);
    }
    
    Expect<ViBuffer>    ViBufferManager::get(uint64_t i) const
    {
        {
            mutex_t::scoped_lock _lock(m_mutex, false);
            auto j = m_buffers.find(i);
            if(j != m_buffers.end())
                return j->second;
        }

        return unexpected<"Unable to located specified buffer">();
    }
    
    bool                ViBufferManager::has(uint64_t i) const
    {
        mutex_t::scoped_lock _lock(m_mutex, false);
        return m_buffers.contains(i);
    }

}
