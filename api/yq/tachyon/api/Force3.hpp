////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Physics.hpp>
#include <yq/tachyon/typedef/force3.hpp>

namespace yq::tachyon {

    class Force³;
    
    /*! \brief Force³ Information
    
        Information for lights.
    */
    class Force³Meta : public PhysicsMeta {
    public:
        template <typename C> struct Writer;

        //! Gets all light informations
        static const std::vector<const Force³Meta*>&    all();
        
        //! Standard constructor for the camera information
        Force³Meta(std::string_view, PhysicsMeta&, const std::source_location& sl = std::source_location::current());
    private:
    
        // This *may* go into toolbox... some common "dynamic creation kit"
        struct Repo;
        static Repo& repo();
    };
    

    /*! \brief A light
    */
    class Force³ : public Physics {
        YQ_TACHYON_META(Force³Meta);
        YQ_TACHYON_DATA(Force³Data)
        YQ_TACHYON_SNAP(Force³Snap)
        YQ_TACHYON_DECLARE(Force³, Physics)
    public:    

        static constexpr const Type kType   = Type::Force³;
    
        static void init_meta();

        Force³ID id() const { return Force³ID(UniqueID::id()); }

    protected:
    
        void        snap(Force³Snap&) const;
        void        finalize(Force³Data&) const;

        //! Default constructor
        Force³(const Param&p = {});
        
        //! Default destructor
        ~Force³();
    };

}
YQ_TYPE_DECLARE(yq::tachyon::Force³ID)
