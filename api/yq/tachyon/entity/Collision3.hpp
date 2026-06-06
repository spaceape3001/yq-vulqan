////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/entity/Collision.hpp>
#include <yq/tachyon/typedef/collision3.hpp>

namespace yq::tachyon {

    class Collision³;
    
    /*! \brief Collision³ Information
    
        Information for lights.
    */
    class Collision³Meta : public CollisionMeta {
    public:
        template <typename C> struct Writer;

        //! Gets all light informations
        static const std::vector<const Collision³Meta*>&    all();
        
        //! Standard constructor for the camera information
        Collision³Meta(std::string_view, CollisionMeta&, const std::source_location& sl = std::source_location::current());
    private:
    
        // This *may* go into toolbox... some common "dynamic creation kit"
        struct Repo;
        static Repo& repo();
    };
    

    /*! \brief Collision of Inertia/Rotational Inertia
    */
    class Collision³ : public Collision {
        YQ_TACHYON_META(Collision³Meta);
        YQ_TACHYON_DATA(Collision³Data)
        YQ_TACHYON_SNAP(Collision³Snap)
        YQ_TACHYON_DECLARE(Collision³, Collision)
    public:    

        static constexpr const Type kType   = Type::Collision³;
    
        static void init_meta();

        Collision³ID id() const { return Collision³ID(UniqueID::id()); }

    protected:
    
        void        snap(Collision³Snap&) const;
        void        finalize(Collision³Data&) const;

        //! Default constructor
        Collision³(const Param&p = {});
        
        //! Default destructor
        ~Collision³();
        
    };

}
YQ_TYPE_DECLARE(yq::tachyon::Collision³ID)
