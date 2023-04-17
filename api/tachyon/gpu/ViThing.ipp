////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/gpu/ViThing.hpp>
#include <tachyon/gpu/ViPipeline.hpp>
#include <tachyon/gpu/Visualizer.hpp>

namespace yq::tachyon {

    ViThing::ViThing(Visualizer& viz, const ViPipeline& vp, const Rendered* object)
    {
        size_t i;

        auto& vc    = vp.cfg.vbos;
        if(!vc.empty()){
            vbos.resize(vc.size());
            for(i=0;i<vbos.size();++i){
                vbos[i] = vp.vbos[i];
                vbos[i].update(viz, vc[i], object);
            }
        }
            
        auto& ic    = vp.cfg.ibos;
        if(!ic.empty()){
            ibos.resize(ic.size());
            for(i=0;i<ibos.size();++i){
                ibos[i] = vp.ibos[i];
                ibos[i].update(viz, ic[i], object);
            }
        }
    }
    
    void    ViThing::update(Visualizer& viz, const ViPipeline& vp, const Rendered* object)
    {
        size_t i;
        auto& vc    = vp.cfg.vbos;
        for(i=0;i<vbos.size();++i)
            vbos[i].update(viz, vc[i], object);
            
        auto& ic    = vp.cfg.ibos;
        for(i=0;i<ibos.size();++i)
            ibos[i].update(viz, ic[i], object);
    }
}
