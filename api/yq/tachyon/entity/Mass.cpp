////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Mass.hpp"
#include "MassData.hpp"
#include "MassMetaWriter.hpp"
#include <yq/meta/Init.hpp>

YQ_TACHYON_IMPLEMENT(yq::tachyon::Mass)
YQ_TYPE_IMPLEMENT(yq::tachyon::MassID)
YQ_OBJECT_IMPLEMENT(yq::tachyon::MassData)
YQ_OBJECT_IMPLEMENT(yq::tachyon::MassSnap)

namespace yq::tachyon {

    MassMeta::MassMeta(std::string_view name, ModelMeta& base, const std::source_location& sl) :
        ModelMeta(name, base, sl)
    {
        set(Type::Mass);
    }
    
    MassMeta::~MassMeta()
    {
    }

    /////////////////////////////////////
    
    MassData::MassData() = default;
    MassData::~MassData() = default;
    
    void MassData::init_meta()
    {
        auto w = writer<MassData>();
        w.description("Mass Frame Data");
    }

    /////////////////////////////////////
    
    MassSnap::MassSnap() = default;
    MassSnap::~MassSnap() = default;
    
    void MassSnap::init_meta()
    {
        auto w = writer<MassSnap>();
        w.description("Mass Snapshot");
    }

    /////////////////////////////////////

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


