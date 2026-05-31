////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Tachyon.hpp>
#include <yq/tachyon/typedef/collision.hpp>

namespace yq::tachyon {

    class Collision;
    
    /*! \brief Collision Information
    
        Information for cameras.
    */
    class CollisionMeta : public TachyonMeta {
    public:
        template <typename C> struct Writer;

        //! Gets all camera informations
        static const std::vector<const CollisionMeta*>&    all();
        
        //! Standard constructor for the camera information
        CollisionMeta(std::string_view, TachyonMeta&, const std::source_location& sl = std::source_location::current());
    private:
    
        // This *may* go into toolbox... some common "dynamic creation kit"
        struct Repo;
        static Repo& repo();
    };
    
    /*
        Right *now*, the camera is assumed to be simple....
    */


    /*! \brief Shows up on the screen
    
        If you want it to show up on the viewport, it needs to be renderable, and thus derived
        from this thing.  
        
        \note We're limited to three dimensions here
    */
    class Collision : public Tachyon {
        YQ_TACHYON_META(CollisionMeta);
        YQ_TACHYON_DATA(CollisionData)
        YQ_TACHYON_SNAP(CollisionSnap)
        YQ_TACHYON_DECLARE(Collision, Tachyon)
    public:    
    
        static void init_meta();

        CollisionID            id() const { return CollisionID(UniqueID::id()); }

    protected:
    
        void        snap(CollisionSnap&) const;

        //! Default constructor
        Collision(const Param&p = {});
        
        //! Default destructor
        ~Collision();
        
    };

}
YQ_TYPE_DECLARE(yq::tachyon::CollisionID)

