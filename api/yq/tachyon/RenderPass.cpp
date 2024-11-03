////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "RenderPass.hpp"
#include <yq/tachyon/pass/RenderPassInfo.hpp>
#include <tbb/spin_rw_mutex.h>
#include <map>

namespace yq::tachyon {
    RenderPassCPtr   RenderPass::simple(DataFormat fmt)
    {
        static tbb::spin_rw_mutex                   s_mutex;
        static std::map<DataFormat, RenderPassCPtr> s_data;
        
        {
            tbb::spin_rw_mutex::scoped_lock _lock(s_mutex, false);
            auto i = s_data.find(fmt);
            if(i != s_data.end())
                return i->second;
        }
        
        RenderPassCPtr p, ret;
        p   = new RenderPass(simple_info(fmt));
        
        {
            tbb::spin_rw_mutex::scoped_lock _lock(s_mutex, false);
            auto [j,first]  = s_data.insert({fmt, p});
            if(first)
                return p;
            std::swap(p, ret);
            ret = j->second;
        }
        
        return ret;
    }

    RenderPassInfo   RenderPass::simple_info(DataFormat fmt)
    {
        AttachmentDescription   ca;
        ca.format       = fmt;

        SubpassInfo spi;
        spi.colorAttachments.push_back(AttachmentReference());
        
        RenderPassInfo          ret;
        ret.attachments.push_back(ca);
        ret.subpasses.push_back(spi);
        return ret;
    }

    RenderPass::RenderPass(const RenderPassInfo& _info) : info(_info)
    {
    }
    
    RenderPass::RenderPass(RenderPassInfo&& _info) : info(std::move(_info))
    {
    }
    
    RenderPass::~RenderPass()
    {
    }
}
