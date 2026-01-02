////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/color/RGBA.hpp>
#include <yq/core/Ref.hpp>
#include <yq/tachyon/api/ID.hpp>
#include <yq/tachyon/typedef/clock.hpp>
#include <yq/tachyon/typedef/frame.hpp>
#include <yq/tachyon/typedef/tachyon.hpp>
#include <yq/tachyon/typedef/thread.hpp>
#include <yq/tachyon/typedef/vi_debug_trace.hpp>
#include <chrono>
#include <vulkan/vulkan_core.h>

namespace yq::tachyon {
    struct ViDebugTrace : public RefCount {
        struct trace_t {
            std::string     file;
            uint32_t        line    = 0;
        };
        
        struct label_t {
            std::string     name;
            RGBA4F          color;
            
            label_t(){}
            label_t(const VkDebugUtilsLabelEXT&);
        };
        
        struct object_t {
            VkObjectType        type    = VK_OBJECT_TYPE_UNKNOWN;
            uint64_t            handle  = 0;
            std::string         name;
            
            object_t(){}
            object_t(const VkDebugUtilsObjectNameInfoEXT&);
        };

        std::vector<label_t>                        cmdbufs;
        VkDebugUtilsMessengerCallbackDataFlagsEXT   flags{};
        FrameCPtr                                   frame;
        const uint64_t                              id;
        std::string                                 message;
        std::string                                 msgIdName;
        uint32_t                                    msgIdNumber = 0;
        std::vector<object_t>                       objects;
        std::vector<label_t>                        queues;
        VkDebugUtilsMessageSeverityFlagBitsEXT      severity;
        TachyonID                                   tachyon;
        ThreadID                                    thread{};
        const time_point_t                          time;
        std::vector<trace_t>                        trace;
        VkDebugUtilsMessageTypeFlagsEXT             types{};
        
        ViDebugTrace(const VkDebugUtilsMessengerCallbackDataEXT&);
        ~ViDebugTrace();
    };
}
