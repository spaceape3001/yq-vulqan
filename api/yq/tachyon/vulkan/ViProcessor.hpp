////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <functional>
#include <yq/tachyon/vulkan/ViWorker.hpp>
#include <yq/tachyon/typedef/vi_processor.hpp>
#include <yq/tachyon/typedef/vi_worker.hpp>
#include <vulkan/vulkan_core.h>

namespace yq::tachyon {

    class VizBase;
    class ViDevice;

    //! This is a frame (or similar)
    class ViProcessor {
    public:
    
        struct Param : public ViWorker::Param {
            size_t  workers     = 1;
        };
    
        ViProcessor(VizBase&);
        ViProcessor(VizBase&, const Param&);
        ~ViProcessor();
        
        ViDevice&               device() { return m_device; }
        const ViDevice&         device() const { return m_device; }
    
        // executes *ALL* workers against the given task
        void                    execute(FNProcessorTask&&);    // TODO
        bool                    good() const { return m_good; }
        VkSemaphore             semaphore_finished() const { return m_semaphore.finished; }
        
        void                    reset();
        
        ViWorker&               new_worker();
        
        size_t                  count() const { return m_workers.size(); }
        bool                    empty() const { return m_workers.empty(); }

        VizBase&                viz() { return m_viz; }
        const VizBase&          viz() const { return m_viz; }

            // allows iteration
        
        auto begin() { return m_workers.begin(); }
        auto end() { return m_workers.end(); }

        auto begin() const { return m_workers.cbegin(); }
        auto end() const { return m_workers.cend(); }

        auto cbegin() const { return m_workers.cbegin(); }
        auto cend() const { return m_workers.cend(); }

        auto rbegin() { return m_workers.rbegin(); }
        auto rend() { return m_workers.rend(); }

        auto rbegin() const { return m_workers.crbegin(); }
        auto rend() const { return m_workers.crend(); }
    
        auto crbegin() const { return m_workers.crbegin(); }
        auto crend() const { return m_workers.crend(); }

    private:
        VizBase&                m_viz;
        ViDevice&               m_device;
        ViWorkerUPtrVector      m_workers;
        
        struct {
            VkSemaphore         finished = nullptr;
        } m_semaphore;
        ViWorker::Param         m_workerParam;
        bool                    m_good  = false;
        
        void    exec_multi(FNProcessorTask&&);
    };
}

