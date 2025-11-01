////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/core/Required.hpp>
#include <yq/macro/debugrel.hpp>
#include <yq/typedef/filesystem_path.hpp>
#include <yq/tachyon/keywords.hpp>
#include <optional>
#include <vector>
#include <yq/tachyon/typedef/queue_spec.hpp>

namespace yq::tachyon {

    struct NameRequired {
        const char*     name    = nullptr;
        Required        req     = Required::NO;
    };

    struct VulqanCreateInfo {
            //  TODO... To share a queue, state the other queue to leverage, if possible

            // API version we'll require (defaults to lates)
        uint32_t                    api             = 0;

            //! Enables the best practices feature (in validation)
        bool                        best_practices  = true;

            //! Set to enable compute & queue capability
        QueueSpec                   compute;

            //! Amount to allocate in "chunks" on the GPU (Zero implies default...currently 256MiB)
        size_t                      chunk_size  = 0;

            //! Set to get descriptors allocated
        uint32_t                    descriptors = 0;

            //! Enable/disable flag for all of vulkan
        bool                        enable          = true;
        
        //! Desired extensions (taking optional & yes)
        std::vector<NameRequired>   extensions;
        
            //!  Set to enable fill of non-solid features
        bool                        fill_non_solid  = true;

            //!  Set to enable graphics & queue capability (implied unless headless)
        QueueSpec                   graphics;

            //!  True to allow headless (w/o this, graphics queue is required)
        bool                        headless        = false;
            
        //! Desired layers (taking optional & yes)
        std::vector<NameRequired>   layers;

            //!  Set if we want multiview capability (think STEREO/VR)
        bool                        multiview   = false;

            //!  Used in computer vision algorithms
        QueueSpec                   optical_flow;

            //!  Set to alter present queue capability
        // QueueSpec                   present;   (Not going to be enabled, inferred from enable/headless)

            //!  Set to enable transfer (DMA) queue capability
        QueueSpec                   transfer;

        //! Add KHRONOS validation layer
        Required                    validation      = YQ_DBGREL( Required::YES, Required::NO);

            //!  Set to enable video-decode queue capability
        QueueSpec                   video_decode;
        
            //!  Set to enable video-encode queue capability
        QueueSpec                   video_encode;
        

        

    };
}
