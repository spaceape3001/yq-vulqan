////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Model.hpp>
#include <yq/tachyon/typedef/moment3.hpp>

namespace yq::tachyon {

    class Moment³;
    
    /*! \brief Moment³ Information
    
        Information for lights.
    */
    class Moment³Meta : public ModelMeta {
    public:
        template <typename C> struct Writer;

        //! Gets all light informations
        static const std::vector<const Moment³Meta*>&    all();
        
        //! Standard constructor for the camera information
        Moment³Meta(std::string_view, ModelMeta&, const std::source_location& sl = std::source_location::current());
    private:
    
        // This *may* go into toolbox... some common "dynamic creation kit"
        struct Repo;
        static Repo& repo();
    };
    

    /*! \brief Moment of Inertia/Rotational Inertia
    */
    class Moment³ : public Model {
        YQ_TACHYON_META(Moment³Meta);
        YQ_TACHYON_DATA(Moment³Data)
        YQ_TACHYON_SNAP(Moment³Snap)
        YQ_TACHYON_DECLARE(Moment³, Model)
    public:    

        static constexpr const Type kType   = Type::Moment³;
    
        static void init_meta();

        Moment³ID id() const { return Moment³ID(UniqueID::id()); }

    protected:
    
        void        snap(Moment³Snap&) const;
        void        finalize(Moment³Data&) const;

        //! Default constructor
        Moment³(const Param&p = {});
        
        //! Default destructor
        ~Moment³();
    };

}
YQ_TYPE_DECLARE(yq::tachyon::Moment³ID)
