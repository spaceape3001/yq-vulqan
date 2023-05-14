////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/viz/Buffer.hpp>
#include <tachyon/gpu/ViBO.hpp>
#include <tachyon/gpu/Visualizer.hpp>
#include <tachyon/viz/PipelineConfig.hpp>

namespace yq::tachyon {
    void    ViBO::update(Visualizer&viz, const ABOConfig&cfg, const void* p)
    {
        do {
            if(!cfg.fetch)
                return ;
            if(p ? (cfg.activity == DataActivity::COMMON) : (cfg.activity != DataActivity::COMMON))
                return;
            if(!buffer)                                 // LOAD
                break;
            if(cfg.activity != DataActivity::DYNAMIC)   // LOAD
                break;
            if(!cfg.revision)
                return ;
            
            uint64_t    n   = cfg.revision(p);
            if(n == rev)
                return ;
            rev    = n;
        } while(false);
        
        BufferCPtr      c   = cfg.fetch(p);
        if(!c){     //  shouldn't really happen....
            yWarning() << "EMPTY BUFFER DETECTED!";
            return ;
        }
        
        const ViBuffer& vb    = viz.create(*c);
        if(vb.buffer){
            buffer  = vb.buffer;
            count   = c->memory.count();
        }
    }
}
