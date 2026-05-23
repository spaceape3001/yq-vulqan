////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/core/Flags.hpp>
#include <yq/meta/MetaBinder.hpp>

namespace yq::tachyon {
    /*! \brief Buffer usage flag
    
        These are translated over to vulkan, meant to be an easier 
        way than dealing with the overly LONG vulkan codes.
    */
    enum class BufferUsage : uint8_t {
        TransferSource                          = 0,
        TransferDestination                     = 1,
        UniformTexel                            = 2,
        StorageTexel                            = 3,
        Uniform                                 = 4,
        Storage                                 = 5,
        Index                                   = 6,
        Vertex                                  = 7,
        Indirect                                = 8,
        ConditionalRendering                    = 9,
        ShaderBindingTable                      = 10,
        TranformFeedback                        = 11,
        TransormFeedbackCounter                 = 12,
        VideoDecodeSource                       = 13,
        VideoDecodeDestination                  = 14,
        VideoEncodeDestination                  = 15,
        VideoEchodeSource                       = 16,
        ShaderDeviceAddress                     = 17,
        AccelerationStructureBuildInputReadOnly = 19,
        AccelerationStructureStorage            = 20,
        SamplerDescriptor                       = 21,
        ResourceDescriptor                      = 22,
        MicromapBuildInputReadOnly              = 23,
        MicromapStorage                         = 24,
        DescriptorsDescriptor                   = 26,
        RayTracing = ShaderBindingTable
    };
    using BufferUsageFlags  = Flags<BufferUsage, uint32_t>;
}
YQ_TYPE_DECLARE(yq::tachyon::BufferUsage)
YQ_TYPE_DECLARE(yq::tachyon::BufferUsageFlags)
