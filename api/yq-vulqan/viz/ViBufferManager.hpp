////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq-vulqan/typedef/buffer.hpp>
#include <yq-toolbox/basic/Expect.hpp>
#include <tbb/spin_rw_mutex.h>
#include <unordered_map>

namespace yq::tachyon {
    class ViBuffer;
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
        
        map_t               m_buffers;
        mutable mutex_t     m_mutex;
        ViVisualizer&       m_viz;
    };
}
