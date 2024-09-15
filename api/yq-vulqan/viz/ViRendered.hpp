////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once


#include <yq-toolbox/basic/Ref.hpp>
#include <yq-toolbox/container/BasicBuffer.hpp>
#include <yq-vulqan/viz/ViData.hpp>
#include <yq-vulqan/typedef/rendered.hpp>

namespace yq::tachyon {
    class ViRendered : public RefCount, public ViData {
    public:
    
    private:
        RenderedCPtr        m_rendered;
        ViPipelineCPtr      m_pipeline;
        PushBuffer          m_push;
    };
}
