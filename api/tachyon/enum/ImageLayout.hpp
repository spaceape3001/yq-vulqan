////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <basic/Enum.hpp>
#include <basic/meta/InfoBinder.hpp>

namespace yq {
    namespace tachyon {
        YQ_ENUM(ImageLayout, ,
            Undefined = 0,
            General = 1,
            ColorAttachment = 2,
            DepthStencilAttachment = 3,
            DepthStencilReadOnly = 4,
            ShaderReadOnly = 5,
            TransferSrc = 6,
            TransferDst = 7,
            Preinitialized = 8,
            DepthReadOnlyStencilAttachment = 1000117000,
            DepthAttachmentStencilReadOnly = 1000117001,
            DepthAttachment = 1000241000,
            DepthReadOnly = 1000241001,
            StencileAttachment = 1000241002,
            StencilReadOnly = 1000241003,
            ReadOnly = 1000314000,
            Attachment = 1000314001,
            PresentSrc = 1000001002,
            VideoDecodeDst = 1000024000,
            VideoDecodeSrc = 1000024001,
            VideoDecodeDPB = 1000024002,
            SharedPresent = 1000111000,
            FragmentDensityMap = 1000218000,
            FragmentShadingRateAttachment = 1000164003,
            VideoEncodeDst = 1000299000,
            VideoEncodeSrc = 1000299001,
            VideoEncodeDPB = 1000299002,
            VideoReadOnlyStencilAttachment = DepthReadOnlyStencilAttachment,
            DepthAttachStencilReadOnly = DepthAttachmentStencilReadOnly,
            ShadingRate = FragmentShadingRateAttachment,
        )
    }
}
YQ_TYPE_DECLARE(yq::tachyon::ImageLayout)
