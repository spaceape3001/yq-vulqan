////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Engine.hpp"
#include "EngineData.hpp"
#include "EngineMetaWriter.hpp"

YQ_TACHYON_IMPLEMENT(yq::tachyon::Engine)

namespace yq::tachyon {
    EngineData::EngineData() = default;
    EngineData::~EngineData() = default;

    /////////////////////////////////////////////////////////////////////////////

    EngineMeta::EngineMeta(std::string_view zName, ManagerMeta& base, const std::source_location& sl) :
        ManagerMeta(zName, base, sl)
    {
        set(Type::Engine);
    }

    /////////////////////////////////////////////////////////////////////////////

    EngineSnap::EngineSnap() = default;
    EngineSnap::~EngineSnap() = default;

    /////////////////////////////////////////////////////////////////////////////

    Engine::Engine() : Manager()
    {
    }
    
    Engine::~Engine()
    {
    }

    void Engine::finalize(EngineData& data) const
    {
        Manager::finalize(data);
    }
    
    void Engine::snap(EngineSnap&sn) const
    {
        Manager::snap(sn);
        sn.engine_scale = m_engineScale;
    }

    void Engine::init_meta()
    {
        auto w = writer<Engine>();
        w.description("Common Engine Stuff");
        w.abstract();
        w.property("engine_scale", &Engine::m_engineScale).tag({kTag_Log, kTag_Save});
    }
}
