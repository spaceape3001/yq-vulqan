////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/api/Model.hpp>
#include <tachyon/api/ModelData.hpp>
#include <tachyon/api/ModelMetaWriter.hpp>
#include <tachyon/api/Post.hpp>
#include <yq/meta/Init.hpp>

namespace yq::tachyon {
    struct ModelMeta::Repo {
        std::vector<const ModelMeta*> all;
    };
    
    ModelMeta::Repo& ModelMeta::repo()
    {
        static Repo* s_repo = new Repo;
        return *s_repo;
    }

    const std::vector<const ModelMeta*>&    ModelMeta::all()
    {
        return repo().all;
    }

    ModelMeta::ModelMeta(std::string_view name, TachyonMeta& base, const std::source_location& sl) : 
        TachyonMeta(name, base, sl)
    {
        set(Type::Model);
        repo().all.push_back(this);
    }


    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    Model::Model(const Param& p) : Tachyon(p)
    {
    }

    Model::~Model()
    {
    }


    void Model::snap(ModelSnap& sn) const
    {
        Tachyon::snap(sn);
    }
    
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    
    void Model::init_meta()
    {
        auto w   = writer<Model>();
        w.abstract();
        w.description("Model base");

        auto wt = writer<ModelID>();
        wt.description("Model Identifier");
        wt.set(Meta::Flag::ID);
        wt.constructor(construct_id<Model>);
        wt.casts<TachyonID>();
    }
}

YQ_TACHYON_IMPLEMENT(yq::tachyon::Model)
YQ_TYPE_IMPLEMENT(yq::tachyon::ModelID)
