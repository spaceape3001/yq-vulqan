////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "ViProcessor.hpp"
#include <yq/tachyon/api/Frame.hpp>
#include <yq/tachyon/vulkan/ViDevice.hpp>
#include <yq/tachyon/vulkan/VizBase.hpp>
#include <yq/tachyon/vulkan/VqStructs.hpp>
#include <tbb/parallel_for.h>

namespace yq::tachyon {
    ViProcessor::ViProcessor(VizBase&vb, ViQueueType qt) : m_viz(vb), m_device(vb.device())
    {
        m_good  = true;
        m_factory = [qt,this]() -> ViWorkerUPtr {
            return std::make_unique<ViWorker>(*this, ViWorker::Param{.queue_type=qt});
        };
    }
    
    ViProcessor::~ViProcessor()
    {
        m_workers.clear();
    }
    
    void    ViProcessor::exec_multi(FNProcessorTask&& fn)
    {
        using range_t    = tbb::blocked_range<size_t>;
        
        const Frame* frame  = Frame::s_current;
            
        auto multi = [&,this](const range_t& r){
            for(size_t i=r.begin(); i!=r.end(); ++i){
                auto& w = m_workers[i];
                if(!w)
                    return;
                
                const Frame*    old = Frame::s_current;
                Frame::s_current    = frame;
                fn(*w);
                Frame::s_current    = old;
            }
        };
            
        tbb::parallel_for(range_t(0, m_workers.size()), multi, tbb::simple_partitioner());
    }

    void      ViProcessor::execute(FNProcessorTask&& fn)
    {
        if(!m_good)
            return;
        if(!fn)
            return ;
            
        switch(m_workers.size()){
        case 0:
            break;
        case 1:
            fn(*m_workers[0]);
            break;
        default:
            exec_multi(std::move(fn));
            break;
        }
        
    }

    bool ViProcessor::add_worker()
    {
        if(!m_factory)
            return false;
        ViWorkerUPtr    wp  = m_factory();
        if(!wp)
            return false;
        wp -> m_id  = (uint32_t) m_workers.size();
        m_workers.push_back(std::move(wp));
        return true;
    }

    bool ViProcessor::expand_workforce_to(uint32_t n)
    {
        m_workers.reserve(n);
        while(m_workers.size() < n){
            if(!add_worker())
                return false;
        }
        return true;
    }

    void ViProcessor::reset()
    {
        for(auto&& w : m_workers){
            if(w)
                w->reset();
        }
    }
}

