////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <basic/Enum.hpp>
#include <basic/Flag.hpp>
#include <basic/meta/InfoBinder.hpp>

namespace yq {
    namespace tachyon {
        YQ_ENUM(BufferUsage, , 
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
        )
        using BufferUsageFlags  = Flag<BufferUsage>;
    }
}
YQ_TYPE_DECLARE(yq::tachyon::BufferUsage)
YQ_TYPE_DECLARE(yq::tachyon::BufferUsageFlags)
