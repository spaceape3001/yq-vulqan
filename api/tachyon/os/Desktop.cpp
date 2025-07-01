////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/os/Desktop.hpp>
#include <tachyon/os/DesktopData.hpp>
#include <tachyon/os/DesktopMetaWriter.hpp>
#include <tachyon/api/Post.hpp>
#include <yq/meta/Init.hpp>

namespace yq::tachyon {

    struct DesktopMeta::Repo {
        std::vector<const DesktopMeta*> all;
    };
    
    DesktopMeta::Repo& DesktopMeta::repo()
    {
        static Repo* s_repo = new Repo;
        return *s_repo;
    }

    const std::vector<const DesktopMeta*>&    DesktopMeta::all()
    {
        return repo().all;
    }

    DesktopMeta::DesktopMeta(std::string_view name, ManagerMeta& base, const std::source_location& sl) : 
        ManagerMeta(name, base, sl)
    {
        set(Type::Desktop);
        repo().all.push_back(this);
    }


    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    Desktop::Param::Param()
    {
        control = ALL;
    }

    Desktop::Desktop(const AppCreateInfo& aci, const Param& p) : Manager(p), m_control(p.control)
    {
    }

    Desktop::~Desktop()
    {
    }

    bool    Desktop::does(cursor_k) const
    {
        return m_control(C::Cursor);
    }
    
    bool    Desktop::does(joystick_k) const
    {
        return m_control(C::Joystick);
    }
    
    bool    Desktop::does(keyboard_k) const
    {
        return m_control(C::Keyboard);
    }
    
    bool    Desktop::does(monitor_k) const
    {
        return m_control(C::Monitor);
    }
    
    bool    Desktop::does(mouse_k) const
    {
        return m_control(C::Mouse);
    }
    
    bool    Desktop::does(window_k) const
    {
        return m_control(C::Window);
    }

    void Desktop::snap(DesktopSnap& sn) const
    {
        Manager::snap(sn);
    }

    
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    
    void Desktop::init_info()
    {
        auto w   = writer<Desktop>();
        w.abstract();

        auto wt = writer<DesktopID>();
        wt.description("Desktop Identifier");
        wt.set(Meta::Flag::ID);
        wt.constructor(construct_id<Desktop>);
        wt.casts<TachyonID>();
    }
}

YQ_TACHYON_IMPLEMENT(yq::tachyon::Desktop)
YQ_TYPE_IMPLEMENT(yq::tachyon::DesktopID)
