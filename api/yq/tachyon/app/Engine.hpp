////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/units.hpp>
#include <yq/tachyon/api/Manager.hpp>
#include <yq/tachyon/typedef/engine.hpp>

namespace yq::tachyon {

    class EngineMeta : public ManagerMeta {
    public:
        template <typename C> class Writer;

        EngineMeta(std::string_view zName, ManagerMeta& base, const std::source_location& sl=std::source_location::current());
    };

    /*! \brief Engine of the game/simulation/etc
    
        This is the "master manager" to control the game/dungeon/simulation/animation/whatever.
    */
    class Engine : public Manager {
        YQ_TACHYON_META(EngineMeta)
        YQ_TACHYON_DATA(EngineData)
        YQ_TACHYON_SNAP(EngineSnap)
        YQ_TACHYON_DECLARE(Engine, Manager)
    public:
    
        static constexpr const Meter kDefault_EngineScale = 1._cm;
        static void init_meta();
        
        Engine();
        ~Engine();
        
        Meter   engine_scale() const { return m_engineScale; }
        
    protected:
        void finalize(EngineData&) const;
        void snap(EngineSnap&) const;
        
        Meter           m_engineScale = kDefault_EngineScale;
    };
}
