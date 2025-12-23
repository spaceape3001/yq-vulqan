////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/color/RGBA.hpp>
#include <yq/core/Tristate.hpp>
#include <yq/tachyon/keywords.hpp>
#include <yq/tachyon/pipeline/DataFormat.hpp>

#include <variant>

struct VkPhysicalDevice_T;

namespace yq::tachyon {
    /*! \brief Base to viewer & headless config
    */
    struct GEnvCreateInfo {
        using queue_spec        = std::variant<std::monostate, required_k, optional_k, device_k>;
    
        //VkPhysicalDevice_T*         device   = nullptr;
    
            //!  This is the background color
        RGBA4F                      clear   = { 0., 0., 0., 1. };

            //!  Compute queue
        queue_spec                  compute;


        using depth_spec  = std::variant<std::monostate, enable_k, DataFormat>;

            //!  Depth buffer
        depth_spec                  depth_buffer;

            //!  Set to get descriptors allocated (pending...might ignore)
        uint32_t                    descriptors     = 0;
        

            //!  Set if we want multiview capability (think STEREO/VR)
        bool                        multiview       = false;

        //queue_spec                  optical_flow;

            //!  Transfer queue
        queue_spec                  transfer;

            //!  Video decoding queue
        queue_spec                  video_decode;

            //!  Video encoding queue
        queue_spec                  video_encode;
    };
    
}
