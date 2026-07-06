////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SimpleDomain.hpp"
#include <yq/tachyon/api/DomainMetaWriter.hpp>

YQ_TACHYON_IMPLEMENT(yq::tachyon::SimpleDomain)

namespace yq::tachyon {
    SimpleDomain::SimpleDomain() : SimpleDomain(Param())
    {
    }
    
    SimpleDomain::SimpleDomain(const Param&p) : Domain(p)
    {
    }
    
    

    SimpleDomain::~SimpleDomain()
    {
    }
    /*
    void    SimpleDomain::snap(DomainSnap& sn) const
    {
        Domain::snap(sn);
        for(const TypedID& t : sn.children){
            if(t(Type::Camera))
                sn.cameras.push_back(t);
            if(t(Type::Light))
                sn.lights.push_back(t);
            if(t(Type::Rendered))
                sn.rendereds.push_back(t);
        }
    }
    */
    
    void SimpleDomain::init_meta()
    {   
        auto w = writer<SimpleDomain>();
        w.description("Simple Domain");
    }
}
