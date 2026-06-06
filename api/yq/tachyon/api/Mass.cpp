////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/api/Mass.hpp>
#include <yq/tachyon/api/MassData.hpp>
#include <yq/tachyon/api/MassMetaWriter.hpp>
#include <yq/meta/Init.hpp>

YQ_TACHYON_IMPLEMENT(yq::tachyon::Mass);
YQ_TYPE_IMPLEMENT(yq::tachyon::MassID)

namespace yq::tachyon {

    MassMeta::MassMeta(std::string_view name, ModelMeta& base, const std::source_location& sl) :
        ModelMeta(name, base, sl)
    {
        set(Type::Mass);
    }
    
    MassMeta::~MassMeta()
    {
    }
    

    Mass::Mass(const Param&p) : Model(p)
    {
    }
    
    Mass::~Mass()
    {
    }

    void Mass::snap(MassSnap&sn) const
    {
        Model::snap(sn);
    }

    void Mass::finalize(MassData&data) const
    {
        Model::finalize(data);
    }

    void Mass::init_meta()
    {
        auto w = writer<Mass>();
        w.description("Mass");

        auto wt = writer<MassID>();
        wt.description("Mass Identifier");
        wt.set(Meta::Flag::ID);
        wt.constructor(construct_id<Mass>);
        wt.casts<TachyonID>();
        wt.casts<ModelID>();
    }

}


