////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yt/sim/Model.hpp>
#include <yt/sim/ModelData.hpp>
#include <yt/sim/ModelInfoWriter.hpp>
#include <tachyon/api/Post.hpp>
#include <yq/meta/Init.hpp>

namespace yq::tachyon {
    struct ModelInfo::Repo {
        std::vector<const ModelInfo*> all;
    };
    
    ModelInfo::Repo& ModelInfo::repo()
    {
        static Repo* s_repo = new Repo;
        return *s_repo;
    }

    const std::vector<const ModelInfo*>&    ModelInfo::all()
    {
        return repo().all;
    }

    ModelInfo::ModelInfo(std::string_view name, TachyonInfo& base, const std::source_location& sl) : 
        TachyonInfo(name, base, sl)
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
    
    void Model::init_info()
    {
        auto w   = writer<Model>();
        w.abstract();
        w.description("Model base");

        auto wt = writer<ModelID>();
        wt.description("Model Identifier");
        wt.set(Meta::Flag::ID);
    }
}

YQ_TACHYON_IMPLEMENT(yq::tachyon::Model)
YQ_TYPE_IMPLEMENT(yq::tachyon::ModelID)
