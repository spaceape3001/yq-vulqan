////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "ViGraphicsProcessor.hpp"
#include <yq/tachyon/api/RenderedData.hpp>
#include <yq/tachyon/pipeline/Pipeline.hpp>

namespace yq::tachyon {
    ViGraphicsProcessor::ViGraphicsProcessor(VizBase& vb) : 
        ViProcessor(vb, ViQueueType::Graphic), m_rendereds(vb, {})
    {
    }
    
    ViGraphicsProcessor::~ViGraphicsProcessor()
    {
    }
    
    ViRenderedPtr      ViGraphicsProcessor::rendered(const RenderedSnap* obj, RenderMode rm)
    {
        const Pipeline*p    = obj->pipeline(rm);
        if(!p)
            return {};

        ViRenderedPtr ret =  m_rendereds.create(obj, p);
        if(!ret)
            return {};
        if(ret->pipeline_id() != p->id())
            ret     = m_rendereds.recreate(obj, p);
        return ret;
    }

}


