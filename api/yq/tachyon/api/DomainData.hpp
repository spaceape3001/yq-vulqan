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
    class DomainSnap : public TachyonSnap {
        YQ_OBJECT_DECLARE(DomainSnap, TachyonSnap)
    public:
        //  parent domain
        //std::vector<TypedID>    cameras;
        //std::vector<TypedID>    lights;
        //std::vector<TypedID>    rendereds;
        std::vector<ModelID>    models;
        std::vector<DomainID>   subdomains; // Tiles, etc
        std::vector<TypedID>    physics;
        
        //  screen mapping here?  (or domain scene)
        //  function handlers (mapping, etc)
        
        DomainSnap();
        virtual ~DomainSnap();
        static void init_meta();
    };
    
    class DomainData : public TachyonData {
        YQ_OBJECT_DECLARE(DomainData, DomainSnap)
    public:
        DomainData();
        virtual ~DomainData();
        static void init_meta();
    };
}
