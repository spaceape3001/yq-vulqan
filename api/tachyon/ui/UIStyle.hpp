////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once
#include <yq/shape/Size2.hpp>

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
            
            UIDim   icons       = { 3., 10., 256. };
        } toolbar;
        
        struct {
            Size2F  def_size    = { 24, 24 };
        } image;
        
        struct {
            UIDim   min_size    = { 2., 20., -1. };
        } window;
        
        struct {
            Size2F  def_size    = { 24, 24 };
            
            std::string_view    unknown     = "openicon/icons/png/48x48/places/nuvola-style/file-important.png";
        } icon;
        
        struct {
            UIDim   keycol  = { 10, 50., -1 };
            
            struct {
                float   min    = 100.;
            } valcol;
        } table;
        
        struct {
            UIDim   indent                  = { 2., 5, 50. };
        } tree;
    };
}
