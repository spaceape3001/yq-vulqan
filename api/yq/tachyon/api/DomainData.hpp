////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/TachyonData.hpp>
#include <yq/tachyon/api/TypedID.hpp>
#include <yq/tachyon/typedef/domain.hpp>
#include <yq/tachyon/typedef/model.hpp>
#include <yq/tachyon/typedef/physics.hpp>

namespace yq::tachyon {
    struct DomainSnap : public TachyonSnap {
    
        //  parent domain
        //std::vector<TypedID>    cameras;
        //std::vector<TypedID>    lights;
        //std::vector<TypedID>    rendereds;
        std::vector<TypedID>    physics;
        std::vector<ModelID>    models;
        std::vector<DomainID>   subdomains; // Tiles, etc
        
        //  screen mapping here?  (or domain scene)
        //  function handlers (mapping, etc)
    };
    
    struct DomainData : public TachyonData {
    };
}
