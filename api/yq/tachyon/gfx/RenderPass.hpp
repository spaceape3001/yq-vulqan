////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/typedef/render_pass.hpp>

#include <yq/core/Ref.hpp>
#include <yq/core/UniqueID.hpp>
#include <yq/tachyon/gfx/RenderPassInfo.hpp>

namespace yq::tachyon {
    class RenderPass : public RefCount, public UniqueID {
    public:
    
        /*
            This is not fully thought out... sidelining the 
            non-vulkan side of render pass until necessary.
        */
    
        const RenderPassInfo    info;
        
        RenderPass(const RenderPassInfo&);
        RenderPass(RenderPassInfo&&);
        ~RenderPass();
        
        static RenderPassCPtr   simple(DataFormat);
        static RenderPassInfo   simple_info(DataFormat);
        
    private:
        RenderPass(const RenderPass&) = delete;
        RenderPass(RenderPass&&) = delete;
        RenderPass& operator=(const RenderPass&) = delete;
        RenderPass& operator=(RenderPass&&) = delete;
    };
}

