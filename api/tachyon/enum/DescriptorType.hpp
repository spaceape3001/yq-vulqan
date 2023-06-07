////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <basic/Enum.hpp>
#include <meta/InfoBinder.hpp>

namespace yq::tachyon {
    /*! \brief Type of descriptor
    
        Descriptors are needed to get data to the GPU for some of the pipeline.
        This type corresponds to vulkan codes, but for our info structures
    */
    YQ_ENUM(DescriptorType, , 
        Sampler = 0,
        CombinedImageSampler = 1,
        SampledImage = 2,
        StorageImage = 3,
        UniformTexelBuffer = 4,
        StorageTextBuffer = 5,
        UniformBuffer = 6,
        StorageBuffer = 7,
        UniformBufferDynamic = 8,
        StorageBufferDynamic = 9,
        InputAttachment = 10,
        InlineUniformBlock = 1000138000,
        AccelerationStructureKHR = 1000150000,
        AccelerationStructureNV = 1000165000,
        MutableValve = 1000351000,
        InlineUniformBlockEXT = InlineUniformBlock,
    )
}

YQ_TYPE_DECLARE(yq::tachyon::DescriptorType)
