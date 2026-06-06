////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/model/Entity.hpp>
#include <yq/tachyon/typedef/entity3.hpp>

namespace yq::tachyon {

    class Entity³;
    
    /*! \brief Entity³ Information
    
        Information for lights.
    */
    class Entity³Meta : public EntityMeta {
    public:
        template <typename C> struct Writer;

        //! Gets all light informations
        static const std::vector<const Entity³Meta*>&    all();
        
        //! Standard constructor for the camera information
        Entity³Meta(std::string_view, EntityMeta&, const std::source_location& sl = std::source_location::current());
    private:
    
        // This *may* go into toolbox... some common "dynamic creation kit"
        struct Repo;
        static Repo& repo();
    };
    

    /*! \brief A light
    */
    class Entity³ : public Entity {
        YQ_TACHYON_META(Entity³Meta);
        YQ_TACHYON_DATA(Entity³Data)
        YQ_TACHYON_SNAP(Entity³Snap)
        YQ_TACHYON_DECLARE(Entity³, Entity)
    public:    

        static constexpr const Type kType   = Type::Entity³;
    
        static void init_meta();

        Entity³ID id() const { return Entity³ID(UniqueID::id()); }

    protected:
    
        void        snap(Entity³Snap&) const;
        void        finalize(Entity³Data&) const;

        //! Default constructor
        Entity³(const Param&p = {});
        
        //! Default destructor
        ~Entity³();
    };

}
YQ_TYPE_DECLARE(yq::tachyon::Entity³ID)
