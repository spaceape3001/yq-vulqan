////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "ViImageManager.hpp"

#include <yq-vulqan/image/Image.hpp>
#include <yq-vulqan/viz/ViImage.hpp>

namespace yq::tachyon {
    ViImageManager::ViImageManager(ViVisualizer& viz) : m_viz(viz)
    {
    }
    
    ViImageManager::~ViImageManager()
    {
        cleanup();
    }

    void                ViImageManager::cleanup()
    {
        m_images.clear();
    }

    ViImageCPtr    ViImageManager::create(const Image&buf)
    {
        {
            mutex_t::scoped_lock _lock(m_mutex, false);
            auto j = m_images.find(buf.id());
            if(j != m_images.end())
                return j->second;
        }

        ViImageCPtr    ret, p;
        
        p       = new ViImage(m_viz, buf);
        if(!p->valid())
            return {};
        
        {
            mutex_t::scoped_lock _lock(m_mutex, true);
            auto [j,f]  = m_images.try_emplace(buf.id(), p);
            if(f){
                std::swap(p, ret);
            } else
                ret = j->second;
        }

        return ret;
    }

    void                ViImageManager::erase(const Image& buf)
    {
        erase(buf.id());
    }
    
    void                ViImageManager::erase(uint64_t i)
    {
        ViImageCPtr    vb;
        {
            mutex_t::scoped_lock _lock(m_mutex, true);
            auto j  = m_images.find(i);
            if(j != m_images.end()){
                vb      = j->second;
                m_images.erase(j);
            }
        }
    }
    
    ViImageCPtr    ViImageManager::get(uint64_t i) const
    {
        {
            mutex_t::scoped_lock _lock(m_mutex, false);
            auto j = m_images.find(i);
            if(j != m_images.end())
                return j->second;
        }

        return {};
    }
    
    bool                ViImageManager::has(uint64_t i) const
    {
        mutex_t::scoped_lock _lock(m_mutex, false);
        return m_images.contains(i);
    }
}
