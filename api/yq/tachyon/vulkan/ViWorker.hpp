////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "ViCommandPool.hpp"

namespace yq::tachyon {
    class VizBase;
    class ViDevice;
    class ViProcessor;

    //! This is a worker bee, one thread/one frame
    class ViWorker {
    public:
    
        struct Param {
            VqCommandPoolCreateFlags    command_pool_flags;
            ViQueueType                 queue_type  = ViQueueType::Graphic;
            uint32_t                    number      = 0;
        };
    
        ViWorker(ViProcessor&);
        ViWorker(ViProcessor&, const Param&);
        ~ViWorker();
        
        VkCommandPool       command_pool() const;
        uint32_t            number() const { return m_number; }
        void                reset();
        bool                good() const { return m_good; }
    
    private:
        ViProcessor&        m_proc;
        VizBase&            m_viz;
        ViDevice&           m_dev;
        ViCommandPool       m_cmdPool;
        const uint32_t      m_number;
        bool                m_good  = false;
    };
}
