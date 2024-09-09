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
    class ViVisualizer;

    class ViShaderManager {
    public:
    
        ViShaderManager(ViVisualizer&);
        ~ViShaderManager();
        
        ViShaderCPtr    create(const Shader&);
        ViShaderCPtr    get(uint64_t) const;
        bool            has(uint64_t) const;
        
        void            cleanup();
        
    private:
        using map_t     = std::unordered_map<uint64_t, ViShaderCPtr>;
        using mutex_t   = tbb::spin_rw_mutex;
        
        ViShaderManager(const ViShaderManager&) = delete;
        ViShaderManager(ViShaderManager&&) = delete;
        ViShaderManager& operator=(const ViShaderManager&) = delete;
        ViShaderManager& operator=(ViShaderManager&&) = delete;
        
        ViVisualizer&       m_viz;
        map_t               m_shaders;
        mutable mutex_t     m_mutex;
    };
}
