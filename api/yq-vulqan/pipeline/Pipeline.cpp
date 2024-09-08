////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Pipeline.hpp"
#include <yq-vulqan/shader/Shader.hpp>

namespace yq::tachyon {

    Pipeline::Pipeline(const PipelineConfig& cfg) : m_config(cfg)
    {
    }
    
    Pipeline::Pipeline(PipelineConfig&&cfg) : m_config(std::move(cfg))
    {
    }
    
    Pipeline::~Pipeline()
    {
    }
}
