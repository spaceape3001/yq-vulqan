////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq-vulqan/typedef/image.hpp>
#include <tbb/spin_rw_mutex.h>
#include <unordered_map>

namespace yq::tachyon {
    struct ViVisualizer;

    class ViImageManager {
    public:
        
        ViImageManager(ViVisualizer&);
        ~ViImageManager();
    
        void            cleanup();
        ViImageCPtr     create(const Image&);
        void            erase(const Image&);
        void            erase(uint64_t);
        ViImageCPtr     get(uint64_t) const;
        bool            has(uint64_t) const;

    private:
    
        using map_t     = std::unordered_map<uint64_t, ViImageCPtr>;
        using mutex_t   = tbb::spin_rw_mutex;
        
        ViImageManager(const ViImageManager&) = delete;
        ViImageManager(ViImageManager&&) = delete;
        ViImageManager& operator=(const ViImageManager&) = delete;
        ViImageManager& operator=(ViImageManager&&) = delete;
        
        map_t               m_images;
        mutable mutex_t     m_mutex;
        ViVisualizer&       m_viz;
    };
}
