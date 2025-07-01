////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/api/Tachyon.hpp>
#include <tachyon/typedef/model.hpp>

namespace yq::tachyon {

    class Model;
    
    /*! \brief Model Information
    
        Information for cameras.
    */
    class ModelMeta : public TachyonMeta {
    public:
        template <typename C> struct Writer;

        //! Gets all camera informations
        static const std::vector<const ModelMeta*>&    all();
        
        //! Standard constructor for the camera information
        ModelMeta(std::string_view, TachyonMeta&, const std::source_location& sl = std::source_location::current());
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
    class Model : public Tachyon {
        YQ_TACHYON_META(ModelMeta);
        YQ_TACHYON_DATA(ModelData)
        YQ_TACHYON_SNAP(ModelSnap)
        YQ_TACHYON_DECLARE(Model, Tachyon)
    public:    
    
        static void init_meta();

        ModelID            id() const { return ModelID(UniqueID::id()); }

    protected:
    
        void        snap(ModelSnap&) const;

        //! Default constructor
        Model(const Param&p = {});
        
        //! Default destructor
        ~Model();
        
    };

}
YQ_TYPE_DECLARE(yq::tachyon::ModelID)

