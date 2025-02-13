////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yt/os/Desktop.hpp>
#include <yt/os/DesktopData.hpp>
#include <yt/os/DesktopInfoWriter.hpp>
#include <yt/msg/Post.hpp>

namespace yq::tachyon {

    struct DesktopInfo::Repo {
        std::vector<const DesktopInfo*> all;
    };
    
    DesktopInfo::Repo& DesktopInfo::repo()
    {
        static Repo* s_repo = new Repo;
        return *s_repo;
    }

    const std::vector<const DesktopInfo*>&    DesktopInfo::all()
    {
        return repo().all;
    }

    DesktopInfo::DesktopInfo(std::string_view name, ManagerInfo& base, const std::source_location& sl) : 
        ManagerInfo(name, base, sl)
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
    }
}

YQ_TACHYON_IMPLEMENT(yq::tachyon::Desktop)
