////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/gfx/Pipeline.hpp>

namespace yq {
    namespace tachyon {

        Pipeline::Pipeline(const PipelineConfig& cfg) : m_config(cfg)
        {
        }
        
        Pipeline::Pipeline(PipelineConfig&&cfg) : m_config(std::move(cfg))
        {
        }
        
        Pipeline::Pipeline()
        {
        }
        
        Pipeline::~Pipeline()
        {
        }
    }
}

