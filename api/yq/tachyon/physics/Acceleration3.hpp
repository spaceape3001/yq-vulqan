////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Physics.hpp>
#include <yq/tachyon/typedef/acceleration3.hpp>

namespace yq::tachyon {

    class Acceleration³;
    
    /*! \brief Acceleration³ Information
    */
    class Acceleration³Meta : public PhysicsMeta {
    public:
        template <typename C> struct Writer;

        //! Gets all light informations
        static const std::vector<const Acceleration³Meta*>&    all();
        
        //! Standard constructor for the camera information
        Acceleration³Meta(std::string_view, PhysicsMeta&, const std::source_location& sl = std::source_location::current());
    private:
    
        // This *may* go into toolbox... some common "dynamic creation kit"
        struct Repo;
        static Repo& repo();
    };
    

    /*! \brief An acceleration type of thing... easily summarized to Acceleration = FN(me).  (Gravity being main example)
    */
    class Acceleration³ : public Physics {
        YQ_TACHYON_META(Acceleration³Meta);
        YQ_TACHYON_DATA(Acceleration³Data)
        YQ_TACHYON_SNAP(Acceleration³Snap)
        YQ_TACHYON_DECLARE(Acceleration³, Physics)
    public:    

        static constexpr const Type kType   = Type::Acceleration³;
    
        static void init_meta();

        Acceleration³ID id() const { return Acceleration³ID(UniqueID::id()); }

    protected:
    
        void        snap(Acceleration³Snap&) const;
        void        finalize(Acceleration³Data&) const;

        //! Default constructor
        Acceleration³(const Param&p = {});
        
        //! Default destructor
        ~Acceleration³();
    };

}
YQ_TYPE_DECLARE(yq::tachyon::Acceleration³ID)
