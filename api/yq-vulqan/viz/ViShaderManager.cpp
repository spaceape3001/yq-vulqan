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
    ViShaderManager::ViShaderManager(VkDevice dev) : m_device(dev)
    {
    }
    
    ViShaderManager::~ViShaderManager()
    {
        cleanup();
    }

    void                ViShaderManager::cleanup()
    {
        for(auto& psh : m_shaders){
            psh.second.destroy(m_device);
        }
        m_shaders.clear();
    }

    Expect<ViShader>    ViShaderManager::create(const Shader& sh)
    {
        {
            mutex_t::scoped_lock _lock(m_mutex, false);
            auto j = m_shaders.find(sh.id());
            if(j != m_shaders.end())
                return j->second;
        }
        
        ViShader    p, ret;
        auto ec = p.create(m_device, sh);
        if(ec)
            return unexpected(ec);
        
        {
            mutex_t::scoped_lock _lock(m_mutex, true);
            auto [j,f]  = m_shaders.try_emplace(sh.id(), p);
            if(f){
                std::swap(p, ret);
            } else {
                ret = j->second;
            }
        }
        
        if(p.shader)
            p.destroy(m_device);
        return ret;
    }
    
    Expect<ViShader>    ViShaderManager::get(uint64_t i) const
    {
        {
            mutex_t::scoped_lock _lock(m_mutex, false);
            auto itr = m_shaders.find(i);
            if(itr != m_shaders.end())
                return itr->second;
        }

        return unexpected<"Unable to find the specified shader">();
    }
    
    bool                ViShaderManager::has(uint64_t i) const
    {
        mutex_t::scoped_lock _lock(m_mutex, false);
        return m_shaders.contains(i);
    }
}
