////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/api/Tachyon.hpp>
#include <yt/typedef/model.hpp>

namespace yq::tachyon {

    class Model;
    
    /*! \brief Model Information
    
        Information for cameras.
    */
    class ModelInfo : public TachyonInfo {
    public:
        template <typename C> struct Writer;

        //! Gets all camera informations
        static const std::vector<const ModelInfo*>&    all();
        
        //! Standard constructor for the camera information
        ModelInfo(std::string_view, TachyonInfo&, const std::source_location& sl = std::source_location::current());
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
        YQ_TACHYON_INFO(ModelInfo);
        YQ_TACHYON_DATA(ModelData)
        YQ_TACHYON_SNAP(ModelSnap)
        YQ_TACHYON_DECLARE(Model, Tachyon)
    public:    
    
        static void init_info();

        ModelID            id() const { return ModelID(UniqueID::id()); }

    protected:
    
        void        snap(ModelSnap&) const;
        //virtual void    receive(const post::PostCPtr&) override;
        virtual PostAdvice  advise(const Post&) const override;

        //! Default constructor
        Model(const Param&p = {});
        
        //! Default destructor
        ~Model();
        
    };

}
