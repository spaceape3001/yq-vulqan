////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/enum/RenderMode.hpp>
#include <yq/tachyon/typedef/vi_rendered.hpp>
#include <yq/tachyon/typedef/vi_rendered_manager.hpp>
#include <yq/tachyon/vulkan/ViProcessor.hpp>
#include <yq/tachyon/vulkan/ViManager.hpp>
#include <yq/tachyon/vulkan/ViRendered.hpp>

namespace yq::tachyon {
    class VizBase;
    struct RenderedSnap;

    // *MIGHT* need to make these parallel the semaphores (in one more and use the semaphore index)

    class ViGraphicsProcessor : public ViProcessor {
    public:
    
        ViGraphicsProcessor(VizBase&);
        ~ViGraphicsProcessor();
    
        ViRenderedPtr      rendered(const RenderedSnap*, RenderMode rm=RenderMode::Simple);

    private:
        ViRenderedManager       m_rendereds;
    };
}
