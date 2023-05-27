////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/gpu/ViThing.hpp>
#include <tachyon/gpu/ViPipeline.hpp>
#include <tachyon/gpu/Visualizer.hpp>
#include <tachyon/gpu/VqStructs.hpp>

namespace yq::tachyon {

    ViThing::ViThing(Visualizer& viz, const ViPipeline& vp, const Rendered* object)
    {
        size_t i;
        size_t  ds = 0;

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
        
        auto& uc    = vp.cfg.ubos;
        if(!uc.empty()){
            ubos.resize(uc.size());
            for(i=0;i<ubos.size();++i){
                ubos[i] = vp.ubos[i];
                ubos[i].update(viz, uc[i], object);
            }
            
            ds += uc.size();
        }
        
        if(ds){
            std::vector<VkDescriptorSetLayout>      layouts(MAX_FRAMES_IN_FLIGHT, vp.descriptors);
            VqDescriptorSetAllocateInfo allocInfo;
            allocInfo.descriptorPool    = viz.descriptor_pool();
            allocInfo.descriptorSetCount    = MAX_FRAMES_IN_FLIGHT * ds;
            allocInfo.pSetLayouts       = layouts.data();
            descriptors.resize(MAX_FRAMES_IN_FLIGHT*ds);
            if(vkAllocateDescriptorSets(viz.device(), &allocInfo, descriptors.data()) != VK_SUCCESS){
                yInfo() << "Unable to allocate descriptor sets!";
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
