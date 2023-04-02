////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/gpu/ViQueues.hpp>

namespace yq {
    namespace tachyon {
        void    ViQueues::set(VkDevice dev, uint32_t cnt)
        {
            queues.clear();
            queues.resize(cnt, nullptr);
            for(uint32_t i=0;i<cnt;++i)
                vkGetDeviceQueue(dev, family, i, &queues[i]);
        }
        
        ViQueues::~ViQueues()
        {
            queues.clear();
        }

        VkQueue ViQueues::operator[](uint32_t i) const
        {
            if(i<queues.size()) [[likely]]
                return queues[i];
            return nullptr;
        }
    }
}
