////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/gfx/Pipeline.hpp>
#include <basic/DelayInit.hpp>

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

        void    Pipeline::set_name(std::string_view sv)
        {
            m_name  = std::string(sv);
        }
    }
}

