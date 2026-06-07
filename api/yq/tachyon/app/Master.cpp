////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Master.hpp"
#include "MasterData.hpp"
#include "MasterMetaWriter.hpp"
#include <yq/meta/Init.hpp>

YQ_TACHYON_IMPLEMENT(yq::tachyon::Master)
YQ_TYPE_IMPLEMENT(yq::tachyon::MasterID)
YQ_OBJECT_IMPLEMENT(yq::tachyon::MasterData)
YQ_OBJECT_IMPLEMENT(yq::tachyon::MasterSnap)

namespace yq::tachyon {
    MasterData::MasterData() = default;
    MasterData::~MasterData() = default;

    void MasterData::init_meta()
    {
        auto w = writer<MasterData>();
        w.description("Master Frame Data");
    }

    /////////////////////////////////////////////////////////////////////////////

    MasterMeta::MasterMeta(std::string_view zName, ManagerMeta& base, const std::source_location& sl) :
        ManagerMeta(zName, base, sl)
    {
        set(Type::Master);
    }

    /////////////////////////////////////////////////////////////////////////////

    MasterSnap::MasterSnap() = default;
    MasterSnap::~MasterSnap() = default;

    void MasterSnap::init_meta()
    {
        auto w = writer<MasterSnap>();
        w.description("Master Snapshot");
    }


    /////////////////////////////////////////////////////////////////////////////

    Master::Master() : Manager()
    {
    }
    
    Master::~Master()
    {
    }

    void Master::finalize(MasterData& data) const
    {
        Manager::finalize(data);
    }
    
    void Master::snap(MasterSnap&sn) const
    {
        Manager::snap(sn);
    }

    void Master::init_meta()
    {
        auto w = writer<Master>();
        w.description("Master of Arms for the Sim/Game/Animation/Etc");
        w.abstract();
    }
}
