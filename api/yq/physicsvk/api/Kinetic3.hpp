////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/3D.hpp>
#include <yq/physicsvk/api/Kinetic.hpp>
#include <yq/physicsvk/typedef/kinetic3.hpp>
#include <yq/vector/Quaternion3.hpp>
#include <yq/vector/Vector3.hpp>

#ifdef NAN
#undef NAN
#endif

namespace yq::tachyon {
    class Kinetic³Meta : public KineticMeta {
    public:
    
        template <typename> class Writer;
        
        Kinetic³Meta(std::string_view, KineticMeta&, const std::source_location& sl = std::source_location::current());
    protected:
        ~Kinetic³Meta();
    };
    
    class Kinetic³ : public Kinetic, public ③ {
        YQ_TACHYON_META(Kinetic³Meta)
        YQ_TACHYON_SNAP(Kinetic³Snap)
        YQ_TACHYON_DATA(Kinetic³Data)
        YQ_TACHYON_DECLARE(Kinetic³, Kinetic)
    public:
    
        struct Param : public Kinetic::Param {
        };
    
        static void init_meta();
    
        Kinetic³ID id() const { return Kinetic³ID(UniqueID::id()); }
        
        using Kinetic::mark;
    
    protected:
        Kinetic³(const Param&);
        ~Kinetic³();
        
        void finalize(Kinetic³Data&) const;
        void snap(Kinetic³Snap&) const;

        using Tachyon::mail;
        using Tachyon::send;
    };
}

YQ_TYPE_DECLARE(yq::tachyon::Kinetic³ID)
