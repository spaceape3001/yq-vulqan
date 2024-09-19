////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Pipeline.hpp"
#include <yq-vulqan/shader/Shader.hpp>

namespace yq::tachyon {

    Pipeline::Pipeline(const SharedPipelineConfig& cfg) : m_config(cfg)
    {
    }
    
    Pipeline::Pipeline(SharedPipelineConfig&&cfg) : m_config(std::move(cfg))
    {
    }
    
    Pipeline::~Pipeline()
    {
    }

    Pipeline::role_t  Pipeline::role() const 
    { 
        if(m_config)
            return m_config -> role;
        return 0;
    }
}
