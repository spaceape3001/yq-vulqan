////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "ViShaderManager.hpp"
#include <yq-toolbox/basic/ErrorDB.hpp>
#include <yq-vulqan/shader/Shader.hpp>
#include <yq-vulqan/viz/ViShader.hpp>

namespace yq::tachyon {
    ViShaderManager::ViShaderManager(ViVisualizer& viz) : m_viz(viz)
    {
    }
    
    ViShaderManager::~ViShaderManager()
    {
        cleanup();
    }

    void                ViShaderManager::cleanup()
    {
        m_shaders.clear();
    }

    ViShaderCPtr    ViShaderManager::create(const Shader& sh)
    {
        {
            mutex_t::scoped_lock _lock(m_mutex, false);
            auto j = m_shaders.find(sh.id());
            if(j != m_shaders.end())
                return j->second;
        }
        
        ViShaderCPtr    p, ret;
        p   = new ViShader(m_viz, sh);
        if(!p->valid())
            return {};
        
        {
            mutex_t::scoped_lock _lock(m_mutex, true);
            auto [j,f]  = m_shaders.try_emplace(sh.id(), p);
            if(f){
                std::swap(p, ret);
            } else {
                ret = j->second;
            }
        }
        
        return ret;
    }
    
    ViShaderCPtr   ViShaderManager::get(uint64_t i) const
    {
        {
            mutex_t::scoped_lock _lock(m_mutex, false);
            auto itr = m_shaders.find(i);
            if(itr != m_shaders.end())
                return itr->second;
        }

        return {};
    }
    
    bool                ViShaderManager::has(uint64_t i) const
    {
        mutex_t::scoped_lock _lock(m_mutex, false);
        return m_shaders.contains(i);
    }
}
