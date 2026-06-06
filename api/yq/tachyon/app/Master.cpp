////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Master.hpp"
#include "MasterData.hpp"
#include "MasterMetaWriter.hpp"

YQ_TACHYON_IMPLEMENT(yq::tachyon::Master)

namespace yq::tachyon {
    MasterData::MasterData() = default;
    MasterData::~MasterData() = default;

    /////////////////////////////////////////////////////////////////////////////

    MasterMeta::MasterMeta(std::string_view zName, ManagerMeta& base, const std::source_location& sl) :
        ManagerMeta(zName, base, sl)
    {
        set(Type::Master);
    }

    /////////////////////////////////////////////////////////////////////////////

    MasterSnap::MasterSnap() = default;
    MasterSnap::~MasterSnap() = default;

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
