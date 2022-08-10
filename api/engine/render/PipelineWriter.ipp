////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "PipelineWriter.hpp"

namespace yq {
    namespace engine {

        Pipeline::Writer::Writer(Pipeline* p) : Meta::Writer(p), PipelineBuilder(&p->m_config), m_pipeline(p)
        {
        }
        
        Pipeline::Writer::Writer(Pipeline&p) : Writer(&p)
        {
        }
        
        Pipeline::Writer::~Writer() = default;
    }
}
