////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/api/Model.hpp>
#include <yq/tachyon/api/ModelBind.hpp>
#include <yq/tachyon/api/ModelData.hpp>
#include <yq/tachyon/api/ModelInfoWriter.hpp>
#include <yq/tachyon/api/Post.hpp>

namespace yq::tachyon {

    ModelBind::ModelBind(const Model* v) : m_model(v ? v->id() : ModelID{})
    {
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

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

    void            Model::set_name(const std::string& v)
    {
        m_name  = v;
    }

    Tachyon::PostAdvice    Model::advise(const Post&pp) const
    {
        PostAdvice  pa  = Tachyon::advise(pp);
        if(!unspecified(pa))
            return pa;
        
        if(const ModelBind* p = dynamic_cast<const ModelBind*>(&pp)){
            if(p->model() != id())
                return REJECT;
        }
        return {};
    }
    
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    
    void Model::init_info()
    {
        auto w   = writer<Model>();
        w.property("name", &Model::get_name).setter(&Model::set_name);
        w.abstract();
    }
}

YQ_TACHYON_IMPLEMENT(yq::tachyon::Model)
