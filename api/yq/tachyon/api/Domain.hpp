////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/color/RGB.hpp>
#include <yq/color/RGBA.hpp>
#include <yq/tachyon/api/Tachyon.hpp>
#include <yq/tachyon/api/Rendered.hpp>
#include <yq/tachyon/typedef/domain.hpp>

namespace yq::tachyon {
    class DomainMeta : public TachyonMeta {
    public:
        template <typename C> struct Writer;
        DomainMeta(std::string_view, TachyonMeta&, const std::source_location& sl = std::source_location::current());

        //! Gets all scene informations
        static const std::vector<const DomainMeta*>&    all();

    protected:
        ~DomainMeta();
        struct Repo;
        static Repo& repo();
    };
    
    /*! \brief Frame of models
    
        This is a collection of models for sim... analogous of Scene for Rendereds.
        
        It'll manage physics, & models & subdomains.
        
    */
    class Domain : public Tachyon {
        YQ_TACHYON_META(DomainMeta)
        YQ_TACHYON_DATA(DomainData)
        YQ_TACHYON_SNAP(DomainSnap)
        YQ_TACHYON_DECLARE(Domain, Tachyon)
    public:
    
        Domain(const Param&p={});
        virtual ~Domain();
        
        static void init_meta();
        
        DomainID id() const { return DomainID{ UniqueID::id()}; }

    protected:
        void    snap(DomainSnap&) const;
        void    finalize(DomainData&) const;
    };
}
YQ_TYPE_DECLARE(yq::tachyon::DomainID)
