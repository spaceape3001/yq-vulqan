////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Model.hpp>
#include <yq/tachyon/typedef/entity.hpp>

namespace yq::tachyon {

    class Entity;
    
    /*! \brief Entity Information
    
        Information for cameras.
    */
    class EntityMeta : public ModelMeta {
    public:
        template <typename C> struct Writer;

        //! Gets all camera informations
        static const std::vector<const EntityMeta*>&    all();
        
        //! Standard constructor for the camera information
        EntityMeta(std::string_view, ModelMeta&, const std::source_location& sl = std::source_location::current());
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
    class Entity : public Model {
        YQ_TACHYON_META(EntityMeta);
        YQ_TACHYON_DATA(EntityData)
        YQ_TACHYON_SNAP(EntitySnap)
        YQ_TACHYON_DECLARE(Entity, Model)
    public:    

        static constexpr const Type kType   = Type::Entity;
    
        static void init_meta();

        EntityID            id() const { return EntityID(UniqueID::id()); }

    protected:
    
        void        snap(EntitySnap&) const;

        //! Default constructor
        Entity(const Param&p = {});
        
        //! Default destructor
        ~Entity();
        
    };

}
YQ_TYPE_DECLARE(yq::tachyon::EntityID)

