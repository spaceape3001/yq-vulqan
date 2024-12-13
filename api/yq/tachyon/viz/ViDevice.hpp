////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

namespace yq::tachyon {
    /*

        On observation that *NOTHING* in the vkCreateDevice() call relies on 
        surfaces (ie, the windows), the visualizer is going to be split.  
        
        ViDevice will be the vulkan logical device, which is tied to a GPU, 
        likely owned by the VulqanManager.
        
        Visualizer will continue to bind the surface to rendering.
    
    */
    
    class ViDevice {
        /* TBD */
    };
}

