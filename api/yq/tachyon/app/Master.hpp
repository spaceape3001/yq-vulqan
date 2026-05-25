////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Manager.hpp>
#include <yq/tachyon/enum/LengthUnit.hpp>
#include <yq/tachyon/typedef/master.hpp>

namespace yq::tachyon {

    class MasterMeta : public ManagerMeta {
    public:
        template <typename C> class Writer;

        MasterMeta(std::string_view zName, ManagerMeta& base, const std::source_location& sl=std::source_location::current());
    };

    /*! \brief Master of the game/simulation/etc
    
        This is the "master manager" to control the game/dungeon/simulation/animation/whatever.
    */
    class Master : public Manager {
        YQ_TACHYON_META(MasterMeta)
        YQ_TACHYON_DATA(MasterData)
        YQ_TACHYON_SNAP(MasterSnap)
        YQ_TACHYON_DECLARE(Master, Manager)
    public:
    
        static void init_meta();
        Master();
        ~Master();
        
    protected:
        void finalize(MasterData&) const;
        void snap(MasterSnap&) const;
        
    };
}
