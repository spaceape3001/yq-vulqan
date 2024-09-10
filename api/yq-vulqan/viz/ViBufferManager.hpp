////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq-vulqan/typedef/buffer.hpp>
#include <tbb/spin_rw_mutex.h>
#include <unordered_map>

namespace yq::tachyon {
    struct ViVisualizer;
    
    class ViBufferManager {
    public:
        
        ViBufferManager(ViVisualizer&);
        ~ViBufferManager();
    
        void            cleanup();
        ViBufferCPtr    create(const Buffer&);
        void            erase(const Buffer&);
        void            erase(uint64_t);
        ViBufferCPtr    get(uint64_t) const;
        bool            has(uint64_t) const;

    private:
    
        using map_t     = std::unordered_map<uint64_t, ViBufferCPtr>;
        using mutex_t   = tbb::spin_rw_mutex;
        
        ViBufferManager(const ViBufferManager&) = delete;
        ViBufferManager(ViBufferManager&&) = delete;
        ViBufferManager& operator=(const ViBufferManager&) = delete;
        ViBufferManager& operator=(ViBufferManager&&) = delete;
        
        map_t               m_buffers;
        mutable mutex_t     m_mutex;
        ViVisualizer&       m_viz;
    };
}
