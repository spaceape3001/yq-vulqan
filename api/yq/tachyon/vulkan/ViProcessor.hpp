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
    
        ViProcessor(VizBase&, ViQueueType);
        virtual ~ViProcessor();
        
        ViDevice&               device() { return m_device; }
        const ViDevice&         device() const { return m_device; }
    
        // executes only THIS processor on current thread!
        void                    execute(FNProcessorTask&&);
        
        // executes *ALL* workers against the given task
        void                    execute(FNWorkerTask&&);

        bool                    good() const { return m_good; }
        //VkSemaphore             semaphore_finished() const { return m_semaphore.finished; }
        
        VkCommandBuffer         vk_command_buffer() const { return m_cmdBuffer.command_buffer(); }
        VkCommandPool           vk_command_pool() const { return m_cmdPool.command_pool(); }
        
        void                    reset();
        
        bool                    add_worker();
        
        //! Expands the worker count until N is here or add worker fails
        bool                    expand_workforce_to(uint32_t);
        
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
        
        uint32_t processor_id() const { return m_id; }
        
    protected:
        
        using worker_create_t   = std::function<ViWorkerUPtr()>;
        
        worker_create_t         m_factory;

        VizBase&                m_viz;
        ViDevice&               m_device;
    private:
        ViCommandPool           m_cmdPool;
        ViCommandBuffer         m_cmdBuffer;
        ViWorkerUPtrVector      m_workers;
        uint32_t                m_id    = 0;
        
        friend class VizBase;
        
        //struct {
            //VkSemaphore         finished = nullptr;
        //} m_semaphore;
        ViWorker::Param         m_workerParam;
        bool                    m_good  = false;
        
        void    exec_multi(FNWorkerTask&&);
    };
}

