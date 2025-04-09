////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

namespace yq::tachyon {
    struct UIDim {
        float   scale;  // scale of ImGui::GetFrameHeight() -- negative disables
        float   min;    // min size -- negative disables
        float   max;    // max size -- negative disables
        
        //! Gets ImGui::GetFrameHeight()*scale, clamped [min...max]
        float operator()() const;
        
        //! Clamps input to [min...max]
        float operator()(float) const;
    };

    struct UIStyle {
        //  exact settings TBD....
        struct {
            //! How thick the toolbars should be
            UIDim   thickness   = {  1.,  10., -1. };
            
            //! How long the toolbars should be
            UIDim   length      = { -1., 100., -1. };
            
            //! Inset from the edge (good for transparent ones) 
            UIDim   inset       = { 0., -1., -1. };
            
            //! Extra spacing between stacked toolbars (ie... 0...1...2)
            UIDim   padding     = { 0., -1., -1. };
        } toolbar;
    };
}
