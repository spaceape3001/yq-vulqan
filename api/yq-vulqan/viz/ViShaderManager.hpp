////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq-vulqan/typedef/shader.hpp>
#include <yq-toolbox/basic/Expect.hpp>

#include <tbb/spin_rw_mutex.h>
#include <unordered_map>
#include <vulkan/vulkan_core.h>

namespace yq::tachyon {
    struct ViShader;
    
    class ViShaderManager {
    public:
    
        ViShaderManager(VkDevice);
        ~ViShaderManager();
        
        Expect<ViShader>    create(const Shader&);
        Expect<ViShader>    get(uint64_t) const;
        bool                has(uint64_t) const;
        
        void                cleanup();
        
    private:
        using map_t     = std::unordered_map<uint64_t, ViShader>;
        using mutex_t   = tbb::spin_rw_mutex;
        
        map_t               m_shaders;
        mutable mutex_t     m_mutex;
        VkDevice const      m_device;
    };
}
