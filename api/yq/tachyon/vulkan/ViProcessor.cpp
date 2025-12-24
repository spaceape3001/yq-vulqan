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
    ViProcessor::ViProcessor(VizBase& vb) : ViProcessor(vb, Param())
    {
    }
    
    ViProcessor::ViProcessor(VizBase&vb, const Param& p) : m_viz(vb), m_device(vb.device(REF)), m_workerParam(p)
    {
        m_good  = true;
        m_workers.reserve(p.workers);
        while(m_workers.size() < p.workers)
            m_good = new_worker().good() && m_good;
        VqSemaphoreCreateInfo   sci;
        vkCreateSemaphore(m_device,  &sci, nullptr, &m_semaphore.finished);
    }
    
    ViProcessor::~ViProcessor()
    {
        if(m_semaphore.finished){
            vkDestroySemaphore(m_device, m_semaphore.finished, nullptr);
        }
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

    ViWorker& ViProcessor::new_worker()
    {
        ViWorker::Param p   = m_workerParam;
        p.worker_id         = (uint32_t) m_workers.size();
        m_workers.push_back(std::make_unique<ViWorker>(*this, p));
        return *m_workers.back();
    }

    void ViProcessor::reset()
    {
        for(auto&& w : m_workers){
            if(w)
                w->reset();
        }
    }
}

